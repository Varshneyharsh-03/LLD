#include <iostream>
#include <string>
#include <vector>

using namespace std;
class BankAccount
{
protected:
  double balance;

public:
  BankAccount(double b)
  {
    if (b < 0)
    {
      throw invalid_argument("Balance cannot be negative");
    }
    balance = b;
  }

  virtual void withdraw(double amount)
  {
    if (balance < amount)
    {
      throw out_of_range("Insufficient balance for withdrawal");
    }
    else
    {
      balance -= amount;
      cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
    }
  }
};

class CheatAccount : public BankAccount
{
public:
  CheatAccount(double b) : BankAccount(b) {};

  void withdraw(double amount) override
  {
    balance -= amount;
    cout << "CheatAccount: Withdrawn: " << amount << ", New Balance: " << balance << endl;
  }
};
int main()
{
  BankAccount *account = new BankAccount(1000);
  BankAccount *cheatAccount = new CheatAccount(1000);

  return 0;
}