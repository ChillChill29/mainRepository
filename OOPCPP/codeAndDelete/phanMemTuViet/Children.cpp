
#include "Person.cpp"

class Children : public Person
{
public:
	Children() {}
	Children(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
	void getInformation(int age, vector<Book> library)
	{
		system("cls");
		cout << "_____________Nhap ten nguoi tre em_____________" << endl;
		Person::getInformation(age, library);
	}
	long moneyPay()
	{
		return this->getVB().size() * 5000;
	}
	void display()
	{
		cout << "Children!" << endl;
		Person::display();
	}
};