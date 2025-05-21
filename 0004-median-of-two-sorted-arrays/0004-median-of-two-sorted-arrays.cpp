class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>arr;
        int i=0,j=0;
        while (i<n && j<m)
        {
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while (i<n)
        {
            arr.push_back(nums1[i]);
            i++;
        }
        while (j<m)
        {
            arr.push_back(nums2[j]);
            j++;
        }
        int total=arr.size();
       if((n+m)&1)return static_cast<double>(arr[total/2]);
       int m1=arr[total/2];
       int m2=arr[total/2-1];
       return (static_cast<double>(m1)+static_cast<double>(m2))/2.0;
    }
};