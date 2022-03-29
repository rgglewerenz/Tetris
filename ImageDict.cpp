#include "ImageDict.h"
ofImage* ImageDict::getItem(char id) {
	int i = 0;
	for (char b : letter) {
		cout << b << " is not equal to " << id << endl;
		if (b == id) {
			cout << b << " in func" << endl;
			return  &images[i];
		}
		i++;
	}
}
void ImageDict::init(int size) {
	int i = 0;
	static ofImage temp;
	for (char let : "abcdefghijklmnopqrstuvwxyz1234567890!.?") {
		if (i > 38)
			break;
		name.push_back(names[i]);
		images.push_back(temp);
		if (i > 25 && i <= 35) {
			cout << name[i] << " name temp" << endl;
			images[i].load("Images\\Numbers\\" + name[i] + ".png");
		}
		else if (i > 35) {
			cout << name[i] << " name temp" << endl;
			images[i].load("Images\\Punctiation\\" + name[i] + ".png");
		}
		else {
			cout << name[i] << " name temp" << endl;
			images[i].load("Images\\Letters\\" + name[i] + ".png");
		}
		images[i].resize(size, size);
		letter.push_back(let);
		i++;
	}
}