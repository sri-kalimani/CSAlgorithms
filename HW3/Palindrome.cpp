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
 
    if (PalindromeArr.length() <=1) {
        return true;
    }
    if (PalindromeArr.substr(0,1) != PalindromeArr.substr(PalindromeArr.length()-1,1)) {
        return false;
    }
    return PalindromeCheck(PalindromeArr.substr(1,PalindromeArr.length()-2));
}
string stringClean(string sentence) {
    int arr_size = sentence.length();
  
    for (int i=0; i<arr_size; i++){
      if (!((sentence[i] >= 'a' && sentence[i]<='z') || (sentence[i] >= 'A' && sentence[i]<='Z')))
        {
            sentence[i] = '\0';
        }
        sentence[i] = std::tolower(sentence[i]);
    }

    
    return sentence;
}


int main() {
   
    string userInput;
    cout << "Enter a string you would like to check if it's a palindrome: "<< endl;
   getline(cin,userInput);
    
    if(PalindromeCheck(stringClean(userInput))){
         cout << "yes it is a palindrome" << endl;
     }else{
         cout << "no it isn't a palindrome" << endl;
     }
     
    return 0;
}
