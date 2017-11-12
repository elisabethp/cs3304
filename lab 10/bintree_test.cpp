/* 
	Write a function that takes a binary search tree as input and 
	produces a linked list of the entries, with the entries sorted 
	(smallest entries at the front of the list and largest entries at the back). 
	Hint: use in-order traversal. 
*/

#include <iostream>
#include "bintree.h"

using namespace main_savitch_10;

binary_tree_node<int>* construct_tree();
void add_tree(int data);
void print_list(int data);
int sum = 0;


int main() {
	
	binary_tree_node<int>* bin_tree = construct_tree();
	breadthfirst(add_tree, bin_tree);
	std::cout << sum << std::endl;
	breadthfirst(print_list, bin_tree);
}

void add_tree(int data) { 	
	sum += data;
}
binary_tree_node<int>* construct_tree() {
	binary_tree_node<int>* third_node = new binary_tree_node<int>(1);
	binary_tree_node<int>* first_node = new binary_tree_node<int>(7);
	binary_tree_node<int>* second_node = new binary_tree_node<int>(6, third_node, first_node);
	
	binary_tree_node<int>* fifth_node = new binary_tree_node<int>(85);
	binary_tree_node<int>* sixth_node = new binary_tree_node<int>(79);
	binary_tree_node<int>* seventh_node = new binary_tree_node<int>(80, sixth_node, fifth_node);
	binary_tree_node<int>* fourth_node = new binary_tree_node<int>(77, NULL, seventh_node);

	binary_tree_node<int>* root_node = new binary_tree_node<int>(22, second_node, fourth_node);
	
	return root_node;
}

void print(int data) {
	std::cout << data << " ";
}

void print_bst() {
	std::queue<BTNode*> tree;
	tree.push(node_ptr);
	
	while (!tree.empty()) {
		if (tree.front()->left() != NULL) {
			tree.push(tree.front()->left());
		}
		if (tree.front()->right() != NULL) {
			tree.push(tree.front()->right());
		}
		f(tree.front()->data());
		tree.pop();
	}
}