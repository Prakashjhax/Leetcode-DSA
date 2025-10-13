class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start= 0, end=0, mid, ans=0, n=piles.size();

        for(int i=0;i<n; i++)
        {
            end=max(end,piles[i]);

        }
        start/=h;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            //mid amount of bananas to consume in 1 hour 
            int total_time =0;
            for(int i=0;i<n;i++)
            {
                total_time+=piles[i]/mid;
                if(piles[i]%mid)
                total_time++;
            }
            if(total_time>h)
            {
                start=mid+1;
            }
            else
            {
                ans=mid;
                end=mid-1;
            }    
        }
        return ans;
    }
};