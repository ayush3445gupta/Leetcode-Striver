class Solution {
public:
    bool findInRanges(vector<vector<int>>& ranges, int num){
    
    for (int i = 0; i < ranges.size(); i++)
    {
        int s=ranges[i][0];
        int e=ranges[i][1];
        if(num>=s && num<=e)return true;
    }
    return false;
}
bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // bruteforce

        for (int i = left; i <=right; i++)
        {
           if(!findInRanges(ranges,i))return false;
        }
        return true;      
}
};