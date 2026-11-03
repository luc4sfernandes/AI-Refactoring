/**
 * Classe abstrata que representa um explorador na Caça ao Tesouro Paralela.
 * Define a estrutura básica para diferentes tipos de exploradores.
 */
public abstract class Explorador {
    
    // * Construtor que inicializa todos os atributos do explorador.
    


    /**
     * Método abstrato que deve ser implementado pelas subclasses.
     * Define como cada tipo de explorador executa sua tarefa.
     * @throws TarefaInvalidaException Se a tarefa for inválida
     */
    public abstract void executarTarefa() throws TarefaInvalidaException;
    
    /**
     * Exibe o status completo do explorador com formatação clara.
     */
    public void exibirStatus() {

    }
    
    // Getters para acesso aos atributos encapsulados


}

