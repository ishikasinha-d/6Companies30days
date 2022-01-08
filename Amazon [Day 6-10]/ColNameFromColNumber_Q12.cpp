    class Solution{
    public:
    string colName (long long int n)
    {
        /*
            1- A
            27- AA
            28- AB
            100- CV, not AAAC
            the pattern is like AA, AB, AC,.. AZ, BA, BB
            we can see that 100/26= 3 (C) and 100%3= 22 (V)
            thus we need to start calculating characters from right to left
            Also here, A=1 but in ascii A=65 
                 while Z= 26 but in ascii Z= 90
            therefore if we do n%26+65-1, for A we get 65 but for Z we get 64 which is wrong
                      so we'll need to do (n-1)%26+65 to get A=65 and Z= 90
            TC: O(log n) SC:O(1)
            
        */
        string ans="";
        
        while(n)
        {
            char ch= (n-1)%26+65;
            ans= ch+ans;
            n= (n-1)/26;
        }
        
        return ans;
    }