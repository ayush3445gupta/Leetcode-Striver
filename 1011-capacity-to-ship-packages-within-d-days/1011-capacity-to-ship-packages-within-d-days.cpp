class Solution {
public:
typedef long long ll;
ll cap(ll mid,vector<int>&weights,int days){
    ll sum=0;
    ll cnt=0;
    for (ll i = 0; i <weights.size(); i++)
    {
       sum+=weights[i];
       if(sum>mid){
        cnt++;
        sum=weights[i];
       }
    }
    cnt++;
    return cnt;
}
int shipWithinDays(vector<int>& weights, int days) {
    ll n=weights.size();
    ll left=*max_element(begin(weights),end(weights));
    ll right=accumulate(begin(weights),end(weights),0);

    while (left<=right)
    {
        ll mid=(left+right)/2;
        ll d1=cap(mid,weights,days);
        if(d1<=days)right=mid-1;
        else left=mid+1;
    }
    return left;
    }
};