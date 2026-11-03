# Desafio - Os Guardiões de Eldoria: A Saga Continua

Bem-vindo ao desafio "Os Guardiões de Eldoria"! Neste sistema, você criará e gerenciará personagens do reino encantado, aplicando conceitos avançados da Programação Orientada a Objetos em Java. Cada personagem possui atributos únicos e habilidades especiais que os distinguem em batalhas épicas.

A empresa TechNova contratou você para desenvolver um sistema completo de gerenciamento de heróis, que demonstra herança, encapsulamento, polimorfismo e sobrescrita de métodos.

O desafio está dividido em três níveis: Novato, Aventureiro e Mestre, com cada nível adicionando mais complexidade ao anterior. Você deve escolher qual desafio quer realizar.

🚨 **Atenção**: O nível Novato do desafio é focado na criação básica de classes com herança e encapsulamento, utilizando construtores para inicializar os dados e métodos para exibi-los.

## 🎮 Nível Novato: Hierarquia Básica de Classes

No nível Novato, você iniciará criando o sistema básico de personagens de Eldoria com herança e encapsulamento. Os personagens serão organizados em uma hierarquia onde a classe Personagem serve como base para especializações como Mago e Guerreiro.

🚩 **Objetivo**: Criar um programa em Java que implementa uma hierarquia de classes com os seguintes atributos:

- Nome (String)
- Classe (String) 
- Nível (int)
- Pontos de Vida (int)
- Poder Base (double)

### ⚙️ Funcionalidades do Sistema:

- Classe Personagem como superclasse com atributos encapsulados (private)
- Subclasses Mago e Guerreiro que herdam de Personagem
- Construtores que inicializam todos os atributos
- Getters e setters para acesso controlado aos atributos
- Método usarHabilidade() implementado em cada subclasse

### 📥 Entrada e 📤 Saída de Dados:

- Os personagens são criados programaticamente no método main
- O programa exibe os dados cadastrados usando toString(), com cada atributo em uma nova linha

**Simplificações para o Nível Novato:**
- Cadastre apenas dois personagens (um Mago e um Guerreiro)
- Concentre-se na herança, encapsulamento e criação básica das classes
- Não implemente comparações ou validações complexas

## 🛡️ Nível Aventureiro: Sobrescrita de Métodos e Validações

No nível Aventureiro, você expandirá o sistema para incluir sobrescrita dos métodos da classe Object e validações nos setters.

### 🆕 Diferença em relação ao Nível Novato:

**Sobrescrita de Métodos:**
- toString(): Formatação personalizada dos dados do personagem
- equals(): Comparação baseada em nome e classe
- hashCode(): Consistente com equals() usando Objects.hash()

**Validações:**
- Nível e pontos de vida não podem ser negativos
- Setters com validação automática

### ⚙️ Funcionalidades do Sistema:

- O sistema validará automaticamente os dados inseridos nos setters
- Os métodos sobrescritos permitirão comparação e exibição adequadas
- Tratamento de exceções para valores inválidos

### 📥 Entrada e 📤 Saída de Dados:

- Mesma entrada do nível Novato
- A saída utilizará os métodos sobrescritos para formatação
- Demonstração de comparação entre personagens usando equals()

**Simplificações para o Nível Aventureiro:**
- Continue cadastrando apenas dois personagens
- Foque na sobrescrita correta dos métodos e validações básicas

## 🏆 Nível Mestre: Polimorfismo e Verificação de Tipos

No nível Mestre, você implementará polimorfismo dinâmico com ArrayList e verificação de tipos com instanceof.

### 🆕 Diferença em relação ao Nível Aventureiro:

**Polimorfismo Dinâmico:**
- ArrayList<Personagem> armazenando diferentes tipos de heróis
- Vinculação dinâmica do método usarHabilidade()

**Verificação de Tipos:**
- Uso do operador instanceof para identificar tipos em tempo de execução
- Mensagens personalizadas para cada tipo de personagem

**Sistema Completo:**
- Cadastro de múltiplos personagens (pelo menos 2 Magos e 2 Guerreiros)
- Comparações entre personagens diferentes
- Demonstração de todos os conceitos de POO

### ⚙️ Funcionalidades do Sistema:

- Lista polimórfica que armazena diferentes tipos de personagens
- Iteração sobre a lista demonstrando polimorfismo dinâmico
- Verificação de tipos e exibição de mensagens específicas
- Comparação completa entre personagens usando equals()

### 📥 Entrada e 📤 Saída de Dados:

- Mesma entrada dos níveis anteriores, mas com múltiplos personagens
- A saída mostrará o resultado completo com polimorfismo, comparações e verificações de tipo

**Exemplo de saída:**
```
=== BEM-VINDOS AO REINO DE ELDORIA ===
--- Herói 1 ---
Nome: Eldoran
Classe: Mago
Nível: 7
Pontos de Vida: 60
Poder Base: 18.0
Habilidade: Eldoran conjura um feitiço de proteção!
O personagem Eldoran é um Mago de nível 7.

Comparação: Eldoran e Arthemis são diferentes.
```

**Observação**: Preste atenção à implementação correta do polimorfismo e à consistência entre equals() e hashCode()!

## 🏁 Conclusão

Ao concluir qualquer um dos níveis, você terá dado um passo importante no domínio da Programação Orientada a Objetos com Java. Boa sorte e divirta-se programando!

**Equipe de Ensino - TechNova**


