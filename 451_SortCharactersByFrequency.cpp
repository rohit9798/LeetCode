Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.




class Solution {
public:
    string frequencySort(string s) {
        
        map<char, int>mp;
        multimap<int, char, greater<int>>mp1;
        string res = "";
        int i;
        for( i = 0; i < s.size(); i++ )
        {
            mp[s[i]]++;
        }
        map<char, int>:: iterator itr;
        for( itr = mp.begin(); itr != mp.end(); itr++ )
        {
            mp1.insert({itr -> second, itr -> first} );
        }
        map<int, char>:: iterator itr1;
        for( itr1 = mp1.begin(); itr1 != mp1.end(); itr1++ )
        {
            for( i = 0; i < itr1->first; i++ )
                    res += itr1->second;
        }
        return res;
    }
};
