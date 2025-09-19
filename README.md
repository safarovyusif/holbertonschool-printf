# `_printf`

`_printf` is a custom implementation of the standard C library's `printf` function. This project was developed as part of the Holberton School curriculum to replicate the core functionality of `printf` using a limited set of format specifiers.

---

### Features

This custom `_printf` function handles the following format specifiers:

* **`%c`**: Prints a single character.
* **`%s`**: Prints a string of characters.
* **`%%`**: Prints a literal percent sign.
* **`%d`** and **`%i`**: Prints an integer (decimal).

---

### How to Use

To use `_printf`, you need to include the `main.h` header file in your C program. The function works similarly to the standard `printf` and returns the number of characters printed.

**Prototype:**
`int _printf(const char *format, ...);`

**Example:**
```c
#include "main.h"

int main(void)
{
    int count;

    count = _printf("Hello, Holberton!\n");
    _printf("Characters printed: %d\n", count);

    _printf("My favorite character is %c, and my favorite number is %d.\n", 'H', 98);
    _printf("Testing a percent sign: %%\n");

    return (0);
}
