Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.



class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int i = start;
        queue<int> q;
        vector<bool> visited(arr.size(), false);
        q.push(i);
        while(q.size() != 0)
        {
            int temp = q.front();
            q.pop();
            if(arr[temp] == 0)
                return true;
            if(visited[temp] == false)
            {
                visited[temp] = true;
                if(temp + arr[temp] < arr.size())
                    q.push(temp + arr[temp]);
                if(temp - arr[temp] >= 0)
                    q.push(temp - arr[temp]);
            }
        }
        return false;
    }
};
