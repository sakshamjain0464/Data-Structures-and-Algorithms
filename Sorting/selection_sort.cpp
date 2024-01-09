#include<iostream>
using namespace std;

int main(){
    int arr[9] = {8,6,3,2,5,4}, len = 6;
    for(int i = 0; i<len-1; i++){
        int minIndex = i;
        for(int j = i; j<len; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for(int k = 0; k<len; k++){
        cout<<arr[k]<<", ";
    }
    return 0;
}