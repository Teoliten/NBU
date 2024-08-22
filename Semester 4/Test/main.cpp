#include <iostream>
#include <string>

using namespace std;

class vehicle
{
private:
  int wheels;
  string color;
  int seats;

public:
  vehicle();
  void setWheels(int wheels)
  {
    this->wheels = wheels;
  }

  int getWheels()
  {
    return wheels;
  }
};

vehicle::vehicle()
{
  wheels = 0;
  color = "";
  seats = 0;
}

class car : public vehicle
{
public:
  int HP;

private:
};

int main()
{
  vehicle v;
  v.setWheels(5);
  cout << v.getWheels() << endl;

  car c;
  c.HP = 5;
  c.setWheels(4);
  cout << c.getWheels() << endl;
  return 0;
}