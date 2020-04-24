Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
       
        vector<double> result;
        if(root == NULL)
            return result;
        queue<pair<TreeNode*, int>> q;
        int index = 0;
        q.push({root, index});
        double sum = 0;
        int count = 0;
        while(!q.empty())
        {
            while(!q.empty())
            {
                TreeNode* ptr = q.front().first;
                int i = q.front().second;
                if(i == index)
                {
                    sum = sum + (ptr -> val);
                    if(ptr -> left)
                        q.push({ptr -> left, index + 1});
                    if(ptr -> right)
                        q.push({ptr -> right, index + 1});
                    q.pop();
                    count++;
                }
                else
                    break;
            }
            index++;
            result.push_back(sum / count);
            count = 0; sum = 0;
            
        }
        return result;
    }
};
