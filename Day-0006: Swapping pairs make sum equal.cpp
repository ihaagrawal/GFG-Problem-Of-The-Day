// Swapping pairs make sum equal (MEDIUM)
// https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++) sum1+=a[i];
        for(int i=0;i<m;i++) sum2+=b[i];
        sort(a,a+n);
        sort(b,b+m);
        if(sum1<sum2){
            int i=0 ,j=m-1;
            while(i<n && j>=0 && b[j]-a[i] >0){
                int x=b[j]-a[i];
                if(sum1+x == sum2-x) return 1;
                i++;
                j--;
            }
        }
        else if(sum1>sum2){
            int i=0,j=n-1;
            while(i<m && j>=0 && a[j]-b[i]>0){
                int x=a[j]-b[i];
                if(sum1-x == sum2+x) return 1;
                i++;
                j--;
            }
        }
        if(sum1==sum2) return 1;
        return -1;
    }
};
