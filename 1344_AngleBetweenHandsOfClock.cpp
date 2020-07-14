Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

 

Example 1:



Input: hour = 12, minutes = 30
Output: 165
Example 2:



Input: hour = 3, minutes = 30
Output: 75
Example 3:



Input: hour = 3, minutes = 15
Output: 7.5
Example 4:

Input: hour = 4, minutes = 50
Output: 155
Example 5:

Input: hour = 12, minutes = 0
Output: 0



class Solution {
public:
    double angleClock(int hour, int minutes) {
    
        int result = 0;
        double angle_minute = minutes * 6.0;
        double angle_hour = ((hour % 12) * 60 + minutes) * 0.5;
        return min(360 - abs(angle_minute - angle_hour), abs(angle_minute - angle_hour));
        
    }
};
