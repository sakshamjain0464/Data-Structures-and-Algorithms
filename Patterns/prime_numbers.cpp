#include<iostream>
using namespace std;
int main(){
    int n, i=2, check=0;
    cin>>n;
    while(i<n){
        if(n%i==0){
            check++;
            break;
        }
        i++;
    }
    if(check==0){
        cout<<"prime";
    }
    else{
        cout<<"Not prime";
    }
    return 0;
}
