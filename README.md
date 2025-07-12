# BDD Test Helpers for Catch2

## Version: 1.0.0

> This library provides RSpec/speclj-style BDD syntax for Catch2.

```c++
// Usage:
// 1. Include Catch2 in your project
// 2. Include this header after Catch2
// 3. Write beautiful BDD-style tests

#include <catch2/catch_test_macros.hpp>
#include "bdd.hpp"
#include "tic_tac_toe.h"

describe("Tic Tac Toe", []() {
    Game* game;
    
    before_each([&]() {
        game = new Game();
    });
    
    after_each([&]() {
        delete game;
    });
    
    context("at game start", []() {
        it("has empty board", []() {
            should(game->isEmpty());
        });
        
        it("X plays first", []() {
            should_eq(game->currentPlayer(), 'X');
        });
    });
    
    context("making moves", []() {
        it("accepts valid moves", []() {
            should(game->makeMove(1, 1));
        });
        
        it("rejects occupied squares", []() {
            game->makeMove(1, 1);
            should_not(game->makeMove(1, 1));
        });
        
        it("alternates players", []() {
            should_eq(game->currentPlayer(), 'X');
            game->makeMove(0, 0);
            should_eq(game->currentPlayer(), 'O');
        });
    });
    
    context("error handling", []() {
        it("throws for out of bounds moves", []() {
            should_throw(game->makeMove(-1, 0));
            should_throw(game->makeMove(3, 0));
        });
        
        it("handles reset safely", []() {
            should_nothrow(game->reset());
        });
    });
});
```

Test closures capture symbols from the calling scope according to the following structue:

| Syntax    | Meaning                 | Use                            |
|-----------|-------------------------|--------------------------------|
| [&]       | All by reference        | Modifying shared test state    |
| [=]       | All by value            | Read-only/immutable data       |
| [&var]    | Specific by reference   | Only need one mutable variable |
| [var]     | Specific by value       | Need a copy of one variable    |
| [&, var]  | All by ref except var   | Mostly mutable, one immutable  |
| [=, &var] | All by value except var | Mostly immutable, one mutable  |
| []        | Capture nothing         | Self-contained test            |






