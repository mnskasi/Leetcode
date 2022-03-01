class Solution 
{
public:
    long long int numberOfTripsForGivenTime(vector<int>&a , long long int givenTime)
    {
        long long int totalTrips = 0;
        for(auto x : a)
        {
            // convert it to long long int 
            long long int val = x;
			
            totalTrips += (givenTime / val);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>& arr ,  int totalTrips) {
        long long int lowestTime = 1;
        long long int max1=*max_element(arr.begin(),arr.end());
        long long int highestTime = max1*totalTrips;
        while(lowestTime<highestTime)
        {
            long long int mid = lowestTime + (highestTime-lowestTime)/2;
            
            if(numberOfTripsForGivenTime(arr , mid) >= totalTrips)
                highestTime = mid;
            else
                lowestTime = mid+1;
        }
        return lowestTime;
    }
};