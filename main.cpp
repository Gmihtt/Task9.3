#include <iostream>

class Person
{
public:
    virtual void info() = 0;
    virtual ~Person() {}
};

class Terrorist : public Person
{
public:
    void info() {
        std::cout << "Terrorist" << std::endl;
    };
};

class SpecialSoldier: public Person
{
public:
    void info() {
        std::cout << "SpecialSoldier" << std::endl;
    };
};

class Hostage: public Person
{
public:
    void info() {
        std::cout << "Hostage" << std::endl;
    };
};

class Factory
{
public:
    virtual Person* createPerson() = 0;
    virtual ~Factory() {}
};

class FactoryTerrorist: public Factory
{
public:
    Person* createPerson() override {
        return new Terrorist;
    }
};

class FactorySpecialSoldier: public Factory
{
public:
    Person* createPerson() override {
        return new SpecialSoldier;
    }
};

class FactoryHostage: public Factory
{
public:
    Person* createPerson() override {
        return new Hostage;
    }
};

int main()
{
    FactoryTerrorist* factoryTerrorist = new FactoryTerrorist;
    FactorySpecialSoldier*  factorySpecialSoldier = new FactorySpecialSoldier ;
    FactoryHostage*  factoryHostage  = new FactoryHostage ;

    Person * p = factoryTerrorist->createPerson();
    p->info();
    p = factoryHostage->createPerson();
    p->info();
    p = factorySpecialSoldier->createPerson();
    p->info();
}