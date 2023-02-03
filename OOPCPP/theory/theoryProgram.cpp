



#include <iostream>
#include "myClassOrigin.cpp"

using namespace std;


// các hàm không cần có dữ liệu đầu vào
/*class Rectangle {
public:
    double width;
    double length;

    void getInformation() {
        cin >> width;
        cin >> length;
    }
    // *
    double getArea() {
        return width * length;
    }
    // *
    double getPerimeter() {
        return (width + length) * 2;
    }

    void display() {
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};*/

 // Ưu tiên dùng double đối với số thực
int main() {
    Account account1(1000, "Tuan", 2000);
    account1.display();
    account1.withdraw(2100);
    account1.deposit(600);
    cout << "Balance: " << account1.getBalance() << endl;
    account1.withdraw(2100);
    cout << "Balance: " << account1.getBalance() << endl;
    return 0;
}