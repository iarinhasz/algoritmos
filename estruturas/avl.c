#include<stdio.h>
#include<stdlib.h>
typedef struct bstnode{
    int element;
    int height;
    struct bstnode *left;
    struct bstnode *right;
}BSTNode;

BSTNode *create_bstnode(int e){
    BSTNode *node = (BSTNode*) malloc(sizeof(BSTNode));
    node->element = e;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int h(BSTNode *rt){
	if(rt == NULL) return 0;
	return rt->height;
}
int getBalance(BSTNode *rt){
	if(rt == NULL) return 0;
	return (h(rt->left) - h(rt->right));
}

int max(int a, int b){
	return (a > b) ? a : b;
}

BSTNode *rightRotate(BSTNode *rt){
	BSTNode *l = rt->left;
	BSTNode *lr = l->right;
	l->right = rt;
	rt->left = lr;
	rt->height = max(h(rt->left), h(rt->right)) + 1;
	l->height = max(h(l->left), h(l->right)) + 1;
	return l;
}
BSTNode *leftRotate(BSTNode *rt){
	BSTNode *r = rt->right;
	BSTNode *rl = r->left;
	r->left = rt;
	rt->right = rl;
	rt->height = max(h(rt->left), h(rt->right)) + 1;
	r->height = max(h(r->left), h(r->right)) + 1;
	return r;
}

BSTNode *inserthelp(BSTNode *rt, int e){
	if(rt == NULL) return create_bstnode(e);

	if(rt->element>e) rt->left = inserthelp(rt->left, e);
	else if(rt->element<e) rt->right = inserthelp(rt->right, e);
	else return rt;

	rt->height = 1 + max(h(rt->left), h(rt->right));

	int balance = getBalance(rt);

	if(balance < -1 && e>= rt->right->element) return leftRotate(rt);

	else if(balance > 1 && e<rt->left->element) return rightRotate(rt);

	else if(balance > 1 && e >= rt->left->element){
		rt->left = leftRotate(rt->left);
		return rightRotate(rt);
	}
	else if(balance<-1 && e < rt->right->element){
		rt->right = rightRotate(rt->right);
		return leftRotate(rt);
	}
	return rt;
}

void preorder(BSTNode *rt){
	if(rt!=NULL){
		printf("%d ", rt->element);
		preorder(rt->left);
		preorder(rt->right);
	}
}
void inorder(BSTNode *rt){
	if(rt!=NULL){
		inorder(rt->left);		
		printf("%d ", rt->element);
		inorder(rt->right);
	}
}
void posorder(BSTNode *rt){
	if(rt!=NULL){
		posorder(rt->left);		
		posorder(rt->right);		
		printf("%d ", rt->element);
	}
}
int main(){

	BSTNode *bst = NULL;
	int entrada, valor;
	scanf("%d", &entrada);
	for(int i = 0; i<entrada; i++){
		scanf("%d", &valor);
		bst = inserthelp(bst, valor);
	}
	
	printf("Pre order : ");
	preorder(bst);
	printf("\n");

	printf("In order  : ");
	inorder(bst);
	printf("\n");

	printf("Post order: ");
	posorder(bst);
	printf("\n");

	free(bst);
	
	return 0;
}



