class NumberContainers
{
public:
    unordered_map<int, int> index_to_number;
    unordered_map<int, set<int> > number_to_indexes;
    NumberContainers() {}

    void change(int index, int number)
    {
        if (index_to_number.find(index) != index_to_number.end())
        {
            auto original_num = index_to_number[index];
            number_to_indexes[original_num].erase(index);
        }
        index_to_number[index] = number;
        number_to_indexes[number].insert(index);
    }

    int find(int number)
    {
        if (number_to_indexes.find(number) == number_to_indexes.end())
        {
            return -1;
        }
        else
        {
            if (number_to_indexes[number].empty())
                return -1;
            return *number_to_indexes[number].begin();
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */