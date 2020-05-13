Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]



class Solution {
public:
    
    void combine(vector<string> &result, string &temp, int count1, int count2, int n)
    {
        if(count1 == n && count2 == n)
            result.push_back(temp);
        string temp1 = temp;
        if(count1 < n)
        {
            temp = temp + '(';
            combine(result, temp, count1 + 1, count2, n);
            temp = temp1; 
        }
        if(count2 < count1)
        {
            temp = temp + ')';
            combine(result, temp, count1, count2 + 1, n);
            temp = temp1;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        string temp = "";
        int count1 = n, count2 = n;
        combine(result, temp, 0, 0, n);
        return result;
    }
};
