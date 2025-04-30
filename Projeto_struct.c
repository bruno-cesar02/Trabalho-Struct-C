#include <stdio.h>
#include <stdbool.h>

// Criar struct
struct Biblioteca {
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
struct Biblioteca total_livros[100];
int tamanho_livros = 0;


// Função cadastrar
void Cadastrar() {
    int novo_id;
    printf("Digite o id: ");
    scanf("%d", &novo_id);

    // Verifica se ID já existe
    for (int i = 0; i < tamanho_livros; i++) {
        if (total_livros[i].id == novo_id) {
            printf("Livro já cadastrado. Aumentando quantidade...\n");
            total_livros[i].qntd++;
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

    total_livros[tamanho_livros].qntd = 1;
    tamanho_livros++;
}

// Busca livro pelo ID
void Consultar() {
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
            return;
        }
    }

    printf("Livro com ID %d nao encontrado.\n", id_con);
}

// Mostra todos os livros cadastrados
void Listar() {
    if (tamanho_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
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
}

// Função para realizar o emprestimo
void Emprestar() {

    if (tamanho_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
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
                        return;
                    }
                }

                printf ("Total de livros para emprestimo atingido.\n");

            }

            else {
                printf ("Nao ha quantidade de livros suficiente para emprestimo.");
            }
        }

    }
    
    if (encontrado == false) {
        printf ("ID %d nao encontrado.", id_emp);
    }

}

void Devolver () {

    if (tamanho_livros == 0) {
        printf ("Nao ha livros cadastrados.\n");
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
                    return;
                }
            }

            printf ("Nome nao encontrado na lista de emprestimos.\n");
            return;

        }
    }

    if (encontrou == false) {
        printf ("ID nao encontrado.\n");
    }

}

// Menu
int main() {
    int opcao;

    do {
        printf("\n===== MENU BIBLIOTECA =====\n");
        printf("1. Cadastrar livro\n");
        printf("2. Consultar livro por ID\n");
        printf("3. Listar todos os livros\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Cadastrar();
                break;
            case 2:
                Consultar();
                break;
            case 3:
                Listar();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
