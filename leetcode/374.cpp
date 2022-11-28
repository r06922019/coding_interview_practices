/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (guess(mid) == 1)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};