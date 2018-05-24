#include<iostream>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>
using namespace std;
int i=0,n=0,avgmarks=0;

/* Function Protoypes*/
void toppers();
void failures();
void avg();
void abvavg();
void belavg();

/*Class*/
class student{ 
	int admno;
	char name[20];
	static char subjectname[5][20];
	int marks[5];
	float percentage;
	void calpercentage();
	public:
		static char* returnsubjectname(int x){
			return subjectname[x];
		}
		static void subject(char* temp, int x){
			for(int j=0;j<strlen(temp);++j){
				subjectname[x][j]=temp[j];
			}
			subjectname[x][strlen(temp)]='\0';
		}
		void details();
		int returnmarks(int);
		void showdata();
}stud[50];

/*Static members initlization*/
char student::subjectname[5][20]={"Physics", "Chemistry", "Maths", "English", "Computer Science"};

/*Main Function*/
int main(int argc, char* argv[]){
	int choice;
	char temp[50];

	/*Entering of the data*/
	cout<<"\nEnter the number of students for the program\t";
	cin>>n;
	cout<<"\nNow enter the name of the subjects.\n";
	for (i=0;i<5;++i){
		cout<<"\n "<<i+1<<"\t";
		cin.getline(temp,30);
		student::subject(temp,i);
	}
	cout<<"\nNow enter the details of each student\n";
	for(int k=0;k<n;++k){
		stud[k].details();
	}

	/*Operations in form of a menu*/
	do{
		cout<<"\n\n\n Main Menu ";
		cout<<"\n\n1. List of toppers in each subject\n2. List of failures in each subject\n3. Average marks in each subject\n4. Count of students above average in each subject\n5.Count of students below average in each subject\n6. Exit";
		cin>>choice;
		switch(choice){
			case 1:
				toppers();
				break;
			case 2:
				failures();
				break;
			case 3:
				avg();
				break;
			case 4:
				abvavg();
				break;
			case 5:
				belavg();
				break;
			case 6:
				cout<<"Exiting";
				break;
			default:
				cout<<"\nSorry Wrong choice! Try Again\n";
		}
	}while(choice!=6);
	return 0;
}

/*Functions Definations*/
void toppers(){
	for (int l=0;l<5;l++){
		printf("\nTopper in %s is \n", student::returnsubjectname(l));
		int max=stud[0].returnmarks(l);
		int pos =0;
		for (int j=0;j<n;j++){
			if(stud[j].returnmarks(l)>max){
				max=stud[j].returnmarks(l);
				pos=j;
			}
		}
		stud[pos].showdata();
	}
}
void failures(){
	for (int l=0;l<5;l++){
		printf("\nFailures in %s is/are \n", student::returnsubjectname(l));	
		for (int j=0;j<n;j++){
			if(stud[j].returnmarks(l)<33.33){
				stud[j].showdata();
			}
		}
	}
}
void avg(){
	for (int l=0;l<5;l++){
		float avgmarks;
		int counter=0;
		for (int j=0;j<n;j++){
			counter+=stud[j].returnmarks(l);
		}
		avgmarks=counter/(float)n;
		printf("\nAverage marks in %s is %.2f \n", student::returnsubjectname(l),avgmarks);	
		//cout<<"\n"<<avgmarks<<"\n\n";
	}
}
void abvavg(){
	for (int l=0;l<5;l++){
		printf("count of students with marks above average in %s is/are\t",student::returnsubjectname(l));	
		float avgmarks;
		int count=0,counter=0;
		for (int j=0;j<n;j++){
			counter+=stud[j].returnmarks(l);
		}
		avgmarks=counter/(float)n;
		for (int m=0;m<n;m++){
			if(stud[m].returnmarks(l)>=avgmarks){
				count++;
			}
		}
		cout<<count<<"\n";
	}
}
void belavg(){
	for (int l=0;l<5;l++){
		printf("count of students with marks below average in %s is/are\t",student::returnsubjectname(l));	
		float avgmarks;
		int count=0, counter=0;
		for (int j=0;j<n;j++){
			counter+=stud[j].returnmarks(l);
		}
		avgmarks=counter/(float)n;
		for (int m=0;m<n;m++){
			if(stud[m].returnmarks(l)<avgmarks){
				count++;
			}
		}
		cout<<count<<"\n";
	}
}

/*Class functions Definations*/
void student::details(){
	cout<<"Enter the details of the student\n 1. Admission Number\t";
	cin>>admno;
	cout<<"\n2. Name \n";
	cin.getline(name,30);
	cout<<"3.Enter the Marks of the student in \n ";
	for (i=0;i<5;++i){
		cout<<subjectname[i]<<"\t";
		cin>>marks[i];
	}
	calpercentage();
}
void student::showdata(){
	printf("Detalis of the student are as follows\n 1 Admn No\t %d\n 2. Name\t %s \n 3. Marks\n", admno, name) ;
	for(i=0;i<5;++i){
		printf("3.%d %s\t %d \n", i+1, subjectname[i], marks[i]);
	}
	printf("4. Percentage\t %.2f",percentage);
}
void student::calpercentage(){
	int sum=0;
	for(i=0;i<5;++i){
		sum+=marks[i];
	}
	percentage=sum/float(5);
}
int student::returnmarks(int a){
	return marks[a];
}
