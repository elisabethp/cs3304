//http://www.cplusplus.com/reference/cctype/isdigit/
//http://www.cplusplus.com/forum/general/13135/
#include <stack>
#include <list>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iostream>

using namespace std;

list<string> get_expression();
int evaluate_expression(list<string> expression);
void print_result(int result);

int main() {
	list<string> expression = get_expression(); //generate expression
	double result = evaluate_expression(expression); //evaluate expression
	print_result(result); //print results
}

list<string> get_expression() {
	list<string> expression;
	expression.push_back("2");
	expression.push_back("3");
	expression.push_back("7");
	expression.push_back("4");
	expression.push_back("+");
	expression.push_back("*");
	expression.push_back("-");	
	
	return expression;
}

int evaluate_expression(list<string> expression) {
	stack<int> storage;
	list<string>::iterator iterator = expression.begin();
	int result; 
	
	while (iterator != expression.end()) {
		
		int operand1;
		int operand2;
		string op =  *iterator;
		
		if (isdigit(op.at(0))) { //check if the current item is a digit
			storage.push(atoi(op.c_str())); //converts string to int and pushes on stack
		}
		else {
			operand1 = storage.top();
			storage.pop();
			operand2 = storage.top();
			storage.pop();
			
			switch(op.at(0)) { //check which operator
				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;
					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					result = operand1 / operand2;
					break;
			}
			
			storage.push(result);
		}
		
		iterator++;
	}
	
	return storage.top();
}

void print_result(int result) {
	cout << result << endl;
}