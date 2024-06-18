// Number of Rectangles in a Circle (MEDIUM)
// https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1


class Solution {
  public:
    int rectanglesInCircle(int r) {
        int dia = 2*r;
        int hypo = dia*dia, count = 0;
        
        for(int i=1;i<dia;i++){
            for(int j=1;j<dia;j++){
                int diag = (i*i + j*j);
                if(diag <= hypo) count++;
            }
        }
        
        return count;
    }
};
