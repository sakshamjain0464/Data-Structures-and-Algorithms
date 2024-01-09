#include<iostream>
using namespace std;
int main(){
    long int n, sum=0, i;
    cin>>n;
    for(i=1; i<=n; i++){
        sum+=i;
    }
    cout<<sum;
}
