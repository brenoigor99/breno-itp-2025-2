# Sistema de Cadastro Escolar

## Descrição

Este é um sistema completo de cadastro e gerenciamento de alunos do ensino fundamental, desenvolvido para facilitar o controle de matrículas, turnos, turmas e estatísticas escolares. O sistema oferece uma interface simples via terminal e armazena informações de até 100 alunos.

## Funcionalidades

### 1. Matrícula de Novo Aluno
- Cadastro completo com validação de dados
- Geração automática de número de matrícula (formato: 2025XXX)
- Definição automática de turma baseada no turno:
  - Manhã → Turma A
  - Tarde → Turma B
- Validação de idade (6 a 14 anos)
- Validação de série (1ª a 9ª)
- Registro de responsável e telefone de contato

### 2. Listar Alunos Matriculados
- Visualização em formato de tabela
- Exibição de todos os dados dos alunos
- Resumo com estatísticas:
  - Total de alunos
  - Alunos matriculados vs transferidos
  - Idade média

### 3. Buscar Alunos
- **Busca por número de matrícula**: localiza aluno específico pelo número da matrícula
- **Busca por nome**: encontra aluno pelo nome completo
- **Busca por série e turma**: lista todos os alunos de uma turma específica (ex: 5ªA, 7ªB)
- **Busca por turno**: exibe alunos do turno da manhã ou tarde, organizados por série
- Exibição detalhada dos dados do aluno encontrado

### 4. Estatísticas da Escola
Relatório completo com:
- **Dados Gerais**: total de alunos, matriculados e idade média
- **Distribuição por Série**: quantidade e percentual de alunos em cada série
- **Distribuição por Turno**: alunos da manhã e tarde com percentuais
- **Distribuição por Turma**: quantidade de alunos nas turmas A ou B
- **Matriz de Distribuição**: visualização em formato de tabela cruzada mostrando a quantidade de alunos por série e turma

### 5. Ver Matriz de Distribuição
- Matriz visual organizada por série (linhas) e turma (colunas)
- Mostra a distribuição completa de alunos ativos
- Totalização por série, turma e geral
- Atualização automática sempre que um aluno é matriculado

## Estrutura do Código
```text
├── Estruturas de Dados
│   ├── Aluno (struct principal)
│   ├── status_aluno (estatísticas de status)
│   ├── contagem_turnos (estatísticas de turnos)
│   └── distribuicao_turmas (matriz de distribuição)
│
├── Funções de Validação
│   ├── validar_idade()
│   ├── tem_vagas()
│   └── definir_Turma_Automaticamente()
│
├── Funções de Cadastro e Busca
│   ├── adicionar_aluno()
│   ├── buscar_aluno_matriculado()
│   ├── buscar_por_nome()
│   ├── buscar_por_serie_turma()
│   ├── buscar_por_turno()
│   └── cadastro_alunos()
│
├── Funções de Estatísticas
│   ├── contar_status()
│   ├── calcular_idade_media()
│   ├── contar_alunos_por_serie()
│   ├── contar_alunos_por_turno()
│   └── contar_alunos_por_turma()
│
├── Funções de Matriz
│   ├── inicializar_matriz()
│   ├── atualizar_matriz()
│   └── exibir_matriz_distribuicao()
│
└── Funções de Exibição
    ├── listar_alunos()
    ├── buscar_alunos()
    └── calcular_estatisticas()
```

## Como compilar

### Linux/macOS:
```bash
gcc sistema_escolar.c -o sistema_escolar
./sistema_escolar
```
### windows:
```bash
gcc sistema_escolar.c -o sistema_escolar.exe
sistema_escolar.exe
```
## Como Usar

### Execute o programa e escolha uma opção do menu:
```text
1 - Matricular novo aluno
2 - Listar todos os alunos
3 - Buscar aluno
4 - Ver estatísticas
5 - Ver matriz de distribuição
0 - Sair
```
## Tecnologias
```text
Linguagem: C
Compilador: GCC
Editor de código: Visual Studio Code
```