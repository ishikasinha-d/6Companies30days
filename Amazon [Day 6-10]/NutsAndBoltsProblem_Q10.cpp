class Solution{
public:	
    
    int partition(char a[], int low, int high)
    {
        int pivot= high;
        int i= low-1;
        
        for(int j=low; j<=high; j++)
        {
            if(a[j]<a[pivot])
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        i++;
        swap(a[i], a[pivot]);
        
        return i;
    }
    
    void quicksort( char a[], int low, int high)
    {
        if(low<high)
        {
            int pivot= partition(a,low,high);
            quicksort(a, low, pivot-1);
            quicksort(a, pivot+1, high);
        }
    }

	void matchPairs(char nuts[], char bolts[], int n) {

	   /*
	        Approach 1: run 2 nested loops and match nuts and bolts TC:O(n^2)
	        Approach 2: using hashmap, store order of elements like 
	                    map<char,int> mp={ {'!',1}, {'#',2}, {'$',3}, {'%',4}, {'&',5}, {'*',6}, {'@',7}, {'^',8}, {'~',9} };
	                    then assign characters of nuts and bolts respective values using the hashmap and sort
	        Approach 3: ASCII of these characters are 
	                    !->33, #->35, $->36, %->37, &->38, *->42, @->64, ^->94, ~ -> 126
	                    Since the ASCII of this order we have to follow is in ascending order 
	                    and there is one-one mapping btween nuts and bolts, hence we can simply sort both the arrays individually
	        
	        TO sort, either use inbulit fnc i.e sort(nuts, nuts+n) and sort(bolts, bolts+n);
	        or apply sorting algorithms like bubble sort, merge sort etc
	        According to expected complexities, algo needs to be inplace and O(nlogn)
	        Therefore I'll go for quicksort
	        
	        TC: O(nlogn), SC:O(1)
	   */
	 
	int low=0, high=n-1;
	quicksort(nuts, low, high);
	quicksort(bolts, low, high);
	    
	}

};
