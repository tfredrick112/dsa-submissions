class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if (A.size() > B.size())
        {
            swap(A, B);
        }

        int m = A.size(), n = B.size();
        int total = m + n;
        int half = total / 2;

        int l = 0, r = m - 1;

        while (true)
        {
            int i = floor((l + r)/2.0);
            int j = half - i - 2;

            int Aleft = i >= 0 ? A[i] : INT_MIN;
            int Aright = i < m - 1 ? A[i + 1] : INT_MAX;
            int Bleft = j >= 0 ? B[j] : INT_MIN;
            int Bright = j < n - 1 ? B[j + 1] : INT_MAX;

            if (Aright >= Bleft && Bright >= Aleft)
            {
                if (total % 2 == 0)
                {
                    return (max(Aleft, Bleft) + min(Aright, Bright))/2.0;
                }
                else
                {
                    return min(Aright, Bright);
                }
            }
            else if (Aleft > Bright)
            {
                r = i - 1;
            }
            else if (Bleft > Aright)
            {
                l = i + 1;
            }
        }

        return 0;
    }
};
