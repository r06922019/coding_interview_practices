class Solution
{
public:
    bool start_with_10(const int x)
    {
        return (x & 0b11000000) == 0b10000000;
    }

    bool is1(const vector<int> &data, const int i)
    {
        // printf("%s\n",__func__);
        return (i + 1 <= data.size()) && ((data[i] & 0x80) == 0);
    }

    bool is2(const vector<int> &data, const int i)
    {
        // printf("%s\n",__func__);
        return (i + 2 <= data.size()) && ((data[i] & 0b11100000) == 0b11000000) && start_with_10(data[i + 1]);
    }

    bool is3(const vector<int> &data, const int i)
    {
        // printf("%s\n",__func__);
        return (i + 3 <= data.size()) && ((data[i] & 0b11110000) == 0b11100000) && start_with_10(data[i + 1]) && start_with_10(data[i + 2]);
    }

    bool is4(const vector<int> &data, const int i)
    {
        // printf("%s\n",__func__);
        return (i + 4 <= data.size()) && ((data[i] & 0b11111000) == 0b11110000) && start_with_10(data[i + 1]) && start_with_10(data[i + 2]) && start_with_10(data[i + 3]);
    }

    bool validUtf8(vector<int> &data)
    {
        int i = 0;
        while (i < data.size())
        {
            printf("i = %d\n", i);
            if (is1(data, i))
            {
                ++i;
            }
            else if (is2(data, i))
            {
                i += 2;
            }
            else if (is3(data, i))
            {
                i += 3;
            }
            else if (is4(data, i))
            {
                i += 4;
            }
            else
            {
                return false;
            }
        }
        return i == data.size();
    }
};