#include <unistd.h>
#include <stdarg.h> // For variadic arguments
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define my_putchar(x) write(1, my_chardup(x), 1)
#define whait4char 1
#define whait4fmt 2
char *my_chardup(const char c) ;
int my_puts(const char *str);
int my_printf(const char  *fmt,...);

char *my_chardup(const char c) {
    static char buff[2];
    buff[0] = c;
    buff[1] = '\0';
    return buff;
}

int my_puts(const char *str) {
  unsigned int size = strlen(str);
  if(size==0) return -1;
    return write(1, str, size );
}




int my_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int printed_chars = 0;
    unsigned char z = whait4char;
    const char *f = fmt;
    char buff[256];

    while (*f) {
        if(z&whait4char){
            if (*f == '%') {
                z = whait4fmt;
            } else {
                my_putchar(*f);
                printed_chars++;
            }
        }
        else if(z & whait4fmt){
        int width  = 0 , pr = -1 , zero = 0;
        if(*f == '0'){
            zero = 1;
            f++;
        }
        while(*f >='0' && *f <= '9'){
            width = (width *10)+(*f - '0');
            f++;
        }
        if(*f == '.'){
            f++;
            pr = 0;
            while(*f>= '0' && *f <= '9'){
                pr = (pr*10)+(*f -'0');
                f++;
            }
        }
        
        
         
            switch (*f) {
                case '%':
                    my_putchar('%');
                    printed_chars++;
                    break;
                case 'd': {
                    int val = va_arg(args, int);
                     sprintf(buff,"%d",val);
                     printed_chars+=my_puts(buff);
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    printed_chars += my_puts(str);
                    break;
                }
                case 'f' :{
                    double val = va_arg(args,double);
                    if(pr == -1){
                        width = 6;
                    }
                    snprintf(buff,sizeof(buff),"%*.*f",width,pr,val);
                    printed_chars+=my_puts(buff);
                    break;
                }
                case 'c' : {
                    char val =  va_arg(args,int);
                    my_putchar(val);
                    printed_chars++;
                    break;
                }
                case 'x' : {
                    int val = va_arg(args,int);
                    sprintf(buff,"%x",val);
                    printed_chars+=my_puts(buff);
                    break;
                }
                
                default:
                    // Unknown format — just print literally
                    my_putchar('%');
                    my_putchar(*f);
                    printed_chars += 2;
                    break;
            }
            z = whait4char;
        }
        f++;
    }
        
        

    va_end(args);
    return printed_chars;
}

int main() {
    my_printf("hello %s\n", "world");
    my_printf("Number: %.2f\n", 42.0);
    return 0;
}