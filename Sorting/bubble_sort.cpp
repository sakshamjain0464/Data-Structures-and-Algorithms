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

    void bubble_sort()
    {
        int flag = -1, temp = 0;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 0; j < len - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = i;
                }
            }
            if (flag == -1)
            {
                break;
            }
        }
        cout << endl;
        cout << "Array Sorted" << endl;
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
    a.bubble_sort();
    a.display();
}