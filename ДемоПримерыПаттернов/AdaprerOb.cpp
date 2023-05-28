#include <iostream>

/*Адаптер объектов
Эта реализация использует принцип композиции:
объект адаптера содержит ссылку на служебный объект*/

using namespace std;

// Уже существующий класс температурного датчика окружающей среды
class FahrenheitSensor
{
  public:
    // Получить показания температуры в градусах Фаренгейта 
		double getFahrenheitTemp() 
		{
			double t = 142.0;
      // ...
			return t;
		}
};

class Sensor
{
  public:
    virtual ~Sensor() {}
    virtual double getTemperature() = 0;
};

class Adapter : public Sensor
{
  public:
    Adapter( FahrenheitSensor* p ) : p_fsensor(p) 
	{  }

   ~Adapter() 
   {
      delete p_fsensor;
   }

    double getTemperature() 
	{
      return (p_fsensor->getFahrenheitTemp()-32.0)*5.0/9.0;
    }

  private:
    FahrenheitSensor* p_fsensor;
};

int main()
{
  Sensor* p = new Adapter( new FahrenheitSensor);
  cout << "Celsius temperature = " << p->getTemperature() << endl;
  delete p;
  return 0;
}


