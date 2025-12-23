# Week3 Day4 Log

Today I practiced applying BFS to actual problems instead of re-implementing the algorithm.

## What I implemented

* Solved a grid-based shortest path problem using my BFS template
* Reused the same BFS structure with minimal changes
* Identified the problem state as a grid position `(row, col)`
* Used a `dist` array to track visited states and shortest distances
* Verified correctness using targeted debug output

## Key understanding

* BFS problems can be recognized by shortest-step and fixed-move patterns
* Defining the correct state matters more than rewriting code
* Initialization differences (single-source vs multi-source) change behavior, not the BFS loop itself

## Project bridge

* BFS models state expansion from multiple initial conditions
* Multi-source BFS mirrors parallel event propagation in simulations

## Reflection

Applying a reusable template reduced cognitive load and helped me focus on problem structure rather than implementation details.
