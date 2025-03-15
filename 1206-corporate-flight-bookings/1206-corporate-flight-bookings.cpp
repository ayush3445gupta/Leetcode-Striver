class Solution {
public:
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

    vector<int>diff_arr(n+1,0);
    for (int i = 0; i < bookings.size(); i++)
    {
        int f=bookings[i][0];
        int l=bookings[i][1];
        int s=bookings[i][2];

        diff_arr[f-1]+=s;
        diff_arr[l]-=s;
    }
    
    for (int i = 1; i < n; i++)
    {
       diff_arr[i]+=diff_arr[i-1];
    }
    diff_arr.pop_back();
    return diff_arr;
}
};