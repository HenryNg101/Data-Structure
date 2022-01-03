#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct btree 
{
    int data;
    //btree *root;
    btree *left_child;
    btree *right_child;
} btree;

//In-order traversal
void inorder_traversal(btree *root){
    btree *traverse = root;
    if (traverse != NULL){
        inorder_traversal(traverse->left_child);
        cout << traverse->data << " ";
        inorder_traversal(traverse->right_child);
    }
}

//Pre-order traversal (DFS)
void preorder_traversal(btree *root){
    btree *traverse = root;
    if (traverse != NULL){
        cout << traverse->data << " ";
        preorder_traversal(traverse->left_child);
        preorder_traversal(traverse->right_child);
    }
}

//Post-order traversal 
void postorder_traversal(btree *root){
    btree *traverse = root;
    if (traverse != NULL){
        postorder_traversal(traverse->left_child);
        postorder_traversal(traverse->right_child);
        cout << traverse->data << " ";
    }
}

//Level-order traversal (BFS)
void LevelorderTraversal(btree *root){
    queue<btree *> travel;
    travel.push(root);

    while(!travel.empty()){
        btree *current = travel.front();
        travel.pop();
        cout << current->data << " ";
        if (current->left_child != NULL)
            travel.push(current->left_child);
        if (current->right_child != NULL)
            travel.push(current->right_child);
    }
}

void assign_node_val(btree *node, int *data){
    node->data = *data;
    *data += 1;
}

btree *CreateTree(btree *root, int max_level, int *start, int level = 0){
    if (root == NULL){
        root = new btree();
        assign_node_val(root, start);
    }
    if (level < max_level){
        btree *left = new btree();
        btree *right = new btree();
        assign_node_val(left, start);
        assign_node_val(right, start);
        root->left_child = left;
        root->right_child = right;
        left = CreateTree(left, max_level, start, level + 1);
        right = CreateTree(right, max_level, start, level + 1);
    }
    return root;
}