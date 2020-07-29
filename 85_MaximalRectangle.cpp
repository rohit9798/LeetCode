Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6



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
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int result = 0, area = 0, max_area = 0;
        if(matrix.size() == 0)
            return result;
        vector<int> prev(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == '1')
                    prev[j] = prev[j] + 1;
                else
                    prev[j] = 0;
            }
            area = largestRectangleArea(prev);
            cout<<area<<" ";
            if(max_area < area)
                max_area = area;
        }
        return max_area;
    }
};
