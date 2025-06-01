#include <stdio.h>
double my_atof(const char *str);
int my_atoi(const char *str);
char* my_itoi(int n , char *str);
char* my_ftoa(float n , char *str );







double my_atof(const char *str){

    int sign = 1;
    double res = 0.0;
    int z = 0;

    if(str[z] == '-'){ sign = -1; z++; }
    else if(str[z] == '+') { z++;}

    while(str[z] >= '0' && str[z] <= '9'){
        res = res *10 + (str[z]-'0');
        z++;

    }

    if(str[z] == '.'){
        z++;
        double d_p = 1.0;

        while(str[z] >= '0' && str[z] <= '9'){
            d_p /= 10.0;
            res+=(str[z] -'0')*d_p;
            z++;
        }

    }
    return sign *res;


}

int my_atoi(const char *str){
    int sign = 1;
    int res = 0;
    int z =0;


    if(str[z]== '-') {
    sign = -1;
     z++;
    }
    else if(str[z] == '+') {z++;
    }
    while(str[z] >= '0' && str[z]<= '9'){
        res = res *10 +(str[z] - '0');
        z++;
    }
    return sign * res;
}

char* my_itoi(int n , char *str){
    int z =0;
    int sign = 1;

    while(n < 0){
        sign = -1;
        n = -n;
    }
    if(n==0){
        str[z++] = '0';
    }
    else{
        while(n> 0){
            str[z++] = n %10+'0';
            n /=10;
        }

    }
    if(sign == -1){
        str[z++] = '-';
    }
    str[z] = '\0';
 int start = 0;
  int end = z -1;
 while(start < end){
    char tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
    start++;
    end--;
 }
     str[z] = '\0';

    return str;
}
char* my_ftoa(float n , char *str ){
    int z = 0;
    int sign = 1;
    if(n<0){
        sign = -1;
        n = -n;
    }
    
    int int_part = (int)n;
    float d_p = n-int_part;
    char tmp[777];
    my_itoi(int_part , tmp);
      int b = 0;
    while (tmp[b] != '\0') {
        str[b] = tmp[b];
        b++;
    }
    z = b;


    for (int i = 0; i < 6; i++)
    {
        d_p *=10;
        int digit = (int)d_p;
        str[z++] = digit +'0';
        d_p -=digit;

    }
    str[z] = '\0';
    if (sign == -1) {
        for (int s = z; s >= 0; s--) {
            str[s+1] = str[s];
        }
        str[0] = '-';
    }

    return str;
    


}

