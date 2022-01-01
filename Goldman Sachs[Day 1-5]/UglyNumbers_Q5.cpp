class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    
	    //Applying Dynamic Programming using 3 index pointers
	    ull ugly[n+1];
	    ugly[1]=1;
	    
	    ull idx2=1, idx3=1, idx5=1, count=2;
	    
	    while(count<=n)
	    {
	        //storing the minimum of next 3 possible ugly numbers each time
	        ull val2= ugly[idx2]*2, val3= ugly[idx3]*3, val5= ugly[idx5]*5;
	        ull val= min(val2, min(val3, val5));
	        ugly[count]= val;
	        count++;
	        
	        //updating pointers
            // to handle duplicates like 3*2=6 and 2*3=6
            // since val is equal to val1 & val3 both; idx2 and idx3 both pointers need to be updated 
	        if(val==val2) idx2++;
	        if(val==val3) idx3++;
	        if(val==val5) idx5++;
	    }
	    
	    return ugly[n];
	}
};
