/*
Q.1. Given an array arr[] and an integer k where k is smaller than the size of 
the array, the task is to find the kth smallest element in the given array. 
It is given that all array elements are distinct.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.
Expected Time Complexity: O(n+(max_element) )
Expected Auxiliary Space: O(max_element)
Constraints:
1 <= arr.size <= 10^6
1<= arr[i] <= 10^6
1 <= k <= n
*/

/*
// Solution of question 1:-
// Space Complexity = O(k)

class Solution {
  public:
    // arr : given array
    // l : starting index of the array i.e. 0
    // r : ending index of the array i.e. size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;

        for(int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for(int i = k; i <= r; i++)
        {
            if(arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        int ans = pq.top();
        return ans;
    }
};
*/

/*
Q.2. Given a binary tree. The task is to check whether the given tree follows the 
max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node 
greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the 
function isHeap() which takes the root of Binary Tree as parameter returns 
True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/

/*
// Solution of question 2:-
// Time Complexity = O(n)
// Space Complexity = O(h)

// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {

int countNodes(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(struct Node* root, int index, int cnt)
{
    if(root == NULL)
    {
        return true;
    }
    if(index >= cnt)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);

        return (left && right);
    }
}

bool isMaxOrder(struct Node* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

public:
    bool isHeap(struct Node* tree) {
        
        int index = 0;
        int totalCount = countNodes(tree);
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
*/

/*
Q.3. Given two binary max heaps as arrays, merge the given heaps to form a new 
max heap.

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}

Your Task:  
You don't need to read input or print anything. Your task is to complete the 
function mergeHeaps() which takes the array a[], b[], its size n and m, as 
inputs and return the merged max heap. Since there can be multiple solutions, 
therefore, to check for the correctness of your solution, your answer will be 
checked by the driver code and will return 1 if it is correct, else it returns 0.

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(n + m)

Constraints:
1 <= n, m <= 10^5
1 <= a[i], b[i] <= 2*10^5
 
*/

/*
// Solution of question 3:-

class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if(right < n && arr[largest] < arr[right])
        {
            largest = right;
        }

        if(largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        // merge both arrays
        vector<int> ans;

        for(auto i : a)
        {
            ans.push_back(i);
        }
        for(auto i : b)
        {
            ans.push_back(i);
        }

        // build heap using merged array
        int size = ans.size();
        for(int i = size/2-1; i >= 0; i--)
        {
            heapify(ans, size, i);
        }

        return ans;

    }
};
*/

/*
Q.4. There are given n ropes of different lengths, we need to connect these ropes 
into one rope. The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost. Given array arr contains the lengths of the ropes. 

Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Which makes the array [4, 5, 6]. Cost of
this operation 2 + 3 = 5. 
2) Now connect ropes of lengths 4 and 5.
Which makes the array [9, 6]. Cost of
this operation 4 + 5 = 9.
3) Finally connect the two ropes and all
ropes have connected. Cost of this 
operation 9 + 6 =15
Total cost for connecting all ropes is 5
+ 9 + 15 = 29. This is the optimized cost
for connecting ropes. 
Other ways of connecting ropes would always 
have same or more cost. For example, if we 
connect 4 and 6 first (we get three rope of 3,
2 and 10), then connect 10 and 3 (we get
two rope of 13 and 2). Finally we
connect 13 and 2. Total cost in this way
is 10 + 13 + 15 = 38.
Input: arr[] = [4, 2, 7, 6, 9]
Output: 62 
Explanation: First, connect ropes 4 and 2, which makes
the array [6, 7, 6, 9]. Cost of
this operation 4 + 2 = 6. Next, add ropes 
6 and 6, which results in [12, 7, 9]. 
Cost of this operation 6 + 6 = 12.
Then, add 7 and 9, which makes the array [12,16]. 
Cost of this operation 7 + 9 = 16. And
finally, add these two which gives [28].
Hence, the total cost is 6 + 12 + 16 + 
28 = 62.
 
Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ arr.size() ≤ 200000
1 ≤ arr[i] ≤ 10^6
*/

/*
// Solution of question 4:-
// Time Complexity = O(n*log(n))
// Space Complexity = O(n)

class Solution {
    public:
        long long minCost(long long arr[], long long n)
        {
            priority_queue<long long, vector<long long>, greater<long long> > pq;

            for(int i = 0; i < n; i++)
            {
                pq.push(arr[i]);
            }
            long long cost = 0;
            while(pq.size() > 1)
            {
                long long a = pq.top();
                pq.pop();
                long long b = pq.top();
                pq.pop();

                long long sum = a + b;
                cost += sum;
                pq.push(sum);
            }

            return cost;
        }
}
*/