/*
       
       In this problem, we not only need to find optimal cost in MCM but also the break points 
       For matrix Ai, dimensions= p[i-1] x p[i] therefore we need to loop from i=1 to n-1
       We'll use recursion and set i=1 and j=n-1
       and will break at points form k= i to k=j-1 -> fn(i,k) and fn(k+1,j)
       and cost of multiplying A1A2..Ak and Ak+1...Aj = A[i-1]*A[k]*A[j]
       So we'll keep finding cost for each such subproblem as a temp ans and
       return min of all those temp ans as our ans while storing the value in a 
       memoized dp matrix to keep the track of already calculated subproblems
       
       In addition to this, we'll maintain a brackets matrix to store the breaking points
       at which we are getting minimum cost
       then recursively we'll add brackets 
       
       TC: O(n^2)
       SC: O(n^2) 
*/
class Solution{
public:
    
    int dp[27][27];
    int bracket[27][27];
    string str;
    char ch;
    
    void printParenthesis(int i, int j)
    {
            
        	if (i == j){
        		str += ch;
        		ch++;
        		return;
        	}
        	str += '(';
        	printParenthesis(i, bracket[i][j]);
        	printParenthesis(bracket[i][j] + 1, j);
        	str += ')';
    }
    
    int solve( int arr[], int i, int j)
    {
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) 
        {
            return dp[i][j];
        }
        
        int ans= INT_MAX;
        for(int k=i; k<=j-1; k++)
        {
            int temp= solve(arr, i, k)+ solve(arr, k+1, j)+ (arr[i-1]*arr[k]*arr[j]);
            
            if(temp<ans)
            {
                ans= temp;
                bracket[i][j]= k;
            }
        }
        
        dp[i][j]= ans;
        return ans;
    }
    
    string matrixChainOrder(int p[], int n){
       
       memset(dp, -1, sizeof(dp));
       memset(bracket, -1, sizeof(bracket));
       
       int cost= solve(p, 1, n-1);
       
       ch = 'A';
       str="";
       printParenthesis(1, n-1);
       return str; 
       
    }
};