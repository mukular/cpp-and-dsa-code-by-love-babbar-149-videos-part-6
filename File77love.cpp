/*
Q.1. You have been given a Binary Search Tree and a target value. You need 
to find out whether there exists a pair of node values in the BST, 
such that their sum is equal to the target value.

A binary search tree (BST), also called an ordered or sorted binary tree, 
is a rooted binary tree whose internal nodes each store a value greater 
than all the values keys in the node's left subtree and less than those 
in its right subtree.

Follow Up:
Can you solve this in O(N) time, and O(H) space complexity?

Constraints:
1 <= T <= 100
1 <= N <= 3000
-10^9 <= node data <= 10^9, (where node data != -1)
-10^9 <= target value <= 10^9

Where N denotes is the number of nodes in the given tree.

Time Limit: 1 second
Sample Input 1:
1
10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
14
Sample Output 1:
True
Explanation for sample 1:
For the first test case, the sum of the nodes with values 2 and 12 equals 
the target value.

Sample Input 2:
1
5 3 7 -1 -1 6 8 -1 -1 -1 -1
20
Sample output 2:
False
Explanation for sample 2:
For the first test case, there is no such pair of nodes, the sum of 
which equals the target value.
*/

/*
// Solution of question 1:-
// Time Complexity = O(n) 

// Following is the Binary Tree node structure

class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inorder(BinaryTreeNode<int>* root, vector<int> &in)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inorderVal;
    inorder(root, inorderVal);

    int i = 0, j = inorderVal.size()-1;

    while(i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];

        if(sum == target)
        {
            return true;
        }
        else if(sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return false;
}

*/

/*
Q.2. You have been given a Binary Search Tree (BST). Your task is to 
flatten the given BST to a sorted list. More formally, you have to make 
a right-skewed BST from the given BST, i.e., the left child of all the 
nodes must be NULL, and the value at the right child must be greater than the current node.

A binary search tree (BST), also called an ordered or sorted binary tree, 
is a rooted binary tree whose internal nodes each store a value greater 
than all the values in the node's left subtree and less than those in its right subtree.

Follow Up :
Can you solve this in O(N) time and O(H)  space complexity?

Constraints :
1 <= T <= 100
1 <= N <= 5000
0 <= node.data <= 10^9, (where node data != -1)

Where 'N' denotes the number of nodes in the given tree.

Time Limit: 1 second
Sample Input 1
2
10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
5 -5 8 -1 -1 -1 -1
Sample Output 1
2 -1 6 -1 8 -1 10 -1 11 -1 12 -1 15 -1 -1
-5 -1 5 -1 8 -1 -1

Sample Input 2
2
5 3 7 -1 -1 6 8 -1 -1 -1 -1
2 1 -1 -1 -1
Sample output 2
3 -1 5 -1 6 -1 7 -1 8 -1 -1
1 -1 2 -1 -1
*/

/*
// Solution of question 2:-
// Time Complexity = O(n)
// Space Complexity = O(n)

Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void inorder(TreeNode<int>* root, vector<int> &in)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);
    int n = inorderVal.size();

    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);

    TreeNode<int>* curr = newRoot;

    for(int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

*/

/*
Q.3. You have been given a binary search tree of integers with ‘N’ nodes. 
Your task is to convert it into a balanced BST with the minimum height possible.

A binary search tree (BST) is a binary tree data structure that has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
A Balanced BST is defined as a BST, in which the height of two subtrees of 
every node differs no more than 1.

Sample Input 1:
1
10 6 -1 4 -1 -1 -1
Sample output 1:
4 6 10
Explanation of Sample output 1:

The inorder traversal of the modified tree will be 4 6 10. Since the 
inorder is sorted. Hence, it is a valid BST. 
Sample Input 2:
2 
10 5 -1 -1 -1
20 -1 -1
Sample output 2:
5 10 
20 
 */

/*
// Solution of question 3:-
// Time Complexity = O(n)

 Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

void inorder(TreeNode<int>* root, vector<int> &in)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &in)
{
    if(s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    
    vector<int> inorderVal;
    inorder(root, inorderVal);

    return inorderToBST(0, inorderVal.size()-1, inorderVal);
}
*/

/*
Q.4. You have been given an array/list 'PREORDER' representing the preorder
traversal of a BST with 'N' nodes. All the elements in the given array 
have distinct values.

Your task is to construct a binary search tree that matches the given 
preorder traversal.

A binary search tree (BST) is a binary tree data structure that has the 
following properties:

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
Note:

It is guaranteed that a BST can be always constructed from the given 
preorder traversal. Hence, the answer will always exist.

Constraints :
1 <= T <= 100
1 <= N <= 5000
0 <= data <= 10^5

Where 'data' denotes data contained in the nodes of the binary search tree.

Time Limit: 1 sec

Sample Input 1:
2
7
15 10 7 13 21 20 25 
3
1 2 4
Sample Output 1:
7 10 13 15 20 21 25
1 2 4
*/

/*
// Solution of question 4:-

Following is the class structure of BinaryTreeNode class for reference:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if(i >= preOrder.size())
    {
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;

}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {

    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);

}
*/