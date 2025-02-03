#include<iostream>

using namespace std;

double pi= 3.14159;
double calculateVolume(double r, double h){
    return pi*r*r*h;
}

double calculateSurfaceArea(double r,double h){
    return (2*pi*r*h)+2*pi*r*r;
}
int getPositiveInteger() {
    int num;
    while (true) {
        cout<< "(positive integer): ";
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
    double r;
    double h;
    cout<<endl<<"Enter radius: ";
    r = getPositiveInteger();
    cout<<endl<<"Enter height: ";
    h = getPositiveInteger();
    cout<<endl;

    if (r<0 || h<0){
        cout<<"Enter positive values only ";
        return 0;
    }
    double volume = calculateVolume(r,h);
    double surface_area = calculateSurfaceArea(r,h);

    cout<<"Volume is: "<<volume<<endl;
    cout<<"Surface Area is: "<<surface_area;

    return 0;

}