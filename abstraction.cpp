#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
  virtual void startEngine() = 0;
  virtual void shiftGear(int gear) = 0;
  virtual void stopEngine() = 0;
  virtual void accelerate() = 0;
  virtual void brake() = 0;
  virtual ~Car() {}
};

class SportsCar : public Car
{
public:
  string brand;
  string model;
  int currentSpeed;
  bool isEngineOn;
  int currentGear;

  SportsCar(string brand, string model)
  {
    this->brand = brand;
    this->model = model;
    this->currentSpeed = 0;
    this->isEngineOn = false;
    this->currentGear = 0;
  }

  void startEngine()
  {
    isEngineOn = true;
    cout << "Engine started for " << brand << " " << model << endl;
  }

  void shiftGear(int gear)
  {
    if (gear < 0 || gear > 6)
    {
      cout << "Invalid gear: " << gear << endl;
      return;
    }
    currentGear = gear;
    cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
  }

  void stopEngine()
  {
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0;
    cout << "Engine stopped for " << brand << " " << model << endl;
  }

  void accelerate()
  {
    if (!isEngineOn)
    {
      cout << "Cannot accelerate, engine is off!" << endl;
      return;
    }
    currentSpeed += 10; // Increase speed by 10 units
    cout << "Accelerating " << brand << " " << model << " to speed: " << currentSpeed << endl;
  }

  void brake()
  {
    if (!isEngineOn)
    {
      cout << "Cannot brake, engine is off!" << endl;
      return;
    }
    if (currentSpeed > 0)
    {
      currentSpeed -= 10; // Decrease speed by 10 units
      if (currentSpeed < 0)
        currentSpeed = 0; // Ensure speed doesn't go negative
      cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << endl;
    }
    else
    {
      cout << brand << " " << model << " is already stopped." << endl;
    }
  }
};

int main()
{
  Car *myCar = new SportsCar("Porsche", "911");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->brake();
  myCar->shiftGear(2);
  myCar->accelerate();
  myCar->brake();
  myCar->stopEngine();
  delete myCar; // Clean up memory
  return 0;
}