/*
Q.1. Question nhi likh raha hu .
Basically question yeh h ki ek tree valid Binary Search Tree h ya nhi 
*/

/*
// Solution of question 1:-
// Time Complexity = O(n) where n is number of nodes
// Space Complexity = O(height of tree)

bool isBST(BinaryTreeNode<int> *root, int min, int max)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}
*/

/*
Q.2. Question nhi likh raha hu.
Basically question yeh h ki find kth smallest element in BST
*/

/*
// Solution of question 2:-
// Time Complexity = O(n) where n is number of nodes
// Space Complexity = O(height of tree)

int solve(BinaryTreeNode<int>* root, int& i, int k)
{
    if(root == NULL)
    {
        return -1;
    }
    int left = solve(root->left, i, k);

    if(left != -1)
    {
        return left;
    }
    i++;
    if(i == k)
    {
        return root->data;
    }

    return solve(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root , int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}
*/

/*
Q.3. You have been given a binary search tree of integers with ‘N’ nodes. 
You are also given 'KEY' which represents data of a node of this tree.
Your task is to return the predecessor and successor of the given node in 
the BST.

Note:
1. The predecessor of a node in BST is that node that will be visited 
just before the given node in the inorder traversal of the tree. If the 
given node is visited first in the inorder traversal, then its predecessor is NULL.

2. The successor of a node in BST is that node that will be visited 
immediately after the given node in the inorder traversal of the tree. 
If the given node is visited last in the inorder traversal, then its successor is NULL.

3. The node for which predecessor and successor are to be found will 
always be present in the given tree.

4. A binary search tree (BST) is a binary tree data structure which has the following properties.
     • The left subtree of a node contains only nodes with data less than the node’s data.
     • The right subtree of a node contains only nodes with data greater than the node’s data.
     • Both the left and right subtrees must also be binary search trees.

Sample Input 1:
15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
10
Sample output 1:
8 12
Explanation of Sample output 1:

The inorder traversal of this tree will be 8 10 12 15 16 20 25.
Since the node with data 8 is on the immediate left of the node with 
data 10 in the inorder traversal, the node with data 8 is the predecessor.
Since the node with data 12 is on the immediate right of the node with 
data 10 in the inorder traversal, the node with data 12 is the successor.
Sample Input 2:
10 5 -1 -1 -1
5
Sample output 2:
-1 10
Constraint :
1 <= N <= 10^4
1 <= data <= 10^7

Time Limit: 1 sec

*/

/*
// Solution of question 3:-
// Time Complexity = O(n)
// Space Complexity = O(1)

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp->data != key)
    {
        if(temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    BinaryTreeNode<int>* rightTree = temp->right;
    while(rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}
*/

/*
Q.4. You are given a binary search tree of integers with N nodes. You are 
also given references to two nodes 'P' and 'Q' from this BST.
Your task is to find the lowest common ancestor(LCA) of these two given nodes.

The lowest common ancestor for two nodes P and Q is defined as the lowest 
node that has both P and Q as descendants (where we allow a node to be a 
descendant of itself)

A binary search tree (BST) is a binary tree data structure which has the 
following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.

For example:
'P' = 1, 'Q' = 3
tree = 2 1 4 -1 -1 3 -1 -1 -1,

Here, we can clearly see that LCA of node 1 and node 3 is 2.

Sample Input 1 :
3 5
2 1 3 -1 -1 -1 5 -1 -1
Sample Output 1:
3
Here, we can clearly see that LCA of node 3 and node 5 is 3.
Sample Input 2 :
1 2
3 2 -1 1 -1 -1 -1
Sample Output 2:
2
Constraints:
1 <= 'N' <= 10^5
1 <= Data <= 10^6

Time Limit: 1sec
*/

/*
// Solution of question 4:-
// Time Complexity = O(n)
// Space Complexity = O(1)

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    while(root != NULL)
    {
        if(root->data < P->data && root->data < Q->data)
        {
            root = root->right;
        }
        else if(root->data > P->data && root->data > Q->data)
        {
            root = root->left;
        }
        else
        {
            return root;
        }

    }
}

*/