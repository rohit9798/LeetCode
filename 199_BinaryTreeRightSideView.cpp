Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
  
  
  
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
    vector<int> rightSideView(TreeNode* root) {
        
        int level = 0, prev = 0;
        queue<pair<TreeNode*, int>> q;
        vector<int> result;
        if(root == NULL)
            return result;
        q.push({root, 0});
        while(q.size() != 0)
        {
            while(q.size() != 0)
            {
                TreeNode* temp = q.front().first;
                int l = q.front().second;
                if(l == level)
                {
                    q.pop();
                    if(temp -> left)
                        q.push({temp -> left, l + 1});
                    if(temp -> right)
                        q.push({temp -> right, l + 1});
                    prev = temp -> val;
                }
                else
                {
                    result.push_back(prev);
                    break;
                }
            }
            level++;
        }
        result.push_back(prev);
        return result; 
    }
};
