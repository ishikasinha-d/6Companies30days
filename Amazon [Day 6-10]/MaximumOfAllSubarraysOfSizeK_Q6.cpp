class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        /*
            Approach 1: there are n-k+1 subarrays 
                        loop i=0 to n-k+1
                            loop j=i to j=i+k and find max
                        TC: O(n^2) SC:O(1)
            Approach 2: using deque O(n)
            Approach 3: using priority queue O(n)
        */
        
        vector<int>ans;
        
        // maxheap with pairs of {arr[i],i} so that heap is created w.r.t arr[i]
        // we need indexes to check whether the element belongs to current window 
        priority_queue<pair<int,int>>pq;
        
        // finding max of firest window
        for(int i=0; i<k; i++)
        {
            pq.push({arr[i],i});
        }
        ans.push_back(pq.top().first);
        
        // processing rest of the elements
        for(int i=k; i<n; i++)
        {
            // current window will be from i-k+1  to i
            // we'll remove elements out of this window
            while(!pq.empty() && pq.top().second<i-k+1)
            {
                pq.pop();
            }
            
            pq.push({arr[i],i});
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};