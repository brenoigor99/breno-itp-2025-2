# Introdução a Técnicas de Programação - Unidade 1 e 2
**Aluno**: Breno Igor da Silva  
**Matrícula**: 20250065477  
**Período**: 2025.2  
## 📁 Estrutura do Projeto
- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo
## 🚀 Projeto: Sistema de Cadastro Escolar
**Descrição**: Este é um sistema completo de cadastro e gerenciamento de alunos do ensino fundamental.  
**Repositório**: https://github.com/brenoigor99/breno-itp-2025-2.git   
**Vídeo de Demonstração**: [link para o vídeo da U1](https://youtu.be/rFKDheTI-2Q)  
**Vídeo de Demonstração**: [link para o vídeo da U2](https://youtu.be/RKiCUzParpc)  
### Funcionalidades Implementadas:
- O sistema permite matricular alunos, listar cadastros, realizar buscas, ver matriz de distribuição e gerar relatórios estatísticos.
### Conceitos da U1 Aplicados:
- Estruturas condicionais: As estruturas condicionais foram usadas por exemplo para verificação vagas disponíveis,
validação da idade, validação de turno, validação de série.
- Estruturas de repetição: Foi utilizado no loop do menu principal, loops de validação de entrada de dados,
iterações para o cálculo das estatísticas.
- Vetores: Foi utilizado um array global para armazenar todos os cadastros, também em manipulação de strings
com arrays de char para nomes e responsáveis.
- Funções: Ao todo foram criadas 14 funções organizadas em categorias: validação de entrada (3),
gerenciamento de dados (3), cálculos estatísticos (5) e interface do usuário (3).
### Conceitos da U2 Aplicados:
- Strings: Foi utilizada a função strcmp da biblioteca string.h para comparar nomes completos na busca de alunos. Arrays 
de char continuam sendo usados para armazenar nomes e dados dos responsáveis, com manipulação através das funções padrão
da biblioteca.
- Estruturas de repetição aninhadas: Foram aplicadas principalmente na função de exibição da matriz de distribuição, onde 
o loop externo percorre as séries (linhas) e o interno percorre as turmas (colunas). Também utilizadas na busca por 
turno, onde organizo a listagem iterando primeiro pelas séries e depois pelos alunos de cada série.
- Matrizes: Implementei a matriz distribuicao_turmas[MAX_SERIES][MAX_TURMAS] que armazena a quantidade de alunos por 
série e turma. As linhas representam as séries (índices 0-8 para 1ª a 9ª série) e as colunas representam as turmas 
(índice 0 para turma A e 1 para turma B). A matriz é atualizada automaticamente sempre que um aluno é matriculado.
- Ponteiros: Foram utilizados nas três novas funções de busca (buscar_por_nome, buscar_por_serie_turma e 
buscar_por_turno). O parâmetro Aluno *lista permite passar o array de alunos por referência, evitando cópias 
desnecessárias e melhorando a eficiência. Uso aritmética de ponteiros para percorrer o array e acessar os dados dos 
alunos.
## 📚 Listas de Exercícios
### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas
### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos
### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ✅ Problema 2: Homem Aranha
- ✅ Problema 3: Números colegas
- ✅ Problema 4: Jogo de dardos
### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código
- ✅ Questões 5-11: Implementações
### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos
- ✅ Problema 3: Pousando a sonda espacial
### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ✅ Problema 4: Em busca do tesouro perdido
### Semana 7 - Strings:
- ✅ Problema 1: Campo minado 1D
- ✅ Problema 2: Detecção de placas
- ✅ Problema 3: OpenMeet
### Semana 8 - Repetições-aninhadas:
- ✅ Problema 1: Estou com sorte (ou não)
- ✅ Problema 2: Os dias mais chuvosos
- ✅ Problema 3: Esse sim é piloto
### Semana 9 - Matrizes:
- ✅ Problema 1: Campo Agrícola
- ✅ Problema 2: Sugestão de amigos
- ✅ Problema 3: Campeonato de empates
- ✅ Problema 4: Uma pechincha!
### Semana 10 Ponteiros-alocação:
- ✅ Problema 1: Soma de Vetores
- ✅ Problema 2: Ocorrências no vetor
- ✅ Problema 3: Sopa de letrinhas
## 🎯 Principais Aprendizados da U1
Durante a Unidade 1, aprendi a utilizar melhor o uso de funções, o que tornou o projeto muito mais organizado e fácil de manter. Com isso, passei a pensar no código de forma mais estruturada, dividindo problemas complexos em funções menores e reutilizáveis. Também desenvolvi habilidade com arrays e compreendi melhor como estruturas condicionais e de repetição trabalham juntas para criar validações eficientes e um melhor controle sobre o que acontece no programa.
## 🎯 Principais Aprendizados da U2
Ponteiros foi para mim o conceito mais novo e desafiador da U2, mas aplicar ele nas funções de busca mostrou na prática a vantagem de passar referências ao invés de cópias e também o tornou mais esclarecedor.
Eu já tinha trabalhado com matrizes antes, mas nunca em um projeto de fato, apenas em exercícios, então foi bem interessante usá-lo para gerenciar a distribuição de alunos por série e turma, o que tornou o uso dos loops aninhados da matriz mais intuitivo do que apenas quando fazia exercícios isolados.
String eu também já conhecia, mas usar funções da string.h no projeto mostrou como aproveitar melhor a biblioteca padrão ao invés de reimplementar tudo do zero.
## 🔧 Ambiente de Desenvolvimento
- **SO**: Linux
- **Compilador**: GCC versão 13.3.0
- **Editor**: Visual Studio Code