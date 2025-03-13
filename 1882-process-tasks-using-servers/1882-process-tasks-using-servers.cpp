class Solution {
public:
vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
     // use 2 min-heaps
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>free_servers;
// weight and index

     priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>busy;
// time,weight and index
     int n=tasks.size();
     for (int i = 0; i < servers.size(); i++)
        free_servers.push({servers[i],i});
    
    vector<int>ans(n);

    int time=0;
    for (int i = 0; i<n; i++)
    {
       time=max(time,i);
       while (!busy.empty() && time>=busy.top().first)
       {
        free_servers.push({busy.top().second.first,busy.top().second.second});
        busy.pop();
       }
       if(free_servers.empty()){
        time=busy.top().first;
        while (!busy.empty() && time>=busy.top().first){
            free_servers.push({busy.top().second.first,busy.top().second.second});
            busy.pop();
        }
    }
       busy.push({i+tasks[i],{free_servers.top().first,free_servers.top().second}});
       ans[i]=free_servers.top().second;
       free_servers.pop();   
    }   
     return ans;
}
};