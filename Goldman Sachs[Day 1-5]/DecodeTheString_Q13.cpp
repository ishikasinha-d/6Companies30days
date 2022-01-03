class Solution{
public:
    string decodedString(string s){
        
        // pattern is <frequency>[string]
        // can use stack to store characters till ] isn't encountered;  when char is equal to ], start popping till [ is found; 
        // now digits will be there which will determine freq, keep popping till top is a digit and form no.
        // append the string according to the frequency and push onto the stack
        // TC: O(|S|)   AS: |S|
        
        stack<char>st;
        string ans="";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==']')
            {
                string str="";
                
                // pop till we get [
                while(!st.empty() && st.top()!='[')
                {
                    str+= st.top();
                    st.pop();
                }
                
                // popping [
                st.pop();
                
                // popping to get frequency
                string freq="";
                while(!st.empty() && isdigit(st.top()))
                {
                    freq= st.top()+freq;
                    st.pop();
                }
                
                // appending string according to frequency
                int num= stoi(freq);
                string str_repeat="";
                while(num--)
                    str_repeat+= str;
                
                reverse(str_repeat.begin(), str_repeat.end());
                
                // pushing str_repeat onto stack 
                for( int j=0; j<str_repeat.length(); j++)
                {
                    st.push(str_repeat[j]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            ans+= st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
