class Solution {
public:
vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    int n=segments.size();
    int maxi=INT_MIN,mini=INT_MAX;
    for (int i = 0; i < n; i++) {
        maxi=max(maxi,segments[i][1]);
        mini=min(mini,segments[i][0]);
    }
    set<long long>st;
    vector<int>arr(maxi+1,0);
    for (int i = 0; i < n; i++)
    {
        int start=segments[i][0];
        int end=segments[i][1];
        int color=segments[i][2];

        st.insert(start),st.insert(end);

        arr[start]+=color;
        arr[end]-=color;
    }

    vector<int>prefix(arr.size(),0);
    for (int i = 1; i < arr.size(); i++) prefix[i]=prefix[i-1]+arr[i];
  
    vector<vector<long long>>res;
    int i=mini;
    for(int point:st){
        if(point!=i && prefix[i]>0)
        res.push_back({i,point,prefix[i]});
        i=point;
    } 
    return res;
}
};