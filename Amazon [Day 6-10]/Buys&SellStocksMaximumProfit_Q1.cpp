class Solution {
  public:
    int maxProfit(int K, int n, int prices[]) {
        
        /*
        Observations:
        1 transaction is completed when stock is sold
        atmost K transactions 
        can buy next stock after selling previous stock only 
        
        Approach: Bottom Up
        1. dp[i][!own][k]: represents max profit we can make from day i to N 
                            such that we don't own any stock and have k transactions
        When we don't own any stock, we'll have 2 choices
        a. buy a stock : (-prices[])+dp[i+1][1][k]
        b. don't buy   :  dp[i+1][1][k]
        
        1. dp[i][own][k]: represents max profit we can make from day i to N 
                          such that we own a stock and have k transactions
        When we own any stock, we'll have 2 choices
        a. sell a stock : (prices[])+dp[i+1][0][k-1] 
                          if we have 1 or more transactions left [Transaction Completed]
        b. don't sell   :  dp[i+1][0][k] 
        
        Thus final ans would be value at dp[0][0][K] i.e 
        max profit we can get from day 0 to N such that we don't own 
        any stock now (transaction completed) and have used our K transactions
        
        TC: O(N*K)
        SC: O(N*K)
        */
        
        // we'll use a dp table [days 0 to N-1][choice - own or !own][transactions- 0 to K]
        int dp[n][2][K+1];
        
        //initialization 
        for(int trans=0; trans<=K; trans++)
        {
            //Case 1: when we don't own stock
            //On last day, if we don't own any stock, 
            // we can't have any profit no matter how many transactions are left
            dp[n-1][0][trans]= 0;
            
            // Case 2: when we own stock
            // If we have no transactions left, we can't sell
            // otherwise we can make our profit
            if(trans==0)
                dp[n-1][1][trans]= 0;
            else
                dp[n-1][1][trans]= prices[n-1];
                
        }
        
        // filling rest of the table
        for(int days= n-2; days>=0; days--)
        {
            for(int trans=0; trans<=K; trans++)
            {
                // Case 1: don't own
                dp[days][0][trans]= max( (-prices[days]+dp[days+1][1][trans]), dp[days+1][0][trans]);
                
                // Case 2: own
                if(trans==0)
                    dp[days][1][trans]= max(0,dp[days+1][1][trans]);
                else
                    dp[days][1][trans]= max( prices[days]+dp[days+1][0][trans-1], dp[days+1][1][trans]);
            }
        }
        
        return dp[0][0][K];
    }
};
