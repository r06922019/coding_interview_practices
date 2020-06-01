class Solution {
public:
    int convert_skill(unordered_map<string, int> &skill_to_id, vector<string> &skills) {
        int ans = 0;
        for(string &skill : skills) {
            ans |= (1 << skill_to_id[skill]);
        }
        return ans;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skill_to_id;
        for(int i = 0; i < req_skills.size(); ++i) {
            skill_to_id[ req_skills[i] ] = i;
        }

        int target_skills = (1 << req_skills.size()) - 1;
        unordered_map<int, vector<int>> table; //table[skill_set] -> list of people

        vector<int> keys; // for updating
        table[0] = vector<int>();

        for(int i = 0; i < people.size(); ++i) {
            int cur_person_skill = convert_skill(skill_to_id, people[i]);

            keys.clear();
            for(auto &it:table)
                keys.push_back(it.first);
            sort(keys.rbegin(), keys.rend());

            for(int &key : keys) {
                int new_skill_set = key | cur_person_skill;
                if(table.find(new_skill_set) == table.end()) {
                    table[new_skill_set] = table[key];
                    table[new_skill_set].push_back(i);
                }
                else if(table[new_skill_set].size() > table[key].size()+1) {
                    table[new_skill_set] = table[key];
                    table[new_skill_set].push_back(i);
                }
            }
        }

        return table[target_skills];
    }
};