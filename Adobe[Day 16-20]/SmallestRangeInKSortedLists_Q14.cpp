/*
    Approach 1: consider all pairs of element O(N^2) and travers each list O(N) => O(N^3)
    where N= total no. of elements in the matrix 
    										
    Approach 2: In prev approach, instead of traversing all lists, we can use Binary Search to find the index of the element just larger than(or equal to) the lower limit of the range currently considered.  O(n^2 log k) where n is total no. of elements and k is avg no. of elements in each list
    
    Approach 3: Using pointers 
    
    Approach 4: Using priority queue
*/

class Triplet
{
    public:
    int row, col, val;
    Triplet(int _row, int _col, int _val)
    {
        row= _row;
        col= _col;
        val= _val;
    }
};

class comp
{
    public:
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.val>t2.val;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //minheap
         priority_queue<Triplet, vector<Triplet>, comp> pq;
         
         int mini=0, maxi=INT_MIN, row, col, val, next_val;
         
         //processing first elements of all row
         for(int i=0; i<k; i++)
         {
              //getting the maximum element of all first elements
             if(KSortedArray[i][0]>maxi)
                maxi= KSortedArray[i][0];
            pq.push(Triplet(i,0,KSortedArray[i][0]));
         }
         
         mini= pq.top().val;
         
         // initial range
         int l= mini;
         int r= maxi;
         int diff= r-l;
         
         while(true)
         {
             auto u= pq.top();
             pq.pop();
             
             row= u.row;
             col= u.col;
             val= u.val;
             
             // exiting loop when any of the row is exhausted
            if(col+1>= n)
                break;
                
            next_val= KSortedArray[row][col+1];
            
            pq.push(Triplet(row, col+1, next_val));
            
            //updating min
            mini= pq.top().val;
            
            //updating maxi
            if(next_val>maxi)
                maxi= next_val;
            
            //updating range
            if( maxi-mini < diff)
            {
                l= mini;
                r= maxi;
                diff= r-l;
            }
        
         }
         
         return {l,r};
    }
};