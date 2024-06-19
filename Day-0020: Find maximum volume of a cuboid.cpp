// Find maximum volume of a cuboid (EASY)
// https://www.geeksforgeeks.org/problems/magical-box5306/1

class Solution {
  public:
    double maxVolume(double p, double area) {
        double d=sqrt(pow(p,2)-24*area);
        double h=(p-d)/12;
        double vol=h*(p*h-8*pow(h,2))/4;
        return vol;
    }
};
