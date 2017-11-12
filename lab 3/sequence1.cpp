#include "sequence1.h"
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;
using namespace main_savitch_3;

// CONSTRUCTOR
sequence::sequence( ) {
	used = 0;
	current_index = 31;
}

// MODIFICATION MEMBER FUNCTIONS
void sequence::start( ) {
	if (used == 0) {
		current_index = 31;
		return;
	}
	current_index = 0;
}

void sequence::advance( ) {
	if (!is_item()) { //precondition
		return;
	}
	
	if (used <= (current_index + 1)) { //is the last item?
		current_index = 31;
		return;
	}
	
	current_index = current_index + 1;			
}

void sequence::insert(const value_type& entry) {
	assert(size() < CAPACITY);
	
	if (used == 0) { //empty data?
		data[0] = entry;
		
		current_index = 0;
		used++;
		return;
	}
	
	if (current_index == 31) { //no current index?
		value_type new_data[CAPACITY];
	
		new_data[0] = entry;
		
		for (int i = 1; i < used+1; i++) {
			new_data[i] = data[i-1];
		}
		
		for (int i = 0; i < used+1; i++) {
			data[i] = new_data[i];
		}
		
		current_index = 0;
		used++;
		return;
	}
		
	value_type new_data[CAPACITY]; //normal case
	
	for (int i = 0; i < current_index; i++) { //put all elements up to current_index
		new_data[i] = data[i];
	}
	
	new_data[current_index] = entry; //put entry at current_index
	
	for (int i = current_index; i < used+1; i++) { //add the rest of data
		new_data[i+1] = data[i];
	}
	
	for (int i = 0; i < used+1; i++) {
		data[i] = new_data[i];
	}
	used++;
}

void sequence::attach(const value_type& entry) {
	assert(size() < CAPACITY);
	
	if (used == 0) { //empty data?
		data[0] = entry;

		current_index = 0;
		used++;
		return;
	}
	
	if (current_index == 31 || (current_index == (used-1))) { //no current index?
		data[used] = entry;
		current_index = used;

		used++;	
		return;
	}
		
	value_type new_data[CAPACITY];
	
	for (int i = 0; i <= current_index; i++) {
		new_data[i] = data[i];
	}

	current_index++;
	new_data[current_index] = entry;

	for (int i = current_index; i < used+1; i++) {
		new_data[i+1] = data[i]; 
	}
		
	for (int i = 0; i < used+1; i++) {
		data[i] = new_data[i];
	}
	
	used++;	
}

void sequence::remove_current( ) {
	if (!is_item()) { //precondition
		return;
	}
	
	value_type new_data[CAPACITY];
	
	for (int i = 0; i < current_index; i++) { //put all elements up to current_index
		new_data[i] = data[i];
	}
	
	for (int i = current_index; i < used+1; i++) {
		new_data[i] = data[i+1];
	}
	
	for (int i = 0; i < 30; i++) {
		data[i] = new_data[i];
	}
	
	used--;
	
	if (used == current_index) {
		current_index = 31;
	}
}

// CONSTANT MEMBER FUNCTIONS
sequence::size_type sequence::size( ) const {
	return used;
}

bool sequence::is_item( ) const {
	if (current_index == 31) {
		return false;
	}
	return true;
}

sequence::value_type sequence::current( ) const {
	assert(is_item());
	return data[current_index];	
}

