Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.



class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        
        int MOD = 100000;
        int hash_pattern = 0;
        int power = 1;
        int repeat = 1;
        if(B.length() >= A.length())
            repeat = ceil(double(B.length()) / A.length());
        string tempA = "";
        for(int i = 0; i < repeat; i++)
            tempA += A;
        int hash_string = 0;
        int k = 0;
        for(k = 0; k < B.length(); k++)
        {
            hash_pattern = (hash_pattern * 31 + B[k]) % MOD;
            hash_string = (hash_string * 31 + tempA[k]) % MOD;
        }
        int temp = hash_string;
        if(hash_pattern < 0)
            hash_pattern += MOD;
        if(hash_string < 0)
            hash_string += MOD;
        if(hash_pattern == hash_string)
        {
            if(tempA.substr(k - B.length(), B.length()) == B)
                return repeat;
        }
        int m = B.length();
        for(int i = 0; i < m - 1; i++)
            power = (power * 31) % MOD;
        for(int i = m; i < tempA.length(); i++)
        {
            hash_string = ((hash_string - (tempA[i - m] * power)) * 31 + tempA[i]) % MOD;
            if(hash_string < 0)
                hash_string = hash_string + MOD;
            if(hash_string == hash_pattern)
            {
                if(tempA.substr(i - m + 1, m) == B)
                    return repeat;
            }
        }
        tempA = tempA + A;
        hash_string = temp;
        for(int i = m; i < tempA.length(); i++)
        {
            hash_string = ((hash_string - (tempA[i - m] * power)) * 31 + tempA[i]) % MOD;
            if(hash_string < 0)
                hash_string += MOD;
            if(hash_string == hash_pattern)
            {
                if(tempA.substr(i - m + 1, m) == B)
                    return repeat + 1;
            }
        }
        return -1;
    }
};
