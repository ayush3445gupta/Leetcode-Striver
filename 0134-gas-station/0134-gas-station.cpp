class Solution {
public:
// bool check(int start,vector<int>& nums1, vector<int>& nums2){
//     int n=nums1.size();
//     int fuel = nums1[start];
//     for (int i =1; i<=n; i++)
//     {
//        int current_index = (start+i)%n;
//        if(fuel>=nums2[(start+i-1)%n])fuel=fuel-nums2[(start+i-1)%n]+nums1[current_index];
       
//        else{
//         return false;
//        }
//     }
//     return true;
// }
// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//      vector<int>potentialIndex;
//      for (int i = 0; i<gas.size(); i++)
//      {
//         if(gas[i]>=cost[i]){
//             if(check(i,gas,cost))return i;
//             }
//      }
      
//      return -1;
//     }

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int totalGas=0,totalCost=0;
     for (int i = 0; i <gas.size(); i++)
     {
        totalCost+=cost[i],totalGas+=gas[i];
     }
     if(totalCost>totalGas)return -1;

     int currentGas=0,start=0;
     for (int i = 0; i <gas.size(); i++)
     {
        currentGas+=gas[i]-cost[i];
        if(currentGas<0){
            currentGas=0;
            start=i+1;
        }
     }
    return start;
    }
};