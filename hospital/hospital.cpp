#include <iostream>
#include <map>
#include <sstream>
#include "pacient.cpp"
#include "medic.cpp"

class Pacient;
void Paciente::addmedic(medic *medic)
{
    this->medics[medic->getSender()] = medic;
}

void Paciente::removemedic(std::string nome)
{
    this->medics.erase(nome);
}

void medic::addPaciente(Paciente *paciente)
{
    this->pacients[paciente->getSender()] = paciente;
}

void medic::removePaciente(std::string nome)
{
    this->pacients.erase(nome);
}

class Hospital
{
private:
    std::map<std::string, Paciente *> pacients;
    std::map<std::string, medic *> medics;

public:
    Hospital()
    {
    }

    void removePaciente(std::string sender)
    {
        this->pacients.erase(sender);
    }

    void removemedic(std::string sender)
    {
        this->medics.erase(sender);
    }

    void addPaciente(Paciente *paciente)
    {
        this->pacients[paciente->getSender()] = paciente;
    }

    void addmedic(medic *medic)
    {
        this->medics[medic->getSender()] = medic;
    }

    void vincular(std::string nomemedic, std::string nomePaciente)
    {
        this->medics[nomemedic]->addPaciente(this->pacients[nomePaciente]);
        this->pacients[nomePaciente]->addmedic(this->medics[nomemedic]);
    }

    std::string showAll()
    {
        std::stringstream ss;
        ss << "pacients: " << std::endl;
        for (auto it = this->pacients.begin(); it != this->pacients.end(); it++)
        {
            ss << *(it->second) << std::endl;
        }
        ss << "medics: " << std::endl;
        for (auto it = this->medics.begin(); it != this->medics.end(); it++)
        {
            ss << *(it->second) << std::endl;
        }
        return ss.str();
    }
};

int main()
{
    Hospital hospital;
    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "end")
        {
            break;
        }
        else if (command == "addPacient")
        {
            std::string sender;
            std::string diagnostic;
            ss >> sender >> diagnostic;
            hospital.addPaciente(new Paciente(sender, diagnostic));
        }
        else if (command == "addMedic")
        {
            std::string sender;
            std::string classe;
            ss >> sender >> classe;
            hospital.addmedic(new medic(sender, classe));
        }
        else if (command == "tie")
        {
            std::string nomemedic;
            std::string nomePaciente;
            ss >> nomemedic >> nomePaciente;
            hospital.vincular(nomemedic, nomePaciente);
        }
        else if (command == "findAll")
        {
            std::cout << hospital.showAll();
        }
    }
}
