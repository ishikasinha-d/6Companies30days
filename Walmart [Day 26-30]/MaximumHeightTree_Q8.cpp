class Solution{
public:
    int height(int N){
        
        /*
        eq= >X^2+X-2*N= 0
        roots=> (-1 + sqrt(1 + 8*N)) / 2 and (-1 - sqrt(1 + 8*N)) / 2
        */
        
        return (-1 + sqrt(1 + 8*N))/2;
    }
}