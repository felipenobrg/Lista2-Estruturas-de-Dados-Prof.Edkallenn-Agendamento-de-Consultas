#include <stdio.h>
#include <stdlib.h>
#include "../patient/patient.h"

typedef struct NursingQueue
{
    int size;
    struct NursingNode *start;
    struct NursingNode *end;
} NursingQueue;

typedef struct NursingNode
{
    Patient patient;
    struct NursingNode *prev;
    struct NursingNode *next;
} NursingNode;

NursingQueue *createNursingQueue();
void addPatientToNursingQueue(NursingQueue *queue, Patient patient);
void printNursingQueue(NursingQueue *queue);
void removePatientFromNursingQueue(NursingQueue *queue);
void freeNursingQueue(NursingQueue *queue);
