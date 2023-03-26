#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
* _printf - Function that produces output according to a format
* @format: format specifier
* @...:other variables
* Return: int
*/
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
char c;

while ((c = *format++))
{
if (c == '%')
{
c = *format++;
if (c == 'c')
{
putchar(va_arg(args, int));
count++;
}
else if (c == 's')
{
char *s = va_arg(args, char *);
while (*s)
{
putchar(*s++);
count++;
}
}
else if (c == '%')
{
putchar('%');
count++;
}
}
else
{
putchar(c);
count++;
}
}
va_end(args);
return (count);
}
