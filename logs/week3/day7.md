# Week3 Day7 — Review + Silver→Gold Checklist

## One-sentence Positioning
Day7 is not solving problems; it is turning what I can do into what I know I can do.

## Session 1 — Week3 Skill Decomposition

### ✅ BFS Skills I actually did + debugged

- I implemented standard grid BFS using a 2D `dist` array and verified correctness by printing the distance grid and checking layer-by-layer expansion.

- I reused the same BFS template across different grid problems by only changing state initialization and transition conditions.

- I recognized when a simple `(r, c)` state was insufficient and expanded the BFS state to `(r, c, used)` to represent remaining resources.

- I correctly defined multi-dimensional distance arrays such as `dist[r][c][used]` and treated each combination as a distinct state.

- I debugged BFS logic errors caused by incorrect `visited` assumptions, dead code after `continue`, and missing state checks before pushing into the queue.

## Session 3 — Common BFS Failure Modes I Experienced

- Mistake:
  Writing logic after a `continue` statement in the BFS loop.
- Why it breaks BFS:
  Some valid transitions are skipped silently, causing certain states to never be pushed into the queue.
- What I will check next time:
  Ensure all state updates and checks are completed before any `continue`.

- Mistake:
  Treating `(r, c)` as the full state even when special actions or resources exist.
- Why it breaks BFS:
  Different paths that reach the same cell may leave different future possibilities, but they get incorrectly merged.
- What I will check next time:
  Ask whether reaching the same position in different ways leads to different future decisions.

- Mistake:
  Checking `visited` or `dist` inconsistently across transitions.
- Why it breaks BFS:
  Some states may be revisited infinitely or pruned incorrectly, breaking BFS correctness.
- What I will check next time:
  Ensure every transition is guarded by the same `dist` or visited condition before pushing.

