Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"



class Solution {
public:
    string multiply(string num1, string num2) {
        
        int m = num1.size();
        int n = num2.size();
        string result = "";
        int dp[m + n];
        for(int i = 0; i < m + n; i++)
            dp[i] = 0;
        int p1 = 0, p2 = 0, sum = 0, mul = 0;
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                mul = (num1[i] - '0') * (num2[j] - '0');
                p1 = i + j;
                p2 = i + j + 1;
                sum = dp[p2] + mul;
                
                dp[p1] += sum / 10;
                dp[p2] = sum % 10;
            }
        }
        int index = 0;
        while(index < m + n && dp[index] == 0)
            index++;
        if(index == m + n)
            result = "0"; 
        for(int i = index; i < m + n; i++)
            result = result + to_string(dp[i]);
        return result;
    }
};
