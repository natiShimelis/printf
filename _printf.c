#include "main.h"

void printBuffer(char buffer[], int *buffInd);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printedChars = 0;
	int flags, width, precision, size, buffInd = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffInd++] = format[i];
			if (buffInd == BUFF_SIZE)
				printBuffer(buffer, &buffInd);
			printedChars++;
		}
		else
		{
			printBuffer(buffer, &buffInd);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printedChars += printed;
		}
	}

	printBuffer(buffer, &buffInd);

	va_end(list);

	return (printedChars);
}

/**
 * printBuffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buffInd: Index at which to add the next char, represents the length.
 */
void printBuffer(char buffer[], int *buffInd)
{
	if (*buffInd > 0)
		write(1, &buffer[0], *buffInd);

	*buffInd = 0;
}
