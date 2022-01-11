class Solution{

    /*
	        Approach:
	        We have to divide the array into two subsets such that their sum S1 and S2 give minimum difference
	        the range of sums we can have is from 0 to sum(array)
	        also, we can't get all sums in that range for example
	        in arr= [1 6 11 5]   sum(arr)= 23 so range of sums= [1,23]
	        however in this range, we can't get sum of any subset equal to 2 or 3 or 4 and so on...
	        So we need to find all sums we can get in this range fow which we can use logic of subset sum problem
	        Also, we need to find half of these numbers as if we get S1, then S2= sum(arr)-S1
	        therefore S2-S1= (sum(arr)-S1)-S1= sum(arr)-2*S1
	        
	        TC: O(n* sum(arr))
	        SC: O(n* sum(arr))
	        
	    */
	    
  public:
  
    vector<int> subsetSum( int n, int arr[], int sum )
    {
        bool dp[n+1][sum+1];
        
        //initialization
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(i==0) dp[i][j]= false;
                if(j==0) dp[i][j]= true;
            }
        }
        
        //filling the rest of the table
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j]= dp[i-1][j];
            }
        }
        
        //storing half of the sums we can get in the range 1 to sum(arr)
        vector<int> v;
        for(int i=0; i<=sum/2; i++)
            if(dp[n][i])
                v.push_back(i);
            
        return v;
        
    }
    
	int minDifference(int arr[], int n)  { 
	    
	    int sum=0;
        for(int i=0; i<n; i++)
            sum+= arr[i];
            
	    vector<int> S1= subsetSum(n, arr, sum);
	    
	    int minDiff= INT_MAX;
	    for(auto x: S1)
	        minDiff= min(minDiff, sum-(2*x));
	    
	    return minDiff;
	} 
};
