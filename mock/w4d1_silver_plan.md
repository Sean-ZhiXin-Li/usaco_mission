# W4D1 Silver BFS Plan

## Problem
- One-sentence goal: output the maximum number of cows that can be reached from one starting cow.

## State (complete)
- State = (cow_index)
- Why this is enough:
  - Each BFS node represents a cow.
  - Coordinates and power are attributes used only to decide reachability.

## dist meaning (one sentence)
- dist[i] = whether cow i has been reached.

## Transitions (neighbors)
- From cow i, I can go to cow j if the distance between i and j is <= power of cow i.

## Checklist triggered
- Directed graph reachability
- BFS from each possible start node

## Failure risks
- Treating (x, y, power) as part of state instead of attributes.
- Using sqrt and floating-point comparison instead of squared distance.
