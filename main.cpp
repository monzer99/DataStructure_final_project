#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{

	int arr[] = {1,0,1,0,1,0,0,1,0};
	sort1(arr, 9);
	
	cout << "sort 1 : " << endl;
	for (int i = 0; i < 9; i++) {

		cout << arr[i] << " ";
	}
	cout << endl;

	int arr2[] = {1,0,1,0,1,0,0,1,0};
	sort2(arr2, 9);
	
	cout << "sort 2 : " << endl;
	for (int i = 0; i < 9; i++) {

		cout << arr2[i] << " ";
	}
	cout << endl;

	int arr3[] = {1,0,1,0,1,0,0,1,0};
	sort3(arr3, 9);
	
	cout << "sort 3 : " << endl;
	for (int i = 0; i < 9; i++) {

		cout << arr3[i] << " ";
	}
	cout << endl;









	/*
	LinkedList<int> l;
	LinkedList<int> l2;
	l.insert(0); //insert in linked list 
	l.insert(2); //insert in linked list
	l.insert(3); //insert in linked list 
	l.insertPos(1, 1);// insert in linked list at certain position
	l.deleteVal(2); // delete from linked list 
	l.deletePos(0); // delete from linked list at certain position

	l2.insert(4);
	l2.insert(5);
	l2.insert(6);
	l2.insert(7);

	cout << "Lniked list 1 : " << endl;
	LinkedList<int>::print(l.gethead()); //print linked list 
	cout << endl;
	
	cout << "Lniked list 2 : " << endl;
	LinkedList<int>::print(l2.gethead()); //print linked list 
	cout << endl;
	
	LinkedList<int>::concatinate(l.gethead(), l2.gethead());//concatinate linked list 

	cout << "Linked list after concatinate : " << endl;
	LinkedList<int>::print(l.gethead()); //print linked list 
	cout << endl;
	*/

	return 0;
}