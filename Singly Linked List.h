#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* CreateNode(int x){
    Node *element = new Node();
    //You can use malloc as well: Node *element = (Node *)malloc(sizeof(Node));
    element->next = NULL;
    element->data = x;
    return element;
}

//Traversal
void PrintList(Node *head){
    cout << "Current list is: ";
    Node *traverse = head;
    while (traverse != NULL){
        cout << traverse->data << " ";
        traverse = traverse->next;
    }
    cout << "\n\n";
}

//Insertion
Node* InsertAtTail(Node* tail, int x){
    Node *element = CreateNode(x);
    tail->next = element;
    return element;
}

Node *InsertAtPosition(int n, int pos, Node* head){
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
        return (head);
    }
}

Node *DeleteAtPosition(int k, Node *head){
    Node *traverse = new Node();
    traverse = head;
    for(int i=1; i<k; i++){
        traverse = traverse->next;
    }
    Node *ToBeDeleted = new Node();
    if (k != 0) {
        ToBeDeleted = traverse->next;
        traverse->next = (traverse->next)->next;
    }
    else {
        ToBeDeleted = head;
        head = head->next;
    }
    delete(ToBeDeleted);
    return (head);
}

void SearchValue(int k, Node *head){
    cout << "Looking for number " << k << " in the linked list.\n";
    Node *traverse = new Node();
    int count = 0;
    traverse = head;
    while (traverse != NULL && traverse->data != k){
        traverse = traverse->next;
    }
    if (traverse == NULL){
        cout << "Number not found\n\n";
    }
    else{
        cout << "Number found, first occurence of the number has index " << count << " \n\n";
    }
}

Node *ChangeNodeValue(int pos, int k, Node *head){
    Node *traverse = new Node();
    traverse = head;
    for(int i=1; i<pos; i++){
        traverse = traverse->next;
    }
    traverse->data = k;
    return (head);
}

Node *ReverseList(Node *head){
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
    return (head);
}