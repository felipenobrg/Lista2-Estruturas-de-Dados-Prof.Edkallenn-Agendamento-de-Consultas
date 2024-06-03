#include <stdio.h>
#include <stdlib.h>
#include "../patient/patient.h"

typedef struct DoctorQueue
{
    int size;
    int maxCapacity;
    struct DoctorNode *start;
    struct DoctorNode *end;
} DoctorQueue;

typedef struct DoctorNode
{
    Patient patient;
    struct DoctorNode *next;
    struct DoctorNode *prev;
} DoctorNode;

DoctorQueue *createDoctorQueue();
void addPatientToDoctorQueue(DoctorQueue *queue, Patient patient);
void printDoctorQueue(DoctorQueue *queue);
void removePatientFromDoctorQueue(DoctorQueue *queue);
void freeDoctorQueue(DoctorQueue *queue);
