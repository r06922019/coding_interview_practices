class Solution
{
public:
    bool is_valid(vector<int> &arr, int index)
    {
        return index >= 0 && index < arr.size();
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        // num1.size() is smaller, ensure the answer exists in 0~len1
        int total_len = nums1.size() + nums2.size();
        int half_len = total_len / 2;
        int l = 0, r = nums1.size();
        // binary search to check how many to include from nums1
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int len1 = mid;
            int len2 = half_len - len1;
            if (
                // right is sufficiently big, legally way
                (is_valid(nums2, len2 - 1) && is_valid(nums1, len1) && nums2[len2 - 1] <= nums1[len1]) ||
                // right is too big that causes problem
                (is_valid(nums2, len2) && is_valid(nums1, len1 - 1) && nums2[len2] <= nums1[len1 - 1]))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("l = %d\n", l);
        int len1 = l;
        int len2 = half_len - len1;
        // [....len1 elements, | len1, ....]
        // [....len2 elements, | len2, ....]
        if (total_len % 2 == 0)
        {
            // avg of left max and right min
            int left_max = INT_MIN;
            if (is_valid(nums1, len1 - 1))
            {
                left_max = max(left_max, nums1[len1 - 1]);
            }
            if (is_valid(nums2, len2 - 1))
            {
                left_max = max(left_max, nums2[len2 - 1]);
            }
            int right_min = INT_MAX;
            if (is_valid(nums1, len1))
            {
                right_min = min(right_min, nums1[len1]);
            }
            if (is_valid(nums2, len2))
            {
                right_min = min(right_min, nums2[len2]);
            }
            return (double)(left_max + right_min) / 2.0;
        }
        else
        {
            // len1 + len2 = half_len,
            // right size is half_len + 1
            // so the answer is right min
            int right_min = INT_MAX;
            if (is_valid(nums1, len1))
            {
                right_min = min(right_min, nums1[len1]);
            }
            if (is_valid(nums2, len2))
            {
                right_min = min(right_min, nums2[len2]);
            }
            return right_min;
        }
        return 0;
    }
};