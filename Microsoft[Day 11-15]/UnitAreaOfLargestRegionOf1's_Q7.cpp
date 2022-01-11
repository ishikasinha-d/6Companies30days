class Solution
{
    public:
    
    void region(vector<vector<int>>& grid, int m, int n, int i, int j, int &area)
    {
        // checking if coordinates is out of bounds or value is 0
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
            return;
        
        //else we'll mark region of 1 visited by changing it to 0
        //and apply dfs on all 8 directions
        grid[i][j]= 0;
        area++;
        
        region(grid,m,n,i,j-1,area); //left
        region(grid,m,n,i,j+1,area); //right
        region(grid,m,n,i-1,j,area); //top
        region(grid,m,n,i+1,j,area); //bottom
        
        region(grid,m,n,i-1,j-1,area); //top left
        region(grid,m,n,i-1,j+1,area); //top right
        region(grid,m,n,i+1,j-1,area); //bottom left
        region(grid,m,n,i+1,j+1,area); //bottom right
    
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        /*
            Logic:
            Traverse the array, whenever 1 is encountered, 
            we can do DFS and visit the 1's connected to the 1 while marking it visited
        */
        
        int m= grid.size(), n= grid[0].size(), max_area=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    int area=0;
                    region(grid,m,n,i,j,area);
                    max_area= max(max_area, area);
                }
            }
        }
        return max_area;
    }
};