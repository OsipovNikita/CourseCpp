#include <iostream>
#include <vector>
using namespace std;

// 1. "�����������" ����������������
class Subject 
{
	// 3. ����� ������ ������� ������� Observer
	vector <class Observer *> views;
	int value;

public:
	void attach(Observer *obs) 
	{
		views.push_back(obs);
	}

	void setVal(int val) 
	{
		value = val;
		notify();
	}

	int getVal() 
	{
		return value;
	}

	void notify();
};

// 2. "���������" ����������������
class Observer 
{
	Subject *model;
	int denom;

public:
	Observer(Subject *mod, int div) 
	{
		model = mod;
		denom = div;
		// 4. ����������� �������������� � ��������
		model->attach(this);
	}
	virtual void update() = 0;
protected:
	Subject *getSubject() 
	{
		return model;
	}
	int getDivisor() 
	{
		return denom;
	}
};

void Subject::notify() 
{
	// 5. ��������� ������������
	for (int i = 0; i < views.size(); i++)
		views[i]->update();
}

class DivObserver : public Observer 
{
public:
	DivObserver(Subject *mod, int div) : Observer(mod, div) {}
	void update() 
	{
		// 6. "�����������" ������������ ����������
		int v = getSubject()->getVal(), d = getDivisor();
		cout << v << " div " << d << " is " << v / d << '\n';
	}
};

class ModObserver : public Observer 
{
public:
	ModObserver(Subject *mod, int div) : Observer(mod, div) {}
	void update() 
	{
		int v = getSubject()->getVal(), d = getDivisor();
		cout << v << " mod " << d << " is " << v%d << '\n';
	}
};

int main() 
{
	Subject subj;
	DivObserver divObs1(&subj, 4); // 7. ������ ����������� ����� 
	DivObserver divObs2(&subj, 3); //    � ���� ������������
	ModObserver modObs3(&subj, 3);
	subj.setVal(14);

	return 0;
}