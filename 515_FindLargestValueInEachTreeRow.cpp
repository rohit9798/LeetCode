You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> result;
        if(root == NULL)
            return result;
        int maximum = INT_MIN;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int level = 0;
        while(q.size() != 0)
        {
            maximum = INT_MIN;
            while(q.size() != 0)
            {
                TreeNode* temp = q.front().first;
                int l = q.front().second;
                if(level == l)
                {
                    q.pop();
                    if(temp -> val > maximum)
                        maximum = temp -> val;
                    if(temp -> left)
                        q.push({temp -> left, l + 1});
                    if(temp -> right)
                        q.push({temp -> right, l + 1});
                }
                else
                    break;
            }
            result.push_back(maximum);
            level++;
        }
        return result;
    }
};
