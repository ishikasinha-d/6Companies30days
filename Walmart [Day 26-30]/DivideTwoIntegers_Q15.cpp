class Solution {
public:
    int divide(int dividend, int divisor) 
    {     
        // edge cases
        if(dividend<=INT_MIN && divisor==-1)
            return INT_MAX;
        
        if(dividend<=INT_MIN && divisor==1)
            return INT_MIN;
        
        long a= abs(dividend);
        long b= abs(divisor);
        int res=0;
     
        
        while(a-b>=0)
        {
            int x= 0;  //  2^0= 2
            
            while(a-(b<<1<<x)>=0)
                x++;
            
            res+= 1<<x;
            a-= b<<x;
        }
        
        // XOR means is either of them is -ve
        return (dividend<0 ^ divisor<0) ? -res : res;
    }
};