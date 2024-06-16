// Prime Pair with Target Sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/sum-of-prime4751/1


class Solution {
  public:
    vector<int> getPrimes(int n) {
    vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        
        for(int p = 2; p <= sqrt(n); p++){
            if(is_prime[p]){
                for(int i = p*p; i <= n; i += p){
                    is_prime[i] = false;
                }
            }
        }
        
        
        // using two-pointer to find pair that is equal to sum
        int i = 2;
        int j = n;
        while(!is_prime[j])j--;
        
        while(i <= j){
            int sum = i + j;
            if(sum == n) return {i, j};
            else if (sum > n){
                j--;
                while(!is_prime[j]) j--;
            }
            else{
                i++;
                while(!is_prime[i]) i++;
            }
        }
        
        return {-1, -1};

}

};
