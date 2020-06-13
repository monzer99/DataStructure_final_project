#pragma once
#include <iostream>

using namespace std;

template <class Type>
struct Node {

	Type data;
	Node* next;
	
};

template <class Type>
class LinkedList{

public:
	LinkedList();
	~LinkedList();
	Node<Type>* gethead();
	void insert(Type n);
	void insertPos(int data, int position);
	void deleteVal(Type value);
	void deletePos(int position);
	static void concatinate(Node<Type>* a, Node<Type>* b);
	static void print(Node<Type>* head);
	
private:
	Node<Type>* head;
	Node<Type>* tail;
	int size;

};

template <class Type>
LinkedList<Type>::LinkedList() {

	head = new Node<Type>;
	tail = new Node<Type>;

	head = tail = NULL;
	size = 0;
}

template <class Type>
LinkedList<Type>::~LinkedList() {

	Node<Type>* tmp;

	while (head != NULL) {

		tmp = head;
		head = head->next;

		delete tmp;
		tmp = NULL;
	}

	head = NULL;
	tail = NULL;

}

template <class Type>
Node<Type>* LinkedList<Type>::gethead() {

	return head;
}

template <class Type>
void LinkedList<Type>::insert(Type n) {

	Node<Type>* newnode = new Node<Type>;

	newnode->data = n;
	newnode->next = NULL;

	if (size == 0) {

		head = tail = newnode;
	}
	else {

		tail->next = newnode;
		tail = newnode;
	}

	size++;
}

template <class Type>
void LinkedList<Type>::insertPos(int data, int pos) {

	Node<Type>* newnode = new Node<Type>;
	Node<Type>* trailcurrent;
	Node<Type>* current;

	newnode->data = data;

	if (pos > size || pos < 0) {

		cout << "Error Position ...!" << endl;
		return;
	}
	else {
		
		if (pos == 0) {

			newnode->next = head;
			head = newnode;
		}
		else if (pos == size) {

			tail->next = newnode;
			tail = newnode;
		}
		else {
			trailcurrent = head;
			current = head->next;
			int i = 1;
			
			while (current != NULL && i != pos) {

				trailcurrent = current;
				current = current->next;
				i++;
			}
			
			newnode->next = current;
			trailcurrent->next = newnode;
			size++;
		}
	}
}
template <class Type>
void LinkedList<Type>::deleteVal(Type value) {

	Node<Type>* trailcurrent;
	Node<Type>* current;
	Node<Type>* tmp;

	if (value == head->data) {

		tmp = head;
		head = head->next;

		delete tmp;
		tmp = NULL;
	}
	else {

		trailcurrent = head;
		current = head->next;

		while (current != NULL && current->data != value) {

			trailcurrent = current;
			current = current->next;
		}

		trailcurrent->next = current->next;
		
		delete current;
		current = NULL;
	}
}

template <class Type>
void LinkedList<Type>::deletePos(int pos) {

	Node<Type>* trailcurrent;
	Node<Type>* current;
	Node<Type>* tmp;

	if (pos == 0) {

		tmp = head;
		head = head->next;

		delete tmp;
		tmp = NULL;
	}
	else {

		trailcurrent = head;
		current = head->next;
		int i = 1;
		
		while (current != NULL && i != pos) {

			trailcurrent = current;
			current = current->next;
			i++;
		}

		trailcurrent->next = current->next;

		delete current;
		current = NULL;
	}
}

template <class Type>
void LinkedList<Type>::concatinate(Node<Type>* a, Node<Type>* b) {
	
	Node<Type>* tmp_a = a;

	while (tmp_a->next != NULL) {
		
		tmp_a = tmp_a->next;
	}
		
	tmp_a->next = b;

}

template <class Type>
void LinkedList<Type>::print(Node<Type>* head) {

	while (head != NULL) {

		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}


void sort1(int array[], int size) {

	int j = size-1;

	for (int i = 0; i < (size / 2) +1; i++, j--) {
	

		if (array[i] != 0 and i < j) {

			swap(array[i], array[j]);
		}

		if (array[j] != 1 and j > i) {

			swap(array[i], array[j]);
		}

		if (j == i) {
			swap(array[i], array[j + 1]);
		}
	
	}
	
}

void sort2(int array[], int size) {

	for (int i = 0; i < (size/2); i++) {

		if (array [i] > array[size - i - 1]) {

			swap(array[i], array[size - i - 1]);
		}
	}

	if (size % 2 != 0) {

		swap(array[(size / 2)], array[(size / 2) + 1]);
	}

}



void sort3(int array[], int size) {

	int j;
	j = (size / 2) -1;

	for (int i = 0; i < (size / 2) +1 ; i++)
	{
		if (array[i] > array[j]) {

			swap(array[i], array[j]);
		}
		else if (array[i] == array[j]) {

			swap(array[i], array[j + 1]);
			j++;
		}

		j++;
	}
}