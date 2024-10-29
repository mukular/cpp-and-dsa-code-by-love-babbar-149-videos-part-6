/*
Q.1. You are given two balanced binary search trees of integers having ‘N’ and 
‘M’ nodes. You have to merge the two BSTs into a balanced binary search
tree and return the root node to that balanced BST.
A binary search tree (BST) is a binary tree data structure with the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.

• The right subtree of a node contains only nodes with data greater than the node’s data.

• Both the left and right subtrees must also be binary search trees.

 Baki question nhi likha maine
*/

/*
// Solution of question 1(Method 1):-
// Time Complexity = O(M+N)
// Space Complexity = O(M+N)

void inorder(TreeNode<int> *root, vector<int> &in)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size()+b.size());

    int i = 0, j = 0;
    int k = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while(i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }

    while(j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }

    return ans;
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

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergeArray = mergeArrays(bst1, bst2);

    int s = 0, e = mergeArray.size()-1;
    return inorderToBST(s, e, mergeArray);

}
*/

/*
// Solution of question 1(Method 2):-
// Time Complexity = O(M+N)
// Space Complexity = O(h1+h2) where h1 and h2 are heights of bst1 and bst2

void convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int>* &head)
{
    if(root == NULL)
    {
        return NULL;
    }

    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if(head != NULL)
    {
        head->left = root;
    }

    head = root;

    convertIntoSortedDLL(root->left, head);

}

TreeNode<int>* mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head1 = head2->right;  // shayad yaha head2 = head2->right hoga
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }

    }

    while(head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;

}

int countNodes(TreeNode<int> *head)
{
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n)
{
    if(n <= 0 || head == NULL)
    {
        return NULL;
    }

    TreeNode<int> *left = sortedLLToBST(head, n/2);

    TreeNode<int> *root = head;
    root->left = left;

    head = head->next;  // shayad yaha head = head->right hoga
    root->right = sortedLLToBST(head, n-n/2-1);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    TreeNode<int> *head = mergeLinkedList(head1, head2);

    return sortedLLToBST(head, countNodes(head));


}

*/