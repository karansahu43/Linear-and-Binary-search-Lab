// Author:  Karan Sahu
// Assignment Number: Lab 5
// File Name: driver.cpp
// Course/Section: data struct
// Due Date:  11/13/18
// Instructor: Bernard Ku
//This program creates 2 arrays one string one int to use linear and binary search(needs to sort with binary) to find wanted element to ultimately check if the searches are working


#include <iostream>
#include <string>
#include <algorithm>
#include <array>


#include "linearSearch.cpp"
#include "binarySearch.cpp"

using namespace std;

//This function is a template function which will take parameters of a template defined array and an intger to display the array
//Pre condition: parrameters template array and integer
//Post condition: True
template<class ItemType>
void Display(ItemType theArray[], int S){
	
	for(int i = 0; i < S; i++)
	{
		cout << theArray[i] << " ";
	}
}

//This function is a template function which will take parameters of a template defined array, an intger and target(the element that needs to be searched for) to  use search functions to search array and return the 
//position of the element if found
//Pre condition: parrameters template array and integer and template target 
//Post condition: return position
template<class ItemType>
int Search(ItemType arr[], int S, ItemType target){
	
	int selection, position;
	
	cout << endl << "Which Searching method would you like to use?" << endl << "1. Linear\n2. Binary\n";
	cout << "which option would you like 1 or 2:";
	cin >> selection;
	
	if(selection == 1)
	{
		position = linearSearch(arr, S, target);
	}
	else if(selection == 2)
	{
		sort (arr, arr + S);
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

//The main function will create arrays find out what type the user wants for the array use all the functions to ultametly search the array and check if the functions are working or not
//Pre condition: True
//Post condition: return 0
int main () {
	
	string a[5] = {"david","john", "josh", "mason","richard"};
	int b[8] = {1, 5, 9, 12, 15, 21, 29, 31};
	int typechecker;
	int holderI[8];
	string holderS[5];
	bool driverLoop= true;
	int position;
	string Schoice;
	int Ichoice;
	
	while(driverLoop)
	{
		cout << endl;
		cout << "Which type of array do you want to search?" << endl;
		cout << "1. Integer" << endl;
		cout << "2. String" << endl;
		cout << "3. Exit" << endl;
		cout << "Pick 1, 2, or 3: ";
		cin >> typechecker;
		if(typechecker==1)
		{
			for(int i = 0; i < 8; i++)
			{
				holderI[i] = b[i];
			}
			cout << endl << "Original Array: ";
			Display(b, 8);
			cout << endl << "What number would you like to search for? ";
			cin >> Ichoice;
			position = Search<int> (holderI, 8, Ichoice);

		}
		else if(typechecker==2)
		{
			for(int i = 0; i < 5; i++)
			{
				holderS[i] = a[i];
			}
			cout << endl << "Original Array: ";
			Display(a, 5);
			cout << endl << "What string would you like to search for?(Case Sensitive) ";
			cin >> Schoice;
			position = Search<string> (holderS, 5, Schoice);
		}
		if(typechecker==3)
		{
			driverLoop = false;
		}
	}
	return 0;
}

/*


Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 1

Original Array: 1 5 9 12 15 21 29 31
What number would you like to search for? 5

Which Searching method would you like to use?
1. Linear
2. Binary
which option would you like 1 or 2:1

5 was found!

Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 1

Original Array: 1 5 9 12 15 21 29 31
What number would you like to search for? 32

Which Searching method would you like to use?
1. Linear
2. Binary
which option would you like 1 or 2:1

32 was not found
Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 1

Original Array: 1 5 9 12 15 21 29 31
What number would you like to search for? 5

Which Searching method would you like to use?
1. Linear
2. Binary
which option would you like 1 or 2:2

5 was found!

Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 1

Original Array: 1 5 9 12 15 21 29 31
What number would you like to search for? 123

Which Searching method would you like to use?
1. Linear
2. Binary
which option would you like 1 or 2:2

123 was not found
Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 2

Original Array: david john josh mason richard
What string would you like to search for?(Case Sensitive) dsa

Which Searching method would you like to use?
1. Linear
2. Binary
which option would you like 1 or 2:1

dsa was not found
Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 2

Original Array: david john josh mason richard
What string would you like to search for?(Case Sensitive) david

Which Searching method would you like to use?
1. Linear
2. Binary
which option would you like 1 or 2:1

david was found!

Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 2

Original Array: david john josh mason richard
What string would you like to search for?(Case Sensitive) sdqw

Which Searching method would you like to use?
1. Linear
2. Binary
which option would you like 1 or 2:2

sdqw was not found
Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 2

Original Array: david john josh mason richard
What string would you like to search for?(Case Sensitive) mason

Which Searching method would you like to use?
1. Linear
2. Binary
which option would you like 1 or 2:2

mason was found!

Which type of array do you want to search?
1. Integer
2. String
3. Exit
Pick 1, 2, or 3: 3



*/

