class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        for (auto& i : access_times) {
            mp[i[0]].push_back(stoi(i[1]));
        }

        vector<string> res;
        for (auto i : mp) {
            sort(i.second.begin(), i.second.end());
            for(int j=0; j < int(i.second.size()) - 2; j++) {
              if(abs(i.second[j]-i.second[j+1])<100 && abs(i.second[j]-i.second[j+2])<100)
                {
                    res.push_back(i.first);
                    break;
                }
            }
        }

        return res; 
    }
};