#include<iostream>
using namespace std;

int find(int tot_days){
    int years = tot_days/365;
    int months = (tot_days%365)/30;
    int days = int(tot_days%365)%30;
    cout<<years<<" years,"<<months<<" months,"<<days<<" days"<<endl;
    return years;
}

bool leap_year(int yr){
    if((yr%4==0 && yr%100!=0 )|| yr%400==0){
        cout<<"leap year";
        return true;
    }

    else
        cout<<"not a leap year";
        return false;
}

int main(){
    int days;
    cout<<"Enter number of days: ";
    cin>>days;
    int a = find(days);
    leap_year(a);
    return 0;
}