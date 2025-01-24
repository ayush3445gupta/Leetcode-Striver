class Solution {
public:
    int maxArea(vector<int>& height) {
    int n=height.size();
    int left=0,right=n-1;
    int maxAr=INT_MIN;
    while (left<right)
    {
       int area=min(height[left],height[right])*(right-left);
       maxAr=max(maxAr,area);
       height[left]<height[right]?left++:right--;
    }
       return maxAr;
    }
};