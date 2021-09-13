class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto it = mp.upper_bound(start);
        //it contains the element if there's any
        //which ends after the start of current event
        //thus a red flag
        //Now to ascertain this we check if th end of event 
        //lies b/w some event as well
        
        //start || it->first(end) //plausible solution only if end < it->second(start) 
        //           it->second(start) || end //conflict
        if(it!=mp.end() && end > it->second)return false;
        mp.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */