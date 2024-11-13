class MyCalendarThree {
    multiset<pair<int, int>> st;
public:
    MyCalendarThree() {}
    
    int book(int startTime, int endTime) {
        st.insert({startTime, 1});
        st.insert({endTime, -1});

        int currOverlap = 0, k = 0;
        for (auto it : st) {
            currOverlap += it.second;
            k = max(k, currOverlap);
        }

        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */