There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.



class Solution {
public:
    struct Node
    {
        int data;
        int rank;
        Node *parent;
    
    };
    map<int, Node*> m;
        void makeset(int data)
        {
            Node *node = new Node();
            node -> data = data;
            node -> rank = 0;
            node -> parent = node;
            m[data] = node;
        }
        
        Node *find(Node *node)
        {
            Node* node_parent = node -> parent;
            if(node == node_parent)
                return node_parent;
            node -> parent = find(node_parent);
            return node -> parent;
        }
        void Union(int x, int y)
        {
            Node* temp1 = find(m[x]);
            Node* temp2 = find(m[y]);
            if(temp1 == temp2)
                return;
            if(temp1 -> rank >= temp2 -> rank)
            {
                if(temp1 -> rank == temp2 -> rank)
                    temp1 -> rank += 1;
                temp2 -> parent = temp1;
            }
            else
                temp1 -> parent = temp2;
        }
    int findCircleNum(vector<vector<int>>& M) {
        
        map<Node*, int> mp;
        for(int i = 0; i < M.size(); i++)
            makeset(i);
        for(int i = 0; i < M.size(); i++)
        {
            for(int j = i + 1; j < M[0].size(); j++)
            {
                if(M[i][j] == 1)
                    Union(i, j);
            }
        }
        for(int i = 0; i < M.size(); i++)
        {
            mp[find(m[i])]++;
        }
        return mp.size();
        
    }
};
