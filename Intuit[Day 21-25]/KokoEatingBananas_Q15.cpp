class Solution {
public:

 /*
	n piles,   guards will come back in h hours
	speed k=> k bananas/hr
	
	[3,6,7,11] 
	total bananas= 27
	if k=1 or 2 or 3 koko eats total 8 or 16 or 24 bananas 
	at h=1  koko eats 1st pile , hrs= ceil(3/4)= 1
	at h=2, 3  koko eats 2nd pile, hrs= ceil(6/4)= 2
	at h=4,5 koko eats 3rd pile, hrs= ceil(7/4)= 2
	at h=6,7,8 koko eats 4th pile, hrs= ceil(11/4)= 3
	
Method 1: set k=1 and increment k while koko isn't able to finish all bananas in hrs<h
	TC: O(n*m) where m is aur min speed
	SC: O(1)
	
	
	Method 2: Binary search
	if k is workable speed then min workable speed would be from 1 to k
	if k is unworkable speed then min workable speed would be from k+1 to max bananas we have in a pile
    when lower and hogher boundaries coincide, we'll get our min speed for koko

    TC: O(n*log m) where m is the min speed 
    SC: O(1)
	
*/
    
    bool check( int k,vector<int>& piles, int h)
    {
        int n=piles.size(), hrs=0;
        for(int i=0; i<n; i++)
        {
            hrs+= (piles[i]/k);
            
            if(piles[i]%k!=0)
                hrs++;
            
            if(hrs>h)
                return false;
        }
        
        if(hrs<=h)
            return true;
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n= piles.size(), low=1, high= INT_MIN;
        
        for(int i=0; i<n; i++)
            high= max(high, piles[i]);
        
        while(low<high)
        {
            int mid= low+(high-low)/2;
            
            // checking is this is workable speed for koko
            bool workable= check(mid, piles, h);
            
            if(workable)
                high= mid;
            else
                low= mid+1;      
        }
       
        return low; 
    }
};