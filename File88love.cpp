/*
Q.1. You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the 
longest common prefix among all these strings. If there is no common prefix, you have to 
return an empty string.

A prefix of a string can be defined as a substring obtained after removing some or all 
characters from the end of the string.

For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix 
in all strings. Hence, the answer is “cod”.

Constraints:
1 <= T <= 10
1 <= N <= 3000
1 <= |ARR[i]| <=1000

Each string consists of only lowercase letters.

Time limit: 1 sec
Sample Input 1:
2
4
coding codezen codingninja coder
3
night ninja nil 
Sample Output 1:
cod
ni
Explanation of sample input 1:
For the first test case, 
The longest common prefix among all the given strings is “cod” as it is present as a prefix 
in all strings. Hence, the answer is “cod”.

For the second test case,
The longest common prefix among all the given strings is “ni” as it is present as a prefix 
in all strings. Hence, the answer is “ni”.
Sample Input 2:
2
3
applejuice applepie apple
4
car cus cart carat
Sample Output 2:
apple
c
*/

/*
// Solution of question 1(Method 1):-
// Time Complexity = O(m*n) where m is length of a string
// Space Complexity = O(m) where m is length of a string

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for(int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];

        bool match = true;

        for(int j = 1; j < n; j++)
        {
            if(arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if(match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }

    return ans;
}
*/

/*
// Solution of question 1(Method 2) :-
// Time Complexity = O(m*n) where m is length of a string
// Space Complexity = O(m*n) where m is length of a string

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for(int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(char ch)
        {
            root = new TrieNode(ch);
        }

        void insertUtil(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                root->isTerminal = true;
                return;
            }

            // assumption, word will be capital 
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            insertUtil(child, word.substr(1));

        }

        void insertWord(string word)
        {
            insertUtil(root, word);
        }

        void lcp(string str, string &ans)
        {
            for(int i = 0; i < str.length(); i++)
            {
                char ch = str[i];

                if(root->childCount == 1)
                {
                    ans.push_back(ch);

                    int index = ch - 'a';
                    root = root->children[index];
                }
                else
                {
                    break;
                }

                if(root->isTerminal)
                {
                    break;
                }
            }
        }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    for(int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    return ans;
}
*/