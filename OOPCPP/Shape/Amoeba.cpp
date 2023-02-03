#include "Shape.cpp"

class Amoeba :public Shape
{
public:
	Amoeba();
	~Amoeba();
	void rotage(){
		cout<<"Day la Amoeba"<<endl;
	}	
	void playSound(){
		cout<<"Choi ban nhac Amoeba"<<endl;
	}
};