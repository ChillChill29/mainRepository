#include "Children.cpp"
#include "Adult.cpp"

bool returnImport()
{
    int n;
    cout << "______________________________" << endl;
    cout << "0: de thoat ra" << endl;
    cout << "1: de tiep tuc nhap" << endl;
    cout << "Chon: ";
    cin >> n;
    while (n != 0 && n != 1)
    {
        cout << "Ban nhap sai" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "chon: ";
        cin >> n;
    }
    return (n == 1);
}

void endProgram()
{
    int n;
    cout << "______________________________" << endl;
    cout << "0: de thoat ra" << endl;
    cout << "chon: ";
    cin >> n;
    while (n != 0)
    {
        cout << "Ban nhap sai" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "chon: ";
        cin >> n;
    }
}
int main()
{
    vector<Children> children;
    vector<Adult> adult;
    vector<Book> library;
    vector<Person *> person;
    int key;
    do
    {
        system("cls");
        cout << "0: thoat" << endl;
        cout << "1: them khach hang" << endl;
        cout << "2: them sach" << endl;
        cout << "3: thong ke tuoi" << endl;
        cout << "4: thong ke sach duoc muon nhieu nhat" << endl;
        cout << "5: danh sach tre em" << endl;
        cout << "6: danh sach nguoi lon" << endl;
        cout << "chon: ";
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
                if (library.size() == 0)
                {
                    system("cls");
                    cout << "vui long nhap sach roi quay lai" << endl;
                    system("pause");
                    break;
                }
                int age;
                do
                {
                    cout << "nhap tuoi khach hang: ";
                    cin >> age;
                } while (age < 0);
                if (age < 18)
                {
                    Children ch;
                    Person *newPerson;
                    ch.getInformation(age, library);
                    children.push_back(ch);
                    newPerson = new Children(ch);
                    person.push_back(newPerson);
                    ch.display();
                    cout << "gia tri: " << ch.moneyPay() << endl;
                }
                else
                {
                    Adult ad;
                    Person *newPerson;
                    ad.getInformation(age, library);
                    adult.push_back(ad);
                    newPerson = new Adult(ad);
                    person.push_back(newPerson);
                    ad.display();
                    cout << "gia tri: " << ad.moneyPay() << endl;
                }

            } while (returnImport());
        }
        break;
        case (2):
        {
            Book book;
            do
            {
                system("cls");
                book.getInformation();
                library.push_back(book);
                book.display();
            } while (returnImport());
        }
        break;
        case (3):
        {
            system("cls");
            Person::sortPersonAge(person);
            vector<int> age = Person::getListAge(person);
            for (int i = 0; i < age.size(); i++)
            {
                cout << age[i] << " ";
            }
            cout << endl;
            system("pause");
            endProgram();
        }
        break;
        case (4):
        {
            system("cls");
            cout << "Best-seller: " << endl;
            vector<Book> res = Person::getMaxBookBorrowed(person, library);
            for (int i = 0; i < res.size(); i++)
                cout << res[i].getNameBook() << " ";
            cout << endl;
            system("pause");
            endProgram();
        }
        break;
        case (5):
        {
            system("cls");
            for (int i = 0; i < children.size(); i++)
            {
                children[i].display();
            }
            system("pause");
            endProgram();
        }
        break;
        case (6):
        {
            system("cls");
            for (int i = 0; i < adult.size(); i++)
            {
                adult[i].display();
            }
            system("pause");
            endProgram();
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