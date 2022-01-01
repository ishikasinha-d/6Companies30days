class Solution {
public:
    // if s= t+t+t...n times and size of t is k
    // TC: O(n*k) 
    // AS: O(1)
    string gcdOfStrings(string str1, string str2) {
        
        //keeping larger string in str1 and smaller string in str2 at all times 
        if(str1.length()<str2.length())
            return gcdOfStrings(str2, str1);
        
        //if str1 isn't starting with str2
        else if( str1.find(str2)!=0 )
            return "";
        
        //if str2 has become null that means str1 which is left is our answer
        else if( str2=="" )
            return str1;
        
        // Cutting off the common prefix part of str1 & recurring
        else
            return gcdOfStrings(str1.substr(str2.length()), str2);
    }
};
