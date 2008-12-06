#ifndef ARQUIVOB_H_
#define ARQUIVOB_H_

#include "No.h"
using namespace std;

/* identificadores para os enderecos no arquivo da arvore */
#define POSICAO_IDENTIFICADOR 0
#define POSICAO_ORDEM 1
#define POSICAO_RAIZ 5
#define POSICAO_DISPONIVEIS 9


/**
 * @brief Classe ArquivoB
 * Classe para manipular o arquivo da arvore B. La encontra-se os nos que serao
 * gravados as chaves, ponteiros, enderecos, e outros dados.
 *
 * @author Juliana Scaquetti, 298921
 * @author Victor Hugo B. R. Santos, 298557
 * @author Diego D. da Silva, 298700
 * @author Thiago A. C. Chagas, 280615
 * @version 5 de Dezembro de 2008
 */
class ArquivoB {
private:
	/**
	 * Stream para controlar o arquivo.
	 */
	fstream fB;

	/**
	 * Nodo da arvore B.
	 */
	No nodo;

	/**
	 * Ordem da arvore B.
	 */
	int ordem;


public:

	/**
	 * Construtor
	 * Abre o arquivo da arvore.
	 */
	ArquivoB(){
		fB.open("btree.txt", fstream::in | fstream::out | fstream::binary);
		this->ordem = this->getOrdem();
		nodo.iniciaNo(this->ordem);
	}

	/**
	 * Destrutor
	 * Fecha o arquivo da arvore.
	 */
	~ArquivoB(){
		if(fB.is_open())
			fB.close();
	}

	/**
	 * Metodo para construir o cabecalho do arquivo da arvore.
	 * @param n ordem da arvore.
	 */
	void setCabecalho(int n){
		char identificador = 'I';
		long temp = 0;
		fB.seekp(0, ios::beg);
		fB.write(reinterpret_cast<char*>(&identificador), sizeof(identificador));
		fB.write(reinterpret_cast<char*>(&n), sizeof(n));
		fB.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		fB.write(reinterpret_cast<char*>(&temp), sizeof(n));
	}

	/**
	 * Metodo para mudar o valor da raiz.
	 * @param endereco endereco que vai ser colocado no campo da raiz no cabecalho do arquivo da arvore.
	 */
	void setRaiz(long endereco){
		fB.seekp(POSICAO_RAIZ, ios::beg);
		fB.write(reinterpret_cast<char*>(&endereco), sizeof(endereco));
	}

	/**
	 * Metodo que escreve o no carregado no arquivo da arvore.
	 * @param nodo no carregado na memoria para ser escrito no arquivo da arvore.
	 */
	void escreveNo(const No &nodo){
		fB.seekp(nodo.get_pos(), ios::beg);
		fB.write(reinterpret_cast<char*>(&nodo->getNChaves()), 4);
		fB.write(reinterpret_cast<char*>(&nodo->get_pai()), 4);
		for (i = 0; i < this->ordem; ++i) {
														//mudar com set e get
			fB.write(reinterpret_cast<char*>(&nodo->chave[i]->valor), 4);
			fB.write(reinterpret_cast<char*>(&nodo->chave[i]->registro), 4);
			fB.write(reinterpret_cast<char*>(&nodo->_filho[i]), 4);
		}
	}

	/**
	 * Metodo que retorna o endereco da lista de disponiveis do arquivo da arvore.
	 * @return retorna o endereco que esta disponivel para gravar um nodo no arquivo da arvore.
	 */
	long getListaDisp(){
		long enderecoDisp;
		fB.seekg(POSICAO_DISPONIVEIS, ios::beg);
		fB.read(reinterpret_cast<char*>(&enderecoDisp), sizeof(enderecoDisp));
		return enderecoDisp;
	}

	/**
	 * Metodo que muda o valor do endereco na lista de disponiveis no arquivo da arvore.
	 * @param endereco endereco a ser gravado na lista de disponiveis do arquivo da arvore.
	 */
	void setListaDisp(const long endereco){
		fB.seekp(POSICAO_DISPONIVEIS, ios::beg);
		fB.write(reinterpret_cast<char*>(&endereco), sizeof(endereco));
	}

};

#endif /*ARQUIVOB_H_*/
