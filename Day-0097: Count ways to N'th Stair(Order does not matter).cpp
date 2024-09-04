// Count ways to N'th Stair(Order does not matter) (MEDIUM)
// https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1


class Solution{
	public:
		int nthStair(int n){
		    int count = 0;
        
            for (int y = 0; y <= n / 2; ++y) {
                int x = n - 2 * y; 
                if (x >= 0) ++count;
            }
            
            return count;
		}
};
