//
// Created by asus on 11/11/2019.
//

#include <stdio.h>
#include <iostream>
#include <array>
#include <string.h>


using namespace std;

bool PalindromeCheck(string ThePalindromeString) {
    string PalindromeArr = ThePalindromeString;
    bool IsItAPalindrome = false;
    cout << PalindromeArr << endl;
    if (PalindromeArr.length() <=1) {
        
        return true;
    }

    if (PalindromeArr.substr(0,1) != PalindromeArr.substr(PalindromeArr.length()-1,1)) {
        return false;
    }

    return PalindromeCheck(PalindromeArr.substr(1,PalindromeArr.length()-2));
}

char *StringCleaning() {
    char StringInput[256];
    cout << "Please provide the word or phrase you wish to check" << endl;
    cin >> StringInput;
    int ArraySize;
    ArraySize = strlen(StringInput);
    char FormattedStringArr[ArraySize];
    int FormattedArraySize;

    for (int i = 0; i < ArraySize; i++) {
        if (StringInput[i] != '!' || StringInput[i] != '?' || StringInput[i] != '.' ||
            StringInput[i] != ',') {
            FormattedStringArr[i] = tolower(StringInput[i]);
        }
    }

    FormattedArraySize = strlen(FormattedStringArr);
    char PalindromeString[FormattedArraySize];

    for (int i = 0; i < FormattedArraySize; i++) {
        PalindromeString[i] = FormattedStringArr[i];
    }
    return PalindromeString;
}


int main() {
    //char* ThePalindromeString = StringCleaning();
   // int rightside = strlen(ThePalindromeString) - 1;
    cout << PalindromeCheck("theeht") << endl;
    

    return 0;
}