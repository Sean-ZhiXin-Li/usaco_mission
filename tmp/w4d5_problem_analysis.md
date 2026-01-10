### USACO 2023 February Contest, Silver --Problem 3. Moo Route II

- Is this a BFS problem? (Y/N): Yes, but not a pure BFS.
- What is the State: (airport_id, arrival_time)
- Initial state(s): (1, 0)  (starting at airport 1 at time 0; initial position does not require a layover wait)
- Transition rule: From (i, t), you may take any flight (i -> j) that departs at time r if r >= t + a[i]; taking it leads to (j, s).
- Visited meaning: For an airport/state, if we have already reached it at an earlier or equal arrival time, reaching it later is useless and can be ignored.
- Where the answer is obtained: For each airport i, the answer is the minimum arrival_time over all reachable states that land at airport i.
- One modeling risk: If visited is tracked only by airport_id, the first-arrival time would be frozen and later (earlier) arrivals would never be allowed to refresh the result, causing wrong answers.
