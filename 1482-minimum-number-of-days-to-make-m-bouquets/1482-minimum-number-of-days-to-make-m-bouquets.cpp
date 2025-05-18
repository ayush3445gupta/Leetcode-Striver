class Solution {
public:
typedef long long ll;
// bruteforce
bool check(ll mid,int n,vector<int>&bloomDay,int m,int k){
    int i=0,j=0;
    while (j<n && m>0)
    {
        if(mid>=bloomDay[j]){
            if(j-i==k-1){
                m--;
                j++;
                i=j;
            }
            else j++;
        } 
        else{
            j++;
            i=j;
        }
    }
    return m==0;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n=bloomDay.size();
    // if(m*k>n)return -1;
    ll left=*min_element(begin(bloomDay),end(bloomDay));
    ll right=*max_element(begin(bloomDay),end(bloomDay));
    ll ans=-1;
    while (left<=right)
    {
        ll mid=left+(right-left)/2;
        if(check(mid,n,bloomDay,m,k)){
            right=mid-1;
            ans=mid;
        }
        else left=mid+1;
    }
    return ans;
    }
};