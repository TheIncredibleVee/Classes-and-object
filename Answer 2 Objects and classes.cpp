#include<iostream>
#include<stdio.h>
using namespace std;

/*Class*/
class Flight{
	int number;
	char* destination;
	float distance;
	float fuel;
	void calfuel(int);
	public:
		void feedinfo();
		void showinfo();
};


/*Class functions Definations*/
void Flight::feedinfo(){
	cout<<"Enter details of the flight\n1. flight number";
	cin>>number;
	cout<<"\n2. Destination of the flight";
	gets(destination);
	cout<<"\n3. Disatnce of the flight";
	cin>>distance;
	calfuel(distance);
}
void Flight::showinfo(){
	cout<<"Flight details \n 1. Number\t"<<number<<endl<<"2. Destination\t "<<destination<<endl<<"3. Distance\t"<<distance<<endl<<"4. Fuel\t"<<fuel;
}
void Flight::calfuel(int x){
	fuel=x>2000?2200:x>1000?1100:500;
}
int main(){
	return 0;
}

