
#include <iostream>
#include <Windows.h>
#include "Stack.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Stack a;
	Stack b;
	Stack c;
	for (int i = 0; i < 10; i++) {
		a.push((char)rand()%40+85);
	}
	a.show();
	b.cloning(a);
	b.show();
	cout << "\n\n";
	for (int i = 0; i < 10; i++) {
		c.push((char)rand() % 40 + 85);
	}
	c.show();
	c * a;
	c.show();
}

