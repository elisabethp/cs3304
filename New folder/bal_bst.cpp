#include <iostream>
#include <cstdlib>
#include <list>
#include <stack>
#include "bintree.h"

using namespace std;
using namespace main_savitch_10;

list<int> construct_list();
binary_tree_node<int>* balance_tree(list<int> list);
void bal_tree(binary_tree_node<int>* ptr, binary_tree_node<int>* prev_ptr, int data);
binary_tree_node<int>* root_node = new binary_tree_node<int>;


int main() {
	list<int> tree_list = construct_list();
	binary_tree_node<int>* bin_tree = balance_tree(tree_list);
	
	print(bin_tree, 5);
}

list<int> construct_list() {
	list<int> list;

	list.push_back(12);
	list.push_back(24);
	list.push_back(30);
	list.push_back(50);
	list.push_back(55);
	list.push_back(63);
	list.push_back(77);
	list.push_back(86);
	list.push_back(90);
	list.push_back(100);

	return list;
}

binary_tree_node<int>* balance_tree(list<int> list) {
	root_node = new binary_tree_node<int>(list.front());
	list.pop_front();

	while (!list.empty()) {
		bal_tree(root_node, NULL, list.front());
		list.pop_front();
	}
	
	return root_node;
}

void bal_tree(binary_tree_node<int>* ptr, binary_tree_node<int>* prev_ptr, int data) {
	binary_tree_node<int>* root;
	binary_tree_node<int>* pivot;
	binary_tree_node<int>* temp;
	
	if (ptr->is_leaf()) {
			//no work to be done here
			ptr->set_right(new binary_tree_node<int>(data));
		}
	else {
		//we need to insert at a leaf
		bal_tree(ptr->right(), ptr, data);
		
		//special case #1
		if (tree_size(ptr->left()) ==  0 && tree_size(ptr->right()) ==  2) {
			pivot = ptr->right();
			temp = new binary_tree_node<int>(ptr->data());
			
			if (prev_ptr == NULL) { //root node
				ptr->set_data(pivot->data());
				ptr->set_right(pivot->right());
				delete pivot;
				ptr->set_left(temp);
				root_node = ptr;
			}
			else {
				prev_ptr->set_right(pivot);
				delete ptr;
				pivot->set_left(temp);
			}
		}
		
		//special case #2
		if (tree_size(ptr->left()) ==  1 && tree_size(ptr->right()) ==  4) {
			int temp2 = ptr->data();
			pivot = ptr->right();
			ptr->set_data(pivot->data());
			ptr->set_right(pivot->right());
			ptr->left()->set_left(new binary_tree_node<int>(ptr->left()->data()));
			ptr->left()->set_right(new binary_tree_node<int>(pivot->left()->data()));
			ptr->left()->set_data(temp2);
		}
	}
	
	
}
