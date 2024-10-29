// Heaps
// Heap is a complete binary tree with heap order property
/*
A complete binary tree is a binary tree whose every level is completely filled 
except last level and nodes always added from the left.
*/

/*
Two types of heap property:-
1. Max heap
2. Min heap
*/

// For the max heap, the values of child of a node is less than node's value.
// For the min heap, the values of child of a node is greater than node's value.

#include<iostream>
#include<queue>
using namespace std;

// Max heap

class heap{
    public:
        int arr[100];
        int size;

        heap()
        {
            arr[0] = -1;
            size = 0;
        }

        // Time Complexity of insertion = O(log(n))
        void insert(int val)
        {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1)
            {
                int parent = index/2;
                if(arr[parent] < arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else
                {
                    return;
                }
            }
        }

        void print()
        {
            for(int i = 1; i <= size; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        // deleting max value from heap
        // love babaar ne code thoda galat likh diya tha toh maine comment section se
        // sahi kar liya waha kai comments the iske
        // Time Complexity = O(log(n))
        void deletefromHeap()
        {
            if(size == 0)
            {
                cout<<"Nothing to delete"<<endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            // take root node to correct position
            int i = 1;
            while(i < size)
            {
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;

                if(leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex])
                {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
                else if(rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex])
                {
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }
                else
                {
                    return;
                }
            }
        }

};

// complete binary tree me leaf nodes index (n/2+1) se n tak hoti h 

// Makes an array heap
// Time Complexity = O(log(n))
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// heap sort
// Time Complexity = O(n*log(n))
void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(34);
    h.insert(52);
    h.insert(60);
    h.print();
    h.deletefromHeap();
    h.print();
    h.deletefromHeap();
    h.print();
    h.deletefromHeap();
    h.print();

    int arr[10] = {-1, 34, 12, 67, 24, 66, 12, 90, 23, 12};
    int n = 9;
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout<<"printing the array now "<<endl;
    for(int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, n);
    cout<<"printing the array after heap sort "<<endl;
    for(int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"Using Priority Queue here "<<endl;

    // max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(13);
    pq.push(53);
    pq.push(5);
    cout<<"Element at top "<<pq.top()<<endl;   // gives max element
    pq.pop();
    cout<<"Element at top "<<pq.top()<<endl;
    cout<<"Size is "<<pq.size()<<endl;
    if(pq.empty())
    {
        cout<<"pq is empty "<<endl;
    }
    else
    {
        cout<<"pq is not empty "<<endl;
    }

    // min heap
    priority_queue<int, vector<int>, greater<int> > pq1;
    pq1.push(4);
    pq1.push(2);
    pq1.push(3);
    pq1.push(13);
    pq1.push(53);
    pq1.push(5);
    cout<<"Element at top "<<pq1.top()<<endl;   // gives min element
    pq1.pop();
    pq1.pop();
    cout<<"Element at top "<<pq1.top()<<endl;
    pq1.pop();
    pq1.pop();
    pq1.pop();
    cout<<"Size is "<<pq1.size()<<endl;
    pq1.pop();
    cout<<"Size is "<<pq1.size()<<endl;
    if(pq1.empty())
    {
        cout<<"pq1 is empty "<<endl;
    }
    else
    {
        cout<<"pq1 is not empty "<<endl;
    }
    return 0;
}