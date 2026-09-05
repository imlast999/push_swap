*This project has been created as part of the 42 curriculum by abenich, efresnil.*

# Push_swap

## Description

Push_swap is a 42 algorithm project written in C. The goal is to sort a list of signed integers in ascending order by generating a valid sequence of Push_swap operations while keeping the number of generated operations as low as possible.

The program works with two stacks:

- `a` initially contains all input values, with the first input value at the top.
- `b` starts empty and is used as temporary storage while sorting.

The allowed operations are:

`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

This implementation contains the four strategies required by the subject:

- **Simple** - `O(n^2)`
- **Medium** - `O(n sqrt(n))`
- **Complex** - `O(n log n)`
- **Adaptive** - selects an internal method from the measured disorder of the initial stack

All complexity classes in this README refer to the number of Push_swap operations generated, not only to the number of internal C comparisons.

## Contributors

This project was completed by exactly two learners:

- **abenich**
- **efresnil**

Git history shows contributions from both learners. The main areas of work were:

### abenich

- Initial Push_swap implementation and core stack operations.
- Parsing, integer-range validation, duplicate handling, and error management.
- Simple, chunk-based, and radix sorting integration.
- Disorder calculation and benchmark reporting.
- Refactoring the project into the current modular structure and integrating the final parsing/benchmark flow.

### efresnil

- Norminette cleanup and project tree organization during development.
- `ft_split`-based argument splitting and quoted-input support work.
- Design and implementation of `linear_sort()` for nearly sorted inputs.
- Integration of `linear_sort()` into the low-disorder branch of the Adaptive strategy.
- Code review, cleanup, and integration work across shared project files.

Both learners are responsible for understanding and defending the complete implementation.

## Instructions

Compile the project with:

```sh
make
```

This creates the executable:

```txt
push_swap
```

Available Makefile rules:

```sh
make
make all
make clean
make fclean
make re
```

The project is compiled with:

```txt
-Wall -Wextra -Werror
```

## Usage

### Default behavior

When no strategy selector is given, Adaptive mode is used:

```sh
./push_swap 5 4 3 2 1
```

### Force a strategy

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

### Quoted and mixed arguments

Arguments are split with `ft_split`, so quoted and mixed forms are accepted:

```sh
./push_swap "5 4" 3 "2 1"
```

This is interpreted as:

```txt
5 4 3 2 1
```

An optional leading `+` or `-` sign is also accepted for numeric tokens:

```sh
./push_swap +2 1
./push_swap --bench -2 1
```

## Error Handling

Invalid input prints:

```txt
Error
```

to standard error, followed by a newline.

Handled cases include:

- non-integer tokens
- signed integers outside the `int` range
- duplicate values
- invalid or incomplete strategy/benchmark arguments
- empty numeric arguments
- malformed signs such as `+`, `-`, `++1`, or `+-1`

If no arguments are supplied, the program prints nothing.

If the input is already sorted, no sorting operation is printed.

## Push_swap Operations

- `sa`: swap the first two elements of `a`
- `sb`: swap the first two elements of `b`
- `ss`: perform `sa` and `sb`
- `pa`: move the top element of `b` to the top of `a`
- `pb`: move the top element of `a` to the top of `b`
- `ra`: rotate `a` upward
- `rb`: rotate `b` upward
- `rr`: perform `ra` and `rb`
- `rra`: reverse-rotate `a`
- `rrb`: reverse-rotate `b`
- `rrr`: perform `rra` and `rrb`

## Disorder Metric

Disorder is measured before any sorting move. It is based on inversion counting:

```txt
disorder = inversions / maximum_possible_inversions
maximum_possible_inversions = n * (n - 1) / 2
```

An inversion is a pair of positions `i < j` where `a[i] > a[j]`.

Therefore:

- sorted input -> disorder `0`
- reverse-sorted input -> disorder `1`

Internally the value remains in the range `[0, 1]`. Benchmark mode converts it to a percentage with two decimal places.

## Sorting Algorithms

### Simple Strategy - O(n^2)

The explicit `--simple` strategy uses minimum extraction.

General flow:

1. Find the minimum element in stack `a`.
2. Move it to the top with `ra` or `rra`, choosing the shorter direction.
3. Push it to `b` with `pb`.
4. Repeat until only a small stack remains in `a`.
5. Sort the remaining three or four elements with dedicated small-stack routines.
6. Push the saved minimum values back to `a` with `pa`.

In the worst case, locating/moving each extracted minimum can require a number of stack operations proportional to the remaining stack size. Repeating this over the input gives an `O(n^2)` Push_swap-operation upper bound.

The algorithm uses constant additional sorting state beyond the already allocated stacks.

### Medium Strategy - O(n sqrt(n))

The Medium strategy uses ranking and chunk-based sorting.

First, every input value is replaced by its rank in sorted order. For example:

```txt
40 10 30 20 -> 3 0 2 1
```

Then:

1. A chunk size close to `sqrt(n)` is computed.
2. Ranked values are processed by consecutive ranges.
3. Values in the current range are pushed from `a` to `b`.
4. Values below the middle of a chunk are rotated in `b`, helping keep each chunk arranged for extraction.
5. Once `a` is empty, the largest remaining rank is repeatedly moved to the top of `b` and pushed back to `a`.

There are approximately `sqrt(n)` chunks. The scan/movement work per regime is bounded by the number of elements times a square-root-sized chunk/range cost, giving an `O(n sqrt(n))` Push_swap-operation upper bound for this strategy.

Ranking temporarily allocates an array of `n` integers, so its additional memory usage is `O(n)`.

### Complex Strategy - O(n log n)

The Complex strategy is an LSD binary radix-sort adaptation over ranks.

Flow:

1. Convert the values in `a` to ranks from `0` to `n - 1`.
2. Compute how many bits are required for the largest rank.
3. Process one bit position at a time, from least significant to most significant.
4. For the current bit:
   - bit `0` -> `pb`
   - bit `1` -> `ra`
5. Push every value in `b` back to `a` with `pa`.
6. Repeat for every required bit.

Each bit pass processes all `n` values, and the number of bit positions is `O(log n)`. The resulting Push_swap-operation complexity is therefore `O(n log n)`.

Ranking uses `O(n)` temporary memory.

### Adaptive Strategy

Adaptive mode is the default strategy. It measures disorder first and then selects an internal sorting technique.

The subject-defined regimes are:

| Disorder | Internal technique used here | Push_swap upper bound |
| --- | --- | --- |
| `< 0.2` | `linear_sort()` | `O(n^2)` |
| `0.2 <= d < 0.5` | Medium chunk strategy | `O(n sqrt(n))` |
| `>= 0.5` | Complex binary radix strategy | `O(n log n)` |

#### Low disorder: `linear_sort()`

For nearly sorted inputs, the Adaptive strategy does not call the explicit `simple_sort()` baseline. Instead it uses `linear_sort()`, which is specialized for inputs that already contain a large increasing subsequence.

Its main steps are:

1. Return immediately if the stack is already sorted.
2. Detect whether the stack is circularly sorted; if so, only rotate the minimum to the top.
3. Move the minimum to the top and keep an increasing sequence in `a`.
4. Push values that break that increasing sequence to `b`.
5. Reinsert each value from `b` into its target position in `a`, using the shorter rotation direction.
6. Move the minimum back to the top.

This often reduces the number of operations on nearly sorted inputs. Its worst-case Push_swap-operation upper bound is still documented as `O(n^2)`: up to `O(n)` values may need reinsertion, and a reinsertion can require up to `O(n)` rotations plus a push.

`linear_sort()` itself performs no additional heap allocation beyond the two existing stacks.

#### Why keep `simple_sort()` separate?

`simple_sort()` remains the explicit baseline selected by `--simple`. Its min-extraction behavior is straightforward and predictable for arbitrary inputs. `linear_sort()` is a specialized internal optimization used only by Adaptive mode when the measured disorder is low.

This keeps `--simple` as a clear `O(n^2)` reference strategy while allowing Adaptive mode to exploit nearly sorted structure.

#### Threshold rationale

The numeric thresholds are defined by the project subject. The implementation maps each regime to a method that respects the required upper bound:

- low disorder: a nearly-sorted-aware insertion/reinsertion approach
- medium disorder: square-root chunking
- high disorder: binary radix sorting

Overall heap usage remains `O(n)`, mainly because the program allocates two array-backed stacks and ranking/parsing may allocate temporary linear-size buffers.

## Small Input Handling

Inputs of size two, three, and four use dedicated small-stack routines to avoid unnecessary operations. These routines are shared by the strategy dispatch and directly generate valid Push_swap operations for those small cases.

## Benchmark Mode

Benchmark mode is enabled with `--bench`.

Examples:

```sh
./push_swap --bench 5 4 3 2 1
./push_swap --bench --simple 5 4 3 2 1
./push_swap --bench --medium 5 4 3 2 1
./push_swap --bench --complex 5 4 3 2 1
./push_swap --bench --adaptive 5 4 3 2 1
./push_swap --simple --bench 5 4 3 2 1
```

Sorting operations remain on **stdout**. Benchmark information is printed only to **stderr**.

The report contains:

- disorder as a percentage with two decimal places
- selected strategy name
- theoretical complexity class
- count of every operation type
- total operation count

For example, with:

```sh
./push_swap --bench +2 1
```

stdout contains:

```txt
sa
```

and stderr contains:

```txt
Disorder :100.00 %
Strategy : adaptive
Complexity : O(n log n)
sa: 1
sb: 0
ss: 0
pa: 0
pb: 0
ra: 0
rb: 0
rr: 0
rra: 0
rrb: 0
rrr: 0
Total operations: 1
```

When default/Adaptive mode is used, the benchmark reports `Strategy : adaptive`; the complexity field reflects the disorder regime selected internally.

## Performance Targets

The subject defines the following evaluation targets.

For **100 random numbers**:

- fewer than 2000 operations: minimum requirement
- fewer than 1500 operations: good performance
- fewer than 700 operations: excellent performance

For **500 random numbers**:

- fewer than 12000 operations: minimum requirement
- fewer than 8000 operations: good performance
- fewer than 5500 operations: excellent performance

These are evaluation targets, not guarantees for every possible input.

## Testing

Rebuild from scratch:

```sh
make re
```

Useful parsing and edge-case checks:

```sh
./push_swap 1 2 3
./push_swap -2 -1 1 2 3
./push_swap +2 1
./push_swap "5 4" 3 "2 1"
./push_swap 1 1
./push_swap 2147483647 -2147483648 0
./push_swap 2147483648
./push_swap +2147483648
```

Count generated operations on a random set:

```sh
ARG="$(shuf -i 0-9999 -n 100 | tr '\n' ' ')"
./push_swap $ARG | wc -l
```

If the 42-provided checker is available, the generated stream can also be verified with it:

```sh
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

## Project Structure

```txt
.
|-- Makefile
|-- README.md
|-- push_swap.h
|-- bench/
|   |-- bench_display.c
|   |-- get_strat_output.c
|   `-- strategy_parser.c
|-- libft/
|   |-- ft_putchar_fd.c
|   |-- ft_putnbr_fd.c
|   |-- ft_putstr_fd.c
|   |-- ft_split.c
|   `-- ft_strcmp.c
|-- operations/
|   `-- Push_swap operation implementations
|-- parsing/
|   |-- check.c
|   |-- parse_numbers.c
|   `-- parse_utils.c
|-- sort/
|   |-- chunk_sort.c
|   |-- linear_sort.c
|   |-- small_sort.c
|   |-- sort_moves.c
|   `-- sort_strategies.c
`-- src/
    |-- main.c
    |-- sort_dispatch.c
    `-- sort_runner.c
```

## Technical Choices

- Stacks are represented by dynamic integer arrays inside `t_stack`.
- Stack sizes are tracked explicitly with `size_a` and `size_b`.
- `t_ops` stores per-operation and total benchmark counters.
- Ranking/coordinate compression converts arbitrary signed integers into compact ranks for chunk and radix strategies.
- Benchmark data is written to stderr so stdout remains a valid Push_swap instruction stream.
- No global variables are used.

## Resources

- 42 Push_swap subject, Version 1.1
- Big-O notation: https://en.wikipedia.org/wiki/Big_O_notation
- Stack data structure: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- Radix sort: https://en.wikipedia.org/wiki/Radix_sort
- Inversion counting: https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)

## Use of AI

AI tools were used as a development assistant for:

- explaining algorithmic and pointer-related concepts
- reviewing/refactoring code structure
- checking parsing and integer-boundary logic
- identifying possible regressions after merges
- suggesting edge cases and stress tests
- reviewing benchmark and subject compliance
- helping prepare and update project documentation

AI-generated suggestions were reviewed and tested rather than accepted automatically. The final implementation remains the responsibility of both learners, and both learners are expected to understand and explain every submitted part of the project.