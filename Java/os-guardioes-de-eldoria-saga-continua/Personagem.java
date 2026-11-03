package eldoria;

import java.util.Objects;

/**
 * Classe base para representar personagens do reino de Eldoria.
 * Aplica conceitos de encapsulamento, herança e polimorfismo.
 */
public class abstract Personagem {
    // Atributos privados (encapsulamento)


    // * Construtor que inicializa todos os atributos do personagem.

    // Getters

    // Setters com validações

    // * Criar métodos que define os pontos de vida do personagem.


    /**
     * Criar método que define a habilidade do personagem.
     * Deve ser sobrescrito pelas subclasses para implementar comportamentos específicos.
     */



    /**
     * Sobrescrita do método toString() para exibir informações do personagem.
     * @return String formatada com todos os atributos do personagem
     */
    @Override
    public String toString() {

    }

    /**
     * Sobrescrita do método equals() para comparar personagens.
     * Dois personagens são considerados iguais se tiverem o mesmo nome e classe.
     * @param obj Objeto a ser comparado
     * @return true se os personagens forem iguais, false caso contrário
     */
    @Override
    public boolean equals(Object obj) {

    }

    /**
     * Sobrescrita do método hashCode() para ser consistente com equals().
     * @return Código hash baseado no nome e classe
     */
    @Override
    public int hashCode() {

    }
}

