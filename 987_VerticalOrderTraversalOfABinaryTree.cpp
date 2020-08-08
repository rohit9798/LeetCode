Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

 

Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.



class Solution {
public:
    void traverse(TreeNode *root, map<pair<int, int>, vector<int>> &m, int hd, int level)
    {
        if(root == NULL)
            return;
        m[{hd, level}].push_back(root -> val);
        level = level + 1;
        traverse(root -> left, m, hd - 1, level);
        traverse(root -> right, m, hd + 1, level);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        map<pair<int, int>, vector<int>> m;
        int hd = 0, level = 0;
        traverse(root, m, hd, level);
        map<pair<int, int>, vector<int>> :: iterator itr = m.begin();
        while(itr != m.end())
        {
            int key = itr -> first.first;
            cout<<key;
            vector<int> temp2;
            while(itr != m.end() && key == itr -> first.first)
            {
                
                vector<int> temp;
                for(int i = 0; i < itr -> second.size(); i++)
                {
                    temp.push_back(itr -> second[i]);
                }
                sort(temp.begin(), temp.end());
                temp2.insert(temp2.end(), temp.begin(), temp.end());
                itr++;
                cout<<itr -> first.first;
            }
            result.push_back(temp2);
        }
        return result;
    }
};
