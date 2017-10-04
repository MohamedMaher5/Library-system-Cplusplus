#include<fstream>
#include<iostream>
using namespace std;
class Book{
public:
	char ISBN[10];
	char book_name[20];
	char Auther_name[20];
	char Publisher_name[20];
	char Year_of_publishing[10];
	char Edition_number[5];
};
int number_of_books;
fstream file1;
Book book[100];
void Insert(){
	int flag = 0;
	char in_ISBN[10];
	cout << "Enter number of Books :";
	cin >> number_of_books;
	for (int i = 0; i < number_of_books; i++)
	{
		int count = 0;
	cout << "\nEnter ISBN : ";
	cin >> in_ISBN;
	file1.open("Data.txt", ios::in);
	while (!file1.eof()){
		file1.getline(book[count].ISBN, 10, '|');
		file1.getline(book[count].book_name, 20, '|');
		file1.getline(book[count].Auther_name, 20, '|');
		file1.getline(book[count].Publisher_name, 20, '|');
		file1.getline(book[count].Year_of_publishing, 10, '|');
		file1.getline(book[count].Edition_number, 5, '\n');
		if (strcmp(in_ISBN, book[count].ISBN) == 0){
			flag = 1;
		}
		count++;}
	if (flag == 1){
		cout << "This ISBN is exist.\n";
	}
	file1.close();
	if (flag == 0){
		file1.open("Data.txt", ios::app);
			strcpy_s(book[i].ISBN, in_ISBN);
			cout << "Enter Book name " << i + 1 << " : ";
			cin >> book[i].book_name;
			cout << "Enter Auther name " << i + 1 << " : ";
			cin >> book[i].Auther_name;
			cout << "Enter Publisher name " << i + 1 << " : ";
			cin >> book[i].Publisher_name;
			cout << "Enter Year of publishing " << i + 1 << " : ";
			cin >> book[i].Year_of_publishing;
			cout << "Enter Edition number " << i + 1 << " : ";
			cin >> book[i].Edition_number;
			file1 << book[i].ISBN << "|" << book[i].book_name << "|" << book[i].Auther_name << "|" << book[i].Publisher_name << "|" << book[i].Year_of_publishing << "|" << book[i].Edition_number << "\n";
			file1.close();
	}
	}
}
void Display(){
	int i = 0;
	file1.open("Data.txt", ios::in);
	if (!file1)
		cout << "\ncannot open the file in read mode. \n";
	cout<<"ISBN\t Book name\t Author name\t Publisher name\t Year of the publishing \t Edition number \n";
	while (!file1.eof())
	{
		file1.getline(book[i].ISBN, 10, '|');
		file1.getline(book[i].book_name, 20, '|');
		file1.getline(book[i].Auther_name, 20, '|');
		file1.getline(book[i].Publisher_name, 20 ,'|');
		file1.getline(book[i].Year_of_publishing, 10, '|');
		file1.getline(book[i].Edition_number, 5, '\n');
		cout << book[i].ISBN << "\t" << book[i].book_name << "\t" << book[i].Auther_name << "\t" << book[i].Publisher_name << "\t" << book[i].Year_of_publishing << "\t" << book[i].Edition_number<<endl;
		i++;
	}
	file1.close();
}
void Search()
{
	int flag;
	char Search_with[10];
	int Number_with;
	int i;
	file1.open("Data.txt", ios::in);
	if (!file1)
		cout << "\n unable to open the file in read mode. ";
	cout << "1:Search with ISBN " << endl;
	cout << "2:Search with Book name " << endl;
	cout << "3:Search with Author name " << endl;
	cout << "4:Search with Year of Publishing " << endl;
	cout << "Enter number you want Search : ";
	cin >> Number_with;
	switch (Number_with){
		case 1:
			flag = 0, i = 0;
			cout << "\nEnter the record's ISBN you want to search : ";
			cin >> Search_with;
			while (!file1.eof())
			{
				file1.getline(book[i].ISBN, 10, '|');

				if (strcmp(book[i].ISBN, Search_with) == 0)
				{
					cout << "\nRecord found.\n";
					cout << "ISBN\t Book name\t Author name\t Publisher name\t Year of the publishing \t Edition number \n";
					cout << book[i].ISBN << "\t" << book[i].book_name << "\t" << book[i].Auther_name << "\t" << book[i].Publisher_name << "\t" << book[i].Year_of_publishing << "\t" << book[i].Edition_number << endl;
					flag = 1;
				}
				i++;
			}
				if (flag != 1)
					cout<<"\nRecord not found!\n";
				file1.close();
			break;
		case 2:
			flag = 0, i = 0;
			cout << "\nEnter the record's Book name you want to search = ";
			cin >> Search_with;
			while (!file1.eof())
			{
				file1.getline(book[i].ISBN, 10, '|');
				file1.getline(book[i].book_name, 20, '|');

				if (strcmp(book[i].book_name, Search_with) == 0)
				{
					cout << "\nRecord found.\n";
					cout << "ISBN\t Book name\t Author name\t Publisher name\t Year of the publishing \t Edition number \n";
					cout << book[i].ISBN << "\t" << book[i].book_name << "\t" << book[i].Auther_name << "\t" << book[i].Publisher_name << "\t" << book[i].Year_of_publishing << "\t" << book[i].Edition_number << endl;
					flag = 1;
				}
				i++;
			}
			if (flag != 1)
				cout << "\nRecord not found!\n";
			file1.close();
			break;
		case 3:
			flag = 0, i = 0;
			cout << "\nEnter the record's Auther name you want to search = ";
			cin >> Search_with;
			while (!file1.eof())
			{
				file1.getline(book[i].ISBN, 10, '|');
				file1.getline(book[i].book_name, 20, '|');
				file1.getline(book[i].Auther_name, 20, '|');
				
				if (strcmp(book[i].Auther_name, Search_with) == 0)
				{
					cout << "\nRecord found.\n";
					cout << "ISBN\t Book name\t Author name\t Publisher name\t Year of the publishing \t Edition number \n";
					cout << book[i].ISBN << "\t" << book[i].book_name << "\t" << book[i].Auther_name << "\t" << book[i].Publisher_name << "\t" << book[i].Year_of_publishing << "\t" << book[i].Edition_number << endl;
					flag = 1;
				}
				i++;
			}
			if (flag != 1)
				cout << "\nRecord not found!\n";
			file1.close();
			break;
		case 4:
			flag = 0, i = 0;
			cout << "\nEnter the record's Year of Publishing you want to search = ";
			cin >> Search_with;
			while (!file1.eof())
			{
				file1.getline(book[i].ISBN, 10, '|');
				file1.getline(book[i].book_name, 20, '|');
				file1.getline(book[i].Auther_name, 20, '|');
				file1.getline(book[i].Publisher_name, 20, '|');
				file1.getline(book[i].Year_of_publishing, 10, '|');

				if (strcmp(book[i].Year_of_publishing, Search_with) == 0)
				{
					cout << "\nRecord found.\n";
					cout << "ISBN\t Book name\t Author name\t Publisher name\t Year of the publishing \t Edition number \n";
					cout << book[i].ISBN << "\t" << book[i].book_name << "\t" << book[i].Auther_name << "\t" << book[i].Publisher_name << "\t" << book[i].Year_of_publishing << "\t" << book[i].Edition_number << endl;
					flag = 1;
				}
				i++;
			}
			if (flag != 1)
				cout << "\nRecord not found!\n";
			file1.close();
			break;
		default:
			cout << "\nInvalid choice";
			break;
		}
}
void Delete(){
	fstream temp;
	char delete_field[10];
	cout << "Enter ISBN you want to delete : ";
	cin >> delete_field;
	int i = 0, j = 0;
	file1.open("Data.txt", ios::in);
	temp.open("temp.txt", ios::app);
	while (!file1.eof())
	{	
		file1.getline(book[i].ISBN, 10, '|');
		file1.getline(book[i].book_name, 20, '|');
		file1.getline(book[i].Auther_name, 20, '|');
		file1.getline(book[i].Publisher_name, 20, '|');
		file1.getline(book[i].Year_of_publishing, 10, '|');
		file1.getline(book[i].Edition_number, 5, '\n');
		i++;
	}
	j = 0;
	while (j<i)
		{	
			if (strcmp(delete_field, book[j].ISBN) != 0){
				temp << book[j].ISBN << "|" << book[j].book_name << "|" << book[j].Auther_name << "|" << book[j].Publisher_name << "|" << book[j].Year_of_publishing << "|" << book[j].Edition_number << "\n";
			}
			j++;
		}
	cout << "Record has been deleted if it exsisted" << endl;
	file1.close();
	temp.close();
	remove("Data.txt");
	rename("temp.txt", "Data.txt");
	
}
void Update()
{
	int flag = 0;
	char modify_field[10];
	int i = 0;
	int j = 0;
	file1.open("Data.txt", ios::in);
	if (!file1)
		cout << "\nunable to open the file in input mode";
	cout << "\nEnter ISBN you want to modify : ";
	cin >> modify_field;
	while (!file1.eof())
	{
		file1.getline(book[i].ISBN, 10, '|');
		file1.getline(book[i].book_name, 20, '|');
		file1.getline(book[i].Auther_name, 20, '|');
		file1.getline(book[i].Publisher_name, 20, '|');
		file1.getline(book[i].Year_of_publishing, 10, '|');
		file1.getline(book[i].Edition_number, 5, '\n');
		i++;
	}
	for (j = 0; j < i; j++)
	{
		if (strcmp(modify_field, book[j].ISBN) == 0)
		{
			cout << "\nThe old values of the record with ISBN '" << book[j].ISBN << "' are";
			cout << "\nISBN = " << book[j].ISBN;
			cout << "\nBook Name = " << book[j].book_name;
			cout << "\nAuther Name = " << book[j].Auther_name;
			cout << "\nPublisher Name = " << book[j].Publisher_name;
			cout << "\nYear of Publishing = " << book[j].Year_of_publishing;
			cout << "\nEdition Number = " << book[j].Edition_number;


			cout << "\nEnter the new values";
			cout << "\nISBN = ";
			cin >> book[j].ISBN;
			cout << "\nBook Name = ";
			cin >> book[j].book_name;
			cout << "\nAuther Name = ";
			cin >> book[j].Auther_name;
			cout << "\nPublisher Name = ";
			cin >> book[j].Publisher_name;
			cout << "\nYear of Publishing = ";
			cin >> book[j].Year_of_publishing;
			cout << "\nEdition Number = ";
			cin >> book[j].Edition_number;
			flag = 1;
		}
	}

	if (flag != 1)
		cout << "\The record with ISBN '" << book[j].ISBN << "' is not exist. ";
	file1.close();

	file1.open("Data.txt", ios::out);
	if (!file1)
		cout << "\nUnable to open the file in output mode";
	j = 0;
	while (j < i){
		file1 << book[j].ISBN << "|" << book[j].book_name << "|" << book[j].Auther_name << "|" << book[j].Publisher_name << "|" << book[j].Year_of_publishing << "|" << book[j].Edition_number << "\n";
		j++;
	}
	file1.close();
}
int main()
{
	int choice;
	for (;;)
	{
		cout << "1 : Insert record\n";
		cout << "2 : Search record\n";
		cout << "3 : Delete record\n";
		cout << "4 : Display record\n";
		cout << "5 : Update record\n";
		cout << "6 : Exit\n\n";
		cout << "\nEnter the choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Insert();
			break;

		case 2:
			Search();
			break;

		case 3: 
			Delete();
			break;

		case 4: 
			Display();
			break;

		case 5:
			Update();
			break;

		case 6:
			exit(0);
			break;

		default: 
			cout << "invalid choice !\n";
			break;
		}
	}
	return 0;
}