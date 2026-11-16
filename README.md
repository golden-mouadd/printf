*This project has been created as part of the 42 curriculum by mouabous.*

# ft_printf

## Description

**ft_printf** is a simplified re-implementation of the C standard library function `printf`. The output is a static library, `libftprintf.a`, containing the following function:

```c
int ft_printf(const char *format, ...);
```

This project introduces **variadic functions** (`<stdarg.h>`), allowing the function to accept a variable number of arguments.

### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if `NULL`) |
| `%p` | a pointer in hexadecimal, prefixed by `0x` (`(nil)` if `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned integer in lower/uppercase hexadecimal |
| `%%` | a literal percent sign |


### Project structure

```
.
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c      # Main parsing and dispatch logic
└── ft_put*.c        # Helper functions for each conversion type
```

## Instructions

### Requirements

- C compiler (`cc`), `make`, and `ar`.
- Compiled with `-Wall -Wextra -Werror`.

### Compilation

```bash
make        # Builds libftprintf.a
make clean  # Removes .o files
make fclean # Removes .o files and the library
make re     # fclean + all
```

### Usage

Include the header and link the library:

```c

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old (0x%x)\n", "42", 42, 42);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c ./libftprintf.a -o test
./test
```

### Examples

| Call | Output |
|------|--------|
| `ft_printf("%c", 'A')` | `A` |
| `ft_printf("%s", "abc")` | `abc` |
| `ft_printf("%d", -2147483648)` | `-2147483648` |
| `ft_printf("%x", 255)` | `ff` |
| `ft_printf("%p", ptr)` | `0x7ffd5c3a1b2c` |

## Algorithm and data structures

### Algorithm

The string is parsed **once** from left to right:
1. Initialize `va_start`.
2. If the character is not `%`, write it.
3. If it is `%`, read the next character and call the matching helper function using `va_arg`.
4. Accumulate the return values of all `write` calls.
5. Call `va_end` and return the total count.

#### Printing numbers

Numbers are printed using **recursion** for both base 10 and base 16:
- It prints the most significant digits first by dividing by the base.
- Recursion prevents the need for buffers or `malloc`, keeping the code simple and leak-free.

#### Edge cases

- **`INT_MIN`**: Handled safely by casting to a `long` before converting to positive.
- **Unsigned `%u`, `%x`, `%X`**: Handled via `unsigned int`.
- **Pointers (`%p`)**: Converts `void *` to `uintptr_t` (base 16). Prints `(nil)` if `NULL`.
- **Strings (`%s`)**: Prints `(null)` if the pointer is `NULL`.
- **Write errors**: If `write` fails (returns `-1`), the error propagates, memory is cleaned with `va_end`, and `ft_printf` returns `-1`.

### Data structures

No custom structs are used:
- **`va_list`**: Used to retrieve arguments sequentially.
- **Lookup strings**: `"0123456789abcdef"` for quick O(1) base conversions.
- Writing is done directly to standard output character by character, trading slight performance for zero dynamic allocations.

## Resources

### References

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [cppreference: `printf`](https://en.cppreference.com/w/c/io/fprintf)

### Use of AI

AI (Claude) was originally used for:
- Explaining the concept of variadic functions and undefined behaviors.
- Helping structure this README.
All code implementation, logic, and tests were written and validated manually.