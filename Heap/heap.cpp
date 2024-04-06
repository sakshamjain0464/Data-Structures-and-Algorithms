#include<bits/stdc++.h>

using namespace std;

class heap{
    public:
    vector<int> h;
    int size;

    heap(){
        size = 0;
        h.push_back(-1);
    }

    void print(){
        for(auto i : h){
            cout<<i<<", ";
        }
        cout<<endl;
    }

    void createHeap(vector<int> arr){
        h = arr;
        size = arr.size()-1;

        for(int i = size/2; i > 0; i--){
            heapify(i);
        }        

        print();
    }

    void heapify(int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left <= size && h[left] > h[largest]){
            largest = left;
        }

        if(right <= size && h[right] > h[largest]){
            largest = right;
        }

        if(largest != i){
            swap(h[i], h[largest]);
            heapify(largest);
        }
    }

    void push(int n){
        h.push_back(n);
        size++;
        
        int i = size;

        while(i > 1){
            int parent = i/2;

            if(h[parent] < h[i]){
                swap(h[parent], h[i]);
                i = parent;
            }
        }
    }

    int pop(){
        swap(h[size], h[1]);
        int deleted = h.back();
        h.pop_back();
        size--;

        int i = 1;
        while(i < size){
            int left = 2*i;
            int right = 2*i+1;

            if(left < size && h[left] > h[i]){
                swap(h[left], h[i]);
                i = left;
            }
            else if(right < size && h[right] > h[i]){
                i = right;
            }
            else{
                break;
            }
        }

        return deleted;
    }

    void heapSort(){
        int n = size;

        while(size > 0){
            swap(h[size], h[1]);

            size--;

            heapify(1); 
        }

        size = n;
    }

};

int main(){

    heap h1;

    vector<int> arr = {-1,54,53,55,52,50};

    h1.createHeap(arr);

    h1.print();

    // h1.print();

    // h1.push(1);
    // h1.push(2);
    // h1.push(3);
    // h1.push(4);
    // h1.push(5);

    // h1.print();

    // int del = h1.pop();

    h1.heapSort();

    h1.print();

    return 0;
}