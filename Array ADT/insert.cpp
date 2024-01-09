#include<iostream.>
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

    int insert(int index, int value){
        if(length >= size){
            cout<<"Array Full!"<<endl;
        }
        else if(index >= length){
            cout<<"Invalid Index!";
        }
        else{
            for(int i = length; i>index; i--){
                arr[i] = arr[i-1];
            }
            arr[index] = value;
            length++;
            cout<<"Element inserted successfully!"<<endl;
        }
    }

    int display(){
        cout<<"Displaying Elements: ";
        for(int i = 0; i<length; i++){
            cout<<"Element "<<i+1<<": "<<arr[i]<<endl;
        }
    }
};

int Array::size = 100;

int main(){
    Array a;
    int place, value;
    cout<<"Enter Place to insert : ";
    cin>>place;
    cout<<"Enter value to insert : ";
    cin>>value;
    a.insert(place-1, value);
    a.display();
}