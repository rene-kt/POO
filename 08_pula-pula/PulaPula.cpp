#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <memory>
#include <sstream>

class Kid {
    std::string name;
    int age;

public:
    Kid(std::string name = "", int age = 0) : name{name}, age{age} {}

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(std::string name) {
        this -> name = name;
    }

    void setAge(int age) {
        this -> age = age;
    }

     friend std::ostream& operator<<(std::ostream& os, const Kid& k) {
        os << k.name << ":" << k.age;
        return os;
    }
};

class Trampoline {
    std::list<std::shared_ptr<Kid>> playing;
    std::list<std::shared_ptr<Kid>> waiting;

public:
    Trampoline(int position) : playing(position, nullptr), waiting() {}  

    friend std::ostream& operator<<(std::ostream& os, const Trampoline& t) {
        os << "=> ";

        for (auto kid : t.waiting) 
        {
            if (kid != nullptr) 
            {
                os << *kid << " ";
            } 
        }

        os << "=> [ ";

        for (auto kid : t.waiting) 
        {
            if (kid != nullptr) 
            {
                os << *kid << " ";
            } 
        }

        os << "]\n";
        return os;
    }

    void arrive(std::shared_ptr<Kid> kid) {
        this -> waiting.push_back(kid);
    }

   void in() {
       if ( this -> waiting.empty()) 
       {
           std::cout << "Empty queue\n";
       }
       else 
       {
           this -> waiting.push_back( this -> waiting.front());
           this -> waiting.pop_front();
       }
   }

   void out() {
       if ( this -> waiting.empty()) 
       {
           std::cout << "Empty trampoline\n";
       }
       else 
       {
           this -> waiting.push_back( this -> waiting.front());
           this -> waiting.pop_front();
       }
    }

    std::shared_ptr<Kid> removerKid(std::string name) {
        for (auto atual = waiting.begin(); atual != waiting.end(); atual++) 
        {
            if (atual -> get() -> getName() == name) 
            {
                return *waiting.erase(atual);
            }
        }

        for (auto atual = waiting.begin(); atual != waiting.end(); atual++) 
        {
            if (atual -> get() -> getName() == name) 
            {
                return *waiting.erase(atual);
            }
        }
        return nullptr;
    }
};

int main() {
    Trampoline trampolim(0);

    while (true) 
    {
    std::string cmd;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    ss >> cmd;
        
        if (cmd == "arrive") 
        {
            std::string name {};
            int age {};
            ss >> name >> age;
            trampolim.arrive(std::make_shared<Kid>(name, age));
        }
        else if (cmd == "show") 
        {
            std::cout << trampolim << '\n';
        }
        else if (cmd == "in") 
        {
            trampolim.in();
        }
        else if (cmd == "out") 
        {
            trampolim.out();
        }
        else if (cmd == "remove") 
        {
            std::string name {};
            ss >> name;
            trampolim.removerKid(name);
            std::cout << name << '\n';
        }
        else if (cmd == "stop") 
        {
            break;
        }
        else {
            std::cout << "Invalid!\n";
        }
    }
}