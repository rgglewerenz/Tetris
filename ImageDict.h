#pragma once
#include "ofImage.h"
#include <string>
using namespace std;
class ImageDict
{
public:
	void init(int);
	ofImage* getItem(char item);
private:
	vector<char> letter;
	vector<string> name;
	vector<ofImage> images;
	string names[39] = {"LetterA","LetterB","LetterC","LetterD",
					"LetterE" ,"LetterF" ,"LetterG" ,"LetterH" ,"LetterI", 
					"LetterJ" ,"LetterK" ,"LetterL" ,"LetterM","LetterN","LetterO",
					"LetterP","LetterQ","LetterR","LetterS","LetterT","LetterU","LetterV",
					"LetterW","LetterX","LetterY","LetterZ","One","Two","Three","Four","Five","Six",
					"Seven", "Eight", "Nine", "Zero", "Exclemation","Period","Question"};
};

