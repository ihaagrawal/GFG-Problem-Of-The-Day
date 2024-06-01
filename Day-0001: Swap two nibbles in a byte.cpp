// Swap two nibbles in a byte (EASY)
// https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1

class Solution {
  public:
    int swapNibbles(int n) {
     
        int lower = n & 0x0F; //AND n with 00001111 to get lower nibble
        int upper = (n & 0xF0) >> 4; //AND n with 11110000 and shift right by 4 places to get upper nibble
        int shiftedLower = lower << 4; //now shift the lower nibble left by 4 
        int result = shiftedLower | upper; //OR shiftedLower with upper to get swapped number
        return result;
    }
};
