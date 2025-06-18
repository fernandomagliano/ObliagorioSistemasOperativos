#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int arr1[] = {1, 2, 3, 4, 5};
int arr2[] = {1, 2, 3, 4, 5};
int result[5];
int finalResult;

void *toSum(void *i){
    int pos = *(int*)i;
    result[pos] = arr1[pos] + arr2[pos];
    printf("Hilo %d: Suma %d + %d = %d\n", pos + 1, arr1[pos], arr2[pos], result[pos]);
    pthread_exit(NULL);
}

void *toMultiply(void *res){
    int totalSum = *(int*)res;
    printf("Hilo %d: Suma total = %d\n", 4, totalSum);
    result[3] = totalSum * arr1[3] * arr2[3];
    printf("Hilo %d: Multiplicacion %d * %d * %d = %d\n", 4, totalSum, arr1[3], arr2[3], result[3]);
    pthread_exit(NULL);
}

void *toFinalSum(void *res){
    int previus = *(int*)res;
    finalResult = previus + arr1[4] + arr2[4];
    printf("Hilo %d:  %d + %d + %d = %d\n", 5, previus, arr1[4], arr2[4], finalResult);
    pthread_exit(NULL);
}

int main(){

    pthread_t thread1;
    pthread_t thread2; 
    pthread_t thread3; 
    pthread_t thread4;  
    pthread_t thread5; 

    int pos0 = 0;
    int pos1 = 1;
    int pos2 = 2;

    pthread_create(&thread1, NULL, toSum, &pos0);
    pthread_create(&thread2, NULL, toSum, &pos1);
    pthread_create(&thread3, NULL, toSum, &pos2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    int totalSum = result[pos0] + result[pos1] + result[pos2];
    pthread_create(&thread4, NULL, toMultiply, &totalSum);
    pthread_join(thread4, NULL);

    pthread_create(&thread5, NULL, toFinalSum, &result[3]);
    pthread_join(thread5, NULL);

    printf("Resultado final: %d\n", finalResult);
}