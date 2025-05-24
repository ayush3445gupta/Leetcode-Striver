class Solution {
public:
int maxConsecutiveAnswers(string answerKey, int k) {
    int n=answerKey.length();
    int cnt_t=0,cnt_f=0;
    int i=0,j=0;
    int maxLen=INT_MIN;
    while (j<n)
    {
        if(answerKey[j]=='F')cnt_f++;
        else cnt_t++;
            while (min(cnt_t,cnt_f)>k)
            {
              maxLen=max(maxLen,j-i);
              if(answerKey[i]=='T')cnt_t--;
              else cnt_f--;
              i++;
            }
        j++;
    }
    if(min(cnt_f,cnt_t)<=k)maxLen=max(maxLen,cnt_t+cnt_f);
       return (maxLen==INT_MIN?n:maxLen);
    }
};