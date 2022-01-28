/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
     int findInMountainArray(int target, MountainArray &arr) 
 {
     
     int low=0, high= arr.length()-1, peak=0, mid;
     while(low<high)
     {
         mid= low+(high-low)/2;
         if(arr.get(mid)<arr.get(mid+1))
            low= peak= mid+1;
         else 
             high= mid;
     }
     
     
     low= 0, high= peak;
     while(low<=high)
     {
         mid= low+(high-low)/2;
         if(arr.get(mid)==target)
            return mid;
         else if(arr.get(mid)<target)
             low= mid+1;
         else
             high= mid-1;
     }
     
     
    low= peak, high= arr.length()-1;
    while(low<=high)
    {
        mid= low+(high-low)/2;
        if(arr.get(mid)==target)
            return mid;
         else if(arr.get(mid)>target)
             low= mid+1;
         else
             high= mid-1;
    }
     
    return -1;
    }
};