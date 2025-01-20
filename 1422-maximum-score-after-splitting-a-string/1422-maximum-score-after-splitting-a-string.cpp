class Solution {
public:
int maxScore(string s) {
    int Totzeros=0,Totones=0;
    int ans=INT_MIN;
    for (int i = 0; i <s.length(); i++)
    {
        s[i]=='0'?Totzeros++:Totones++;
    }
    int z=0,ones=0;
    for (int i = 0; i <s.length()-1; i++)
    {
        if(s[i]=='0'){
            z++;
        }
        else{
            ones++;
        }
        ans=max(ans,z+Totones-ones);
    }
    return ans;
    }
};