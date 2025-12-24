# Week3 Day5 Log

Goal: Speed + stability for BFS. No new algorithms.

## Session 1: Pattern recognition

Problem 1 (Standard BFS):
- BFS? (why): Yes, this is a shortest-path problem with equal-cost moves. so BFS works.
- State = (r, c)
- Single or multi-source = Single

### Error Recovery — Problem 1 (Standard BFS)

Most likely mistake:
- Confusing assignment (`=`) with comparison (`==`) when checking grid cells, and mixing up coordinate storage with distance values.

How I fixed it:
- Replaced all assignment operators with comparisons, stored the target as coordinates `{i, j}` instead of `dist[i][j]`, and corrected wall checks to use the grid (`g`) rather than the distance array.

The line I will watch next time:
- Grid condition checks (`g[r][c] == ...`) and target initialization lines, especially where coordinates and distances are handled together.


Problem 2(Silver variant: 0-1 BFS with arrows):
- BFS? (why): Yes, This is a shortest-path problem with 0/1 edge costs, so 0-1 BFS is suitable.
- State: (r,c)
- Single or multi-source = Single

Independent thinking:
- Why normal BFS (queue) is not enough:
  When edge costs can be 0 or 1, the equal-cost assumption breaks, so a normal queue cannot guarantee shortest paths.
- Why deque works:
  Deque allows pushing 0-cost moves to the front and 1-cost moves to the back, preserving the correct shortest-path order.

### Error Recovery — Problem 2 (0-1 BFS)

Most likely mistake:
- Forgetting that states must carry (d,r,c) in the deque, or pushing neighbors even when no relaxation happened.

How I fixed it:
- Stored (d,r,c) in the deque and added a stale-state guard (skip if d != dist[r][c]); only push when nd improves dist.

The line I will watch next time:
- The relax block: `if (nd < dist[nr][nc]) { ... push_front/back ... }` and the tuple arguments `(nd, nr, nc)`.


