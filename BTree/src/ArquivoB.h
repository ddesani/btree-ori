#ifndef ARQUIVOB_H_
#define ARQUIVOB_H_
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

	/**
	 * Nome do arquivo
	 */
	string filename;

public:

	/**
	 * Construtor
	 * Abre o arquivo da arvore.
	 */
	ArquivoB() //apagar o filename
	{
		fB.open("btree.txt", fstream::in | fstream::out | fstream::binary);
	}

	/**
	 * Destrutor
	 * Fecha o arquivo da arvore.
	 */
	~ArquivoB() {
		if (fB.is_open())
			fB.close();
	}

	/**
	 * Metodo para iniciar o no do arquivo com ordem n.
	 * @return verdadeiro se alocou o no e false caso contrario.
	 */
	bool open() {

		if (fB.is_open()) {

			this->ordem = this->getOrdem();
			nodo.iniciaNo(this->ordem);

			return true;
		} else
			return false;
	}

	/**
	 * Metodo para construir o cabecalho do arquivo da arvore.
	 * @param n ordem da arvore.
	 */
	void setCabecalho(int n) {
		char identificador = 'I';
		ordem = n + 1;
		nodo.iniciaNo(ordem);
		long temp = 0;
		fB.seekp(0, ios::beg);
		fB.write(reinterpret_cast<char*> (&identificador), 1);
		fB.write(reinterpret_cast<char*> (&n), 4);
		fB.write(reinterpret_cast<char*> (&temp), 4);
		fB.write(reinterpret_cast<char*> (&temp), 4);
	}

	/**
	 * Metodo para mudar o valor da raiz.
	 * @param endereco endereco que vai ser colocado no campo da raiz no cabecalho do arquivo da arvore.
	 */
	void setRaiz(long endereco) {
		fB.seekp(POSICAO_RAIZ, ios::beg);
		fB.write(reinterpret_cast<char*> (&endereco), sizeof(endereco));
	}

	/**
	 * Metodo para setar o nome do arquivo.
	 * @param nome nome do arquivo.
	 */
	void setFileName(string nome) {
		filename = nome;
	}

	/**
	 * Metodo para pegar o nome do arquivo.
	 * @return o nome do arquivo.
	 */
	string getFileName() {
		return filename;
	}

	/**
	 * Metodo que retorna o endereco da raiz.
	 * @return endereco da raiz.
	 */
	long getRaiz() {
		long raiz;

		fB.seekg(POSICAO_RAIZ, ios::beg);
		fB.read(reinterpret_cast<char *> (&raiz), 4);

		return raiz;
	}

	/**
	 * Metodo que muda o valor do endereco na lista de disponiveis no arquivo da arvore.
	 * @param endereco endereco a ser gravado na lista de disponiveis do arquivo da arvore.
	 */
	void setListaDisp(long endereco) {
		fB.seekp(POSICAO_DISPONIVEIS, ios::beg);
		fB.write(reinterpret_cast<char*> (&endereco), sizeof(endereco));
	}

	/**
	 * Metodo que retorna o endereco da lista de disponiveis do arquivo da arvore.
	 * @return retorna o endereco que esta disponivel para gravar um nodo no arquivo da arvore.
	 */
	long getListaDisp() {
		long enderecoDisp;
		fB.seekg(POSICAO_DISPONIVEIS, ios::beg);
		fB.read(reinterpret_cast<char*> (&enderecoDisp), sizeof(enderecoDisp));
		return enderecoDisp;
	}

	/**
	 * Metodo para setar o endereco do pai no nodo.
	 * @param endereco endereco do nodo.
	 */
	void setPai(long endereco) {
		nodo.set_pai(endereco);
	}

	/**
	 * Metodo que pega o endereco do pai no nodo.
	 * @return endereco do pai no nodo.
	 */
	long getPai() {
		return nodo.get_pai();
	}

	/**
	 * Metodo que retorna a ordem do nodo.
	 * @return a ordem do nodo.
	 */
	int getOrdem() {
		int ordem;

		fB.seekg(POSICAO_ORDEM, ios::beg);
		fB.read(reinterpret_cast<char *> (&ordem), 4);

		return ordem;
	}

	/**
	 * Metodo que escreve o no carregado no arquivo da arvore.
	 * @param nodo no carregado na memoria para ser escrito no arquivo da arvore.
	 */
	void escreveNo(No* nodo) {
		int dadoI;
		long dadoL;
		int i;

		if (nodo->get_pos() != 0) {
			//para um nodo que nao é novo
			dadoI = nodo->getNChaves();
			dadoL = nodo->get_pai();
			fB.seekp(nodo->get_pos(), ios::beg);
			fB.write(reinterpret_cast<char*> (&dadoI), 4);
			fB.write(reinterpret_cast<char*> (&dadoL), 4);
			for (i = 0; i < ordem; ++i) {
				dadoI = nodo->getRA(i);
				dadoL = nodo->getRegistro(i);
				fB.write(reinterpret_cast<char*> (&dadoI), 4);
				fB.write(reinterpret_cast<char*> (&dadoL), 4);

				dadoL = nodo->get_filho(i);
				fB.write(reinterpret_cast<char*> (&dadoL), 4);
			}
			dadoL = nodo->get_filho(i);
			fB.write(reinterpret_cast<char*> (&dadoL), 4);
		} else {
			//se o nodo é novo
			long temp = this->getListaDisp();
			if (temp == 0) {
				dadoI = nodo->getNChaves();
				dadoL = nodo->get_pai();
				fB.seekp(0, ios::end);
				fB.write(reinterpret_cast<char*> (&dadoI), 4);
				fB.write(reinterpret_cast<char*> (&dadoL), 4);
				for (i = 0; i < ordem; ++i) {
					dadoI = nodo->getRA(i);
					dadoL = nodo->getRegistro(i);
					fB.write(reinterpret_cast<char*> (&dadoI), 4);
					fB.write(reinterpret_cast<char*> (&dadoL), 4);

					dadoL = nodo->get_filho(i);
					fB.write(reinterpret_cast<char*> (&dadoL), 4);
				}
				dadoL = nodo->get_filho(i);
				fB.write(reinterpret_cast<char*> (&dadoL), 4);
			} else {
				dadoI = nodo->getNChaves();
				dadoL = nodo->get_pai();
				fB.seekg(temp, ios::beg);
				long temp2;
				fB.read(reinterpret_cast<char*>(&temp2), sizeof(temp2));
				this->setListaDisp(temp2);
				fB.seekp(temp, ios::beg);
				fB.write(reinterpret_cast<char*> (&dadoI), 4);
				fB.write(reinterpret_cast<char*> (&dadoL), 4);
				for (i = 0; i < ordem; ++i) {
					dadoI = nodo->getRA(i);
					dadoL = nodo->getRegistro(i);
					fB.write(reinterpret_cast<char*> (&dadoI), 4);
					fB.write(reinterpret_cast<char*> (&dadoL), 4);

					dadoL = nodo->get_filho(i);
					fB.write(reinterpret_cast<char*> (&dadoL), 4);
				}
				dadoL = nodo->get_filho(i);
				fB.write(reinterpret_cast<char*> (&dadoL), 4);
			}
		}
	}

	/**
	 * Metodo que remove o nodo do arquivo de dados da arvore.
	 * @param posicao endereco do nodo no arquivo da arvore.
	 */
	void removerNo(long posicao){
		long temp = this->getListaDisp();
		this->setListaDisp(posicao);
		fB.seekp(posicao, ios::beg);
		fB.write(reinterpret_cast<char*>(&temp), sizeof(temp));
	}

	/**
	 * Metodo que carrega o no na memoria.
	 * @param posicao endereco do no no arquivo.
	 * @return retorna um ponteiro para o no.
	 */
	No* carregaNo(long posicao) {
		if (posicao != 0) {
			int dadosI;
			long dadosL;

			nodo.set_pos(posicao);

			fB.seekg(posicao, ios::beg);

			fB.read(reinterpret_cast<char *> (&dadosI), 4);
			nodo.setNChaves(dadosI);

			fB.read(reinterpret_cast<char *> (&dadosL), 4);
			nodo.set_pai(dadosL);

			for (int i = 0; i < ordem; ++i) {
				fB.read(reinterpret_cast<char*> (&dadosI), 4);
				nodo.setRA(dadosI, i);
			}

			for (int i = 0; i < ordem; ++i) {
				fB.read(reinterpret_cast<char*> (&dadosL), 4);
				nodo.setRegistro(dadosL, i);
			}
		}

		return &nodo;
	}

	/**
	 * Metodo que retorna um objeto da classe chave.
	 * @param indice posicao do vetor.
	 * @return retorna um objeto da classe chave.
	 */
	Chave getChave(int indice) {
		Chave aux;

		aux.setRA(nodo.getRA(indice));
		aux.setRegistro(nodo.getRegistro(indice));

		return aux;
	}

};

#endif /*ARQUIVOB_H_*/
