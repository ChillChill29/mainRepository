class testOOP
{
private:
	int name;
	string age;
	int countt = 0
protected:
	int value = 4;	
public:
	testOOP(){
		cout<<"testOOP duoc goi";
	}
	testOOP(int name, string age){
		this.
	}
	~testOOP();
	static int countCalled(){
		countt++;
	}	
};


class childOfTestOOP: public testOOP
{

}