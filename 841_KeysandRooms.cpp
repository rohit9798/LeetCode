There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int i = 0;
        int flag[rooms.size()];
        for(int i = 0; i < rooms.size(); i++)
            flag[i] = 0;
        flag[0] = 1;
        vector<int> keys;
        for(int j = 0; j < rooms[0].size(); j++)
            keys.push_back(rooms[0][j]);
        while(keys.size() > 0)
        {
            int i = keys[0];
            for(int j = 0; j < rooms[i].size(); j++)
                if(flag[i] == 0)
                    keys.push_back(rooms[i][j]);
            flag[i] = 1;
            keys.erase(keys.begin());
        }
        for(int j = 0; j < rooms.size(); j++)
            if(flag[j] == 0)
                return false;
        return true;
    }
};
