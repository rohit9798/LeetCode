Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"




class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int low = 0, high = letters.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(low < 0 || high < 0)
                return letters[0];
            if(letters[mid] <= target && letters[(mid + 1) % letters.size()] > target)
                return letters[(mid + 1) % letters.size()];
            else if(letters[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return letters[0];
    }
};
