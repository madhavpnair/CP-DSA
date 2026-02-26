## Implementation
One pass is sufficient, so `O(n)` time complexity<br>
We created a `res` array to store results which uses a `O(n)` space<br>

**the key idea is to merge all the intervals where the `start_i` of the given interval is less than or equal to the `end_i` of the interval to be inserted**


## TODO - improve for constant space
