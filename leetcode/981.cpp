class TimeMap
{
public:
    unordered_map<string, map<int, string>> m;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto &mm = m[key];
        if (mm.find(timestamp) != mm.end())
            return mm[timestamp];
        auto ub = mm.upper_bound(timestamp);
        if (ub == mm.begin())
            return "";
        ub--;
        return ub->second;
    }
};

/**
 * @brief 
 * 
 */
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */