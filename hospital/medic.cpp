
#include <iostream>
#include <map>
#include <sstream>
class Paciente;
class medic
{
private:
    std::string sender;
    std::string classe;
    std::map<std::string, Paciente *> pacients;

public:
    medic(std::string sender, std::string classe)
    {
        this->sender = sender;
        this->classe = classe;
    }

    void addPaciente(Paciente *paciente);

    void removePaciente(std::string nome);

    std::string getClasse()
    {
        return this->classe;
    }

    std::string getSender()
    {
        return this->sender;
    }

    std::string getpacients()
    {
        std::stringstream ss;
        for (auto it = pacients.begin(); it != pacients.end(); it++)
        {
            ss << it->first << " ";
        }
        return ss.str();
    }

    friend std::ostream &operator<<(std::ostream &os, medic &medic)
    {
        os << "medic: " << medic.getSender() << " Classe: " << medic.getClasse() << " pacients: " << medic.getpacients();
        return os;
    }
};
