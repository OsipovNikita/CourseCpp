#include<iostream>
#include<string>


/**
*  ласс ќдиночка предоставл€ет метод `GetInstance`, который ведет себя как
* альтернативный конструктор и позволяет клиентам получать один и тот же
* экземпляр класса при каждом вызове
*/
class Singleton
{
	/**
	*  онструктор ќдиночки всегда должен быть скрытым, чтобы предотвратить
	* создание объекта через оператор new.
	*/

private:
	Singleton(const std::string value) : value_(value)
	{
	}

	static Singleton* singleton_;

	std::string value_;

	/**
	* ќдиночки не должны быть клонируемыми.
	*/
	Singleton(Singleton &other) = delete;
	/**
	* Singletons should not be assignable.
	*/
	void operator=(const Singleton &);// = delete;
	/**
	* Ёто статический метод, управляющий доступом к экземпляру одиночки. 
	ѕри первом запуске, он создает экземпляр одиночки и помещает его в статическое поле. 
	ѕри последующих запусках, он возвращает клиенту объект, хранящийся в статическом поле.
	*/
public:
	static Singleton *GetInstance(const std::string& value);
	/**
	* ќдиночка должен содержать некоторую бизнес-логику, которая
	* может быть выполнена на его экземпляре.
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