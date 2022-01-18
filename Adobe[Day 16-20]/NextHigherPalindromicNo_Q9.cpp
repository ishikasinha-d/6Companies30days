class Solution{
  public:
  
    string nextPermutation(string a, int n)
    {
        /*
        traverse from right to left and find i such that a[i]<a[i+1] => idx1= i
        traverse from right to left and find idx2 such that a[idx2]>a[idx1]
        swap a[idx1], a[idx2]
        reverse form indx1+1 to last

        */
        
        // finding breaking point 
        int i,j;
        for(i=n-2; i>=0; i--)
        {
            if(a[i]<a[i+1])
                break;
        }
        
        //no breaking pt
        if(i<0)
            return "-1";
        
        // finding smallest no. greater than no. at i
        for(int j=n-1; j>=i; j--)
        {
            if(a[j]>a[i])
                {
                    swap(a[i], a[j]);
                    break;
                }
        }
        
        // reversing from i+1 to end
        string a1= a.substr(0,i+1);
        string a2= a.substr(i+1);
        reverse(a2.begin(), a2.end());
        return a1+a2;
        
    }
    
    string nextPalin(string N) { 
      
      /*
      Step1 : for the first half no., find the next highest no. 
      Step2: reverse it and add it to the string
     
      */
      
      int n= N.length();
        
      string half= N.substr(0,n/2);
        
      string str= nextPermutation(half, n);
      
      if(str=="-1")
        return "-1";
        
      string rev= str;
      reverse(rev.begin(), rev.end());
      
      if(n%2==0)
      {
          str= str+rev;
      }
      else
      {
          char ch= N[n/2];
          str= str+ch;
          str+= rev;
      }
      
      return str;
      
    }
};