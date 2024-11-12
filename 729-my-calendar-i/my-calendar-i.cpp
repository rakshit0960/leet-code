class MyCalendar {
    set<pair<int, int>> st;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {

        auto it = st.lower_bound({startTime, endTime});

        if (it != st.end() and it->first < endTime) {
            return false;
        }

        if (it != st.begin() and (--it)->second > startTime) {
            return false;
        }

        st.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */