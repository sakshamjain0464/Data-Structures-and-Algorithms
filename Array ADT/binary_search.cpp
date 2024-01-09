#include<iostream>
using namespace std;

int binarySearch(int *arr,int key, int start, int end){
	if(key > arr[end]){
		return -1;
	}
	
	while(start <= end){
		int mid =  start + (end-start)/2;
		if(key == arr[mid]){
			return mid;
		}
		else{
			(key>arr[mid])?start = mid+1: end = mid - 1;
		}
	}
	return -1;
}

int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10}, len = 10;
	int s = binarySearch(arr, 10, 0, len-1);
	(s == -1)?cout<<"Not Found"<<endl:cout<<"Found at "<<s+1<<" Position"<<endl;
	return 0;
}