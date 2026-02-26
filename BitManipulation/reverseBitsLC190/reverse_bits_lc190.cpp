class Solution {
public:
    int reverseBits(int n) {
        // only using a new var, so const space
        int res=0;
        // traversing 32 bits of the input is const time
        for(int i=0;i<32;i++){
            res <<= 1;
            res |= n&1;
            n >>= 1;
        }
        return res;
    }
};