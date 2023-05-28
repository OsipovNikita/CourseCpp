#include<iostream>
#include<string>


/**
* ����� �������� ������������� ����� `GetInstance`, ������� ����� ���� ���
* �������������� ����������� � ��������� �������� �������� ���� � ��� ��
* ��������� ������ ��� ������ ������
*/
class Singleton
{
	/**
	* ����������� �������� ������ ������ ���� �������, ����� �������������
	* �������� ������� ����� �������� new.
	*/

private:
	Singleton(const std::string value) : value_(value)
	{
	}

	static Singleton* singleton_;

	std::string value_;

	/**
	* �������� �� ������ ���� ������������.
	*/
	Singleton(Singleton &other) = delete;
	/**
	* Singletons should not be assignable.
	*/
	void operator=(const Singleton &);// = delete;
	/**
	* ��� ����������� �����, ����������� �������� � ���������� ��������. 
	��� ������ �������, �� ������� ��������� �������� � �������� ��� � ����������� ����. 
	��� ����������� ��������, �� ���������� ������� ������, ���������� � ����������� ����.
	*/
public:
	static Singleton *GetInstance(const std::string& value);
	/**
	* �������� ������ ��������� ��������� ������-������, �������
	* ����� ���� ��������� �� ��� ����������.
	*/
	void SomeBusinessLogic()
	{
		// ...
	}

	std::string value() const {
		return value_;
	}
};

Singleton* Singleton::singleton_ = nullptr;;

/**
* Static methods should be defined outside the class.
*/
Singleton *Singleton::GetInstance(const std::string& value)
{
	/**
	* This is a safer way to create an instance. instance = new Singleton is
	* dangeruous in case two instance threads wants to access at the same time
	*/
	if (singleton_ == nullptr) {
		singleton_ = new Singleton(value);
	}
	return singleton_;
}

void Foo() {
	Singleton* singleton = Singleton::GetInstance("FOO");
	std::cout << singleton->value() << "\n";
}

void Bar() {
	Singleton* singleton = Singleton::GetInstance("BAR");
	std::cout << singleton->value() << "\n";
}


int main()
{
    Foo();
	Bar();

	return 0;
}