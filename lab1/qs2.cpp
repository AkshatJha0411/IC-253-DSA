
#include <iostream>
using namespace std;

int getPositiveInteger() {
    int num;
    while (true) {
        cout<< "Enter positive integer: ";
        cin >> num;
        if (cin.fail() || num <= 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a positive integer.\n";
        } else {
            return num;
        }
    }
}

int main(){
cout<<"enter a positive number: " ;
int n;
n = getPositiveInteger() ;
int a =1;
int b = 1;
cout<<a<<" "<<b<<" ";
for (int i=2; i<n;i++) {
    int temp=a+b;
    cout<<temp<<" ";
    a=b;
    b=temp;
}





}