#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
int n;

/*Function Prototypes*/
void lsearch_Author(char*);
void bsort();
void delete_Book(int);
void books_Issued();
void del(int);
void swap(int);
void Displayrecord();

/*Class*/
class Book{
    int  bookId;
    char name[20];
	char author[20];
	char publisher[20];
	float price;
	int noofcopies;
	int noofcopiesissued;
	static int count[10];
	public :
		char* getauthor();
		int getnoofcopiesissued();
		int getnoofcopies();
		int getid();
		void showdata();
		void getdata();
}books[50];

/*Main Function*/
int main(int argc, char** argv){
	int x,choice;
	char* temp;
	cout<<"Enter the number of Books";
	cin>>n;
	printf("Enter the details of each of %d books\n", n);
	for(int i=0;i<n;++i){
		books[i].getdata();
	}
	/*Operations in form of a menu*/
	do{
		cout<<"\n\n\n Main Menu ";
		cout<<"\n\n1. Record of all the books for a specific author\n2. List of books whose all the copies have been issued\n3. Delete a complete book\n4. Sort the list of books on basis of their ID\n5. Exit";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter the name fo the authour for whose books you want to see";
				cin.ignore();
				cin.getline(temp,30);
				lsearch_Author(temp);
				break;
			case 2:
				books_Issued();
				break;
			case 3:
				cout<<"\nEnter the book ID of the book you want to remove";
				cin>>x;
				delete_Book(x);
				break;
			case 4:
				bsort();
				break;
			case 5:
				cout<<"Exiting";
				break;
			default:
				cout<<"\nSorry Wrong choice! Try Again\n";
		}
	}while(choice!=5);
	//delete books;
	return 0;
}

/*Functions Definations*/
void lsearch_Author(char* auth){
	printf("The Books with %s as author are\n",auth);
	int flag=1;
	for (int i=0;i<n;++i){
		if (!strcmpi(auth,books[i].getauthor())){
			books[i].showdata();
			flag=0;
		}
	}
	if(flag){
		printf("\nSorry, No book by %s found.\n", auth);
	}
}
void bsort(){
	for (int i=0;i<n;i++){
		for(int j=0;j<n-i-1;++j){
			if (books[j].getid()>books[j+1].getid())
				swap(j);
		}
	}
	cout<<"\nThe Book list is now sorted.\nDo you wish to have a look at it?\t (y/n)";
	char x= getch();
	if (x=='y'|| x=='Y')
		Displayrecord();
}
void Displayrecord(){
	for(int i=0;i<n;++i){
		books[i].showdata();
	}
}
void delete_Book(int id){
	
	int flag=1;
	for(int i=0;i<n;++i){
		if(id == books[i].getid() ){
			del(i);
			flag=0;
			break;								//Assuming that Book Id is unique
		}
	}
	if(flag)
		printf("No book of Book id %d found in the book list",id);
	else 
	printf("\n Book with ID %d successfully deleted the record\n", id);
}

void del(int x){
	for (;x<n;){
			books[x++]=books[x];
	}
	n--;
}
void books_Issued(){
	for(int i=0;i<n;++i){
	 	if(books[i].getnoofcopies()==books[i].getnoofcopiesissued()){
	 		books[i].showdata();
		 }
	}	
}

void swap(int pos){
	Book buffer;
	buffer =books[pos];
	books[pos]=books[pos+1];
	books[pos+1]=buffer;
}

/*Class functions Definations*/
void Book::showdata(){
	printf("\n1. Book Id\t %d \n2. Name\t %s \n3. Author\t %s \n4. Publisher\t %s \n5. Price\t %.2f \n6. Total Number of Copies of book\t %d \n7. Number of Copies of book issued\t %d ",bookId,name,author,publisher,price,noofcopies,noofcopiesissued);
	
}
void Book::getdata(){
	cout<<"Enter the details of the book";
	cout<<"\n1. Book ID \t";
	cin>>bookId;
	cin.ignore();
	cout<<"\n2. Name of the book \t";
	cin.getline(name,30);
	cout<<"\n3. Author of the book \t";
	cin.getline(author,30);
	cout<<"\n4. Publisher of the book \t";
	cin.getline(publisher,30);
	cout<<"\n5. Price of the book \t";
	cin>>price;
	cout<<"\n6. Total number of copies of the book \t";
	cin>>noofcopies;
	cout<<"\n7. Number of copies of the book issued \t";
	cin>>noofcopiesissued;
}
char* Book::getauthor(){
	return author;
}
int Book::getnoofcopies(){
	return noofcopies;
}
int Book::getnoofcopiesissued(){
	return noofcopiesissued;
}
int Book::getid(){
	return bookId;
}
