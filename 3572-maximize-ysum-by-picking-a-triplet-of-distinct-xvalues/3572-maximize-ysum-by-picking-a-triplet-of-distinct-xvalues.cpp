class Solution {
public:
   int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
     int n=x.size();
     
     priority_queue<pair<int,int>>pq;
     for (int i = 0; i < n; i++)
     {
        pq.push({y[i],x[i]});
     }
     unordered_set<int>st;
     int ans=0;
     while (!pq.empty() && st.size()<3)
     {
        int to_add=pq.top().first;
        int to_insert = pq.top().second;
        pq.pop();
        if(st.find(to_insert)==st.end()){
            ans+=to_add;
            st.insert(to_insert);
        }
     }
     if(st.size()==3)return ans;
     return -1;
    }
};