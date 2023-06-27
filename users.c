#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct que define o usuário
typedef struct users
{
    char *id;
    char *name;
    char *email;
    char *password;
    struct users *prox;
} users;

users *inicio = NULL;
users *final = NULL;
int tam_Users = 0;

// Função para Cadastrar Usuário
void create_user(users user)
{
    // Abre o arquivo de "users.txt" no modo "append" ou adicionar
    FILE *new_user = fopen("../users/users.txt", "a");

    // testa se consegui abrir o arquivo
    if (new_user == NULL)
    {
        printf("Erro ao abrir o arquivo Users!\n");
        system("pause");
        exit(1);
    }

    // Escreve no arquivo
    fprintf(new_user, "%s -=- %s -=- %s -=- %s\n", user.id, user.name, user.email, user.password);

    // Fecha o arquivo fechado
    fclose(new_user);
}

// Função para ler o arquivo de usuários.

void read_users_file()
{
    // Abre o arquivo "users.txt" para leitura.

    FILE *users_file = fopen("../users/users.txt", "r");

    // Verifica se o arquivo foi aberto corretamente.

    if (users_file == NULL)
    {
        printf("Erro ao abrir o arquivo Users!\n");
        system("pause");
        exit(1);
    }

    // Variáveis temporárias para armazenar os dados lidos.

    char linha[256];
    char *id, *name, *email, *password;

    // Lê cada linha do arquivo.

    while (fgets(linha, sizeof(linha), users_file) != NULL)
    {
        // Divide a linha em campos separados pelo delimitador "-=-"

        id = strtok(linha, "-=-");
        name = strtok(NULL, "-=-");
        email = strtok(NULL, "-=-");
        password = strtok(NULL, "-=-");

        // Cria uma estrutura de usuário e atribui os valores lidos.

        users *user = malloc(sizeof(users));
        user->id = strdup(id);
        user->name = strdup(name);
        user->email = strdup(email);
        user->password = strdup(password);
        user->prox = NULL;

        if (inicio == NULL)
        {
            inicio = user;
            final = user;
        }
        else
        {
            final->prox = user;
            final = user;
        }
        tam_Users++;
    }

    // Fecha o arquivo.

    fclose(users_file);
}

void print_list()
{
    users *aux = inicio;
    for (int i = 0; i < tam_Users; i++)
    {
        printf("%s -=- %s -=- %s -=- %s\n", aux->id, aux->name, aux->email, aux->password);
        aux = aux->prox;
    }
}

int main()
{
    // linha 38 até linha 42 crio 1 usuário, mas é gambiarra, vai ser mudado pela interação com o IG.
    // users Leticia;
    // Leticia.id = "02";
    // Leticia.name = "Leticia";
    // Leticia.email = "Leticia@gmail.com";
    // Leticia.password = "1234";

    // create_user(Leticia);

    read_users_file();
    print_list();

    return 0;
}