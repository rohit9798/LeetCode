Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.



class Solution {
public:
    void fun(string s, int i, vector<string> &result, string temp)
    {
        while(i < s.size() && !isalpha(s[i]))
        {
            temp = temp + s[i];
            i++;
        }
        if(i == s.size())
        {
            result.push_back(temp);
            return;
        }
        if(isalpha(s[i]))
        {
           
            string temp1 = temp;
            temp = temp + s[i];
            i++;
            fun(s, i, result, temp);
            i--;
            char a;
            if(s[i] >= 'a' && s[i] <= 'z')
                a = s[i] - 32;
            else
                a = s[i] + 32;
            i++;
            temp = temp1 + a;
            fun(s, i, result, temp);
        }
    }
    vector<string> letterCasePermutation(string S) {
        
        vector<string> result;
        string temp = "";
        int i = 0;
        fun(S, i, result, temp);
        return result;
    }
};
