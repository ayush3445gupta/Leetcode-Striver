class Solution {
public:
vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
    unordered_set<string>pos,neg;
    for(string s:positive_feedback)pos.insert(s);
    for(string s:negative_feedback)neg.insert(s);

    int n=student_id.size();
    vector<pair<int,int>>rank;
    for (int i = 0; i < n; i++)
    {
        int score=0;
        stringstream ss(report[i]);
        string word;
        while (ss >> word)
        {
            if(pos.count(word)) score+=3;
           else if(neg.count(word))score-=1;
        }
        rank.push_back({score,student_id
        [i]});
    }
    sort(begin(rank),end(rank),[](const pair<int,int>&a,const pair<int,int>&b){
        if(a.first==b.first)return a.second<b.second;
        return a.first>b.first;
    });
    vector<int>ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i]=(rank[i].second);
    }
    return ans;
}
};