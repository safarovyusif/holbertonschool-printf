#include "main.h"

/**
 * handle_specifier - Handles the format specifiers and returns the count.
 * @format: The format string.
 * @i: A pointer to the current index in the format string.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed, or -1 on error.
 */
int handle_specifier(const char *format, int *i, va_list args)
{
	int count = 0;

	if (!format[*i])
	{
		return (-1);
	}

	if (format[*i] == 'c')
	{
		count += char_print(va_arg(args, int));
	}
	else if (format[*i] == 's')
	{
		count += string_print(va_arg(args, char *));
	}
	else if (format[*i] == '%')
	{
		count += percent_print();
	}
	else if (format[*i] == 'd' || format[*i] == 'i')
	{
		count += int_print(va_arg(args, int));
	}
	else
	{
		_putchar('%');
		_putchar(format[*i]);
		count += 2;
	}

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: a character string with format specifiers
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list zg;
	int i = 0;
	int count = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(zg, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_specifier(format, &i, zg);
			if (count == -1)
				return (-1);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(zg);
	return (count);
}
