#ifndef NO_H_
#define NO_H_

using namespace std;

/**
 * @brief Classe No
 * Classe No da arvore. Esta contem as vareaveis de elementos da arvore, ponteiros para
 * pais e filhos e endereco da posicao.
 *
 * @author Juliana Scaquetti, 298921
 * @author Victor Hugo B. R. Santos, 298557
 * @author Diego D. da Silva, 298700
 * @author Thiago A. C. Chagas, 280615
 * @version 5 de Dezembro de 2008
 */

class No {
	//TODO: remover esta linha
	friend class BTree;
private:
	/**
	 * Numero de chaves armazenadas na pagina.
	 */
	int nChaves;

	/**
	 * Vetor de chaves do no.
	 */
	Chave *chave;

	/**
	 * Endereco do Nodo.
	 */
	long _pos;

	/**
	 * Endereco do nodo pai.
	 */
	long _pai;

	/**
	 * Vetor de endereco dos filhos.
	 */
	long* _filho;

public:
	/**
	 * Construtor.
	 */
	No() {
		nChaves = 0;
		_pos = 0;
		_pai = 0;
	}

	/**
	 * Destrutor
	 */
	~No() {
		/*delete[] chave;
		 delete[] filho;*/
	}


	/**
	 * Metodo para setar o endereco do pai.
	 * @param end endereco do pai.
	 */
	void set_pai(long end) {
		_pai = end;
	}

	/**
	 * Metodoo que retorna o endereco do pai.
	 * @return endereco do pai.
	 */
	long get_pai() {
		return _pai;
	}

	/**
	 * Metodo para setar o RA.
	 * @param ra o valor do RA.
	 * @param indice o indice do vetor de chaves.
	 */
	void setRA(int ra, int indice) {
		chave[indice].setRA(ra);
	}

	/**
	 * Metodo que retorna o RA.
	 * @param indice indice do vetor de chaves.
	 * @return o valor do RA.
	 */
	int getRA(int indice) {
		return chave[indice].getRA();
	}

	/**
	 * Metodo que seta a posicao do Registro no arquivo de dados.
	 * @param endereco endereco do Registro.
	 * @param indice indice do vetor de chaves.
	 */
	void setRegistro(long endereco, int indice) {
		chave[indice].setRegistro(endereco);
	}

	/**
	 * Metodo que retorna o endereco do Registro no arquivo de dados.
	 * @param indice indice do vetor de chaves.
	 * @return o endereco do Registro.
	 */
	long getRegistro(int indice) {
		return chave[indice].getRegistro();
	}

	/**
	 * Metodo que seta o ponteiro do filho.
	 * @param valor o ponteiro do filho.
	 */
	void set_filho(long valor, int indice) {
		_filho[indice] = valor;
	}

	/**
	 * Metodo que retorna o ponteiro do filho.
	 * @param indice indice do vetor de ponteiros do filho.
	 * @return o ponteiro do filho.
	 */
	long get_filho(int indice) {
		return _filho[indice];
	}

	/**
	 * Metodo que seta a posicao do nodo.
	 * @param posicao posicao do nodo no arquivo.
	 */
	void set_pos(long posicao) {
		_pos = posicao;
	}

	/**
	 * Metodo que retorna o endereco do nodo.
	 * @return endereco do nodo.
	 */
	long get_pos() {
		return _pos;
	}


	/**
	 * Metodo que seta a chave segundo um indice de um vetor de chave.
	 * @param ch chave que sera setada.
	 * @param indice indice do vetor de chaves.
	 */
	void setChave(Chave ch, int indice) {
		setRA(ch.getRA(), indice);
		setRegistro(ch.getRegistro(), indice);
	}

	/**
	 * Metodo que retorna o objeto chave segundo um indice de um vetor de chave.
	 * @param indice indice do vetor de chave.
	 * @return um objeto chave.
	 */
	Chave getChave(int indice) {
		Chave aux;

		aux.setRA(getRA(indice));
		aux.setRegistro(getRegistro(indice));

		return aux;
	}

	/**
	 * Metodo que seta o numero de chaves.
	 * @param valor numero de chaves.
	 */
	void setNChaves(int valor) {
		nChaves = valor;
	}

	/**
	 * Metodo que retorna o numero de chaves.
	 * @return o numero de chaves.
	 */
	int getNChaves() {
		return nChaves;
	}

	/**
	 * Metodo para alocar o no.
	 * @param n o tamanho dos vetores de chave e filho dependem desse.
	 */
	void iniciaNo(int n) {
		chave = new Chave[n];
		_filho = new long[n + 1];
	}

};

#endif /*NO_H_*/
