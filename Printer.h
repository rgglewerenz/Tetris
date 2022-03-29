#pragma once
#include "ofImage.h"
#include "ImageDict.h"
#include <string>
using namespace std;
class Printer
{
public:
	void init();
	void print(string prompt);
private:
	ImageDict dict;
};

