#include "lib132.h"
#include <iostream>
#include <vector>
#include <string>
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
        if (isalpha(s[i]))
        {
            temp_s = tolower(s[i]);
            s.replace(i, 1, temp_s);

        }
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


int Date::absoluteDay()
{
    if (month == 1)return day;
    if (month == 2)return day + 28;
    int absday = 0;
    for (int i = 1; i < month; i++)
    {
        if (i < 8)
        {
            if (i % 2 == 1)
                absday += 31;
            else
                absday += 30;
            if (i == 2)
                absday += 28;
        }
        else if (i > 7)
        {
            if (i % 2 == 1)
                absday += 30;
            else
                absday += 31;
        }
    }
    return absday+day-30;
}


#pragma region Class MovieRating
MovieRating::MovieRating(string title) :rating(0), review(0), title(title) {}


string MovieRating::getMovieTitle()
{
    return  title;
}

double MovieRating::getReviewCount()
{
    return review;
}

const double MovieRating::getAverageRating()
{
    if (rating == 0)
        return -1;
    return rating / review;
}

void MovieRating::addRating(double rating)
{
    this->rating += rating;
    review++;

}

void removeEvenLength(vector<string>& word)
{
    for (size_t i = 0; i < word.size(); i++)
    {
        if (word[i].size() % 2 == 0)
        {
            word.erase(word.begin() + i);
            i--;
        }
    }
}

ostream& operator<<(ostream& out, MovieRating& other)
{
    // format The Wizard of Oz : 4.562 stars (3623 reviews)
    out << other.title << " : " << other.getAverageRating() << " stars (" << other.getReviewCount() << " reviews)" << endl;
    return out;
}

int pow(int base, int exp)
{
    cout << "Recursion" << endl;
    if (exp == 0)
    {
        return 1;
    }
    else
    {
        if (exp % 2 == 0)
        {
            exp /= 2;
            base *= base;
        }
        return base * pow(base, exp-1);
    }
}

void printRange(int x, int y)
{
    if (x > y)
    {
        throw string("x is bigger than y");
    }
    int range = y - x;
    helper(x, range, 0);
    /*for (int i = 0; i <= range; i++)
    {
        cout << x++;
        if (i+1 > range)return;
        if ((range%2==1) && (i == range / 2))
            cout << " -- ";
        else if (i < range / 2)
            cout << " > ";
        else
            cout << " < ";
    }*/
}
void helper(int x,int range, int iterlater)
{
    cout << x;
    if (iterlater <= range)
    {
        if (iterlater + 1 > range)return;
        if ((range % 2 == 1) && (iterlater == range / 2))
            cout << " -- ";
        else if (iterlater < range / 2)
            cout << " > ";
        else
            cout << " < ";
        helper(x + 1, range, iterlater + 1);
    }

}




bool MovieRating::operator==(MovieRating otherMovie)
{
    if (this->title != otherMovie.title) return false;
    else if (this->review != otherMovie.review) return false;
    else if (this->getAverageRating() != otherMovie.getAverageRating()) return false;
    else return true;
}

#pragma endregion

#pragma region ItemOrder
ItemOrder::ItemOrder(string itemnum, int quantity, int pricePerItem) :
    itemNumber(itemnum), quantity(quantity), pricePerItem(pricePerItem) {}

string ItemOrder::getItem()
{
    return itemNumber;
}

double ItemOrder::getPrice()
{
    return quantity * pricePerItem/100;
}

int ItemOrder::getQuantity()
{
    return quantity;
}

ostream& operator<<(ostream& out, ItemOrder& other)
{
    out << "item #" << other.getItem() <<": " << other.quantity << " for $" << other.getPrice();
    return out;
}


bool ItemOrder::operator<(ItemOrder other)
{
    if (getPrice() < other.getPrice())
        return true;
    if (getPrice() == other.getPrice())
    {

        if (getQuantity() < other.getQuantity()) return true;
        if (getQuantity() == other.getQuantity())
        {
            string otherName = other.getItem();
            for (size_t i = 0; i < otherName.size(); i++)
            {
                if (otherName[i] > itemNumber[i])
                    return true;
                else
                    return false;
            }
        }
    }
    return false;
}
#pragma endregion

void printPath(const std::vector<int>& path) {
    if (path.empty()) {
        return;
    }
    cout << path.front();
    if(path.size()>1)
        cout << ", ";
    printPath(std::vector<int>(path.begin() + 1, path.end()));
}
void waysToClimb(int n) {
    std::vector<int> path;
    if (n >= 0)
        throw 0;
    waysToClimbHelper(n, path);
}
void waysToClimbHelper(int n, std::vector<int>& path) {
    if (n == 0)
    {
        cout << "{";
        printPath(path);
        cout << "}";
        cout << endl;
    }
    if (n >= 1)
    {
        path.push_back(1);
        waysToClimbHelper(n - 1, path);
        path.pop_back();
    }
    if (n >= 2)
    {
        path.push_back(2);
        waysToClimbHelper(n - 2, path);
        path.pop_back();
    }
}

int wordCount(string words)
{
    if (words.empty())
        return 0;
    bool continuousspaces = true;
    int count = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == ' ')
        {
            continuousspaces = true;
        }
        else
        {
            if (continuousspaces)
            {
                continuousspaces = false;
                count++;
            }

        }
    }

    return count;
}

