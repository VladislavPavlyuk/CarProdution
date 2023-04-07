#include <iostream>
#include <string>

using namespace std;

class Car
{
	string name, body, gear;
	int power = 0;
	int weels = 0;

public:
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return this->name;
	}
	void SetBody(string body)
	{
		this->body = body;
	}
	string GetBody()
	{
		return this->body;
	}
	void SetPower(int power)
	{
		this->power = power;
	}
	int GetPower()
	{
		return this->power;
	}
	void SetWeels(int weels)
	{
		this->weels = weels;
	}
	int GetWeels()
	{
		return this->weels;
	}
	void SetGear(string gear)
	{
		this->gear = gear;
	}
	string GetGear()
	{
		return this->gear;
	}

	void ShowCar()
	{
		cout << GetName() + "\t" << GetBody() + "\t" << "\t" << GetPower() + "\t" << GetWeels() + "\t" << GetGear() + "\n";
	}
};


class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	virtual void BuildName() abstract;
	virtual void BuildBody() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWeels() abstract;
	virtual void BuildGear() abstract;
};


class DaewooLanosBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Dawoo Lanos");
	}
	void BuildBody() override
	{
		car.SetBody("sedan");
	}
	void BuildEngine() override
	{
		car.SetPower(98);
	}
	void BuildWeels() override
	{
		car.SetWeels(13);
	}
	void BuildGear() override
	{
		car.SetGear("5 Manual");
	}
};

class FordProbeBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Ford Probe");
	}
	void BuildBody() override
	{
		car.SetBody("coupe");
	}
	void BuildEngine() override
	{
		car.SetPower(160);
	}
	void BuildWeels() override
	{
		car.SetWeels(14);
	}
	void BuildGear() override
	{
		car.SetGear("4 Auto");
	}
};

class UAZPatriot : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("UAZ Patriot");
	}
	void BuildBody() override
	{
		car.SetBody("hatchback");
	}
	void BuildEngine() override
	{
		car.SetPower(120);
	}
	void BuildWeels() override
	{
		car.SetWeels(16);
	}
	void BuildGear() override
	{
		car.SetGear("4 Manual");
	}
};

class HyundaiGetz : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Hyundai Getz");
	}
	void BuildBody() override
	{
		car.SetBody("hatchback");
	}
	void BuildEngine() override
	{
		car.SetPower(66);
	}
	void BuildWeels() override
	{
		car.SetWeels(13);
	}
	void BuildGear() override
	{
		car.SetGear("4 Auto");
	}
};

// Director(распор€дитель) - конструирует объект (Car), пользу€сь интерфейсом Builder
class Shop
{
	CarBuilder* carBuilder;
public:
	void SetCarBuilder(CarBuilder* pb)
	{
		carBuilder = pb;
	}
	Car GetCar()
	{
		return carBuilder->GetCar();
	}
	void ConstructCar()
	{
		carBuilder->BuildName();
		carBuilder->BuildBody();
		carBuilder->BuildEngine();
		carBuilder->BuildWeels();
		carBuilder->BuildGear();
	}
};

// клиент создает объект-распор€дитель Director и конфигурирует его нужным объектом-строителем Builder
void client(CarBuilder* builder)
{
	Shop shop;
	shop.SetCarBuilder(builder);
	shop.ConstructCar();
	Car car = shop.GetCar();
	car.ShowCar();
}

void ShowHead()
{
	cout << "Car" << "\t" << "\t" << "Body" << "\t" << "\t" << "Power" << "\t" << "Weels" << "\t" << "Gear" << "\n";
}

int main()
{
	ShowHead();

	CarBuilder* builder = new DaewooLanosBuilder();
	client(builder);
	delete builder;

	builder = new FordProbeBuilder();
	client(builder);
	delete builder;

	builder = new UAZPatriot();
	client(builder);
	delete builder;

	builder = new HyundaiGetz();
	client(builder);
	delete builder;

	system("pause");

	return 0;
}