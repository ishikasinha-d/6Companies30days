class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        /*
            mountain= first increase then decrease; min length should be 3 and we want longest mountain
            therefore, a. its not possible for mountain to start after the peak  
                       b. next mountain starts only after previous one is over else overlapping can occur 
                        giving us smaller mountains which we don't need
            2 pointers start and end can be used
            if a mountain is from i to j peaking at some point between i and j,  then next mountain will be from j to k
            however if sequence ends at peak and there is no decreasing sequence OR 
            sequence starts decreasing from peak and there is no increasing sequence
            it won't be considered a mountain and we'll simply start next mountain from end+1
                TC: O(n)  SC: O(1)
        */
        
        int n= arr.size();
        int start=0, ans=0;
        
        while(start<n)
        {
            int end= start;
            int desc=0, asc=0;
            //reaching the peak
            while(end+1<n && arr[end+1]>arr[end])
            {  
                end++;
                asc=1;
            }
            
            //now descending from the peak
            while(end+1<n && arr[end]>arr[end+1])
            {
                end++;
                desc=1;
            }
            
            int mountain_len= end-start+1;
            if(mountain_len!=1 && asc==1 && desc==1)
                ans= max(ans, mountain_len);
            
            // next mountain will start from end of the previous
            if(desc)
                start= end;
            else
                start= end+1;
        }
        
        return ans;
    }
};