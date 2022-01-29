class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        /*
        combinatorics:
        m = number of rows 
        n = number of columns
        Down moves = (m – 1)
        Right moves = (n – 1)
        Total moves = Down moves + Right Moves = (m – 1) + (n – 1) 
        therefore no. of ways will be m+n-2 C n-1 i.e (m+n-2)! / (n-1)! (m-1)!
        */
        
        // NCr
        int N= m+n-2;
        int r= m-1;
        double res= 1;
        
        for(int i=1; i<=r; i++)
        {
            res= res*(N-r+i)/i;
        }
        
        return res;
    }
};
