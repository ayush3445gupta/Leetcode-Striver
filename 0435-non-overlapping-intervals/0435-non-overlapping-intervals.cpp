class Solution {
public:
//     bool static comp(vector<int>&a,vector<int>&b){
//     return a[1]<b[1];
// }
// int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//       sort(intervals.begin(),intervals.end(),comp); 
//       int last=intervals[0][1];
//       int cnt=0;
//       for (int i = 1; i < intervals.size(); i++)
//       {
//         if(intervals[i][0]>=last){
//             last=intervals[i][1];
//         }
//         else cnt++;
//       }
//        return cnt;
//     }

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n=intervals.size();
    int cnt=0;
    sort(begin(intervals),end(intervals));
    int prev_end=intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if(intervals[i][0]<prev_end){
            cnt++;
        }
       else  prev_end=intervals[i][1];
    }
    return cnt;
}
};