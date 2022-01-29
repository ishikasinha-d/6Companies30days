class Solution
{
    public:
    
    /*
      Approach 1: find all pairs and check if the no. formed is max 
                  each recurive call will make n^2 further recursive calls and there will be k such call
                  TC: ((n^2)^k)
      Approach 2: starting from left, swap the digits with max digit present on it's right
                  Edge case: N= 7588 K= 1
                  then max will be 8587 and not 8578. To tackle such cases, we need to find all such combinations and get max of it
                  To implement this we can apply bactracking and visit all possibilities
                  each recurive call will make n further recursive calls and there will be k such call
                  TC: O(n^k)
    */
    
    string largest_no="";
    void findMax(int indx, string str, int k)
    {
        if(k==0)
            return;
        
        int n= str.length();
        char max_d= str[indx];
        
        //finding max element ahead
        for(int i= indx+1; i<n; i++)
        {
            if(str[i]>max_d)
                max_d= str[i];
        }
        
        if(max_d != str[indx])
           k--;  
           
        //getting all max elements and swapping
        for(int i= n-1; i>=indx; i--)
        {
            if(str[i]==max_d)
            {
                swap(str[i], str[indx]);
                
                if (str.compare(largest_no) > 0)
                    largest_no = str;
                    
                findMax(indx+1, str, k);
                swap(str[i], str[indx]);
            }    
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       findMax(0, str, k);
       return largest_no;
    }
};
