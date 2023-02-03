#include <string>
#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    string address;

public:
    Person() {}
    Person(string name, string address) : name(name), address(address) {}
    virtual void getInformation()
    {
        cin.ignore();
        cout << "Name: ";
        getline(cin, this->name);
        cout << "Address: ";
        getline(cin, this->address);
    }
    virtual void printInformation()
    {
        cout << "Name: " << getName();
        cout << "Address: " << getAdress();
    }
    string getName()
    {
        return name;
    }
    string getAdress()
    {
        return address;
    }
};
