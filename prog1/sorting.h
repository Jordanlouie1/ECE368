#include<stdio.h>
#include<stdlib.h>

long *Load_From_File(char *Filename, int *Size);

int Save_From_File(char *Filename, long *Array);

void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move);

void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move);

int Print_Seq(char * Filename, int Size);
