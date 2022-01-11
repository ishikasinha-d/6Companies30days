class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        /*
            Logic:
            Firstly sort the array in ascending order 
            Loop i=0 to n-3 and j=i+1 to n-2
            Now fixing i and j, we can use 2 pointer method and set left= j+1 & r=n-1
            Since we need unique quadruples, we can use set of vectors
            Also for i,j,left and right, we can run a loop to skip all duplaicate numbers
            
            TC: O(n^3)
            SC: O(n^2)
        */
        
        set<vector<int>> ans;
        int n= arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n-3;i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                int target= k-(arr[i]+arr[j]);
                int l=j+1, r=n-1;
                
                while(l<r)
                {
                    int x= (arr[l]+arr[r]);
                    
                    if(target==x) 
                        {
                            ans.insert({arr[i],arr[j],arr[l],arr[r]});
                            
                            while( l<r && arr[l]==arr[l+1])
                                l++;
                            while( l<r && arr[r]==arr[r-1])
                                r--;
                            l++; r--;
                        }
                    else if( x<target )
                        l++;
                    else
                        r--;
                }
                
                while( j<n-2 && arr[j]==arr[j+1])
                    j++;
            }
             while( i<n-1 && arr[i]==arr[i+1])
                    i++;
        }
        
        vector<vector<int>>res(ans.begin(), ans.end());
        
        return res;
        
    }
};