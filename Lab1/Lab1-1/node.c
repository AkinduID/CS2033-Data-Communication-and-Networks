// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <string.h> // includes strlen(), memcpy()
#include <ctype.h> // includes toupper(), tolower()

// user-defined header files
#include "node.h" // do not modify this file

// put your function prototypes for additional helper functions below:make


// implementation
void insert_node_before(list *lst, int index, char *word)
{	
	// TODO
	node *newNode = (node*)malloc(sizeof(node));
	newNode->word = word;
	if(index==0){
		newNode->next=lst->head;
		lst->head=newNode;

	}
	else{
		node *current=lst->head;
		for(int i=0;i<index;i++){
			current=current->next;
		}
		newNode->next=current->next;
		current->next=newNode;
	}

}

void insert_node_after(list *lst, int index, char *word)
{
	// TODO
	insert_node_before(lst,index+1,word);
}

char *list_to_sentence(list *lst)
{
	// TODO
	node *current = lst->head;
	while(current!=NULL){
		print("%s",current->word);
		current=current->next;
	}
    return NULL; // Change this line accordingly
}

void delete_node(list *lst, int index)
{
	// TODO
	if(index==0){
		node *temp=lst->head;
		lst->head=lst->head->next;
		free(temp->word);
		free(temp);
	}
	else{
		node *prev =NULL;
		node *current=lst->head;
		for(int i=0;i<index;i++){
			prev=current;
			current=current->next;
		}
		prev->next=current->next;
		free(current->word);
		free(current);

	}
}

void delete_list(list *lst)
{
	// TODO
	node *current = lst->head;
	while(current!=NULL){
		node *temp=current;
		current=current->next;
		free(temp->word);
		free(temp);
	}
	lst->head=NULL;
}
