class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
     int n=tasks.size();
     unordered_map<int,int>mp;
    for(auto it:tasks)mp[it]++;
    int ans=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        int freq=it->second;
        if(freq==1)return -1;
        if(freq%3==1){
            ans+=2;
            freq-=4;
        }
        else if (freq%3==2)
        {
           ans+=1;
           freq-=2;
        }
        if(freq)ans+=freq/3;
    } 
    return ans;
    }
};