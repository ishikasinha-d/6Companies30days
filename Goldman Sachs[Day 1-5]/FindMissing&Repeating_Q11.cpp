class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        /*
            Approach 1: use hashmap TC: O(n) SC: O(n)\
            Approach 2: mathematical formula for sum of n and n^2 numbers TC: O(N) SC: O(1) but overflow can occur
            Approach 3: use XOR 
            Step 1: find XOR of all array elements and numbers from 1 to N, this will give us X^Y= some value where X and Y will be missing snd repeting no.s
            Step 2: find rightmost set bit in number, since we have found XOR, ith bit set in XOR X and Y is possible is ith bit at X and Y are opposite
            therefore, separate all elements of array and 1 to N into set and unset buckets and XOR both these buckets to get missing and repeating no.s
            the numbers might have been swapped so run a loop to check which is missing and which is repeating
        */
        
        int *ans= new int[2];
        
        int Xor=0, x=0, y=0;
        
        for( int i=1; i<=n; i++) Xor= Xor^i;
        for(int i=0; i<n; i++) Xor= Xor^arr[i];
        
        //finding rightmost set bit
        int set_bit= Xor & ~(Xor-1);
        
        //dividing into hypothetical buckets
        for(int i=0; i<n; i++ )
        {
            // if set, goes in bucket x
            if(arr[i]&set_bit)
                x= x^arr[i];
            // otherwise in bucket y
            else
                y= y^arr[i];
            
        }
        for(int i=1; i<=n; i++ )
        {
            //if set, belongs to bucket x
            if(i&set_bit)
                x= x^i;
            // otherwise belongs to bucket y
            else
                y= y^i;
            
        }
        
        // finding which one is missing and which one is repeating
        int flag=0;
        for(int i=0; i<n; i++)
            if(x==arr[i])
                {
                    flag=1; break;
                }
        
        // if number is present, must be repeating
        if(flag==1)
            {
                ans[0]= x;
                ans[1]= y;
                return ans;
            }
            
        ans[0]= y;
        ans[1]= x;
        return ans;
    }
};
