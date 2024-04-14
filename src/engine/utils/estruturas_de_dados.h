#pragma once
#include "SDL2/SDL.h"

/***********************************************************************************/
/* IMPLEMENTAÇÃO DE LISTA ESTÁTICA */
/***********************************************************************************/
template <class T>
class ListaEstatica {
    private:
    //typedef SDL_Rect* DATA;
    //---------------------------------------------------------------------------------------------------------
    // ATRIBUTOS PRIVADOS
    //---------------------------------------------------------------------------------------------------------
    int capacidade=5; // capacidade padrão
    int aumento=5; // qtd de aumento da capacidade na operação "aumentarCapacidadeCasoNecessario()"
    int qtd;
    T* dados; // um array de T

    //---------------------------------------------------------------------------------------------------------
    // MÉTODOS PRIVADOS
    //---------------------------------------------------------------------------------------------------------
    void aumentarCapacidadeCasoNecessario(){
        if(this->qtd < this->capacidade) return; // caso não seja necessário, cai fora
        // cria um novo array de dados com o dobro da capacidade
        capacidade+=aumento;
        T* novosDados = new T[capacidade];
        // transfere os dados do anterior para o novo
        for(int i=0;i<qtd;i++){
            novosDados[i]=this->dados[i];
        }
        delete[] this->dados; // libera a memória do array antigo
        this->dados = novosDados; // redireciona o ponteiro dos dados para o novo espaço
    }

    public:
    //---------------------------------------------------------------------------------------------------------
    // CONTRUTORES
    //---------------------------------------------------------------------------------------------------------
    ListaEstatica(){
        this->qtd = 0; // a princípio a lista está vazia
        this->dados = new T[capacidade];
    }

    //---------------------------------------------------------------------------------------------------------
    // MÉTODOS
    //---------------------------------------------------------------------------------------------------------
    int capacity() // retorna a capacidade máxima de elementos
    {
        return this->capacidade;
    }
    int size() // retorna a qtd de elementos atualmente existentes
    {
        return this->qtd;
    }
    int add(T valor) // adiciona no início
    {
        return this->add(valor,0);
    }
    int add(T valor, int index) // adiciona em um índice específico
    {
        if(index>this->qtd || index < 0) return 1; // se o indice for inválido
        aumentarCapacidadeCasoNecessario(); // verifica se ainda há espaço
        int i=this->qtd; // ponteiro de movimentação dos dados
        while(i>index){ // condição de parada para a movimentação dos dados
            this->dados[i]=this->dados[i-1]; // movimenta os dados 1 pos para o fundo da estrutura
            i--; // retrocede o ponteiro
        }
        this->dados[index]=valor;
        this->qtd++;
        return 0; // adição feita com sucesso
    }
    T get(int index) // obtém um valor de uma posição específicia
    {
        // if(this->qtd==0) reutn nullptr; omitido por questões de desempenho
        return this->dados[index];
    }
    void remove(int index) // remove de uma posição específica
    {

    }
};