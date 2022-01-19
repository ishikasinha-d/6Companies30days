/*
    Approach 1: Find LCS (Longest Commonn Subsequence)
                insertions= length of A- LCS
                deletions = length of B- LCS
                
                TC: O(N*M) and N<=1e5 so TLE
    
    Approach 2: Using th property that array B is sorted and have distinct elements
                We'll make a vector v such that it will be intersection of array A and B
                Longest increasing subsequence(LIS) in vector v will be our LCS which can be found in 
                
                TC: O(N*LogN)
    
 
 */

class Solution {
  public:
    int LIS(vector<int>a)
    {
        int n= a.size();
        
        if(n==0 || n==1)
            return n;
            
        vector<int>lis;
        lis.push_back(a[0]);
        
        for(int i=1; i<n; i++)
        {
            if(lis.back()<a[i])
                lis.push_back(a[i]);
            
            else
            {
                int indx= lower_bound(lis.begin(), lis.end(), a[i])-lis.begin();
                lis[indx]= a[i];
            }
        }
        
        return lis.size();
    }
    
    int minInsAndDel(int A[], int B[], int N, int M) {
        
        vector<int>v;
        map<int,int>mp;
        
        for(int i=0; i<M; i++)
            mp[B[i]]=1;
        
        //finding intersection of A and B
        for(int i=0; i<N; i++)
            if(mp[A[i]])
                v.push_back(A[i]);
        
        int lcs_length= LIS(v);
        int insertions= N- lcs_length;
        int deletions = M- lcs_length;
        
        return insertions+deletions;
    }
};
