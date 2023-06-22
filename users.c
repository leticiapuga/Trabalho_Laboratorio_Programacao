#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct que define o usuário
typedef struct users
{
    char *id;
    char *name;
    char *email;
    char *password;
}users;


//Função para Cadastrar Usuário
void create_user(users user){
    //Abre o arquivo de "users.txt" no modo "append" ou adicionar
    FILE *new_user = fopen("../users/users.txt", "a");  

    //testa se consegui abrir o arquivo
    if (new_user == NULL)
    {
        printf("Erro ao abrir o arquivo Users!\n");
        system("pause");
        exit(1);
    
    }

    //Escreve no arquivo
    fprintf(new_user, "%s -=- %s -=- %s -=- %s\n", user.id, user.name, user.email, user.password);

    //Fecha o arquivo fechado
    fclose(new_user);
}

int main(){
    // linha 38 até linha 42 crio 1 usuário, mas é gambiarra, vai ser mudado pela interação com o IG.
    users Leticia;
    Leticia.id = "02";
    Leticia.name = "Leticia";
    Leticia.email = "Leticia@gmail.com";
    Leticia.password = "1234";

    create_user(Leticia);
    return 0;
}