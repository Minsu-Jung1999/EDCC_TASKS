#include <iostream>
#include <vector>
#include <string>
using namespace std;

string replaceAll(const std::string& s, char c1, char c2);
void startEndLetter(char c);
int countWords(string s);
int indexOfHelper(string s1, string s2, int start_index);

int indexOf(string s1, string s2);
bool containsTwice(string s1, char c1);
void startEndLetter(char c);
void trim(string& s);

bool containsTwice(string s1, char c1);
//void wordStats(string fileName);
void addStars(vector<string>& a);
int largestDigit(int num);
string toLowercase(string s);

string reprompt(string name);
void swapPairsInPlace(string& s);

void reverse(vector<int>& v);

void stretch(vector<int>& v);
class Date
{
private:
    int month;
    int day;
    int totalday;
public:
    Date(int m, int d) : month(m), day(d)
    {
        if (m < 8)
        {
            if (m % 2 == 1)
                totalday = 31;
            else
                totalday = 30;
            if (m == 2)
                totalday = 28;
        }
        else if (m > 7)
        {
            if (m % 2 == 1)
                totalday = 30;
            else
                totalday = 31;
        }
    }
    int daysInMonth()
    {
        return totalday;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    void nextDay()
    {
        if (totalday == day)
        {
            month++;
            if (month > 12)
                month = 1;
            day = 1;
        }
        else
            day++;

    }
    std::string toString()
    {
        std::string date;
        if (month < 10)
            date = "0" + std::to_string(month);
        else
            date = std::to_string(month);
        date += "/";
        if (day < 10)
            date += "0" + std::to_string(day);
        else
            date += std::to_string(day);
        return date;
    }

    int absoluteDay();

};
void removeEvenLength(vector<string>& word);

class MovieRating
{
private:
    int review;
    double rating;
    string title;
public:
    MovieRating(string title);
    string getMovieTitle();
    double getReviewCount();
    const double getAverageRating();
    void addRating(double rating);
    friend ostream& operator<< (ostream& out,  MovieRating& other);
    bool operator== (MovieRating otherMovie);
};

int pow(int base, int exp);

void printRange(int x, int y);
void helper(int x, int range, int iterlater);

class ItemOrder
{
private:
    string itemNumber;
    int quantity;
    int pricePerItem;
public:
    ItemOrder(string itemnum, int quantity, int pricePerItem);
    string getItem();
    double getPrice();
    int getQuantity();
    friend ostream& operator <<(ostream& out,  ItemOrder& other);
    bool operator < (ItemOrder other);
};

void waysToClimb(int n);

void waysToClimbHelper(int n, std::vector<int>& path);

int wordCount(string words);

void printBinary(int num);

#pragma region Point2_Class

class Point2
{
private:

    int x;
    int x_origin;
    int y;
    int y_origin;

public:

    int getX();//	returns the x coordinate
    int getY();	//returns the y coordinate
    void setX(int newX); //	sets the x coordinate to the parameter value
    void setY(int newY);//	sets the y coordinate to the parameter value
    void translate(int dx, int dy); //	changes a Point's location by a given dx, dy amount.
    double distanceFromOrigin();

};

#pragma endregion

void vectorMystery(std::vector<int>& v);
int merge(int n);
void removeAll(string first, string second);
void Stractch(vector<int>& v);

void VowelStats(string v);
void letteronly(string s);
void switchPairs(vector<int>& v);

string addCommas(string a);

vector<int> intersect(vector<int> v1, vector<int> v2);

#pragma region Vector
int matchCount(vector<int> v1, vector<int> v2);

void multTable2D(vector<vector<int>>& v1);

#pragma endregion


