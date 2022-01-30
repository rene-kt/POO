#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "client.cpp"


class Cinema {
    private:
        std::vector<std::shared_ptr<Client>> chairs;

    public:
        Cinema(int capacity ) : chairs(capacity, nullptr) {}

        friend std::ostream& operator<<(std::ostream& os, const Cinema& c) {
        os << "[ ";

        for (auto chair : c.chairs) {
            if (chair == nullptr) {
                os << "- ";
            } else {
                os << *chair << " ";
            }
        }

        os << "]\n";

        return os;
    }

    int findByName(std::string name) {
        for (int i = 0; i < (int) chairs.size(); i++)
            if (chairs[i] != nullptr && chairs[i] -> getname() == name) 
                return i;
        return -1;
    }

    bool book(std::string name, std::string phone, int indice) {
        if (indice < 0 || indice >= this -> chairs.size()) {
            std::cout << "Chair not found" << '\n';
            return false;
        }
        if (chairs[indice] != nullptr) {
            std::cout << "Chair is already being used" << '\n';
            return false;
        }
        if (this -> chairs[indice] == nullptr) {
            this -> chairs[indice] = std::make_shared<Client>(name, phone);
            return true;
        }
    }

    void cancel(std::string name){
        int indice = findByName(name);
        if (indice == -1) {
            std::cout << "Client not found" << '\n';
        }
        else {
            this -> chairs[indice] = nullptr;
        }
    }
};

int main() {
    Cinema cinema(0);

    while (true) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "init") {
            int capacity;
            std::cin >> capacity;
            cinema = Cinema(capacity);
        }
        else if (cmd == "show") {
            std::cout << cinema << '\n';
        }
        else if (cmd == "book") {
            std::string name {};
            std::string phone {};
            int indice;
            std::cin >> name >> phone >> indice;
            cinema.book(name, phone, indice);
        }
        else if (cmd == "cancel") {
            std::string name {};
            std::cin >> name;
            cinema.cancel(name);
        }
        else if (cmd == "end") {
            break;
        } 
        else {
            std::cout << "Invalid!\n";
        }
    }
    return 0;
}