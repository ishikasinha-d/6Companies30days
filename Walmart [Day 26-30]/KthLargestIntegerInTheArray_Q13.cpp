class Solution {
public:
    
    class mycomp
    {
        public:
        bool operator()(string &a, string &b)
        {
            if(a.size()!=b.size())
                return a.size()>b.size();
            return a>b;
        }
        
    };
    
    bool isGreater(string a, string b)
    {
         if(a.size()!=b.size())
                return a.size()>b.size();
            return a>b;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        // minheap 
        priority_queue<string, vector<string>, mycomp> pq;
        
        for(int i=0; i<k; i++)
            pq.push(nums[i]);
        
        for(int i=k; i<nums.size(); i++)
        {            
            if(isGreater(nums[i],(pq.top())))
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        string ans= pq.top();
        
        return ans;
    }
};