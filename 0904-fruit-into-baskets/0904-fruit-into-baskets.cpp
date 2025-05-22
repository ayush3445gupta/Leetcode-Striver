class Solution {
public:
int totalFruit(vector<int>& fruits) {
     int n=fruits.size();
     int left=0,right=0;
     int mx=INT_MIN;
     unordered_map<int,int>mp;
     while (right<n)
     {
        mp[fruits[right]]=right;
        while (left<right && mp.size()>2)
        {
            int k=mp[fruits[left]]+1;
            mp.erase(fruits[left]);
            left=max(left,k);
        }
        mx=max(mx,right-left+1);
        right++;
     }
     return mx;   
    }
};