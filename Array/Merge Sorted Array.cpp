class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0,j =0;
        //O(N+M)
        while(i<m && j<n) result.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);

        //TO check which list is inserted into list
        while(j<n) result.push_back(nums2[j++]);
        while(i<m) result.push_back(nums1[i++]);
        nums1 = result;


    }
};