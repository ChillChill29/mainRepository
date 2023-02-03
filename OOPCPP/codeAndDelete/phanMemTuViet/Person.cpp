#pragma once
#include <vector>
#include <algorithm>
#include "Book.cpp"

class Person
{
private:
	string name;
	int age;
	string add;
	vector<Book> vb;

public:
	Person() {}
	Person(string name, int age, string add, vector<Book> vb) : name(name), age(age), add(add), vb(vb) {}
	void getInformation(int age, vector<Book> library)
	{
		cin.ignore();
		this->age = age;
		cout << "nhap ten: ";
		getline(cin, this->name);
		cout << "nhap dia chi: ";
		getline(cin, this->add);
		cout << "nhap so luong sach: " << endl;
		for (int i = 0; i < library.size(); i++)
		{
			int n = 0;
			cout << library[i].getNameBook() << " : " << endl;
			cout << "	yes: 1" << endl;
			cout << "	no: 0" << endl;
			cout << "_chon:	";
			cin >> n;
			if (n == 1)
			{
				this->vb.push_back(library[i]);
			}
		}
	}
	string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	string getAdd()
	{
		return add;
	}
	vector<Book> getVB()
	{
		return vb;
	}
	virtual long moneyPay() = 0;
	virtual void display()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Add: " << add << endl;
		cout << "List Book Borrowed:" << endl;
		for (int i = 0; i < vb.size(); i++)
		{
			vb[i].display();
		}
		cout << "______________________________" << endl;
		cout << "Money Pay: " << moneyPay() << endl;
	}

	//  sắp xếp danh sách theo tuổi từ trẻ tới già
	static void sortPersonAge(vector<Person *> &vt)
	{
		for (int i = 0; i < vt.size() - 1; i++)
		{
			for (int j = i + 1; j < vt.size(); j++)
			{
				if (vt[i]->getAge() > vt[j]->getAge())
					swap(vt[i], vt[j]);
			}
		}
	}

	// list Age của cả thư viện chưa sắp xếp
	static vector<int> getListAge(vector<Person *> vt)
	{
		vector<int> str;
		for (int i = 0; i < vt.size(); i++)
		{
			// tìm kiếm cả mảng str, có cái giá trị Age nào chưa có thì push vào mảng *chưa sắp xếp
			if (!(find(str.begin(), str.end(), vt[i]->getAge()) != str.end()))
			{
				str.push_back(vt[i]->getAge());
			}
		}
		return str;
	}
	// sách nào được mượn nhiều nhất của cả thư viện
	static vector<Book> getMaxBookBorrowed(vector<Person *> vp, vector<Book> vB)
	{
		// vector = mảng
		// tạo mảng đểm gồm các phần tử 0, nhưng size bằng số sách
		vector<int> count(vB.size(), 0);
		for (int i = 0; i < vB.size(); i++)
		{
			// gán i lược qua các cuốn sách
			for (int j = 0; j < vp.size(); j++)
			// gán j lược qua các danh sách người
			{
				// gán bookPerson là biến chứa các cuốn sách mà người j mượn
				vector<Book> bookPerson(vp[j]->getVB());
				// gán k lược qua các cuốn sách mà người j mượn
				for (int k = 0; k < bookPerson.size(); k++)
					// so sánh nếu trùng tên thì ++
					if (vB[i].getNameBook() == bookPerson[k].getNameBook())
						count[i]++;
			}
		}
		// gán giá trị maxx là giá trị max nhất trong list
		int maxx = *max_element(count.begin(), count.end()); // #include <algorithm>
		vector<Book> res;
		// tạo 1 mảng gồm các cuốn sách và push giá trị cuốn sách đó vào mảng res
		for (int i = 0; i < vB.size(); i++)
		{
			if (count[i] == maxx)
				res.push_back(vB[i]);
		}
		return res;
	}
};