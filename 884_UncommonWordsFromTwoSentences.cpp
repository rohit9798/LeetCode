We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]




class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        
        vector<string> result;
        map<string, int> m;
        string temp = "";
        for(int i = 0; i < A.length(); i++)
        {
            temp = "";
            while(i < A.length() && A[i] != ' ')
            {
                temp = temp + A[i];
                i++;
            }
            m[temp]++;
        }
        for(int i = 0; i < B.length(); i++)
        {
            temp = "";
            while(i < B.length() && B[i] != ' ')
            {
                temp = temp + B[i];
                i++;
            }
            m[temp]++;
        }
        map<string, int> :: iterator itr = m.begin();
        while(itr != m.end())
        {
            if(itr -> second == 1)
                result.push_back(itr -> first);
            itr++;
        }
        return result;
    }
};
