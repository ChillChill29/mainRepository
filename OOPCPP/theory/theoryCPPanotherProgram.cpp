#include <iostream>

using namespace std;

struct Student
{
	string name;
	int age;
	void getInformation()
	{
		cin>>name>>age;
	}
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
	}
};

int main()
{
	Student A;
	A.getInformation();
	A.display();
	// or khai báo trực tiếp
	Student B {"Quan", 12};
	B.display();
	return 0;
}