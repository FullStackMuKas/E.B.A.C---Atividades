#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file, "%s;", cpf); // salvo o valor da vari�vel
    fclose(file); // fecha o arquivo

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s;", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s;", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    system("pause");
    return 0;
}

int consulta() {
    char cpf[40], conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
    } else {
        while (fgets(conteudo, 200, file) != NULL) {
            printf("Essas s�o as informa��es do usu�rio: ");
            printf("%s\n", conteudo);
        }
        system("pause");
        fclose(file);
    }
    return 0;
}

int deletar() {
    printf("Voc� escolheu deletar nomes!\n");
    system("pause");
    return 0;
}

void sair() {
    printf("Saindo do sistema...\n");
    system("pause");
}

int main() {
    int opcao = 0, laco = 1;
    char senhadigitada[10] = "a"; // inicializa a senha digitada
    char senha[10] = "admin"; // senha correta

    setlocale(LC_ALL, "Portuguese");

    printf("### Cart�rio da EBAC ###\n");
    printf("Login de administrador\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    if(senhadigitada[0] == 'a' && strcmp(senhadigitada, senha) == 0) {
        for (laco = 1; laco == 1;) {
            system("cls");
            printf("### Cart�rio da EBAC ###\n");
            printf("Escolha a op��o desejada do menu\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair\n\n");
            printf("Op��o: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    registro();
                    break;
                case 2:
                    consulta();
                    break;
                case 3:
                    deletar();
                    break;
                case 4:
                    sair();
                    laco = 0; // Encerra o loop
                    break;
                default:
                    printf("Essa op��o n�o est� dispon�vel!\n");
                    system("pause");
                    break;
            }
        }
    } else {
        printf("Senha incorreta\n");
    }

    return 0;
}

