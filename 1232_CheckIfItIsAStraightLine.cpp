You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.



class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& A) {
        
        map<pair<int, int>, int> m;
        for(int i = 0; i < A.size() - 1; i++)
        {
            if(A[i][0] - A[i + 1][0] == 0)
                m[{INT_MAX, 0}]++;
            else
            {
                int slope = (double)(A[i][1] - A[i + 1][1]) / (A[i][0] - A[i + 1][0]);
                int c = A[i][1] - slope * A[i][0];
                m[{slope, c}]++;
            }
        }
        if(m.size() == 1)
            return true;
        return false;
    }
};
