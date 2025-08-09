class Solution {
public:
int findtime(vector<int>& landStartTime, vector<int>& landDuration,vector<int>& waterStartTime, vector<int>& waterDuration){
    int t=3000;
    for (int i = 0; i < landStartTime.size(); i++)
    {
        t=min(t,landStartTime[i]+landDuration[i]);
    }
    
    int final_t=3000;
    for (int i = 0; i < waterDuration.size(); i++)
    {
        if(waterStartTime[i]>=t){
            final_t=min(final_t,waterDuration[i]+waterStartTime[i]);
        }
        else{
            final_t=min(final_t,t+waterDuration[i]);
        }
    }
    return final_t;
}
int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

    int k=findtime(landStartTime,landDuration,waterStartTime,waterDuration);
    int j=findtime(waterStartTime,waterDuration,landStartTime,landDuration);

    return min(k,j);
    }
};