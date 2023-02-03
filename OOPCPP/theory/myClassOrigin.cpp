#pragma once
#include <iostream>
#include <math.h>


using namespace std;

class Person{
private:
    string name;
    int age;
    string address;
public:
    Person(string name, int age, string address){
        this->name = name;
        this->age = age;
        this->address =address;
    }
    void setName(string name, int age, string address){
        this->name = name;
        this->age = age;
        this->address = address;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getAddress(){
        return address;
    }
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    void setAddress(string address){
        this->address = address;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Address: "<<address<<endl;
    }
};
class Student: public Person{
private:
    double gpa;
public:
    Student(string name, int age, string address, double gpa):Person(name, age, address){
        this->gpa = gpa;
    }
    void setGpa(double gpa){
        this->gpa = gpa;
    }
    double getGpa(){
        return gpa;
    }
    void display(){
        Person::display();
        cout<<"GPA: "<<gpa<<endl;
    }
};
class Teacher: public Person{
private:
    int salary;
public:
    Teacher(string name, int age, string address, int salary): Person(name, age, address){
        this->salary = salary;
    }
    void setSalary(int salary){
        this->salary = salary;
    }
    int getSalary(){
        return salary;
    }
    void display(){
        Person::display();
        cout<<"Salary: "<<salary<<endl;
    }
};

class Account{
private:
    int id;
    string name;
    int balance;
public:
    Account(int id, string name){
        this->id = id;
        this->name = name;
    }
    Account(int id, string name, int balance){
        this->id = id;
        this->name = name;
        this->balance = balance;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    int getBalance(){
        return balance;
    }
    void deposit(int amount){
        balance += amount;
    }
    void withdraw(int amount){
        if(balance>=amount)
            balance-=amount;
        else
            cout<<"That amount exceeds your current balance."<<endl;
    }
    void display(){
        cout<<"Id: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

class Point{
private:
    double x;
    double y;
public:
    Point(){}
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
    void setX(double x){
        this->x = x;
    }
    double getX(){
        return x;
    }
    void setY(double y){
        this->y = y;
    }
    double getY(){
        return y;
    }
    void setXY(double x, double y){
        this->x = x;
        this->y = y;
    }
    double distance(double x, double y){
        return sqrt((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y));
    }
    double distance(Point another){
        return distance(another.getX(), another.getY());
    }
};

class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    void setHour(int hour){
        this->hour = hour;
    }
    int getHour(){
        return hour;
    }
    void setMinute(int minute){
        this->minute = minute;
    }
    int getMinute(){
        return minute;
    }
    void setSecond(int second){
        this->second = second;
    }
    int getSecond(){
        return second;
    }
    void setTime(int hour, int minute, int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    void nextSecond(){
        if(second == 59){
            second = 0;
            if(minute == 59){
                minute = 0;
                if(hour == 23)
                    hour = 0;
                else
                    hour++;
            }
            else
                minute++;
        }
        else
            second++;
    }
    void previousSecond(){
        if (second == 0)
        {
            second = 59;
            if (minute == 0)
            {
                minute = 59;
                if(hour == 0)
                    hour = 23;
                else
                    hour--;
            }
            else
                minute--;
        }
        else
            second--;
    }

    void display(){
        string hour = to_string(this->hour);
        string minute = to_string(this->minute);
        string second = to_string(this->second);
        if(hour.length()==1)
            hour = "0"+hour;
        if(minute.length()==1)
            minute = "0"+minute;
        if(second.length()==1)
            second = "0"+second;
        cout<<hour + ":" + minute + ":" + second<<endl;
    }
};

class Rectangle{
private:
    double length;
    double width;
public:
    Rectangle() {}
    Rectangle(double length, double width){
        this->length = length;
        this->width = width;
    }
    void setLength(double length){
        this->length = length;
    }
    double getLength(){
        return length;
    }
    void setWidth(double width){
        this->width = width;
    }
    double getWidth(){
        return width;
    }
    double getArea(){
        return length*width;
    }
    double getPerimeter(){
        return (length+width)*2;
    }
};

// class Employee{
// private:
//     string name;
//     int salary;
// public:
//     Employee(string name, int salary){
//         this->name = name;
//         this->salary = salary;
//     }
//     void setName(string name){
//         this->name = name;
//     }
//     string getName(){
//         return name;
//     }
//     void setSalary(int salary){
//         this->salary = salary;
//     }
//     int getSalary(){
//         return salary;
//     }
//     void display(){
//         cout<<"Name: "<<name<<endl;
//         cout<<"Salary: "<<salary<<endl;
//     }
// };



class Employee{
private:
    int id;
    string firstName;
    string lastName;
    int salary;
public:
    Employee(int id, string firstName, string lastName, int salary){
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->salary = salary;
    }
    void setId(int id){
        this->id = id;
    }
    int getId(){
        return id;
    }
    void setFirstName(string firstName){
        this->firstName = firstName;
    }
    string getFirstName(){
        return firstName;
    }
    void setLastName(string lastName){
        this->lastName = lastName;
    }
    string getLastName(){
        return firstName;
    }
    void setSalary(int salary){
        this->salary = salary;
    }
    int getSalary(){
        return id;
    }
    string getFullName(){
        return firstName + " " + lastName;
    }
};
class Manager: public Employee{
private:
    int bonus;
public:
    Manager(string name, int salary, int bonus): Employee(name, salary){
        this->bonus = bonus;
    }
    void setBonus(int bonus){
        this->bonus = bonus;
    }
    int getBonus(){
        return bonus;
    }
    int getSalary(){
        return Employee::getSalary() + bonus;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<getSalary()<<endl;
    }
};

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setDate(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setDay(int day){
        this->day = day;
    }
    void setMonth(int month){
        this->month = month;
    }
    void setYear(int year){
        this->year = year;
    }
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
    void display(){
        if(day<10){
            if(month<10)
                cout<<"0"<<day<<"//0"<<month<<"//"<<year<<endl;
            else
                cout<<"0"<<day<<"//"<<month<<"//"<<year<<endl;
        }
        else{
            if(month<10)
                cout<<day<<"//0"<<month<<"//"<<year<<endl;
            else
                cout<<day<<"//"<<month<<"//"<<year<<endl;
        }
    }
};
