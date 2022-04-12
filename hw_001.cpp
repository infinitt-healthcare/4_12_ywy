#include <iostream>
#include <vector>
using namespace std;


class Calc
{
public:
	virtual double calc(const double a, const double b) const = 0;
};

class AddCalc : public Calc
{
public:
	AddCalc() {}
	virtual double calc(const double a, const double b) const override
	{
		return a + b;
	}
};

class SubCalc : public Calc
{
public:
	virtual double calc(const double a, const double b) const override
	{
		return a - b;
	}
};

class MulCalc : public Calc
{
public:
	virtual double calc(const double a, const double b) const override
	{
		return a * b;
	}
};

class DivCalc : public Calc
{
public:
	virtual double calc(const double a, const double b) const override
	{
		return a / b;
	}
};

double MyCalc(Calc& obj, const double a, const double b)
{
	cout << "a: " << a << ", b: " << b << endl;
	cout << typeid(obj).name()<<" called"<<endl;
	return obj.calc(a, b);
}

double cin_double() 
{
	double _input;
	do
	{
		cout <<"값 입력 >>";
		cin >> _input;

		if (!cin.fail())
		{
			break;
		}
		else
		{
			cin.clear();
		}
	} while (1);
	return _input;
}

const bool sCalc(const vector<Calc*>& const v) 
{
	int _menu;
	double a, b;

	cout << " 1. add  / 2. sub / 3. mul / 4. div / 이외 종료"<<endl;
	do
	{
		cout << "menu >> ";
		cin >> _menu;

		if (!cin.fail())
		{
			break;
		}
		else
		{
			cin.clear();
		}
	} while (1);

	if (_menu > 4)
		return false;
	a = cin_double();
	b = cin_double();

	switch (_menu)
	{
	case 1:
	{
		cout << MyCalc(*v.at(0), a, b) << endl;
		break;
	}

	case 2:
	{
		cout << MyCalc(*v.at(1), a, b) << endl;
		break;
	}
		
	case 3:
	{
		cout << MyCalc(*v.at(2), a, b) << endl;
		break;
	}
	case 4:
	{
		if (b == 0)
		{
			while (!b)
			{
				cout << "div  b 피연산자가 0입니다." << endl;
				b = cin_double();
			}
		}
		
		cout << MyCalc(*v.at(3), a, b) << endl;
		break;
	}
	};
}
int main()
{
	AddCalc add;
	SubCalc sub;
	MulCalc mul;
	DivCalc div;

	const vector<Calc*> const vCalc = { &add, &sub, &mul, &div };

	bool isProgress = true;
	while (isProgress)
	{
		isProgress = sCalc(vCalc);
	}
};
