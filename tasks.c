#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct task
typedef struct tasks
{
    char *id;
    char *title;
    char *desc;
    char *date_hour_initial;
    char *date_hour_final;
    char *locate;
    char *do_check;
}tasks;

//Função para criar uma tarefa
void create_task(tasks task, char *user_id){
    //linha 20 à 22 eu concateno o endereço até que fique da maneira "../task/task_ID_USERS.txt"
    char taskPath[] = "../tasks/task_";
    strcat(taskPath, user_id);
    strcat(taskPath, ".txt");

    //Abre o arquivo
    FILE *new_task = fopen(taskPath, "a");

    //Testa se funcionou abrir
    if (new_task == NULL)
    {
        printf("Erro ao abrir o arquivo Task!\n");
        system("pause");
        exit(1);
    }

    
    //Essa parte não acabei
    fprintf(new_task, "%s -=- %s -=- %s -=- %s -=- %s -=- %s -=- %s\n", task.id, task.title, task.desc, task.date_hour_initial, task.date_hour_final, task.locate, task.do_check);
    fclose(new_task);
}

int main(){
    tasks alisson_task;
    alisson_task.id = "10";
    alisson_task.title = "titulo";
    alisson_task.desc = "descricao";
    alisson_task.date_hour_initial = "21/06/2023 09:39";
    alisson_task.date_hour_initial = "31/12/2023 23:59";
    alisson_task.locate = "em casa";
    alisson_task.do_check = "check";


    create_task(alisson_task, "1");
    return 0;
}

