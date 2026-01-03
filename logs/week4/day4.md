# Week 4 · Day 4 — BFS → Usable Problem-Solving Tool

## What I attempted today

Applied a hand-built BFS engine to a real USACO Silver problem (Piggyback).
I implemented BFS as a reusable function, ran it from multiple sources,
and combined the resulting distance tables to model a meeting-point optimization problem.

## What broke

1. I initially misunderstood the interaction between `freopen` and `cin`,
   which caused invalid input reads and runtime/memory errors.
   The fix was to ensure file redirection happens before any input operation.

2. While the BFS logic itself was correct, translating problem semantics
   into a clean cost model required careful separation between
   “distance in edges” and “energy cost,” especially when combining results.

## What I will do differently next time

Treat input handling and execution environment (file vs stdin) as part of the model,
not as an afterthought, before debugging algorithm logic.
