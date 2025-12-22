# Week3 Day3 Log

Today I completed my first full BFS (Breadth-First Search) implementation on a 2D grid.

## What I implemented

* Read and stored a grid map using `vector<string>`
* Located the start position `S` by scanning the grid
* Implemented BFS using a queue to expand states level by level
* Used a 2D `dist` array to track visited states and shortest distances
* Handled boundaries, walls (`#`), and revisits correctly
* Printed the distance grid for debugging and computed the maximum reachable distance

## Key understanding

* BFS explores states in layers using a FIFO queue
* Each grid cell should be processed exactly once
* The `dist` array serves both as a visited marker and a distance record
* `dx / dy` arrays unify direction handling and prevent repetitive code

## Project bridge

* BFS models state expansion from an initial condition
* Queue-based traversal matches event propagation logic in simulations

## Reflection

This task took longer than expected, but it helped me fully understand how BFS works internally instead of relying on templates.
