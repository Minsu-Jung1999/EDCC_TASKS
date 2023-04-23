#ifndef _lib132_h_
#define _lib132_h_
#include <vector>
#include <iostream>
using namespace std;


std::string replaceAll(const std::string& s, char c1, char c2);

void startEndLetter(char c);

int countWords(std::string s);

int indexOfHelper(std::string s1, std::string s2, int start_index);

int indexOf(std::string s1, std::string s2);

bool containsTwice(std::string s1, char c1);

void startEndLetter(char c);

void trim(std::string& s);

bool containsTwice(std::string s1, char c1);

void wordStats(string fileName);

int largestDigit(int num);

string toLowercase(string s);

string reprompt(string name);

void swapPairsInPlace(string& s);

void reverse(vector<int>& v);

void stretch(vector<int>& v);

#endif







