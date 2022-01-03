class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        
        //SLIDING WINDOW APPROACH
        // TC: O(n)
        // AS: O(1)
        
        if (k < 1) return 0;
        
        long long product=1;
        int l=0, r=0, count=0;
        
        while(l<=r && l<n && r<n)
        {
            product*= nums[r];
            
            while( product>=k && l<=r && l<n)
            {
                product/= nums[l];
                l++;
            }
            
            count+= r-l+1;
            r++;
        }
        
        return count;
    }
};
