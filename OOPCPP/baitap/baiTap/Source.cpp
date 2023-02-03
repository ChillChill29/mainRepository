#include "Student.cpp"
#include "Staff.cpp"
#include <vector>

bool returnImport()
{
    int n;
    cout << "____________________" << endl;
    cout << "0: de thoat" << endl;
    cout << "1: de tiep tuc" << endl;
    cout << "Chon: ";
    cin >> n;
    while (n != 0 && n != 1)
    {
        cout << "____________________" << endl;
        cout << "Ban nhap sai" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "0: de thoat" << endl;
        cout << "1: de tiep tuc" << endl;
        cout << "Chon: ";
        cin >> n;
    }
    return (n == 1);
}

void endProgram()
{
    int n;
    cout << "____________________" << endl;
    cout << "0: de thoat ra" << endl;
    cout << "chon: ";
    cin >> n;
    while (n != 0)
    {
        cout << "Ban nhap sai" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "____________________" << endl;
        cout << "0: de thoat ra" << endl;
        cout << "chon: ";
        cin >> n;
    }
}

int main()
{
    vector<Staff> staff;
    vector<Student> student;
    int key;
    do
    {
        system("cls");
        cout << "0: thoat" << endl;
        cout << "1: student" << endl;
        cout << "2: staff" << endl;
        cout << "Chon: ";
        cin >> key;
        switch (key)
        {
        case (0):
        {
            exit(0);
        }
        break;
        case (1):
        {
            do
            {
                system("cls");
                cout << "0: Quay lai" << endl;
                cout << "1: Nhap them hoc sinh" << endl;
                cout << "2: Hien thi danh sach hoc sinh" << endl;
                cout << "3: Tim hoc sinh" << endl;
                cout << "Chon: ";
                cin >> key;
                switch (key)
                {
                case (1):
                {
                    Student s;
                    s.getInformation();
                }
                break;
                case (2):
                {
                }
                break;
                case (3):
                {
                }
                break;
                default:
                {
                    cout << " Ban nhap sai" << endl;
                    cout << " Vui long nhap lai" << endl;
                    system("pause");
                }
                }
            } while (key != 0);
        }
        break;
        case (2):
        {
        }
        break;
        default:
        {
            cout << " Ban nhap sai" << endl;
            cout << " Vui long nhap lai" << endl;
            system("pause");
        }
        }
    } while (key != 0);
    return 0;
}