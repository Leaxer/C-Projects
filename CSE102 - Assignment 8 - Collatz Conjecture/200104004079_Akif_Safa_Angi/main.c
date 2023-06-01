#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){
    int xs,seqlen;
    int *loop;
    int looplen;
    int *h;

    printf("Please enter the sequence length: ");
    scanf("%d",&seqlen);
    printf("Please enter the first element: ");
    scanf("%d",&xs);
    printf("\n");

    looplen = seqlen/2;

    loop = (int*)malloc(sizeof(int) * looplen);// allocate memory
    check_loop_iterative(generate_sequence, xs, seqlen, loop,&looplen);//call function
    //If there is a loop,equalize the loop to the loopNums array and free the loop array  
    if(looplen != -1){
    printf("Loop: {");
    for(int i = 0;i < looplen;i++){
        if(i != looplen - 1) printf("%d,",*(loop + i));
        else printf("%d",*(loop + i));
    }
    printf("}\n");
    }else{
        printf("No loop found.\n");
        printf("\n");
    }
    free(loop);

    //Allocate memory for *h array
    h = (int*)malloc(sizeof(int) * 9);
    hist_of_firstdigits(generate_sequence, xs, seqlen, h, 1);
    //Print the histogram of the sequence
    printf("Histogram of the sequence: {");
    for(int i = 0;i < 9;i++){
        if(i != 8) printf("%d,",*(h + i));
        else printf("%d",*(h + i));
    }
    printf("}");
    free(h);
return 0;
}