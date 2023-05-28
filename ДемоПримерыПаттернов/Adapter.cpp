#include <iostream>
/*Адаптер классов
Эта реализация базируется на наследовании:
адаптер наследует оба интерфейса одновременно*/

using namespace std;

// Уже существующий класс температурного датчика окружающей среды
class FahrenheitSensor
{
  public:
      double k;
	// Получить показания температуры в градусах Фаренгейта 
		double getFahrenheitTemp() 
		{
			double t = 132.0;   
      // ...
			return t;
		}
  protected:
		void adjust() {} // Настройка датчика (защищенный метод)
};

class Sensor
{
  public:
    virtual ~Sensor() {}
    virtual double getTemperature() = 0;
    virtual void adjust() = 0;
};

class Adapter : public Sensor, private FahrenheitSensor
{
private:
    // наследуется от Fan
  public:
    Adapter() { }

    double getTemperature() 
	{
      return (getFahrenheitTemp()-32.0)*5.0/9.0;
    }

    void adjust() {
        k = 10;
      FahrenheitSensor::adjust();
    }
};

class MyDDD : public Adapter
{
    void adjust() {
        /// <summary>
        /// //
        /// </summary>
        /// 
        Sensor::adjust();
        FahrenheitSensor::adjust();
    }

};

int main()
{
    Sensor * p = new Adapter();
    p->adjust();
    cout << "Celsius temperature = " << p->getTemperature() << endl;
    delete p;
    return 0;

}

