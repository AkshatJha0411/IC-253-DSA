#include<iostream>
using namespace std;




double calculateArea (double length, double width){
    cout <<"Area: " <<length*width; 
    return length*width;
}

double calculatePerimeter(double length, double width){
    cout << "Perimeter: "<<2*(length+width);
    return 2*(length+width);
}
int main (){
    double length,width;
    
    double area = calculateArea(length,width);
    cout<<endl;
    double perimeter = calculatePerimeter(length,width);
    return 0;
}

