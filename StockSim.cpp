// 188. Best Time to Buy and Sell Stock IV
//
// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();

        if(k > len/2)
        	return quickSolve(prices);

        std::vector<vector<int> > dp(k+1,vector<int>(len,0));

        int tempMax;
        for(int i = 1; i <= k ; i++){
        	tempMax = -prices[0];
        	for(int j = 1; j < prices.size(); j++){
        		//I'm selling the stock at prices[j]
        		dp[i][j] = max(dp[i][j-1], prices[j] + tempMax);
        		//If I buy the stock at prices[j] (Profit - cost of j)
        		tempMax = max(tempMax, dp[i-1][j-1] - prices[j]);
        	}
        }
        return dp[k][len-1];
    }

    int quickSolve(std::vector<int> prices){
    	int res;

    	for(int i = 1 ; i < prices.size(); i++){
    		if(prices[i] > prices[i-1])
    			res += prices[i] - prices[i-1];
    	}

    	return res;

    }
};
