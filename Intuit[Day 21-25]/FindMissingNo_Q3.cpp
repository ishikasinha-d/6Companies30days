/* You are required to complete this function
which return the required missing number
if present else return -1*/

// fnc to find value of length len from position i 
int getValue(string str, int i, int len)
{
    if(i+len>str.length())
    {
        return -1;
    }
    
    int num=0;
    for(int j=0; j<len;j++)
    {
        int d= str[i+j]-'0';
        
        if(d<0 || d>9)
            return -1;
        
        num= num*10+d;
    }
    
    return num;
}

int missingNumber(const string& str)
{
    
    for(int len=1; len<=6; len++)
    {
        //value of 1st no. with length len
        int n= getValue(str, 0, len);
        
        if(n==-1)
            break;
            
        int missing_no= -1;
        bool invalid= false;
        
        //finding subsequent numbers with previous number as n
        for(int i=len; i!=str.length(); i+=1+log10l(n))
        {
            // if missing no. is not found before 
            if(missing_no==-1 && getValue(str, i,1+log10l(n+2))==n+2)
            {
                missing_no= n+1;
                n+=2;
            }
            //the sequence is incrementing as per rule
            else if(getValue(str, i, 1+log10l(n+1))==n+1)
                n++;
            else
            {
                invalid= true;
                break;
            }
                
        }
        
        if(invalid==false)
            return missing_no;
    }
   return -1;
}