#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1,3,2,5,7}, len = 5;
    int k = 3;
    int j = 0;
    while(j<k){
        int last = arr[len-1];
        for(int i = len-1; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = last;
        j++;
    }
    for(int i = 0; i<len; i++){
        cout<<arr[i]<<", "<<endl;
    }
}