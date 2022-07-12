class PairHash
{
public:
    size_t operator()(const pair<int, int> &p) const
    {
        return p.first ^ p.second;
    }
};
class Solution
{
public:
#define ll long long
    bool can_use(int unused, int use)
    {
        return ((~unused) & use) == 0;
    }

    void do_use(int &unused, int use)
    {
        unused &= ~use;
    }

    void do_unuse(int &unused, int use)
    {
        unused |= use;
    }

    ll sum_set(vector<ll> &matchsticks, int use)
    {
        ll ans = 0;
        for (int i = 0; i < matchsticks.size(); ++i)
        {
            if (use & (1 << i))
            {
                ans += matchsticks[i];
            }
        }
        return ans;
    }

    bool solve(int unused, const vector<int> &choices, int sides_remaining, unordered_map<pair<int, int>, int, PairHash> &dp)
    {
        const pair<int, int> k = {unused, sides_remaining};
        if (dp.find(k) != dp.end())
            return dp[k];
        if (sides_remaining == 1)
            return true;
        auto &dp_val = dp[k];
        for (auto choice : choices)
        {
            if (can_use(unused, choice))
            {
                do_use(unused, choice);
                if (solve(unused, choices, sides_remaining - 1, dp))
                {
                    dp_val = true;
                    return true;
                }
                do_unuse(unused, choice);
            }
        }
        dp_val = false;
        return false;
    }

    bool makesquare(vector<int> &_matchsticks)
    {
        vector<ll> matchsticks;
        for (auto m : _matchsticks)
            matchsticks.push_back(m);
        ll total = accumulate(matchsticks.begin(), matchsticks.end(), (ll)0);
        if (total % 4 != 0)
            return false;
        ll target_val = total >> 2;
        int n = matchsticks.size();
        vector<int> choices;
        for (int use = 0; use < (1 << n); ++use)
        {
            if (sum_set(matchsticks, use) == target_val)
            {
                choices.push_back(use);
            }
        }
        unordered_map<pair<int, int>, int, PairHash> dp;
        return solve((1 << n) - 1, choices, 4, dp);
    }
};
/*
class PairHash {
public:
    size_t operator()(const pair<int, int> &p) const {
        return p.first ^ p.second;
    }
};
class Solution {
public:
    #define ll long long
    vector<ll> sum_cache = vector<ll>(1<<15, -1);
    bool can_use(int unused, int use) {
        return ((~unused) & use) == 0;
    }

    void do_use(int &unused, int use) {
        unused &= ~use;
    }

    void do_unuse(int &unused, int use) {
        unused |= use;
    }

    ll sum_set(vector<ll> &matchsticks,int use) {
        if(sum_cache[use] == -1) {
            ll ans = 0;
            for(int i = 0; i < matchsticks.size(); ++i) {
                if(use & (1 << i)) {
                    ans += matchsticks[i];
                }
            }
            sum_cache[use] = ans;
        }
        return sum_cache[use];
    }

    bool can_achieve(vector<ll> &matchsticks, int unused, vector<ll> &sides, const int target_len, const ll target_val, vector<vector<int>> &dp) {
        if(unused == 0) return sides.size() == target_len;
        // pair<int, int> k = {unused, (int)sides.size()};
        // if(dp.find(k) != dp.end()) return dp[k];
        auto &dp_val = dp[sides.size()][unused];
        if(dp_val != -1) return dp_val;
        // dp[k] = false;
        dp_val = 0;
        for(int use = 0; use < (1 << matchsticks.size()) && !dp_val; ++use) {
            if(can_use(unused, use) && sum_set(matchsticks, use) == target_val) {
                do_use(unused, use);
                sides.push_back(use);
                dp_val = dp_val | can_achieve(matchsticks, unused, sides, target_len, target_val, dp);
                sides.pop_back();
                do_unuse(unused, use);
            }
        }
        return dp_val;
    }

    bool makesquare(vector<int>& _matchsticks) {
        vector<ll> matchsticks;
        for(auto m : _matchsticks) matchsticks.push_back(m);
        ll total = accumulate(matchsticks.begin(), matchsticks.end(), (ll)0);
        if(total % 4 != 0) return false;
        ll target_val = total >> 2;
        int unused = (1 << matchsticks.size()) - 1;
        vector<ll> sides;
        // unordered_map<pair<int,int>,bool,PairHash> dp;
        vector<vector<int>> dp(4+1, vector<int>(unused+1, -1));
        dp[0][0] = 1;
        return can_achieve(matchsticks, unused, sides, 4, target_val, dp) == 1;
    }
};
*/
/*
class Solution {
public:
    #define ll long long
    bool can_use(int unused, int use) {
        return ((~unused) & use) == 0;
    }

    void do_use(int &unused, int use) {
        unused &= ~use;
    }

    void do_unuse(int &unused, int use) {
        unused |= use;
    }

    ll sum_set(vector<ll> &matchsticks,int use) {
        ll ans = 0;
        for(int i = 0; i < matchsticks.size(); ++i) {
            if(use & (1 << i)) {
                ans += matchsticks[i];
            }
        }
        return ans;
    }

    bool makesquare(vector<int>& _matchsticks) {
        vector<ll> matchsticks;
        for(auto m : _matchsticks) matchsticks.push_back(m);
        ll total = accumulate(matchsticks.begin(), matchsticks.end(), (ll)0);
        if(total % 4 != 0) return false;
        ll target_val = total >> 2;
        int n = matchsticks.size();
        vector<int> choices;
        for(int use = 0; use < (1 << n) ; ++use) {
            if(sum_set(matchsticks, use) == target_val) {
                choices.push_back(use);
            }
        }
        unordered_set<int> a_b;
        for(auto a : choices) {
            for(auto b : choices) {
                a_b.insert(a | b);
            }
        }
        int mask = (1 << n)-1;
        for(auto ab : a_b) {
            if(a_b.find( mask - ab ) != a_b.end()) return true;
        }
        return false;
    }
};

*/