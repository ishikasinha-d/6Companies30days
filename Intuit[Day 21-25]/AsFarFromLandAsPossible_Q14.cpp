class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        /*
            nxn grid    0-water 1-land
            find a water cell such that it's distance with the nearest land is maximized
            Manhattan Distance: |x0 - x1| + |y0 - y1|    
            
            Approach: BFS
            we store all the positions of land , and explore(BFS) surrounding for water, 
            at each level of BFS , distance will increase by 1

        */
        
        int m= grid.size(), n= grid[0].size(), dist=-1;
        
        queue<pair<int,int>> q;
        
        // coordinates for up-right-down-bottom
        int x[]= {-1,0,1,0};
        int y[]= {0,1,0,-1};
        
        // pushing coordinates of land
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        // if no land or water exists in the grid
        if(q.size()==0 || q.size()==m*n)
            return -1;
        
        
        // BFS
        while(!q.empty())
        { 
            int size= q.size();
            dist++;
            
            while(size--)
            {
                pair<int,int> land= q.front();
                q.pop();
                
                int x0= land.first;
                int y0= land.second;
                
                // searching for water 4-directionally
                for(int i=0; i<4; i++)
                {
                    int x1= x0+x[i];
                    int y1= y0+y[i];
                    // if water is surrounding the land, we'll find the distance and update if it greater than max dist
                    if( x1>=0 && y1>=0 && x1<m && y1<n && grid[x1][y1]==0)
                    {
                        q.push({x1,y1});
                        
                        // mark water visited
                        grid[x1][y1]= 1;
                    }
                }
            }
        }
        return dist;
    }
};