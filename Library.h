#pragma once
#include <iostream>

using namespace std;

class Queue;


struct Q_Node {

	string copyDate;
	string borrowDate;
	string borrowr;
	int numberDaysToReturn;
	bool borrow_flag;
	Q_Node* next;
	
};

class Queue {

public:
	Queue();
	Queue(int capacity);
	~Queue();
	void insert(string copyDate, bool borrow_flag, string borrower, string borrowDate, int numberOfDaysToReturn);
	void viewAll();
	void remove(string borrower);
	int Size();

private:
	Q_Node* first;
	Q_Node* last;
	int size;
	int capacity;

};

/*
Queue::Queue() {

	first = last = NULL;
	size = 0;
	capacity = 3;
}*/


Queue::Queue(int capacity) {

	first = last = NULL;
	size = 0;
	this->capacity = capacity;
}

void Queue::insert(string copyDate, bool borrow_flag, string borrower, string borrowDate, int numberOfDaysToReturn = 15) {

	Q_Node* newnode = new Q_Node;
	
	newnode->copyDate = copyDate;
	newnode->borrow_flag = borrow_flag;
	newnode->borrowDate = borrowDate;
	newnode->borrowr = borrower;
	newnode->numberDaysToReturn = numberOfDaysToReturn;
	newnode->next = NULL;

	if (size == capacity) {

		cout << "Sorry No Copy is Available in this time ...! " << endl;
	}

	else if (size == 0) {

		first = last = newnode;
		size++;
	}

	else {

		last->next = newnode;
		last = newnode;
		size++;
	}
}

void Queue::viewAll() {

	Q_Node* tmp;

	tmp = first;
	int i = 0;

	while (i < size) {

		cout << tmp->borrowr << endl;
		tmp = tmp->next;
		i++;
	}


}

void Queue::remove(string borrowr) {

	Q_Node* tmp;
	Q_Node* current;
	Q_Node* trailcurrent;

	if (first->borrowr == borrowr) {

		tmp = first;
		first = first->next;

		delete tmp;
		tmp = NULL;
	}
	else {
		
		trailcurrent = first;
		current = first->next;
		
		while (current != NULL) {

			if (current->borrowr == borrowr) {

				break;
			}

			trailcurrent = current;
			current = current->next;
		}

		if (current == NULL) {

			cout << "Sorry There is no Borrowr have this name ..!" << endl;
		}
		else {

			trailcurrent->next = current->next;
			
			delete current;
			current = NULL;
		}
	}

}

int Queue::Size() {

	return size;
}


struct Node {

	string bookName;
	int bookIsbn;
	int numberOfCopies;
	Node* next;
	Queue* copies;

};

class LinkedList {

public: 
	LinkedList();
	~LinkedList();
	void insert(string bookName, int bookIsbn, int NumberOfCopies);
	void borrowBook(string bookName);
	void returnBook(string bookName, string borrowrName);
	void viewCopies(string bookName);
	bool search(string bookName);
	int copiesSize(string bookName);


private : 
	Node* head;
	Node* tail;
	int size;
};


LinkedList::LinkedList() {

	head = tail = NULL;
	size = 0;
}


LinkedList::~LinkedList() {

	Node* tmp;
	for (int i = 0; i < size; i++) {

		tmp = head;
		head = head->next;

		delete tmp;
		tmp = NULL;
	}

	head = tail = NULL;
}


void LinkedList::insert(string bookName, int bookIsbn, int NumberOfCopies) {

	Node* newnode = new Node;

	newnode->bookName = bookName;
	newnode->bookIsbn = bookIsbn;
	newnode->numberOfCopies = NumberOfCopies;
	newnode->copies = new Queue(NumberOfCopies);
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


bool LinkedList::search(string bookName) {

	if (size == 0) {

		cout << "The Book Is Not Exsist in Libarary" << endl;
		return 0;
	}

	else {

		Node* current;
		current = head;

		while (current != NULL) {

			if (current->bookName == bookName) {

				if (current->copies->Size() < current->numberOfCopies) {

					cout << "The Book Is Exsist in Libarary but there is " << size << " copies available right now ...!" << endl;
					return 1;
				}
				else {

					cout << "The Book Is Exsist in Libarary but there is no copies available right now ...!" << endl;
					return 0;
				}
			}

			current = current->next;
		}
	}		
	
	cout << "The Book Is Not Exsist in Libarary" << endl;
	return 0;
}


void LinkedList::borrowBook(string bookName) {
	
	Node* tmp;
	string copyDate;
	string borrower;
	string borrowDate;
	int numberOfDaysToReturn;
	bool borrow_flag;

	cout << "Enter Copy Date : " << endl;
	cin >> copyDate;
	
	cout << "Enter Borrower Name : " << endl;
	cin >> borrower;
	
	cout << "Enter Borrower Date : " << endl;
	cin >> borrowDate;
	
	cout << "Enter Number Of Days To Return : " << endl;
	cin >> numberOfDaysToReturn;
	cout << endl;
	
	tmp = head;

	while (tmp != NULL) {

		if (tmp->bookName == bookName) {

			tmp->copies->insert(copyDate, true, borrower,borrowDate,numberOfDaysToReturn);
			break;
		}
	}

	if (tmp == NULL) {

		cout << "This Book Doesn't Exsist ...! " << endl;
	}

}

void LinkedList::returnBook(string bookName, string borrowrName) {

	Node* tmp;

	tmp = head;

	while (head != NULL) {

		if (tmp->bookName == bookName) {

			tmp->copies->remove(borrowrName);
			break;
		}
	}
}

void LinkedList::viewCopies(string bookName) {
	
	Node* tmp;

	for (int i = 0; i < size; i++) {
		
		tmp = head;
		if (tmp->bookName == bookName) {

			tmp->copies->viewAll();
			break;
		}

		tmp = tmp->next;
	}

}

int LinkedList::copiesSize(string bookName) {

	Node* tmp;

	tmp = head;

	while (head != NULL) {

		if (head->bookName == bookName) {

			return head->copies->Size();
		}
	}

	cout << "sorry this book doesn't exsist ...! " << endl;
	return -1;
}


class Library {

private: 
	LinkedList books;
	int numberOfBooks;

public: 
	Library();
	void menu();
	void newBook();
	void bookBorrow();
	void bookReturn();
	void showBorrowStatics();
	void libraryInventory();
	void searchAboutBook();

};


Library::Library() {

	numberOfBooks = 0;
}


void Library::menu() {
	
	cout << "1-Add New Book " << endl;
	cout << "2-Book Borrow " << endl;
	cout << "3-Book Return " << endl;
	cout << "4-Borrow Statics " << endl;
	cout << "5-Library Inventory " << endl;
	cout << "6-Search About Book " << endl;
	cout << "7-Exit " << endl;

}


void Library::newBook() {

	string bookName;
	int bookIsbn;
	int numberOfCopies;

	cout << "Enter Book Name : " << endl;
	cin >> bookName;

	cout << "Enter Book ISBN : " << endl;
	cin >> bookIsbn;

	cout << "Enter Number of Copies : " << endl;
	cin >> numberOfCopies;

	books.insert(bookName, bookIsbn, numberOfCopies);
	numberOfBooks++;
}


void Library::bookBorrow() {

	string bookName;

	cout << "Enter Book Name : " << endl;
	cin >> bookName;
	
	books.borrowBook(bookName);
}


void Library::bookReturn() {

	string bookName;
	string borrowName;
	cout << "Enter Book Name : " << endl;
	cin >> bookName;

	cout << "Enter Borrow Name : " << endl;
	cin >> borrowName;

	books.returnBook(bookName,borrowName);

}


void Library::showBorrowStatics() {

	string bookName;

	cout << "Enter Book Name : " << endl;
	cin >> bookName; 

	cout << books.copiesSize(bookName) << endl;
}


void Library::libraryInventory() {

	cout << "total books available : " << numberOfBooks << endl;
}


void Library::searchAboutBook() {
	
	string bookName;
	
	cout << "Enter Book Name : " << endl;
	cin >> bookName;
	
	books.search(bookName);
}