// Minimum Cost of ropes (EASY)
// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());

        while(pq.size() > 1){
            
            long long smallest = pq.top();
            pq.pop();
            smallest += pq.top();
            pq.pop();
            
            sum += smallest;
            pq.push(smallest);
        }
        
        return sum;
    }
};
