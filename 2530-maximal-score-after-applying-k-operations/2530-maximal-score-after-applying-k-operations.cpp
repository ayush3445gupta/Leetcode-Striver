class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
    
    priority_queue<int>pq;
    for(int i:nums)pq.push(i);
    long long ans=0;
    while (k--)
    {
       long long n=pq.top();
        ans+=n;
        pq.pop();
        pq.push(ceil(n/3.0));
    }
    return ans;
}
};