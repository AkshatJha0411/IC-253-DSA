#include <bits/stdc++.h>
using namespace std;
int comparisons = 0, swaps = 0;
void merge(vector<int> &arr,int l,int mid,int h){
    vector<int> t;
    int c1=l;
    int c2=mid+1;
    while(c1<=mid && c2<=h){
        comparisons++;
        if(arr[c1]<=arr[c2]){
            t.emplace_back(arr[c1++]);
        }
        else {
            t.emplace_back(arr[c2++]);
        }
        swaps++;
    }
    while (c1<=mid){t.emplace_back(arr[c1++]);swaps++;}
    while (c2<=h){t.emplace_back(arr[c2++]);swaps++;}
    
    for(int i=0;i<t.size();i++ ){
        arr[l+i]= t[i];
    }
}

void mergeSort(vector<int> &arr,int l, int h){
    if(l>=h) return;
    int mid = (l+h)/2;
    mergeSort(arr,l, mid);
    mergeSort(arr,mid+1,h);
    merge(arr,l,mid,h);

}


int main(){
    vector<int> hello = {1,4,3,2,8,5};
    mergeSort(hello,0,hello.size()-1);
    for (int i = 0; i<hello.size();i++){
        cout<<hello[i];
        cout<<endl;
    }
    cout<<endl;
    cout<<comparisons<<endl;
    cout<<swaps<<endl;
    return 0;
}