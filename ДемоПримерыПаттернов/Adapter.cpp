#include <iostream>
/*������� �������
��� ���������� ���������� �� ������������:
������� ��������� ��� ���������� ������������*/

using namespace std;

// ��� ������������ ����� �������������� ������� ���������� �����
class FahrenheitSensor
{
  public:
      double k;
	// �������� ��������� ����������� � �������� ����������
		double getFahrenheitTemp() 
		{
			double t = 132.0;   
      // ...
			return t;
		}
  protected:
		void adjust() {} // ��������� ������� (���������� �����)
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
    // ����������� �� Fan
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

