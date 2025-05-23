#ifndef MY_CTYPE_H
#define MY_CTYPE_H

/* Character classification functions */
int my_isalnum(int c);
int my_isalpha(int c);
int my_iscntrl(int c);
int my_isdigit(int c);
int my_isgraph(int c);
int my_islower(int c);
int my_isprint(int c);
int my_ispunct(int c);
int my_isspace(int c);
int my_isupper(int c);
int my_isxdigit(int c);

/* Character conversion functions */
int my_tolower(int c);
int my_toupper(int c);

#endif /* MY_CTYPE_H */