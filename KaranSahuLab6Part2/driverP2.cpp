// Author:  Karan Sahu
// Assignment Number: Lab 5
// File Name: driver.cpp
// Course/Section: data struct
// Due Date:  11/13/18
// Instructor: Bernard Ku
//This program is used to compare 2 different searches search times using string and integer data sets with multiple data sizes


#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <fstream>
#include <ctime>

#include "quicksort.cpp"
#include "linearSearch.cpp"
#include "binarySearch.cpp"



using namespace std;


//This function is a template function which will take parameters of a template defined array and an intger to create files to display array
//Pre condition: parrameters array and 2 integers 
//Post condition: True
template<class ItemType>
void Display(ItemType theArray[], int S, int C){
	
	cout << endl << "Creating Text files with Array elements: " << endl;
	if(C==1)
	{
		ofstream myfile ("SortedArray.txt");
		if (myfile.is_open())
		{
			for(int i = 0; i < S; i++)
			{
				myfile << theArray[i] << endl;
			}

    	myfile.close();
   		}
	else cout << "Unable to open file";
	}
	else if(C==0)
	{
		ofstream myfile ("UnSortedArray.txt");
		if (myfile.is_open())
		{
			for(int i = 0; i < S; i++)
			{
				myfile << theArray[i] << endl;
			}

    	myfile.close();
    
    	}
	else cout << "Unable to open file";
	}
	cout << endl << "Complete(check files in folder)\n";
}


//This function is a template function which will take parameters of a template defined array and array target for search 
// and an intger to  use search functions to search array for given target finally returning the position of the target in the array
//Pre condition: parrameters array and 2 integers, and ItemType target 
//Post condition: True
template<class ItemType>
int Search(ItemType arr[], int S, int selection, ItemType target){
	
	int position;
	
	if(selection == 1)
	{
		position = linearSearch(arr, S, target);
	}
	else if(selection == 2)
	{
		position = binarySearch(arr, 0, S-1, target);
	}

	if(position == -1)
	{
		cout << endl << target << " was not found";
	}
	else
		cout << endl << target << " was found!" << endl;
		
	return position;
	
}

int selection1()
{
	int selection;
	
	cout << endl << "Which Searching method would you like to use?" << endl << "1. Linear\n2. Binary(search time does not include sorting)\n";
	cout << "which option would you like 1 or 2:";
	cin >> selection;
	
	return selection;
}

//The main function will use various functions to search int and string arrays giving back if the search was successfull and how long the search took
//Pre condition: True
//Post condition: return 0
int main () {
	
	long long size;
	int typechecker;
	int selection;
	clock_t t;
	int position;
	string Schoice;
	int Ichoice;
	int DisplayCheck = 0;

	bool driverLoop= true;
	
	while(driverLoop)
	{
		cout << endl;
		cout << "Which type of array do you want to sort?" << endl;
		cout << "1. Integer" << endl;
		cout << "2. String" << endl;
		cout << "3. Exit" << endl;
		cout << "Pick 1, 2, or 3: ";
		cin >> typechecker;
		if(typechecker==1)
		{
			size = 0;
			cout << "\nHow many elements?\n1 million: type   (1000000)" << endl << "10 million:  type (10000000)" << endl << "50 million:  type (50000000)" 
			<< endl << "100 million: type (100000000)" << endl << "1 billion: type (1000000000)" ;
			while(!(size == 1000000 || size == 10000000 || size == 50000000 || size == 100000000 || size == 1000000000 ))
			{
				cout<< "\nhow big do you want the array?(type one option)";
				cin >> size;
			}
			
			int* holderI = new int[size];
  
			for(int i = 0; i < size; i++)
 			{
 			   holderI[i] = (rand() % 100000000) + 1;
			}
  
	
			cout << endl << "Would you like to create a text file to view integers in Array(May take a while)" << endl << "type 1 if yes or type 0 if no: ";
			cin >> DisplayCheck;
			
			if(DisplayCheck== 1 )
				Display(holderI, size, 0);
			
			cout << endl << "What number would you like to search for? ";
			cin >> Ichoice;
			selection = selection1();
			if (selection == 2)
				quickSort(holderI,0 , size -1);
			
			
			t = clock();
			position = Search<int> (holderI, size, selection, Ichoice);
			t = clock() - t;
			printf(": search took %d clicks(%f seconds).\n",t,((float)t/CLOCKS_PER_SEC));
			
			delete [] holderI;
  			holderI = nullptr;
		}
		else if(typechecker==2)
		{
			size = 435670;
			//size = 400000;
			
			string* holderS = new string[size];
			
			ifstream myfile ("Lab6string.txt");
			if (myfile.is_open())
			{
		    	for(int i = 0; i < size; i++ )
		    	{
		      		getline (myfile,holderS[i]);
		    	}
			}
			else 
				cout << "Unable to open the file";
			myfile.close();
			cout << endl << "What string would you like to search for?(Case sensitive) ";
			cin >> Schoice;
			selection = selection1();
			quickSort(holderS,0 , size -1);
			t = clock();
			position = Search<string> (holderS, size, selection, Schoice);
			t = clock() - t;
			printf(":search took %d clicks(%f seconds).\n",t,((float)t/CLOCKS_PER_SEC));
			
			delete [] holderS;
  			holderS = nullptr;
		}
		if(typechecker==3)
		{
			driverLoop = false;
		}
	}
	return 0;
}

/*

Which type of array do you want to sort?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 1

How many elements?
1 million: type   (1000000)
10 million:  type (10000000)
50 million:  type (50000000)
100 million: type (100000000)
1 billion: type (1000000000)
how big do you want the array?(type one option)1000000

Would you like to create a text file to view integers in Array(May take a while)
type 1 if yes or type 0 if no: 0

What number would you like to search for? 233214324

Which Searching method would you like to use?
1. Linear
2. Binary(search time does not include sorting)
which option would you like 1 or 2:1

233214324 was not found: search took 0 clicks(0.000000 seconds).

Which type of array do you want to sort?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 2

What string would you like to search for?(Case sensitive) LOVE

Which Searching method would you like to use?
1. Linear
2. Binary(search time does not include sorting)
which option would you like 1 or 2:2

LOVE was found!
:search took 0 clicks(0.000000 seconds).

Which type of array do you want to sort?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 3



*/


