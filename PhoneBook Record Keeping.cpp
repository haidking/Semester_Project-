#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

//universal varibles which can be used by any function in the program
char mobile[15];
char email[30];
char address[50];
string record,check,name;
int i=0,count=0;

//Function that gets and stores data in the txt file
void info()
{
    ofstream fileout;
    fileout.open("PhoneBook.txt",ios::app);
        cout<<endl<<"...............CREATE NEW PHONE RECORD..............."<<endl,cin.ignore();
        
        //searches the text file again to check if the name is present or not
        while(true)
        {
			cout<<"Enter Record Name   : "; getline(cin,name);
			ifstream filein("PhoneBook.txt");
			while(getline(filein,record))
			{
				if(record.compare(name)==0)
				{
					count++;
				}
				continue;
				if(filein.eof())
				break;
			}
			if(count)
			{
				cout<<"This name is already present. Try a different name."<<endl;
				count=0;
			}
			else
			break;
		}
		
        cout<<"Enter Mobile Number : "; cin.getline(mobile,15);
        cout<<"Enter E-Mail        : "; cin.getline(email,30);
        cout<<"Enter Address       : "; cin.getline(address,50);
        cout<<endl;
		fileout<<name<<endl;
        fileout<<"Contact: "<<mobile<<endl;
        fileout<<"Email: "<<email<<endl;
        fileout<<"Address: "<<address<<endl;
    fileout.close();
    cout<<endl<<"Record Saved to File"<<endl<<endl<<endl;
}

//function that displays the data of the text file line by line
void DisplayRec()
{
    ifstream filein;
    filein.open("PhoneBook.txt",ios::app);
    while(getline(filein,record))
    {
    	cout<<record<<endl;
	}
    cout<<endl<<"Reading of Data File Completed"<<endl<<endl<<endl;
}

//function that helps in searching for the name and then displaying its data which
//is on the next three lines
void searchRec(string search)
{
	 ifstream filein;
    filein.open("PhoneBook.txt",ios::app);
    while(getline(filein,record))
    {
    	if(record.length()==search.length()&&record.compare(search)==0)
    	{	
    		while(getline(filein,record) && i<4)
    		{
				cout<<record<<endl;
				i++;
			}
		}
    	else
    	continue;
	}
	if(filein.eof())
	cout<<"Record no found"<<endl;
}


//The main menu
int main()
{
    int choice;
    char ans;
    string search;
    {
        cout<<"............................................"<<endl;
        cout<<"           PHONE BOOK MANAGEMENT            "<<endl;
        cout<<"............................................"<<endl<<endl;
        cout<<"::::::::::::::: PROGRAM MENU :::::::::::::::"<<endl;
        cout<<"1. Save New Phone Record"<<endl;
        cout<<"2. Display All Saved Records"<<endl;
        cout<<"3. Search for records"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>choice;

        system("CLS");
        switch(choice)
        {
            case 1: info(); break;
            case 2: DisplayRec(); break;
            case 3: cout<<endl<<"...............SEARCH FOR A RECORD................"<<endl;
					cout<<"Enter the name: ";cin.ignore(); getline(cin,search); searchRec(search); break;
			case 4:exit(0);
        }
    }
    cout<<"Do you want to run the program again?"<<endl<<"'Y' for yes and 'N' for no: ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
    	system("CLS");
    	main();
    }
    else
    exit(0);
}


