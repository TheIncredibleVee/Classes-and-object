#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int i;

/*Class*/
class Shop{
	char name[40];
	char address[40];
	char type[3][40];
	int avail[3];
	int total[3];
		
	public:
		void init();
		int purchase();
		void display();
};

/*Class functions Definations*/
void Shop::init(){
	cout<<"Enter the setails as follows: \n1.Name of the shop\t";
	gets(name);
	cout<<"\n2. Address of the shop\t";
	gets(address);
	cout<<"\n3. Type of items \n";
	for(i=0;i<3;i++){
		cout<<"Item "<<i<<"\t";
		gets(type[i]);
	}
	cout<<"\n4. Avaliable quantity of each item \n";
	for(i=0;i<3;i++){
		cout<<"Item "<<i<<"\t";
		cin>>avail[i];
	}
	cout<<"\n5. Total quantity of each item \n";
	for(i=0;i<3;i++){
		cout<<"Item "<<i<<"\t";
		cin>>total[i];
	}
}
void Shop::display(){
	cout<<"Name of the Shop:\t ";
	puts(name);
	cout<<"Address of the Shop:\t ";
	puts(address);
	cout<<endl<<endl<<"Items:\t";
	for (i=0;i<3;++i){
		puts(type[i]);
		cout<<"\t";
	}
	cout<<endl<<endl<<"Balance Stock :\t";
	for (i=0;i<3;++i){
		cout<<avail[i]<<"\t";
	}
}
int Shop::purchase(){
	char* temp;
	unsigned int val;
	cout<<"Enter the name of the item purchased\n";
	gets(temp);
	for (i=0;i<3;++i){
		if(!strcmpi(temp,type[i])){
			cout<<"Enter the number of items purchased\n";
			cin>>val;
			if (avail[i]>val){
				avail[i]-=val;
				cout<<"Purchase Complete!\n";
				return 0;
			}
			else 
				cout<<"Pruchase Incomplete!\n Quantity entered is too high!\n";
				return 1;
		}
	}
	cout<<"No item named "<<temp<<" found!";
	return -1;
}
