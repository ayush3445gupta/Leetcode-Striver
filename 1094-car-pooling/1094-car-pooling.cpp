class Solution {
public:
    // bool carPooling(vector<vector<int>>& trips, int capacity) {
    // if(trips[0][0]>capacity)return false;
    //  int n=trips.size();
     
    //  for (int i = 0; i <n-1; i++)
    //  {
    //     int first_end=trips[i][2],start_next=trips[i+1][1];
    //     if(trips[i][0]+trips[i+1][0]>capacity && 
    //       start_next<first_end)return false;
    //  }
    //  return true;
    // }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    int maxi=INT_MIN;
    for (int i = 0; i < trips.size(); i++)  //O(N)
    {
        maxi=max(maxi,trips[i][2]);
    }
    
    vector<int>arr(maxi+1,0);
    for (int i = 0; i < trips.size(); i++)   //O(N)
    {
        int passengers=trips[i][0];
        int from=trips[i][1];
        int to=trips[i][2];

        arr[from]+=passengers;
        arr[to]-=passengers;
    }
    int cum_sum=0;
    for (int i = 0; i < arr.size(); i++)   //O(K)
    {
        cum_sum+=arr[i];
        if(cum_sum>capacity)return false;
    }
    return true;
}
};