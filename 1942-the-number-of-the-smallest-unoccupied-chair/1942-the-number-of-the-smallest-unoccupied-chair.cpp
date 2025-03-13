class Solution {
public:
int smallestChair(vector<vector<int>>& times, int targetFriend) {
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;

    for (int i = 0; i < times.size(); i++)
    {
       pq.push({{times[i][0],1},i});
       pq.push({{times[i][1],0},i});
    }
    int n=times.size();
    vector<int>people(n,-1);
    int ans=-1;
    int i=0;
    while (!pq.empty())
    {
        int time=pq.top().first.first;
        int status=pq.top().first.second;
        int fr=pq.top().second;

        if(status==1){
            people[fr]=i;
            if(fr==targetFriend)ans=i;
            i++;
        }
        else{
            people[fr]=-1;
            i--;
        }
        pq.pop();
    }
    return ans;
}
};