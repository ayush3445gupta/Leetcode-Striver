class Solution {
public:
int convertTime(string current, string correct) {
     string curr_hr=current.substr(0,2);
     string curr_min=current.substr(3,2);
     
     string dest_hr=correct.substr(0,2);
     string dest_min=correct.substr(3,2);

     int  curr_time = stoi(curr_hr)*60+stoi(curr_min);
     int dest_time = stoi(dest_hr)*60 + stoi(dest_min);

     int diff=dest_time-curr_time;
     int ans=0;
     while (diff)
     {
        if(diff>=60){
            ans+=diff/60;
            diff%=60;
        }
        else if (diff>=15)
        {
            ans+=diff/15;
            diff%=15;
        }
        else if (diff>=5)
        {
            ans+=diff/5;
            diff%=5;
        }
        else{
            ans+=diff;
            diff=0;
        }
     }
    return ans;
    }
};