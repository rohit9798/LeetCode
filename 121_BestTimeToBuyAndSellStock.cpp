Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
             
             
             
             
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minimum = 0;
        int maximum = 1;
        int current = INT_MIN;
        while(minimum < prices.size() && maximum < prices.size())
        {
            if(prices[minimum] >= prices[maximum])
            {
                minimum = maximum;
                maximum++;
            }
            else if(current < prices[maximum] - prices[minimum])
            {
                current = prices[maximum] - prices[minimum];
                maximum++;
            }
            else
                maximum++;
        }
        if(current == INT_MIN)
            return 0;
        return current;
    }
};
