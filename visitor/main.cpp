#include <iostream>
#include <vector>

class ConcreteElementA;
class ConcreteElementB;

class Visitor 
{
public:
    virtual void visit(ConcreteElementA* element) = 0;
    virtual void visit(ConcreteElementB* element) = 0;
};

class Element 
{
public:
    virtual void accept(Visitor* visitor) = 0;
};

class ConcreteElementA : public Element 
{
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }

    void operationA() {
        std::cout << "ConcreteElementA operation A." << std::endl;
    }
};

class ConcreteElementB : public Element 
{
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }

    void operationB() {
        std::cout << "ConcreteElementB operation B." << std::endl;
    }
};

class ConcreteVisitor1 : public Visitor 
{
public:
    void visit(ConcreteElementA* element) override {
        std::cout << "ConcreteVisitor1 visited ConcreteElementA." << std::endl;
        element->operationA();
    }

    void visit(ConcreteElementB* element) override {
        std::cout << "ConcreteVisitor1 visited ConcreteElementB." << std::endl;
        element->operationB();
    }
};

class ConcreteVisitor2 : public Visitor 
{
public:
    void visit(ConcreteElementA* element) override {
        std::cout << "ConcreteVisitor2 visited ConcreteElementA." << std::endl;
        element->operationA();
    }

    void visit(ConcreteElementB* element) override {
        std::cout << "ConcreteVisitor2 visited ConcreteElementB." << std::endl;
        element->operationB();
    }
};

int main() {
    std::vector<Element*> elements;
    elements.push_back(new ConcreteElementA());
    elements.push_back(new ConcreteElementB());

    ConcreteVisitor1 visitor1;
    ConcreteVisitor2 visitor2;

    for (Element* element : elements) {
        element->accept(&visitor1);
    }

    for (Element* element : elements) {
        element->accept(&visitor2);
    }

    for (Element* element : elements) {
        delete element;
    }

    return 0;
}

