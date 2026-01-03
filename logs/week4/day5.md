## Week 4 · Day 5 — Bronze Stabilization + Modeling Correction

### What I worked on
Solved USACO 2025 US Open Bronze Problem 1 (Hoof Paper Scissors Minus One).
Built the full solution from scratch with guidance, focusing on:
- Correctly parsing the triangular win/lose table
- Building a clear representation of "which symbols beat which"
- Translating the phrase "guaranteed win" into a precise modeling condition

### Key difficulty
I initially misinterpreted "guaranteed win" as being able to respond differently to each of Elsie's choices.
After checking the sample output, I realized the game assumes simultaneous selection, which requires
a single symbol to beat both of Elsie's options.
This modeling correction was the hardest and most important part of today.

### What I learned
For problems involving "guarantees" under simultaneous decisions,
the correct model often requires finding an option that dominates all opponent choices,
not a combination that can respond separately.
This distinction directly affects how counting logic is built.

### Current status
I can now follow and understand the full solution structure line by line.
Next step is to re-implement this solution independently to fully internalize the model.
