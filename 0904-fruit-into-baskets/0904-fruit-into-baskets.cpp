class Solution {
public:
int totalFruit(vector<int>& fruits) {
     int n=fruits.size();
     int left=0,right=0;
     int mx=INT_MIN;
     unordered_map<int,int>mp;
     while (right<n)
     {
        mp[fruits[right]]++;
        while (left<right && mp.size()>2)
        {
            mp[fruits[left]]--;
            if(mp[fruits[left]]==0)mp.erase(fruits[left]);
            left++;
            
        }
        mx=max(mx,right-left+1);
        right++;
     }
     return mx;   
    }
};