// Job Sequencing Problem (MEDIUM)
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int u, int v) {
        parent[u] = v;
    }
};

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs(n);
    
        for (int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]};
        }
    
        sort(jobs.rbegin(), jobs.rend());
    
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].second);
        }
    
        DisjointSet ds(maxDeadline);
        int totalProfit = 0, jobCount = 0;
    
        for (int i = 0; i < n; i++) {
            int profit = jobs[i].first;
            int deadline = jobs[i].second;
    
            int availableSlot = ds.find(deadline);
            if (availableSlot > 0) {
                ds.merge(availableSlot, availableSlot - 1);
                totalProfit += profit;
                jobCount++;
            }
        }
    
        return {jobCount, totalProfit};
            
    }
};
