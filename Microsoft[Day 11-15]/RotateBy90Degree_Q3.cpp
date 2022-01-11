/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& a)
{
    /*
        Approach 1: extra array SC: O(n^2)
        Approach 2: inplace
        [[1,2,3],                   
         [4,5,6],  --> reverse each row
         [7,8,9]]
         
         [[3,2,1],
          [6,5,4],    --> transpose
          [9,8,7]]
          
          
         [[3,6,9], 
          [2,5,8],    <--- final ans
          [1,4,7]]

          
          TC: O(n^2)
          SC: O(1)
        */
        
    int n= a.size();
    
    // reversing each row
    for(int i=0; i<n; i++)
        reverse(a[i].begin(), a[i].end());
        
    // finding transpose
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            swap(a[i][j],a[j][i]);
    
}