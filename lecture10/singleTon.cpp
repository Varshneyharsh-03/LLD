#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Singleton
{
private:
  static Singleton *instance;
  Singleton()
  {
    cout << "Singleton instance created." << endl;
  }

public:
  static Singleton *getInstance()
  {
    if (instance == nullptr)
    {
      instance = new Singleton();
    }
    return instance;
  }
};
Singleton *Singleton::instance = nullptr;

int main()
{
  Singleton *s1 = Singleton::getInstance();
  Singleton *s2 = Singleton::getInstance();
  if (s1 == s2)
  {
    cout << "Both pointers point to the same instance." << endl;
  }
  else
  {
    cout << "Pointers point to different instances." << endl;
  }
  return 0;
}