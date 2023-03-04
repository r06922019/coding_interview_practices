class PairHash
{
public:
    size_t operator()(const pair<int, int> &p) const
    {
        return p.first + ((p.second & 0x7FFF) << 15);
    }
};
typedef unordered_set<pair<int, int>, PairHash> PAIR_SET;
typedef unordered_map<pair<int, int>, int, PairHash> PAIR_MAP;
