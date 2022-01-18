class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) 
    {
        int i, j, res=0, n= str.length();
        bool neg= false;
        for(int i=0; i<n; i++)
        {
            if(i==0 && str[i]=='-')
            {
               neg= true;
               continue;
            }
            else if(!isdigit(str[i]))
                return -1;
            else
                res= res*10+ (str[i]-'0');
            
        }
        
        return neg ? -1*res : res;
        
    }
};