//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    vector<string> ans;
    for(int i=1; i<=N; i++)
    {
        string s="";
        int num=i;
        
        // computing binary value of num
        while(num)
        {
            s= to_string(num%2)+s;
            num/= 2;
        }
        ans.push_back(s);
    }
    return ans;
}