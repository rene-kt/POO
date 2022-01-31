#include <iostream>
#include <ostream>
#include <sstream>
#include <map>
#include <memory>



class Person
{
private:
  std::string id;
  std::string name;
  std::string phone;

public:
  Person(std::string id = "", std::string name = "", std::string phone = "")
  {
    this->id = id;
    this->name = name;
    this->phone = phone;
  }

  std::string getId() const
  {
    return this->id;
  }

  std::string getName() const
  {
    return this->name;
  }

  std::string getPhone() const
  {
    return this->phone;
  }

  void setId(int id)
  {
    this->id = id;
  }

  void setName(std::string name)
  {
    this->name = name;
  }

  void setPhone(std::string phone)
  {
    this->phone = phone;
  }

  friend std::ostream &operator<<(std::ostream &os, const Person &person)
  {
    os << person.getId() << ":" << person.getName() << ":" << person.getPhone();
    return os;
  }
};

class Room
{
private:
  std::map<int, std::shared_ptr<Person>> seats;

  bool idAlreadyExists(std::string id)
  {
    for (auto &seat : seats)
    {
      if (seat.second->getId() == id)
      {
        return true;
      }
    }

    return false;
  }

public:
  Room()
  {
    this->seats.clear();
  }

  std::map<int, std::shared_ptr<Person>> getSeats()
  {
    return this->seats;
  }

  bool reserve(std::string id, std::string name, std::string phone, int numberSeat)
  {
    bool idAlreadyExists = this->idAlreadyExists(id);

    if (idAlreadyExists)
    {
      std::cout << "This ID is already being used\n";
      return false;
    }

    this->seats.insert(std::make_pair(numberSeat, std::make_shared<Person>(id, name, phone)));

    return true;
  }

  void cancel(std::string id)
  {
    for (auto &seat : seats)
    {
      if (seat.second->getId() == id)
      {
        seat.second = nullptr;
        return;
      }
    }

    std::cout << "Person not found\n";
  }

  friend std::ostream &operator<<(std::ostream &os, const Room &room)
  {
    os << "[ ";

    for (auto seat : room.seats)
    {
      if (seat.second != nullptr)
      {
        os << seat.first << ":" << *seat.second << " ";
      }
      else
      {
        os << "- ";
      }
    }

    os << "]";

    return os;
  }
};



int main()
{
  Room room;

  while (true)
  {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::string cmd;
    ss >> cmd;

    if (cmd == "end")
    {
      break;
    }
    else if (cmd == "init")
    {
      room = Room();
    }
    else if (cmd == "show")
    {
      std::cout << room << "\n";
    }
    else if (cmd == "book")
    {
      std::string id{""};
      std::string name{""};
      std::string phone{""};
      int numberSeat{0};
      ss >> id >> name >> phone >> numberSeat;

      room.reserve(id, name, phone, numberSeat);
    }
    else if (cmd == "cancel")
    {
      std::string id;

      ss >> id;
      room.cancel(id);
    }
    else
    {
      std::cout << "Invalid!\n";
    }
  }
}
