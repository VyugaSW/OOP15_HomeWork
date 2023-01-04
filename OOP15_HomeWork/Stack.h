#pragma once

#include <iostream>

#define FULL_DEF 25 // default size of stack


class Stack {
	int empty = -1, full = FULL_DEF; // stack boundary
	int top; // upper relevant bound
	char* arr; // stack matrix 
public:
	Stack();
	void push(char c) ;  // add element to stack
	char pop(); // delete element from stack
	void clear(); // clear all stack
	bool isEmpty(); // is the stack empty
	bool isFull(); // is the stack full
	int getCount(); // get count elements of stack
	void show(); // show stack (for comfort)

	int& cloning(Stack const& cSt); // clone stack

	int& operator+(Stack const& anSt); // addition stacks

	int& operator*(Stack const& anSt); // multiplication stacks (finding general elements)





};

Stack::Stack() { 
	arr = new char[full + 1];
	top = empty; 
}

void Stack::push(char c) {
	if (isFull())
		full++;
	arr[++top] = c;
}

char Stack::pop() {
	if (!isEmpty()) {
		return arr[top - 1];
		if (full > FULL_DEF)
			full--;
	}
	else
		return 0;
}

void Stack::clear() {
	top = empty;
	full = FULL_DEF;
}

bool Stack::isEmpty() {
	return top == empty;
}

bool Stack::isFull() {
	return top == full;
}

int Stack::getCount() {
	return top + 1;
}

void Stack::show() {
	for (int i = 0; i <= top; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int& Stack::cloning(Stack const& clSt) {
	if (!isEmpty()) // if we have any elements
		clear();
	// else just pushing elements from another stack (clSt)
	for (int i = 0; i <= clSt.top; i++) {
		push(clSt.arr[i]);
	}
	return top;
} 

int& Stack::operator+(Stack const& anSt) {
	for (int i = 0; i <= anSt.top; i++) {
		push(anSt.arr[i]); // just adding elements from "anSt"
	}
	return top;
}

int& Stack::operator*(Stack const& anSt) {
	Stack nS; // class's object like buffer
	for (int i = 0; i < anSt.top; i++) {
		for (int j = 0; j < top; j++) {
			if (arr[j] == anSt.arr[i]) { // if we will find general element
				if (!strchr(nS.arr, anSt.arr[i])) // if we have already this element
					nS.push(arr[j]);
				else
					continue;
			}
		}
	}
	clear(); // clear this
	cloning(nS); // cloning object "nS" in this
	return top;
}
