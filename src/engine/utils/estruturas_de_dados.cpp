#include "estruturas_de_dados.h"

//---------------------------------------------------------------------------------------------------------
// MÉTODOS PRIVADOS
//---------------------------------------------------------------------------------------------------------

void SpriteList::aumentarCapacidadeCasoNecessario(){
    if(this->qtd < this->capacidade) return; // caso não seja necessário, cai fora
    // cria um novo array de dados com o dobro da capacidade
    capacidade+=aumento;
    DATA* novosDados = new DATA[capacidade];
    // transfere os dados do anterior para o novo
    for(int i=0;i<qtd;i++){
        novosDados[i]=this->dados[i];
    }
    delete[] this->dados; // libera a memória do array antigo
    this->dados = novosDados; // redireciona o ponteiro dos dados para o novo espaço
}

//---------------------------------------------------------------------------------------------------------
// CONTRUTORES
//---------------------------------------------------------------------------------------------------------

SpriteList::SpriteList()
{
    this->qtd = 0; // a princípio a lista está vazia
    this->dados = new DATA[capacidade];
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------

int SpriteList::capacity()
{
    return this->capacidade;
}

int SpriteList::size(){
    return this->qtd;
}

int SpriteList::add(DATA valor)
{
    return this->add(valor,0);
}

int SpriteList::add(DATA valor, int index)
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

SpriteList::DATA SpriteList::get(int index)
{
    // if(this->qtd==0) reutn nullptr; omitido por questões de desempenho
    return this->dados[index];
}
void SpriteList::remove(int index)
{
}