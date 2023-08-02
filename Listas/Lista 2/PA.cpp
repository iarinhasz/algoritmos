#include<iostream>
#include<string.h>
using namespace std;
typedef struct link{
	char elemento;
	link *next, *prev;
}Link;
Link *a, *b, *cur;
void insert(char ch){
	Link *newnode = (Link*)malloc(sizeof(Link));
	newnode->elemento = ch, newnode->next = newnode->prev = NULL;
	if (cur == NULL){
		a = newnode, b = (Link*)malloc(sizeof(Link));

		b->elemento = '\0';
		
		a->next = cur, cur = b, b->next = NULL, b->prev = a;
		/*cout << newnode->ch << endl;
		cout << b->ch << endl;*/
	}
	else{
		//cout << newnode->ch << endl;
		newnode->next = cur;
		if (cur->prev != NULL){

			newnode->prev = cur->prev;
			cur->prev->next = newnode, cur->prev = newnode;
		}
		else
			/*newnode->next = cur,*/ cur->prev = newnode, a = newnode;
	}
}
void del(Link *cur){
	if (cur->next != NULL)
		del(cur->next);
	free(cur);
}
int main(){
	
    char S[100005];
	while (scanf("%s", S)==1){
		a = b = cur = NULL;
		for (int i = 0; S[i] != '\0'; i++){
			if (S[i] == '[')
				cur = a;
			else if (S[i] == ']')
				cur = b;
			else
				insert(S[i]);
		}
		//cout << endl;
		for (Link *ptr = a; ptr != b; ptr = ptr->next){
			
			putchar(ptr->elemento);
		}
		putchar('\n');
		del(a);
	}
	return 0;
}