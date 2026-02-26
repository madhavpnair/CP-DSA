- we have to sort the given intervals based on the start_time
- **push the first interval to the result vector**
- Now, merging is simply done by comparing the end_time of the last pushed interval in the result vector with the start_time of the next interval - 
```
if(start_time of next interval > end_time of last pushed interval)
then overlap detected
```
thus we can detect overlaps and merge these two intervals by 
```
last_pushed_interval[end_time] = max (intervals[i][end_time], last_pushed_interva[end_time])
```
[1,3], [2,4] overlap.<br>
push [1,3] to `result` <br>
`2 < 3` implies `overlap` which is resolved by setting the last interval in `result` to `[1,max(3,4)] = [1,4]` 
- use while loop since we might be doing multiple merges continuously
- the result vector contains the merged intervals with all overlaps resolved at the end of the iterations

**TODO** <br>the implementation takes linear space and can be optimized to constant space 