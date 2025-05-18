class Solution {
public:
typedef long long ll;
bool possible(ll mid,int n,vector<int>&stalls,int k){
    k-=1;
    ll prev=stalls[0];
    for (int i = 1; i < n && k>0; i++)
    {
        if(stalls[i]-prev>=mid){
            k--;
            prev=stalls[i];
        }
    }
    return k==0;
}
int maxDistance(vector<int>& position, int m) {
     ll n=position.size();
     sort(begin(position),end(position));
     ll left=1,right=position[n-1]-position[0];
     while (left<=right)
     {
        ll mid=(left+right)/2;
        if(possible(mid,n,position,m))left=mid+1;
        else right=mid-1;
     }
     return right;       
    }
};