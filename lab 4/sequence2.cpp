#include "sequence2.h"
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;
using namespace main_savitch_4;

// CONSTRUCTOR
sequence::sequence(size_t initial_capacity) {
	data = new value_type[initial_capacity];
	capacity = initial_capacity;
	used = 0;
	current_index = capacity + 1;
}

sequence::sequence(const sequence& source) {
	data = new value_type[source.capacity];
	used = source.used;
	capacity = source.capacity;
	current_index = source.current_index;
    
	for (int i = 0; i < used+1; i++) {
		data[i] = source.data[i];
	}

}

sequence::~sequence( ) {
	delete [] data;
}

// MODIFICATION MEMBER FUNCTIONS
void sequence::start( ) {
	if (used == 0) {
		current_index = capacity + 1;
	}
    else {
        current_index = 0;
    }
}

void sequence::advance( ) {
	assert(is_item()); //precondition
	
	if (used <= (current_index + 1)) { //is the last item?
		current_index = capacity + 1;
	}
    else {
        current_index = current_index + 1;   
    }			
}

void sequence::resize(size_type new_capacity) {
	if (new_capacity < capacity) {
		return;
	}		
	
	value_type *new_data;
	
	new_data = new value_type[new_capacity];
	
	for (int i = 0; i < used+1; i++) {
		new_data[i] = data[i];
	}
	
	capacity = new_capacity;
	delete [] data;
	data = new_data;
}

void sequence::insert(const value_type& entry) { 
	if (size() + 1 > capacity) {
		resize(capacity + 10); //add ten empty spots to the array
	}
	
	if (used == 0) { //empty data?
		data[0] = entry;
		
		current_index = 0;
		used++;
	}	
	else if (current_index == (capacity + 1)) { //no current index?
		value_type new_data[capacity];
	
		new_data[0] = entry;
		
		for (int i = 1; i < used+1; i++) {
			new_data[i] = data[i-1];
		}
		
		for (int i = 0; i < used+1; i++) {
			data[i] = new_data[i];
		}
		
		current_index = 0;
		used++;
	}
    else {
        value_type new_data[capacity]; //normal case

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
}

void sequence::attach(const value_type& entry) {
	if (size() + 1 > capacity) {
		resize(capacity + 10); //add ten empty spots to the array
	}
	
	if (used == 0) { //empty data?
		data[0] = entry;

		current_index = 0;
		used++;
	}
	else if (current_index == (capacity + 1)) { //no current index?
		data[used] = entry;
		current_index = used;

		used++;	
	}
    else {
        //normal case
        value_type new_data[capacity];

        for (int i = 0; i <= current_index; i++) {
            new_data[i] = data[i];
        }

        current_index++;
        new_data[current_index] = entry;

        for (int i = current_index; i < used+1; i++) {
            new_data[i+1] = data[i]; 
        }

        for (int i = 0; i < used+1; i++) {
            data[i] = new_data[i] ;
        }

        used++;	
    }
}

void sequence::remove_current( ) {
	assert (is_item()); //precondition
	
	value_type new_data[capacity];
	
	for (int i = 0; i < current_index; i++) { //put all elements up to current_index
		new_data[i] = data[i];
	}
	
	for (int i = current_index; i < used+1; i++) {
		new_data[i] = data[i+1];
	}
	
	for (int i = 0; i < used+1; i++) {
		data[i] = new_data[i];
	}
	
	used--;
	
	if (used == current_index) {
		current_index = capacity + 1;
	}
}

void sequence::operator =(const sequence& source) {
	
	value_type *new_array;
	
    new_array = new value_type[source.capacity];
    
    for (int i = 0; i <= source.used+1; i++) {
		new_array[i] = source.data[i];
	}
    
	delete [] data;
	data = new_array;
    
	
	used = source.used;
	capacity = source.capacity;
    current_index = source.current_index;
}

// CONSTANT MEMBER FUNCTIONS
sequence::size_type sequence::size( ) const {
	return used;
}

bool sequence::is_item( ) const {
	if (current_index == (capacity + 1)) {
		return false;
	}
	return true;
}

sequence::value_type sequence::current( ) const {
	assert(is_item());
	return data[current_index];	
}

//https://www.programiz.com/cpp-programming/pointers