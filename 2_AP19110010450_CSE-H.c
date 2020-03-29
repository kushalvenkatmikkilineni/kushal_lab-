#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
    int key; 
    struct node *l,*r; 
}; 
struct node *newNode(int item) 
{ 
    struct node *temp=(struct node *)malloc(sizeof(struct node)); 
    temp->key=item; 
    temp->l=temp->r=NULL; 
    return temp; 
} 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->l); 
        printf("%d \n", root->key); 
        inorder(root->r); 
    } 
} 
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
        node->l=insert(node->l, key); 
    else if (key > node->key) 
        node->r=insert(node->r, key);    
    return node; 
} 
int main() 
{ 
    struct node *root = NULL; 
    root = insert(root, 12); 
    insert(root, 90); 
    insert(root, 65); 
    insert(root, 24);
    inorder(root); 
    return 0; 
} 