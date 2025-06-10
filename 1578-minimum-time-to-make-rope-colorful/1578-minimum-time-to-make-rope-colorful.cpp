class Solution {
public:
int minCost(string colors, vector<int>& neededTime) {
     int n=colors.size();
     int ans=0;
     bool f=0;
     int prevIdx=0;
     for (int i = 1; i < n; i++)
     {
        while (colors[i]==colors[prevIdx] && i<n)
        {
            if(neededTime[i]>neededTime[prevIdx]){
                ans+=neededTime[prevIdx];
                prevIdx=i;
            }
            else{
                ans+=neededTime[i];
            }
            i++;
        }
        prevIdx=i;
        // if(i<n)mini=neededTime[i];
     }
     return ans;
    }
};