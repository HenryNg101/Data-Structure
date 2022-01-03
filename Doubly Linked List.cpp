#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void InsertAtHead(int x, Node *head, Node *tail){
    Node* element = new Node();
    element->data = x;
    element->next = NULL;
    element->prev = NULL;
    if(head == NULL){
        head = element;
        tail = element;
        return;
    }
    head->prev = element;
    element->next = head;
    head = element;
}

void PrintList(Node *head){
    Node* traverse = new Node();
	traverse = head;
    while(traverse->next != NULL){
        cout << traverse->data << " ";
        traverse = traverse->next;
    }
    cout << traverse->data << endl;
}

void PrintListReverseOrder(Node *tail){
	Node *traverse = new Node();
	traverse = tail;
	while(traverse->prev != NULL){
		cout << traverse->data << " ";
		traverse = traverse->prev;
	}
	cout << traverse->data;
}