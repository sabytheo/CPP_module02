*This project has been created as part of the 42 curriculum by tsaby.*

# C++ Module 02

> Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form

## Description

A `Fixed` point number class built step by step, following the Orthodox Canonical Form.

Part of the C++ piscine of the 42 curriculum: every exercise is written in **C++98** and compiled with `-Wall -Wextra -Werror -std=c++98`.

## Exercises

| Exercise | Name | What it does |
|---|---|---|
| [`ex00`](ex00/) | My First Class in Orthodox Canonical Form | `Fixed` with default constructor, copy constructor, copy assignment operator and destructor, plus raw bit accessors. |
| [`ex01`](ex01/) | Towards a more useful fixed-point number class | Conversion constructors from `int` and `float`, `toInt()` / `toFloat()` and an `operator<<` overload. |
| [`ex02`](ex02/) | Now we're talking | Comparison, arithmetic and increment/decrement operators, plus static `min` / `max` helpers. |

## Instructions

Each exercise is an independent program with its own `Makefile`:

```bash
cd ex00
make
```

| Exercise | Binary | Usage |
|---|---|---|
| `ex00` | `First` | `./First` |
| `ex01` | `Useful` | `./Useful` |
| `ex02` | `Talk` | `./Talk` |

`make clean` removes the object files, `make fclean` also removes the binary and `make re` rebuilds from scratch.

## Resources

- [cppreference.com](https://en.cppreference.com/w/cpp) — language and standard library reference
- [cplusplus.com](https://cplusplus.com/reference/) — C++98 standard library reference
