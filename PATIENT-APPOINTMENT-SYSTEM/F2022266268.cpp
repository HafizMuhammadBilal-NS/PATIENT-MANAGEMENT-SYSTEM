#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

const int cap = 50;

void loadfromfile(int& NOP, string filename, int agearray[], double phonearray[], string namearray[], string genarray[], string mailarray[], string cnicarray[])
{
	ifstream rdr(filename);
	if (!rdr)
	{
		cout << "File not found !!!" << endl;
	}

	rdr >> NOP;
	rdr.close();
	filename = "input.txt";
	rdr.open(filename);

	if (!rdr)
	{
		cout << "input File not found !!!" << endl;
	}

	for (int i = 0; i < NOP; i++)
	{
		char ch;
		ch = rdr.peek();
		while (ch == '\n' || ch == ' ')
		{
			rdr.ignore();
			ch = rdr.peek();
		}

		string name;
		getline(rdr, name);
		namearray[i] = name;


		rdr >> genarray[i];

		rdr >> agearray[i];

		rdr >> cnicarray[i];

		rdr >> mailarray[i];
		ch = rdr.peek();
		rdr.ignore();
		ch = rdr.peek();
		rdr >> phonearray[i];
	}

}

void print(int& NOP, string filename, int agearray[], double phonearray[], string namearray[], string genarray[], string mailarray[], string cnicarray[])
{

	for (int i = 0; i < NOP; i++)
	{
		cout << endl << " Details of patient " << i + 1 << " is :" << endl;
		cout << setprecision(13);
		cout << "Name of patient " << i + 1 << ": " << setw(1) << namearray[i] << endl;
		cout << "Gender of patient " << i + 1 << ": " << setw(1) << genarray[i] << endl;
		cout << "Age of patient " << i + 1 << ": " << setw(1) << agearray[i] << endl;
		cout << "CNIC of patient " << i + 1 << ": " << setw(1) << cnicarray[i] << endl;
		cout << "Phone number of patient " << i + 1 << ": " << setw(1) << phonearray[i] << endl;
		cout << "Gmail of patient " << i + 1 << ": " << setw(1) << mailarray[i] << endl;

		cout << endl << endl;
	}

}

void addingpatient(int& NOP, string filename, int agearray[], double phonearray[], string namearray[], string genarray[], string mailarray[], string cnicarray[], int enter)
{
	filename = "input.txt";
	ofstream wtr(filename, ios::app);

	if (!wtr)
	{
		cout << "File not found !!!" << endl;
	}

	//wtr << (NOP + enter);

	for (int i = 0; i < enter; i++)
	{
		cout << "Enter the name of patient :" << endl;
		cin.ignore();
		getline(cin, namearray[NOP + i]);
		wtr << endl << endl << endl << namearray[NOP + i] << endl;


		cout << "Enter the gender of patient :" << endl;
		//cin.ignore();
		getline(cin, genarray[NOP + i]);
		wtr << genarray[NOP + i] << endl;


		cout << "Enter the age of patient :" << endl;
		cin >> agearray[NOP + i];
		wtr << agearray[NOP + i] << endl;


		cout << "Enter the CNIC of patient :" << endl;
		cin.ignore();
		getline(cin, cnicarray[NOP + i]);
		wtr << cnicarray[NOP + i] << endl;


		cout << "Enter the Gmail of patient :" << endl;
		//cin.ignore();
		getline(cin, mailarray[NOP + i]);
		wtr << mailarray[NOP + i] << endl;


		cout << "Enter the phone number of patient :" << endl;
		cin >> phonearray[NOP + i];
		wtr << phonearray[NOP + i] << endl;
	}

	NOP = NOP + enter;

	wtr.close();
	wtr.open("NOP.txt");
	wtr << NOP;
}

bool searching(int NOP, string cnicarray[], int& data)
{
	string search;
	cin.ignore();
	getline(cin, search);

	for (int i = 0; i < NOP; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (search[j] != cnicarray[i][j])
			{
				break;
			}

			if (j == 12)
			{
				data = i;
				return true;
			}

		}
	}
	return false;

}

void salaryadding()
{
	double salary = 0;
	int salarray[30] = {};

	ifstream rdr("salaryinfo.txt");
	if (!rdr)
	{
		cout << "File not found !!" << endl;
	}

	char ch;
	ch = rdr.peek();
	int i = 0;
	while (ch != EOF)
	{
		rdr >> salarray[i];
		ch = rdr.peek();
		salary = salary + salarray[i];
		i++;
	}

	char a;
	cout << "Do you want to enter your " << i + 1 << " day salary (y/n)" << endl;
	cin >> a;
	if (a != 'n')
	{
		int nesal = 0;
		rdr.close();
		ofstream wtr("salaryinfo.txt", ios::app);
		cout << "Enter your " << i + 1 << " day salary :" << endl;
		cin >> nesal;
		wtr << endl << nesal;
		salary = salary + nesal;
	}

	cout << "Your salary after " << i + 1 << " day is " << salary << endl;

}

int main()
{

	string filename;
	filename = "NOP.txt";
	int NOP = 0;
	int agearray[cap] = {};
	double phonearray[cap] = {};
	string namearray[cap] = {};
	string genarray[cap] = {};
	string mailarray[cap] = {};
	string cnicarray[cap] = {};

	loadfromfile(NOP, filename, agearray, phonearray, namearray, genarray, mailarray, cnicarray);

	while (true)
	{
		int input;
		cout << "Enter 1 for detail of previous patients " << endl;
		cout << "Enter 2 for entering new patients " << endl;
		cout << "Enter 3 for searching the patients data " << endl;
		cout << "Enter 4 for checking the doctor salary  " << endl;
		cout << "Enter 5 for booking the appointments slots" << endl;

		cin >> input;


		while (input > 5)
		{
			cout << "Invalid input Enter again :";
			cin >> input;
		}
		system("cls");

		switch (input)
		{
		case 1:
			print(NOP, filename, agearray, phonearray, namearray, genarray, mailarray, cnicarray);
			break;
		case 2:
			int enter;
			cout << "How many patients do you want to enter :" << endl;
			cin >> enter;
			addingpatient(NOP, filename, agearray, phonearray, namearray, genarray, mailarray, cnicarray, enter);
			print(NOP, filename, agearray, phonearray, namearray, genarray, mailarray, cnicarray);
			break;
		case 3:
			cout << "Enter your CNIC for searching :" << endl;
			int data;
			if (searching(NOP, cnicarray, data) == true)
			{
				cout << "Patient is find " << endl;

				cout << setprecision(13);
				cout << "Name of patient : " << setw(1) << namearray[data] << endl;
				cout << "Gender of patient : " << setw(1) << genarray[data] << endl;
				cout << "Age of patient : " << setw(1) << agearray[data] << endl;
				cout << "CNIC of patient : " << setw(1) << cnicarray[data] << endl;
				cout << "Phone number of patient : " << setw(1) << phonearray[data] << endl;
				cout << "Gmail of patient " << setw(1) << mailarray[data] << endl;
			}
			else
			{
				cout << "Patient not found !!" << endl;
			}
			break;
		case 4:

			salaryadding();
			break;
		case 5: {
			{
				struct Appointment
				{
					string patientName;
					bool booked;
				};

				const int NUM_SLOTS = 10; // we can change this value
				const int BOOK_SLOTS = 6; // we can change this value
				Appointment slots[NUM_SLOTS];

				// initialize all slots as available
				for (int i = 0; i < BOOK_SLOTS; i++)
				{
					slots[i].booked = true;
				}

				// display available slots
				cout << "Available Slots :\n";
				for (int i = 0; i < NUM_SLOTS; i++)
				{
					cout << i + 1 << ". ";
					if (slots[i].booked)
					{
						cout << "(Booked)\n";
					}
					else
					{
						cout << "available" << "\n";
					}
				}

				// ask user to select a slot
				int slotNumber;
				int age;
				cout << "Enter slot number to book: ";
				cin >> slotNumber;

				// check if selected slot is available
				if (slots[slotNumber - 1].booked)
				{
					cout << "Sorry, this slot is already booked. Please select another slot.\n";
				}
				else
				{
					// book the slot
					cout << "Enter patient name: ";
					cin >> slots[slotNumber - 1].patientName;
					cout << "Enter patient age: ";
					cin >> age;
					slots[slotNumber - 1].booked = true;
					cout << "Appointment booked successfully!\n";
				}

				// allow user to cancel appointments
				cout << "if you want to cancel a previous appointment press 'y' otherwise press 'n' ";
				char choice;
				cin >> choice;
				if (choice == 'y' || choice == 'Y')
				{
					cout << "Enter slot number to cancel: ";
					cin >> slotNumber;
					if (slots[slotNumber - 1].booked)
					{

						cout << "Appointment cancelled successfully!\n";
					}
					else
					{
						cout << "Sorry, this slot is already available.\n";
					}
				}
			}
		}
			break;
		}

		char ch;
		cout << "Do you want to continue(y/n)";
		cin >> ch;

		if (ch != 'y')
		{
			cout << "Program terminate " << endl;
			system("cls");
			exit(1);
		}

		system("cls");
	}
	return 0;
}

