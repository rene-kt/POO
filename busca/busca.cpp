#include <iostream>
#include <sstream>
#include <list>


class Fone {
private:
    std::string id;
    std::string number;

public:
    Fone(std::string id, std::string number) {
        this->id = id;
        this->number = number;
    }

    static bool isValid(std::string number) {
        for(int i : number) {
            if( i == '(' || i == ')' || (i >= '0' && i <= '9') ) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }

    std::string getId() {
        return this->id;
    }

    std::string getNumber() {
        return this->number;
    }

    void setId(std::string id) {
        if(isValid(id)) {
            this->id = id;
        }
        else {
            std::cout << "Invalid ID" << '\n';
        }
    }

    void setNumber(std::string number) {
        this->number = number;
    }

    friend std::ostream& operator<<(std::ostream& os, Fone& fone) {
        os << fone.id << ':' << fone.number;
        return os;
}
};

class Contact {
private:
    std::string name;
    std::list<Fone> fones;

public:
    Contact(std::string name) {
        this->name = name;
    }

    void addFone(Fone fone) {
        this->fones.push_back(fone);
    }

    void rmFone(int index) {
        if(fones.size() == 0) {
            std::cout << "Não há fones para remover" << '\n';
        }
        else {
            std::list<Fone>::iterator it = this->fones.begin();
            std::advance(it, index);
            this->fones.erase(it);
        }
    }

    std::string getName() {
        return this->name;
    }

    std::list<Fone> getFones() {
        return this->fones;
    }

    void setName(std::string name) {
        this->name = name;
    }

    friend std::ostream& operator<<(std::ostream& os, Contact& contact) {
        os << contact.name << ' ';
        int cont{0};
        for(Fone fone : contact.fones) {
            os << '[' << cont << ':';
            os << fone;
            os << ']';
        }
        return os;
    }


};

class Agenda {
private:
    std::list<Contact> contacts;

public:

    int findPosByName(std::string name) {
        int pos = 0;
        for(Contact c: contacts) {
            if(c.getName() == name) {
                return pos;
            }
            pos++;
        }
        return -1;
    }

    Agenda() {}

    Contact findContact(std::string name) {
        int pos = findPosByName(name);
        if(pos == -1) {
            std::cout << "Não há contato com esse nome" << '\n';
            return Contact("");
        }
        else {
            auto it = this->contacts.begin();
            std::advance(it, pos);
            return *it;
        }
        
    }

    void addContact(Contact contact) {
        this->contacts.push_back(contact);
    }

    void rmContact(std::string name) {
        int pos = findPosByName(name);
        if(pos == -1) {
            std::cout << "Não há contato com esse nome" << '\n';
        }
        else {
            auto it = this->contacts.begin();
            std::advance(it, pos);
            this->contacts.erase(it);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Agenda& agenda) {
        for(Contact c : agenda.contacts) {
            os << c << '\n';
        }
        return os;
    }



};


int main() {
    Agenda agenda;

    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if(command == "add") {
            std::string name;
            std::string id;
            std::string number;
            ss >> name;
            std::string format;
            ss >> format;
            Contact c(name);
            
            for(int i = 0; i < (int) format.size(); i++) {
                if(format[i] == ':') {
                    format[i] = ' ';
                }
            }
            std::stringstream ss2(format);
            ss2 >> id >> number;
            if(Fone::isValid(number)) {
                //se o contato já existir, adiciona o fone
                if(agenda.findPosByName(name) != -1) {
                    c.addFone(Fone(id, number));
                } else {
                c.setName(name);
                Fone fone(id, number);
                c.addFone(fone);
                agenda.addContact(c);

                }
                
            }
            else {
                std::cout << "Invalid number" << '\n';
            }
            

        }
        else if(command == "rm") {
            std::string name;
            ss >> name;
            int pos = agenda.findPosByName(name);
            if(pos == -1) {
                std::cout << "Não há contato com esse nome" << '\n';
            }
            else {
                agenda.rmContact(name);
            }
        }
        else if(command == "find") {
            std::string name;
            ss >> name;
            Contact c = agenda.findContact(name);
            if(c.getName() == "") {
                std::cout << "Não há contato com esse nome" << '\n';
            }
            else {
                std::cout << c << '\n';
            }
        }

        else if(command == "exit") {
            break;
        }

        else if(command == "show") {
            std::cout << agenda << '\n';
        }

        else {
            std::cout << "Invalid command" << '\n';
        }

    }
    return 0;

}
