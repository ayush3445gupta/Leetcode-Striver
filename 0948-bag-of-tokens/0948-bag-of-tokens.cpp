class Solution {
public:
int bagOfTokensScore(vector<int>& tokens, int power) {
     int n=tokens.size();
     if(n==0)return 0;
     sort(begin(tokens),end(tokens));
     int maxScore=INT_MIN;
     int curr_Score=0;
     int left=0,right=n-1;
     while (left<=right)
     {
        if(power>=tokens[left]){
            power-=tokens[left];
            curr_Score++;
            left++;
        }
        else{

            power+=tokens[right];
            right--;
            curr_Score--;
        }
        if(curr_Score<0)curr_Score=0;
        maxScore=max(maxScore,curr_Score);
     }
     return (maxScore==INT_MIN?0:maxScore);
    }
};