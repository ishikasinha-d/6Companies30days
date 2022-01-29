class Solution {
public:
    int dp[201][201];
    int solve(int start, int end)
    {
        if(start>=end)
            return 0;
        
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int res= INT_MAX;
        for(int i=start; i<=end; i++)
        {
            int choice= i+ max(solve(i+1, end),solve(start, i-1));
            res= min(res,choice);
        }
        
        return dp[start][end]=res;
    }
    
    int getMoneyAmount(int n) {
        
        if(n==1 || n==2)
            return n-1;
        
        memset(dp, -1, sizeof(dp));      
        return solve(1, n);
    }
    
   
};