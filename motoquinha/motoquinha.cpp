#include <iostream>
#include <sstream>

struct Pessoa {
    std::string nome{};
    int idade{};

    Pessoa( std::string nome = "", int idade = 0) {
        this -> nome = nome;
        this -> idade = idade;
    }

    Pessoa fazerFilho( Pessoa pais) {
        Pessoa filho( this->nome + " " + pais.nome, 0);
        return filho;
    }

    friend std::ostream& operator<<( std::ostream& os, Pessoa p ) {
        os << "Nome: " << p.nome << " Idade: " << p.idade;
        return os;
    }
};

struct Motoca {
    Pessoa *pessoa{nullptr};
    int tempo;
    int potencia;


    
    Motoca(Pessoa *pessoa = nullptr, int tempo = 0, int potenca = 1){
        this->pessoa = pessoa;
        this->tempo = tempo;
        this->potencia = potencia;
    }

    Motoca(int potencia = 1, int tempo = 1) {
        this->potencia = potencia;
        this->tempo = tempo;
    }
    void inserirPessoa(Pessoa *p) {
        if (this->pessoa == nullptr) {
            this->pessoa = p;
            return;
        } else {
            std::cout << "Motoquinha em uso" << '\n';
        }
    }

    Pessoa *removerPessoa() {
        if (this->pessoa == nullptr) {
            std::cout << "Motoquinha vazia" << '\n';
            return nullptr;
        } else {
            Pessoa *p = this->pessoa;
            this->pessoa = nullptr;
            return p;
        }
    }

    std::string buzinar() {
        return "B" + std::string(this->potencia,'e') + 'z';
    }

    friend std::ostream& operator<<( std::ostream& os, Motoca m ) {
        os << "Tempo :" << m.tempo << " Potencia: " << m.potencia << '\n';
        if (m.pessoa != nullptr) {
            os << *m.pessoa;
        } else {
            os << "Nao tem ninguem na motoquinha" << '\n';
        }
        
        return os;
    }
};


int main() {

    Motoca m(1,1);

    while (true) {
        std::string line;
        std::getline(std::cin,line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        
        if (cmd == "init") {
            int pot{0};
            int temp{0};
            ss >> pot >> temp;
            m = Motoca(pot,temp);
        } else if (cmd == "show") {
            std::cout << m << '\n';

        } else if (cmd == "add") {
            std::string nome{};
            std::string idade{};
            ss >> nome >> idade;
            Pessoa *pessoa = new Pessoa(nome, std::stoi(idade));            
            m.inserirPessoa(pessoa);

        } else if (cmd == "remove") {
            Pessoa *p = m.removerPessoa();  
            delete p;  
       
        }   else {
            std::cout << "ERROR" << '\n';
        }

        if ( cmd == "exit") {
            break;
        }
    }

}