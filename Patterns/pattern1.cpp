// 1
// 2 3
// 3 4 5
// 4 5 6 7
// 5 6 7 8 9
#include <iostream>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            cout<<i-j+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}