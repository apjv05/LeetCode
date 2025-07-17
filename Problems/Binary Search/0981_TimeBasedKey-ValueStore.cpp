class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> Map;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        Map[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        auto& values = Map[key];
        int floor = 0, ceiling = values.size() - 1;
        string output = "";

        while(floor <= ceiling) {
            int mid = (floor + ceiling) / 2;

            if(values[mid].second <= timestamp) {
                output = values[mid].first;
                floor = mid + 1;
            }
            else ceiling = mid - 1;
        }
        return output;
    }
    //almost had this problem, only had to figure 
    //out how to retrieve the most recent set when
    //there was no exact time match
};