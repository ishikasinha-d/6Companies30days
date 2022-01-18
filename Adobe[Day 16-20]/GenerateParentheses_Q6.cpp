// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void generateParentheses(int n, int open, int close, string s, vector<string>&ans)
    {
        if(open==n && close==n)
            {
                ans.push_back(s);
                return;
            }
        if(open<n)
            {
                generateParentheses(n, open+1, close, s+"(", ans);
            }
        if(close<open)
            {
                generateParentheses(n, open, close+1, s+")", ans);
            }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        /*
            Approach 1: Generate all 2^2n sequences and check for validity 
            ans will be = '('+ all sequences of length n-1+ ')'+ all sequences of length n-1
            if no. of closing - opening bracket < 0 or doesn't reach 0 =>invalid sequence, 
            TC: O(2^2n * n)
            SC: O(2^2n * n)
            
            Approach 2: Instead of adding '(' or ')' every time, we can add them when we know 
                        it will remain a valid sequence. We can do this by keeping track of the 
                        number of opening and closing brackets we have placed so far.
            TC: O(2^n)
            SC: O(n)
        */
        
        vector<string> ans;
        string s= "";
        generateParentheses(n, 0, 0, s, ans);
        return ans;
    }
};