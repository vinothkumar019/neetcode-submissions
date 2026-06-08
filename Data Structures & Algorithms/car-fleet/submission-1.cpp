class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
                
                        int n = position.size();

                                // pair -> {position, time_to_reach_target}
                                        vector<pair<int,double>> cars;

                                                for(int i = 0; i < n; i++) {
                                                            double time = (double)(target - position[i]) / speed[i];
                                                                        cars.push_back({position[i], time});
                                                                                }

                                                                                        // Sort by position
                                                                                                sort(cars.begin(), cars.end());

                                                                                                        stack<double> st;

                                                                                                                // Traverse from nearest car to target
                                                                                                                        for(int i = n - 1; i >= 0; i--) {

                                                                                                                                    double currTime = cars[i].second;

                                                                                                                                                // New fleet
                                                                                                                                                            if(st.empty() || currTime > st.top()) {
                                                                                                                                                                            st.push(currTime);
                                                                                                                                                                                        }
                                                                                                                                                                                                    // else:
                                                                                                                                                                                                                // current car joins fleet ahead
                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                return st.size();
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                    };
