#include "Person.cpp"

class Adult : public Person
{
public:
	Adult() {}
	Adult(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
	void getInformation(int age, vector<Book> library)
	{
		system("cls");
		cout << "_____________Nhap ten nguoi lon_____________" << endl;
		Person::getInformation(age, library);
	}
	long moneyPay()
	{
		return this->getVB().size() * 10000;
	}
	void display()
	{
		cout << "Adult!" << endl;
		Person::display();
	}
};
