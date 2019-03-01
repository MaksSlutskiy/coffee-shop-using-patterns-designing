#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include<fstream>
#include <vector>
#include<list>
#include <algorithm>
using namespace std;
int choice;
int choice1;
int choice2;

class Size
{
public:
	virtual void size() = 0;

};

class Sugar
{
public:
	virtual void sugar() = 0;
};
class Syrup
{
public:
	virtual void syrup() = 0;
};

class Big :public Size
{
	virtual void size() override
	{
		cout << "Big portion\n";
	}

};
class Little :public Size
{
	virtual void size() override
	{
		cout << "Little portion\n";
	}

};


class SugarLess :public Sugar
{
	virtual void sugar() override
	{
		cout << "Sugar less\n";


	}
};
class SugarOnePortion :public Sugar
{
	virtual void sugar() override
	{
		cout << "Sugar one portion\n";


	}
}; 
class SugarTwoPortion :public Sugar
{
	virtual void sugar() override
	{
		cout << "Sugar two portion\n";


	}
};

class SyrupLess :public Syrup
{
	virtual void syrup() override
	{
		cout << "Syrup less\n";
	}
};
class Chocolate :public Syrup
{
	virtual void syrup() override
	{
		cout << "Chocolate syrup\n";
	}
};
class Banana :public Syrup
{
	virtual void syrup() override
	{
		cout << "Banana syrup\n";
	}
};
class Caramel :public Syrup
{
	virtual void syrup() override
	{
		cout << "Caramel syrup\n";
	}
};


class Buyer
{
public:
	~Buyer() {
		int i;
		for (i = 0; i<sugar.size(); ++i)  delete sugar[i];
		for (i = 0; i<size.size(); ++i)  delete size[i];
		for (i = 0; i<syrup.size(); ++i)  delete syrup[i];
	}
	void info() {
		int i;
		for (i = 0; i<sugar.size(); ++i)  sugar[i]->sugar();
		for (i = 0; i<size.size(); ++i)  size[i]->size();
		for (i = 0; i<syrup.size(); ++i)  syrup[i]->syrup();
	}
	vector<Sugar*> sugar;
	vector<Size*> size;
	vector<Syrup*> syrup;
};

class BuyerFactory
{
public:
	virtual Sugar* createSugar() = 0;
	virtual Size* createSize() = 0;
	virtual Syrup* createSyrup() = 0;
};

class Americano :public BuyerFactory
{
public:

	Sugar * createSugar()
	{
		if (choice == 1)
		{
			return new SugarLess;
		}
		if (choice == 2)
		{
			return new SugarOnePortion;
		}
		if (choice == 3)
		{
			return new SugarTwoPortion;
		}
	}
	Size * createSize()
	{
		if (choice1 == 1)
		{
			return new Big;
		}
		if (choice1 == 2)
		{
			return new Little;
		}
		
	}
	Syrup * createSyrup()
	{
		if (choice2 == 1)
		{
			return new SyrupLess;
		}
		if (choice2 == 2)
		{
			return new Chocolate;
		}
		if (choice2 == 3)
		{
			return new Banana;
		}
		if (choice2 == 4)
		{
			return new Caramel;
		}
	}
	
};
class Cappuccino :public BuyerFactory
{
	Sugar * createSugar()
	{
		if (choice == 1)
		{
			return new SugarLess;
		}
		if (choice == 2)
		{
			return new SugarOnePortion;
		}
		if (choice == 3)
		{
			return new SugarTwoPortion;
		}
	}
	Size * createSize()
	{
		if (choice1 == 1)
		{
			return new Big;
		}
		if (choice1 == 2)
		{
			return new Little;
		}

	}
	Syrup * createSyrup()
	{
		if (choice2 == 1)
		{
			return new SyrupLess;
		}
		if (choice2 == 2)
		{
			return new Chocolate;
		}
		if (choice2 == 3)
		{
			return new Banana;
		}
		if (choice2 == 4)
		{
			return new Caramel;
		}
	}
};
class Latte:public BuyerFactory
{
public:

	Sugar * createSugar()
	{
		if (choice == 1)
		{
			return new SugarLess;
		}
		if (choice == 2)
		{
			return new SugarOnePortion;
		}
		if (choice == 3)
		{
			return new SugarTwoPortion;
		}
	}
	Size * createSize()
	{
		if (choice1 == 1)
		{
			return new Big;
		}
		if (choice1 == 2)
		{
			return new Little;
		}

	}
	Syrup * createSyrup()
	{
		if (choice2 == 1)
		{
			return new SyrupLess;
		}
		if (choice2 == 2)
		{
			return new Chocolate;
		}
		if (choice2 == 3)
		{
			return new Banana;
		}
		if (choice2 == 4)
		{
			return new Caramel;
		}
	}

};
class Order
{
public:
	Buyer * createBuyer(BuyerFactory& factory) {
		Buyer* p = new Buyer;
		p->sugar.push_back(factory.createSugar());
		p->size.push_back(factory.createSize());
		p->syrup.push_back(factory.createSyrup());
		return p;
	}
};

void Shop()
{
	Order order;
	Americano am_factory;
	Cappuccino ca_factory;
	Latte la_factory;
	int ptr;
	while (1)
	{
		cout << "Choose what you want to order\n" << endl;
		cout << "Americano - 1\n";
		cout << "Cappuccino - 2\n";
		cout << "Latte - 3\n";
		cout << "Exit - 0\n\n";
		cin >> ptr;
		if (ptr == 1)
		{
			cout << "Big americano - 1 \n\n";
			cout << "Little americano - 2 \n\n";
			cin >> choice1;
			cout << "Sugar less - 1 \n\n";
			cout << "Sugar one portion - 2\n\n";
			cout << "Sugar two portion - 3\n\n";
			cin >> choice;
			cout << "Syrup less - 1\n\n";
			cout << "Chocolate syrup - 2\n\n";
			cout << "Banana syrup - 3\n\n";
			cout << "Caramel syrup - 4\n\n";
			cin >> choice2;
			Buyer * am = order.createBuyer(am_factory);
			cout << "Order completed successfully\n" << endl;
			Sleep(2000);
			system("cls");
			cout << "Your receipt\n" << endl;
			cout << "Americano" << endl;
			am->info();
			cout << endl;
		}
		if (ptr == 2)
		{
			cout << "Big cappuccino - 1 \n\n";
			cout << "Little cappuccino - 2 \n\n";
			cin >> choice1;
			cout << "Sugar less - 1 \n\n";
			cout << "Sugar one portion - 2\n\n";
			cout << "Sugar two portion - 3\n\n";
			cin >> choice;
			cout << "Syrup less - 1\n\n";
			cout << "Chocolate syrup - 2\n\n";
			cout << "Banana syrup - 3\n\n";
			cout << "Caramel syrup - 4\n\n";
			cin >> choice2;
			Buyer * ca = order.createBuyer(ca_factory);
			cout << "Order completed successfully\n" << endl;
			Sleep(2000);
			system("cls");
			cout << "Your receipt\n" << endl;
			cout << "Cappuccino" << endl;
			ca->info();
			cout << endl;
		}
		if (ptr == 3)
		{
			cout << "Big latte - 1 \n\n";
			cout << "Little latte - 2 \n\n";
			cin >> choice1;
			cout << "Sugar less - 1 \n\n";
			cout << "Sugar one portion - 2\n\n";
			cout << "Sugar two portion - 3\n\n";
			cin >> choice;
			cout << "Syrup less - 1\n\n";
			cout << "Chocolate syrup - 2\n\n";
			cout << "Banana syrup - 3\n\n";
			cout << "Caramel syrup - 4\n\n";
			cin >> choice2;
			Buyer * la = order.createBuyer(la_factory);
			cout << "Order completed successfully\n" << endl;
			Sleep(2000);
			system("cls");
			cout << "Your receipt\n" << endl;
			cout << "latte" << endl;
			la->info();
			cout << endl;
		}
		if (ptr == 0)
			break;
	}
}

int main()
{
	Shop();


	system("pause");
	return 0;
}
