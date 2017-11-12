/* 
	Write a function that takes a binary search tree as input and 
	produces a linked list of the entries, with the entries sorted 
	(smallest entries at the front of the list and largest entries at the back). 
	Hint: use in-order traversal. 
*/

#include <iostream>
#include <list>
#include "bintree.h"

using namespace std;
using namespace main_savitch_10;

binary_tree_node<double>* construct_tree();
list<double> flatten_list(binary_tree_node<double>* tree);
void flatten(double data);
void print_list(list<double> flat_tree);
list<double> ans;


int main() {
	
	binary_tree_node<double>* bin_tree = construct_tree();
	list<double> flat_tree = flatten_list(bin_tree);
	print_list(flat_tree);
}

binary_tree_node<double>* construct_tree() {
	binary_tree_node<double>* third_node = new binary_tree_node<double>(1);
	binary_tree_node<double>* first_node = new binary_tree_node<double>(7);
	binary_tree_node<double>* second_node = new binary_tree_node<double>(6, third_node, first_node);
	
	binary_tree_node<double>* fifth_node = new binary_tree_node<double>(85);
	binary_tree_node<double>* sixth_node = new binary_tree_node<double>(79);
	binary_tree_node<double>* seventh_node = new binary_tree_node<double>(80, sixth_node, fifth_node);
	binary_tree_node<double>* fourth_node = new binary_tree_node<double>(77, NULL, seventh_node);

	binary_tree_node<double>* root_node = new binary_tree_node<double>(22, second_node, fourth_node);
	
	return root_node;
}

list<double> flatten_list(binary_tree_node<double>* tree) {
	inorder(flatten, tree);
	return ans;
}

void flatten(double data) {	
	ans.push_back(data);
}

void print_list(list<double> flat_tree) {
	
	for (std::list<double>::iterator it=flat_tree.begin(); it != flat_tree.end(); ++it) {
		cout << *it << " "; 
	}
	
}