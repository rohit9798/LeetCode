In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.



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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<pair<TreeNode*, pair<TreeNode*, int>>> q;
        q.push({root, {NULL, 0}});
        int i = 0;
        while(q.size() != 0)
        {
            while(q.size() != 0)
            {
                auto temp = q.front();
                TreeNode* ptr = temp.first;
                int level = temp.second.second;
                TreeNode* parent = temp.second.first;
                if(level == i)
                {
                    if(ptr -> left)
                        q.push({ptr -> left, {ptr, level + 1}});
                    if(ptr -> right)
                        q.push({ptr -> right, {ptr, level + 1}});
                    if(ptr -> val == x || ptr -> val == y)
                    {
                        q.pop();
                        while(q.size() != 0)
                        {
                            auto temp1 = q.front();
                            ptr = temp1.first;
                            if((ptr -> val == x || ptr -> val == y) && (parent != temp1.second.first) && level == temp1.second.second)
                                return true;
                            q.pop();
                        }
                        return false;
                    }
                    q.pop();
                }
                else
                    break;
            }
            i++;
        }
        return true;
    }
};
