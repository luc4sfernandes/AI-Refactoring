/**
 * Explorador cuidadoso que executa tarefas com precisão e atenção aos detalhes.
 * Implementa Runnable para execução em thread separada.
 */
public class ExploradorCuidadoso extends Explorador implements Runnable {
    
    // * Construtor do explorador cuidadoso.
    
    /**
     * Implementação específica da execução de tarefa para exploradores cuidadosos.
     * Exploradores cuidadosos executam tarefas com mais cautela e precisão.
     * @throws TarefaInvalidaException Se a tarefa for nula ou vazia
     */
    @Override
    public void executarTarefa() throws TarefaInvalidaException {
        // Valida se a tarefa é válida
    }
    
    /**
     * Método run() executado quando a thread é iniciada.
     * Trata exceções e chama executarTarefa().
     */
    @Override
    public void run() {
    }
}

