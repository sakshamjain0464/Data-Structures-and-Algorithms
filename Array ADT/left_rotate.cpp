#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int *temp = new int[k];
    for(int i = 0; i<k; i++){
        temp[i] = arr[i];
    }
    for(int i = k; i<n; i++){
        arr[i-k] = arr[i];
    }
    for(int i = 0; i<k; i++){
        arr[n-k+i] = temp[i];
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<", "<<endl;
    }
    return 0;
}