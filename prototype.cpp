/*
 *  A Prototype pattern is used in software when the type of objects to create is
 *  determined by a prototypical instance, which is cloned to produces new objects.
 *
 *  This pattern is used when the inherent cost of a new object in the standart way
 *  (using new keyword) is expensive and time consuming for a given application.
 *
 *  The new operator considered harmful.
 *
 *  The protoype is more focused on abstracting how you can create many "copies" of
 *  an object from a prototype object. You mainly use this pattern when you want to
 *  try and avoid the use of the new keyword.
 */

#include <iostream>
#include <string>

class Iprototype
{
protected:
    std::string city;
    std::string street;
    int number;
public:

    std::string get_city() const {return city;}
    std::string get_street() const {return street;}
    int get_number() const {return number;}

    virtual Iprototype *clone() = 0;
};

class home: public Iprototype
{
public:
    home(std::string city, std::string street, int number)
    {
        this->city = city;
        this->street = street;
        this->number = number;
    }

    Iprototype * clone() override
    {
        return new home(*this);
    }

};

class work: public Iprototype
{
public:
    work(std::string city, std::string street, int number)
    {
        this->city = city;
        this->street = street;
        this->number = number;
    }


    Iprototype * clone() override
    {
        return new work(*this);
    }
};

class address
{
private:
    static Iprototype *home_address;
    static Iprototype *work_address;

public:
    static void init(std::string city, std::string street, int number)
    {
        home_address = new home(city, street, number);
        work_address = new work(city, street, number);
    }


    static Iprototype *get_home_address()
    {
        return home_address->clone();
    }

    static Iprototype *get_work_address()
    {
        return work_address->clone();
    }
};

Iprototype* address::home_address = 0;
Iprototype* address::work_address = 0;

int main(void)
{
    address::init("Ankara", "Yenimahalle", 25);

    Iprototype *client_address;

    client_address = address::get_home_address();

    std::cout << "City: " << client_address->get_city() << std::endl;
    std::cout << "Street: " << client_address->get_street() << std::endl;
    std::cout << "Number: " << client_address->get_number() << std::endl;

    client_address = address::get_work_address();

    std::cout << "City: " << client_address->get_city() << std::endl;
    std::cout << "Street: " << client_address->get_street() << std::endl;
    std::cout << "Number: " << client_address->get_number() << std::endl;

    return 0;
}
