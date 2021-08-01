/*
5187. Minimum Garden Perimeter to Collect Enough Apples

In a garden represented as an infinite 2D grid, there is an apple tree planted at every integer coordinate. The apple tree planted at an integer coordinate (i, j) has |i| + |j| apples growing on it.

You will buy an axis-aligned square plot of land that is centered at (0, 0).

Given an integer neededApples, return the minimum perimeter of a plot such that at least neededApples apples are inside or on the perimeter of that plot.

The value of |x| is defined as:

x if x >= 0
-x if x < 0

x = 1

2 1 2
1 0 1
2 1 2

total = 12
*/

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long x = 1;
        while( ((x+1)*(x+2*x*x))*2 < neededApples) {
            ++x;
        }
        return 8*x;
    }
};