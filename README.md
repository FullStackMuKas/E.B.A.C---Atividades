Cartório da EBAC

Este projeto é um programa simples de cartório escrito em C, desenvolvido para registrar, consultar e deletar informações de usuários com base no CPF.
Funcionalidades

    Registro de usuário: Registra informações como CPF, nome, sobrenome e cargo.
    Consulta de usuário: Consulta e exibe informações registradas de um usuário pelo CPF.
    Deleção de usuário: Opção para deletar informações de um usuário (ainda a ser implementada).

Requisitos

    Compilador C (como gcc)
    Sistema operacional compatível com comandos de terminal (Linux, macOS, Windows com Prompt de Comando)

Ao executar o programa, você verá o menu principal com as opções:

    Registro: Digite 1 para registrar um novo usuário. Siga as instruções para inserir CPF, nome, sobrenome e cargo.
    Consulta: Digite 2 para consultar as informações de um usuário pelo CPF.
    Deleção: Digite 3 para deletar informações de um usuário (a ser implementado).
    Sair: Digite 4 para sair do programa.

Explicação do Código:

registro()
Esta função coleta informações do usuário (CPF, nome, sobrenome e cargo) e as salva em um arquivo nomeado com o CPF.

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    strcpy(arquivo, cpf);

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, "%s;", cpf);
    fclose(file);

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

consulta()
Esta função consulta um arquivo baseado no CPF fornecido pelo usuário e exibe seu conteúdo.

int consulta() {
    char cpf[40], conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo, não localizado.\n");
    } else {
        while (fgets(conteudo, 200, file) != NULL) {
            printf("Essas são as informações do usuário: ");
            printf("%s\n", conteudo);
        }
        system("pause");
        fclose(file);
    }
    return 0;
    }

deletar()
Esta função é um placeholder para deletar informações de um usuário. No momento, apenas exibe uma mensagem.

int deletar() {
    printf("Você escolheu deletar nomes!\n");
    system("pause");
    return 0;
}

main()
A função principal exibe um menu e chama as outras funções com base na entrada do usuário.

int main() {
    int opcao = 0, laco = 1;
    setlocale(LC_ALL, "Portuguese");

    while (laco) {
        system("cls");
        printf("### Cartório da EBAC ###\n");
        printf("1. Registro\n");
        printf("2. Consulta\n");
        printf("3. Deletar\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
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
                laco = 0;
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                system("pause");
                break;
        }
    }

    return 0;
    }
