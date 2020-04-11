/*
 *  Object pools (resource pools) are used to manage the object caching.
 *  A client with access to a Object Pool can avoid creating a new objects
 *  by simply asking the pool for one that has been already instentiated instead.
 *
 * Object pooling can offer a significant performance boost;
 * it is most effective in situations where the cost of initializing a class instance is high,
 * the rate of instantiation of a class is high, and
 * the number of instantiations in use at any one time is low.
 */

#include <iostream>
#include <list>

#define ENABLE_THIS_MAIN  ( 1 )

class resource
{
private:
    int value;
public:
    resource(): value { 0 } {}

    void reset() {value = 0;}
    void set_value(int value) {this->value = value;}
    int get_value() const {return value;}
};

class object_pool
{
private:
    std::list<resource*> resources;
    static object_pool *instance;

    object_pool() {}

public:
    static object_pool* get_instance()
    {
        if (instance == 0)
        {
            instance = new object_pool;
        }

        return instance;
    }

    resource *get_resource()
    {
        if (resources.empty())
        {
            std::cout << "Creating new resource" << std::endl;
            return new resource;
        }

        else
        {
            std::cout << "Reusing existing resouce" << std::endl;
            resource *resource_p = resources.front();
            resources.pop_front();
            return resource_p;
        }
    }

    void return_resource(resource *object)
    {
        object->reset();
        resources.push_back(object);
    }
};

object_pool *object_pool::instance = 0;

#if ENABLE_THIS_MAIN
int main(void)
{
    object_pool *pool = object_pool::get_instance();

    resource *resource_one;
    resource *resource_two;

    resource_one = pool->get_resource();
    resource_one->set_value(10);
    std::cout << "Resource One: " << resource_one->get_value() << std::endl;

    resource_two = pool->get_resource();
    resource_two->set_value(20);
    std::cout << "Resource Two: " << resource_two->get_value() << std::endl;

    pool->return_resource(resource_one);
    pool->return_resource(resource_two);

    std::cout << "Resource One: " << resource_one->get_value() << std::endl;
    std::cout << "Resource Two: " << resource_two->get_value() << std::endl;

    return 0;
}
#endif
