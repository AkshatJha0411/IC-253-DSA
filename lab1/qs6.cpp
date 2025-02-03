#include<iostream>
using namespace std;


int lengthS(string s){
    int l = 0;
    while (s[l] != '\0'){
        l++;
    }
    
    return l;
}
string reverseS(string s, int l){
    string reverse;

    for (int i = l-1;i>=0;i--){
        reverse += s[i];

    }
    cout<< "Reverse of string: "<<reverse;

    return reverse;
}

void checkPalindrome(string s, string reverse){
    if (s==reverse){
        cout<<"Given string is a palindrome"<<endl;
    }
    else {
        cout<<"Given string is not a palindrome"<<endl;
    }
}

int main (){
    string s;
    cout<<"Enter String:";
    cin>> s;
    int length = lengthS(s);
    cout << endl << "Length of string is: " << length << endl;
    string reverse = reverseS(s,length);
    cout<<endl;
    checkPalindrome(s,reverse);
    return 0;
}