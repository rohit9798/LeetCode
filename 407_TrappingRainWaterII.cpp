Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.


The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.

 



After the rain, water is trapped between the blocks. The total volume of water trapped is 4.



class Solution {
public:
    class cell
    {
        public:
        int height;
        int i, j;
        cell(int ii, int jj, int hh)
        {
            i = ii; j = jj; height = hh;
        }
        bool operator<(const cell &cell2)const{
            
            return height > cell2.height;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        priority_queue<cell> q;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
        {
            cell temp(i, 0, heightMap[i][0]);
            visited[temp.i][temp.j] = true;
            q.push(temp);
            temp.height = heightMap[i][n - 1];
            temp.j = n - 1;
            q.push(temp);
            visited[temp.i][temp.j] = true;
        }
        for(int j = 0; j < n; j++)
        {
            cell temp(0, j, heightMap[0][j]);
            visited[temp.i][temp.j] = true;
            q.push(temp);
            temp.height = heightMap[m - 1][j];
            temp.i = m - 1;
            q.push(temp);
            visited[temp.i][temp.j] = true;
        }
        int height = 0;
        int result = 0;
        while(!q.empty())
        {
            cell temp = q.top();
            height = temp.height;
            q.pop();
            if(temp.i - 1 >= 0 && !visited[temp.i - 1][temp.j])
            {
                result += max(0, height - heightMap[temp.i - 1][temp.j]);
                q.push(cell(temp.i - 1, temp.j, max(heightMap[temp.i - 1][temp.j], height)));
                visited[temp.i - 1][temp.j] = true;
            }
            if(temp.j - 1 >= 0 && !visited[temp.i][temp.j - 1])
            {
                result += max(0, height - heightMap[temp.i][temp.j - 1]);
                q.push(cell(temp.i, temp.j - 1, max(heightMap[temp.i][temp.j - 1], height)));
                visited[temp.i][temp.j - 1] = true;
            }
            if(temp.i + 1 < m && !visited[temp.i + 1][temp.j])
            {
                result += max(0, height - heightMap[temp.i + 1][temp.j]);
                q.push(cell(temp.i + 1, temp.j, max(heightMap[temp.i + 1][temp.j], height)));
                visited[temp.i + 1][temp.j] = true;
            }
            if(temp.j + 1 < n && !visited[temp.i][temp.j + 1])
            {
                result += max(0, height - heightMap[temp.i][temp.j + 1]);
                q.push(cell(temp.i, temp.j + 1, max(heightMap[temp.i][temp.j + 1], height)));
                visited[temp.i][temp.j + 1] = true;
            }
        }
        return result;
    }
};
