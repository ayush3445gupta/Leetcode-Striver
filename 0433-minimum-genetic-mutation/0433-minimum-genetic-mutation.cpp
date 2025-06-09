class Solution {
public:

int minMutation(string startGene, string endGene, vector<string>& bank) {
    int n=startGene.length();
    unordered_set<string>st(bank.begin(),bank.end());
    
    queue<pair<string,int>>que;
    que.push({startGene,0});
    if(st.find(startGene)!=st.end())st.erase(startGene);

while (!que.empty())
    {
        string word=que.front().first;
        int level=que.front().second;
        que.pop();

        for (int i = 0; i < n; i++)
        {
            char original=word[i];
            for(char ch:"ACGT"){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    que.push({word,level+1});
                    if(word==endGene)return level+1;
                    st.erase(word);
                }  
                word[i]=original;
            }
        }
        
    }
    return -1;
    }
};