#include <iostream>
#include <vector>

using namespace std;



class Person{
private:
	string name;
	string address;
public:
	Person(string name, string address){
		this->name = name;
		this->address = address;
	}
	string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    void setName(string name){
        this->name = name;
    }
    void setAddress(string address){
        this->address = address;
    }
    virtual void display() = 0;
};

class Employee : public Person{
private:
	int salary;
public:
	Employee(string name, string address, int salary): Person(name, address){
		this->salary = salary;
	}
	void display(){
		cout<<"Employee name: "<<Person::getName()<<endl;
		cout<<"Employee address: "<<Person::getAddress()<<endl;
		cout<<"Employee salary: "<<salary<<endl;
	}
};

class Customer : public Person{
private:
	int balance;
public:
	Customer(string name, string address, int balance): Person(name, address){
		this->balance = balance;
	}
	void display(){
		cout<<"Customer name: "<<Person::getName()<<endl;
		cout<<"Customer address: "<<Person::getAddress()<<endl;
		cout<<"Customer balance: "<<balance<<endl;
	}
};

class Shape{
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
};
class Rectangle: public Shape{
private:
	double length;
	double width;
public:
	Rectangle(double length, double width){
		this->length = length;
		this->width = width;
	}
	double getArea(){
		return length*width;
	}
	double getPerimeter(){
		return 2*(length+width);
	}
};
class Circle: public Shape{
private:
	double radius;
public:
	Circle(double radius){
		this->radius = radius;
	}
	double getArea(){
		return 3.14*radius*radius;
	}
	double getPerimeter(){
		return 2*3.14*radius;
	}
};

class Employee{
private:
	string name;
	int paymentPerHour;
public:
	Employee(string name, int paymentPerHour){
		this->name = name;
		this->paymentPerHour = paymentPerHour;
	}
	void setName(string name){
		this->name = name;
	}
	string getName(){
		return name;
	}
	void setPaymentPerHour(int paymentPerHour){
		this->paymentPerHour = paymentPerHour;
	}
	int getPaymentPerHour(){
		return paymentPerHour;
	}
	virtual int calculateSalary() = 0;
};

class PartTimeEmployee: public Employee{
private:
	int workingHour;
public:
	PartTimeEmployee(string name, int paymentPerHour, workingHour): Employee(name, paymentPerHour){
		this->workingHour = workingHour;
	}
	int calculateSalary(){
		return workingHour* getPaymentPerHour();
	}
};

class FullTimeEmployee: public Employee{
public:
	FullTimeEmployee(string name, int paymentPerHour): Employee(name, paymentPerHour){}
	int calculateSalary(){
		return 8*getPaymentPerHour();
	}
};


//Thu nạp
class Point{
private:
	int x;
	int y;
public:
	Point(){}
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
	void setX(int x){
		this->x = x;
	}
	int getX(){
		return x;
	}
	void setY(int y){
		this->y = y;
	}
	int getY(){
		return y;
	}
};
class PolyLine{
private:
	vector<Point> points;
public:
	PolyLine(){}
	PolyLine(vector <Point> points){
		this->points = points;
	}
	void appendPoint(Point point){
		points.push_back(point);
	}
	void appendPoint(int x, int y){
		points.push_back(Point(x,y));
	}
	double getLength(){
		double length = 0;
		for(int i =0; i<points.size()-1; i++){
			length+=sqrt(pow(points[i].getX() - points[i+1].getX(), 2)
			 + pow(points[i].getY() - points[i+1].getY(), 2));
		}
		return length;
	}

};
class Triangle{
private:
	Point vertice1;
	Point vertice2;
	Point vertice3;
public:
	Triangle(Point vertice1, Point vertice2, Point vertice3){
		this->vertice1 = vertice1;
		this->vertice2 = vertice2;
		this->vertice3 = vertice3;
	}
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
		this->vertice1 = Point(x1, y1);
		this->vertice2 = Point(x2, y2);
		this->vertice3 = Point(x3, y3);
	}
	double getPerimeter(){
		double d1 = sqrt(pow(vertice1.getX() - vertice2.getX(), 2)
		 + pow(vertice1.getY() - vertice2.getY(), 2));
		double d2 = sqrt(pow(vertice2.getX() - vertice3.getX(), 2)
		 + pow(vertice2.getY() - vertice3.getY(), 2));
		double d3 = sqrt(pow(vertice3.getX() - vertice1.getX(), 2)
		 + pow(vertice3.getY() - vertice1.getY(), 2));
		return d1 + d2 + d3;
	}
};
class Line{
private:
	Point begin;
	Point end;
public:
	Line(Point begin, Point end){
		this->begin = begin;
		this->end = end;
	}
	Line(int x1, int y1, int x2, int y2){
		this->begin = Point(x1, y1);
		this->end = Point(x2, y2);		
	}
	void setBegin(Point begin){
		this->begin = begin;
	}
	Point getBegin(){
		return begin;
	}
	void setEnd(Point end){
		this->end = end;
	}
	Point getEnd(){
		return end;
	}
	double getLength(){
		return sqrt(pow(begin.getX() - end.getX(), 2) + pow(begin.getY() - end.getY(), 2));
	}

};

// Thu nạp
class Author{
private:
	string name;
	string email;
public:
	Author(string name, string email){
		this->name = name;
		this->email =email;
	}
	void setName(string name){
		this->name = name;
	}
	void setEmail(string email){
		this->email = email;
	}
	string getName(){
		return name;
	}
	string getEmail(){
		return email;
	}
};
class Book{
private:
	string name;
	vector<Author> authors;
	double price;
public:
	Book(string name, vector<Author> authors, double price){
		this->name = name;
		this->authors = authors;
		this->price = price;
	}
	void setName(string name){
		this->name = name;
	}
	string getName(){
		return name;
	}	
	void setPrice(double price){
		this->price = price;
	}
	double getPrice(){
		return price;
	}	
	string getAuthorNames(){
		string ans = "";
		for(int i = 0; i< authors.size()-1; i++)
			ans+= authors[i].getName() + ", ";
		ans+= authors[authors.size()-1].getName();
		return ans;
	}

};

// Thu nạp
class Customer{
private:
	int id;
	string name;
	int discount;
public:
	Customer(){}
	Customer(int id, string name, int discount){
		this->id = id;
		this->name = name;
		this->discount = discount;
	}
	int getId(){
		return id;
	}
	string getName(){
		return name;
	}
	void setName(string name){
		this->name = name;
	}
	int getDiscount(){
		return discount;
	}
	void setDiscount(int discount){
		this->discount = discount;
	}
};
class Invoice{
private:
	int id;
	Customer customer;
	double amount;
public:
	Invoice(int id, Customer customer, double amount){
		this->id = id;
		this->customer = customer;
		this->amount = amount;
	}
	int getId(){
		return id;
	}
	void setCustomer(Customer customer){
		this->customer = customer;
	}
	Customer getCustomer(){
		return customer;
	}
	void setAmount(double amount){
		this->amount = amount;
	}
	double getAmount(){
		return amount;
	}
	string getCustomerName(){
		return customer.getName();
	}
	double getAmountAfterDiscount(){
		return amount - amount*customer.getDiscount()/100;
	}

};

class Card{
private:
	string nameBook;
	string nameAuthor;
	int numberBook;
public:
	Card(){}
	Card(string nameBook, string nameAuthor, int numberBook){
		this->nameBook = nameBook;
		this->nameAuthor = nameAuthor;
		this->numberBook = numberBook;
	}
	void display(){
		cout<<"Name Book: "<<nameBook<<endl;
		cout<<"Name Author: "<<nameAuthor<<endl;
		cout<<"Number Book: "<<numberBook<<endl;
	}
	int getNumberBook(){
		return numberBook;
	}
	static void sortCard(vector<Card> &cards){
		for(int i = 0; i<cards.size()-1; i++)
			for(int j = i+1; j<cards.size(); j++)
				if(cards[i].getNumberBook() > cards[j].getNumberBook())
					swap(cards[i], cards[j]);
	}
};

class Student{
private:
	string name;
	double math;
	double physic;
	double chemistry;
public:
	Student(){}
	Student(string name, double math, double physic, double chemistry){
		this->name = name;
		this->math = math;
		this->physic = physic;
		this->chemistry = chemistry;
	}
	double getMath(){
		return math;
	}
	double getPhysic(){
		return physic;
	}
	double getChemistry(){
		return chemistry;
	}
	void display(){
		cout<<"Name: "<<name<<endl;
		cout<<"Point math: "<<math<<endl;
		cout<<"Point physic: "<<physic<<endl;
		cout<<"Point chemistry: "<<chemistry<<endl;
		cout<<"Average: "<<avgPoint()<<endl;
	}
	double avgPoint(){
		return (math+physic+chemistry)/3;
	}
	static vector<Student> getStudentMaxAvg(vector<Student> vt){
		double maxAvg = vt[0].avgPoint();
		vector<Student> res;
		// tim maxAvg
		for(int i =1; i<vt.size(); i++)
			if(vt[i].avgPoint() > maxAvg)
				maxAvg= vt[i].avgPoint();
		// them vao vector
		for(int i =0; i<vt.size(); i++)
			if(vt[i].avgPoint() == maxAvg)
				res.push_back(vt[i]);
		return res;
	}
	static vector<Student> getStudentMaxMath(vector<Student> vt){
		double maxAvg = vt[0].math;
		vector<Student> res;
		// tim maxAvg
		for(int i =1; i<vt.size(); i++)
			if(vt[i].math > maxAvg)
				maxAvg= vt[i].math;
		// them vao vector
		for(int i =0; i<vt.size(); i++)
			if(vt[i].math == maxAvg)
				res.push_back(vt[i]);
		return res;
	}
	static vector<Student> getStudentMaxPhysic(vector<Student> vt){
		double maxAvg = vt[0].physic;
		vector<Student> res;
		// tim maxAvg
		for(int i =1; i<vt.size(); i++)
			if(vt[i].physic > maxAvg)
				maxAvg= vt[i].physic;
		// them vao vector
		for(int i =0; i<vt.size(); i++)
			if(vt[i].physic == maxAvg)
				res.push_back(vt[i]);
		return res;
	}
	static vector<Student> getStudentMaxChemistry(vector<Student> vt){
		double maxAvg = vt[0].chemistry;
		vector<Student> res;
		// tim maxAvg
		for(int i =1; i<vt.size(); i++)
			if(vt[i].chemistry > maxAvg)
				maxAvg= vt[i].chemistry;
		// them vao vector
		for(int i =0; i<vt.size(); i++)
			if(vt[i].chemistry == maxAvg)
				res.push_back(vt[i]);
		return res;
	}	
};

class Subject{
private:
	string nameSub;
	double point;
	int numberCredit;
	long money;
public:
	Subject(){}
	Subject(string nameSub, double point, int numberCredit, long money){
		this->nameSub = nameSub;
		this->point = point;
		this->numberCredit = numberCredit;
		this->money = money;
	}
	string getNameSub(){
		return nameSub;
	}
	double getPoint(){
		return point;
	}
	int getNumberCredit(){
		return numberCredit;
	}
	long getMoney(){
		return money;
	}
	void display(){
		cout<<"Name Subject: "<<nameSub<<endl;
		// cout<<"Point: "<<point<<endl;
		cout<<"Number Credit: "<<numberCredit<<endl;
		cout<<"Money Of One Credit: "<<money<<endl;
	}
};
class Student{
private:
	string id;
	string name;
	vector<Subject> s;
public:
	Student(){}
	Student(string id, string name, vector<Subject> s){
		this->id = id;
		this->name = name;
		this->s = s;
	}
	string getTd(){
		return id;
	}
	string getName(){
		return name;
	}
	vector<Subject> getS(){
		return s;
	}
	long getSumMoney(){
		long rMoney = 0;
		for(int i = 0; i<s.size(); i++)
			rMoney+=s[i].getMoney()*s[i].getNumberCredit();
		return rMoney;
	}
	double avgPoint(){
		double points = 0;
		int numberCredit = 0;
		for(int i =0; i<s.size(); i++){
			points+= s[i].getPoint()*s[i].getNumberCredit();
			numberCredit+=s[i].getNumberCredit();
		}
		return points/numberCredit;
	}
	void display(){
		cout<<"Id: "<<id<<endl;
		cout<<"Name Student: "<<name<<endl;
		cout<<"List Subject"<<endl;
		for (int i = 0; i < s.size(); ++i)
		{
			s[i].display();
		}
		cout<<"Sum Money Have To Pay: "<<getSumMoney()<<endl;
		cout<<"Average Point: "<<avgPoint()<<endl;
	}
};

class Transport{
private:
	string manufacturer;
	string name;
	int year;
	int speed;
public:
	Transport(){}
	Transport(string manufacturer, string name, int year, int speed){
		this->manufacturer = manufacturer;
		this->name = name;
		this->year = year;
		this->speed = speed;
	}
	string getManufacturer(){
		return manufacturer;
	}
	string getName(){
		return name;
	}
	int getYear(){
		return year;
	}
	int getSpeed(){
		return speed;
	}
	void display(){
		cout<<"Manufacturer: "<<manufacturer<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Year Of Manufacturer: "<<year<<endl;
		cout<<"Speed: "<<speed<<endl;
	}
};

class Car: public Transport{
private:
	int numberSeat;
	string engineType;
public:
	Car(){}
	Car(string manufacturer, string name, int year, int speed, int numberSeat, string engineType): Transport(manufacturer, name, year, speed){
		this->numberSeat = numberSeat;
		this->engineType = engineType;
	}
	int getNumberSeat(){
		return numberSeat;
	}
	string getEngineType(){
		return engineType;
	}
	double getSpeedBasic(){
		return Transport::getSpeed()/numberSeat;
	}
	void display(){
		Transport::display();
		cout<<"Number Seat: "<<numberSeat<<endl;
		cout<<"Engine Type: "<<engineType<<endl;
		cout<<"Speed Basic: "<<getSpeedBasic()<<endl;
	}
	static vector<Car> getCarHaveMaxSpeedBasic(vector<Car> vt){
		vector<Car> res;
		double speedBasic = vt[0].getSpeedBasic();
		for (int i = 1; i < vt.size(); ++i)
		{
			if(speedBasic<vt[i].getSpeedBasic())
				speedBasic = vt[i].getSpeedBasic();
		}
		for (int i = 0; i < vt.size(); ++i)
		{
			if(vt[i].getSpeedBasic()==speedBasic)
				res.push_back(vt[i]);
		}
		return res;
	}
	static vector<Car> getCarHaveMaxSeat(vector<Car> vt){
		vector<Car> res;
		int seat = vt[0].getNumberSeat();
		for (int i = 1; i < vt.size(); ++i)
		{
			if(seat<vt[i].getNumberSeat())
				seat = vt[i].getNumberSeat();
		}
		for (int i = 0; i < vt.size(); ++i)
		{
			if(vt[i].getNumberSeat()==seat)
				res.push_back(vt[i]);
		}
		return res;
	}
};

class Geometry{
public:
	virtual double perimeter() = 0;
	virtual double area() = 0;
	virtual void display(){
		cout<<"Perimeter: "<<perimeter()<<endl;
		cout<<"Area: "<<area()<<endl;
	}
};
class Traingle: public Geometry{
private:
	int a;
	int b;
	int c;
public:
	Traingle(){}
	Traingle(int a, int b, int c){
		this->a = a;
		this->b = b;
		this->c = c;
	}
	// Traingle(int a, int b, int c) : a(a), b(b), c(c) {}
	double perimeter(){
		return a + b + c;
	}
	double area(){
		double p = (a+b+c)/2.0;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
};
class Circle: public Geometry{
private:
	int r;
public:
	Circle(){}
	Circle(int r){
		this->r = r;
	}
	double perimeter(){
		return 3.14*r*2;
	}
	double area(){
		return 3.14*r*r;
	}
};
class Rectangle: public Geometry{
private:
	int h;
	int w;
public:
	Rectangle(){}
	Rectangle(int h, int w){
		this->h = h;
		this->w = w;
	}
	double perimeter(){
		return 2*(h+w);
	}
	double area(){
		return h*w;
	}
};

class Person{
private:
	string name;
	int age;
	string add;
	string tel;
	string sex;
public:
	Person(){}
	Person(string name, int age, string add, string tel, string sex):
		name(name), age(age), add(add), tel(tel), sex(sex) {}
	string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	string getAdd(){
		return add;
	}
	string getTel(){
		return tel;
	}
	string getSex(){
		return sex;
	}
	virtual void display(){
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Sex: "<<sex<<endl;
		cout<<"Add: "<<add<<endl;
		cout<<"Tel: "<<tel<<endl;		
	}
	virtual long salary() = 0;
	static vector<Person*> findPerson(vector <Person*> p){
		vector<Person*> res;
		for (int i = 0; i < p.size(); i++)
		{
			// vì p ở dạng con trỏ nên dùng -> thay vì .
			if(p[i]->getAdd() == "HN")
				res.push_back(p[i]);
		}
		return res;
	}
};
class EmployeePT: public Person{
private:
	int hour;
	long money;
public:
	EmployeePT(){}
	EmployeePT(string name, int age, string add, string tel, string sex, int hour, long money): 
		Person(name, age, add, tel, sex), hour(hour), money(money){}
	int getHour(){
		return hour;
	}
	long getMoney(){
		return money;
	}
	void display(){
		cout<<"Employee Part Time"<<endl;
		Person::display();
		cout<<"Hour: "<<hour<<endl;
		cout<<"Money: "<<money<<endl;
		cout<<"Salary: "<<salary()<<endl;
	}
	long salary(){
		return hour*money;
	}
	static vector<EmployeePT> getMaxSalary(vector <EmployeePT> pt){
		long maxSalary = pt[0].salary();
		vector<EmployeePT> res;
		for (int i = 1; i < pt.size(); i++)
		{
			if(maxSalary < pt[i].salary())
				maxSalary = pt[i].salary();
		}
		for (int i = 0; i < pt.size(); i++)
		{
			if(maxSalary == pt[i].salary())
				res.push_back(pt[i]);
		}
		return res;

	}
};
class EmployeeFT: public Person{
private:
	int day;
	long money;
public:
	EmployeeFT(){}
	EmployeeFT(string name, int age, string add, string tel, string sex, int day, long money): 
		Person(name, age, add, tel, sex), day(day), money(money){}
	int getDay(){
		return day;
	}
	long getMoney(){
		return money;
	}
	void display(){
		cout<<"Employee Full Time"<<endl;
		Person::display();
		cout<<"Day: "<<day<<endl;
		cout<<"Money: "<<money<<endl;
		cout<<"Salary: "<<salary()<<endl;
	}
	long salary(){
		return day*money;
	}
	static vector<EmployeeFT> getMaxSalary(vector <EmployeeFT> ft){
		long maxSalary = ft[0].salary();
		vector<EmployeeFT> res;
		for (int i = 1; i < ft.size(); i++)
		{
			if(maxSalary < ft[i].salary())
				maxSalary = ft[i].salary();
		}
		for (int i = 0; i < ft.size(); i++)
		{
			if(maxSalary == ft[i].salary())
				res.push_back(ft[i]);
		}
		return res;

	}
};


class Point{
public:
    int x;
    int y;
public:
    Point(){}
    Point(int x, int y): x(x), y(y){}
    friend Point operator - (Point A, Point B){
        return Point(A.x - B.x, A.y - B.y);
    }
    double distance(Point B){
        return sqrt((this->x - B.x)*(this->x - B.x) + (this->y - B.y)*(this->y - B.y));
    }
};
class Traingle: public Point{
private:
    Point A;
    Point B;
    Point C;
public:
    Traingle(){}
    Traingle(Point A, Point B, Point C): A(A), B(B), C(C){}
    double perimeter(){
        return A.distance(B)+ B.distance(C)+ C.distance(A);
    }
    double area(){
        double p = perimeter()/2;
        return sqrt(p* (p-A.distance(B))* (p-B.distance(C))* (p-C.distance(A)));
    }
    Point center(){
        return Point((A.x+B.x+C.x)/3.0, (A.y+B.y+C.y)/3.0);
    }
    bool isTrangle(){
        double a = A.distance(B);
        double b = B.distance(C);
        double c = C.distance(A);
        return (a+b>c && a+c>b && b+c>a);
    }
};

class Food{
private:
    string name;
    double price;
public:
    Food(){}
    Food(string name, double price): name(name), price(price) {}
    void setName(string name){
        this-> name = name;
    }
    void setPrice(double price){
        this-> price = price;
    }
    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
};
class CannedFood: public Food{
private:
    int numberBox;
public:
    CannedFood(){}
    CannedFood(string name, double price, int numberBox): Food(name, price), numberBox(numberBox) {}
    void display(){
        cout<<"Name: "<<getName()<<endl;
        cout<<"Price: "<<getPrice()<<endl;
        cout<<"Number box: "<<numberBox<<endl;
    }
    void setNumberBox(int numberBox){
    	this->numberBox = numberBox;
    }
    int getNumberBox(){
        return numberBox;
    }
    void sortNumberBox(vector<CannedFood>&vt){
        for (int i = 0; i < vt.size() - 1; i++)
        {
        	for (int j = 0; j < vt.size(); j++)
        	{
        		if(vt[i].getNumberBox() > vt[j].getNumberBox())
        			swap(vt[i], vt[j]);
        	}
        }
    }
};
class NonCFood: public Food{
private:
    double weight;
public:
    NonCFood(){}
    NonCFood(string name, double price, double weight): Food(name, price), weight(weight) {}
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Weight: "<<weight<<endl;
    }
    void setWeight(double weight){
    	this->weight =weight;
    }
    int getWeight(){
        return weight;
    }
    void sortWeight(vector<NonCFood>&vt){
        for (int i = 0; i < vt.size() - 1; i++)
        {
        	for (int j = 0; j < vt.size(); j++)
        	{
        		if(vt[i].getWeight() > vt[j].getWeight())
        			swap(vt[i], vt[j]);
        	}
        }
    }
};

class Score{
protected:
	double math;
	double literature;
	double english;
public:
	Score(){}
	Score(double math, double literature, double english): math(math), literature(literature), english(english){}
	double getMath(){
		return math;
	}
	double getLiterature(){
		return literature;
	}
	double getEnglish(){
		return english;
	}
	virtual double pointA(){
		return 0;
	}
	virtual double pointB(){
		return 0;
	}
	virtual double pointC(){
		return 0;
	}
	virtual double pointD(){
		return 0;
	}
	virtual double avgPoint() = 0;
	static double getMaxAvg(vector<Score*>vt){
		double maxAvg = vt[0]->avgPoint();
		for (int i = 1; i < vt.size(); i++)
		{
			if(maxAvg < vt[i]->avgPoint())
					maxAvg = vt[i]->avgPoint();
		}
		return maxAvg;
	}
	static double getMinAvg(vector<Score*>vt){
		double minAvg = vt[0]->avgPoint();
		for (int i = 1; i < vt.size(); i++)
		{
			if(minAvg > vt[i]->avgPoint())
					minAvg = vt[i]->avgPoint();
		}
		return minAvg;
	}	
	bool isPass(){
		return avgPoint()>5;
	}
	static double getMaxPointA(vector<Score*>vt){
		double maxPointA = vt[0]->pointA();
		for (int i = 1; i < vt.size(); i++)
		{
			if(maxPointA < vt[i]->pointA())
					maxPointA = vt[i]->pointA();
		}
		return maxPointA;
	}
	static double getMaxPointB(vector<Score*>vt){
		double maxPointB = vt[0]->pointB();
		for (int i = 1; i < vt.size(); i++)
		{
			if(maxPointB < vt[i]->pointB())
					maxPointB = vt[i]->pointB();
		}
		return maxPointB;
	}
	static double getMaxPointC(vector<Score*>vt){
		double maxPointC = vt[0]->pointC();
		for (int i = 1; i < vt.size(); i++)
		{
			if(maxPointC < vt[i]->pointC())
					maxPointC = vt[i]->pointC();
		}
		return maxPointC;
	}
	static double getMaxPointD(vector<Score*>vt){
		double maxPointD = vt[0]->pointD();
		for (int i = 1; i < vt.size(); i++)
		{
			if(maxPointD < vt[i]->pointD())
					maxPointD = vt[i]->pointD();
		}
		return maxPointD;
	}
};
class ScoreNatural: public Score{
private:
	double physic;
	double chemistry;
	double biology;
public:
	ScoreNatural(){}
	ScoreNatural(double math, double literature, double english, double physic, double chemistry, double biology):
		Score(math, literature, english), physic(physic), chemistry(chemistry), biology(biology) {}
	double getPhysic(){
		return physic;
	}
	double getChemistry(){
		return chemistry;
	}
	double getBiology(){
		return biology;
	}
	double pointA(){
		return math + getPhysic() + getChemistry();
	}
	double pointB(){
		return math + getChemistry() + getBiology();
	}
	double pointNatural(){
		return physic + chemistry + biology;
	}
	double avgPoint(){
		return (math + literature + english + physic + chemistry + biology)/6;
	}
};
class ScoreSocial: public Score{
private:
	double ce;
	double geography;
	double history;
public:
	ScoreSocial(){}
	ScoreSocial(double math, double literature, double english, double ce, double geography, double history):
		Score(math, literature, english), ce(ce), geography(geography), history(history) {}
	double getCe(){
		return ce;
	}
	double getGeography(){
		return geography;
	}
	double getHistory(){
		return history;
	}
	double pointC(){
		return math + getCe() + getGeography();
	}
	double pointD(){
		return math + getGeography() + getHistory();
	}
	double pointSocial(){
		return ce + geography + history;
	}
	double avgPoint(){
		return (math + literature + english + ce + geography + history)/6;
	}
};

class Group{
private:
	string nameGr;
	vector<Family> f;
public:
	Group(){}
	Group(string nameGr, vector<Family>f): nameGr(nameGr), f(f) {}
	string getNameGr(){
		return nameGr;
	}
	vector<Family> getF(){
		return f;
	}
	int getNumberFamily(){
		return f.size();
	}
	static double avgAgeGroup(Group v){
		double sum = 0;
		int n = 0;
		vector<Family> f(v.getF());
		for(int i =0; i<f.size(); i++){
			vector<People> p(f[i].getP());
			for (int j = 0; j < p.size(); j++)
			{
				sum+= p[j].getAge();
			}
			n+=p.size();
		}
		return sum/n;
	}
	static vector<People> getPeopleHaveNotJob(Group g){
		vector<People> res;
		vector<Family> f(g.getF());
		for (int i = 0; i < F.size(); i++)
		{
			vector<People>p (f[i].getP());
			for (int j = 0; j < p.size(); j++)
			{
				if(p[j].getJob() == "")
					res.push_back(p[i]);
			}
		}
		return res;
	}
};
class Family{
private:
	string nameF;
	string status;
	string add;
	vector<People> p;
public:
	Family(){
	    nameF = p[0].getName();
	}
	Family(string add, string status, vector<People> p): 
	    add(add), status(status), p(p) {
	        nameF = p[0].getName();
		}
	string getStatus(){
		return status;
	}
	string getAdd(){
		return add;
	}
	vector<People> getP(){
		return p;
	}
	void display(){
		cout<<"householder's name: "<<nameF<<endl;
		cout<<"Number Member: "<<p.size()<<endl;
		cout<<"Address: "<<add<<endl;
		cout<<"Status: "<<status<<endl;
		cout<<"List Information Member"<<endl;
		for(int i =0; i<p.size(); i++)
			p[i].display();
	}
	static vector<Family> getPoorHousehold(vector<Family> fa){
		vector<Family>res;
		for (int i = 0; i < fa.size(); i++)
		{
			if(fa[i].getStatus() == "poor")
				res.push_back(fa[i]);
		}
		return res;
	}
	static vector<Family> findFamilySurename(vector<Family>fa, string surename){
		vector<Family>res;
		for (int i = 0; i < fa.size(); i++)
		{
			if(fa[i].getNameF() == surename)
				res.push_back(fa[i]);
		}
		return res;
	}
};
class People{
private:
	string name;
	int age;
	string job;
	string id;
public:
	People(){}
	People(string name, int age, string job, string id): name(name), age(age), job(job), id(id) {}
	string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	string getJob(){
		return job;
	}
	string getId(){
		return id;
	}
	void display(){
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Job: "<<job<<endl;
		cout<<"Id: "<<id<<endl;
	}
};

class Person{
private:
	string name;
	int age;
	string add;
	vector<Book> vb;
public:
	Person(){}
	Person(string name, int age, string add, vector<Book>vb): 
		name(name), age(age), add(add), vb(vb) {}
	string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	string getAdd(){
		return add;
	}
	vector<Book> getVB(){
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
		cout << "Money Pay: " << moneyPay() << endl;
	}
	static void sortPersonAge(vector<Person*>&vt){
		for (int i = 0; i < vt.size()-1; i++)
		{
			for (int j = i+1; j < vt.size(); j++)
			{
				if(vt[i]->getAge() > vt[j]->getAge())	
					swap(vt[i], vt[j]);			
			}
		}
	}
	static vector<int> getListAge(vector<Person*>vt)
	{
		vector<int> str;
		for (int i = 0; i < vt.size(); i++)
		{
			if (!(find(str.begin(), str.end(), vt[i]->getAge()) != str.end()))
			{
				str.push_back(vt[i]->getAge());
			}
		}
		return str;
	}
	static vector<Book> getMaxBookBorrowed(vector<Person*> vp, vector<Book> vB){
		vector<int> count(vB.size(), 0);
		for(int i = 0; i<vB.size(); i++){
			for (int j = 0; j < vp.size(); j++)
			{
				vector<Book> bookPerson(vp[j]->getVB());
				for(int k = 0; k<bookPerson.size(); k++)
					if(vB[i].getNameBook() == bookPerson[k].getNameBook())
						count[i]++;
			}
		}
		int maxx = *max_element(count.begin(), count.end()); // #include <algorithm>
		vector<Book> res;
		for (int i = 0; i < vB.size(); i++)
		{
			if(count[i] == maxx)
				res.push_back(vB[i]);
		}
		return res;
	}
};
class Book{
private:
	string nameBook;
	string nameAuthor;
	int numberBook;
public:
	Book(){}
	Book(string nameBook, string nameAuthor, int numberBook): 
		nameBook(nameBook), nameAuthor(nameAuthor), numberBook(numberBook) {}
	string getNameBook(){
		return nameBook;
	}	
	string getNameAuthor(){
		return nameAuthor;
	}
	int getNumberBook(){
		return numberBook;
	}
	void display()
	{
		cout << "Name Book: " << this->nameBook << endl;
		cout << "Name Author: " << this->nameAuthor << endl;
		cout << "Number Book: " << this->numberBook << endl;
	}
};
class Children: public Person{
public:
	Children(){}
	Children(string name, int age, string add, vector<Book> vb): 
		Person(name, age, add, vb){}
	long moneyPay(){
		return this->getVB().size()*5000;
	}
	void display(){
		cout<<"Children!"<<endl;
		Person::display();
	}
};
class Adult: public Person{
public:
	Adult(){}
	Adult(string name, int age, string add, vector<Book> vb):
		Person(name, age, add, vb) {}
	long moneyPay(){
		return this->getVB().size()*5000;
	}
	void display(){
		cout<<"Adult!"<<endl;
		Person::display();
	}
};


