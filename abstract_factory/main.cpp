#include <iostream>


class Button
{
public:
	virtual void print() = 0;
};

class Checkbox
{
public:
	virtual void print() = 0;
};

class WinButton : public Button
{
public:
	void print() override {
		std::cout << "WinButton\n";
	}
};

class WinCheckbox : public Checkbox
{
public:
	void print() override {
		std::cout << "WinCheckbox\n";
	}
};

class MacButton : public Button
{
public:
	void print() override {
		std::cout << "MacButton\n";
	}
};

class MacCheckbox : public Checkbox
{
public:
	void print() override {
		std::cout << "MacCheckbox\n";
	}
};

class GUIFactory
{
public:
	virtual Button* createButton() = 0;
	virtual Checkbox* createCheckbox() = 0;
};

class WinFactory : public GUIFactory
{
public:
	Button* createButton() override {
		return new WinButton();
	}

	Checkbox* createCheckbox() override {
		return new WinCheckbox();
	}
};

class MacFactory : public GUIFactory
{
public:
	Button* createButton() override {
		return new MacButton();
	}

	Checkbox* createCheckbox() override {
		return new MacCheckbox();
	}
};

int main()
{
	int a;
	std::cin >> a;

	GUIFactory* factory;

	if (a < 10) {
		factory = new WinFactory();
	}
	else {
		factory = new MacFactory();
	}

	Button* btn = factory->createButton();
	btn->print();

	Checkbox* ckb = factory->createCheckbox();
	ckb->print();

	delete factory;
	delete btn;
	delete ckb;

	return 0;
}

















