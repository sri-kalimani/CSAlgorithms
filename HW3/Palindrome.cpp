//
// Created by asus on 11/11/2019.
//

#include <stdio.h>
#include <iostream>
#include <array>
#include <string.h>


using namespace std;

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

    cout<< stringClean("p*nv jJK opk&&&!!!@iop");

    return 0;
}
