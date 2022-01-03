
class Solution {
	
  public:
		
  int CountWays(string s){
	
	/*  
        Logic: using dynamic programming
        when we come to the next digit, either this digit can occur individually or can be appended to the prev digit
        a digit can occur individually only if it is not 0 and the number of ways remain same as we had till previous digit
        a digit can be appended if after appending, no. is in the range [10,26] because 06,09,70 all are considered invalid
        TC: O(n) SC:O(1)
    */
        
        int n= s.length(), mod= 1000000007;
        
        // Base case
        if (n==0 || s[0]=='0')
            return 0;
        if (n==1)
            return 1;
        
        // starting counting ways from second character
        // hence initially, count at prev and prev to prev position will be 1
        int count_prev=1, count_prev2=1, count;
        
        for(int i=1; i<n; i++)
        {
            int d= s[i]-'0';
            int dd= (s[i-1]-'0')*10+d;
            
            count=0;
            if(d>0 && d<=9)
                count= (count+count_prev)%mod;
            if(dd>=10 && dd<=26)
                count= (count+count_prev2)%mod;
            
            count_prev2= count_prev%mod;
            count_prev= count%mod;
        }
        
        return count_prev%mod;
    
	}

};
