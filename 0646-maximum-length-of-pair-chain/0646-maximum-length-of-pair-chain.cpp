class Solution {
public:
int findLongestChain(vector<vector<int>>& pairs) {
   sort(begin(pairs),end(pairs));
   int cnt=1;
   int prev_end=pairs[0][1];
   for (int i = 1; i < pairs.size(); i++)
   {
    if(pairs[i][0]>prev_end){
        cnt++;
        prev_end=pairs[i][1];
    }
    else{
        prev_end=min(prev_end,pairs[i][1]);
    }
   }
    return cnt;    
}
};