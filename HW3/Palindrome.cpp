//
// Created by asus on 11/11/2019.
//

#include <stdio.h>
#include <iostream>
#include <array>
#include <string.h>


using namespace std;

bool PalindromeCheck(int leftside, int rightside, char *&ThePalindromeString) {
    char *PalindromeArr = ThePalindromeString;
    bool IsItAPalindrome = false;

    if (leftside >= rightside) {
        IsItAPalindrome = true;
        return IsItAPalindrome;
    }

    if (PalindromeArr[leftside] != PalindromeArr[rightside]) {
        return IsItAPalindrome;
    }

    return PalindromeCheck(++leftside, --rightside, ThePalindromeString);
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
            FormattedStringArr[i] == tolower(StringInput[i]);
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
    char* ThePalindromeString = StringCleaning();
    int rightside = strlen(ThePalindromeString) - 1;
    PalindromeCheck(0, rightside, ThePalindromeString);


    return 0;
}