class Solution {
  public:
    int findPosition(int N , int M , int K) {
        
        // Since we are starting from Kth position, 
        // Mth item will be received by person at (K+M-1)th position
        // K and M might be more than N, so modulo will be taken 
        
        if(K>N)
            K%= N;
        if(M>N)
            M%= N;
            
        int pos= K+M-1;
        
        // is position is out of bounds, arrangement being cicular, modulo N of position will be taken 
        if(pos>N)
            pos= pos%N;
        
        return pos;
    }
};
