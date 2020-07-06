Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6




class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size() == 0)
            return 0;
        int x = 0, y = 0, temp_x = 0, temp_y = 0;
        int maximum = 0;
        int flag = 0;
        map<long double, int> m;
        for(int i = 0; i < points.size(); i++)
        {
            x = points[i][0];
            y = points[i][1];
            flag = 0;
            for(int j = 0; j < points.size(); j++)
            {
                temp_x = points[j][0];
                temp_y = points[j][1];
                if(j != i)
                {
                    if(temp_x == x && temp_y == y)
                        flag++;
                    else if(temp_x - x == 0)
                        m[INT_MAX]++;
                    else
                        m[(long double)(temp_y - y) / (temp_x - x)]++;
                }
            }
            if(maximum < flag)
                maximum = flag;
            map<long double, int> :: iterator itr = m.begin();
            while(itr != m.end())
            {
                if(itr -> second + flag > maximum)
                    maximum = itr -> second + flag;
                itr++;
            }
            m.clear();
            cout<<flag<<" "<<maximum<<" ";
        }
        return maximum + 1;
    }
};
