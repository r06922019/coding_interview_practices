class Bitset
{
public:
    vector<bool> bits;
    int size;
    int sum = 0;
    bool flipped = false;
    string str;
    Bitset(int _size) : bits(_size, false)
    {
        size = _size;
    }

    void fix(int idx)
    {
        if (flipped)
        {
            if (bits[idx])
            {
                bits[idx] = false;
                --sum;
            }
        }
        else
        {
            if (!bits[idx])
            {
                bits[idx] = true;
                ++sum;
            }
        }
    }

    void unfix(int idx)
    {
        if (flipped)
        {
            if (!bits[idx])
            {
                bits[idx] = true;
                ++sum;
            }
        }
        else
        {
            if (bits[idx])
            {
                bits[idx] = false;
                --sum;
            }
        }
    }

    void flip()
    {
        flipped = !flipped;
    }

    bool all()
    {
        return (flipped) ? sum == 0 : sum == size;
    }

    bool one()
    {
        return (flipped) ? sum < size : sum > 0;
    }

    int count()
    {
        return (flipped) ? size - sum : sum;
    }

    string toString()
    {
        string s = "";
        for (int i = 0; i < size; ++i)
        {
            if (flipped)
            {
                s += (bits[i]) ? '0' : '1';
            }
            else
            {
                s += (!bits[i]) ? '0' : '1';
            }
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */