*This project has been created as part of the 42 curriculum by abenich, efresnil.*

# Push_swap

## Description

Push_swap is a 42 sorting project written in C. The program receives a list of integers and prints a sequence of Push_swap operations that sorts them in ascending order, with the smallest number at the top of stack `a`.

The program works with two stacks:

- `a`: contains all input integers at the beginning.
- `b`: starts empty and is used as temporary storage during sorting.

The only operations that may be printed are:

`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

This implementation includes four strategies required by the subject:

- Simple: `O(n^2)`
- Medium: `O(n sqrt(n))`
- Complex: `O(n log n)`
- Adaptive: selects an internal strategy using the disorder metric

Complexity here refers to the number of Push_swap operations generated, not only to internal C loops.

## Group Project / Contributors

This project was completed by exactly two learners:

- abenich
- efresnil

The repository history and file headers show work from both contributors. The exact individual split cannot be fully inferred from the current repository alone, so the contribution summary is intentionally general: both learners collaborated on parsing and validation, stack operations, sorting strategies, benchmark integration, debugging, testing, Norminette cleanup, code review, and integration. Both learners are responsible for understanding and defending the full mandatory implementation.

## Instructions

Compile the project with:

```sh
make
```

The Makefile builds the executable:

```txt
push_swap
```

Supported Makefile rules:

```sh
make
make all
make clean
make fclean
make re
```

Compilation uses:

```txt
-Wall -Wextra -Werror -I.
```

## Usage

Basic usage:

```sh
./push_swap 5 4 3 2 1
```

Strategy selectors:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

When no selector is supplied, the program uses the adaptive strategy by default.

Quoted and mixed numeric arguments are supported through `ft_split`:

```sh
./push_swap "5 4" 3 "2 1"
```

This is parsed as:

```txt
5 4 3 2 1
```

## Error Handling

Invalid input prints:

```txt
Error
```

to standard error.

The parser handles:

- non-integer arguments
- values outside the signed `int` range
- duplicate integers
- invalid strategy selectors
- empty or invalid numeric arguments

Behavior confirmed by the implementation:

- no arguments produce no output
- already sorted input produces no operations
- invalid input prints `Error` followed by a newline on stderr

## Push_swap Operations

- `sa`: swap the first two elements of stack `a`
- `sb`: swap the first two elements of stack `b`
- `ss`: perform `sa` and `sb` together
- `pa`: push the top element of `b` to `a`
- `pb`: push the top element of `a` to `b`
- `ra`: rotate stack `a` upward
- `rb`: rotate stack `b` upward
- `rr`: perform `ra` and `rb` together
- `rra`: reverse rotate stack `a`
- `rrb`: reverse rotate stack `b`
- `rrr`: perform `rra` and `rrb` together

## Disorder Metric

The disorder metric is computed before sorting. It is based on inversion counting:

```txt
disorder = inversions / maximum_possible_inversions
maximum_possible_inversions = n * (n - 1) / 2
```

A sorted input has disorder `0`. A reverse sorted input has disorder `1`. Internally, the value is represented between `0` and `1`.

Benchmark mode displays disorder as a percentage with two decimal places. For example:

```txt
0.7333 -> 73.33 %
```

## Sorting Algorithms

### Simple Strategy - O(n^2)

The simple strategy uses a minimum-extraction approach:

- find the smallest value in stack `a`
- move it to the top with rotations
- push it to stack `b`
- repeat until a small stack remains
- sort the small remaining stack
- push saved elements back to `a`

Because each extracted value may require scanning/moving through a large part of the stack, the Push_swap operation upper bound is `O(n^2)`.

### Medium Strategy - O(n sqrt(n))

The medium strategy uses ranking and chunk-based movement:

- values are converted into ranks from `0` to `n - 1`
- the chunk size is based on approximately `sqrt(n)`
- stack `a` is processed by rank ranges
- values inside the current range are pushed to `b`
- stack `b` is then processed by repeatedly moving the maximum rank back to `a`

This gives an intended operation complexity of `O(n sqrt(n))` because elements are processed through approximately square-root-sized ranges.

### Complex Strategy - O(n log n)

The complex strategy uses binary radix sorting over ranks:

- values are first converted to ranks from `0` to `n - 1`
- the number of bits needed for the largest rank is computed
- bits are processed from least significant to most significant
- values with a `0` bit are pushed to `b`
- values with a `1` bit are rotated inside `a`
- after each pass, all values in `b` are pushed back to `a`

There are `O(log n)` bit passes and `O(n)` operations per pass, giving `O(n log n)` Push_swap operations.

### Adaptive Strategy

The adaptive strategy measures disorder before any sorting move and chooses an internal strategy:

- `disorder < 0.2`: Simple, `O(n^2)`
- `0.2 <= disorder < 0.5`: Medium, `O(n sqrt(n))`
- `disorder >= 0.5`: Complex, `O(n log n)`

In benchmark mode, the reported strategy remains `adaptive` for default/adaptive mode, while the reported complexity corresponds to the internal disorder regime selected by the implementation.

The rationale is:

- low disorder: simple extraction is acceptable
- medium disorder: chunking balances movement and extraction
- high disorder: radix over ranks gives predictable scaling

Auxiliary memory is mainly used for the two array-backed stacks and temporary rank/split arrays, so space usage is linear in the number of input values.

## Benchmark Mode

Benchmark mode is enabled with `--bench`. Operations are printed to stdout, and the benchmark report is printed to stderr. The benchmark appears only when `--bench` is present.

Supported forms include:

```sh
./push_swap --bench 5 4 3 2 1
./push_swap --bench --simple 5 4 3 2 1
./push_swap --bench --medium 5 4 3 2 1
./push_swap --bench --complex 5 4 3 2 1
./push_swap --bench --adaptive 5 4 3 2 1
./push_swap --simple --bench 5 4 3 2 1
```

Example format:

```txt
Disorder :100.00 %
Strategy : adaptive
Complexity : O(n log n)
sa: 1
sb: 0
ss: 0
pa: 0
pb: 0
ra: 1
rb: 0
rr: 0
rra: 0
rrb: 0
rrr: 0
Total operations: 2
```

## Performance Targets

The subject defines these evaluation targets. They are targets, not guaranteed claims for every run.

For 100 random numbers:

- fewer than 2000 operations: minimum/pass
- fewer than 1500 operations: good
- fewer than 700 operations: excellent

For 500 random numbers:

- fewer than 12000 operations: minimum/pass
- fewer than 8000 operations: good
- fewer than 5500 operations: excellent

## Testing

Build first:

```sh
make re
```

Examples:

```sh
./push_swap 5 4 3 2 1
./push_swap "5 4" 3 "2 1"
./push_swap --complex 5 4 3 2 1
./push_swap --bench --adaptive 5 4 3 2 1
```

If `checker_linux` is present in the repository root, operations can be verified with:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Useful manual checks:

```sh
./push_swap 1 2 3
./push_swap 3 2 1
./push_swap 1 1
./push_swap 2147483647 -2147483648 0
./push_swap 2147483648
```

The repository also contains `test.sh`, which can be run after making it executable:

```sh
chmod +x test.sh
./test.sh
```

## Project Structure

```txt
.
|-- Makefile
|-- README.md
|-- libft.h
|-- src/        main program and high-level helpers
|-- operations/ Push_swap operations and chunk helpers
|-- sort/       sorting strategies and movement helpers
|-- parsing/    input validation and cleanup helpers
|-- bench/      disorder, strategy selection, and benchmark output
`-- libft/      small utility functions used by the project
```

## Technical Choices

The stacks are represented as arrays inside `t_stack`. Operation counts are stored in `t_ops` and are incremented when operations are printed. The project uses ranking/coordinate compression before chunk and radix sorting. Benchmark data is sent to stderr so stdout remains a valid Push_swap operation stream.

## Resources

- 42 Push_swap subject, Version 1.1
- Big-O notation: https://en.wikipedia.org/wiki/Big_O_notation
- Stack data structure: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- Radix sort: https://en.wikipedia.org/wiki/Radix_sort
- Inversion counting: https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)

## Use of AI

AI tools were used as a development assistant for explaining concepts, reviewing and refactoring code, identifying pointer/type mistakes, reasoning about parsing, inspecting Norminette issues, suggesting test cases, reviewing subject compliance, and helping prepare documentation.

AI suggestions were not treated as automatically correct. The final code was reviewed and tested by the learners, and both learners are responsible for understanding and defending the complete implementation.
