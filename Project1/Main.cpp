/*
	Iacob, Marius

	March 11, 2020

	CS A250
	Assignment 10 STL Vectors and Lists
*/

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

// Declaration function printSet.
// The function passes a list and prints all
// the elements on one line, separated by a space.
// Use a range-based FOR loop. If you do not know
// what this means, search the Web.

void printSet(const set<int>& aSet)
{
	for (auto i : aSet)
	{
		cout << i << " ";
	}
}

int main()
{

	/***************************************************************************
	* SETS
	***************************************************************************/
	cout << "  ***  STL SET CLASS  ***  \n\n";

	// Create a set of ints named set1 and use the initializer list to insert the 
	// following integers in this order: 2, 7, 5, 6, 9, 1 and 3.
	set<int> set1;
	set1.insert(2);
	set1.insert(7);
	set1.insert(5);
	set1.insert(6);
	set1.insert(9);
	set1.insert(1);
	set1.insert(3);

	// Print the set using the printSet function you implemented.
	cout << "set1: ";
	printSet(set1);
	cout << endl;

	// What do you notice in the printout?
		// The numbers were all in order. Not 2, 7, 5, 6, 9, 1 and 3.

	// size_type  erase (const value_type& val);
	// Use the function erase to erase the integer 9 from set1, but this
	// time use cout to print the return value.  What is the return
	// value?
	// Print out set1.
	set1.erase(9);
	cout << "set1 (ERASE 9):";
	for (auto iter = set1.begin(); iter != set1.end(); ++iter)		// Print out while using cout
	{
		cout << " " << *iter;
	}
	cout << endl;

	// size_type  erase (const value_type& val);
	// Use the function erase to erase integer 2 from set1, but
	// this time use cout to print the return value.
	// What is the return value?	
	set1.erase(2);
	cout << "set1 (ERASE 2):";
	for (auto iter = set1.begin(); iter != set1.end(); ++iter)
	{
		cout << " " << *iter;
	}
	cout << endl;

	// If you do not know what the return value is, then
	// check set::erase in cplusplus.com

	// Print set1.
	cout << "set1: ";
	printSet(set1);
	cout << endl;

	// iterator  erase (const_iterator position);
	// This function is different from the previous one,
	// because instead of passing a value, it passes a 
	// position indicated by an iterator.
	// Delete the second element in the set without creating
	// an iterator variable, but do use the prefix increment
	// operator.
	cout << "set1 (ERASE 2nd element): ";
	set<int>::iterator iter = ++set1.begin();
	set1.erase(iter);

	// Print set1.
	printSet(set1);
	cout << endl;

	// pair<iterator,bool> insert (const value_type& val);
	// Use the function insert to insert 4 and 8 in set1.
	cout << "set1 (INSERT 4 & 8): ";
	pair<int, int> pair1 = make_pair(4, 8);
	set1.insert(pair1.first);
	set1.insert(pair1.second);

	// Print set1.
	printSet(set1);
	cout << endl;

	set<int>::iterator first = set1.begin();
	set<int>::iterator second = ++set1.begin();
	// iterator erase(const_iterator first, const_iterator last);
	// Use function erase to delete the first and second element
	// in set1. Use the given iterators created above.
	// Note that you should write one statement only.
	cout << "set1 (ERASE FIRST & SECOND): ";
	set1.erase(first, ++second);

	// Print set1.
	printSet(set1);

	// Your output should be: 5 6 7 8
	// If it is not, you need to carefully view the function erase
	// to understand how it works.

	cout << "\n\n----------------------------------------------------";
	cout << "\n\nThe output for the next sections depends on your implementation.";


	/***************************************************************************
	* MAPS
	***************************************************************************/
	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  STL MAP CLASS  ***  \n\n";

	// Create a few maps using the different constructors shown in the slides.
	// Use the following functions to manipulate the maps:
	// pair<iterator,bool> insert (const value_type& val);
	// void insert (InputIterator first, InputIterator last);
	// iterator erase(const_iterator position);
	// size_type erase(const key_type& k);
	// iterator erase(const_iterator first, const_iterator last);
	// Print each map without creating a print function, but by using
	// a loop.

	map<int, string> map1; // Model & car

	cout << "map1: ";
	pair<int, string> p1;
	p1 = make_pair(5052, "Nissan");
	map1.insert(p1);
	map1[2434] = "Subaru";
	map1[2301] = "Toyota";
	map1[3401] = "Ferrari";
	
	map<int, string>::iterator itFirst = map1.begin();
	map<int, string>::iterator itSecond = map1.begin();
	itSecond++;
	itSecond++;
	map1.erase(itFirst, itSecond);
	map1.erase(3401);

	for (auto i : map1) // Printing
	{
		cout << "(" << i.first << ", " << i.second << ") ";
	}
	cout << endl;
	
	// Copy map1 to map2
	cout << "map2: ";
	map<int, string> map2(map1);
	
	for (auto i : map2) // Printing
	{
		cout << "(" << i.first << ", " << i.second << ") ";
	}
	cout << endl;

	cout << "map3: ";
	map<int, string> map3 // ID & Nickname
	{
		{31, "Jeff"}, 
		{22, "Mar"},
		{35, "Claud"},
		{2, "Dave"}
	};
	map<int, string>::iterator iterMap3 = map3.begin();

	map3.erase(iterMap3++);

	for (auto i : map3) // Printing 
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}

	cout << "\n\n----------------------------------------------------";

	cout << endl;
	system("Pause");
	return 0;
}