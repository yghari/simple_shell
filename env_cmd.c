#include "shell.h"
/**
 * _fput_helper - function helps to
 * print number
 *
 * @fd: file descriptor of the file that
 * the given number will be printed in
 * @number: number to be printed
 * Return: number of printed digits
 */
int _fput_helper(int fd, int number)
{
	int ret;
	char c;

	if (number == 0)
		return (0);
	ret = _fput_helper(fd, number / 10);
	c = number % 10 + 48;
	write(fd, &c, 1);
	return (1 + ret);
}

/**
 * _fputnumber - function that print
 * given number into given file
 *
 * @fd: file descriptor
 * @number: to be printed
 * Return: the length of the printed
 * characters
 */
int _fputnumber(int fd, int number)
{
	int printed;

	printed = 0;
	if (!number)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (number < 0)
	{
		write(fd, "-", 1);
		printed = 1;
		number *= -1;
	}
	return (printed + _fput_helper(fd, number));
}

/**
 * _fputs - function that prints string
 * into given file descriptor
 *
 * @fd: file descriptor
 * @s: string to be printed
 * Return: number of character printed
 */
int _fputs(int fd, const char *s)
{
	return (write(fd, s, strlen(s)));
}

/**
 * _fprint - function that allows to
 * to print number and string using
 * format specifiers
 *
 *
 * @fd: file descriptor
 * @format: format to be printed to given fd
 * and change place holder to specific values
 * Return: number of printed characters
 */
int _fprint(int fd, const char *format, ...)
{
	va_list ap;
	int i, printed;
	int is_percent;

	va_start(ap, format);
	is_percent = 0;
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
			is_percent = 1;
		else
		{
			if (is_percent)
			{
				if (format[i] == 'd')
					printed += _fputnumber(fd, va_arg(ap, int));
				else if (format[i] == 's')
					printed += _fputs(fd, va_arg(ap, char *));
				else
					printed += write(fd, &format[i - 1], 2);
			}
			else
				printed += write(fd, format + i, 1);
			is_percent = 0;
		}
		i++;
	}
	va_end(ap);
	return (printed);
}
/**
 * env_cmd - Prints the environment variables
 *
 * Description: This function prints the environment variables. It uses
 * the 'environ' variable, which is a global variable containing the
 * environment variables passed to the program. It iterates through the
 * environment variables using a while loop and prints each variable
 * using the fprintf() function. The loop terminates when it reaches the
 * end of the environment variables, which is indicated by a NULL pointer.
 * Return: chi l3ba of printed characters
 */
int env_cmd(void)
{
	char **env;

	env = environ;
	if (!env)
		return (1);
	while (*env)
	{
		_fprint(1, "%s\n", *env++);
	}
	return (0);
}
