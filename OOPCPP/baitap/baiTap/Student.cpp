#include "Person.cpp"
class Student : Person
{
private:
    /* data */
    string program;
    int year;
    double score;

public:
    Student() {}
    Student(string name, string address, string program, int year, double score)
        : program(program), year(year), score(score), Person(name, address) {}
    string getProgram()
    {
        return program;
    }
    int getYear()
    {
        return year;
    }
    double getScore()
    {
        return score;
    }
    void getInformation()
    {
        Person::getInformation();
        cout << "Program: ";
        getline(cin, this->program);
        cout << "Year: ";
        cin >> this->year;
        cout << "Score: ";
        cin >> score;
    }
    void printInformation()
    {
        Person::printInformation();
        cout << "Program: " << getProgram();
        cout << "Year: " << getYear();
        cout << "Score: " << getScore();
    }
};
