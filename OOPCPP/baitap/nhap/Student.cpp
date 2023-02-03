#pragma once
#include <iostream>

using namespace std;

class Student{
private:
	int id;
	string name;
	bool gender;
public:
	Student();
	Student(int id, string name, bool gender): id(id), name(name), gender(gender) {}
	int getId(){
		return id;
	}
	string getName(){
		return name;
	}
	bool isMale(){
		return gender;
	}
	void printInfo(){
		cout<<"Id: "<<id<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Gender: "<<(gender)?"Male": "Female"<<endl;
	}
	void setId(int id){
		this->id = id;
	}
	void setMale(bool gender){
		this->gender = gender;
	}
	void setName(string name){
		this->name = name;
	}
};