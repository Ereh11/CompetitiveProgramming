class Solution {
public:
    
    
    
    bool BS(vector<int>& time, int &totalTrips, long long &assuming_time)
    {
        long long ans = 0;
        
        for(auto& it: time)
            ans += (assuming_time / it); 
        
        return ans >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        
        long long l = 1, r = *min_element(time.begin(), time.end()) * (long long)totalTrips, assuming_time = 0;
        while(l <= r)
        {
            assuming_time = ((l + r) >> 1);
            
            if(BS(time, totalTrips, assuming_time)) 
                r = assuming_time - 1;
            else
                l = assuming_time + 1;
        }
        
        return l;
    }
};