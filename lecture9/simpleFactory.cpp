#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Burger
{
public:
  virtual void prepare() = 0;
  virtual ~Burger() {}
};

class RegularBurger : public Burger
{
public:
  void prepare() override
  {
    cout << "Preparing a regular burger." << endl;
  }
};

class PremiumBurger : public Burger
{
public:
  void prepare() override
  {
    cout << "Preparing a premium burger." << endl;
  }
};

class CheeseBurger : public Burger
{
public:
  void prepare() override
  {
    cout << "Preparing a cheese burger." << endl;
  }
};

class BurgerFactory
{
public:
  Burger *createBurget(string type)
  {
    if (type == "regular")
    {
      return new RegularBurger();
    }
    else if (type == "premium")
    {
      return new PremiumBurger();
    }
    else if (type == "cheese")
    {
      return new CheeseBurger();
    }
    else
    {
      return new RegularBurger();
    }
  }
};

int main()
{
  string type;
  cin >> type;

  BurgerFactory *factory = new BurgerFactory();
  Burger *burget = factory->createBurget(type);
  burget->prepare();
  delete burget;
  delete factory;
  return 0;
}