class UndergroundSystem {
    unordered_map<int,pair<string,int>> st;
    
    // stores total travel time between each source and destination
    unordered_map<string,unordered_map<string,double>> avg;
    
    // store total no of travels from source to destination
    unordered_map<string,unordered_map<string,int>> count;
public:
    UndergroundSystem() {
        st.clear();
        avg.clear();
    }
    
    // initialize new travel for id
    void checkIn(int id, string stationName, int t) {
        st[id] = make_pair(stationName,t);
    }
    
    // increment travel time and no of travels from id's source to destination
    void checkOut(int id, string stationName, int t) {
        double time = t - st[id].second;
                
        if (!(avg.count(st[id].first) and avg[st[id].first].count(stationName)))
            avg[st[id].first][stationName] = 0;
            
        avg[st[id].first][stationName] += time;
        ++count[st[id].first][stationName];
        
        st.erase(id);
    }
    
    // return the avg (total travel time / total no of travels)
    double getAverageTime(string startStation, string endStation) {
        return avg[startStation][endStation] / count[startStation][endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */