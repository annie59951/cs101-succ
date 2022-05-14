#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node* next;
	int data;
};
typedef struct node node_t;

node_t* allocate_node(int data){
	node_t* p = malloc(sizeof(node_t));
	p->data = data;
	p->next = NULL;
	return p;
}

void show_list(node_t* head){
	while(head){
		printf("[%d]->", head->data);
		head = head->next;
	}
	printf("null\n");
}

node_t* append_node(node_t* head, int new_data){
    node_t* new_node = allocate_node(new_data);
    if(head) {
        node_t* p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = new_node;
    }
    else {
        head = new_node;
    }
    return head;
}

void free_all_node(node_t* head){
    node_t* p = NULL;
	while(head) {
	    p = head;
	    head = head->next;
		printf("free([%d])->", p->data);
		free(p);
	}
	printf("null\n");
}

node_t* add_node(node_t* head, int new_data) {
	node_t* first_node = allocate_node(new_data);
	first_node->data = new_data;
	first_node->next = head;
	head = first_node;
	return head;
}

node_t* del_node(node_t* head, int n) {
	if(head == NULL) {
		return head;
	}
	node_t* p = head;
	if(n == 0) {
		p = p->next;
	}
	else {
		for(int i=0 ; (p != NULL) && (i < n-2) ; i++) {
			p = p->next;
		}
		p->next = p->next->next;
	}
	return p;
}

int main(){
	node_t* head = NULL;
	head = append_node(head, 0);
	show_list(head);
	head = append_node(head, 1);
	show_list(head);
	head = add_node(head, -1);
	show_list(head);
	del_node(head, 1);
	show_list(head);
	free_all_node(head);
	return 0;
}
