class Client {
    std::string name;
    std::string phone;

public:
    Client(std::string name = "", std::string phone = "") : name{name}, phone{phone} {}
     
    friend std::ostream& operator<<(std::ostream& os, const Client& c) {
        os << c.name << ":" << c.phone;
        return os;
    }

    void setname(std::string name) {
        this -> name = name;
    }

    void setphone(std::string phone) {
        this -> phone = phone;
    } 

    std::string getname() {
        return name;
    }

    std::string getphone() {
        return phone;
    }
 
};
