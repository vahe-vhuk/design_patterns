#include <iostream>
#include <vector>

class Command
{
public:
	virtual ~Command() {};
	virtual void execute() = 0;
};

class Light
{
public:
	void turnOn() {
		std::cout << "Light is on\n";
	}

	void turnOff() {
		std::cout << "Light is off\n";
	}
};

class TurnOnCommand : public Command
{
private:
	Light* light;
public:
	TurnOnCommand(Light* light)
		:	light(light)
	{}
	void execute() override {
		light->turnOn();
	}
};

class TurnOffCommand : public Command
{
private:
	Light* light;
public:
	TurnOffCommand(Light* light)
		:	light(light)
	{}
	void execute() override {
		light->turnOff();
	}
};

class RemoteControl
{
private:
	std::vector<Command*> commands;
public:
	void addCommand(Command* com) {
		commands.push_back(com);
	}

	void executeCommands() {
		for (Command* com : commands) {
			com->execute();
		}
	}
};



int main()
{
	Light li;
	RemoteControl contr;

	Command* turnon = new TurnOnCommand(&li);
	Command* turnoff = new TurnOffCommand(&li);

	contr.addCommand(turnon);
	contr.addCommand(turnoff);

	contr.executeCommands();

	delete turnon;
	delete turnoff;

	return 0;
}









