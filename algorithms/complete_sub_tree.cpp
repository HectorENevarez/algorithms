#include <bits/stdc++.h>

// local includes
#include "complete_sub_tree.h"

// Max value macro
#define MAX(a,b) (((a)>(b))?(a):(b))

// Node structure of the tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Node return values
typedef struct _node_return_t{
    int is_complete;
    int height;
    int is_perfect;
}node_return_t;

// To create a new node
static struct node* _new_node(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

static node_return_t _complete_subtree(node *root){

    node_return_t ret;

    // check if null
    if (root == NULL){
        ret.is_complete = 1;
        ret.height = 0;
        ret.is_perfect = 1;

        return ret;
    }

    // check recurse through left and right subtrees
    node_return_t left_sub = _complete_subtree(root->left);
    node_return_t right_sub = _complete_subtree(root->right);

    // both subtrees must be complete if we made it this far
    // There are only 2 cases for a tree to be complete
    // if both subtrees are same height, left subtree must be perfect
    if (left_sub.height == right_sub.height && left_sub.is_perfect && right_sub.is_complete){
        ret.is_complete = 1;
        ret.height = left_sub.height + 1; // increment our height up the tree
        ret.is_perfect = right_sub.is_perfect;

        return ret;
    }

    // if the left subtree is taller by 1, the right subtree must be perfect
    if (left_sub.height == (right_sub.height + 1) && right_sub.is_perfect && left_sub.is_complete){
        ret.is_complete = 1;
        ret.height = left_sub.height + 1;
        ret.is_perfect = 0;

        return ret;
    }

    // not a complete subtree if we reached this far
    ret.is_complete = 0;
    ret.height = MAX(left_sub.height, right_sub.height);
    ret.is_perfect = 0;

    return ret;

}

// initializes subtree and starts to find complete subtree
int complete_subtree_init(){

    // Create the tree
    struct node* root = _new_node(50);
    root->left = _new_node(30);
    root->right = _new_node(60);
    root->left->right = _new_node(5);
    root->left->left = _new_node(20);
    root->right->left = _new_node(45);

    node_return_t results = _complete_subtree(root);

    // print out results
    printf("is complete: %d\n", results.is_complete);
    printf("subtree height: %d\n", results.height);
    printf("is perfect: %d\n", results.is_perfect); // not required but good to print out

    return 0;
}