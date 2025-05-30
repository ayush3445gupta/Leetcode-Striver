class Solution {
public:
int longestSubarray(vector<int>& nums, int limit) {
     int n=nums.size();
     priority_queue<pair<int,int>>mxheap;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mnheap;
     int i=0,j=0;  
     int maxLen=0;
     while (j<n)
     {
       mxheap.push({nums[j],j});
       mnheap.push({nums[j],j});

       while (mxheap.top().first-mnheap.top().first>limit)
       {
        i = min(mxheap.top().second,mnheap.top().second)+1;
        while (mxheap.top().second<i)mxheap.pop();
        while (mnheap.top().second<i)mnheap.pop();
        
       }
       maxLen=max(maxLen,j-i+1);
       j++;
     }
     return maxLen;
    }
};