
# Push_Swap - 42

## Description

Push_Swap is a project from the 42 School curriculum that involves sorting data on a stack, with a limited set of instructions, and the smallest number of actions. This project helps students learn about sorting algorithms and the concept of stack data structure in C language.

The project consists of two programs:
- `checker`, which takes integer arguments and reads instructions on the standard input. Once read, `checker` executes them and displays `OK` if integers are sorted, otherwise, it displays `KO`.
- `push_swap`, which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received.

## Instructions

- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : sa and sb at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : rra and rrb at the same time.

## Compilation

A Makefile is provided for compiling the programs. Run the following commands for respective outcomes:

```bash
make         # to compile both the checker and push_swap programs
make checker # to compile just the checker
make push_swap  # to compile just the push_swap
make clean   # to remove all object files
make fclean  # to remove all object files and the programs
make re      # to re-compile both programs
```

After running `make`, two executable files `checker` and `push_swap` should be created.

## Usage

To sort a list of integers:

```bash
./push_swap 5 2 3 1 4
```

To check if a list of integers is sorted:

```bash
ARG="5 2 3 1 4"; ./push_swap $ARG | ./checker $ARG
```

## Notes

The code adheres to The Norm (the 42 School's coding standard). Therefore, it follows a specific format and only includes certain C Standard Library functions.

## Authors and acknowledgment

This project is carried out by 42 students. We express gratitude to the pedagogical team for providing us a challenging platform to learn and grow.

## License

This project is licensed under the 42 School Norm. Feel free to use and adapt it while respecting the license.
```

Remember to modify this README based on your project's specific needs and functions. This is a general structure that should cover most of the requirements.
