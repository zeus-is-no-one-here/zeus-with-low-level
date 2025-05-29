#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
  int *mmb;
  int len;
}set;
set* init();
bool is_emp(set *SET);
void inser(set *SET , int member);
void print_set(set *Set);
set *union_set(set *setA , set *setB);
set *intr_set(set *setA , set *setB);
set *diff_set(set *setA , set *setB);
bool is_sub(set *setA , set *setB);
bool is_eque(set *setA , set *setB);
bool is_mmb(set *SET , int val);
///



int main(){
    set *setA = init();
    set *setB = init();
    inser(setA , 5);
    inser(setA , 6);
    inser(setB , 7);
    inser(setB , 5);
    inser(setB , 6);
    inser(setB , 10);
    bool find = is_mmb(setB,2)?printf("find"):printf("not find");
   
}
set* init(){
    set *new_set = malloc(sizeof(set));
    new_set->len = 0;
    new_set->mmb = malloc(sizeof(int));
    return new_set;
}
bool is_emp(set *SET){
    return (SET->len == 0);
}

void inser(set *SET , int member){

    bool check = false;

    for (int i = 0; i < SET->len; i++)
    {
         if(SET->mmb[i] == member){
            check = true;
         }
      }
    if(!check){
        SET->mmb = realloc(SET->mmb , sizeof(int)*(SET->len+1));
        SET->mmb[SET->len] = member;
        SET->len = SET->len+1;
    }
}

void print_set(set *Set){
    for (int i = 0; i < Set->len; i++)
    {
        if(i==Set->len-1) printf("%d",Set->mmb[i]);
        else printf("%d,",Set->mmb[i]);
     }
    
}
set *union_set(set *setA , set *setB)
{

    set *new = init();
    for (int i = 0; i < setA->len; i++)
    {
        inser(new,setA->mmb[i]);
    }
    for (int i = 0; i < setB->len; i++)
    {
        inser(new,setB->mmb[i]);
    }
   return new;
}

set *intr_set(set *setA , set *setB){


    set *new = init();

    for (int i = 0; i < setA->len; i++)
    {
        for (int s = 0; s < setB->len; s++)
        {
            if(setA->mmb[i] == setB->mmb[s]) inser(new,setA->mmb[i]);

        }
        
                      }
                      return new;
    
}
set *diff_set(set *setA , set *setB){
    set *new = init();

    for (int i = 0; i < setA->len; i++)
    {
        bool find = false;

        for (int s = 0; s < setB->len; s++)
        {
           if(setA->mmb[i] == setB->mmb[s]) find = true;
        }
        if(!find){
             inser(new,setA->mmb[i]);
        }
        
    }
    return new;
}


bool is_sub(set *setA , set *setB){

    for (int i = 0; i < setA->len; i++)
    {
        bool find = false;

        for (int s = 0; s < setB->len; s++)
        {
           if(setA->mmb[i] == setB->mmb[s]) find = true;
        }
        if(!find){
             return false;
        }
        
    }
    return true;
}

bool is_eque(set *setA , set *setB){
    if(setA->len != setB->len) return false;
    for (int i = 0; i < setA->len; i++)
    {
        bool find = false;

        for (int s = 0; s < setB->len; s++)
        {
           if(setA->mmb[i] == setB->mmb[s]) find = true;
        }
        if(!find){
             return false;
        }
        
    }
    return true;
}


bool is_mmb(set *SET , int val){
    for (int i = 0; i < SET->len; i++)
    {
       if(SET->mmb[i] == val) return true;
    }
    return false;
}
