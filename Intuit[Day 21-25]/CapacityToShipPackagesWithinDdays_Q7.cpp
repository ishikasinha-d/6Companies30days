class Solution {
public:
    
    bool isWorkableCapacity(int capacity, vector<int>& weights, int D)
    {
        int days=1, total_weight=0;
        
        for(int i=0; i<weights.size(); i++)
        {
            // if any weight is more than totak ship capacity 
            if(weights[i]>capacity)
                return false;
            
            if(total_weight+weights[i]<=capacity)
                total_weight= total_weight+weights[i];
            else
            {
                total_weight= weights[i];
                days++;
            }
        }
        return days<=D;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
            // binary search
            int low=1, high= 500*50000;
        
        while(low<high)
        {
            int mid= low+(high-low)/2;
            
            if(isWorkableCapacity(mid, weights, days))
                high= mid;
            else
                low= mid+1;
        }
        
        return low;
    }
};