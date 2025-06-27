class Solution {
public:
void solve(int left,int right,string res,vector<string>& ans){
    if(left==0 && right==0){
        ans.push_back(res);
        return;
    }

    if(left>0)solve(left-1,right,res+'(',ans);
    if(right>left)solve(left,right-1,res+')',ans);
}
vector<string> generateParenthesis(int n) {
     int left=n,right=n;
     vector<string>ans;
     string res="";
     solve(left,right,res,ans);
     return ans;
}
};