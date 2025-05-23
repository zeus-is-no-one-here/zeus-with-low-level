#include "my_ctype.h"

int my_ispunct(int c)
{

  return ((c >= 33 && c <= 47) ||
          (c >= 58 && c <= 64) ||
          (c >= 91 && c <= 96) ||
          (c >= 123 && c <= 126));
}
int my_isdigit(int c)
{
  return (c >= '0' && c <= '9');
}
int my_isspace(int c)
{
  return (c == ' ' || c == '\t' || c == '\n' ||
          c == '\v' || c == '\f' || c == '\r');
}
int my_islower(int c)
{
  return (c >= 97 && c <= 122);
}
int my_isupper(int c)
{
  return (c >= 65 && c <= 90);
}
int my_isalpha(int c)
{
  return (my_islower(c) || my_isupper(c));
}
int my_isalnum(int c)
{
  return (my_isalpha(c) || my_isdigit(c));
}
int my_isxdigit(int c)
{
  return (my_isdigit(c) ||

          (c >= 'A' && c <= 'F') ||
          (c >= 'a' && c <= 'f'));
}
int my_isprint(int c)
{
  return (c >= 32 && c <= 126);
}
int my_isgraph(int c)
{
  return (my_isprint(c) && c != ' ');
}
int my_iscntrl(int c)
{
  return (c >= 0 && c <= 31 || c == 127);
}
//
int my_tolower(int c)
{
  if (my_isupper(c))
    return c + 32;

  return c;
}
int my_toupper(int c)
{
  if (my_islower(c))
    return c - 32;

  return c;
}
