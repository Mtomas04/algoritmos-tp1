#include "tp1.h"
#include <stdio.h>
#include <stdlib.h>

bool are_friends_numbers(int x, int y){
    int sumax = 0 ;
    int sumay = 0 ;
    int i;
    if (x == y) return false;
    for (i = 1 ; i<x ; i++){
        if (x%i ==0){
            sumax+= i;
        }
    }    
    for (i = 1 ; i<y ; i++){
        if (y%i ==0){
            sumay+= i;
        }
    }
    if (sumax == y && sumay == x){
        return true;
    }
    else{
        return false;
    }
}

int calculate_time_in_seconds(float di, float df, float v) {
    int distance = (int)(df - di);
    int time; 
    if (v == 0) return -1;
    if ((df-di)<0){
        distance = distance*(-1);
    }
    time = distance / (int)v;   
    return time;
}

void swap(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
    return;
}

int array_min_index(const int *array, int length) {
    int minimo = 0;
    if (array == NULL) return -1;
    for (int i = 0 ; i<length ; i++){
        if (array[minimo] > array[i]){
            minimo = i;
        }
    }
    return minimo;
}

int *copy_array(const int *array, int length) {
    if (array==NULL || length<=0) return NULL;
    int* cparray = (int*) malloc(length*sizeof(int));
    if (!cparray) return NULL;
    for (int i = 0; i<length ; i++){
        cparray[i] = array[i];
    }
    return cparray;
}

void selection_sort(int *array, int length){
    if (array == NULL) return;
    int aux , i , j , min;
    for (i = 0 ; i<length ; i++){
        min = i;
        for (j = i+1 ; j<length ; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
    return;
}

int* array_union(const int *array1, int length1, const int *array2, int length2) {
    int counter = 0 , n = length1+length2;
    if (n == 0) return NULL;
    int *union_array_rep = (int*) malloc((length1 + length2) * sizeof(int));
    if (!union_array_rep) return NULL; 
    int i , j ;
    for (i = 0 ; i<length1 ; i++){
        union_array_rep[i] = array1[i];    
    }
    for (j=0; j<length2 ; j++){
        union_array_rep[j + length1] = array2[j];
    }
    selection_sort(union_array_rep,(length1 + length2));
    for (i = 0 ; i<n-1 ; i++){
        if(union_array_rep[i] != union_array_rep[i+1]){
            counter++;
    }}
    counter++;
    int *union_array = (int*) malloc(counter * sizeof(int));
    j=0;
    for (i = 0 ; i<n-1 ; i++){
        if (union_array_rep[i] != union_array_rep[i+1]){
            union_array[j] = union_array_rep[i];
            j++;
        }
    }
    union_array[j] = union_array_rep[n-1];
    free(union_array_rep);
    return (union_array);
}

void matrix_map(Matriz matrix, int row_size, int col_size, int f(int)) {
    int i , j;
    if(f == NULL) return;
    for (i = 0 ; i < row_size ; i++){
        for (j = 0 ; j< col_size ; j++){
            matrix[i][j] = f(matrix[i][j]);
        }
    }
    return;
}

Matriz copy_matrix(const Matriz matrix, int row_size, int col_size) {
    if (matrix == NULL) return NULL;
    Matriz cpmat = malloc (sizeof(int*)*row_size);
    if (!cpmat) return NULL;
 
    int i , j ; 
    for (i = 0 ; i <row_size ; i++ ){
        cpmat[i] = malloc (sizeof(int) *col_size);
        if(!cpmat[i]){
            for(int k = 0; k < i; k++){
                free(cpmat[k]);
            }
            free(cpmat);
            return NULL ; 
        }
        for (j = 0 ; j < col_size ; j++){
            cpmat[i][j] = matrix[i][j];
        }
    }
    return cpmat;
}

bool matrix_equal(const Matriz matrix1, int row_size1, int col_size1, const Matriz matrix2, int row_size2, int col_size2) {
    if(matrix1 == NULL && matrix2 ==NULL) return true;
    if(matrix1 == NULL || matrix2 == NULL) return false;
    if (row_size1 != row_size2 || col_size1 != col_size2) return false;
    int i , j;
    for (i = 0 ; i< row_size1 ; i++){
        for (j = 0 ; j<col_size1 ; j++){
            if(matrix1[i][j] != matrix2 [i][j]) return false;
        }
    }
    return true;
}

Matriz* copy_array_of_matrices(const Matriz *array_of_matrices, const Matriz matrix_dimensions, int array_lenght) {
    if (array_of_matrices == NULL) return NULL;
    int i;
    Matriz *cp_array_matriz = malloc (sizeof(Matriz)*array_lenght);
    for (i = 0 ; i< array_lenght ; i++){
        cp_array_matriz[i] = copy_matrix(array_of_matrices[i],matrix_dimensions[i][0] , matrix_dimensions[i][1]);
    }

    return cp_array_matriz;
}

void free_array_of_matrices(Matriz* array_of_matrices, Matriz matrix_dimensions, int array_lenght) {
    if (array_of_matrices == NULL) return;
    int i , j;
    for(i= 0; i<array_lenght ;i++){
        for (j = 0 ; j< matrix_dimensions[i][0] ; j++){
            free(array_of_matrices[i][j]);
        }
        free(array_of_matrices[i]);

    }
    free(array_of_matrices);
    for (int i = 0; i < array_lenght; i++) {
        free(matrix_dimensions[i]); 
    }
    free(matrix_dimensions);
    return;

}

