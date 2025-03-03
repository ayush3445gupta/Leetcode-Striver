class Solution {
public:
string frequencySort(string s) {
    string t="";
    unordered_map<char,int>freq_map;
    for(char c:s)freq_map[c]++;
    priority_queue<pair<int,char>>pq;
    for(auto it=freq_map.begin();it!=freq_map.end();it++){
        pq.push({it->second,it->first});
    }     
    while (!pq.empty())
    {
        int fr=pq.top().first;
        char ch=pq.top().second;
        while (fr--)
        {
            t+=ch;
        }
        pq.pop();
    }
    return t;
}
};