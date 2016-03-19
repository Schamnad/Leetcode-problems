// 4. Median of Two Sorted Arrays
//
// There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double FMSA(vector<int>::iterator nums1, int len1, vector<int>::iterator nums2, int len2, int k){

    	if(len1 > len2)
    		return FMSA(nums2,len2,nums1,len1,k);

    	if(len1==0)
    		return *(nums2 + k-1);

    	if(k==1)
    		return min(*nums1,*nums2);

    	int pa = min(len1,k/2);
    	int pb = k-pa;

    	if(*(nums1 + pa-1) == *(nums2+ pb-1))
    		return *(nums1+pa-1);
    	else if(*(nums1 + pa-1) < *(nums2+ pb-1))
    		return FMSA((nums1+pa),len1-pa,nums2,len2,k-pa);
    	else
    		return FMSA(nums1,len1,nums2+pb,len2-pb,k-pb);
    }



    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int total = len1+len2;

        if(total % 2 == 1)
        	return FMSA(nums1.begin(),len1,nums2.begin(),len2, total/2 +1);
        else
        	return (FMSA(nums1.begin(),len1,nums2.begin(),len2, total/2) + FMSA(nums1.begin(),len1,nums2.begin(),len2, (total)/2 +1))/2.0;
    }
};
