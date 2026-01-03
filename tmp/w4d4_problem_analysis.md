### USACO 2014 December Contest, Silver--Problem 1. Piggyback
- Is this a BFS problem? (Y): Yes, the graph is unweighted and all moves have equal step cost.
- Why BFS instead of brute force? BFS gives the minimum number of steps from a source to all fields efficiently.
- State definition: State = current field (node index).
- Initial state(s): Field 1 for Bessie's BFS, field 2 for Elsie's BFS, and field N for the barn BFS.
- Transition types (list): Move along an edge to an adjacent field.
- Visited meaning: dist[u] represents the minimum number of steps required to reach field u from the source.
- What is the answer asking for? The minimum total energy, computed by combining BFS distances at a meeting field.
