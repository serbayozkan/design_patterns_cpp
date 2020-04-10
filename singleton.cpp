/*
 * Singleton pattern ensures that a class has only one instance and provides a global point
 * of access to that instance.
 *
 * One common use of the singleton design pattern is for application configurations.
 * Configuration may need to be accesible globally and future expensions to the app.
 * configurations may be needed.
 *
 * Another example is if you are using a logger that writes to file, the user can use
 * a singleton class to create such a logger.
 *
 * This example is based on Scott Meyers Singleton Design Pattern Implementation
 * With C++11 and newer versions this implementation is lazy-evaluated, correctly
 * destroyed and thread-safe.
 *
 * **** What is the difference between global class and singleton pattern? ****
 *
 * Singleton is used when user don't want to create more than one object.
 * Singleton class ensures that not more than object is created but global
 * objects does not ensure this.
 ********************************************************************************
 *
 * References:
 * - https://www.amazon.com/Effective-Modern-Specific-Ways-Improve/dp/1491903996
 * - https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Structural_Patterns
 * - https://www.tutorialspoint.com/Explain-Cplusplus-Singleton-design-pattern
 * - https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 * - https://stackoverflow.com/questions/42870559/differences-between-singleton-and-global-variable
 */

#include <iostream>

#define ENABLE_THIS_MAIN  ( 0 )

class singleton
{
private:
    singleton()
    {
        std::cout << "Singleton Constructor is called" << std::endl;
    }

    ~singleton() {}

    std::string name;
    std::string surname;

public:
    singleton (singleton const&) = delete;
    void operator = (singleton const&) = delete;

    static singleton &get_instance()
    {
        std::cout << "Some object getting instance of singleton" << std::endl;

        static singleton instance;

        return instance;
    }

    void set_name(std::string name) {this->name = name;}
    void set_surname(std::string surname) {this->surname = surname;}

    std::string get_name() const {return name;}
    std::string get_surname() const {return surname;}
};

#if ENABLE_THIS_MAIN
int main()
{
    singleton &singleton1 = singleton::get_instance();
    singleton &singleton2 = singleton::get_instance();

    singleton1.set_name("SerbayFromSingleton1");
    singleton1.set_surname("OzkanFromSingleton1");

    std::cout << "*************************************" << std::endl;
    std::cout << singleton1.get_name() << std::endl;
    std::cout << singleton1.get_surname() << std::endl;

    std::cout << singleton2.get_name() << std::endl;
    std::cout << singleton2.get_surname() << std::endl;
    std::cout << "*************************************" << std::endl;

    singleton2.set_name("SerbayFromSingleton2");
    singleton2.set_surname("OzkanFromSingleton2");

    std::cout << "*************************************" << std::endl;
    std::cout << singleton1.get_name() << std::endl;
    std::cout << singleton1.get_surname() << std::endl;

    std::cout << singleton2.get_name() << std::endl;
    std::cout << singleton2.get_surname() << std::endl;
    std::cout << "*************************************" << std::endl;

    return 0;
}
#endif
