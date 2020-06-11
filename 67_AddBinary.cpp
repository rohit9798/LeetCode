Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"



class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.length() - 1, j = b.length() - 1;
        string result = "";
        int carry = 0;
        while(i >= 0 && j >= 0)
        {
            result = to_string(((a[i] - 48) + (b[j] - 48) + carry) % 2) + result;
            carry = ((a[i] - 48) + (b[j] - 48) + carry) / 2;
            i--;
            j--;
        }
        while(i >= 0)
        {
            result = to_string(((a[i] - 48) + carry) % 2) + result;
            carry = ((a[i] - 48) + carry) / 2;
            i--;
        }
        while(j >= 0)
        {
            result = to_string(((b[j] - 48) + carry) % 2) + result;
            carry = ((b[j] - 48) + carry) / 2;
            j--;
        }
        if(carry == 1)
            result = '1' + result;
        return result;
    }
};
