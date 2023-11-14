#include "main.h"

/**
 * is_printable - Determines whether a char is printable
 * @c: Char to be assessed
 *
 * Return: Returns 1 if the char is printable, Else 0.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appends ASCII in hexadecimal code to a char array
 * @buffer: Array of chars.
 * @i: Starting index for appending
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - evaluate if a char is a digit
 * @c: Char to be assessed
 *
 * Return: 1 if c is a digit, Else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Transforms a given num to the specified size.
 * @num: Number to be transformed
* @size: Number indicating the type to be transformed
 *
 * Return: transformed value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - transforms a number to the specified size
 * @num: Number to be transformed
 * @size: Number indicating the type to be transformed
 *
 * Return: transformed value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
