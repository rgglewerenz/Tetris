#include "Printer.h"
void Printer::init() 
{
	dict.init(30);
}
void Printer::print(string prompt) {
	cout << "**Printing**" << endl;
	int i = 0;
	cout << "**Printing**" << endl;
	for (char b : prompt) {
		cout << b << endl;
		if (b < 48|| b  > 122) {
			continue;
		}
		cout << b << endl;
		if (b == 32) {
			i++;
			continue;
		}
		if (b < 'a') {
			b += 32;
		}
		cout << b << endl;
		ofImage* temp = dict.getItem(b);
		temp->draw(10,10);
		i++;
	}
}