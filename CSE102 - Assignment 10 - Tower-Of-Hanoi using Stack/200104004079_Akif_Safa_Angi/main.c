#include <stdio.h>
#include <stdlib.h>

#define STACK_BLOCK_SIZE 10
typedef struct {
    int *array; 
    int currentsize;
    int maxsize;
} stack;

stack * init_return(); /* initializes an empty stack */
int init(stack * s); /* returns 1 if initialization is successful */
int push(stack * s, int d); /* the stack array will grow STACK_BLOCK_SIZE entries at
a time */
int pop(stack * s); /* the stack array will shrink STACK_BLOCK_SIZE entries at a
time */

int main(){
    int size,check = 1,i = 0;
	int checkInit = 1,a;
    printf("Enter tower size:");
    scanf("%d",&size);
	while(size <= 0){
		printf("Enter positive number:");
    	scanf("%d",&size);
	}
	stack *f,*m,*l;
	f = init_return();
	do{
		checkInit = init(f);
	}while(checkInit == 0);
	if(size > 10){
	a = size;
	while(a > 0){
		a = a-10;
		i++;
	}
	f->array = (int*)realloc(f->array,i * STACK_BLOCK_SIZE * sizeof(int));
	}
	m = init_return();
	do{
		checkInit = init(m);
	}while(checkInit == 0);
	if(size > 10){
	m->array = (int*)realloc(m->array,i * STACK_BLOCK_SIZE * sizeof(int));
	}
	l = init_return();
	do{
		checkInit = init(l);
	}while(checkInit == 0);
	if(size > 10){
	l->array = (int*)realloc(l->array,i * STACK_BLOCK_SIZE * sizeof(int));
	}
	f->maxsize = size;
	m->maxsize = size;
	l->maxsize = size;
	if(checkInit == 1){
		printf("Initilization is successful\n");
		for(i = size;i > 0;i--) push(f,i);//Push the disks to first pole
		int a = 0, operation = 0, topDisk,repeat = 0;
		while(f->currentsize != -1 || m->currentsize != -1){//Loop until first and middle poles have no disks
			/*check two poles every time differently in each step
			Set operation number to pole which we put disk. So if the next turn is this disk,then don't change it's disks
			Increase repeat++ each turn. If repeat = 4,then other poles are empty therefore the disk of the last remaining pole has to change
			If it goes inside the if block, it resets the repeat
			*/
			if(a%3 == 0){
				if(l->currentsize != -1 && (operation != 3 || repeat == 4)){//if l is not empty and some disk didn't put to this pole recently
					if(l->array[l->currentsize] < m->array[m->currentsize] || m->currentsize == -1){//if l's top disk smaller than m or m is empty
						topDisk = pop(l);
						push(m,topDisk);
						printf("Move the disk %d from '3' to '2'\n",topDisk);
						operation = 2;
						repeat = 0;
					}else if(l->array[l->currentsize] < f->array[f->currentsize] || f->currentsize == -1){//if l's top disk smaller than f or f is empty
						topDisk = pop(l);
						push(f,topDisk);
						printf("Move the disk %d from '3' to '1'\n",topDisk);
						operation = 1;
						repeat = 0;
					}
				}
			}else if(a%3 == 1){
				if(m->currentsize != -1 && (operation != 2 || repeat == 4)){//if m is not empty and some disk didn't put to this pole recently
					if(m->array[m->currentsize] < f->array[f->currentsize] || f->currentsize == -1){//if m's top disk smaller than f or f is empty
						topDisk = pop(m);
						push(f,topDisk);
						printf("Move the disk %d from '2' to '1'\n",topDisk);
						operation = 1;
						repeat = 0;
					}else if(m->array[m->currentsize] < l->array[l->currentsize] || l->currentsize == -1){//if m's top disk smaller than l or l is empty
						topDisk = pop(m);
						push(l,topDisk);
						printf("Move the disk %d from '2' to '3'\n",topDisk);
						operation = 3;
						repeat = 0;
					}
				}
			}else if(a%3 == 2){
				if(f->currentsize != -1 && (operation != 1 || repeat == 4)){//if f is not empty and some disk didn't put to this pole recently
					if(f->array[f->currentsize] < l->array[l->currentsize] || l->currentsize == -1){//if f's top disk smaller than l or l is empty
						topDisk = pop(f);
						push(l,topDisk);
						printf("Move the disk %d from '1' to '3'\n",topDisk);
						operation = 3;
						repeat = 0;
					}else if(f->array[f->currentsize] < m->array[m->currentsize] || m->currentsize == -1){//if f's top disk smaller than m or m is empty
						topDisk = pop(f);
						push(m,topDisk);
						printf("Move the disk %d from '1' to '2'\n",topDisk);
						operation = 2;
						repeat = 0;
					}
				}
			}
			a++;
			repeat++;
		}
	}
	//free stacks
	free(f);
	free(m);
	free(l);
    return 0;
}


stack * init_return(){//initializes stack and return
	stack *st = (stack*)malloc(sizeof(stack));
	st->array = NULL;
	return st;
}

int init(stack * s){
	s->array = (int*)malloc(STACK_BLOCK_SIZE * sizeof(int));
	s->maxsize = 0;
	s->currentsize = -1;//set currentsize
	if(s->array != NULL) return 1;//if init successfull return 1
	else return 0;
}

int push(stack * s, int d){//increases currentsize and add disk number to pole's array
	if (s->currentsize == s->maxsize - 1)
	return 0;	
	s->array[++s->currentsize] = d;//disk's number to array
	return 1;
}

int pop(stack * s){//returns pole's top disk
	if (s->currentsize == -1)
	return 0;
	return s->array[s->currentsize--];
}