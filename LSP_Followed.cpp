#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DepositAccount
{
public:
  virtual void deposit(double amount) = 0; // Pure virtual function
};

class WithdrawalAccount : public DepositAccount
{
public:
  virtual void withdraw(double amount) = 0; // Pure virtual function
};

class SavingsAccount : public WithdrawalAccount
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

class CurrentAccount : public WithdrawalAccount
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

class FixedTermAccount : public DepositAccount
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
  vector<WithdrawalAccount *> withdraw_accounts;
  vector<DepositAccount *> deposit_accounts;

public:
  BankClient(vector<WithdrawalAccount *> withdraw_accounts,
             vector<DepositAccount *> deposit_accounts)
  {
    this->withdraw_accounts = withdraw_accounts;
    this->deposit_accounts = deposit_accounts;
  }

  void processTransaction()
  {
    for (auto account : withdraw_accounts)
    {
      account->deposit(1000); // Example deposit amount
      account->withdraw(100); // Example withdrawal amount
    }

    for (auto account : deposit_accounts)
    {
      account->deposit(1000);
    }
  }
};

int main()
{
  vector<WithdrawalAccount *> withdraw_accounts;
  vector<DepositAccount *> deposit_accounts;

  withdraw_accounts.push_back(new SavingsAccount());
  withdraw_accounts.push_back(new CurrentAccount());
  deposit_accounts.push_back(new FixedTermAccount());
  BankClient *client = new BankClient(withdraw_accounts, deposit_accounts);
  client->processTransaction();
  return 0;
}