#include <iostream>
#include <list>
#include <sstream>
#include <memory>

class Phone {
private:
    std::string id;
    std::string number;

public:
    Phone(std::string id, std::string number) {
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
        this->id = id;
    }

    void setNumber(std::string number) {
        this->number = number;
    }

    friend std::ostream& operator<<(std::ostream& os, Phone& phone) {
        os << phone.id << ":" << phone.number;
        return os;
    }
};

class Contact {
private:
    std::string name;
    std::list<Phone> phones;

public:
    Contact(std::string name) {
        this->name = name;
    }

    void addPhone(Phone phone) {
        this->phones.push_back(phone);
    }

    void removePhone(int index) {
        if(phones.size() == 0) {
            std::cout << "The list is empty" << '\n';
        }
        else {
            std::list<Phone>::iterator it = this->phones.begin();
            std::advance(it, index);
            this->phones.erase(it);
        }
    }

    std::string getName() {
        return this->name;
    }

    std::list<Phone> getPhones() {
        return this->phones;
    }

    void setName(std::string name) {
        this->name = name;
    }

    friend std::ostream& operator<<(std::ostream& os, Contact& contact) {
        os << contact.name << ' ';
        int cont{0};
        for(Phone phone : contact.phones) {
            os << '[' << cont << ':';
            os << phone;
            os << ']';
        }
        return os;
    }


};


int main() {
    Contact c1("");
    
    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if(command == "init") {
            std::string name;
            ss >> name;
            c1 = Contact(name);
        }        
        else if(command == "add") {
            std::string id;
            std::string number;
            ss >> id >> number;
            if(Phone::isValid(number)) {
                Phone phone(id, number);
                c1.addPhone(phone);
            }
            else {
                std::cout << "Número inválido" << '\n';
            }
        }
        else if(command == "rm") {
            int index;
            ss >> index;
            c1.removePhone(index);
        }
        else if(command == "show") {
            std::cout << c1 << '\n';
        }
        else if(command == "end") {
            break;
        }
        else {
            std::cout << "Invalid!" << '\n';
        }
    }
}