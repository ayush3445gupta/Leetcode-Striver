class Solution {
public:
int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int>pq;
    for(int i:piles)pq.push(i);
    while (!pq.empty() && k>0)
    {
        int top=pq.top();
        pq.pop();
        top=ceil(top/2.0);
        pq.push(top);
        k--;
    }
    int ans=0;
    while (!pq.empty())
    {
        ans+=pq.top();
        pq.pop();
    }
     return ans;
}
};