class Solution {
public:
 /*
	    X-> choses left + 
	    if Y choses right recur for (i+1,j-1) 
	    if Y choses left  recur for(i+2, j) 
	  or 
	    X->choses right +
	    if Y choses right recur for (i,j-2) 
	    if Y choses left  recur for(i+1, j-1) 
	    
	    return max(ch1, ch2)
	    
	    Since Y is playing optimally,
	    he will try to minimize the X's coins, 
	    i.e., the Y will make a choice that will leave X with minimum coins.

        TC: O(n^2)
	    SC: O(n^2)
	    */
	    
    int dp[501][501];
    int solve(int i, int j, vector<int>&A)
    {
        // one pot left
        if(i==j)
            return A[i];
        
        // two pots left
        if(j-i==1)
            return max(A[i], A[j]);
            
        if(dp[i][j]==-1)
        {
            int ch1= A[i]+ min(solve(i+1, j-1, A), solve(i+2, j, A));
            int ch2= A[j]+ min(solve(i+1, j-1, A), solve(i, j-2, A));
            dp[i][j]= max(ch1, ch2);
        }
        return dp[i][j];
        
    }
    int maxCoins(vector<int>&A,int n)
    {
        memset(dp, -1, sizeof(dp));
	    return solve(0, n-1, A);
    }
};