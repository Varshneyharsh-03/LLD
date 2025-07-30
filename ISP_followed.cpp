#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TwoDShapes
{
public:
  virtual double area() = 0; // Pure virtual function
};

class ThreeDShapes
{
  virtual double volume() = 0;
  virtual double area() = 0;
};

class Reactangle : public TwoDShapes
{
private:
  double length, width;

public:
  Reactangle(double length, double width)
  {
    this->length = length;
    this->width = width;
  }

  double area() override
  {
    return length * width;
  }
};

class Square : public TwoDShapes
{
private:
  double side;

public:
  Square(double side)
  {
    this->side = side;
  }

  double area() override
  {
    return side * side;
  }
};

class Cube : public ThreeDShapes
{
private:
  double side;

public:
  Cube(double side)
  {
    this->side = side;
  }
  double area() override
  {
    return 6 * side * side;
  }

  double volume() override
  {
    return side * side * side;
  }
};

int main()
{
  Reactangle *rec = new Reactangle(5, 10);
  Square *sq = new Square(4);
  Cube *cube = new Cube(3);
  cout << "Area of Rectangle: " << rec->area() << endl;
  cout << "Area of Square: " << sq->area() << endl;
  cout << "Area of Cube: " << cube->area() << endl;
  cout << "Volume of Cube: " << cube->volume() << endl;
  delete rec;
  delete sq;
  delete cube;
  return 0;
}