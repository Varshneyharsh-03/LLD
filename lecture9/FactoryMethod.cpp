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

class WheatRegularBurger : public Burger
{
public:
  void prepare() override
  {
    cout << "Preparing a wheat regular burger." << endl;
  }
};

class WheatPremiumBurger : public Burger
{
public:
  void prepare() override
  {
    cout << "Preparing a wheat premium burger." << endl;
  }
};

class WheatCheeseBurger : public Burger
{
public:
  void prepare() override
  {
    cout << "Preparing a wheat cheese burger." << endl;
  }
};

class BurgerFactory
{
public:
  virtual Burger *createBurger(string type) = 0;
};

class BurgerSingh : public BurgerFactory
{
public:
  Burger *createBurger(string type) override
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

class BurgerKing : public BurgerFactory
{
public:
  Burger *createBurger(string type) override
  {
    if (type == "regular")
    {
      return new WheatRegularBurger();
    }
    else if (type == "premium")
    {
      return new WheatPremiumBurger();
    }
    else if (type == "cheese")
    {
      return new WheatCheeseBurger();
    }
    else
    {
      return new WheatRegularBurger();
    }
  }
};

int main()
{
  BurgerFactory *burgerSingh = new BurgerSingh();
  Burger *burger1 = burgerSingh->createBurger("regular");
  burger1->prepare();
  delete burger1;

  BurgerFactory *burgerKing = new BurgerKing();
  Burger *burger2 = burgerKing->createBurger("premium");
  burger2->prepare();
  delete burger2;

  delete burgerSingh;
  delete burgerKing;

  return 0;
}
