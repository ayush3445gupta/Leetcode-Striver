class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       priority_queue<pair<int,int>>pq;
       
       for (int i = 0; i < score.size(); i++)
       pq.push({score[i],i});
       int n=score.size();
       vector<string>res(n);
       int i=0;
    while (!pq.empty())
       {
        if(i==0){
            int ind=pq.top().second;
            res[ind]="Gold Medal";
            pq.pop();
        }
       else if(i==1){
            int ind=pq.top().second;
            res[ind]="Silver Medal";
            pq.pop();
        }
        else if(i==2){
            int ind=pq.top().second;
            res[ind]="Bronze Medal";
            pq.pop();
        }
        else{
            int ind=pq.top().second;
           res[ind]= to_string(i+1);
            pq.pop();
        }
        i++;
       }
       return res;
}
};