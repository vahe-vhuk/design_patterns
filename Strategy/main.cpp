#include <iostream>

class Strategy 
{
public:
    virtual void execute() = 0;
};

class ConcreteStrategyA : public Strategy 
{
public:
    void execute() override {
        std::cout << "Executing strategy A." << std::endl;
    }
};

class ConcreteStrategyB : public Strategy 
{
public:
    void execute() override {
        std::cout << "Executing strategy B." << std::endl;
    }
};

class ConcreteStrategyC : public Strategy 
{
public:
    void execute() override {
        std::cout << "Executing strategy C." << std::endl;
    }
};

class Context 
{
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeStrategy() {
        strategy->execute();
    }
};

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;
    ConcreteStrategyC strategyC;

    Context context(&strategyA);

    context.executeStrategy();

    context.setStrategy(&strategyB);
    context.executeStrategy();

    context.setStrategy(&strategyC);
    context.executeStrategy();

    return 0;
}

