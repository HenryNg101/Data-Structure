#include <iostream>
#include "Singly Linked List.h"

using namespace std;

void SinglyLinkedListTest(){
	int n, x;

	//Test linked list creation
	cout << "Test Linked List\n\nEnter the number of elements: ";
	cin >> n;
	cout << "Enter all elements, seperated by space: ";
	cin >> x;
	Node *head = CreateNode(x);
	Node *tail = head;
	for (int i = 1; i < n; i++){
		cin >> x;
		tail = InsertAtTail(tail, x);
	}
	PrintList(head);

	//Test insertion
	cout << "Enter the position to insert new element (Start from 0): ";
    cin >> n;
	cout << "Enter the value to insert: ";
	cin >> x;
    head = InsertAtPosition(x,n,head);
    PrintList(head);

	//Test deletion
	cout << "Enter the position to delete element (Start from 0): ";
    cin >> n;
    head = DeleteAtPosition(n,head);
    PrintList(head);

	//Test search
	cout << "Enter number to search in linked list: ";
	cin >> n;
	SearchValue(n, head);

	//Test update value
	cout << "Enter the position to change value: ";
	cin >> n;
	cout << "Enter the value to change: ";
	cin >> x;
	head = ChangeNodeValue(n, x, head);
	PrintList(head);

	//Test reverse list
	cout << "Reversing list...\n";
	head = ReverseList(head);
	PrintList(head);
}

/*
void DoublyLinkedListTest(){
}

void BinarySearchTreeTest(){
}*/

int main(){
	SinglyLinkedListTest();
	//DoublyLinkedListTest();
	//BinarySearchTreeTest();
	return 0;
}
