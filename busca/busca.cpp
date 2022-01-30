#include <iostream>
#include <sstream>
#include <list>

class Phone
{
private:
    std::string id;
    std::string number;

public:
    Phone(std::string id, std::string number)
    {
        this->id = id;
        this->number = number;
    }

    static bool isValid(std::string number)
    {
        for (int i : number)
        {
            if (i == '(' || i == ')' || (i >= '0' && i <= '9'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    std::string getId()
    {
        return this->id;
    }

    std::string getNumber()
    {
        return this->number;
    }

    void setId(std::string id)
    {
        this->id = id;
    }

    void setNumber(std::string number)
    {
        this->number = number;
    }

    friend std::ostream &operator<<(std::ostream &os, Phone &phone)
    {
        os << phone.id << ":" << phone.number;
        return os;
    }
};

class Contact
{
private:
    std::string name;
    std::list<Phone> phones;

public:
    Contact(std::string name)
    {
        this->name = name;
    }

    void addPhone(Phone phone)
    {
        this->phones.push_back(phone);
    }

    void rmPhone(int index)
    {
        if (phones.size() == 0)
        {
            std::cout << "The list is empty" << '\n';
        }
        else
        {
            std::list<Phone>::iterator it = this->phones.begin();
            std::advance(it, index);
            this->phones.erase(it);
        }
    }

    std::string getName()
    {
        return this->name;
    }

    std::list<Phone> getPhones()
    {
        return this->phones;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    friend std::ostream &operator<<(std::ostream &os, Contact &contact)
    {
        os << contact.name << ' ';
        int cont{0};
        for (Phone phone : contact.phones)
        {
            os << '[' << cont << ':';
            os << phone;
            os << ']';
        }
        return os;
    }
};

class Agenda
{
private:
    std::list<Contact> contacts;

public:
    int findByName(std::string name)
    {
        int pos = 0;
        for (Contact c : contacts)
        {
            if (c.getName() == name)
            {
                return pos;
            }
            pos++;
        }
        return -1;
    }

    Agenda() {}

    Contact findContact(std::string name)
    {
        int pos = findByName(name);
        if (pos == -1)
        {
            std::cout << "The name was not found" << '\n';
            return Contact("");
        }
        else
        {
            auto it = this->contacts.begin();
            std::advance(it, pos);
            return *it;
        }
    }

    void addContact(Contact contact)
    {
        this->contacts.push_back(contact);
    }

    void rmContact(std::string name)
    {
        int pos = findByName(name);
        if (pos == -1)
        {
            std::cout << "The name was not found" << '\n';
        }
        else
        {
            auto it = this->contacts.begin();
            std::advance(it, pos);
            this->contacts.erase(it);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, Agenda &agenda)
    {
        for (Contact c : agenda.contacts)
        {
            os << c << '\n';
        }
        return os;
    }
};

int main()
{
    Agenda agenda;

    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "add")
        {
            std::string name;
            std::string id;
            std::string number;
            ss >> name;
            Contact c(name);
            ss >> id;
            ss >> number;
            if (Phone::isValid(number))
            {
                if (agenda.findByName(name) != -1)
                {
                    c.addPhone(Phone(id, number));
                }
                else
                {
                    c.setName(name);
                    Phone phone(id, number);
                    c.addPhone(phone);
                    agenda.addContact(c);
                }
            }
            else
            {
                std::cout << "Invalid number" << '\n';
            }
        }
        else if (command == "rm")
        {
            std::string name;
            ss >> name;
            int pos = agenda.findByName(name);
            if (pos == -1)
            {
                std::cout << "Name was not found" << '\n';
            }
            else
            {
                agenda.rmContact(name);
            }
        }
        else if (command == "find")
        {
            std::string name;
            ss >> name;
            Contact c = agenda.findContact(name);
            if (c.getName() == "")
            {
                std::cout << "Name was not found" << '\n';
            }
            else
            {
                std::cout << c << '\n';
            }
        }

        else if (command == "exit")
        {
            break;
        }

        else if (command == "show")
        {
            std::cout << agenda << '\n';
        }

        else
        {
            std::cout << "Invalid command" << '\n';
        }
    }
    return 0;
}
