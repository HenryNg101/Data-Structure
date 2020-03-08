#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head = new Node();

void InsertAtHead(int data){
	Node* element = new Node();
	element->data = data;
	element->next = head;
	head = element;
}

void InsertAtPosition(int n, int data){
	Node* traverse = new Node();
	traverse = head;
	for(int i=1; i<n; i++){
		traverse = traverse->next;
	}
	Node* NewNode = new Node();
	NewNode->data = data;
	NewNode->next = traverse->next;
	traverse->next = NewNode;
}

void DeleteAtPosition(int k){
	Node* traverse = new Node();
	traverse = head;
	for(int i=1; i<k; i++){
		traverse = traverse->next;
	}
	Node* ToBeDeleted = traverse->next;
	traverse->next = (traverse->next)->next;
	delete(ToBeDeleted);
}

void PrintList(){
	Node* traverse = new Node();
	traverse = head;
	while(traverse->next != NULL){
		cout << traverse->data << " ";
		traverse = traverse->next;
	}
	cout << traverse->data;
}

void PrintListRecursion(Node* temp){
    cout << temp->data << " ";
    if(temp->next != NULL){
        PrintListRecursion(temp->next);
    }
}

void ReverseList(){
    Node* next = new Node();
    Node* prev = new Node();
    Node* current = new Node();
    current = NULL;
    prev = NULL;
    next = head;
    while(next != NULL){
        prev = current;
        current = next;
        next = current->next;
        current->next = prev;
    }
    head = current;
}

int main() {
    head = NULL;
	int k, n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> k;
		InsertAtHead(k);
	}
	PrintListRecursion(head);
	cout << "\n";
	PrintList();
	return 0;
}
