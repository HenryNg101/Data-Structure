#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct bst 
{
    int data;
    struct bst *parent;
    struct bst *left_child;
    struct bst *right_child;
} bst;

bst *search_tree(bst *l, int x)
{
    if (l == NULL) {
        return (NULL);
    }
    if (l->data == x) {
        return (l);
    }
    if (l->data > x) {
        return (search_tree(l->left_child, x));
    }
    else {
        return (search_tree(l->right_child, x));
    }
}