class Solution {
public:
int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n=times.size();
    vector<int>chairs(n,-1);
    int targetFriendArrivalTime=times[targetFriend][0];
    
    sort(times.begin(),times.end());

    for (int i = 0; i < n; i++)
    {
        int arrival=times[i][0];
        int depart=times[i][1];

        for (int i = 0; i < n; i++)
        {
            if(chairs[i]<=arrival){
                chairs[i]=depart;
                if(targetFriendArrivalTime==arrival){
                    return i;
                }
                break;
            }
        }     
    }
   return -1; 
}
};