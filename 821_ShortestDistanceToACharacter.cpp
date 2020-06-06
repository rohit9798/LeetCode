Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 
 
 
 
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        
        vector<int> store, result;
        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] == C)
                store.push_back(i);
        }
        int index = 0;
        for(int i = 0; i < S.length(); i++)
        {
            if(index == 0)
                result.push_back(store[index] - i);
            else if(index < store.size())
                result.push_back(min(store[index] - i, i - store[index - 1]));
            else
                result.push_back(i - store[index - 1]);
            if(S[i] == C)
                index++;
        }
        return result;
    }
};
