#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
	int data; 
	struct node* l; 
	struct node* r; 
}; 
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->l = NULL; 
	node->r = NULL; 
	return(node); 
} 
void ppostorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 
	ppostorder(node->l); 
	ppostorder(node->r); 
	printf("%d ", node->data); 
} 
void pinorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 
	pinorder(node->l); 
	printf("%d ", node->data); 
	pinorder(node->r); 
} 
void ppreorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 
	printf("%d ", node->data); 
	ppreorder(node->l); 
	ppreorder(node->r); 
}	 
int main() 
{ 
     struct node *root  = newNode(10); 
     root->l=newNode(80); 
     root->r=newNode(50); 
     root->l->l=newNode(30); 
     root->l->r=newNode(20);  
     printf("Preorder traversal"); 
     ppreorder(root); 
     printf("inorder traversal"); 
     pinorder(root);   
     printf("Postorder traversal"); 
     ppostorder(root); 
     getchar(); 
     return 0; 
}