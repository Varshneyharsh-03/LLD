#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parent
{
public:
  virtual void print(string msg)
  {
    cout << "Parent: " << msg << endl;
  }
};

class Child : public Parent
{
public:
  void print(string msg) override
  {
    cout << "Child: " << msg << endl;
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

  void printMsg()
  {
    p->print("Hello");
  }
};

int main()
{
  Parent *p = new Parent();
  Child *c = new Child();

  Client *c1 = new Client(p);
  c1->printMsg(); // Should print "Parent: Hello"
  Client *c2 = new Client(c);
  c2->printMsg(); // Should print "Child: Hello"
  delete p;
  delete c;
  delete c1;
  delete c2;
  return 0;
}
