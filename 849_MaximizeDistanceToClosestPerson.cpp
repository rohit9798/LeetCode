In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.




class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int front = -1, back = 0;
        int distance = 0;
        while(back < seats.size())
        {
            while(back < seats.size() && seats[back] != 1)
                back++;
            if(front == -1)
                distance = max(distance, back);
            else if(back == seats.size())
                distance = max(distance, back - 1 - front);
            else
                distance = max(distance, ((front + back) / 2) - front);
            front = back;
            back++;
        }
        return distance;
    }
};
