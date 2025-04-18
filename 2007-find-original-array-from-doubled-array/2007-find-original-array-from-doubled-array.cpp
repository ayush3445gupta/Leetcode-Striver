class Solution {
public:
vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>mp;
        int n=changed.size();
        vector<int>res;
         sort(changed.begin(),changed.end());
        for (int i = 0; i < n; i++)
        {
           mp[changed[i]]++;
        }
        
        for (int i = 0; i < n; i++)
        {
           if(mp[changed[i]]==0)continue;
           mp[changed[i]]--;

           if(mp[2*changed[i]]==0){
            vector<int>emp;
            return emp;
           }
           else{
            mp[2*changed[i]]--;
            res.push_back(changed[i]);
           }
        }
        return res;
}
};