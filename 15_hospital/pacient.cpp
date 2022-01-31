#include <iostream>
#include <map>
#include <sstream>

class medic;
class Paciente
{

private:
    std::string diagnostic;
    std::string sender;
    std::map<std::string, medic *> medics;

public:
    Paciente(std::string sender, std::string diagnostic)
    {
        this->sender = sender;
        this->diagnostic = diagnostic;
    }

    void addmedic(medic *medic);

    void removemedic(std::string nome);

    std::string getdiagnostic()
    {
        return this->diagnostic;
    }

    std::string getSender()
    {
        return this->sender;
    }

    std::string getmedics()
    {
        std::stringstream ss;
        for (auto it = medics.begin(); it != medics.end(); it++)
        {
            ss << it->first << " ";
        }
        return ss.str();
    }

    friend std::ostream &operator<<(std::ostream &os, Paciente &paciente)
    {
        os << "Pacient: " << paciente.getSender() << " diagnostic: " << paciente.getdiagnostic() << " medics: " << paciente.getmedics();
        return os;
    }
};