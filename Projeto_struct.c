#include <stdio.h>
#include <stdbool.h>

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

struct Biblioteca total_livros[100];
int tamanho_livros = 0;

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

void Consultar() {
    int id;
    printf("Digite o ID desejado: ");
    scanf("%d", &id);

    for (int i = 0; i < tamanho_livros; i++) {
        if (total_livros[i].id == id) {
            printf("Titulo: %s\n", total_livros[i].titulo);
            printf("Autor: %s\n", total_livros[i].autor);
            printf("Paginas: %d\n", total_livros[i].numero_pag);
            printf("Ano: %d\n", total_livros[i].ano);
            printf("ID: %d\n", total_livros[i].id);
            printf("Quantidade: %d\n", total_livros[i].qntd);
            return;
        }
    }

    printf("Livro com ID %d nao encontrado.\n", id);
}

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
