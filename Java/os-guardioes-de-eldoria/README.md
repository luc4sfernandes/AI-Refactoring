# Desafio - Os Guardiões de Eldoria 🗡️🛡️

Olá! Boas-vindas ao desafio de programação do **Tema 1: Introdução à Programação OO em Java**! 

A TechNova, uma renomada empresa de tecnologia, contratou você como programador-líder para restaurar a ordem e a lógica no desenvolvimento do jogo de RPG *Os Guardiões de Eldoria*. Sua missão é aplicar os princípios da Programação Orientada a Objetos (POO) com Java para otimizar as funcionalidades do jogo, organizando dados que foram lançados ao caos.

O desafio está dividido em três níveis de dificuldade: **Novato, Aventureiro e Mestre**. Cada etapa reflete habilidades reais exigidas pelo mercado, desde o design básico de classes até o gerenciamento de grandes volumes de objetos. Você deve escolher qual nível quer realizar de acordo com o seu momento de aprendizado.

🚨 **Atenção**: É fundamental organizar seu código, utilizar boas práticas de nomenclatura (PascalCase para classes, camelCase para atributos/métodos), fazer a correta identação e comentar trechos relevantes.

---

## 🟢 Nível Novato: Ambiente, Classes e Objetos

No nível Novato, o coração da orientação a objetos começa a bater. Você dará o primeiro passo criando a estrutura fundamental dos personagens do jogo, atribuindo características e comportamentos a eles.

🚩 **Objetivo**: Criar um programa em Java que defina uma classe base e instancie objetos na memória.

### ⚙️ Funcionalidades do Sistema:
- Criação da classe `Personagem`.
- Definição dos seguintes atributos:
  - `nome` (String)
  - `classe` (String - ex: Mago, Guerreiro, Arqueiro)
  - `nivel` (int)
  - `pontosDeVida` (int)
  - `poderBase` (double)
- Criação do método `exibirStatus()`, responsável por imprimir no console todas as informações do personagem de forma legível.

### 📥 Entrada e 📤 Saída de Dados:
- No método `main`, instancie **dois personagens** (utilizando a palavra-chave `new`).
- Atribua valores diretamente aos atributos.
- Chame o método `exibirStatus()` para cada um.

**Restrições do Nível Novato:**
- Não utilize estruturas de decisão (`if`, `switch`) ou repetição (`for`, `while`).
- O código deve compilar e executar sem erros via terminal ou IDE.

**Exemplo de saída esperada:**
```text
Nome: Arthemis
Classe: Arqueira
Nível: 5
Pontos de Vida: 80
Poder Base: 12.5
```

---

## 🟡 Nível Aventureiro: Herança, Classes Abstratas e Polimorfismo

No nível Aventureiro, a hierarquia de Eldoria ganha forma! Você vai evoluir o seu código aplicando herança para reaproveitar lógicas e polimorfismo para tratar diferentes heróis de forma genérica.

### 🆕 Evolução em relação ao Nível Novato:
Você transformará a classe `Personagem` em uma **superclasse abstrata** e criará classes especializadas que herdam dela.

### ⚙️ Funcionalidades do Sistema:
- **Classe Abstrata**: Transforme `Personagem` em uma classe `abstract`.
- **Construtores**: Utilize construtores adequados, usando `super()` nas subclasses para inicializar os dados da superclasse.
- **Herança**: Crie pelo menos duas subclasses (ex: `Guerreiro` e `Mago`) com atributos e comportamentos próprios.
- **Métodos Abstratos e Sobrescrita**:
  - Adicione o método abstrato `usarHabilidadeEspecial()` em `Personagem`.
  - Sobrescreva (`@Override`) este método em cada subclasse com uma mensagem personalizada. (Ex: *"Guerreiro Arthus ataca com Espada Flamejante!"*).
- **Reuso**: Crie um método `exibirStatus()` na classe mãe para reaproveitar comportamento comum.

### 📥 Entrada e 📤 Saída de Dados:
- Instancie diferentes personagens e armazene-os em uma estrutura polimórfica (um `Array` clássico `Personagem[]` ou `ArrayList`).
- Faça uma iteração (`for` ou `foreach`) sobre essa estrutura e chame o método `usarHabilidadeEspecial()` de forma genérica, demonstrando o polimorfismo em tempo de execução (Dynamic Dispatch).

---

## 🔴 Nível Mestre: Associações, Coleções e Batalhas Épicas

Chegou a hora de provar seu domínio! No nível Mestre, você agrupará objetos utilizando a *Java Collections Framework* e colocará seus heróis para duelar utilizando regras de negócio precisas.

### 🆕 Evolução em relação ao Nível Aventureiro:
Você vai criar relações do tipo "um-para-muitos" utilizando a classe `ArrayList` e implementar lógicas matemáticas para decidir o vencedor de um confronto.

### ⚙️ Funcionalidades do Sistema:
- **Associação**: Crie a classe `Grupo` que contém uma lista encapsulada: `private ArrayList<Personagem> membros;`
- **Métodos do Grupo**:
  - `adicionarPersonagem(Personagem p)`: Insere um herói na coleção.
  - `listarPersonagens()`: Exibe todos os membros do grupo.
  - `batalhar(Personagem a, Personagem b)`: Realiza a batalha e exibe o vencedor.
- **Lógica de Combate**: 
  - Aplique a fórmula: `int poderTotal = personagem.getNivel() * personagem.getPoderBase();`
  - O personagem com maior `poderTotal` vence.

### 📥 Entrada e 📤 Saída de Dados:
- Crie múltiplos personagens e adicione-os a dois grupos distintos.
- Realize batalhas e exiba o resultado.

**Exemplo de saída de batalha:**
```text
Mago Elenara venceu! Poder total: 300
```

### 🌟 Desafios Extras (Opcional - Para ir além!):
1. Crie uma classe `Arena` com o método `batalharGrupos(Grupo g1, Grupo g2)` que realiza batalhas em pares entre os membros dos dois grupos.
2. Implemente a interface `Comparable` na classe `Personagem` para permitir a ordenação (ex: `Collections.sort()`) dos personagens pelo seu nível antes das batalhas.

---

## 🏁 Conclusão e Entrega

A arquitetura de sistemas orientados a objetos reflete a complexidade do mundo real. Ao concluir este desafio, você não escreveu apenas código: você modelou um ecossistema digital reutilizável, coeso e escalável.

* Para realizar a entrega, faça o **commit** do seu código no repositório do GitHub Classroom fornecido.
* Lembre-se de organizar cada classe em um arquivo separado (`.java`).

A jornada começa agora, Guardião. **Vamos lá!** 🚀☕

---
*Professor e Curadoria de TI - Curso de Programação Orientada a Objetos em Java.*
```
