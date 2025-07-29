#include <iostream>
#include <string>

using namespace std;

class Car
{
protected:
  string brand;
  string model;
  int currentSpeed;
  bool isEngineOn;

public:
  Car(string model, string brand)
  {
    this->brand = brand;
    this->model = model;
    this->currentSpeed = 0;
    this->isEngineOn = false;
  }
  virtual ~Car() {}

  void startEngine()
  {
    isEngineOn = true;
    cout << "Engine started for " << brand << " " << model << endl;
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
  void stopEngine()
  {
    isEngineOn = false;
    currentSpeed = 0;
    cout << "Engine stopped for " << brand << " " << model << endl;
  }
  void brake()
  {
    if (!isEngineOn)
    {
      cout << "Cannot brake, engine is off!" << endl;
      return;
    }
    currentSpeed -= 10; // Decrease speed by 10 units
    if (currentSpeed < 0)
      currentSpeed = 0;
    cout << "Braking " << brand << " " << model << " to speed: " << currentSpeed << endl;
  }
};

class ManualCar : public Car
{
private:
  int currentGear;

public:
  ManualCar(string model, string brand) : Car(model, brand), currentGear(0) {}

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
};

class ElectricCar : public Car
{
private:
  int batteryLevel;

public:
  ElectricCar(string model, string brand) : Car(model, brand)
  {
    batteryLevel = 100; // Assume battery starts fully charged
  }

  void chargeBattery()
  {
    batteryLevel = 100; // Charge the battery to full
    cout << "Battery charged for " << brand << " " << model << endl;
  }
};

int main()
{
  ManualCar *myManualCar = new ManualCar("Suzuki", "WagonR");
  myManualCar->startEngine();
  myManualCar->shiftGear(1); // specific to manual car
  myManualCar->accelerate();
  myManualCar->brake();
  myManualCar->stopEngine();
  delete myManualCar;

  cout << "----------------------" << endl;

  ElectricCar *myElectricCar = new ElectricCar("Tesla", "Model S");
  myElectricCar->chargeBattery(); // specific to electric car
  myElectricCar->startEngine();
  myElectricCar->accelerate();
  myElectricCar->brake();
  myElectricCar->stopEngine();
  delete myElectricCar;
  return 0;
}