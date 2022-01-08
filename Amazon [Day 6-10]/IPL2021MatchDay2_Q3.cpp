class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        /*
        Approach 1: find all subarrays of size K using left and right pointer and find max O(n2)
        Approach 2: use 2 pointers and maintain a map to store frequecy of values from l to r
                    before we do l++, if we find arr[l] in map, we do mp[l]--
                    since map is sorted, we add the last key in aur ans vector
                    O(nlogn)
        Approach 3: using maxheap
        Approach 4: Use dequeue  
                    There will be n-k+1 windows of size k
                    for each window, 
                    a. remove elements which are not part of the current window from front
                    b. remove elements from rear in deque which are <= ith element
                    c. push index i at back
                    d. front will be max element of the current window
                    Store index of elements and not the elements itself to avoid problems due to duplicacy
                    TC: O(n)  SC: O(n)
        */
        
        vector<int> ans;
        deque<int> Q;
        
        // 1st window
        for(int i=0; i<k; i++)
        {
            while(!Q.empty() && arr[Q.back()]<=arr[i])
                Q.pop_back();
            Q.push_back(i);
        }
        
        // pushing max element of 1st window of size k
        ans.push_back(arr[Q.front()]);
        
        // processing rest subarrays
        for(int i=k; i<n; i++)
        {
            // the new window will be from i-k+1 till i
            // removing elements belonging to previous window
            while(!Q.empty() && Q.front()<i-k+1)
                Q.pop_front();
                
            // removing all previous elements smaller or equal to current element
            while(!Q.empty() && arr[Q.back()]<=arr[i])
                Q.pop_back();
            
            Q.push_back(i);
            
            // pushing max element of the current window
            ans.push_back(arr[Q.front()]);
        }
    
    return ans;
    }
};