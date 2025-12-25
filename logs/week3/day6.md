# Week3 Day6 Log

## Focus

BFS with expanded state (introducing an extra dimension in state design).

This day is **not** about learning a new algorithm.
It is about understanding that **state definition determines BFS difficulty**, not the loop itself.

---

## Session 1 — State Analysis (No Code)

### CP1: Why is this a BFS problem?

* All moves have equal cost (each step costs 1).
* We are asked for the shortest path.
* There is no weighted edge, so Dijkstra is unnecessary.

**Conclusion:** This is a standard BFS problem with expanded state.

---

### CP2: State definition

State representation:

* Position: `(r, c)`
* Extra dimension: `used` (number of walls already broken)

Why `(r, c)` alone is insufficient:

* The same cell can be reached with different remaining resources.
* Reaching `(r, c)` with `used = 0` and `used = 1` leads to different future possibilities.
* Therefore, these must be treated as different states.

---

### CP3: Distance definition

Meaning of `dist[r][c][used]`:

* The minimum number of steps to reach cell `(r, c)` after breaking exactly `used` walls.

Initial values:

* All values initialized to `-1` (unvisited).
* Start state: `dist[sr][sc][0] = 0`.

Final answer selection:

* The target `(er, ec)` may be reached with different `used` values.
* The answer is the minimum `dist[er][ec][used]` for all `used <= K`.

---

## Session 2 — Implementation Notes

Key implementation decisions:

* The BFS queue stores `(r, c, used)` as a single state.
* `nused` defaults to `cur.used` and only increases when a wall is broken.
* Wall handling and non-wall handling share the same BFS structure.
* A 3D `dist` array replaces a simple 2D `visited` array.

Critical rule:

* **All transitions (wall and non-wall) must be checked against `dist` before pushing.**

---

## Error Recovery

Most likely bugs I encountered or may encounter again:

* Writing logic after `continue` (dead code).
* Forgetting to update `nused` when breaking a wall.
* Checking `visited/dist` only for walls, causing infinite queue expansion.

How I detected `visited` was insufficient:

* The same `(r, c)` reached with different `used` values produced different valid paths.
* This showed that `(r, c)` alone cannot represent a complete state.

What I will do next time:

* Immediately ask whether the state needs an extra dimension.
* Decide the full state before writing BFS code.

---

## Key Takeaway

* BFS complexity comes from **state design**, not the BFS loop.
* Expanded state increases correctness requirements but not algorithm type.
* Multi-dimensional `dist` is not dangerous; ignoring it is.

---

## Reflection

What felt uncomfortable today:

* Accepting that a simple grid problem needs a 3D distance array.

What feels clearer than before:

* BFS correctness depends on treating logically different situations as different states.

What I will watch for next time:

* Any problem involving limited resources, permissions, or special actions.
* These almost always imply state expansion.
