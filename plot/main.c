#include <stdio.h>
#include <stdlib.h>
#include "plot_structs.h"

int comp;
int main() {
    ABB * binary_tree = NULL;
    AVL * balanced_tree = NULL;
    FILE *comparision;
    comparision = fopen("C:\\Users\\jpham\\CLionProjects\\plot\\Plot.txt","w+");
    int number;
    for (long int i = 0; i < 10000; ++i) {
        number = rand();
        binary_tree = add(binary_tree,number);
        balanced_tree = add_balanced(balanced_tree,number);
    }
    fprintf(comparision,"VALUE\tABB\tAVL\n");
    for (long int j = 0; j < 10000; ++j) {
        number = rand();
        search(binary_tree,number);
        fprintf(comparision,"%d\t%d\t",number,comp);
        comp = 0;
        search_balanced(balanced_tree,number);
        fprintf(comparision,"%d\n",comp);
    }
    fclose(comparision);
    printf("Data wrote succesfully!");
    return 0;
}