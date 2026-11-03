/**
 * Explorador rápido que executa tarefas com alta velocidade e eficiência.
 * Implementa Runnable para execução em thread separada.
 */
public class ExploradorRapido extends Explorador implements Runnable {
    
    // * Construtor do explorador rápido.
    
    /**
     * Implementação específica da execução de tarefa para exploradores rápidos.
     * Exploradores rápidos executam tarefas com maior agilidade.
     * @throws TarefaInvalidaException Se a tarefa for nula ou vazia
     */
    @Override
    public void executarTarefa() throws TarefaInvalidaException {
        
    }
    
    /**
     * Método run() executado quando a thread é iniciada.
     * Trata exceções e chama executarTarefa().
     */
    @Override
    public void run() {
    }
}

