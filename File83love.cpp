/*
Q.1. Given an array of integers, find the Kth largest sum subarray.
For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest 
sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.

Constraints:-
1 <= T <= 50
1 <= N <= 100
1 <= K <= N*(N+1)/2
-1000 <= ARR[i] <= 1000

Sample Input 1 :
2   // T
3 3   // N K
3 -2 5   // ARR
2 2
4 1
Sample output 1 :
3
4
Explanation of Sample output 1 :
For the first test case, 
Sum of [0, 0] = 3
Sum of [0, 1] = 1
Sum of [0, 2] = 6
Sum of [1, 1] = -2
Sum of [1, 2] = 3
Sum of [2, 2] = 5
All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.

For the second test case, 
Sum of [0, 0] = 4
Sum of [0, 1] = 5
Sum of [1, 1] = 1
All sum of subarrays are {5, 4, 1} where the second largest element is 4.
Sample Input 2 :
2
4 10
5 4 -8 6
3 1
1 2 3
Sample output 2 :
-8
6
Explanation of Sample output 2 :
For the first test case, among the sum of all the subarray, the tenth-largest sum will be -8.

For the second test case, among the sum of all the subarray, the largest sum will be 6.
*/

/*
// Solution of question 1:-
// Space Complexity = O(k)

int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int> > mini;
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[i];
            if(mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if(sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }

    return mini.top();
}
*/

/*
Q.2. You have been given ‘K’ different arrays/lists, which are sorted 
individually (in ascending order). You need to merge all the given arrays/list 
such that the output array/list should be sorted in ascending order.

Constraints :
1 <= T <= 5
1 <= K <= 5
1 <= N <= 20
-10^5 <= DATA <= 10^5

Time Limit: 1 sec 
Sample Input 1:
1
2
3 
3 5 9 
4 
1 2 3 8   
Sample Output 1:
1 2 3 3 5 8 9 
Explanation of Sample Input 1:
After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], 
the output sorted array will be [1, 2, 3, 3, 5, 8, 9].
Sample Input 2:
1
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 2:
0 1 2 5 6 9 45 78 90 100 234
Explanation of Sample Input 2 :
After merging the given arrays/lists [1, 5, 9], [45, 90], [2, 6, 78, 100, 234] 
and [0], the output sorted array will be [0, 1, 2, 5, 6, 9, 45, 78, 90, 100, 234].
*/

/*
// Solution of question 2:-
// Time Complexity = O(n*k*log(k))
// Space Complexity = O(n*k)

#include <bits/stdc++.h> 

class node{
    public:
        int data;
        int i;
        int j;

        node(int data, int row, int col)
        {
            this->data = data;
            i = row;
            j = col;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b)
        {
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;

    for(int i = 0; i < k; i++)
    {
        node* tmp = new node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    while(minHeap.size() > 0)
    {
        node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if(j+1 < kArrays[i].size())
        {
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }

    return ans;

}
*/

/*
Q.3. Given 'k' sorted linked lists, each list is sorted in increasing order. 
You need to merge all these lists into one single sorted list. You need to 
return the head of the final linked list.

For example:
Input:
3
3
4 6 8
3
2 5 7 
2
1 9

Output:
1 2 4 5 6 7 8 9 

Explanation:
First list is: 4 -> 6 -> 8 -> NULL
Second list is: 2 -> 5 -> 7 -> NULL
Third list is: 1 -> 9 -> NULL
The final list would be: 1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL

Sample Input 1:
2
2
2 6 
2
-5 7 
Sample Output 1:
-5 2 6 7
Explanation for input 1:
First list is: 2 -> 6 -> NULL
Second list is: -5 -> 7 -> NULL
The final list would be: -5 -> 2 -> 6 -> 7 -> NULL
Sample Input 2:
2
3
8 9 11 
2
1 2 
Sample output 2:
1 2 8 9 11 
Constraints:
1 <= 'k' <= 10 ^ 3
1 <= 'n' <= 100
-10 ^ 9  <= 'data' <=  10 ^ 9 

where 'n' is the size of the list.
Time limit: 1 sec.
*/

/*
// Solution of question 3:-
// Time Complexity = O(N*log(k)) where N is total number of nodes
// Space Complexity = O(k)

class compare{
    public:
        bool operator()(Node<int>* a, Node<int>* b)
        {
            return a->data > b->data;
        }
}

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
    priority_queue<Node<int>*, vector<Node<int>*>, compare> minHeap;

    int k = listArray.size();
    if(k == 0)
    {
        return NULL;
    }

    for(int i = 0; i < k; i++)
    {
        if(listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while(minHeap.size() > 0)
    {
        Node<int>* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL)
        {
            minHeap.push(top->next);
        }
        if(head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}
*/