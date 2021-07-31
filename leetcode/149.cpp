class PairHash {
public:
    size_t operator()(const pair<int, int> &p) const {
        size_t x = 0;
        x ^= p.first;
        x ^= p.second;
        return x;
    }
};

class Solution {
public:

    int gcd(int x, int y) {
        if(x < y) return gcd(y,x);
        if(y == 0) return x;
        return gcd(y, x%y);
    }

    pair<int, int> get_m(int x1, int y1, int x2, int y2) {
        int dx = x2-x1;
        if(dx == 0) return {0,0};
        int dy = y2-y1;
        if(dy == 0) return {0,1};
        int sign = 1;
        if(dy < 0 && dx > 0) {
            sign = -1;
            dy = -dy;
        }
        else if(dy > 0 && dx < 0) {
            sign = -1;
            dx = -dx;
        }
        else if(dy < 0 && dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        int gcd_dx_dy = gcd(dx,dy);
        return {sign*dy/gcd_dx_dy, dx/gcd_dx_dy};
    }

    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1;
        int max_count = 0, n = points.size();
        for(int i = 0; i < n; ++i) {
            unordered_map<pair<int, int>, int, PairHash> counter;
            for(int j = i+1; j < n; ++j) {
                ++counter[get_m(points[i][0], points[i][1], points[j][0], points[j][1])];
            }
            for(auto &p : counter) {
                max_count = max(max_count, p.second+1);
            }
        }
        return max_count;
    }
};