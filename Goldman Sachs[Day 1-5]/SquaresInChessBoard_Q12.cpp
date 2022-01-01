class Solution {
  public:
    long long squaresInChessBoard(long long N) {
       
    // If we have 8x8 chessboard, we'll have squares of size 1x1, 2x2, 3x3....8x8
    // sum of the following will be total squares we have
    // 1x1=> 8*8= 64 
    // 2x2=> 7*7= 49 and so on..
    
    // Approach 1: we can loop i from 1 to N and store sum+= i*i; TC=O(N), AS=O(1)
    // Approach 2: use mathematical formula for sum of squares of n numbers TC=O(1), AS=O(1)
    
    return (N*(N+1)*(2*N+1))/6;
    
    }
};
