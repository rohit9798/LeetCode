Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        if(intervals.size() == 0)
            return result;
        if(intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        int start, end, i;
        for(i = 0; i < intervals.size() - 1; i++)
        {
            start = intervals[i][0];
            end = intervals[i][1];
            while(i < intervals.size() - 1 && end >= intervals[i + 1][0])
            {
                end = max(end, intervals[i + 1][1]);
                i++;
            } 
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            result.push_back(temp);
        }
        vector<int> temp;
        if(i == intervals.size() - 1 && end < intervals[i][0] )
        {
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            result.push_back(temp);
        } /**/
        return result;
    }
};
