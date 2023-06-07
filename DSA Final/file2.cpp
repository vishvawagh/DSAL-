#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class Student
{
public:
	int rollno;
	char name[20],add[20];
	char dv;
	void get()
	{
		cout<<"Enter Name: ";
		cin>>name;
		cout<<"Enter Roll no.: ";
		cin>>rollno;
		cout<<"Enter Division: ";
		cin>>dv;
		cout<<"Enter Address: ";
		cin>>add;
	}
	void put()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Roll No.: "<<rollno<<endl;
		cout<<"Division: "<<dv<<endl;
		cout<<"Address: "<<add<<endl;
        cout<<"---------------------------------"<<endl;

	}
	int getroll()
	{
		return rollno;
	}
};
void write_record()
{
	ofstream outFile;
	Student obj;
	outFile.open("student.dat", ios::binary | ios::app);
	obj.get();
	outFile.write((char*)&obj, sizeof(obj));
	outFile.close();
}
void display_record()
{
	ifstream inFile;
	Student obj;
	inFile.open("student.dat", ios::binary);
	while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.put();
    }
	inFile.close();
}
void search_record(int n)
{
	ifstream inFile;
	Student obj;
	inFile.open("student.dat", ios::binary);
	while(inFile.read((char*)&obj, sizeof(obj)))
	{
		if(obj.getroll() == n)
		{
			obj.put();
			break;
		}
	}
	inFile.close();
}
void delete_record(int n)
{
	Student obj;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	ofstream outFile;
	outFile.open("temp.dat", ios::binary | ios::out);
	while(inFile.read((char*)&obj, sizeof(obj)))
	{
		if(obj.getroll() != n)
			outFile.write((char*)&obj, sizeof(obj));
	}
	inFile.close();
	outFile.close();
    cout << "Record Deleted" << endl;
	remove("student.dat");
	rename("temp.dat", "student.dat");
}
void modify_record(int n)
{
	fstream file;
	file.open("student.dat", ios::in | ios::out);
	Student obj;
	while(file.read((char*)&obj, sizeof(obj)))
	{
		if(obj.getroll() == n)
		{
			cout<<"Enter new details: ";
			obj.get();
			int pos = -1*sizeof(obj);
			file.seekp(pos,ios::cur);
			file.write((char*)&obj, sizeof(obj));
		}
	}
	file.close();
     cout << "Record modified" << endl;
}
int main()
{
	int ch, n;
	cout<<"*Student Data using Sequential file*\n";
	while(true)
	{
		cout<<"1. Write Info"<<endl;
		cout<<"2. Display Info"<<endl;
		cout<<"3. Search Info"<<endl;
		cout<<"4. Delete Info"<<endl;
		cout<<"5. Modify Info"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter no. of records: ";
			cin>>n;
			for(int i=0; i<n; i++)
				write_record();
			break;
			case 2: display_record(); break;
			case 3: cout<<"Enter roll no.: ";
			cin>>n;
			search_record(n);
			break;
			case 4: cout<<"Enter roll no.: ";
			cin>>n;
			delete_record(n);
			break;
			case 5: cout<<"Enter roll no.: ";
			cin>>n;
			modify_record(n);
			break;
			case 6: exit(1); break;
		}
	}
	return 0;
}