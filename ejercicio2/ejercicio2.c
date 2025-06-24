#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t semM2FN,
    semF1FN, 
    semF1TD, 
    semQGTD, 
    semM2RR, 
    semM2FN, 
    semFNRR, 
    semFNPR, 
    semFNINU, 
    semQGMIN, 
    semRRSR, 
    semM2MF, 
    semTDMF, 
    semMFSR, 
    semSRSN, 
    semFNMIN, 
    semMINCB, 
    semMINPR,
    semPRCB,
    semPRSN,
    semPRINU;


void* M1(void* x) {
    printf("M1 (Matemáticas I)\n");
    printf("M2 (Matemáticas II)\n");
    sem_post(&semM2FN);
    sem_post(&semM2RR);
    sem_post(&semM2MF);
    pthread_exit(0);
}

void* IN(void* x) {
    printf("IN (Introducción a la Ingeniería Nuclear)\n");
    pthread_exit(0);
}

void* FN(void* x) {
    sem_wait(&semM2FN);
    sem_wait(&semF1FN);
    printf("FN (Fisica Nuclear)\n");
    sem_post(&semFNRR);
    sem_post(&semFNINU);
    sem_post(&semFNPR);
    sem_post(&semFNMIN);
    pthread_exit(0);
}

void* F1(void* x) {
    printf("F1 (Fisica 1)\n");
    sem_post(&semF1FN);
    sem_post(&semF1TD);
    pthread_exit(0);
}

void* QG(void* x) {
    printf("QG (Quimica General)\n");
    sem_post(&semQGTD);
    sem_post(&semQGMIN);
    pthread_exit(0);
}

void* RR(void* x){
    sem_wait(&semM2RR);
    sem_wait(&semFNRR);
    printf("RR (Reactividad de Reactores)\n");
    sem_post(&semRRSR);
    pthread_exit(0);
}

void* MF(void * x){
    sem_wait(&semM2MF);
    sem_wait(&semTDMF);
    printf("MF (Mecánica de Fluidos)\n");
    sem_post(&semMFSR);
    pthread_exit(0);
}

void* SR(void* x){
    sem_wait(&semRRSR);
    sem_wait(&semMFSR);
    printf("SR (Sistemas de Reactores)\n");
    sem_post(&semSRSN);
    pthread_exit(0);
}

void* TD(void* x){
    sem_wait(&semF1TD);
    sem_wait(&semQGTD);
    printf("TD (Termodinámica)\n");
    sem_post(&semTDMF);
    pthread_exit(0);
}

void* MIN(void* x){
    sem_wait(&semFNMIN);
    sem_wait(&semQGMIN);
    printf("MIN (Materiales en Ingeniería Nuclear)\n");
    sem_post(&semMINCB);
    sem_post(&semMINPR);
    pthread_exit(0);
}

void* PR(void* x){
    sem_wait(&semMINPR);
    sem_wait(&semFNPR);
    printf("PR (Protección Radiológica)\n");
    sem_post(&semPRCB);
    sem_post(&semPRSN);
    sem_post(&semPRINU);
    pthread_exit(0);
}

void* INU(void* x){
    sem_wait(&semPRINU);
    sem_wait(&semFNINU);
    printf("INU (Instrumentación Nuclear)\n");
    pthread_exit(0);
}

void* CB(void* x){
    sem_wait(&semMINCB);
    sem_wait(&semPRCB);
    printf("CB (Cálculo de Blindajes)\n");
    pthread_exit(0);
}

void* SN(void* x){
    sem_wait(&semSRSN);
    sem_wait(&semPRSN);
    printf("SN (Seguridad Nuclear)\n");
    pthread_exit(0);
}

int main() {

    sem_init(&semM2FN, 0, 0);
    sem_init(&semF1FN, 0, 0);
    sem_init(&semF1TD, 0, 0);
    sem_init(&semQGTD, 0, 0);
    sem_init(&semM2RR, 0, 0);
    sem_init(&semM2MF, 0, 0);
    sem_init(&semFNRR, 0, 0);
    sem_init(&semFNPR, 0, 0);
    sem_init(&semFNINU, 0, 0);
    sem_init(&semQGMIN, 0, 0);
    sem_init(&semRRSR, 0, 0);
    sem_init(&semTDMF, 0, 0);
    sem_init(&semMFSR, 0, 0);
    sem_init(&semSRSN, 0, 0);
    sem_init(&semFNMIN, 0, 0);
    sem_init(&semMINCB, 0, 0);
    sem_init(&semMINPR, 0, 0);
    sem_init(&semPRCB, 0, 0);
    sem_init(&semPRSN, 0, 0);
    sem_init(&semPRINU, 0, 0);

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_t t_IN, t_M1, t_F1, t_QG, t_TD, t_FN, t_MF, t_MIN, t_RR, t_PR, t_SR, t_INU, t_CB, t_SN;
    pthread_create(&t_IN, &attr, IN, NULL);
    pthread_create(&t_M1, &attr, M1, NULL);
    pthread_create(&t_F1, &attr, F1, NULL);
    pthread_create(&t_QG, &attr, QG, NULL);
    
    pthread_create(&t_TD, &attr, TD, NULL);
    pthread_create(&t_FN, &attr, FN, NULL);
    pthread_create(&t_MF, &attr, MF, NULL);
    pthread_create(&t_MIN, &attr, MIN, NULL);
    pthread_create(&t_RR, &attr, RR, NULL);
    pthread_create(&t_PR, &attr, PR, NULL);
    pthread_create(&t_SR, &attr, SR, NULL);
    pthread_create(&t_INU, &attr, INU, NULL);
    pthread_create(&t_CB, &attr, CB, NULL);
    pthread_create(&t_SN, &attr, SN, NULL);

    pthread_join(t_INU, NULL);
    pthread_join(t_CB, NULL);
    pthread_join(t_SN, NULL);

    return 0;
}
