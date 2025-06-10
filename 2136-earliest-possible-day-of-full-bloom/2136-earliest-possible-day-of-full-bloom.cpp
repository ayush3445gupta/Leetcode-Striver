class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
     priority_queue<pair<int,int>>pq;
     int n=plantTime.size();
     int days=0;
     int grow=0;
     for (int i = 0; i < n; i++)
     {
       pq.push({growTime[i],plantTime[i]});
     }
     while (!pq.empty())
     {
        days+=pq.top().second;
        grow=max(days+pq.top().first,grow);
        pq.pop();
     }
     return grow;
    }
};