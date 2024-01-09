#include <iostream>
using namespace std;

class Array
{   
public:
    int arr[10];
    int len;
    static int size;

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

    int partition(int start, int end){
        int pivot = start;
        int count = 0;
        for(int i = start+1; i<=end; i++){
            if(arr[i] < arr[pivot]){
                count++;
            }
        }

        pivot += count;

        swap(arr[start], arr[pivot]);

        int i = start, j = end;
        while(i<pivot && j>pivot){
            while(arr[i] < arr[pivot]){
                i++;
            }
            while(arr[j]> arr[pivot]){
                j--;
            }

            if(i<pivot && j>pivot){
                swap(arr[i++], arr[j++]);
            }
        }

        return pivot;
    }

    void quick_sort(int start, int end){
        if(start>=end){
            return;
        }
        else{
            int pivot = partition(start, end);
            quick_sort(start, pivot - 1);
            quick_sort(pivot+1, end);
        }
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
    a.quick_sort(0, a.len-1);
    a.display();
}