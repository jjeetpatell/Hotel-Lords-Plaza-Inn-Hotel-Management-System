/* Hotel Management System */

// This project lets's you perform each and every operation needed in a Hotel. 
// This Project has various options like ---
// 1. Book a Room - Allows you to Book a Room in the Hotel
// 2. Customer Record - Displays you the Customer Record
// 3. Rooms Allocated - Displays the Total Rooms Allocated
// 4. Edit Record - Allows you to Edit a Record
// 5. Food Menu - Displays the Food Menu for ordering the Food
// 6. Food Bill - Let's you calculate the Food Bill and Display it
// 7. Exit - When you're done with your task, you can exit as and when needed...

// This program is a Fully-Functional Program
// I developed this program code back in my High-School
// I developed this code on Turbo C/C++ Compiler

//#include "graf.cpp"
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>
char Cname[50];
char Iname[50];
int Ino;
float bill;


class hotel
{
	int room_no;
	char name[30];
	char address[50];
	char phone[10];

	public:
	void main_menu();    //to dispay the main menu
	void add();        //to book a room
	void display();    //to display the customer record
	void rooms();    //to display alloted rooms
	void edit();    //to edit the customer record
	int check(int);    //to check room status
	void modify(int);    //to modify the record
	void delete_rec(int);    //to delete the record
	void foodmenu();   //to display food menu
	void food_bill();  //to calculate food bill

};

void hotel::main_menu()
{
	int choice;

	while(choice!=7)
	{
	clrscr();
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\t\t\t\t* MAIN MENU *";
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\n\n\t\t\t1.Book A Room";
	cout<<"\n\t\t\t2.Customer Record";
	cout<<"\n\t\t\t3.Rooms Allotted";
	cout<<"\n\t\t\t4.Edit Record";
	cout<<"\n\t\t\t5.Food Menu";
	cout<<"\n\t\t\t6.Food bill";
	cout<<"\n\t\t\t7.Exit";

	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>choice;

	switch(choice)
	{
		case 1: add();
			break;
		case 2: display();
			break;
		case 3: rooms();
			break;
		case 4: edit();
			break;
		case 5: foodmenu();
			break;
		case 6: food_bill();
			break;
		case 7:break;

		default:
			{
			cout<<"\n\n\t\t\tWrong choice!!!";
			cout<<"\n\t\t\tPress any key to continue!!";
			getch();
			}
	}
	}
}

void hotel::add()
{
	clrscr();
	int r,flag;
	ofstream fout("Record.dat",ios::app);

	cout<<"\n Enter Customer Detalis";
	cout<<"\n **********************";
	cout<<"\n\n Room no: ";
	cin>>r;
	flag=check(r);

	if(flag)
	cout<<"\n Sorry..!!!Room is already booked";
	else
	{
	room_no=r;
	cout<<" Name: ";
	gets(name);
	cout<<" Address: ";
	gets(address);
	cout<<" Phone No: ";
	gets(phone);
	fout.write((char*)this,sizeof(hotel));
	cout<<"\n Room is booked!!!";
	}

	cout<<"\n Press any key to continue!!";
	getch();
	fout.close();
}

void hotel::display()
{
	clrscr();
	ifstream fin("Record.dat",ios::in);
	int r,flag;
	cout<<"\n Enter room no: ";
	cin>>r;

	while(!fin.eof())
	{
	fin.read((char*)this,sizeof(hotel));
	if(room_no==r)
	{
		clrscr();
		cout<<"\n Cusromer Details";
		cout<<"\n ****************";
		cout<<"\n\n Room no: "<<room_no;
		cout<<"\n Name: "<<name;
		cout<<"\n Address: "<<address;
		cout<<"\n Phone no: "<<phone;
		flag=1;
		break;
	}
	}

	if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";

	cout<<"\n\n Press any key to continue!!";
	getch();
	fin.close();
}

void hotel::rooms()
{
	clrscr();
	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\tList Of Rooms Allotted";
	cout<<"\n\t\t\t*********************";
	cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

	while(!fin.eof())	
	{
	fin.read((char*)this,sizeof(hotel));
	cout<<"\n\n "<<room_no<<"\t\t"<<name;
	cout<<"\t\t"<<address<<"\t\t"<<phone;
	}

	cout<<"\n\n\n\t\t\tPress any key to continue!!";
	getch();
	fin.close();
}

void hotel::edit()
{
	clrscr();
	int choice,r;

	cout<<"\n EDIT MENU";
	cout<<"\n *********";
	cout<<"\n\n 1.Modify Customer Record";
	cout<<"\n 2.Delete Customer Record";

	cout<<"\n Enter your choice: ";
	cin>>choice;

	clrscr();
	cout<<"\n Enter room no: ";
	cin>>r;

	switch(choice)
	{
	case 1: modify(r);
		break;
	case 2: delete_rec(r);
		break;
	default: cout<<"\n Wrong Choice!!";
	}

	cout<<"\n Press any key to continue!!!";
	getch();
}

int hotel::check(int r)
{
	int flag=0;
	ifstream fin("Record.dat",ios::in);
	while(!fin.eof())
	{
	fin.read((char*)this,sizeof(hotel));
	if(room_no==r)
	{
		flag=1;
		break;
	}
	}

	fin.close();
	return(flag);
}

void hotel::modify(int r)
{
	long pos,flag=0;
	fstream file("Record.dat",ios::in|ios::out|ios::binary);

	while(!file.eof())
	{
	pos=file.tellg();
	file.read((char*)this,sizeof(hotel));
	if(room_no==r)
	{
		cout<<"\n Enter New Details";
		cout<<"\n *****************";
		cout<<"\n Name: ";
		gets(name);
		cout<<" Address: ";
		gets(address);
		cout<<" Phone no: ";
		gets(phone);

		file.seekg(pos);
		file.write((char*)this,sizeof(hotel));
		cout<<"\n Record is modified!!";
		flag=1;
		break;
	}
	}

	if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";

	file.close();
}

void hotel::delete_rec(int r)
{
	int flag=0;
	char ch;
	ifstream fin("Record.dat",ios::in);
	ofstream fout("temp.dat",ios::out);

	while(!fin.eof())
	{
	fin.read((char*)this,sizeof(hotel));
	if(room_no==r)
	{
		cout<<"\n Name: "<<name;
		cout<<"\n Address: "<<address;
		cout<<"\n Pone No: "<<phone;
		cout<<"\n\n Do you want to delete this record(y/n): ";
		cin>>ch;

		if(ch=='n')
		fout.write((char*)this,sizeof(hotel));

		flag=1;
	}
	else
		fout.write((char*)this,sizeof(hotel));
	}

	fin.close();
	fout.close();

	if(flag==0)
	cout<<"\n Sorry room no. not found or vacant!!";
	else
	{
	remove("Record.dat");
	rename("temp.dat","Record.dat");
	}
}
void hotel::foodmenu()
{       clrscr();
	cout<<"\t\t\t\tFOOD MENU";
	cout<<"\n1. All time Favourites(Rs.200)\t\t\t4.Ice cream(Rs.100) ";
	cout<<"\n\t  (a)French fries\t\t\t(a)Butterscotch";
	cout<<"\n\t  (b)Garlic bread\t\t\t(b)Chocolate fudge";
	cout<<"\n\t  (c)Sandwitch\t\t\t\t(c)Double chocolate";
	cout<<"\n\t  (d)Burger";
	cout<<"\n\t  (e)Pizza";

	cout<<"\n2.Starter(Rs.100)\t\t\t\t5.Aerated Drinks(Rs.80)";
	cout<<"\n\t  (a)Soup\t\t\t\t(a)Cola";
	cout<<"\n\t  (b)Masala Papad\t\t\t(b)Diet Pepsi";
	cout<<"\n\t  (c)Kabab\t\t\t\t(c)Lime soda";
	cout<<"\n\t  (d)Cheese balls\t\t\t(d)Mineral Water";


	cout<<"\n3.Main course(Rs.300)";
	cout<<"\n\t  3.1 Subjiyan\t\t\t 3.2 Chapati";
	cout<<"\n\t\t  (a)Shahi paneer\t\t(a)Tandoori roti";
	cout<<"\n\t\t  (b)Paneer tikka\t\t(b)Rumali Roti";
	cout<<"\n\t\t  (c)Veg kohlapuri\t\t(c)Butter naan";
	cout<<"\n\t\t  (d)Malai kofta";
	cout<<"\n\t  3.3 Rice\t\t\t 3.4 Dal";
	cout<<"\n\t\t  (a)Jeera rice\t\t\t (a)Dal Makhni";
	cout<<"\n\t\t  (b)Schezhwan rice\t\t (b)Dal Fry";
	cout<<"\n\t\t  (c)Veg biryani\t\t (c)Punjabi Kadhi";
	cout<<"\n\t\t  (d)Pulav";
	cout<<"\n\n\t Press any key to continue....!!!";
	getch();
}
void hotel::food_bill()
{
	clrscr();
	cout<<"\t\t\t\n\nEnter customer name \t";
	gets(Cname);
	cout<<"\t\t\t\n\nEnter item name\t";
	gets(Iname);
	cout<<"\t\t\t\n\nEnter quantity of items\t";
	cin>>Ino;
	cout<<"\t\t\t\n\nThe bill amount is\t";
	float price;
	int atf=200;
	int start=100;
	int mainc=300;
	int icecreams=100;
	int adrinks=80;

		if(strcmp(Iname,"All time favourite")==0)
			bill=atf*Ino;
		else
			if(strcmp(Iname,"Starters")==0)
				bill=start*Ino;
			else
				if(strcmp(Iname,"Main Course")==0)
					bill=mainc*Ino;
				else
					if(strcmp(Iname,"Ice creams")==0)
						bill=icecreams*Ino;
					else
						if(strcmp(Iname,"Aerated Drinks")==0)
							bill=adrinks*Ino;
	cout<<bill;
	getch();
}

void main()
{
	hotel h;
	clrscr();
	cout<<"\n\t\t\t****************************";
	cout<<"\n\t\t\t*\t WELCOME TO\t *";
	cout<<"\n\t\t\t****************************";
	sleep(1);
	cout<<"\n\n\n";
	cout<<"\n\t\t\t****************************";
	cout<<"\n\t\t\t*\t HOTEL PARKTON\t *";
	cout<<"\n\t\t\t****************************";
	sleep(1);
	cout<<"\n\n\n\n\n\t\t\tPress any key to continue!!";
	getch();

	h.main_menu();
}






























































































































