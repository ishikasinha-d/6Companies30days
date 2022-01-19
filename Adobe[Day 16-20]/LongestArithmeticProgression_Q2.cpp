class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        
        /*
        We need to take 2 states into account
        1. difference of all pairs 
        2. if the diff matches with some other pair then it's last value in pair is equal to the the first of next pair
        
        dp[val][diff]->  will contain no. of elements in AP with difference as diff and last value as val
        */
      
        int maxi=2;
        vector<unordered_map<int,int>>dp(n);
        
        if(n<=2)
            return n;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int diff= A[j]-A[i];
                if(dp[i].find(diff)!=dp[i].end())
                    dp[j][diff]= dp[i][diff]+1;
                else
                    dp[j][diff]= 2;
                maxi= max(maxi, dp[j][diff]);
            }
        }
        
        return maxi;
        
    }
};
