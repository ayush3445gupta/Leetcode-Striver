class Solution {
public:
typedef long long ll;
int mySqrt(ll x) {
    if(x==1)return 1;
     ll left=1,right=x/2;
     ll ans=0;
     while (left<=right)
     {
        ll mid=left+(right-left)/2;
        if((mid*mid)==x)return mid;
        else if (mid*mid<x)
        {
            ans=mid;
            left=mid+1;
        }
        else right=mid-1;
     }
      return ans;  
    }
};