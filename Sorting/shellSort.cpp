#include<iostream>
using namespace std;

int main(){
	int len;
	cout<<"Enter Size of array";
	cin>>len;
	int *a = new int[len];
	for(int i = 0; i<len; i++){
		cin>>a[i];
	}
	int gap = len/2;
	while(gap > 0){
		bool swapped = false;
		int i = 0, j = gap;
		while(j<len){
			if(a[i] > a[j]){
				swap(a[i], a[j]);
				swapped = true;
			}
			i++; 
			j++;
		}
		if(swapped == false){
			gap /=2;
		}
	}
	
	cout<<"Sorted"<<endl;
	for(int i = 0; i<len; i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
