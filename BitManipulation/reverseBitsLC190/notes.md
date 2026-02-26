- the problem demands both `O(1)` time and space solution
  - traversing the 32 bits of the input is not linear time but takes constant time only
  - using the `res` variable which is to be returned needs no additional space

- **observe the movement of `res` and `n` in opposite directions to realize reversing**

```
res <<= 1  // creates space
res |= n&1 // accomodate last bit of n in the space created
n >>= 1    // the next bit of the input comes to the play
``` 