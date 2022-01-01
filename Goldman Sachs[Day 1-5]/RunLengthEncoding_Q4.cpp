
string encode(string str)
{     
    // LOGIC:
    // Approach 1: Can create a frequency array TC: O(N+N) AS: O(N)
    // Approach 2: Keep a counter variable for frequency of each character, append frequecy and reset counter when str[i] != str[i-1]
    // TC: O(N) and AS: O(1)
    
    //add dollar character at the end to tackle the edge case of last repeating chartacters
    str+= "$";
    string encoded_str;
    encoded_str= str[0];
    int count=1, n=str.length();
    

    for(int i=1; i<n; i++)
    {
        if(str[i]!=str[i-1])
        {
            encoded_str+= to_string(count);
            
            if(i != n-1)
               encoded_str+= str[i];
               
             count=1;
        }
        else
        {
            count++;
        }
    }
    
    return encoded_str;
}     
