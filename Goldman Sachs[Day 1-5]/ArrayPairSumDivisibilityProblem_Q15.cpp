class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
        // Logic
        // Using hashmap to store frequency of remainders
        // traversing through array elements and checking their remainder for 3 cases
        // case 1: if remainder is 0, then it should have even frequecy as it will form pair with itself
        // case 2: if remainder is k/2, then also it will form pair with itself
        // case 3: otherwise freq of remainder and freq of (k-remainder) must be equal
        // TC: O(n) SC: O(n)
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]%k]++;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            int rem= nums[i]%k;
            
            // case 1 and 2
            if((rem==0 || rem*2==k)) 
                {
                    if (mp[rem]%2!=0)
                        return false;
                    else 
                        continue;
                }
            // case 3
            if( mp[rem]!=mp[k-rem])
                return false;
            
        }
        
        return true;
    }
};
