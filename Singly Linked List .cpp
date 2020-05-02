#include<iostream>

using namespace std;

struct Node{
	int data;
	Node *next;
};

Node* CreateNode(int x){
    Node *element = new Node();
    element->next = NULL;
    element->data = x;
    return element;
}

void PrintList(Node *element){
	Node *traverse = element;
	while (traverse != NULL){
		cout << traverse->data << " ";
		traverse = traverse->next;
	}
}

Node* InsertElementAtTail(Node* tail, int x){
	Node *element = CreateNode(x);
	tail->next = element;
	return element;
}

Node* InsertElementInPosition(int n, int pos, Node* head){
    Node* element = new Node();
    if(pos == 0){
        element->data = n;
        element->next = head;
        head = element;
        return head;
    }
    else{
        Node* traverse = head;
        for(int i=1; i<pos; i++){
            traverse = traverse->next;
        }
        element->data = n;
        element->next = traverse->next;
        traverse->next = element;
        return head;
    }
}

int main(){
	int n, x, k, l;
	cin >> n;
	cin >> x;
	Node *head = CreateNode(x);
	Node *tail = head;
	for (int i = 1; i < n; i++){
		cin >> x;
		tail = InsertElementAtTail(tail, x);
	}
    cin >> k >> l;
    head = InsertElementInPosition(l,k,head);
	PrintList(head);
	return 0;
}
