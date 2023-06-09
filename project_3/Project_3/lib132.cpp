#include <iostream>
#include <vector>
#include <string>
#include "lib132.h"
using namespace std;

string replaceAll(const std::string& s, char c1, char c2)
{
    std::string result = s;
    for (char& c : result)
    {
        if (c == c1)
        {
            c = c2;
        }
    }
    return result;
}

void startEndLetter(char c) {
    cout << "Looking for two \"" << c << "\" words in a row." << endl;
    string prev_word;
    bool isend = false;
    while (true)
    {
        cout << "Type a word: ";
        string word;
        cin >> word;
        char first_char = tolower(word.front());
        char last_char = tolower(word.back());
        if (first_char != last_char)
        {
            isend = false;
        }
        if (first_char == tolower(c))
        {
            if (isend)
            {
                cout << "\"" << c << "\" is for \"" << word << "\"" << endl;
                break;
            }
            isend = true;
        }
    }
}

int countWords(string s)
{
    int word = 0;
    bool isword = false;
    bool isspace = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            if (isspace)
                word++;
            isword = true;
            isspace = false;
        }
        else
        {
            isspace = true;
        }
    }

    return word;
}

int indexOfHelper(string s1, string s2, int start_index)
{
    if (s2.empty())return 0;	// found as it starts
    if (start_index + s2.size() > s1.size()) return -1;	// not matched

    if (s1.substr(start_index, s2.size()) == s2) return start_index;

    return indexOfHelper(s1, s2, start_index + 1);
}

int indexOf(string s1, string s2)
{
    return indexOfHelper(s1, s2, 0);
}

//bool containsTwice(string s1, char c1)
//{
//    bool isin = false;
//    for (int i = 0; i < s1.size(); i++)
//    {
//        if (s1[i] == c1)
//        {
//            if (isin)
//                return true;
//            isin = true;
//        }
//    }
//    return false;
//
//}
//
//void startEndLetter(char c) {
//    cout << "Looking for two \"" << c << "\" words in a row." << endl;
//    string prev_word;
//    bool isend = false;
//    while (true)
//    {
//        cout << "Type a word: ";
//        string word;
//        cin >> word;
//        char first_char = tolower(word.front());
//        char last_char = tolower(word.back());
//        if (first_char != last_char)
//        {
//            isend = false;
//        }
//        if (first_char == tolower(c))
//        {
//            if (isend)
//            {
//                cout << "\"" << c << "\" is for \"" << word << "\"" << endl;
//                break;
//            }
//            isend = true;
//        }
//    }
//}

void trim(string& s)
{
    // Find the index of the first non-whitespace character
    size_t start = s.find_first_not_of(" \t\r\n");

    // If the string is all whitespace, erase everything and return
    if (start == string::npos) {
        s.erase();
        return;
    }

    // Find the index of the last non-whitespace character
    size_t end = s.find_last_not_of(" \t\r\n");

    // Erase the whitespace at the beginning and end of the string
    s.erase(end + 1);
    s.erase(0, start);
}


bool containsTwice(string s1, char c1)
{
    bool isin = false;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == c1)
        {
            if (isin)
                return true;
            isin = true;
        }
    }
    return false;

}

//void wordStats(string fileName)
//{
//    ifstream INPUTFILE(fileName);
//    if (!INPUTFILE.good())
//    {
//        cout << "Error, bad input file." << endl;
//        return;
//    }
//    char cread;
//    char alphabet[26] = { 0, };
//    double count = 0.f;
//    int unique = 0;
//    double words = 0.f;
//    string word;
//    // Unique Counter
//    while (INPUTFILE >> word)
//    {
//        words++;
//        count += word.size();
//        for (int i = 0; i < word.size(); i++)
//        {
//            int c_temp = (int)(tolower(word[i]));
//            c_temp -= 97;
//            if (c_temp >= 0)
//            {
//                alphabet[c_temp]++;
//            }
//        }
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (alphabet[i] > 0)
//            unique++;
//    }
//    double mean = count / words;
//    cout << "Total words    = " << words << endl;
//    cout << "Average length = " << mean << endl;;
//    cout << "Unique letters = " << unique << endl;
//}

void addStars(vector<string>& a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        if (!a[i].empty())
        {
            a.insert(a.begin() + i, "*");
            i++;
        }
    }
    a.insert(a.end(), "*");

}

int largestDigit(int num) {
    // Base case: single digit number
    if (num < 10 && num >= 0) {
        return num;
    }
    else if (num < 0) { // handle negative numbers
        num = -num;
    }
    // Recursive case: find the largest digit in the remaining part of the number
    int max_digit = largestDigit(num / 10);
    // Compare the largest digit found so far with the last digit of the current number
    int last_digit = num % 10;
    if (last_digit > max_digit) {
        return last_digit;
    }
    else {
        return max_digit;
    }
}

string toLowercase(string s)
{
    string temp_s;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!isalpha(s[i]))
        {
            s.erase(s.begin() + i);
        }
        temp_s = tolower(s[i]);
        s.replace(i, 1, temp_s);
    }
    return s;
}

string reprompt(string name)
{
    bool isvalid = false;
    string input_name;
    while (isvalid == false)
    {
        cout << name;
        getline(cin, input_name);
        if (input_name.empty() || input_name == " ")
        {
            cout << "Invalid response. Please try again." << endl;
        }
        else
        {
            isvalid = true;
        }
        cout << endl;

    }

    return input_name;
}

void swapPairsInPlace(string& s)
{
    if (s.empty()) return;
    int size = s.size();
    if (size % 2 != 0) size--;
    for (int i = 0; i < size - 1; i++)
    {
        char temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
        i++;
    }

}

void reverse(vector<int>& v)
{
    int lastIndex = v.size() - 1;
    cout << "size = " << v.size() / 2 << endl;
    for (size_t i = 0; i < v.size() / 2; i++)
    {
        int tempdata = v[i];
        v[i] = v[lastIndex];
        v[lastIndex] = tempdata;
        lastIndex--;
    }

}

void stretch(vector<int>& v)
{
    int size = v.size() * 2;
    for (int i = 0; i < size; i++)
    {
        int tempdata = v[i];
        v.erase(v.begin() + i);
        v.insert(v.begin() + i, tempdata / 2);
        v.insert(v.begin() + i + 1, tempdata / 2);
        cout << endl;
        if (tempdata % 2 != 0)
        {
            v[i]++;
        }
        i++;
    }
}



















