// AAA
// BBB
// CCC
#include <iostream>
using namespace std;
int main(){
    int i,j,n,ch=65;
    cin>>n;
    for(i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            cout<<char(ch+j-1)<<" ";
        }
        cout<<endl;
       ch=ch+j-1; 
    }
    return 0;
}