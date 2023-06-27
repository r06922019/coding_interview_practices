class SmallestInfiniteSet
{
public:
    int fake_smallest = 1;
    set<int> s;
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        int ret = fake_smallest;
        if (s.empty())
        {
            ++fake_smallest;
        }
        else
        {
            auto it = s.begin();
            ret = *it;
            s.erase(it);
        }
        return ret;
    }

    void addBack(int num)
    {
        if (num < fake_smallest)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */