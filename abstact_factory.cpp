/* A utility class that creates an instance of a class from
 * a family of derived classes
 *
 * The Abstract Factory design pattern is useful in a situation that
 * requires the creation of many different types of objects all derived
 * from a common base type.
 *
 * The factory method defines a method for creating the objects which
 * subclasses can then overridee to specify the derived type that will
 * be created.
 *
 * Thus, at run time, the Factory Method can be passed a description of a
 * desired object (e.g a string read from user input) and return a base class
 * pointer to a new instance of that object
 */

#include <iostream>
#include <string>

#define ENABLE_THIS_MAIN  ( 1 )

class document
{
public:
    virtual std::string get_document_format() = 0;

    virtual ~document() {}
};

class pdf:public document
{
public:
    virtual std::string get_document_format() override
    {
        return "PDF";
    }
};

class word:public document
{
public:
    virtual std::string get_document_format() override
    {
        return "Word";
    }
};

class excel:public document
{
public:
    virtual std::string get_document_format() override
    {
        return "Excel";
    }
};

class document_factory
{
public:
    static document *create_document(const std::string &type)
    {
        if (type == "PDF") return new pdf;
        else if (type == "WORD") return new word;
        else if (type == "EXCEL") return new excel;
        else return  nullptr;
    }
};

#if ENABLE_THIS_MAIN
int main()
{
    document *pdf_doc = document_factory::create_document("PDF");
    document *word_doc = document_factory::create_document("WORD");
    document *excel_doc = document_factory::create_document("EXCEL");

    std::cout << "Format: " << pdf_doc->get_document_format() << std::endl;
    std::cout << "Format: " << word_doc->get_document_format() << std::endl;
    std::cout << "Format: " << excel_doc->get_document_format() << std::endl;
}
#endif
