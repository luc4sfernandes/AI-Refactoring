## Desafio Caça ao Tesouro Paralela - Programação Concorrente em Java ##

Bem-vindo ao desafio **"Caça ao Tesouro Paralela"**! Neste jogo, você será o líder de uma expedição em uma ilha misteriosa repleta de tesouros escondidos. Seu papel é coordenar exploradores que atuam como **threads** em um mapa 10x10, garantindo que a busca seja simultânea, eficiente e sem conflitos.

O desafio está dividido em três níveis: **Novato, Aventureiro e Mestre**, cada um acrescentando novos conceitos e complexidade. Você pode escolher qual nível deseja realizar ou avançar gradualmente.

### 🎮 Nível Novato: Exploradores em Ação ###

No nível Novato, você dará os primeiros passos na missão, criando **threads básicas** para explorar o mapa.

🚩 **Objetivo:** Implementar threads em Java que simulem exploradores percorrendo o mapa em paralelo.

⚙️ **Funcionalidades do Sistema:**

- Criar uma classe abstrata Explorador com atributos como nome, tipo, prioridade e tarefa.
- Criar subclasses como **ExploradorRápido** e **ExploradorCuidadoso**, cada uma implementando **Runnable**.
- Implementar executarTarefa() de forma distinta em cada subclasse.
- Tratar **exceções personalizadas** (ex: TarefaInvalidaException) quando uma tarefa for nula ou inválida.
- Exibir o status de cada explorador durante a execução.

📥 **Entrada** e 📤 **Saída de Dados:**

- O usuário define pelo menos 4 exploradores com diferentes tarefas.
- O sistema cria threads e as inicia em paralelo.
- Saída mostra mensagens temáticas como:
- Explorador: Alice | Tipo: Rápido | Status: Vasculhando a caverna!
- Explorador: Bob | Tipo: Cuidadoso | Status: Mapeando a floresta com cautela.
- Erro: Tarefa inválida para Clara

📝 **Simplificações:**

- Não usar estruturas de decisão ou repetição dentro das classes explorador (apenas no main).
- Organizar threads em **ArrayList&lt;Thread&gt;**.

### 🛡️ Nível Aventureiro: Coordenação e Sincronização ###

No nível Aventureiro, você enfrentará o desafio de garantir que exploradores **não coletem o mesmo tesouro ao mesmo tempo**.

🆕 **Diferença em relação ao Novato:**

- Implementação de **sincronização com Semáforos e Monitores** (synchronized, Semaphore, wait(), notify()).
- Criação de **objetos imutáveis** para representar tarefas, garantindo segurança no compartilhamento.

⚙️ **Funcionalidades do Sistema:**

- Criar uma classe Tarefa imutável (final, atributos private final, apenas getters).
- Utilizar um **Semaphore** para controlar quantos exploradores podem agir simultaneamente.
- Sincronizar regiões críticas para evitar condições de corrida.
- Exibir mensagens mostrando que apenas exploradores autorizados conseguem acessar um recurso.

📥 **Entrada** e 📤 **Saída de Dados:**

- O usuário cria pelo menos 4 tarefas e 4 exploradores.
- Threads competem por permissões do semáforo (ex: 2 permissões simultâneas).
- Saída mostra execuções coordenadas:
- Alice iniciou tarefa: Mapear caverna
- Bob aguardando permissão...
- Bob iniciou tarefa: Explorar ruínas

### 🏆 Nível Mestre: Estratégia Avançada com ExecutorService e Fork/Join ###

No nível Mestre, você usará recursos avançados da API de concorrência do Java para gerenciar exploradores de forma escalável e eficiente.

🆕 **Diferença em relação ao Aventureiro:**

- Uso de **ExecutorService** para gerenciar pools de threads.
- Implementação de **Callable e Future** para retornar resultados de missões.
- Aplicação do **Fork/Join Framework** para consolidar pontos obtidos pelas equipes.

⚙️ **Funcionalidades do Sistema:**

- Criar uma classe imutável Missao com descricao, local e dificuldade.
- Criar subclasses de Explorador (ex: Rastreador, Saqueador) que implementem Callable&lt;Double&gt; e calculem pontos.
- Submeter exploradores ao ExecutorService, capturar resultados com Future e exibir no console.
- Implementar classe SomaPontos estendendo RecursiveTask&lt;Double&gt; para consolidar a pontuação final com Fork/Join.

📥 **Entrada** e 📤 **Saída de Dados:**

- Usuário cadastra pelo menos 4 exploradores e suas missões.
- Sistema processa as missões em paralelo e calcula a soma total de pontos.

Exemplo de saída esperada:

Explorador: Lina | Especialidade: Rastreador | Missão: Mapear cavernas | Pontos: 150.0

Explorador: Drogan | Especialidade: Saqueador | Missão: Recuperar artefatos | Pontos: 200.0

Soma total dos pontos: 650.0

**🏁 Conclusão**

Ao concluir qualquer um dos níveis, você terá desenvolvido competências fundamentais em **programação concorrente com Java**: desde a criação básica de threads até a aplicação de **ExecutorService, Callable/Future, Semáforos e Fork/Join Framework**.

Este desafio simula a verdadeira liderança em uma expedição paralela: coordenar exploradores, evitar conflitos e garantir que todos os tesouros sejam encontrados com eficiência.

Boa sorte e divirta-se programando!
