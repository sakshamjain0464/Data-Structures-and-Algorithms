#include <iostream>
using namespace std;

class Array
{
    int arr[10];
    int len;
    static int size;

public:
    Array()
    {
        cout << "How many elements do you want to enter : ";
        cin >> len;
        for (int i = 0; i < len; i++)
        {
            cout << "Element " << i + 1 << " : ";
            cin >> arr[i];
        }
    }

    void insertion_sort(){
        for(int i =1; i<len; i++){
            int temp = arr[i];
            int j = i-1;
            while(arr[j] > temp && j>=0){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
        cout<<"Array Sorted!!"<<endl;
    }

    void display()
    {
        for (int i = 0; i < len; i++)
        {
            cout << "Element " << i + 1 << " : " << arr[i] << endl;
        }
    }
};

int Array::size = 10;

int main()
{
    Array a;
    a.insertion_sort();
    a.display();
}