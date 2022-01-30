#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <sstream>

class AccountException
{
public:
    AccountException(std::string msg) : msg(msg) {}
    std::string getMessage() { return msg; }

private:
    std::string msg;
};
class Account
{
protected:
    int id = 0;
    std::string clientId = "";
    float balance = 0.0;
    std::string type = "";

public:
    Account(int id, std::string clientId)
    {
        this->id = id;
        this->clientId = clientId;
    }

    virtual ~Account() {}

    virtual void monthlyUpdate() = 0;

    float getBalance()
    {
        return this->balance;
    }

    std::string getClientId()
    {
        return this->clientId;
    }

    int getId()
    {
        return this->id;
    }

    std::string getType()
    {
        return this->type;
    }

    void deposit(float value)
    {
        this->balance += value;
    }

    void transfer(std::shared_ptr<Account> accountTo, float value)
    {
        if (accountTo == nullptr)
            throw AccountException("Object not found");

        if (value > this->balance)
            throw AccountException("Insuficient money");

        this->balance -= value;
        accountTo->balance += value;
    }

    void withdraw(float value)
    {
        if (value > this->balance)
            throw AccountException("Insuficient money");

        this->balance -= value;
    }

    friend std::ostream &operator<<(std::ostream &os, const Account &account)
    {
        os << account.id << ":" << account.clientId << ":" << account.balance << ":" << account.type;
        return os;
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int id, std::string clientId) : Account(id, clientId)
    {
        this->type = "CC";
    }

    void monthlyUpdate() override
    {
        this->balance -= 20;
    }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(int id, std::string clientId) : Account(id, clientId)
    {
        this->type = "CP";
    }

    void monthlyUpdate() override
    {
        this->balance += this->balance * 0.01;
    }
};

class Client
{
private:
    std::vector<std::shared_ptr<Account>> accounts = {};
    std::string clientId = "";

public:
    Client(std::string clientId = "") : clientId{clientId} {}

    std::vector<std::shared_ptr<Account>> getAccounts() const
    {
        return this->accounts;
    }

    std::string getClientId() const
    {
        return this->clientId;
    }

    void addAccount(std::shared_ptr<Account> account)
    {
        if (account == nullptr)
            throw AccountException("Object not found");

        this->accounts.push_back(account);
    }

    friend std::ostream &operator<<(std::ostream &os, const Client &client)
    {
        os << "- " << client.clientId << " [";

        for (int i = 0; i < (int)client.accounts.size(); i++)
        {
            if (i > 0)
            {
                os << ", " << client.accounts[i]->getId();
            }
            else
            {
                os << client.accounts[i]->getId();
            }
        }

        os << "]";
        return os;
    }
};

class BankAgency
{
private:
    std::map<int, std::shared_ptr<Account>> accounts = {};
    std::map<std::string, std::shared_ptr<Client>> clients = {};
    int nextAccountId = 1;

    std::shared_ptr<Account> getAccount(int id)
    {
        for (auto account : this->accounts)
        {
            if (account.first == id)
            {
                return account.second;
            }
        }

        return nullptr;
    }

public:
    BankAgency() {}

    void addClient(std::string clientId)
    {
        this->clients.insert(std::make_pair(clientId, std::make_shared<Client>(clientId)));

        std::shared_ptr<Account> checkingAccount = std::make_shared<CheckingAccount>(nextAccountId, clientId);
        this->accounts.insert(std::make_pair(nextAccountId, checkingAccount));
        nextAccountId += 1;

        std::shared_ptr<Account> savingAccount = std::make_shared<SavingsAccount>(nextAccountId, clientId);
        this->accounts.insert(std::make_pair(nextAccountId, savingAccount));
        nextAccountId += 1;

        this->clients[clientId]->addAccount(checkingAccount);
        this->clients[clientId]->addAccount(savingAccount);
    }

    void deposit(int accountId, float value)
    {
        auto account = this->getAccount(accountId);

        if (account == nullptr)
        {
            throw AccountException("Object not found");
        }

        account->deposit(value);
    }

    void withdraw(int accountId, float value)
    {
        auto account = this->getAccount(accountId);

        if (account == nullptr)
        {
            throw AccountException("Object not found");
        }

        account->withdraw(value);
    }

    void transfer(int accountIdFrom, int accountIdTo, float value)
    {
        auto accountFrom = this->getAccount(accountIdFrom);
        auto accountTo = this->getAccount(accountIdTo);

        if (accountFrom == nullptr || accountTo == nullptr)
        {
            throw AccountException("conta nao encontrada");
        }

        accountFrom->transfer(accountTo, value);
    }

    void monthlyUpdate()
    {
        for (auto &account : this->accounts)
        {
            account.second->monthlyUpdate();
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const BankAgency &bankAgency)
    {
        os << "clientes:\n";
        for (auto client : bankAgency.clients)
        {
            os << *(client.second) << "\n";
        }

        os << "contas:\n";
        for (auto account : bankAgency.accounts)
        {
            os << *(account.second) << "\n";
        }

        return os;
    }
};

int main()
{
    BankAgency bankAgency;

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
        else if (cmd == "iniciar")
        {
            bankAgency = BankAgency();
        }

        else if (cmd == "add")
        {
            std::string clientName{""};
            ss >> clientName;

            bankAgency.addClient(clientName);
        }
        else if (cmd == "withdraw")
        {
            int accountId;
            float value;
            ss >> accountId >> value;

            bankAgency.withdraw(accountId, value);
        }
        else if (cmd == "deposit")
        {
            int accountId;
            float value;
            ss >> accountId >> value;

            bankAgency.deposit(accountId, value);
        }
        else if (cmd == "transfer")
        {
            int accountIdFrom;
            int accountIdTo;
            float value;
            ss >> accountIdFrom >> accountIdTo >> value;

            bankAgency.transfer(accountIdFrom, accountIdTo, value);
        }
        else if (cmd == "update")
        {
            bankAgency.monthlyUpdate();
        }
        else if (cmd == "show")
        {
            std::cout << bankAgency << "\n";
        }
        else
        {
            std::cout << "Invalid!\n";
        }
    }
}