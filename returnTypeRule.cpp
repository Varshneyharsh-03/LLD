#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
};
class Dog : public Animal
{
};

class Parent
{
public:
  virtual Animal *getAnimal()
  {
    cout << "Parent getAnimal Called" << endl;
    return new Animal();
  }
};

class Child : public Parent
{
public:
  Dog *getAnimal() override
  {
    cout << "Child getAnimal Called" << endl;
    return new Dog();
  }
};

class Client
{
private:
  Parent *p;

public:
  Client(Parent *p)
  {
    this->p = p;
  }
  void takeAnimal()
  {
    p->getAnimal();
  }
};

int main()
{
  Parent *p = new Parent();
  Child *c = new Child();

  Client *c1 = new Client(p);
  c1->takeAnimal();

  return 0;
}