#ifndef _UTIL_H_
#define _UTIL_H_

void generate_sequence(int, int , int , int *);

void check_loop_iterative(void (*f)(int,int,int,int *), int , int , int *,int *);

int has_loop(int *,int,int,int *,int *);

void hist_of_firstdigits(void (*f)(int,int,int,int *), int, int, int *, int);

#endif /* _UTIL_H_ */
