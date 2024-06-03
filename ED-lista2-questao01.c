/*
** Função: Sistema de Agendamento de Consultas
** Autor: Felipe Nóbrega de Almeida
** Data: 02/06/2024
** Observações:
*/

#include <locale.h>

#include "patient/patient.h"
#include "nursing/nursing.h"
#include "doctor/doctor.h"

void menu();
void menuNursingQueue();
void menuDoctorQueue();
Patient newPatient();
void clearConsole();

int main()
{
    setlocale(LC_ALL, "Portugese");

    NursingQueue *nursingQueue = createNursingQueue();
    DoctorQueue *doctorQueue = createDoctorQueue();

    printf("Bem-vindo ao Sistema de Agendamento de Consultas\n");

    int option;
    while (1)
    {
        menu();
        scanf("%d", &option);
        fflush(stdin);

        switch (option)
        {
        case 1:
            while (1)
            {
                menuNursingQueue();
                scanf("%d", &option);
                fflush(stdin);
                clearConsole();

                switch (option)
                {
                case 1:
                    addPatientToNursingQueue(nursingQueue, newPatient());
                    break;
                case 2:
                    removePatientFromNursingQueue(nursingQueue);
                    break;
                case 3:
                    printNursingQueue(nursingQueue);
                    break;
                case 4:
                    clearConsole();
                    break;
                default:
                    printf("Opção inválida\n");
                    break;
                }

                if (option == 4)
                {
                    break;
                }
            }
            break;
        case 2:
            while (1)
            {
                menuDoctorQueue();
                scanf("%d", &option);
                fflush(stdin);
                clearConsole();

                switch (option)
                {
                case 1:
                    addPatientToDoctorQueue(doctorQueue, newPatient());
                    break;
                case 2:
                    removePatientFromDoctorQueue(doctorQueue);
                    break;
                case 3:
                    printDoctorQueue(doctorQueue);
                    break;
                case 4:
                    clearConsole();
                    break;
                default:
                    printf("Opção inválida\n");
                    break;
                }

                if (option == 4)
                {
                    break;
                }
            }
            break;
        case 3:
            freeNursingQueue(nursingQueue);
            freeDoctorQueue(doctorQueue);
            return 0;
        default:
            printf("Opção inválida\n");
            break;
        }
    }

    return 0;
}

void menu()
{
    printf("\n");
    printf("1 - Fila Enfermagem\n");
    printf("2 - Fila Médico\n");
    printf("3 - Sair\n");
}

void menuNursingQueue()
{
    printf("\n");
    printf("1 - Adicionar Pasciente\n");
    printf("2 - Remover Pasciente\n");
    printf("3 - Imprimir Fila\n");
    printf("4 - Voltar\n");
}

void menuDoctorQueue()
{
    printf("\n");
    printf("1 - Adicionar Pasciente\n");
    printf("2 - Remover Pasciente\n");
    printf("3 - Imprimir Fila\n");
    printf("4 - Voltar\n");
}

Patient newPatient()
{
    char name[50];
    int cpf;
    char birth_date[11];
    char phone[15];
    char email[50];

    printf("\n");
    printf("Nome: ");
    scanf("%s", name);
    fflush(stdin);

    printf("CPF: ");
    scanf("%d", &cpf);
    fflush(stdin);

    printf("Data de Nascimento: ");
    scanf("%s", birth_date);
    fflush(stdin);

    printf("Telefone: ");
    scanf("%s", phone);
    fflush(stdin);

    printf("Email: ");
    scanf("%s", email);
    fflush(stdin);

    return registerPatient(name, cpf, birth_date, phone, email);
}

void clearConsole()
{
    system("cls");
}