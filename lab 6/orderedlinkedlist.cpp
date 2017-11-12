/*
	Write a function that has two linked-list
	head pointers as parameters. Assume that the
	linked list’s items are ordered by the < operator.
	On each list, every item is less than the next item on
	the same list. The function should create a new
	linked list that contains all the items on both lists,
	and the new linked list should also be ordered (so
	that every item is less than the next item on the list).
	The new linked list should also eliminate duplicate
	items (i.e., if the same item appears on both input
	lists, then only one copy is placed in the newly constructed
	linked list). To eliminate duplicate items,
	you may assume that two items can be compared for
	equality using ==. The function should return a head
	pointer for the newly constructed linked list.
*/

#include "node1.h"
#include <iostream>
using namespace main_savitch_5;

void printList(node* head_ptr);
node* combineLists(node* list1_headptr, node* list2_headptr);

int main() {
	
	//create two lists
	node* list1;
	list1 = NULL;

	list_head_insert(list1, 0);
	list_insert(list1, 7);
	list_insert(list1, 5);
	list_insert(list1, 4);
	list_insert(list1, 1);
	
	
	node* list2;
	list2 = NULL;
	
	list_head_insert(list2, 2);
	list_insert(list2, 15);
	list_insert(list2, 11);
	list_insert(list2, 10);
	list_insert(list2, 8);
	list_insert(list2, 5);
	list_insert(list2, 3);
	
	//call combineLists
	node* combined_list = combineLists(list1, list2);
	
	//print new list
	printList(combined_list);	
}


void printList(node* head_ptr) {
	node *cursor;
	cursor = head_ptr; 
	
	while(cursor != NULL) {
		std::cout << cursor->data( ) << " ";
		cursor = cursor->link( );
	}
}

node* combineLists(node* list1_headptr, node* list2_headptr){
	
	//create new list
	node* new_list_headptr; //holds the head of the new list
	new_list_headptr = NULL;
	
	//define cursors
	node* cursor1 = list1_headptr; //cursor for list 1
	node* cursor2 = list2_headptr; //cursor for list 2
	node* new_list_cursor = new_list_headptr; //cursor for new list
	
	node* next_link;
	
	while (cursor2 != NULL || cursor1 != NULL) {
		
		//avoid seg fault by checking potential null cursors
		if (cursor2 == NULL) {
			next_link = cursor1;
			cursor1 = cursor1->link();
		}
		else if (cursor1 == NULL) {
			next_link = cursor2;
			cursor2 = cursor2->link();
		}
		////check the value differences between the cursors
		else if (cursor1->data() < cursor2->data()) {
			next_link = cursor1;
			cursor1 = cursor1->link();
		}
		else {
			next_link = cursor2;
			cursor2 = cursor2->link();
		}
		
		//check to see if the current pointer is null
		if (new_list_cursor == NULL) {
			list_head_insert(new_list_headptr, next_link->data());
			new_list_cursor = new_list_headptr;
		}
		//check to see if the value already exists in the new array	
		else {
			if (list_search(new_list_headptr, next_link->data()) == NULL) {
				list_insert(new_list_cursor, next_link->data());
				new_list_cursor = new_list_cursor->link();
			}		
		}  
	} 
	
	return new_list_headptr;
} 