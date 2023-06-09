// C++ 132.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype> 
#include <fstream>

using namespace std;
#pragma region Class open ~ 04-25
int recursion_mystery3(int n) {
    if (n < 0) {
        return -recursion_mystery3(-n);
    }
    else if (n < 10) {
        return (n + 1) % 10;
    }
    else {
        return 100 * recursion_mystery3(n / 10) + (n + 1) % 10;
    }
}

bool equalsIgnoringCase(string s1, string s2)
{
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s2.size() = " << s2.size() << endl;
    if (s1.size() != s2.size())return false;
    for (int i = 0; i < s1.size(); i++)
    {
        cout << "s1 compare with s2 => " << s1[i] << s2[i] << endl;
        if (tolower(s1[i]) != tolower(s2[i]))return false;
    }
    return true;
}

void quadratic(int a, int b, int c, double& root1, double& root2)
{
    root1 = (-b + sqrt(b * b - (4 * a * c))) / (2 * a);
    root2 = (-b - sqrt(b * b - (4 * a * c))) / (2 * a);
}

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

double averageValueInFile(string fileName)
{
    ifstream inputFile(fileName);
    double total = 0;
    double count = 0;
    string line;
    while (getline(inputFile, line))
    {
        std::istringstream iss(line);
        double num = 0.0;
        while (iss >> num) {
            count++;
            cout << num << " is a valid number." << std::endl;
            total += num;
        }
        if (!iss.eof()) {
            cerr << line << " contains an invalid number." << std::endl;
        }
    }
    if (total == 0) return 0.f;
    double mean = total / count;
    inputFile.close();
    return mean;
}

void wordStats(string fileName)
{
    ifstream INPUTFILE(fileName);
    if (!INPUTFILE.good())
    {
        cout << "Error, bad input file." << endl;
        return;
    }
    char cread;
    char alphabet[26] = { 0, };
    double count = 0.f;
    int unique = 0;
    double words = 0.f;
    string word;

    // Unique Counter
    while (INPUTFILE >> word)
    {
        words++;
        count += word.size();
        for (int i = 0; i < word.size(); i++)
        {
            int c_temp = (int)(tolower(word[i]));
            c_temp -= 97;
            if (c_temp >= 0)
            {
                alphabet[c_temp]++;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > 0)
            unique++;
    }
    double mean = count / words;
    cout << "Total words    = " << words << endl;
    cout << "Average length = " << mean << endl;;
    cout << "Unique letters = " << unique << endl;
}

void hoursWorked(string fileName)
{
    ifstream FILE(fileName);
    if (!FILE.is_open()) return;
    string id, name, line;
    double total_hours, daily_average, hours;
    while (getline(FILE, line))
    {
        istringstream iss(line);
        total_hours = 0.0;
        int num_days = 0;
        iss >> id >> name;
        while (iss >> hours) {
            total_hours += hours;
            num_days++;
        }
        daily_average = total_hours / num_days;
        cout << left << setw(9) << name << " (ID# " << right << setw(4) << id << ") worked "
            << fixed << setprecision(1) << total_hours << " hours ("
            << setprecision(2) << daily_average << "/day)" << endl;
    }
    FILE.close();
}


string recursionMystery6(string s) {
    if (s.length() == 0) {
        return s;
    }
    else if (s.length() % 2 == 0) {
        string rest = s.substr(0, s.length() - 1);
        string last = s.substr(s.length() - 1, 1);
        return last + recursionMystery6(rest);
    }
    else {
        string first = s.substr(0, 1);
        string rest = s.substr(1);
        return "(" + first + ")" + recursionMystery6(rest);
    }
}

void recursionMystery7(string s) {
    if (s.length() <= 1) {
        cout << s;
    }
    else {
        string first = s.substr(0, 1);
        string last = s.substr(s.length() - 1, 1);
        string mid = s.substr(1, s.length() - 2);
        if (first < last) {
            recursionMystery7(mid);
            cout << last << "<" << first << ">";
        }
        else {
            cout << "[" << first << "]";
            recursionMystery7(mid);
            cout << last;
        }
    }
}

void crazyCaps(string& s)
{
    string tempchar;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 1)
        {
            tempchar = toupper(s[i]);
            s.replace(i, 1, tempchar);
        }
        else
        {
            tempchar = tolower(s[i]);
            s.replace(i, 1, tempchar);
        }

    }
}

void vectorMystery1(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        int n = v[i];
        if (n % 10 == 0) {
            v.erase(v.begin() + i, v.begin() + i + 1);
            v.push_back(n);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

double mean(vector<double> v)
{
    double nums = 0;
    if (v.empty()) return 0.0f;
    for (int i = 0; i < v.size(); i++)
    {
        nums += v[i];
    }
    //cout << "nums = " << nums << endl;
    //cout << "v.size() = " << v.size() << endl;
    return nums / v.size();
}
string lettersOnly(string s)
{
    if (s.size() == 0)
        return "";
    else if (!isalpha(s[0]))
        return lettersOnly(s.substr(1));
    else
        return s[0] + lettersOnly(s.substr(1));
}
string toLowercase(string s)
{
    string temp_s;
    for (size_t i = 0; i < s.size(); i++)
    {
        temp_s = tolower(s[i]);
        s.replace(i, 1, temp_s);
    }
    return s;
}
string starString(int num)
{
    if (num < 0) return "";
    string stars;
    int iterator = 1;
    for (size_t i = 0; i < num; i++)
    {
        iterator *= 2;
    }
    for (int i = 0; i < iterator; i++)
    {
        stars += "*";
    }
    return stars;
}
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
void removeBadPairs(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i == (v.size() - 1)) return;
        if (v[i] > v[i + 1])
        {
            //v.erase(v.begin()+i,)
        }
    }
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
            cout << "Invalid response. Please try again" << endl;
        }
        else
        {
            isvalid = true;
        }
        cout << endl;
    }

    return input_name;
}

bool isPalindrome(string word)
{
    //if (word.size() % 2 == 0) return false;
    if (word.empty()) return true;
    if (tolower(word[0]) != tolower(word[word.size() - 1]))return false;
    else
    {
        if (word.size() == 2)return true;
        return isPalindrome(word.substr(1, word.size() - 2));
    }
}


int numberSequence(int n)
{
    if (n <= 1)return 0;
    int a = n - (n / 2);

    cout << a;
    return numberSequence(a);

}
void collectionMystery1(vector<int>& list) {
    for (int i = 0; i < list.size(); i++) {
        int n = list[i];
        list.erase(list.begin() + i, list.begin() + i + 1);
        if (n % 2 == 0) {
            list.push_back(i);
        }
    }
}

int largestDigit(int num) {
    // Base case: single digit number
    if (num < 10 && num >= 0) {
        return num;
    }
    else if (num < 0) { // handle negative numbers
        num *= -1;
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

void stretch(vector<int>& v)
{
    int size = v.size() * 2;
    for (int i = 0; i < size; i++)
    {
        int tempdata = v[i];
        v.erase(v.begin() + i);
        cout << i << " �ݺ�:" << endl;
        cout << "erase: ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ,";
        }
        cout << endl;
        v.insert(v.begin() + i, tempdata / 2);
        v.insert(v.begin() + i + 1, tempdata / 2);
        cout << "inserat: ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ,";
        }
        cout << endl;
        if (tempdata % 2 != 0)
        {
            v[i]++;
        }
        i++;
    }
}
#pragma endregion

#pragma region 04-27

void reverseFileHelper(ifstream& file)
{
    string line;
    if(getline(file, line))
    {
        reverseFileHelper(file);
        cout << line << endl;
    }
}

// public
void reverseFile(string fileName)
{
    ifstream file;
    file.open(fileName);
    reverseFileHelper(file);

}

// base 1: 0, 1, 2, 3, 4, ---
// base 2: 0, 1
// decimal      binary
//      0          0
//      1          1
//      2         10    // add 0
//      3         11
//      4        100    // add 0
//      5        101
//      6        110
//      7        111
//      8       1000    // add 0

// n % 2 == 0
//  _______0
// n % 2 == 1
// ______1
// 
// 
// n % 10 -----> digit in 1s place
// 1234     % 10 = 4
// 1234     / 10 = 123
// 
// 
// 1234 % 2 = 0
// 1234 / 2 = 617
// 
// _ _ _ _ _ _ _ _ _ _
// 2048 1024 512 256 128 64 32 16 8 4 2 1 0

void printBinary()
{

}

#pragma endregion

#pragma region 04-28

bool digitsSorted(int num)
{
    if (num < 10)
        return true;
    if (num % 10 > (num % 100) / 10)
    {
        return digitsSorted(num / 10);
    }
    return false;
}

void printAllBinaryHelper(int num, string& memory)
{
    if (num == 0)
    {
        // base case
        cout << memory << endl;
    }
    else
    {
        memory += "0";
        printAllBinaryHelper(num - 1, memory);
        memory = memory.substr(0, memory.size() - 1);
        memory += "1";
        printAllBinaryHelper(num - 1, memory);
        memory = memory.substr(0, memory.size() - 1);
    }
}
void printAllBinary(int num)
{
    string space = "";
    printAllBinaryHelper(num, space);
}

void makeChange(int num, vector<string>& v)
{

}

void waysToClimbHelper(int stairs,int mount)
{
    if (stairs > mount)
    {
        cout << 1;
        if(mount+1<stairs)
            cout << ", ";
        waysToClimbHelper(stairs,mount+1);
    }
    else
    {
        cout << 2;
        waysToClimbHelper(stairs,mount+2);
    }
}

void waysToClimb(int stairs)
{
    cout << "{";
    waysToClimbHelper(stairs,0);
    cout << "}";
}

#pragma endregion



int main()
{
    waysToClimb(5);
}







