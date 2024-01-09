#include<iostream>
using namespace std;

void TOH(int n, char A, char B, char C){
    if(n==0) cout<<"Invalid disk number"<<endl;
    else if(n==1) cout<<A<<" -> "<<C<<endl;
    else{
        TOH(n-1, A,C,B);
        TOH(1, A,B,C);
        TOH(n-1, B,A,C);
    }
}

int main(){
    int n;
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}