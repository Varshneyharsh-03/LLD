#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account
{
public:
  virtual void deposit(double amount) = 0;
  virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public Account
{
private:
  double balance;

public:
  SavingsAccount()
  {
    balance = 0;
  }

  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposited: " << amount << "in the SavingsAcount, New Balance: " << balance << endl;
  }
  void withdraw(double amount)
  {
    if (amount < balance)
    {
      cout << "Your account does not have sufficient balance to withdraw" << endl;
    }
    else
    {
      balance -= amount;
      cout << "Withdrawn: " << amount << " from the SavingsAcount, New Balance: " << balance << endl;
    }
  }
};

class CurrentAccount : public Account
{
private:
  double balance;

public:
  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposited: " << amount << "in the CurrentAcount, New Balance: " << balance << endl;
  }
  void withdraw(double amount)
  {
    if (amount < balance)
    {
      cout << "Your account does not have sufficient balance to withdraw" << endl;
    }
    else
    {
      balance -= amount;
      cout << "Withdrawn: " << amount << " from the CurrentAcount, New Balance: " << balance << endl;
    }
  }
};

class FixedTermAccount : public Account
{
private:
  double balance;

public:
  FixedTermAccount()
  {
    balance = 0;
  }
  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposited: " << amount << " in the FixedTermAccount, New Balance: " << balance << endl;
  }
  void withdraw(double amount)
  {
    throw logic_error("Withdrawal not allowed in Fixed Term Account!");
  }
};

class BankClient
{
private:
  vector<Account *> accounts;

public:
  BankClient(vector<Account *> accounts)
  {
    this->accounts = accounts;
  }

  void processTransaction()
  {
    for (auto account : accounts)
    {
      account->deposit(1000);
      try
      {
        account->withdraw(500);
      }
      catch (const logic_error &e)
      {
        cout << e.what() << endl;
      }
    }
  }
};

int main()
{
  vector<Account *> accounts;
  accounts.push_back(new SavingsAccount());
  accounts.push_back(new CurrentAccount());
  accounts.push_back(new FixedTermAccount());
  BankClient *client = new BankClient(accounts);
  client->processTransaction();
  return 0;
}