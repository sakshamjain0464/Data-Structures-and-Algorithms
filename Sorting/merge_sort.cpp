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

    void merge(int start, int end){
        int mid = start + (end-start)/2;
        int len1 = mid - start+1;
        int len2 = end - mid;

        int *a = new int[len1];
        int *b = new int[len2];

        for(int i = 0; i<len1; i++){
            a[i] = arr[start+i];
        }

        for(int j = 0; j<len2; j++){
            b[j] = arr[mid+1+j];
        }

        int p1 = 0, p2 = 0, p3 = start;
        while(p1<len1 && p2<len2){
            if(a[p1] < b[p2]){
                arr[p3++] = a[p1++];
            }
            else{
                arr[p3++] = b[p2++];
            }
        }

        while(p1 < len1){
            arr[p3++] = a[p1++];
        }

        while(p2 < len2){
            arr[p3++] = b[p2++];
        }

        delete []a;
        delete []b;
    }

    void merge_sort(int start, int end){
        if(start >= end){
            return;
        }

        else{
            int mid = start + (end-start)/2;
            merge_sort(start, mid);
            merge_sort(mid+1, end);

            merge(start, end);
        }
    }
    void display()
    {   cout<<"Element are"<<endl;
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
    a.merge_sort(0,a.len -1);
    a.display();
}