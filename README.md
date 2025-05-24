# Kayn's Motorcycle - Administração de Estoque de Motos

## Como executar o projeto
Clone o repositório ou baixe o arquivo kayn's_motorcycle.c

Compile o código no terminal:

```terminal
gcc kayn's_motorcycle.c -o kayn's_motorcycle.exe
```

Execute o programa:
```terminal
kayn's_motorcycle.exe
```
## Funcionalidades

Listar Motos Cadastradas
O sistema busca no arquivo estoque_motos.txt todos os registros de motos armazenados. Utilizando uma lista encadeada, o programa percorre cada item e imprime os dados organizados.

Formato da listagem:

=== Motos Cadastradas ===

![Captura de tela 2025-05-23 220946](https://github.com/user-attachments/assets/c1ee4a1c-d996-4752-826f-3f561bf63a01)

### Cadastrar Nova Moto
Permite o cadastro de uma nova moto no sistema. O usuário informa os seguintes dados:

![image](https://github.com/user-attachments/assets/bf22c0d8-890a-4ca1-b425-254d60fbb1bf)

Após o preenchimento, os dados são armazenados em uma lista encadeada e gravados no arquivo estoque_motos.txt.

### Buscar Moto por Modelo

O sistema permite buscar uma moto pelo nome do modelo. A busca percorre a lista encadeada e retorna as informações correspondentes.

Exemplo:

Digite o modelo da moto a ser buscado: Fazer 250

![image](https://github.com/user-attachments/assets/eda55822-bc85-4856-ba9a-7eec1dd2ad30)


### Editar Informações da Moto
Permite atualizar os dados de uma moto cadastrada. O usuário localiza a moto pelo modelo e seleciona qual informação deseja editar.

![image](https://github.com/user-attachments/assets/32c2a588-e32f-4462-b77e-cf608d22e2c8)


### Remover Moto
A moto é removida da lista encadeada e seu registro é excluído do arquivo de dados. A busca para remoção também é feita pelo nome do modelo.

![image](https://github.com/user-attachments/assets/c396be3d-c61e-43a9-8a1e-55418743dd00)

e então atualiza a lista de motos:

![image](https://github.com/user-attachments/assets/2da49c1c-1a47-4dce-8278-4971b10a3390)

### Salvar e Carregar Dados
O sistema grava todas as motos em um arquivo de texto (estoque_moto.txt), permitindo a persistência das informações. Ao iniciar o programa, os dados são carregados automaticamente no sistema.

### Estrutura de Dados
Lista Encadeada Simples

Cada nó representa uma moto.

Estrutura dinâmica que facilita inserções, remoções e busca.

