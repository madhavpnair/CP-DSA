## Problem definition
cheapest cost from `src` to `dst` using **at most k stops**

### key observations
k stops implies k+1 edges from `src` to `dst`

## Approach - Modify Bellman Ford
Bellman-Ford normally relaxes edges V-1 times since shortest paths can have at most V - 1 edges<br>
here, relax all edges k+1 times because we only allow paths of length <= k+1 edges

### Why not Dijkstra?
This can be solved by Dijkstra also since no edges are negative! We have to consider a graph on  expanded state space since **a node reached with different stop counts represents different states**.<br>
Implement Dijkstra using a **priority queue of `{cost, current_node, stops_taken}`**. Use an array (e.g., `dist[node]`) to track the minimum stops used to reach each node at a certain cost, or more commonly, use `stops[node]` to keep track of the minimum stops it took to reach a node. If you reach a node and both your current cost is higher than a previous visit AND you've used more stops, you can safely prune that path.<br>

BF offers a clean implementation since we can control the number of edges (or stops) easily.

### Why `temp[]`? Ans: edge limit control
Normal BF uses only `dist[]` to store and update the single source shortest distances while we modified it and use another array `temp[]` for each iteration.<br>

Because in the modified version, **each iteration must strictly represent paths using exactly one additional edge**. If we update `dist` in-place, we may use newly updated values within the same iteration, effectively allowing more than `k` edges. <br>In normal BF, there is no such strict edge limit, so in-place updates are safe since longer paths propogate early due to in-place updates, but correctness is not affected because we eventually perform `V-1` iterations<br>

eg : 
```
0 --> 1 : cost = 100
1 --> 2 : cost = 100
```
suppose k=0, src=0, dst=2<br>
k+1 = 1<br>
if we update in-place during the first iteration:
1. Relax 0 --> 1 , so dist[1] = 100
2. Immediately relax 1 --> 2, giving dist[2] = 200<br>

now we have effectively used 2 edges in this single iteration!!!
<br>
Using `temp[]` prevents this.<br>
**We always relax edges using values from the previous iteration (`dist[]`) and write updates into `temp[]`.**<br> This ensures each iteration increases the allowed path length by exactly one edge
