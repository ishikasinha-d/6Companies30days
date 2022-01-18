class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
                
        int l=0,r=0;
        long long sum=arr[r];
        vector<int> res;
        
        while(l<=r && r<n && l<n)
        {
              while(sum>s && l<n)
                {
                    sum-= arr[l];
                    l++;
                }
            if(sum==s)
                {
                    res={l+1,r+1};
                    return res;
                }
         
            if(r<n)
                {
                    r++;
                    sum+= arr[r];
                }
            
        }
      
        res.push_back(-1);
        
        return res;
    }
};