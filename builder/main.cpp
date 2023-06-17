#include <iostream>
#include <string>

class Pizza {
public:
    void setDough(const std::string& dough) {
        dough_ = dough;
    }

    void setSauce(const std::string& sauce) {
        sauce_ = sauce;
    }

    void setTopping(const std::string& topping) {
        topping_ = topping;
    }

    void printPizza() {
        std::cout << "Pizza with " << dough_ << " dough, " << sauce_ << " sauce and " << topping_ << " topping." << std::endl;
    }

private:
    std::string dough_;
    std::string sauce_;
    std::string topping_;
};

class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza* getPizza() = 0;
};

class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    HawaiianPizzaBuilder() : pizza_(new Pizza()) {}

    void buildDough() override {
        pizza_->setDough("cross");
    }

    void buildSauce() override {
        pizza_->setSauce("mild");
    }

    void buildTopping() override {
        pizza_->setTopping("ham and pineapple");
    }

    Pizza* getPizza() override {
        return pizza_;
    }

private:
    Pizza* pizza_;
};

class SpicyPizzaBuilder : public PizzaBuilder {
public:
    SpicyPizzaBuilder() : pizza_(new Pizza()) {}

    void buildDough() override {
        pizza_->setDough("pan baked");
    }

    void buildSauce() override {
        pizza_->setSauce("hot");
    }

    void buildTopping() override {
        pizza_->setTopping("pepperoni and salami");
    }

    Pizza* getPizza() override {
        return pizza_;
    }

private:
    Pizza* pizza_;
};

class Cook {
public:
    void setPizzaBuilder(PizzaBuilder* builder) {
        builder_ = builder;
    }

    void constructPizza() {
        builder_->buildDough();
        builder_->buildSauce();
        builder_->buildTopping();
    }

    Pizza* getPizza() {
        return builder_->getPizza();
    }

private:
    PizzaBuilder* builder_;
};

int main() {
    Cook cook;

    HawaiianPizzaBuilder hawaiianBuilder;
    cook.setPizzaBuilder(&hawaiianBuilder);
    cook.constructPizza();
    Pizza* hawaiianPizza = cook.getPizza();
    hawaiianPizza->printPizza();

    SpicyPizzaBuilder spicyBuilder;
    cook.setPizzaBuilder(&spicyBuilder);
    cook.constructPizza();
    Pizza* spicyPizza = cook.getPizza();
    spicyPizza->printPizza();

    delete hawaiianPizza;
    delete spicyPizza;

    return 0;
}

