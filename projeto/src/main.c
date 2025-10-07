#include <stdio.h>
#include <stdlib.h>

#define Max_alunos 100

/*Estrutura principal que armazena todos os dados de cada aluno*/
typedef struct 
{
    int matricula;
    char nome[25];
    int idade;
    int serie;
    char turma;
    char turno; 
    char responsavel[20];
    int telefone;
    int ativo;

} Aluno;

/*Array global que armazena todos os alunos do sistema*/
Aluno alunos[Max_alunos];
int total_alunos = 0;

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

/*Define turma automaticamente baseada no turno: Manhã = A, Tarde = B*/
char definir_Turma_Automaticamente(int serie, char turno){
    if(turno == 'M'){
        return 'A';
    }
    else{
        return 'B';
    }
}
/*Valida a idade para o ensino fundamental (6 a 14 anos)*/
int validar_idade(int idade){
    return (idade >= 6 && idade <= 14);
}
/*Verifica se há vagas dispiníveis no sistema*/
int tem_vagas(){
    return total_alunos < Max_alunos;
}
/*Adiciona o aluno ao sistema. Retorna: 1 = sucesso, 0 = erro e -1 = inválido*/
int adicionar_aluno(Aluno novo_aluno){
    if(!tem_vagas()){
        return 0;
    }
    
    if(!validar_idade(novo_aluno.idade)){
        return -1;
    }
    /*Definição do número da matrícula*/
    novo_aluno.matricula = 2025000 + total_alunos + 1;

    /*Definição da turma automaticamente*/
    novo_aluno.turma = definir_Turma_Automaticamente(novo_aluno.serie, novo_aluno.turno);

    /*Status inicial do aluno*/
    novo_aluno.ativo = 1;

    /*Busca aluno por matrícula - retorna índice se encontrou ou -1 se não encontrar*/
    alunos[total_alunos] = novo_aluno;
    total_alunos++;

    return 1;
}
/*Busca aluno por matrícula - retorna índice se encontrou ou -1 se não encontrar*/
int buscar_aluno_matriculado(int busca_matricula)
{
    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].matricula == busca_matricula){
            return i; /*Encontrou*/
        }
    }
    return -1; /*Não encontrou*/
}
/*Conta alunos ativos e transferidos*/
status_aluno contar_status()
{
    status_aluno status;
    status.matriculados = 0;
    status.transferidos = 0;

    /*Verifica o status de cada aluno (ativo = 1, transferido = 0)*/
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
/*Calcula a idade média dos alunos matriculados*/
float calcular_idade_media()
{
    /*Evita divisão por zero*/
    if(total_alunos == 0){
        return 0.0;
    }
    int soma_idades = 0;
    for(int i = 0; i < total_alunos; i++){
        soma_idades += alunos[i].idade;
    }
    /*Converte para float para obter média com decimais*/
    return (float)soma_idades / total_alunos;
}
/*Conta quantos alunos estão matriculados em uma série específica*/
int contar_alunos_por_serie(int serie)
{
    int cont = 0, indice_serie;
    /*Percorre todos os alunos verificando a série*/
    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].serie == serie){
            cont++;
        }
    }
    return cont;
}
/*Retorna a quantidade de alunos em cada turno (manhã e tarde)*/
contagem_turnos contar_alunos_por_turno()
{
    contagem_turnos contagem;
    contagem.manha = 0;
    contagem.tarde = 0;

    /*Separa e conta os alunos por turno*/
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
/*Conta quantos alunos pertencem a uma turma específica (A, B ou C)*/
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
/*Função de cadastro - coleta os dados do aluno e valida as entradas*/
void cadastro_alunos()
    {
        printf("\n========= Matrícula de aluno =========\n");

        /*Verifica se ainda há vagas*/
        if(!tem_vagas()){
            printf("Não há mais vagas! Máximo de %d alunos matriculados.\n", Max_alunos);
            return;
        }
        
        Aluno Novo_aluno;
        int Ano_nascimento;

        /*Noma do(a) estudante*/
        printf("\nNome completo do(a) Aluno(a): ");
        getchar(); /*limpa o buffer*/
        scanf("%24[^\n]", Novo_aluno.nome); /*lê até 24 caracters ou até \n.
        
        /*Cálculo da idade*/
        printf("\nAno de nascimento: ");
        scanf("%d", &Ano_nascimento);
        Novo_aluno.idade = 2025 - Ano_nascimento;

        /*Loop de validação - só aceita séries de 1 a 9*/
        do{
            printf("\nSérie (1ª, 2ª, 3ª, 4ª, 5ª, 6ª, 7ª, 8ª, ou 9ª): ");
            scanf("%d", &Novo_aluno.serie);
            while(getchar() != '\n');

            if(Novo_aluno.serie < 1 || Novo_aluno.serie > 9){
                printf("\nSérie inválida! Séries válidas: 1ª, 2ª, 3ª, 4ª, 5ª, 6ª, 7ª, 8ª ou 9ª");
            }

        }while(Novo_aluno.serie < 1 || Novo_aluno.serie > 9);

        /*Loop de validação - só aceita M ou T*/
        do{
            printf("\nTurno (M - Manhã ou T - Tarde): ");
            scanf(" %c", &Novo_aluno.turno);
            while (getchar() != '\n');

            if(Novo_aluno.turno != 'M' && Novo_aluno.turno != 'T'){
                printf("\nTurno inválido! Turnos válidos: M ou T");
            }
        }while(Novo_aluno.turno != 'M' && Novo_aluno.turno != 'T');

        /*Dados do responsável*/
        printf("\nTelefone de contato do responsável (últimos 4 dígitos): ");
        scanf("%d", &Novo_aluno.telefone);

        printf("\nNome do responsável: ");
        getchar();
        scanf("%19[^\n]", Novo_aluno.responsavel);

        /*Chama a função de adicionar aluno e verifica o resultado*/
        int resultado = adicionar_aluno(Novo_aluno);

        if(resultado == 1){
            Aluno aluno_adicionado = alunos[total_alunos - 1];
        /*Confirmação do cadastro com resumo dos dados*/
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
/*Função para exibir todos os alunos em formato de tabela com resumo estatístico*/
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

        /*Loop que exibe cada aluno formatado*/
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
        /*Exibe resumo com estatísticas gerais*/
        printf("------------------------------------------------------------------------------------\n");
        printf("RESUMO: Total=%d | Matriculados=%d | Transferidos=%d\n", 
           total_alunos, status.matriculados, status.transferidos);
        printf("Idade média: %.1f anos\n", calcular_idade_media());
    }
/*Função para buscar os alunos no sistema*/
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
    printf("3 - Por série e turmas\n");
    printf("4 - Por turno\n");
    printf("Opção: ");
    scanf("%d", &opcao_busca);

    if(opcao_busca == 1){
        int busca_matricula;
        printf("Digite o número da matrícula: ");
        scanf("%d", &busca_matricula);

        /*Busca o aluno e verifica se encontrou*/
        int indice = buscar_aluno_matriculado(busca_matricula);

        if(indice != -1){
            /*Exibe todos os dados do aluno encontrado*/
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
}
/*Essa função gera relatório completo com todas as estatísticas da escola*/
void calcular_estatisticas()
{
    printf("\n ======== Estatísticas da Escola ======== \n");

    if(total_alunos == 0){
        printf("Nenhum aluno matriculado ainda.\n");
        return;
    }
    /*Coleta todos os dados necessários*/
    status_aluno status = contar_status();
    contagem_turnos turnos = contar_alunos_por_turno();
    float idade_media = calcular_idade_media();

    printf("\n ======== DADOS GERAIS ======== \n");
    printf("Total de alunos: %d\n", total_alunos);
    printf("Alunos matriculados: %d\n", status.matriculados);
    printf("Idade média: %.1f anos\n", idade_media);

    /*Mostra distribuição por série (apenas séries que têm alunos)*/
    printf("\n ======== DISTRIBUIÇÃO POR SÉRIE ======== \n");
    for(int serie = 1; serie <= 9; serie++){
        int contar = contar_alunos_por_serie(serie);
        if(contar > 0){
            printf("%dª série: %d alunos (%.1f%%)\n", serie, contar, (float)contar * 100 / total_alunos);
        }
    }
    /*Mostra distribuição por turno com porcentagens*/
    printf("\n ======== DISTRIBUIÇÃO POR TURNO ======== \n");
    printf("Manhã: %d alunos (%.1f%%)\n", turnos.manha, (float)turnos.manha * 100 / total_alunos);
    printf("Tarde: %d alunos (%.1f%%)\n", turnos.tarde, (float)turnos.tarde * 100 / total_alunos);

    printf("\n ======== DISTRIBUIÇÃO POR TURMA ======== \n");
    int turmaA = contar_alunos_por_turma('A');
    int turmaB = contar_alunos_por_turma('B');
    int turmaC = contar_alunos_por_turma('C');

    if(turmaA > 0){
        printf("Turma A: %d alunos\n", turmaA);
    }
    if(turmaB > 0){
        printf("Turma B: %d alunos\n", turmaB);
    }
    if(turmaC > 0){
        printf("Turma C: %d alunos\n", turmaC);
    }
}

int main()
{
    int opcao;

    printf("========================================\n");
    printf("SISTEMA DE CADASTRO ESCOLAR\n");
    printf("Escola Estadual Prof. Fernando Marques\n");
    printf("========================================\n\n");

    /*Loop principal do sistema*/
    do{
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1 - Matricular Novo Aluno\n");
        printf("2 - Listar Alunos Matriculados\n");
        printf("3 - Buscar Alunos\n");
        printf("4 - Estatísticas da Escola\n");
        printf("0 - Sair do Sistema\n");
        printf("==================================\n");

        /*O usuário escolhe a opção que desejar*/
        printf("Digite a sua opção: \n");
        scanf("%d", &opcao);

        /*Direciona para a função correspondente*/
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
        case 0:
            printf("Obrigado por usar nosso sistema!\n");
            break;
        default:
            printf("\nErro! Opção inválida. Digite 1, 2, 3, 4 ou 0\n");
        }
        /*Pausa para o usuário visualizar os resultados*/
        if(opcao != 0){
            printf("Pressione a tecla Enter para continuar...\n");
            getchar();
            getchar();
        }
    }while(opcao != 0);
   
    return 0;
}