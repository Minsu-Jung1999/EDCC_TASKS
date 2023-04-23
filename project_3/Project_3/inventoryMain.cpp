// Replace this with your code. This is just so 
// you can try compiling before you start writing code
#include "LetterInventory.h"
#include "lib132.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    // Get the first input
    cout << "First word/phrase/letters: ";
    string input1;
    getline(cin, input1);

    // Get the second input
    cout << "Second word/phrase/letters: ";
    string input2;
    getline(cin, input2);

    // Create LetterInventory objects for each input
    LetterInventory inv1(input1);
    LetterInventory inv2(input2);

    // Check if the two LetterInventory objects are equal (i.e. if the inputs are anagrams)
    if (inv1.contains(inv2) && inv2.contains(inv1)) {
        cout << "They are anagrams!";
    }
    else {
        cout << "They are not anagrams.";
    }

    return 0;
}