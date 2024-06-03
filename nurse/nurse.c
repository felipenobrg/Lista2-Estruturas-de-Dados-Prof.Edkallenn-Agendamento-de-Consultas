#include "nursing.h"

NursingQueue *createNursingQueue()
{
    NursingQueue *queue = (NursingQueue *)malloc(sizeof(NursingQueue));
    queue->size = 0;
    queue->start = NULL;
    queue->end = NULL;
    return queue;
}

void addPatientToNursingQueue(NursingQueue *queue, Patient patient)
{
    NursingNode *newNode = (NursingNode *)malloc(sizeof(NursingNode));
    newNode->patient = patient;
    newNode->next = NULL;
    if (queue->size == 0)
    {
        newNode->prev = NULL;
        queue->start = newNode;
        queue->end = newNode;
    }
    else
    {
        newNode->prev = queue->end;
        queue->end->next = newNode;
        queue->end = newNode;
    }
    queue->size++;
}

void printNursingQueue(NursingQueue *queue)
{
    int i = 0;
    NursingNode *current = queue->start;
    while (current != NULL)
    {
        i++;
        printf("\n");
        printf("Nome: %s\n", current->patient.name);
        printf("CPF: %d\n", current->patient.cpf);
        printf("Data de Nascimento: %s\n", current->patient.birth_date);
        printf("Celular: %s\n", current->patient.phone);
        printf("Email: %s\n", current->patient.email);
        printf("\n");
        current = current->next;
    }
}

void removePatientFromNursingQueue(NursingQueue *queue)
{
    if (queue->size == 0)
    {
        printf("Fila está vazia\n");
        return;
    }
    NursingNode *removedNode = queue->start;
    queue->start = queue->start->next;
    free(removedNode);
    queue->size--;
}

void freeNursingQueue(NursingQueue *queue)
{
    NursingNode *current = queue->start;
    while (current != NULL)
    {
        NursingNode *next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}
