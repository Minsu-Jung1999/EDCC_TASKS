#include <iostream>
#include <vector>
#include "Date.cpp"
using namespace std;

void removeBadPairs (vector <int>& v)
{
    if(v.empty()) return;

    for (size_t i = 0; i < v.size(); i++)
    {
        if(i%2!=0)
        {
            if(v[i-1] > v[i])
            {
                cout<<"i = "<< i<<endl;
                cout<<v[i-1]<<" "<<v[i]<<endl;
                v.erase(v.begin()+i-1,v.begin()+i+1);
                i--;
            }
        }
    }
    if(v.size()==1) v.erase(v.begin());    
}

int main()
{
   Date date(11,4);
   cout<<"Month: " <<date.getMonth()<<endl;
   cout<<"Total days of the month: "<<date.daysInMonth()<<endl;
   cout<<"Current day: "<<date.getDay()<<endl;
   cout<<"Next day.....";
   date.nextDay();
   cout<<date.getDay()<<endl;
   cout<<date.toString()<<endl;
    
    return 0;
}