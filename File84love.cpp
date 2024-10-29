/*
Q.1. You are given ‘K’ lists containing non-negative integers. Each list has a 
size ‘N’ and is sorted in non-decreasing order. You need to find the minimum 
length of a range such that at least one element of each list must be included 
in that range.

For example :

If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is 
the range that includes 1 from the first list, 2,3 from the second list, and 
5 from the third list i.e, this range contains at least one element from each list.

Constraints :
1 <= 'T' <= 50
1 <= 'N' <= 10 ^ 4  
1 <= 'K' <= 10 ^ 4  
1 <= 'N' * 'K' <= 10 ^ 4
1 <= 'VAL' <= 10 ^ 9

Where 'VAL' is the value of any element of any list.

Time Limit: 1 sec
Sample Input 1 :
2
3 2
2 4 5
5 6 7
2 3
1 1
9 12
4 9
Sample Output 1 :
1
9
Explanation For Sample Input 1 :
Test case 1 :
The given list are [2, 4, 5], [5, 6, 7]. The range [5, 5] will include 5 
which is present in both the list and hence the length of this range is 1. 
This is the only possible range having the minimum length.

Test case 2 :
The given list are [1, 1], [9, 12], [4, 9]. The range [1, 9] will include 1 
which is present in the first list, and 9 which include in both the second and 
third list  The length of the range is 9 (9 - 1 + 1 = 9).
Sample Input 2 :
2
3 3
4 7 30
1 2 12
20 40 50
5 1
3 6 8 12 31
Sample Output 2 :
14
1
Explanation For Sample Input 2 :
Test case 1 :
The given list are [4, 7, 30], [1, 2, 12] and [20, 40, 50]. The range [7, 20], 
hence the length of this range is 14. This is the only possible range having the minimum length.

Test case 2 :
The range [3, 3] will include 3 which is present in the first list. 
The length of the range is 1. Infect, we can select any of element present in 
first list as there is only one list given to us.
*/

/*
// Solution of question 1:-

class node{
    public:
        int data;
        int row;
        int col;

        node(int d, int r, int c)
        {
            data = d;
            row = r;
            col = c;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b)
        {
            return a->data > b->data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare > minHeap;

    for(int i = 0; i < k; i++)
    {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;
    while(!minHeap.empty())
    {
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;
        if(maxi - mini < end -start)
        {
            start = mini;
            end = maxi;
        }

        if(temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col+1));
        }
        else
        {
            break;
        }
    }

    return (end - start + 1);

}
*/

/*
Q.2. Given that integers are read from a data stream. Your task is to find the 
median of the elements read so far.
Median is the middle value in an ordered integer list. If the size of the list 
is even there is no middle value. So the median is the floor of the average of 
the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.

Constraints :
1 <= T <= 10
1 <= N <= 10^4
0 <= data <= 10^8
Where T is the number of test cases, N is the number of elements in the data stream.

Time Limit : 1 sec
Sample Input 1:
3
3
1 2 3 
2
9 9 
1
4 
Sample Output 1:
1 1 2
9 9 
4 
Explanation for Sample Input 1:
For test case 1 
After reading first element of stream , Median of [1] is 1 
After reading second element of stream, Median of [1, 2]  = floor((1+2)/2)  = 1
After reading third element of stream, Median of [1,2,3] = 2
So the output will be 1 1 2.
Sample Input 2:
2
3
5 3 8
2
3 8
Sample Output 2:
5 4 5
3 5
Explanation for Sample Input 2:
For test case 1 
After reading first element of stream, Median of [5] is 5
After reading second element of stream, Median of [5, 3]  = floor((5+3)/2)  = 4
After reading third element of stream, Median of [5,3,8] = 5 , it is the middle value of the sorted array
So the output will be 5 4 5.
*/

/*
// Solution of question 2:-
// Time Complexity = O(n*log(n))

int signum(int a, int b)
{
    if(a == b)
    {
        return 0;
    }
    else if(a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int> > &mini, int &median)
{
    switch(signum(maxi.size(), mini.size()))
    {
        case 0: if(element > median)
                {
                    mini.push(element);
                    median = mini.top();
                }
                else
                {
                    maxi.push(element);
                    median = maxi.top();
                }
                break;
        case 1: if(element > median)
                {
                    mini.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                else
                {
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = (mini.top() + maxi.top())/2; 
                }
                break;
        case -1: if(element > median)
                {
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                else
                {
                    maxi.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){

    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;
    int median = 0;
    for(int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }

    return ans;
}

*/