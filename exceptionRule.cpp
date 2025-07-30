#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
├── std::logic_error        <-- For logical errors detected before runtime
│   ├── std::invalid_argument   <-- Invalid function argument
│   ├── std::domain_error       <-- Function argument domain error
│   ├── std::length_error       <-- Exceeding valid length limits
│   ├── std::out_of_range       <-- Array or container index out of bounds
│
├── std::runtime_error      <-- For errors that occur at runtime
│   ├── std::range_error        <-- Numeric result out of range
│   ├── std::overflow_error     <-- Arithmetic overflow
│   ├── std::underflow_error
*/

class Parent
{
public:
  virtual void getValue() noexcept(false)
  {
    throw logic_error("Parent exception");
  }
};

class Child : public Parent
{
public:
  void getValue() noexcept(false) override
  {
    throw out_of_range("Child error");
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
  void takeValue()
  {
    try
    {
      p->getValue();
    }
    catch (logic_error &e)
    {
      cout << "Logic error exception occured : " << e.what() << endl;
    }
  }
};

int main()
{
  Parent *p = new Parent();
  Child *c = new Child();
  Client *c1 = new Client(p);
  c1->takeValue();
  return 0;
}