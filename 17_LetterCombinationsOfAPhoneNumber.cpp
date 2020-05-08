Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].



class Solution {
public:
    void produceCombine(vector<string> &sample, string &temp, vector<string> &result, int row, int col)
    {
        if(row == sample.size())
        {
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < sample[row].size(); i++)
        {
            string temp1 = temp;
            temp = temp + sample[row][i];
            produceCombine(sample, temp, result, row + 1, col);
            temp = temp1;
        }
        
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> con, result;
        if(digits.size() == 0)
        {
            return result;
        }
        con.push_back("abc");
        con.push_back("def");
        con.push_back("ghi");
        con.push_back("jkl");
        con.push_back("mno");
        con.push_back("pqrs");
        con.push_back("tuv");
        con.push_back("wxyz");
        
        int row = 0, col = 0, i;
        vector<string> sample;
        string temp = "";
        for(i = 0; i < digits.size(); i++)
            sample.push_back(con[(digits[i] - '0') - 2]);
        produceCombine(sample, temp, result, row, col);
        return result;
    }
};
