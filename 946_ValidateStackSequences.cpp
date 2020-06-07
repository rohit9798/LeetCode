Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.



class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        if(pushed.size() == 0 && popped.size() == 0)
            return true;
        if(pushed.size() != popped.size())
            return false;
        stack<int> st;
        int i = 0, j = 0;
        while(i < pushed.size())
        {
            cout<<i<<" "<<j<<" ";
            if(pushed[i] == popped[j])
            {
                j++;
            }
            else if(!st.empty() && st.top() == popped[j])
            {
                st.pop();
                i--;
                j++;
            }
            else
            {
                st.push(pushed[i]);
            }
            i++;
        }
        while(!st.empty())
        {
            if(st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            else
                return false;
        }
        return true;
    }
};
