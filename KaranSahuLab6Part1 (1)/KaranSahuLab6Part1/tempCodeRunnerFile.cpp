
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