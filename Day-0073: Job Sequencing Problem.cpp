// Job Sequencing Problem (MEDIUM)
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1


/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool cmp(const Job& a, const Job& b){
        return a.profit > b.profit;
    }
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, cmp);
        
        int max_dead = INT_MIN;
        for(int i=0;i<n;i++) max_dead = max(max_dead, arr[i].dead);
        
        vector<int> jobs(max_dead+1, -1);
        
        int max_profit = 0, count=0;
        for(int i=0;i<n;i++){
            int currDead = arr[i].dead;
            int currProfit = arr[i].profit;
            int currId = arr[i].id;
            
            for(int k=currDead;k>0;k--){
                if(jobs[k] == -1){
                    jobs[k] = currId;
                    max_profit += currProfit;
                    count++;
                    break;
                }
            }
        }
        
        return {count, max_profit};
    } 
};
