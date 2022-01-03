class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
    // Logic: Similar to Kadane's algorithm
    // take left and right pointers, keep incrementig right pointer and add array element at that index in current sum
    // while current sum is equal or greater to target
    // keep subtracting array element at left pointer, increment left and update minimum subarray size each time
    // if current sum hasn't reached target even once, return minimum subarray size as 0
    // TC: O(n) SC:O(1)
        
        
        int l=0, r=0, n=nums.size();
        int res= INT_MAX, curr_sum=0;
        
        while(l<=r && r<n)
        {
            curr_sum+= nums[r];
            
            while(curr_sum>=target)
            {
                res= min(res, r-l+1);
                curr_sum = curr_sum-nums[l];
                l++;
            }
            
            r++;
            
        }
        return res!=INT_MAX ? res: 0;
    }
};
