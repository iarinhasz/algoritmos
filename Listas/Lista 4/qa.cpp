#include <stdio.h>
#include <stdlib.h>

struct node 
{ 
    int key; 
    struct node *left, *right; 
    int leftsize;
}; 

struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    temp->leftsize=1;
    return temp; 
} 

int ind=0; 
int flag=0;  
int count=0;
int size(struct node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
        return(size(node->left) + 1 + size(node->right));  
}  

struct node* insert(struct node* node, int value) 
{ 

    if (node == NULL) {
        struct node* x = newNode(value);
        x->leftsize=size(x); 
        return x; 
    }

    else if (value < node->key) {
        node->left  = insert(node->left, value); 
        node->leftsize++;
    }
    else if (value > node->key) {
        node->right = insert(node->right, value); 
      //  node->right->leftsize=node->leftsize+1;   
    }

    return node; 
} 

void search(struct node* node,int value){
    if (node == NULL) {
        return; 
    }
    else if(value==node->key){
        printf("%d\n",count-(ind+node->leftsize)+1);
         flag=-1;
         return;
    }

    else if (value < node->key) 
       search(node->left, value); 
    else if (value > node->key) {
       ind+=node->leftsize;
        search(node->right, value);    
    }

    return; 
}

/*void printPostOrderTraversal(Node* root) {
	if (root != NULL) {
		printPostOrderTraversal(root->left);
		printPostOrderTraversal(root->right);
		printf("%d ", root->val);
	}
}*/

int main() {
	node* root = NULL;
	
	long long int op,i,test,it=0,value;
    bool status=false;
    scanf("%lld",&test);
    while(it<test){
    scanf("%lld %lld",&op,&value);
        if(op==1)root = insert(root,value);
        else if (op==2){
           ind=0;
            flag=0;
            search(root,value); 
            if(flag==0){
                printf("Data tidak ada\n");
            }
            it++;
        }
	}
	return 0;
}