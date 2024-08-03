// The Celebrity Problem (MEDIUM)
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1


class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m) {
        int n = m.size();
        int top = 0, bottom = n-1;
        while(top < bottom){
            if(m[top][bottom] == 1) top++;
            else if(m[bottom][top] == 1) bottom--;
            else{
                top++;
                bottom--;
            }
        }
        

        for(int i=0;i<n;i++){
            if(i != top && (m[i][top] == 0 || m[top][i] == 1)) return -1;
        }
        
        return top;
    }
};
