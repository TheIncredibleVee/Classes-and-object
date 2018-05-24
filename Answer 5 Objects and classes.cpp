#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

/*Class*/
class Cloth{
	char code[30];
	char type[50];
	int size;
	char material[50];
	float price;
	void Calc_price();
	public:
		Cloth();
		void getData();
		void showData();
};

/*Main Function*/
int main(int argc, char* arv[]){
	Cloth *c=new Cloth();			// New pointer to cloth
	c->showData();					// Checking that constructor correctly or not
	c->getData();					//Change the data
	c->showData();					//Check if the data is chnaged or not
	return 0;	
}

/*Class functions Definations*/
void Cloth::Calc_price(){
	if(!strcmpi(material,"cotton")){
		if (!strcmpi(type,"trouser"))
			price=1500;
		else if (!strcmpi(type,"shirt")){
			price=1200;
		}
		else
			price=1000;
	}	
	else{
		if (!strcmpi(type,"trouser"))
			price=0.75*float(1500);
		else if (!strcmpi(type,"shirt")){
			price=0.75*(1200);
		}
		else
			price=1000;
		
	}
}
Cloth::Cloth(){
	strcpy(type,"NOT ASSIGNED");
	strcpy(code,"NOT ASSIGNED");
	strcpy(material,"NOT ASSIGNED");
	price=0;
	size=0;
}
void Cloth::getData(){
	cout<<"\nEnter the details as follows\n1. Code of the cloth \t";
	cin.ignore();
	cin.getline(code,30);
	cout<<"2. Type of the cloth \t";
	cin.getline(type,30);
	cout<<"3. Size of the cloth \t";
	cin>>size;
	cout<<"4. Material of the cloth \t";
	cin.ignore();
	cin.getline(material,30);
	Calc_price();
}
void Cloth::showData(){
	printf("The details are as follows\n1. Code of the cloth \t %s \n2. Type of the cloth \t %s \n3. Size of the cloth \t %d \n4.Material of the coth \t %s \n5. Price of the cloth\t %.2f\n", code, type, size, material, price);
}

