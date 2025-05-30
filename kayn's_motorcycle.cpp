#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 50 //define limite de caracteres para 50
#include <locale.h> //necess�rio para aceitar caracteres UTF-8

/*  PROJETO Kayn� Filipe 3 SI-A-N

       Kayn's Motorcycle - Administra��o.
       Fun��es:
            Registrar motos:{Modelo,MarcaAno,Estado ,Km Rodados,Pintura,Combust�vel.}
            Buscar motos:{Busca moto espec�fica no estoque}
            Motos dispon�veis:{Mostra quais motos t�m no estoque e a quantidade}
            Editar estoque:{Apaga moto do estoque, altera informa��o da moto no estoque.}
            Adicionar status:{Vendida, esgotada ou em estoque.}
            Sair:{fecha o sistema.]
*/

// Enum para status da moto
typedef enum {
    VENDIDA,
    ESGOTADA,
    EM_ESTOQUE
} StatusMoto;

// Estrutura dos dado necess�rios para o cadastro da moto.
typedef struct {
    char modelo[MAX_STRING];
    char marca[MAX_STRING];
    int ano;
    char estado[MAX_STRING];
    double km_rodados;
    char pintura[MAX_STRING];
    char combustivel[MAX_STRING];
    StatusMoto status;
} Moto;

// N� da lista encadeada
typedef struct No {
    Moto dados;
    struct No* proximo;
} No;

// In�cio da lista encadeada
No* inicio = NULL;

// contador 
int total_motos = 0;
// O Pause(), serve para pausar a execu��o do programa at� que o usuario pressiona "Enter".
void pause() {
    printf("\nPressione Enter para continuar...");
    getchar();
}
/*  
 A fun��o cadastrar moto permite ao usuario cadastrar nova moto no estoque.
(coleta os dados de estrutura Moto, cria um novo n� na lista encadeada e adiciona a moto.)
*/
void cadastrarMoto(){
    system("cls"); // limpar o terminal depois de uma tarefa executada no windows.
    printf("=== Cadastro de Moto ===\n");
   
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro ao alocar memoria para uma nova moto.\n");
        pause();
        return;
    }

    printf("Modelo: ");
    fgets(novo->dados.modelo, MAX_STRING, stdin);
    strtok(novo->dados.modelo, "\n"); // remove \n do final

    printf("Marca: ");
    fgets(novo->dados.marca, MAX_STRING, stdin);
    strtok(novo->dados.marca, "\n");

    printf("Ano: ");
    scanf("%d", &novo->dados.ano);
    getchar(); // limpa o \n do buffer

    printf("Estado (Nova, Seminova, etc): ");
    fgets(novo->dados.estado, MAX_STRING, stdin);
    strtok(novo->dados.estado, "\n");

    printf("Km Rodados: ");
    scanf("%lf", &novo->dados.km_rodados);  
    getchar();

    printf("Pintura: ");
    fgets(novo->dados.pintura, MAX_STRING, stdin);
    strtok(novo->dados.pintura, "\n");

    printf("Combust�vel: ");
    fgets(novo->dados.combustivel, MAX_STRING, stdin);
    strtok(novo->dados.combustivel, "\n");

    printf("Status (0 - Vendida, 1 - Esgotada, 2 - Em estoque): ");
    int statusTemp;
    scanf("%d", &statusTemp);
    getchar();
    novo->dados.status = (StatusMoto)statusTemp;

    // Inserir no fim da lista encadeada
    novo->proximo = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        No* temp = inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }

    total_motos++;
    printf("\nMoto cadastrada com sucesso! Total de motos: %d\n", total_motos);
    pause();
}
/* 
 A fun��o listarmotos Lista todas as motos cadastradas no estoque.
( e exibe todas  as informa��es de cada moto armazenada na lista encadeada.)  
*/
void listarmotos(){
    system("cls");
    printf("=== Listagem de Motos ===\n");
    
    if (inicio == NULL){
        printf("Nenhuma moto cadastrada no estoque.\n");    
        pause();
        return;
    }
    
    No* atual = inicio;
    int contador = 1;  // inicializado
    
    while(atual != NULL){
        
        printf("\n Moto %d:\n", contador);
        printf(" Modelo: %s\n", atual->dados.modelo);
        printf(" Marca: %s\n", atual->dados.marca);
        printf(" Ano: %d\n", atual->dados.ano);
        printf(" Estado: %s\n", atual->dados.estado);
        printf(" Km Rodados: %.2lf\n", atual->dados.km_rodados);
        printf(" Pintura: %s\n", atual->dados.pintura);
        printf(" Combust�vel: %s\n", atual->dados.combustivel);
        
        switch (atual->dados.status){
            case VENDIDA:
                printf(" Status: Vendida\n");
                break;
            
            case ESGOTADA:
                printf(" Status: Esgotada\n");
                break;
            
            case EM_ESTOQUE:
                printf(" Status: Em estoque\n");
                break;
        }
    
        atual = atual->proximo;
        contador++;
    }
    pause();
}
/*
 A fun��o editarMoto, permite Editar os dados de uma moto existente. 
*/
void editarMoto() {
    system("cls");
    printf("=== Editar Moto ===\n");

    if (inicio == NULL) {
        printf("Nenhuma moto cadastrada.\n");
        pause();
        return;
    }

    char modeloBusca[MAX_STRING];
    printf("Digite o modelo da moto que deseja editar: ");
    fgets(modeloBusca, MAX_STRING, stdin);
    strtok(modeloBusca, "\n");

    No* atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados.modelo, modeloBusca) == 0) {
            printf("\nMoto encontrada. Editando dados...\n");

            printf("Nova marca: ");
            fgets(atual->dados.marca, MAX_STRING, stdin);
            strtok(atual->dados.marca, "\n");

            printf("Novo ano: ");
            scanf("%d", &atual->dados.ano);
            getchar();

            printf("Novo estado: ");
            fgets(atual->dados.estado, MAX_STRING, stdin);
            strtok(atual->dados.estado, "\n");

            printf("Novo km rodados: ");
            scanf("%lf", &atual->dados.km_rodados);
            getchar();

            printf("Nova pintura: ");
            fgets(atual->dados.pintura, MAX_STRING, stdin);
            strtok(atual->dados.pintura, "\n");

            printf("Novo combust�vel: ");
            fgets(atual->dados.combustivel, MAX_STRING, stdin);
            strtok(atual->dados.combustivel, "\n");

            printf("Novo status (0 - Vendida, 1 - Esgotada, 2 - Em estoque): ");
            int statusTemp;
            scanf("%d", &statusTemp);
            getchar();
            atual->dados.status = (StatusMoto)statusTemp;

            printf("\nMoto atualizada com sucesso!\n");
            pause();
            return;
        }
        atual = atual->proximo;
    }

    printf("Moto com modelo '%s' n�o encontrada.\n", modeloBusca);
    pause();
}
/*
 A fun��o removerMoto permite ao usuario remover uma moto do estoque pelo modelo.
*/
void removerMoto() {
    system("cls");
    printf("=== Remover Moto ===\n");

    if (inicio == NULL) {
        printf("Nenhuma moto cadastrada.\n");
        pause();
        return;
    }

    char modeloBusca[MAX_STRING];
    printf("Digite o modelo da moto que deseja remover: ");
    fgets(modeloBusca, MAX_STRING, stdin);
    strtok(modeloBusca, "\n");

    No* atual = inicio;
    No* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados.modelo, modeloBusca) == 0) {
            if (anterior == NULL) {
                inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            total_motos--;

            printf("\nMoto '%s' removida com sucesso!\n", modeloBusca);
            pause();
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Moto com modelo '%s' n�o encontrada.\n", modeloBusca);
    pause();
}
/*  
 A fun��o buscarmoto, permite ao usuario buscar uma moto especifica cadastrada
pelo modelo e exibe suas informa��es se encontrada.
*/
void buscarMoto() {
    system("cls");
    printf("=== Buscar Moto ===\n");

    if (inicio == NULL) {
        printf("Nenhuma moto cadastrada.\n");
        pause();
        return;
    }

    char modeloBusca[MAX_STRING];
    printf("Digite o modelo da moto que deseja buscar: ");
    fgets(modeloBusca, MAX_STRING, stdin);
    strtok(modeloBusca, "\n");

    No* atual = inicio;
    int encontrada = 0;

    while (atual != NULL) {
        if (strcmp(atual->dados.modelo, modeloBusca) == 0) {
            printf("\n=== Moto Encontrada ===\n");
            printf(" Modelo: %s\n", atual->dados.modelo);
            printf(" Marca: %s\n", atual->dados.marca);
            printf(" Ano: %d\n", atual->dados.ano);
            printf(" Estado: %s\n", atual->dados.estado);
            printf(" Km Rodados: %.2lf\n", atual->dados.km_rodados);
            printf(" Pintura: %s\n", atual->dados.pintura);
            printf(" Combust�vel: %s\n", atual->dados.combustivel);

            switch (atual->dados.status) {
                case VENDIDA:
                    printf(" Status: Vendida\n");
                    break;
                case ESGOTADA:
                    printf(" Status: Esgotada\n");
                    break;
                case EM_ESTOQUE:
                    printf(" Status: Em estoque\n");
                    break;
            }

            encontrada = 1;
            break;
        }
        atual = atual->proximo;
    }

    if (!encontrada) {
        printf("Moto com modelo '%s' n�o encontrada.\n", modeloBusca);
    }
    pause();
}
/*
 A fun��o salvarArquivo, salva o estoque atual de motos em um arquivo .txt
"estoque_motos.txt", para que os dados fiquem armazenados e possam ser utilizados depois.
*/
void salvarArquivo() {

    FILE *file = fopen("estoque_motos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }

    No* atual = inicio;
    while (atual != NULL) {
        fprintf(file, "%s\n%s\n%d\n%s\n%.2lf\n%s\n%s\n%d\n",
            atual->dados.modelo,
            atual->dados.marca,
            atual->dados.ano,
            atual->dados.estado,
            atual->dados.km_rodados,
            atual->dados.pintura,
            atual->dados.combustivel,
            atual->dados.status
        );
        atual = atual->proximo;
    }

    fclose(file);
    printf("Estoque salvo com sucesso!\n");
    system("cls");
}
/*
  A fun��o carregarArquivo, carrega os dados de motos salvos anteriormente
no arquivo "estoque_motos.txt" para a lista encadeada.
*/
void carregarArquivo() {
	system("cls");
    FILE *file = fopen("estoque_motos.txt", "r");
    if (file == NULL) {
 
        return;
    }

    char buffer[MAX_STRING];
    while (fgets(buffer, MAX_STRING, file) != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        if (!novo) {
            printf("Erro de mem�ria ao carregar arquivo.\n");
            fclose(file);
            return;
        }

       
        strtok(buffer, "\n");
        strcpy(novo->dados.modelo, buffer);

        fgets(novo->dados.marca, MAX_STRING, file);
        strtok(novo->dados.marca, "\n");

        fscanf(file, "%d\n", &novo->dados.ano);

        fgets(novo->dados.estado, MAX_STRING, file);
        strtok(novo->dados.estado, "\n");

        fscanf(file, "%lf\n", &novo->dados.km_rodados);

        fgets(novo->dados.pintura, MAX_STRING, file);
        strtok(novo->dados.pintura, "\n");

        fgets(novo->dados.combustivel, MAX_STRING, file);
        strtok(novo->dados.combustivel, "\n");

        int statusTemp;
        fscanf(file, "%d\n", &statusTemp);
        novo->dados.status = (StatusMoto)statusTemp;

        novo->proximo = NULL;

        if (inicio == NULL) {
            inicio = novo;
        } else {
            No* temp = inicio;
            while (temp->proximo != NULL) {
                temp = temp->proximo;
            }
            temp->proximo = novo;
        }
        total_motos++;
    }

    fclose(file);
    printf("Estoque carregado com sucesso! Total: %d motos\n", total_motos);
}


int main() {
    setlocale(LC_ALL, "");  
    carregarArquivo();

    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar moto\n");
        printf("2. Listar motos\n");
        printf("3. Buscar moto\n");
        printf("4. Editar moto\n");
        printf("5. Remover moto\n");
        printf("6. Salvar estoque em arquivo\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        system("cls");
        getchar();
        

        switch (opcao) {
            case 1: 
				cadastrarMoto();
			 break;
            case 2: 
				listarmotos();
			 break;
            case 3: 
				buscarMoto();
			 break;
            case 4: 
				editarMoto(); 
			break;
            case 5: 
				removerMoto();
			 break;
            case 6: 
				salvarArquivo();
			 break;
            case 0:
                salvarArquivo(); 
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
