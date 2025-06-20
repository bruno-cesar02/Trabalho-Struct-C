#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
/*
MEMBROS DO GRUPO:
Arthur Sebastian – RA: 24795528
Bruno César – RA: 24795502
Gustavo Lieb – RA: 24023376

*/

// Criar struct
struct Livros {
    char titulo[100];
    char autor[100];
    int numero_pag;
    int ano;
    int id;
    int qntd;
    char emprestimo[10][100];
    int total_emprestimos;
};

// Variavel global para o tamanho do vetor
struct  Livros total_livros[100];
int tamanho_livros = 0;


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função cadastrar #1
void Cadastrar() {
    int opc;
    int qtd;

    int novo_id;
    printf("Digite o id: ");
    scanf("%d", &novo_id);

    // Verifica se ID já existe
    for (int i = 0; i < tamanho_livros; i++) {
        if (total_livros[i].id == novo_id) {
            printf("Livro ja cadastrado.\n");
            printf("Deseja adicionar apenas mais 1 ou uma quantidade especifica\n");
            printf("1 - aumentar em 1\n");
            printf("2 - adicionar uma quantidade especifica\n");
            printf("digite a opcao: \n");
            scanf("%d", &opc);

            switch (opc){
                case 1:
                    printf("Aumentando quantidade em mais 1...");
                    total_livros[i].qntd++;
                    pausarTela();
                    return;
                
                case 2: 
                    printf("digite a quantidade de livros: ");
                    scanf("%d", &qtd);
                    total_livros[i].qntd += qtd;
                    printf("livros adicionados com sucesso!!!");
                    pausarTela();
                    return;
            }
            
            return;
        }
    }

    total_livros[tamanho_livros].id = novo_id;

    printf("Digite o nome do livro: ");
    scanf(" %[^\n]", total_livros[tamanho_livros].titulo);

    printf("Digite o nome do autor: ");
    scanf(" %[^\n]", total_livros[tamanho_livros].autor);

    printf("Digite o numero de paginas: ");
    scanf("%d", &total_livros[tamanho_livros].numero_pag);

    printf("Digite o ano de publicacao: ");
    scanf("%d", &total_livros[tamanho_livros].ano);

    printf("digite a quantidade: ");
    scanf("%d", &qtd);

    
     
    total_livros[tamanho_livros].qntd += qtd;
    tamanho_livros++;

    printf("Livro Cadastrado com sucesso\n");
    pausarTela();
}

// Busca livro pelo ID #2
void Consultar() {
    
    limparBuffer();

    int id_con;
    printf("Digite o ID desejado: ");
    scanf("%d", &id_con);

    for (int i = 0; i < tamanho_livros; i++) {
        if (total_livros[i].id == id_con) {
            printf("Titulo: %s\n", total_livros[i].titulo);
            printf("Autor: %s\n", total_livros[i].autor);
            printf("Paginas: %d\n", total_livros[i].numero_pag);
            printf("Ano: %d\n", total_livros[i].ano);
            printf("ID: %d\n", total_livros[i].id);
            printf("Quantidade: %d\n", total_livros[i].qntd);
            pausarTela();
            return;
        }
    }

    printf("Livro com ID %d nao encontrado.\n", id_con);
    pausarTela();
}

// Mostra todos os livros cadastrados #2
void Listar() {
    
    if (tamanho_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
        pausarTela();
        return;
    }

    for (int i = 0; i < tamanho_livros; i++) {
        printf("Titulo: %s\n", total_livros[i].titulo);
        printf("Autor: %s\n", total_livros[i].autor);
        printf("Paginas: %d\n", total_livros[i].numero_pag);
        printf("Ano: %d\n", total_livros[i].ano);
        printf("ID: %d\n", total_livros[i].id);
        printf("Quantidade: %d\n\n", total_livros[i].qntd);
    }
    pausarTela();
}

// Função para realizar o emprestimo #3
void Emprestar() {
    

    if (tamanho_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
        pausarTela();
        return;
    }

    char nome_emprestimo[100];
    int id_emp;
    bool encontrado = false;
    
    printf ("Digite o ID do livro procurado: ");
    scanf ("%d", &id_emp);

    for (int i = 0;i < tamanho_livros; i++) {
        if (total_livros[i].id == id_emp) {
            encontrado = true;


            if (total_livros[i].qntd > 0) {
                printf ("Nome da pessoa: ");
                scanf (" %[^\n]", nome_emprestimo);

                for (int j = 0; j < 10; j++){
                    if (strlen(total_livros[i].emprestimo[j]) == 0) {
                        strcpy(total_livros[i].emprestimo[j], nome_emprestimo);
                        total_livros[i].qntd--;
                        printf ("Livro emprestado com sucesso!\n");
                        pausarTela();
                        return;
                    }
                }

                printf ("Total de livros para emprestimo atingido.\n");
                pausarTela();
            }

            else {
                printf ("Nao ha quantidade de livros suficiente para emprestimo.");
                pausarTela();
            }
        }

    }
    
    if (encontrado == false) {
        printf ("ID %d nao encontrado.", id_emp);
    }
    pausarTela();

}

//Função para devolver livros #4
void Devolver () {
    

    if (tamanho_livros == 0) {
        printf ("Nao ha livros cadastrados.\n");
        pausarTela();
        return;
    }

    int id_devo;
    bool encontrou = false;
    char nome_devolucao[100];

    printf ("ID do livro: \n");
    scanf ("%d", &id_devo);

    for (int i = 0; i < tamanho_livros; i++) {
        if (total_livros[i].id == id_devo) {
            encontrou = true;

            printf ("Nome da pessoa que emprestou: \n");
            scanf (" %[^\n]", nome_devolucao);

            for (int j = 0; j < 10; j ++) {
                //compara nomes, se for igual retorna 0
                if (strcmp(total_livros[i].emprestimo[j], nome_devolucao) == 0) {
                    //se nome for encontrado limpa a posição
                    strcpy(total_livros[i].emprestimo[j], "");
                    total_livros[i].qntd++;
                    printf ("Livro devolvido com sucesso!\n");
                    pausarTela();
                    return;
                }
                else{
                    printf("Nome nao existe no sistema");
                    pausarTela();
                    return;
                }
            }

            printf ("Nome nao encontrado na lista de emprestimos.\n");
            pausarTela();
            return;

        }
    }

    if (encontrou == false) {
        printf ("ID nao encontrado.\n");
    }
    pausarTela();

}

void remover(){
    if(tamanho_livros == 0){
        printf("Nao tem livros para serem removidos\n");
        pausarTela();
        return;
    }

    int id_remover;

    printf("Digite o ID do livro que deseja remover: ");
    scanf("%d", &id_remover);

    for(int i = 0; i<tamanho_livros; i++){
        if(total_livros[i].id == id_remover)
        {
            total_livros[i] = total_livros[tamanho_livros - 1];

            tamanho_livros --;

            printf("Livro com id %d Removido com sucesso!",id_remover);
            pausarTela();

            return;
        }
    }
    printf("O livro com ID %d nao foi encontrado no sistema", id_remover);
    pausarTela();
    return;

}


//FUNCAO PARA LIMPAR O TERMINAL
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausarTela() {
    printf("\nPressione ENTER para continuar...");
    getchar(); // tira o ultimo enter digitado
    getchar(); // esse espera o proximo enter q o usuario vai digitar
}



// Menu
int main() {
    int opcao;
    do
    {   
        limparTela();
        printf("\n");
        printf("=====================================\n");
        printf("     SISTEMA DE BIBLIOTECA - MENU    \n");
        printf("=====================================\n");
        printf("  1 - Cadastrar livros\n");
        printf("  2 - Consultar livro por ID\n");
        printf("  3 - Listar todos os livros\n");
        printf("  4 - Emprestar livro\n");
        printf("  5 - Devolver livro\n");
        printf("  6 - Remover livros\n");
        printf("  7 - Sair do sistema\n");
        printf("=====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                limparTela();
                Cadastrar();
                break;
            case 2:
                limparTela();
                Consultar();
                break;
            case 3:
                limparTela();
                Listar();
                break;
            case 4:
                limparTela();
                Emprestar();
                break;
            case 5:
                limparTela();
                Devolver();
                break;
            case 6:
                limparTela();    // Funcao para limpar o terminal 
                remover(); //remover livro
                break;
            case 7:
                limparTela();
                printf("Encerrando Sistema... ate logo");
                break;
            default:
                printf("Opcao Invalida");
                pausarTela();
        }
    
    } while (opcao != 7);

    return 0;
}
