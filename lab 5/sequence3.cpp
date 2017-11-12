#include "sequence3.h"
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;
using namespace main_savitch_5;

// CONSTRUCTOR
sequence::sequence() {
	head_ptr = NULL;
	cursor = NULL;
	precursor = NULL;
	many_nodes = 0;
}

sequence::sequence(const sequence& source) {

	list_copy(source.head_ptr, head_ptr, tail_ptr);
	
	cursor = source.cursor;
	precursor = source.precursor;
	tail_ptr = NULL;
	many_nodes = source.many_nodes;
}

sequence::~sequence( ) {
	list_clear(head_ptr);
}

// MODIFICATION MEMBER FUNCTIONS
void sequence::start( ) {
	if (many_nodes == 0) {
		cursor == NULL;
	}
    else {
		precursor = head_ptr;
        cursor = head_ptr;
    }
}

void sequence::advance( ) {
	assert(is_item()); //precondition
	
	if (cursor->link() == NULL) { //is the last item?
		precursor = cursor;
		cursor = NULL;
	}
	else if (cursor == NULL) {
		precursor = NULL;
	}
    else {
		precursor = cursor;
        cursor = cursor->link();	
    }	

	
}

void sequence::insert(const value_type& entry) { //check
	
	if (many_nodes == 0 || cursor == head_ptr) { //empty data?
		list_head_insert(head_ptr, entry);
		cursor = head_ptr;
		precursor = head_ptr;
		many_nodes++;
	}	
	else if (cursor == NULL) { //no current index?
		
		head_ptr = new node(entry, head_ptr);
		
		precursor = NULL;
		cursor = head_ptr;

		many_nodes++;	
	}
    else {
        //normal case
		
		node* temp;
		temp = cursor;
		
		std::cout << precursor->data();
		list_insert(precursor, entry);
		cursor = precursor->link();
		cursor->set_link(temp);

        many_nodes++;
    }
}

void sequence::attach(const value_type& entry) { //check
	
	if (many_nodes == 0) { //empty data?
		list_head_insert(head_ptr, entry);
		cursor = head_ptr;
		precursor = head_ptr;
		many_nodes++;
	}
	else if (cursor == NULL) { //no current index?
		list_insert(list_locate(head_ptr, many_nodes), entry);	
		many_nodes++;
		precursor = list_locate(head_ptr, many_nodes-1);
		cursor = list_locate(head_ptr, many_nodes);
	}
    else {
        //normal case
		
		node* temp = cursor->link();
		
		list_insert(cursor, entry);
		cursor->link()->set_link(temp);
		precursor = cursor;
		cursor = cursor->link();
		
        many_nodes++;	
		std::cout<< many_nodes;
    }
}

void sequence::remove_current( ) {
	assert (is_item()); //precondition
	
	if (cursor == head_ptr) { //case for when there is one item or need to remove head
		cursor = cursor->link();
		list_head_remove(head_ptr);
	}
	else { //all other normal cases
		list_remove(precursor);
		cursor = precursor->link();
	}
		
	many_nodes--;
	
}

void sequence::operator =(const sequence& source) {
	list_clear(head_ptr);
	
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	
	cursor = source.cursor;
	precursor = source.precursor;
	tail_ptr = source.tail_ptr;
	many_nodes = source.many_nodes;
}

// CONSTANT MEMBER FUNCTIONS
sequence::value_type sequence::current( ) const {
	assert(is_item());
	return cursor->data();	
}

//https://www.programiz.com/cpp-programming/pointers