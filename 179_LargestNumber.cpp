Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.


class Solution {
public:
        string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), [this] (long long i, long long j){
        string a = to_string(i);
        string b = to_string(j);
        string result1 = a + b;
        string result2 = b + a;
        return stoll(result1) > stoll(result2);
    }); 
        int flag = 0;
        string result = "";
        for(int i = 0; i < nums.size(); i++)
        {
            if(flag == 0 && nums[i] == 0)
                continue;
            result = result + to_string(nums[i]);
            flag = 1;
        }
        if(flag == 0)
            result = "0";
        return result;
    }
};
