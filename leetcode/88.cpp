class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        auto merged = nums1.rbegin(), head1 = nums1.rbegin() + n, head2 = nums2.rbegin(), end1 = nums1.rend(), end2 = nums2.rend();
        while (head1 != end1 || head2 != end2)
        {
            if (head2 == end2 || (head1 != end1 && *head1 > *head2))
            {
                *merged = *head1;
                ++head1;
            }
            else
            {
                *merged = *head2;
                ++head2;
            }
            ++merged;
        }
    }
};