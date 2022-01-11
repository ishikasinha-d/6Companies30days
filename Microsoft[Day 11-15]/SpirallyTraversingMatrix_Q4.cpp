class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        /*
            Observation:
            To traverse spirally in a 4x4 matrix
            {{1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15,16}}
             
             we can take 4 pointers--> left=0, right= n-1, top=0, down= m-1;
             we print first row i.e i=0 and j=left to right --> 1 2 3 4
             then last column   i.e j= n-1 and i=top+1 to down-1 -> 8 12
             then last row      i.e i= m-1 and j= right to left -> 16 15 14 13
             then 1st column    i.e j=0 and i= down-1 to top+1 -> 9 5
             
             then we can update left++ top++ and right--  down-- and repeat above procedure
            
        */
        
        vector<int>ans;
        
        int m= matrix.size(), n= matrix[0].size();
        int left= 0, right= n-1, top=0, down= m-1;
        
        while( left<=right && top<=down )
        {
            for(int j= left; j<=right; j++)
                ans.push_back(matrix[top][j]);
            
            for(int i= top+1; i<=down-1; i++)
                ans.push_back(matrix[i][right]);
            
            if(top!=down)
                for(int j= right; j>=left; j--)
                    ans.push_back(matrix[down][j]);
            
            if(left!=right)
                for(int i=down-1; i>= top+1; i--)
                       ans.push_back(matrix[i][left]);
            
            top++; left++;
            down--; right--;
        }
        
        return ans;  
    }
};