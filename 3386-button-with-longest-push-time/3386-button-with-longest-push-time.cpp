class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
     int n=events.size();
     int maxTime=events[0][1];
     int ans=events[0][0];
     for (int i = 1; i < n; i++)
     {
       int time=events[i][1]-events[i-1][1];
       if(time>maxTime){
        maxTime=time;
        ans=events[i][0];
       }
    //    else if(time=maxTime){
    //     ans=min(ans,events[i][0]);
    //    }
    //    else continue;
     }
    return ans;    
    }
};