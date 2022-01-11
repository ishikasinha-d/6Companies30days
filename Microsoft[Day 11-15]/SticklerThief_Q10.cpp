class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        /*
            As the thief can't loot consecutive houses
            1 house-> loot it
            2 houses-> loot max(1st,2nd)
            3 houses-> loot max( 2nd, 1st+3rd) 
            
            using bottom up approach
        */
        
        //base cases
        if (n==1) return arr[0];
        if (n==2) return max(arr[0], arr[1]);
        
        //initialization
        int dp[n];
        dp[0]= arr[0];  
        dp[1]= max(arr[0], arr[1]);
        
        //bottom up
        for(int i=2; i<n; i++)
            dp[i]= max(arr[i]+dp[i-2], dp[i-1]);
            
        return dp[n-1];
    }
};