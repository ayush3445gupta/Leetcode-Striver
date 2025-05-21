class Solution {
public:
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         int m=nums2.size();
//         vector<int>arr;
//         int i=0,j=0;
//         while (i<n && j<m)
//         {
//             if(nums1[i]<nums2[j]){
//                 arr.push_back(nums1[i]);
//                 i++;
//             }
//             else{
//                 arr.push_back(nums2[j]);
//                 j++;
//             }
//         }
//         while (i<n)
//         {
//             arr.push_back(nums1[i]);
//             i++;
//         }
//         while (j<m)
//         {
//             arr.push_back(nums2[j]);
//             j++;
//         }
//         int total=arr.size();
//        if((n+m)&1)return static_cast<double>(arr[total/2]);
//        int m1=arr[total/2];
//        int m2=arr[total/2-1];
//        return (static_cast<double>(m1)+static_cast<double>(m2))/2.0;
//     }
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=0; 
        int n=(n1+n2);
        int ind2=n/2;
        int ind1=ind2-1;
        int cnt=0;
        int ind1el=-1,ind2el=-1;
        while (i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j]){
                if(cnt==ind1)ind1el=nums1[i];
                if(cnt==ind2)ind2el=nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==ind1)ind1el=nums2[j];
                if(cnt==ind2)ind2el=nums2[j];
                cnt++;
                j++;
            }
        }
        while (i<n1)
        {
                if(cnt==ind1)ind1el=nums1[i];
                if(cnt==ind2)ind2el=nums1[i];
                cnt++;
                i++;
        }      
        while (j<n2)
        {
                if(cnt==ind1)ind1el=nums1[j];
                if(cnt==ind2)ind2el=nums1[j];
                cnt++;
                j++;
        }      
    if(n&1)return ind2el;
    return double((double)(ind2el+ind1el))/2.0;
}
};