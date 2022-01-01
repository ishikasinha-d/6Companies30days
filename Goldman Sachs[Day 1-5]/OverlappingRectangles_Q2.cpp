class Solution {
  public:
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        
        // LOGIC:
        // The rectangles donot overalp if 
        // (Rect1 is completely above or below Rect2) || (Rect1 is completely to the left or right of Rect2)
        
        if( r1[0] < l2[0] ||  // rect1 left to rect2
            r2[0] < l1[0] ||  // rect1 right to rect2
            l1[1] < r2[1] ||  // rect1 below rect2
            l2[1] < r1[1]     // rect1 above rect2
            )
        return false;
        
        return true;
    }
};
