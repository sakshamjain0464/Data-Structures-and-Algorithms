#include<iostream>
using namespace std;

class Array{
    public:
    int arr[100];
    int length;
    static int size;
    Array(){
        cout<<"Enter the length of array : ";
        cin>>length;
        cout<<"Enter Array Elemants:"<<endl;
        for(int i = 0; i<length; i++){
            cout<<"Enter "<<i+1<<" element : ";
            cin>>arr[i];
        }
    }

    int remove(int index){
        if(index >= length){
            cout<<"invalid index"<<endl;
        }
        else{
            arr[index] = 0;
            for(int i = index; i<length-1; i++){
                arr[i] = arr[i+1];
            }
            length--;
        }
    }

    int display(){
        cout<<"Displaying Elements: "<<endl;
        for(int i = 0; i<length; i++){
            cout<<"Element "<<i+1<<": "<<arr[i]<<endl;
        }
    }
};

int Array::size = 100;

int main(){
    Array a;
    int place;
    cout<<"Enter Place to remove : ";
    cin>>place;
    a.remove(place-1);
    a.display();
}