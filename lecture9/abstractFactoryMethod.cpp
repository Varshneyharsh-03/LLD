#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GarlicBread
{
public:
  virtual void prepare() = 0;
  virtual ~GarlicBread() {}
};

class RegularGarlicBread : public GarlicBread
{
public:
  void prepare() override
  {
    cout << "Preparing a regular garlic bread." << endl;
  }
};

class WheatRegularGarlicBread : public GarlicBread
{
public:
  void prepare() override
  {
    cout << "Preparing a wheat regular garlic bread." << endl;
  }
};

class CheeseGarlicBread : public GarlicBread
{
public:
  void prepare() override
  {
    cout << "Preparing a cheese garlic bread." << endl;
  }
};

class WheatCheeseGarlicBread : public GarlicBread
{
public:
  void prepare() override
  {
    cout << "Preparing a wheat cheese garlic bread." << endl;
  }
};

class PremiumGarlicBread : public GarlicBread
{
public:
  void prepare() override
  {
    cout << "Preparing a premium garlic bread." << endl;
  }
};

class WheatPremiumGarlicBread : public GarlicBread
{
public:
  void prepare() override
  {
    cout << "Preparing a wheat premium garlic bread." << endl;
  }
};

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
  virtual GarlicBread *createGarlicBread(string type) = 0;
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

  GarlicBread *createGarlicBread(string type) override
  {
    if (type == "regular")
    {
      return new RegularGarlicBread();
    }
    else if (type == "premium")
    {
      return new PremiumGarlicBread();
    }
    else if (type == "cheese")
    {
      return new CheeseGarlicBread();
    }
    else
    {
      return new RegularGarlicBread();
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
  GarlicBread *createGarlicBread(string type) override
  {
    if (type == "regular")
    {
      return new WheatRegularGarlicBread();
    }
    else if (type == "premium")
    {
      return new WheatPremiumGarlicBread();
    }
    else if (type == "cheese")
    {
      return new WheatCheeseGarlicBread();
    }
    else
    {
      return new WheatRegularGarlicBread();
    }
  }
};

int main()
{
  BurgerFactory *burgerSingh = new BurgerSingh();
  Burger *burger1 = burgerSingh->createBurger("regular");
  GarlicBread *garlicBread1 = burgerSingh->createGarlicBread("premium");
  burger1->prepare();
  garlicBread1->prepare();
  delete burger1;

  BurgerFactory *burgerKing = new BurgerKing();
  Burger *burger2 = burgerKing->createBurger("premium");
  GarlicBread *garlicBread2 = burgerKing->createGarlicBread("cheese");
  burger2->prepare();
  garlicBread2->prepare();
  delete burger2;

  delete burgerSingh;
  delete burgerKing;

  return 0;
}
