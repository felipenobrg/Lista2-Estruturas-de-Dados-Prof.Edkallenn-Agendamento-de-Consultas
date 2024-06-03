#include "patient.h"
#include <string.h>

Patient registerPatient(char name[50], int cpf, char birth_date[11], char phone[15], char email[50])
{
    Patient patient;
    strcpy(patient.name, name);
    patient.cpf = cpf;
    strcpy(patient.birth_date, birth_date);
    strcpy(patient.phone, phone);
    strcpy(patient.email, email);
    return patient;
}
