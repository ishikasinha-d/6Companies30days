class Solution {
public:

    /*
        have to make lower triangular matrix
        i.e for nxn matrix, target is to make a matrix such that
        row 1 will have >=(n-1) trailing zeroes
        row 2 will have >=(n-2) trailing zeroes
        :
        :
        row n-1 will have >=0 trailing zeroes
        
        In other words, if our focus is only trailing zeroes, we can see that
        I/P= [0,1,2]
        Target= [2,1,0]
        So basically we need to sort this array in descending order by swapping adjacent no.s
        this reduces the problem to min adj swaps required to sort array =>swap greedily 	
				
    */
    int minSwaps(vector<vector<int>>& grid) {
       
        int n= grid.size(), min_swaps=0, i, j;
        int arr[n];
        
        // getting list of trailing zeroes
        for(i=0; i<n; i++)
        {
            int trailing_zeroes=0;
            for(int j=n-1; j>=0 && grid[i][j]!=1; j--)
            {
                if(grid[i][j]==0)
                    trailing_zeroes++;
            }
            arr[i]= trailing_zeroes;
        }
        
        // finding min swaps
        for(i=0; i<n; i++)
        {
            if(arr[i]<n-i-1)
            {
                // greedy approach
                // getting the first row with >=n-1-i zeroes
                for(j=i+1; j<n ; j++)
                {
                    if(arr[j]>=n-i-1)
                        break;
                }
                
                // if we haven't found such a row which we can keep at ith row's place, valid grid isn't possible
                if(j==n)
                    return -1;
                
                // and swapping adjacent rows to bring that row to ith position
                while(j>i)
                {
                    swap(arr[j-1], arr[j]);
                    j--;
                    min_swaps++;
                }
                
            }
        }
        
        return min_swaps;
    }
};