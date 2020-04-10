/*
 *
 * The Builder Creational Pattern is used to separate the construction of a complex object from
 * its representation so that the same construction process can create different objects representations.
 *
 * Problem
 * We want to construct a complex object, however we do not want to have a complex constructor member or
 * one that would need many arguments.
 * Solution
 * Define an intermediate object whose member functions define the desired object part
 * by part before the object is available to the client. Builder Pattern lets us defer the construction of the object until all the options for creation have been specified.
 */

#include <iostream>
#include <string>
#include <memory>

#define ENABLE_THIS_MAIN  ( 1 )

class car
{
public:
    std::string color;
    std::string brand;
    std::string model;
    int horse_power;

    void set_color(std::string color) {this->color = color;}
    void set_brand(std::string brand) {this->brand = brand;}
    void set_model(std::string model) {this->model = model;}
    void set_horse_power(int horse_power) {this->horse_power = horse_power;}

    std::string get_color() const {return color;}
    std::string get_brand() const {return brand;}
    std::string get_model() const {return model;}
    int get_horse_power() const {return horse_power;}

    void print_car_details()
    {
        std::cout << "*******************************" << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Horse Power: " << horse_power << std::endl;
        std::cout << "*******************************" << std::endl;
    }
};

class car_builder
{
protected:
    car *car_p;

public:
    virtual ~car_builder() {}

    car *get_car()
    {
        return car_p;
    }

    virtual void build_car_specs() = 0;
};

class audi_builder:public car_builder
{
public:
    virtual ~audi_builder() {}

    audi_builder()
    {
        car_p = new car();
    }

    virtual void build_car_specs() override
    {
        car_p->set_brand("Audi");
        car_p->set_color("Black");
        car_p->set_model("A8");
        car_p->set_horse_power(449);
    }
};

class bmw_builder:public car_builder
{
public:
    virtual ~bmw_builder() {}

    bmw_builder()
    {
        car_p = new car();
    }

    virtual void build_car_specs() override
    {
        car_p->set_brand("BMW");
        car_p->set_color("Blue");
        car_p->set_model("i8");
        car_p->set_horse_power(420);
    }
};

class car_order_manager
{
private:
    car_builder *car_builder_p;
public:
    void create_order (car_builder *car_builder_p)
    {
        this->car_builder_p = car_builder_p;
        this->car_builder_p->build_car_specs();
    }

    void print_details()
    {
        car_builder_p->get_car()->print_car_details();
    }
};

#if ENABLE_THIS_MAIN
int main()
{
    car_order_manager car_order;
    audi_builder audi_a8;
    bmw_builder bmw_i8;

    car_order.create_order(&audi_a8);
    car_order.print_details();

    car_order.create_order(&bmw_i8);
    car_order.print_details();

    return 0;
}
#endif
