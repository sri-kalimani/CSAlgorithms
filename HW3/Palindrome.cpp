//
// Created by asus on 11/11/2019.
//

#include <stdio.h>
#include <iostream>
#include <array>
#include <string.h>


using namespace std;

// bool PalindromeCheck(int leftside, int rightside, char *&ThePalindromeString) {
//     char *PalindromeArr = ThePalindromeString;
//     bool IsItAPalindrome = false;
//
//     if (leftside >= rightside) {
//         IsItAPalindrome = true;
//         return IsItAPalindrome;
//     }
//
//     if (PalindromeArr[leftside] != PalindromeArr[rightside]) {
//         return IsItAPalindrome;
//     }
//
//     return PalindromeCheck(++leftside, --rightside, ThePalindromeString);
// }

string stringClean(string sentence) {
    // char StringInput[256];
    // cout << "Please provide the word or phrase you wish to check" << endl;
    // cin >> StringInput;


    // int arr_size = strlen(sentence);
    int arr_size = sentence.length();
    // char FormattedStringArr[ArraySize];
    // int FormattedArraySize;

    for (int i=0; i<arr_size; i++){
      if (!((sentence[i] >= 'a' && sentence[i]<='z') || (sentence[i] >= 'A' && sentence[i]<='Z')))
        {
            sentence[i] = '\0';
        }
        sentence[i] = std::tolower(sentence[i]);
    }

    // for (int i = 0; i < ArraySize; i++) {
    //     if (StringInput[i] != '!' || StringInput[i] != '?' || StringInput[i] != '.' ||
    //         StringInput[i] != ',') {
    //         FormattedStringArr[i] = tolower(StringInput[i]);
    //     }
    // }

    // FormattedArraySize = strlen(FormattedStringArr);
    // char PalindromeString[FormattedArraySize];
    //
    // for (int i = 0; i < FormattedArraySize; i++) {
    //     PalindromeString[i] = FormattedStringArr[i];
    // }
    return sentence;
}


int main() {
    // char* ThePalindromeString = stringClean();
    // int rightside = strlen(ThePalindromeString) - 1;
    // cout << PalindromeCheck(0, rightside, ThePalindromeString) << endl;

    cout<< stringClean("p*nv jJK opk&&&!!!@iop");
    // cout<<"hello";
    return 0;
}
