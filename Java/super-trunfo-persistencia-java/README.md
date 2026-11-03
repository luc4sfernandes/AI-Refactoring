# Desafio Super Trunfo - Dominando a Persistência com Java

Bem-vindo ao desafio "Super Trunfo - Dominando a Persistência com Java"! No jogo Super Trunfo, os jogadores comparam os atributos das cartas para determinar a mais forte. O tema deste Super Trunfo é "Alunos", onde você comparará os atributos dos estudantes usando diferentes tecnologias de persistência em Java.

A empresa MateCheck contratou você para desenvolver um sistema completo de cartas, evoluindo desde implementações básicas com JDBC até sistemas avançados com JPA e mini-torneios.

O desafio está dividido em três níveis: Novato, Aventureiro e Mestre, com cada nível adicionando mais complexidade ao anterior e introduzindo novas tecnologias de persistência. Você deve escolher qual desafio quer realizar.

🚨 Atenção: O nível Novato do desafio é focado apenas no cadastro das cartas, utilizando JDBC puro para manipular os dados diretamente no banco.

## 🥉 Nível Novato: JDBC Puro

No nível Novato, você iniciará criando o sistema básico do jogo Super Trunfo utilizando JDBC puro para manipulação direta do banco de dados. As cartas serão representadas por alunos, cada um com atributos únicos. Imagine um sistema escolar onde cada aluno possui uma matrícula única (ex: A2020001, B2021002).

🚩 **Objetivo**: Criar um programa em Java que cadastra alunos/cartas com os seguintes atributos:

- Matrícula (String)
- Nome (String)  
- Ano de Entrada (int)

⚙️ **Funcionalidades do Sistema**:

- O sistema permitirá ao usuário cadastrar dados de alunos via terminal
- Implementará operações CRUD completas usando JDBC puro
- Após o cadastro, o sistema exibirá as cartas de forma organizada
- Sistema de batalha entre cartas baseado nos atributos
- Cálculo automático de raridade baseado na matrícula

📥 **Entrada e 📤 Saída de Dados**:

- O usuário insere os dados de cada carta interativamente via console
- O programa exibe as cartas cadastradas com formatação ASCII
- Conexão direta com banco Apache Derby

**Simplificações para o Nível Novato**:

- Cadastre pelo menos 5 alunos
- Concentre-se na persistência com JDBC puro
- Use PreparedStatement e ResultSet para manipulação de dados
- Implemente sistema básico de batalha entre cartas

## 🥈 Nível Aventureiro: DAO e JPA

No nível Aventureiro, você expandirá o sistema para incluir o padrão DAO e JPA básico, abstraindo a camada de persistência com mapeamento objeto-relacional.

🆕 **Diferença em relação ao Nível Novato**:

**Novos Recursos**:
- **Padrão DAO**: Abstração da camada de persistência
- **JPA com Anotações**: @Entity, @Id, @Column para mapeamento
- **GenericDAO**: Classe abstrata reutilizável com generics
- **Sistema de Pontuação**: 1 ponto por operação bem-sucedida

⚙️ **Funcionalidades do Sistema**:

- O sistema utilizará GenericDAO<E,K> para operações CRUD
- Menu interativo com 6 opções (inserir, remover, alterar, listar, obter, sair)
- Sistema de pontuação que finaliza automaticamente após 5 operações válidas
- Controle transacional automático com EntityManager

📥 **Entrada e 📤 Saída de Dados**:

- Mesma entrada do nível Novato via console
- A saída exibirá interface mais rica com emojis e feedback visual
- Persistência via JPA com arquivo persistence.xml

**Simplificações para o Nível Aventureiro**:

- Continue com os mesmos atributos básicos
- Implemente GenericDAO<Aluno, String> 
- Menu com exatamente 6 opções fixas
- Sistema de pontuação simples

## 🏆 Nível Mestre: JPA Avançado e Mini-Torneio

No nível Mestre, você implementará JPA avançado com recursos completos, organização em pacotes e funcionalidades de gamificação incluindo cartas lendárias e mini-torneio.

🆕 **Diferença em relação ao Nível Aventureiro**:

**Novos Recursos**:
- **Organização em Pacotes**: model, manager, app
- **Mini-Torneio**: Sistema de batalha avançado com sorteio de cartas  
- **Cartas Lendárias**: Cartas especiais com entrada em 2030 como recompensa
- **NamedQueries**: Consultas otimizadas e reutilizáveis

⚙️ **Funcionalidades do Sistema**:

- Sistema completo de mini-torneio onde o jogador escolhe carta e atributo
- Cartas lendárias geradas automaticamente como recompensa por vitórias
- Menu com 7 opções incluindo torneio e visualização de cartas lendárias
- Interface avançada com bordas especiais para cartas lendárias
- Estatísticas em tempo real do baralho

📥 **Entrada e 📤 Saída de Dados**:

- Sistema interativo com múltiplas escolhas para torneio
- A saída mostrará cartas formatadas com bordas especiais para lendárias
- Persistência com JPA completo e NamedQueries especializadas

**Observação**: Preste atenção à organização em pacotes (model, manager, app) e ao controle transacional avançado com EntityManager!

## 🚀 Como Executar

### Pré-requisitos
```bash
# JDK 17 ou superior
java -version

# Dependências necessárias:
# - Apache Derby (derby.jar)
# - EclipseLink (eclipselink.jar)  
# - Jakarta Persistence API (jakarta.persistence-api.jar)
```

### Nível Novato - JDBC Puro
```bash
cd modulo1-novato/desafio-codigo
javac -cp "derby.jar" *.java
java -cp ".:derby.jar" SuperTrunfoJDBC
```

### Nível Aventureiro - DAO e JPA
```bash
cd modulo2-aventureiro/desafio-codigo
javac -cp "derby.jar:eclipselink.jar:jakarta.persistence-api.jar" *.java
java -cp ".:derby.jar:eclipselink.jar:jakarta.persistence-api.jar" BaralhoDAO
```

### Nível Mestre - JPA Avançado
```bash
cd modulo3-mestre/desafio-codigo
javac -cp "derby.jar:eclipselink.jar:jakarta.persistence-api.jar" model/*.java manager/*.java app/*.java
java -cp ".:derby.jar:eclipselink.jar:jakarta.persistence-api.jar" app.SistemaEscola
```

## 🏁 Conclusão

Ao concluir qualquer um dos níveis, você terá dado um passo importante no desenvolvimento do Super Trunfo - Dominando a Persistência com Java. Boa sorte e divirta-se programando!

**Equipe de Ensino - MateCheck**


