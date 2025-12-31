# W4D2 Silver BFS Plan -- USACO 2016 February Contest, Silver, Problem 3. Milk Pails

- Is BFS needed? (Y/N): Y
- Why: Each move costs 1 step, and we need to explore states reachable within <= K steps to minimize |(a+b)-M|.
- State: (a, b) where a is water in bucket X, b is water in bucket Y.
- Transition: From (a, b), apply one action (fill/empty/pour) to get a new (a', b').
- Visited meaning: dist[(a, b)] is the minimum steps used to reach (a, b). If we reach it again with >= dist, we do not expand it.






