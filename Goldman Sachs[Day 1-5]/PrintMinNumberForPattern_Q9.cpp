class Solution{   
public:
    string printMinNumberForPattern(string S){
        
        /*
            the pattern consists of I's and D's only and digits can't be repeated
            Case 1: for pattern like III, it's simple as we can start from 1 and keep increasing i.e III= 1 2 3 4 
            Case 2: for pattern like DDD, we need to think how many D's we have and then start i.e DDD= 4 3 2 1 
            Case 3: for DDIDD, we see that I will be breaking point
            so when we reach I, we can count the previous D's , so till I we will be able to form 3 2 1
            however we have 2 more D's in the end, so to tackle that edge case, we can add 'I' at the end
            Case 4: for IDI, we still need to append a I in the end to consider last I
            TC: O(N)  SC: O(N)
        */
        
        S+='I';
        int n= S.length();
        stack<char> st;
        int d=1;
        string ans="", res="";
        
        for(int i=0; i<n; i++)
        {
            // when I is encountered, we'll start forming the number till this breaking point
            if(S[i]=='I')
            {
                int num=0;
                if(st.empty())
                    {
                        num=num*10+d;
                        d++;
                    }
                else
                {
                    // pushing extra character in stack because we have to calculate number for (no. of D's)+1 times
                    st.push('X');
                    while(!st.empty())
                    {
                        num=num*10+d;
                        d++;
                        st.pop();
                    }
                }
            
            // reversing the number and appending to final result
            ans= to_string(num);
            reverse(ans.begin(), ans.end());
            res+= ans;
            }
            
            // if D is encountered, simply push onto stack
            else 
                st.push(S[i]);
        }
        
        return res;
    }
};
