Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int max_area = 0, area = 0;
        int i = 0;
        for(i = 0; i < heights.size(); i++)
        {
            if(st.empty())
                st.push(i);
            else if(!st.empty() && heights[i] >= heights[st.top()])
                st.push(i);
            else
            {
                while(!st.empty() && heights[i] < heights[st.top()])
                {
                    int top = st.top();
                    st.pop();
                    if(st.empty())
                        area = heights[top] * i;
                    else
                        area = heights[top] * (i - st.top() - 1);
                    if(max_area < area)
                        max_area = area;
                }
                st.push(i);
            }
        }
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            if(st.empty())
                area = heights[top] * i;
            else
                area = heights[top] * (i - st.top() - 1);
            if(max_area < area)
                max_area = area;
        }
        return max_area;
    }
};
