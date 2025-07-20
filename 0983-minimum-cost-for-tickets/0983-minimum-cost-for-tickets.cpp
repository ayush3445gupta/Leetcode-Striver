class Solution {
public:
int lastday;
unordered_map<int,int>isTravelNeeded;
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n=days.size();
    
    for(int i:days)isTravelNeeded[i]++;
    lastday=days[n-1];
    vector<int>dp(lastday+1,0);

    int i=0;
    for (int day=1; day <=lastday; day++)
    {
        if(day<days[i])dp[day]=dp[day-1];
        else{
            i++;
            dp[day] = min(min(dp[day-1]+costs[0],dp[max(0,day-7)]+costs[1]),dp[max(0,day-30)]+costs[2]);
        }
    }
    return dp[lastday];
}
};