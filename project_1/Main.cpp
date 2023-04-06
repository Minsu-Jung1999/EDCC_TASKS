#include <iostream>
#include <fstream>
#include <string>
#include "Project_1.h"
using namespace std;

int main() 
{
    bool bEnd = false;
    string user_input;
    GameStartText();
    while (!bEnd)
    {
        int mode = ModeSetting();
        switch (mode)
        {
        case EMode::CREATE_MODE:
            // Create mode function call    
            CreateFile();
            break;
        case EMode::VIEW_MODE:
            ViewFile();
            // View mode function call    
            break;
        default:
            break;
        }

    }
}