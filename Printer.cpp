#include "Printer.h"
void Printer::init() 
{
	dict.init(30);
}
void Printer::print(string prompt, int X, int Y) {
	int i = 0;
	for (char b : prompt) {
		cout << b << endl;
		if ((b < 48|| b  > 122)&& b != 32) {
			continue;
		}
		cout << b << endl;
		if (b == 32) {
			i++;
			continue;
		}
		if (b < 'a' && b >= 'A') {
			b += 32;
		}
		cout << b << endl;
		ofImage* temp = dict.getItem(b);
		temp->draw(i*X,Y);
		i++;
	}
}