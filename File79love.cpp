/*
Q.1. You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. 
Your task is to return the size of the largest subtree of the binary tree which is also a BST.

A binary search tree (BST) is a binary tree data structure which has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.

Sample Input 1 :
2 1 3 -1 -1 -1 -1
Sample Output 1:
3
Explanation for Sample 1:
In the given binary tree, subtree rooted at 2 is a BST and its size is 3.

Sample Input 2 :
50 -1 20 -1 30 -1 40 -1 50 -1 -1
Sample Output 2:
4
Constraints :
1 <= 'N' <= 10^5
0 <= 'data' <= 10^5     

where 'N' is the number of nodes and 'data' denotes the node value of the binary tree nodes.

Time limit: 1 sec
*/

/*
// Solution of question 1:-
// Time Complexity = O(n)

class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(TreeNode<int>* root, int &ans)
{
    if(root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    if(currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;

}

int largestBST(TreeNode<int>* root){   
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
*/