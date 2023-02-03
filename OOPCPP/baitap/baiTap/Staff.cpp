#include "Person.cpp"
class Staff : Person
{
private:
    /* data */
    string school;
    double salary;

public:
    Staff() {}
    Staff(string name, string address, string school, double salary)
        : school(school), salary(salary), Person(name, address) {}
    string getSchool()
    {
        return school;
    }
    double getSalary()
    {
        return salary;
    }
    void getInformation()
    {
        Person::getInformation();
        cout << "School: ";
        getline(cin, this->school);
        cout << "Salary: ";
        cin >> salary;
    }
    void printInformation()
    {
        Person::printInformation();
        cout << "School: " << getSchool();
        cout << "Salary: " << getSalary();
    }
    void upToSalary()
    {
        double percent;
        cout << "Percent(%): ";
        cin >> percent;
        this->salary = salary * percent * 0.01;
    }
};
