#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = new Node();
Node* tail = new Node();

void InsertNodeAtHead(int x){
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

void PrintList(){
    Node* traverse = head;
    while(traverse->next != NULL){
        cout << traverse->data << " ";
        traverse = traverse->next;
    }
    cout << traverse->data << endl;
}

void PrintListReverseOrder(){
	Node* traverse = tail;
	while(traverse->prev != NULL){
		cout << traverse->data << " ";
		traverse = traverse->prev;
	}
	cout << traverse->data;
}

int main()
{
    head = NULL;
    tail = NULL;
    int k, n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k;
        InsertNodeAtHead(k);
    }
    PrintList();
    PrintListReverseOrder();
    return 0;
}
