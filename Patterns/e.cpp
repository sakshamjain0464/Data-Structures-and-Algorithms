 #include<iostream>
 using namespace std;
 int main(){
    int x=121,m,n=0;
       while(x>0){
            m=x%10;
            x=x/10;
            n=(n*10)+m;
            cout<<n;
        }
    
        return 0;
    }