// HashMaps

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;

    // insertion

    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    m["mukul"] = 1;
    m["mukul"] = 2;

    // search
    cout<<m["mukul"]<<endl;
    cout<<m.at("babbar")<<endl;
    // cout<<m.at("unknown")<<endl;  // gives error because no entry
    cout<<m["unknown"]<<endl;   // m["unknown"] makes an entry 0 corresponding to "unknown"
    cout<<m.at("unknown")<<endl;

    // size
    cout<<m.size()<<endl;

    // to check presence
    cout<<m.count("bro")<<endl;
    cout<<m.count("love")<<endl;

    // erase
    m.erase("love");
    cout<<m.size()<<endl;

    for(auto i : m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }


    // similarly, there is a map

    return 0;
}


/*
Q.1. Ninja is given an array of integers that contain numbers in random order. 
He needs to write a program to find and return the number which occurs the 
maximum times in the given input. He needs your help to solve this problem.

If two or more elements contend for the maximum frequency, return the element 
which occurs in the array first i.e. whose index is lowest.

For example,

For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.

Constraints:
1 <= T <= 5
1 <= N <= 10000
-10 ^ 3 <= |arr| <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1:
1 
13
2 12 2 11 -12 2 -1 2 2 11 12 2 -6 
Sample Output 1:
2
Explanation of Sample Input 1:
Test case 1:
For the first test case of sample output 1, as we start traveling the array, 
‘2’ has the highest frequency, hence our answer is ‘2’.
Sample Input 2:
2 
3
4 -5 1
4
1 -2 1 -2
Sample Output 2:
4
-2
Explanation of Sample Input 2:
Test case 1:
For the first test case of sample output 2, as all the elements have only 
occurred once, so we will take the first element that has occurred once. 
Therefore our output will be ‘4’.

Test case 2:
-2 has the highest frequency.
*/

/*
// Solution of question 1:-
// Time Complexity = O(n)

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}
*/