/*
	< Jazmin Even Dorra >

	colorWheel.cpp

	Menu-Driven interface program that allows the user to:
		1. Primary colors
		2. Secondary colors
		3. Tertiary colors
		4. Color wheel
		5. Quit
*/

// Header Files
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Prototypes
void displayWheel(const int);
const int SIZE = 12;

int main()
{
	// Variables & Constants
	
	string colors[SIZE];
	int choice;
	fstream myFile;
	

	// Open file for reading
	myFile.open("wheel.dat", ios::in | ios::binary);


	if (myFile.fail())
	{
		cout << "Fatal Error ... Could not read file." << endl;
		exit(EXIT_FAILURE);
	}


	// Intro
	cout << "\nThe Wheel of Colors App ..." << endl;

	do
	{
		cout << "\nChoose one of the following options" << endl
			<< "\t1. Primary colors." << endl
			<< "\t2. Secondary colors." << endl
			<< "\t3. Tertiary colors." << endl
			<< "\t4. Color Wheel." << endl
			<< "\t5. Quit" << endl
			<< "Option: ";
		cin >> choice;

		

		switch (choice)
		{
		case 1:  // Display primary colors

			// Yellow
			myFile.seekg(0L, ios::beg);
			getline(myFile, colors[0]);

			// Red
			myFile.seekg(48L, ios::cur);
			getline(myFile, colors[1]);

			// Blue
			myFile.seekg(48L, ios::cur);
			getline(myFile, colors[2]);

			// Display primary colors
			cout << "\nPrimary Colors" << endl
				<< "------------------------------------" << endl;

			for (int i = 0; i < 3; i++)
			{
				cout << setw(10) << colors[i] << "\t";
			}
			
			cout << endl;

			// go back to the beginnninng of the file
			// Clear the eof flag
			myFile.clear();
			myFile.seekg(0L, ios::beg);		//rewind the read position
			break;

		case 2:	// secondary colors
			// Orange
			myFile.seekg(32L, ios::beg);
			getline(myFile, colors[3]);

			// Purple 
			myFile.seekg(48L, ios::cur);
			getline(myFile, colors[4]);

			// Green
			myFile.seekg(48L, ios::cur);
			getline(myFile, colors[5]);

			// Display secondary colors
			cout << "\nSecondary Colors" << endl
				<<"------------------------------------" << endl;
			
			for (int i = 3; i < 6; i++)
			{
				cout << setw(10) << colors[i] << "\t";
			}

			cout << endl;

			// go back to the beginnninng of the file
			// Clear the eof flag
			myFile.clear();
			myFile.seekg(0L, ios::beg);		//rewind the read position
			break;
			

		case 3: // Display tertiary colors
			// Amber
			myFile.seekg(16L, ios::beg);
			getline(myFile, colors[6]);

			// Vermillion
			myFile.seekg(16L, ios::cur);
			getline(myFile, colors[7]);

			// Magenta
			myFile.seekg(16L, ios::cur);
			getline(myFile, colors[8]);

			// Violet
			myFile.seekg(16L, ios::cur);
			getline(myFile, colors[9]);

			// Teal
			myFile.seekg(16L, ios::cur);
			getline(myFile, colors[10]);

			// Chartreuse
			myFile.seekg(16L, ios::cur);
			getline(myFile, colors[11]);

			// Display tertiary colors
			cout << "\nTertiary Colors" << endl
				<< "------------------------------------" << endl;

			// Display
			
			for (int i = 6; i < 12; i++)
			{
				
				cout << setw(10) << colors[i] << "\t";
				if (i == 8)
					cout << endl;
			}

			cout << endl;

			// go back to the beginnninng of the file
			// Clear the eof flag
			myFile.clear();
			myFile.seekg(0L, ios::beg);		//rewind the read position
			break;

		case 4: // Display wheel of colors

			displayWheel(SIZE);
		
			break;
		case 5: // QUIT
			cout << "\nGood Bye ..." << endl;
			break;
			
		default:
			cout << "Error ... Invalid choice. Try again." << endl;
		}

	} while (choice != 5);

	// Close file
	myFile.close();

	return 0;
}

/*
	void displayWheel()

	Displays all the colors of the wheel of colors

	Return Value: none
*/
void displayWheel(const int size)
{
	string colorWheel[SIZE];
	
	fstream file;

	// Open file for reading
	file.open("wheel.dat",ios::in);


	if (file.fail())
	{
		cout << "Fatal Error ... Could not read file." << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++)
	{
		getline(file, colorWheel[i]);
	}

	cout << "\nColor Wheel" << endl
		<< "------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		if (i % 3 == 0)
			cout << endl;
		cout << colorWheel[i];
		
	}
	
	// Close file
	file.close();


	return;
}

