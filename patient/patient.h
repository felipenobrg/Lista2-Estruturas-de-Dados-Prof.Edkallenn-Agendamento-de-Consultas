#ifndef PASCIENTE_H
#define PASCIENTE_H

typedef struct Pasciente
{
    char name[50];
    int cpf;
    char birth_date[11];
    char phone[15];
    char email[50];
} Patient;

Patient registerPatient(char name[50], int cpf, char birth_date[11], char phone[15], char email[50]);

#endif