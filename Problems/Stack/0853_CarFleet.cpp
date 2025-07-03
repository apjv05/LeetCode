int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int,int>> highway;
    vector<double> cars;

    for(int i = 0; i < position.size(); i++) {
        highway.push_back({position[i], speed[i]});
    }

    sort(highway.rbegin(), highway.rend());

    for(auto& p : highway) {
        cars.push_back((double)(target - p.first) / p.second);

        //if a car collides with another car we only need 
        //to worry about the car with the greatest time
        if(cars.size() >= 2 && cars.back() <= cars[cars.size() - 2]) {
            cars.pop_back();
        }
    }
    return cars.size();
}