class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int n)
    {
        /*
            Case 1: When the order matters
            Since person can climb 1 or 2 stairs at a time
            no. of ways to reach nth stair from n-1th stair= 1 [1]
            no. of ways to reach nth stair from n-2th stair= 2 [1+1] or [2]
            therefore, no. of ways to reach nth stair= (no. of ways to get to n-1) + (no. of ways to get to n-2)
            like ways to reach 3rd stair= ways to reach 2nd stair + ways to reach 1st stair= 2+1= 3 [1+1+1], [1+2], [2+1]
            and ways to reach 4th stair= ways to reach 3rd stair + ways to reach 2nd stair= 3+2= 5 [1+1+1+1],[1+1+2],[1+2+1],[2+1+1],[2+2]
            it is just like fibonaaci series starting with a=1 and b=2
            
            Case 2: When the order doesn't matter 
            some examples
            3rd stair ways= [1 1 1], [1 2] or [2 1]= 2 ways
            4th stair ways= [1 1 1 1], [2 1 1]or[1 2 1]or[1 1 2], [2 2]= 3 ways
            5th stair ways= [1 1 1 1 1], [1 1 1 2]or[1 1 2 1]or[1 2 1 1]or[2 1 1 1], [1 2 2]or[2 1 2]or[2 2 1]= 3 ways
            similarly observing from other examples, we see a pattern is followed
            for ODD value of n: 
            no. of ways when order doesn't matter= n/2+1
            and for EVEN value of n also: 
            no. of ways when order doesn't matter= n/2+1
            
            TC:O(1) SC: O(1)
        */
        
        return (n/2)+1;
    }
};
