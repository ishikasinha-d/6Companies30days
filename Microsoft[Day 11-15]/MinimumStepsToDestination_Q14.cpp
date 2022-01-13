class Solution{
public:
    int minSteps(int D){
          /*
        Intuition:
        Put + and - on no.s from such that sum == D
        Also, it doens't matter whether D is +ve or -ve
        because if (x+y)==D then (-x)+(-y)=(-D) and in both cases steps= 2
        
        let 1+2+3+4+...+k= D
        then ans is k
        
        but if 1+2+3+.....+k>D
        so we need to choose some no.s in range [1,k] and make them  -ve
        
        suppose D= 4
        1+2+3=6>4  diff= 6-4= 2   so we need to find no.s whose sum will be (diff/2) so that we can flip their signs
        -1+2+3= 4  
        
        but here the diff was even, lets see a case where diff is odd
        D= 5
        1+2+3= 6-5= 1->odd and k=3
        if we negate any of these numbers, sum<D
        lets add one more no. 1+2+3+4= 10 diff= 5 , it still isn't working
        adding one more no.   1+2+3+4+5= 15 diff= 10   diff/2= 5 which we have in our list ....ans would be 5
        
        if D = 7
        1+2+3+4= 10-7 = 3 odd
        1+2+3+4+5= 15-7= 8 even   8/2= 4 therefore ans= 4
        
        TC: O(D)
        SC: O(1)
        
        */
        
        int steps=0, sum=0;
        
        while(sum<D)
        {
            steps++;
            sum+= steps;
        }
        
        if(sum==D)
            return steps;
        else
        {
            int diff= sum-D;
            
            //even diff
            if(diff%2==0)
                return steps;
            else
            {
                steps++;
                diff+= steps;
                
                // if diff is now even
                if(diff%2==0)
                    return steps;
                //if diff still remains odd, adding one more step will definitely make it even 
                else
                    return steps+1;
                
                
            }
        }
        return 0;
    }
};