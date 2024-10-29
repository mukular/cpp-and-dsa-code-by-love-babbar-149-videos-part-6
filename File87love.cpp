// Trie

#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for(int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie()
        {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                root->isTerminal = true;
                return;
            }

            // assumption, word will be capital 
            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insertUtil(child, word.substr(1));

        }

        // Time Complexity = O(l) where l is length of word
        // insert a word in trie
        void insertWord(string word)
        {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;
            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        // Time Complexity = O(l) where l is length of word
        // search a word in trie
        bool searchWord(string word)
        {
            return searchUtil(root, word);
        }

        // Returns true if there is any word in the trie that starts with the 
        // given prefix
        bool prefixUtil(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                return true;
            }

            int index = word[0] - 'A';
            TrieNode* child;
            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                return false;
            }

            return prefixUtil(child, word.substr(1));
        }

        bool startsWith(string prefix)
        {
            return prefixUtil(root, prefix);
        }



};

int main()
{
    Trie *t = new Trie();
    t->insertWord("MUKUL");
    t->insertWord("JASMINE");
    t->insertWord("RIYANSHI");
    t->insertWord("PREM");

    cout<<"Present or Not "<<t->searchWord("RIYA")<<endl;
    cout<<"Present or Not "<<t->searchWord("MUKUL")<<endl;
    cout<<"Present or Not "<<t->searchWord("MUKULGARG")<<endl;
    cout<<"Present or Not "<<t->searchWord("RITIKA")<<endl;
    cout<<"Present or Not "<<t->searchWord("RIYANSHI")<<endl;
    cout<<"Present or Not "<<t->startsWith("RIYANSHI")<<endl;
    cout<<"Present or Not "<<t->startsWith("RIY")<<endl;
    cout<<"Present or Not "<<t->startsWith("MUK")<<endl;
    cout<<"Present or Not "<<t->startsWith("PREMA")<<endl;
    
    return 0;
}