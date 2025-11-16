#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_alunos 100
#define Tam_nome 50
#define Tam_responsavel 50
#define MAX_SERIES 9
#define MAX_TURMAS 2

// Estrutura principal que armazena todos os dados de cada aluno
typedef struct 
{
    int matricula;
    char nome[Tam_nome];
    int idade;
    int serie;
    char turma;
    char turno; 
    char responsavel[Tam_responsavel];
    int telefone;
    int ativo;

} Aluno;

// Array global que armazena todos os alunos do sistema
Aluno alunos[Max_alunos];
int total_alunos = 0;

// MATRIZ DE DISTRIBUIÇÃO - Organiza alunos por série e turma
// Linhas = séries (1ª a 9ª) | Colunas = turmas (A=0, B=1)
int distribuicao_turmas[MAX_SERIES][MAX_TURMAS];

typedef struct 
{
    int matriculados;
    int transferidos;
}status_aluno;

typedef struct
{
    int manha;
    int tarde;
}contagem_turnos;

// Busca aluno pelo nome completo usando strcmp
// Recebe ponteiro para array de alunos e total cadastrado
void buscar_por_nome(Aluno *lista, int total)
{
    char nome[Tam_nome];
    int encontrou = 0;
    
    printf("Digite o nome completo do aluno: ");
    getchar();
    scanf("%49[^\n]", nome);
    
    printf("\n");
    
    // Percorre array comparando nomes
    for(int i = 0; i < total; i++){
        // strcmp retorna 0 quando strings são iguais
        if(strcmp(lista[i].nome, nome) == 0){
            printf("Aluno encontrado:\n");
            printf("Nome: %s\n", lista[i].nome);
            printf("Matrícula: %d\n", lista[i].matricula);
            printf("Idade: %d anos\n", lista[i].idade);
            printf("Turma: %d%c - Turno: %c\n", lista[i].serie, lista[i].turma, lista[i].turno);
            printf("Responsável: %s (Tel: %04d)\n", lista[i].responsavel, lista[i].telefone);
            printf("\n");
            encontrou = 1;
            break;
        }
    }
    
    if(!encontrou){
        printf("Aluno não encontrado. Verifique se digitou o nome completo.\n");
    }
}

// Busca e lista alunos de uma série e turma específica
// Útil para visualizar todos os alunos de uma sala
void buscar_por_serie_turma(Aluno *lista, int total)
{
    int serie;
    char turma;
    int contador = 0;
    
    printf("Digite a série (1 a 9): ");
    scanf("%d", &serie);
    
    printf("Digite a turma (A ou B): ");
    scanf(" %c", &turma);
    
    printf("\n========= Alunos da %dª série - Turma %c =========\n", serie, turma);
    
    for(int i = 0; i < total; i++){
        if(lista[i].serie == serie && lista[i].turma == turma){
            printf("%d. %s (Matrícula: %d)\n", contador + 1, lista[i].nome, lista[i].matricula);
            contador++;
        }
    }
    
    if(contador == 0){
        printf("Nenhum aluno encontrado nessa turma.\n");
    }
    else{
        printf("\nTotal de alunos: %d\n", contador);
    }
}

// Lista alunos por turno, organizando por série
// Facilita visualização da distribuição dos turnos
void buscar_por_turno(Aluno *lista, int total)
{
    char turno;
    int contador = 0;
    
    printf("Digite o turno (M para Manhã / T para Tarde): ");
    scanf(" %c", &turno);
    
    printf("\n========= Alunos do turno da %s =========\n", 
           turno == 'M' ? "Manhã" : "Tarde");
    
    // Organiza listagem por série (1 a 9)
    for(int serie = 1; serie <= 9; serie++){
        int tem_aluno_serie = 0;
        
        for(int i = 0; i < total; i++){
            if(lista[i].turno == turno && lista[i].serie == serie){
                if(!tem_aluno_serie){
                    printf("\n%dª Série:\n", serie);
                    tem_aluno_serie = 1;
                }
                printf("  - %s (Turma %c)\n", lista[i].nome, lista[i].turma);
                contador++;
            }
        }
    }
    
    if(contador == 0){
        printf("Nenhum aluno encontrado nesse turno.\n");
    }
    else{
        printf("\nTotal de alunos no turno: %d\n", contador);
    }
}

// Inicializa a matriz com zeros
void inicializar_matriz()
{
    for(int i = 0; i < MAX_SERIES; i++){
        for(int j = 0; j < MAX_TURMAS; j++){
            distribuicao_turmas[i][j] = 0;
        }
    }
}

// Atualiza a matriz sempre que um aluno é adicionado
void atualizar_matriz()
{
    // Zera a matriz
    inicializar_matriz();
    
    // Reconta todos os alunos ativos
    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].ativo == 1){
            int serie_index = alunos[i].serie - 1; // Converte série 1-9 para índice 0-8
            int turma_index = (alunos[i].turma == 'A') ? 0 : 1; // A=0, B=1
            
            distribuicao_turmas[serie_index][turma_index]++;
        }
    }
}

// Exibe a matriz de distribuição em formato de tabela
void exibir_matriz_distribuicao()
{
    printf("\n ======== MATRIZ DE DISTRIBUIÇÃO (Série x Turma) ======== \n\n");
    
    if(total_alunos == 0){
        printf("Nenhum aluno matriculado ainda.\n");
        return;
    }
    
    // Atualiza a matriz antes de exibir
    atualizar_matriz();
    
    // Cabeçalho da tabela
    printf("Série | Turma A | Turma B | Total\n");
    printf("------|---------|---------|-------\n");
    
    int total_geral = 0;
    
    // Percorre cada série
    for(int i = 0; i < MAX_SERIES; i++){
        int turma_a = distribuicao_turmas[i][0];
        int turma_b = distribuicao_turmas[i][1];
        int total_serie = turma_a + turma_b;
        
        // Só exibe séries que têm alunos
        if(total_serie > 0){
            printf("  %dª  |   %2d    |   %2d    |  %2d\n", 
                   i + 1, turma_a, turma_b, total_serie);
            total_geral += total_serie;
        }
    }
    
    printf("------|---------|---------|-------\n");
    printf("TOTAL |   %2d    |   %2d    |  %2d\n", 
           distribuicao_turmas[0][0] + distribuicao_turmas[1][0] + distribuicao_turmas[2][0] + 
           distribuicao_turmas[3][0] + distribuicao_turmas[4][0] + distribuicao_turmas[5][0] + 
           distribuicao_turmas[6][0] + distribuicao_turmas[7][0] + distribuicao_turmas[8][0],
           
           distribuicao_turmas[0][1] + distribuicao_turmas[1][1] + distribuicao_turmas[2][1] + 
           distribuicao_turmas[3][1] + distribuicao_turmas[4][1] + distribuicao_turmas[5][1] + 
           distribuicao_turmas[6][1] + distribuicao_turmas[7][1] + distribuicao_turmas[8][1],
           
           total_geral);
}

// Define turma automaticamente baseada no turno: Manhã = A, Tarde = B
char definir_Turma_Automaticamente(int serie, char turno){
    if(turno == 'M'){
        return 'A';
    }
    else{
        return 'B';
    }
}
// Valida a idade para o ensino fundamental (6 a 14 anos)
int validar_idade(int idade){
    return (idade >= 6 && idade <= 14);
}
// Verifica se há vagas dispiníveis no sistema
int tem_vagas(){
    return total_alunos < Max_alunos;
}
// Adiciona o aluno ao sistema. Retorna: 1 = sucesso, 0 = erro e -1 = inválido
int adicionar_aluno(Aluno novo_aluno){
    if(!tem_vagas()){
        return 0;
    }
    
    if(!validar_idade(novo_aluno.idade)){
        return -1;
    }
    // Definição do número da matrícula
    novo_aluno.matricula = 2025000 + total_alunos + 1;

    // Definição da turma automaticamente
    novo_aluno.turma = definir_Turma_Automaticamente(novo_aluno.serie, novo_aluno.turno);

    // Status inicial do aluno
    novo_aluno.ativo = 1;

    // Busca aluno por matrícula - retorna índice se encontrou ou -1 se não encontrar
    alunos[total_alunos] = novo_aluno;
    total_alunos++;
    
    // Atualiza a matriz após adicionar
    atualizar_matriz();

    return 1;
}

// Busca aluno por matrícula - retorna índice se encontrou ou -1 se não encontrar
int buscar_aluno_matriculado(int busca_matricula)
{
    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].matricula == busca_matricula){
            return i; // Encontrou
        }
    }
    return -1; // Não encontrou
}

// Conta alunos ativos e transferidos
status_aluno contar_status()
{
    status_aluno status;
    status.matriculados = 0;
    status.transferidos = 0;

    // Verifica o status de cada aluno (ativo = 1, transferido = 0)
    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].ativo == 1){
            status.matriculados++;
        }
        else{
            status.transferidos++;
        }
    }
    return status;
}

// Calcula a idade média dos alunos matriculados
float calcular_idade_media()
{
    // Evita divisão por zero
    if(total_alunos == 0){
        return 0.0;
    }
    int soma_idades = 0;
    for(int i = 0; i < total_alunos; i++){
        soma_idades += alunos[i].idade;
    }
    // Converte para float para obter média com decimais
    return (float)soma_idades / total_alunos;
}

// Conta quantos alunos estão matriculados em uma série específica
int contar_alunos_por_serie(int serie)
{
    int cont = 0, indice_serie;
    // Percorre todos os alunos verificando a série
    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].serie == serie){
            cont++;
        }
    }
    return cont;
}

// Retorna a quantidade de alunos em cada turno (manhã e tarde)
contagem_turnos contar_alunos_por_turno()
{
    contagem_turnos contagem;
    contagem.manha = 0;
    contagem.tarde = 0;

    // Separa e conta os alunos por turno
    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].turno == 'M'){
            contagem.manha++;
        }
        else{
            contagem.tarde++;
        }
    }
    return contagem;
}

// Conta quantos alunos pertencem a uma turma específica (A ou B)
int contar_alunos_por_turma(char turma)
{
    int cont = 0;
    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].turma == turma){
            cont++;
        }
    }
    return cont;
}

// Função de cadastro - coleta os dados do aluno e valida as entradas
void cadastro_alunos()
    {
        printf("\n========= Matrícula de aluno =========\n");

        // Verifica se ainda há vagas
        if(!tem_vagas()){
            printf("Não há mais vagas! Máximo de %d alunos matriculados.\n", Max_alunos);
            return;
        }
        
        Aluno Novo_aluno;
        int Ano_nascimento;

        // Nome do(a) estudante
        printf("\nNome completo do(a) aluno(a): ");
        getchar(); // Limpa o buffer
        scanf("%49[^\n]", Novo_aluno.nome); // Lê até 49 caracters ou até \n.
        
        // Cálculo da idade
        printf("\nAno de nascimento: ");
        scanf("%d", &Ano_nascimento);
        Novo_aluno.idade = 2025 - Ano_nascimento;

        // Loop de validação - só aceita séries de 1 a 9
        do{
            printf("\nSérie (1ª, 2ª, 3ª, 4ª, 5ª, 6ª, 7ª, 8ª, ou 9ª): ");
            scanf("%d", &Novo_aluno.serie);
            while(getchar() != '\n');

            if(Novo_aluno.serie < 1 || Novo_aluno.serie > 9){
                printf("\nSérie inválida! Séries válidas: 1ª, 2ª, 3ª, 4ª, 5ª, 6ª, 7ª, 8ª ou 9ª");
            }

        }while(Novo_aluno.serie < 1 || Novo_aluno.serie > 9);

        // Loop de validação - só aceita M ou T
        do{
            printf("\nTurno (M - Manhã ou T - Tarde): ");
            scanf(" %c", &Novo_aluno.turno);
            while (getchar() != '\n');

            if(Novo_aluno.turno != 'M' && Novo_aluno.turno != 'T'){
                printf("\nTurno inválido! Turnos válidos: M ou T");
            }
        }while(Novo_aluno.turno != 'M' && Novo_aluno.turno != 'T');

        // Dados do responsável
        printf("\nTelefone de contato do responsável (últimos 4 dígitos): ");
        scanf("%d", &Novo_aluno.telefone);

        printf("\nNome do responsável: ");
        getchar();
        scanf("%49[^\n]", Novo_aluno.responsavel);

        // Chama a função de adicionar aluno e verifica o resultado
        int resultado = adicionar_aluno(Novo_aluno);

        if(resultado == 1){
            Aluno aluno_adicionado = alunos[total_alunos - 1];
        // Confirmação do cadastro com resumo dos dados
        printf("\n ======== MATRÍCULA REALIZADA COM SUCESSO! ======== \n");
        printf("Aluno: %s\n", aluno_adicionado.nome);
        printf("Matrícula: %d\n", aluno_adicionado.matricula);
        printf("Idade: %d anos\n", aluno_adicionado.idade);
        printf("Turma: %d%c (%s)\n", aluno_adicionado.serie, aluno_adicionado.turma, aluno_adicionado.turno == 'M' ? "Manhã" : "Tarde");
        printf("Responsável: %s\n", aluno_adicionado.responsavel);
        }
        else if(resultado == 0){
            printf("Escola lotada! Não há mais vagas.\n");
        }
        else if(resultado == -1){
            printf("Idade inválida para o ensino fundamental nessa escola!\n");
            printf("A escola só aceita alunos de 6 a 14 anos.\n");
        }
    }

// Função para exibir todos os alunos em formato de tabela com resumo estatístico
void listar_alunos()
    {
        printf("\n ======== Lista de alunos matriculados ======== \n");

        if(total_alunos == 0){
            printf("Nenhum aluno matriculado ainda.\n");
            return;
        }

        printf("Mat.     Nome                    Idade  Turma  Turno  Telefone  Responsável  Status");
        printf("\n------------------------------------------------------------------------------------\n");

        status_aluno status = contar_status();

        // Loop que exibe cada aluno formatado
        for(int i = 0; i < total_alunos; i++){
            printf("%-7d %-15s %-5d  %d%c   %c   %04d  %-15s %s\n",
               alunos[i].matricula,
               alunos[i].nome,
               alunos[i].idade,
               alunos[i].serie,
               alunos[i].turma,
               alunos[i].turno,
               alunos[i].telefone,
               alunos[i].responsavel,
               alunos[i].ativo ? "Ativo" : "Transferido");
        }
        // Exibe resumo com estatísticas gerais
        printf("------------------------------------------------------------------------------------\n");
        printf("RESUMO: Total=%d | Matriculados=%d | Transferidos=%d\n", 
           total_alunos, status.matriculados, status.transferidos);
        printf("Idade média: %.1f anos\n", calcular_idade_media());
    }

// Função para buscar os alunos no sistema
void buscar_alunos()
{
    printf("\n ======== Buscar Alunos ======== \n");

    if(total_alunos == 0){
        printf("\nNenhum aluno cadastrado para buscar.\n");
        return;
    }

    int opcao_busca;
    printf("Como deseja buscar?\n");
    printf("1 - Por número da matrícula\n");
    printf("2 - Por nome\n");
    printf("3 - Por série e turma\n");
    printf("4 - Por turno\n");
    printf("Opção: ");
    scanf("%d", &opcao_busca);

    if(opcao_busca == 1){
        int busca_matricula;
        printf("Digite o número da matrícula: ");
        scanf("%d", &busca_matricula);

        // Busca o aluno e verifica se encontrou
        int indice = buscar_aluno_matriculado(busca_matricula);

        if(indice != -1){
            // Exibe todos os dados do aluno encontrado
            printf("\n ======== Aluno Encontrado ======== \n");
            printf("Nome: %s\n", alunos[indice].nome);
            printf("Matrícula: %d\n", alunos[indice].matricula);
            printf("Idade: %d anos\n", alunos[indice].idade);
            printf("Turma: %d%c\n", alunos[indice].serie, alunos[indice].turma);
            printf("Turno: %s\n", alunos[indice].turno == 'M' ? "Manhã" : "Tarde");
            printf("Responsável: %s\n", alunos[indice].responsavel);
        }
        else{
            printf("Aluno não encontrado.\n");
        }
    }
    // Chama as novas funções de busca passando o array como ponteiro
    else if(opcao_busca == 2){
        buscar_por_nome(alunos, total_alunos);
    }
    else if(opcao_busca == 3){
        buscar_por_serie_turma(alunos, total_alunos);
    }
    else if(opcao_busca == 4){
        buscar_por_turno(alunos, total_alunos);
    }
    else{
        printf("Opção inválida!\n");
    }
}

// Essa função gera relatório completo com todas as estatísticas da escola
void calcular_estatisticas()
{
    printf("\n ======== Estatísticas da Escola ======== \n");

    if(total_alunos == 0){
        printf("Nenhum aluno matriculado ainda.\n");
        return;
    }
    // Coleta todos os dados necessários
    status_aluno status = contar_status();
    contagem_turnos turnos = contar_alunos_por_turno();
    float idade_media = calcular_idade_media();

    printf("\n ======== DADOS GERAIS ======== \n");
    printf("Total de alunos: %d\n", total_alunos);
    printf("Alunos matriculados: %d\n", status.matriculados);
    printf("Idade média: %.1f anos\n", idade_media);

    // Mostra a distribuição por série (apenas séries que têm alunos)
    printf("\n ======== DISTRIBUIÇÃO POR SÉRIE ======== \n");
    for(int serie = 1; serie <= 9; serie++){
        int contar = contar_alunos_por_serie(serie);
        if(contar > 0){
            printf("%dª série: %d alunos (%.1f%%)\n", serie, contar, (float)contar * 100 / total_alunos);
        }
    }
    // Mostra distribuição por turno com porcentagens
    printf("\n ======== DISTRIBUIÇÃO POR TURNO ======== \n");
    printf("Manhã: %d alunos (%.1f%%)\n", turnos.manha, (float)turnos.manha * 100 / total_alunos);
    printf("Tarde: %d alunos (%.1f%%)\n", turnos.tarde, (float)turnos.tarde * 100 / total_alunos);

    printf("\n ======== DISTRIBUIÇÃO POR TURMA ======== \n");
    int turmaA = contar_alunos_por_turma('A');
    int turmaB = contar_alunos_por_turma('B');

    if(turmaA > 0){
        printf("Turma A: %d alunos\n", turmaA);
    }
    if(turmaB > 0){
        printf("Turma B: %d alunos\n", turmaB);
    }
    
    // EXIBE A MATRIZ DE DISTRIBUIÇÃO
    exibir_matriz_distribuicao();
}

int main()
{
    int opcao;
    
    // Inicializa a matriz no início do programa
    inicializar_matriz();

    printf("========================================\n");
    printf("SISTEMA DE CADASTRO ESCOLAR\n");
    printf("Escola Estadual Prof. Fernando Marques\n");
    printf("========================================\n\n");

    // Loop principal do sistema
    do{
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1 - Matricular Novo Aluno\n");
        printf("2 - Listar Alunos Matriculados\n");
        printf("3 - Buscar Alunos\n");
        printf("4 - Estatísticas da Escola\n");
        printf("5 - Ver Matriz de Distribuição\n");
        printf("0 - Sair do Sistema\n");
        printf("==================================\n");

        // O usuário escolhe a opção que desejar
        printf("Digite a sua opção: \n");
        scanf("%d", &opcao);

        // Direciona para a função correspondente
        switch (opcao)
        {
        case 1:
            cadastro_alunos();
            break;
        case 2:
            listar_alunos();
            break;
        case 3:
            buscar_alunos();
            break;
        case 4:
            calcular_estatisticas();
            break;
        case 5:
            exibir_matriz_distribuicao();
            break;
        case 0:
            printf("Obrigado por usar nosso sistema!\n");
            break;
        default:
            printf("\nErro! Opção inválida. Digite 1, 2, 3, 4, 5 ou 0\n");
        }
        // Pausa para o usuário visualizar os resultados
        if(opcao != 0){
            printf("Pressione a tecla Enter para continuar...\n");
            getchar();
            getchar();
        }
    }while(opcao != 0);
   
    return 0;
}