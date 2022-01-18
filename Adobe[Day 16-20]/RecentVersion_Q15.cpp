#include <iostream>  
#include <string>    
#include <sstream>
using namespace std;

string recentVersion(string a, string b)
{
    istringstream ss1(a), ss2(b);
    string v1, v2;
    
    while( getline(ss1, v1, '.') && getline(ss2, v2, '.'))
    {
        if(v1>v2)
            return a;
        if(v1<v2)
            return b;
            
        v1="";
        v2="";
    }
    
    if(v1!="")
        return a;
    
    return b;
    
}
int main() {
    
    string v1, v2;
    cin>>v1>>v2;
    
    cout<<recentVersion(v1,v2);
    
    return 0;
}
