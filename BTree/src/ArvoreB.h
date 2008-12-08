#ifndef ARVOREB_H_
#define ARVOREB_H_
using namespace std;

/**
 * @brief Classe Registro
 * Classe para manipular a arvore-B
 * @author Juliana Scaquetti, 298921
 * @author Victor Hugo B. R. Santos, 298557
 * @author Diego D. da Silva, 298700
 * @author Thiago A. C. Chagas, 280615
 * @version 6 de Dezembro de 2008
 */

class Btree
{
private:

	/**
	 * Metodo para a inicializacao da arvore-B
	 * @param Chave - chave com o valor que sera inserido
	 * @param No* - nodo onde sera inserida a chave
	 */
	void insere(Chave ch, No* no)
	{
		No* _filho1;
		No* _filho2;
		_filho1 = new No;
		_filho2 = new No;
		No* _pai;
		_pai = new No;
		_pai->iniciaNo(nChaves);
		No* novo;
		int i, j;
		bool sair = false;

		// inserir nova chave no no
		do
		{
			//quando um nodo esta vazio
			if (no->getNChaves() == 0)
			{
				no = new No;
				no->iniciaNo(nChaves);
				no->setNChaves(0);
				objArqB.escreveNo(no);
				_raiz = no->get_pos();
				objArqB.setRaiz(_raiz);
			}

			//para que o no nao seja alterado
			//fazemos o pai apontar para outro 
			//endereco de memoria
			No* auxPai = new No;
			auxPai->iniciaNo(nChaves);
			*auxPai = objArqB.carregaNo(no->get_pai());

			_pai = auxPai;

			// quando ocorre overflow no nodo
			if (no->getNChaves() == nChaves)
			{
				// nodo direito
				novo = new No;
				novo->iniciaNo(nChaves);

				// Constroi lista ordenada de chaves
				// organiza os enderecos dos filhos
				i = 0;
				while (no->getRA(i) < ch.getRA() && i < nChaves)
				{
					lista[i] = no->getChave(i);
					_listaPtr[i] = no->get_filho(i);
					++i;
				}
				lista[i] = ch;
				_listaPtr[i] = _filho1->get_pos();
				_listaPtr[i+1] = _filho2->get_pos();
				while (i < nChaves)
				{
					lista[i+1] = no->getChave(i);
					_listaPtr[i+2] = no->get_filho(i+1);
					i++;
				}

				// Dividir nos
				// No esquerdo
				for (j = 0; j < (nChaves/2); j++)
				{
					no->setChave(lista[j], j);
					no->set_filho(_listaPtr[j], j);
				}
				no->setNChaves(nChaves/2);
				no->set_filho(_listaPtr[no->getNChaves()], no->getNChaves());
				objArqB.escreveNo(no);

				// No direito
				// Organiza as chaves e os enderecos dos filhos
				novo->setNChaves(nChaves - no->getNChaves());
				for (j = 0; j < novo->getNChaves(); ++j)
				{
					novo->setChave(lista[j+(nChaves/2)+1], j);
					novo->set_filho(_listaPtr[j+(nChaves/2)+1], j);
				}
				novo->set_filho(_listaPtr[nChaves+1], novo->getNChaves());
				// Grava no arquivo este novo nodo
				objArqB.escreveNo(novo);

				//Atualiza o endereco do pai para cada filho do nodo
				for (j = 0; j <= no->getNChaves(); ++j)
					if (no->get_filho(j))
					{
						No auxFilho = objArqB.carregaNo(no->get_filho(j));
						auxFilho.set_pai(no->get_pos());
						objArqB.escreveNo(&auxFilho);
					}

				for (j = 0; j <= novo->getNChaves(); j++)
					if (novo->get_filho(j))
					{
						No auxFilho = objArqB.carregaNo(novo->get_filho(j));
						auxFilho.set_pai(novo->get_pos());
						objArqB.escreveNo(&auxFilho);
					}
				// Obtem a chave da lista ordenada
				ch = lista[nChaves/2];

				// Carrega os filhos apos a quebra do nodo
				*_filho1 = objArqB.carregaNo(no->get_pos());
				_filho2 = novo;

				// Caso o pai nao seja 0 - cabecalho
				if (_pai->get_pos() != 0)
					_filho2->set_pai(_pai->get_pos());
				// Atualiza o nodo  _filho2 no arquivo
				objArqB.escreveNo(_filho2);
				no = _pai;
			}
			else //numero de Chaves != no->chaves
			{

				// Insere nova chave em seu lugar
				i = 0;

				if (no->getNChaves() > 0)
				{
					while (no->getRA(i) < ch.getRA() && i < no->getNChaves())
						i++;

					for (j = no->getNChaves(); j > i; --j)
						no->setChave(no->getChave(j-1), j);

					for (j = no->getNChaves()+1; j > i; --j)
						no->set_filho(no->get_filho(j-1), j);
				}

				no->setNChaves(no->getNChaves()+1);
				no->setChave(ch, i);
				no->set_filho(_filho1->get_pos(), i);
				no->set_filho(_filho2->get_pos(), i+1);

				objArqB.escreveNo(no);
				/*if (objArqB.getRaiz() != no->get_pai())
				 {
				 _raiz = no->get_pos();
				 objArqB.setRaiz(_raiz);
				 }*/
				if (_filho1->getNChaves() != 0)
				{
					_filho1->set_pai(no->get_pos());
					objArqB.escreveNo(_filho1);
				}
				if (_filho2->getNChaves() !=0)
				{
					_filho2->set_pai(no->get_pos());
					objArqB.escreveNo(_filho2);
				}

				sair = true;

			}
		} while (!sair);

	}

public:
	/**
	 * Objeto que manipulara o arquivo da arvore-B
	 */
	ArquivoB objArqB;

	/**
	 * Vetor de Chaves para mante-las ordenadas
	 */
	Chave* lista;

	/**
	 * Variavel para o total de chaves de um nodo
	 */
	int nChaves;

	/**
	 * Variavel que contem o endereco da raiz do arquivo
	 * btree.txt
	 */
	long _raiz;

	/**
	 * Vetor de enderecos dos nodos filhos
	 */
	long* _listaPtr;

	/**
	 * Construtor padrao para a classe Btree
	 */
	Btree()
	{

	}

	/**
	 * Destrutor padrao para a classe Btree
	 * desaloca os vetores que guardam os enderecos
	 */
	~Btree()
	{
		delete[] lista;
		delete[] _listaPtr;

	}

	/**
	 * Metodo para a inicializacao da arvore-B
	 * @param n Quantidade de elementos na arvore-B
	 */
	void open(int n)
	{
		//inicializa o cabecalho do arquivo
		//que contem a arvore-B
		objArqB.setCabecalho(n+1);
		//Inicia o total de chaves
		nChaves = n;
		// Vetor que ordena as chaves na insercao
		lista = new Chave[n+1];
		// Vetor que contem os enderecos dos filhos
		_listaPtr = new long[n+2];
		// Inicia a Raiz com endereco 0
		_raiz = 0;

	}

	/**
	 * Metodo para a inicializacao da arvore-B
	 */
	void open()
	{
		int n;

		//Obtem a ordem do cabecalho
		n = objArqB.getOrdem();

		//inicializa a variavel ordem de objArqB
		objArqB.setOrdem(n);

		//Inicia o total de chaves
		nChaves = n-1;
		// Vetor que ordena as chaves na insercao
		lista = new Chave[n];
		// Vetor que contem os enderecos dos filhos
		_listaPtr = new long[n+1];
		// Inicia a Raiz com endereco 0
		_raiz = objArqB.getRaiz();

	}

	/**
	 * Metodo para verificar o arquivo btree.txt
	 * @return true caso esteja vazio
	 */
	bool isEmpty()
	{
		if (objArqB.tamanho() > 0)
			return false;
		else
			return true;
	}

	/**
	 * Metodo que realiza a busca por uma determinada
	 * chave na arvore-B retornando o endereco do registro
	 * no arquivo de dados
	 * @param ch chave para a realizacao
	 * @return o endereco do registro no arquivo de dados
	 */
	long buscar(int ch)
	{
		// Inicia o nodo com a raiz
		No no = objArqB.carregaNo(objArqB.getRaiz());

		int i;

		// Realiza a busca pela chave na arvore
		while (no.getNChaves() !=0)
		{
			i =0;
			while (i< no.getNChaves() && (no.getRA(i) < ch))
				++i;
			if (no.getRA(i) == ch)
				return no.getRegistro(i);
			else
				no = objArqB.carregaNo(no.get_filho(i));
		}
		return 0; //caso nao ache a chave
	}

	/**
	 * Metodo que inicia a insercao da chave na arvore-B
	 * @param ch chave para reazliacar a insercao
	 */
	bool inserir(Chave ch)
	{
		No* no;
		no = new No;
		no->iniciaNo(nChaves);

		No* pai;
		pai = new No;
		pai->iniciaNo(nChaves);

		int i;

		// verificar se existe uma raiz para a arvore
		if (objArqB.getRaiz() != 0)
		{
			*pai = *no = objArqB.carregaNo(objArqB.getRaiz());
			pai = no;
		}
		while (no->getNChaves() !=0)
		{
			pai = no;
			i = 0;
			while (i < no->getNChaves() && (no->getRA(i) < ch.getRA()))
				++i;
			/*
			 * Caso a chave seja igual ao elemento do vetor e
			 * o contador i ainda pertenca ao intervalo de elementos
			 * retornamos false
			 */
			if (no->getRA(i) == ch.getRA() && i < no->getNChaves())
				return false;
			else
			{
				No* auxFilho;
				auxFilho = new No;
				*auxFilho = objArqB.carregaNo(no->get_filho(i));

				no = auxFilho;
			}
		}

		no = pai;
		// Continua a insercao apos encontrar o nodo
		// relativo a essa chave
		insere(ch, no);

		return true;
	}

	/**
	 * Metodo que retorna o endereco do no no arquivo da arvore B para futura remocao.
	 * @param ch RA desejado.
	 * @return retorna o endereco do no que contem o RA como parametro.
	 */

	long buscarRemover(int ch)
	{
		No no = objArqB.carregaNo(objArqB.getRaiz());

		int i;

		while (no.getNChaves() != 0)
		{
			i = 0;
			while (i < no.getNChaves() && (no.getRA(i) < ch))
				++i;
			if (no.getRA(i) == ch)
				return no.get_pos();
			else
				no = objArqB.carregaNo(no.get_filho(i));
		}
		return -1L;
	}

	/**
	 * Metodo que realiza a remocao de nodo em uma determinada posicao
	 * @param	ch posicao do nodo referente ao arquivo
	 */ 
	void remover(int ch)
	{
		No no1 = objArqB.carregaNo(this->buscarRemover(ch));

		No no = objArqB.carregaNo(objArqB.getRaiz());

		int i;
		int j;
		bool achou = false;
		while (no.getNChaves() != 0 && !achou)
		{
			i = 0;
			while (i < no.getNChaves() && (no.getRA(i) < ch))
				++i;
			if (no.getRA(i) == ch)
				achou = true;
			else
				no = objArqB.carregaNo(no.get_filho(i));
		}

		if (no.getNChaves() != 0)
		{

			if (no.get_filho(i + 1) != (long int) NULL)
			{
				//no recebe filho da direita
				no = objArqB.carregaNo(no.get_filho(i + 1));
				No noTemp = no;
				No noTemp2 = no;
				while (noTemp.getNChaves() != 0)
				{
					//no recebe todos os filhos da esquerda ate o ultimo
					noTemp = objArqB.carregaNo(no.get_filho(0));
					if (noTemp.getNChaves() != 0)
						no = noTemp;
				}

				//troca efetuada
				no1.setRA(no.getRA(0), i);
				no1.setRegistro(no.getRegistro(0), i);
				objArqB.escreveNo(&no1);

				//se so foi para direita
				if (noTemp2 == no)
				{

					//esta com apenas um elemento que sera excluido
					if (no.getNChaves() - 1 == 0)
					{
						//se nao existem filhos e o no so tem um elemento
						No temp4 = objArqB.carregaNo(no.get_pai());
						int p = 0;

						while (temp4.getRA(p) != no.getRA(0) && p
								< temp4.getNChaves())
							p++;

						temp4.set_filho((long int) NULL, p + 1);
						objArqB.escreveNo(&temp4);
						objArqB.setListaDisp(no.get_pos());
					}
					else
					{
						//mais de um elemento retira o ch e move os da direita um para esquerda
						j = 0;
						while (no.getRA(j) < ch)
							j++;

						for (; j <= no.getNChaves(); j++)
						{
							no.setRA(no.getRA(j + 1), j);
							no.setRegistro(no.getRegistro(j + 1), j);
						}
						no.setNChaves(no.getNChaves() - 1);
						objArqB.escreveNo(&no);
					}
				}
				else
				{ //andou para esquerda

					//esta com apenas um elemento
					if (no.getNChaves() - 1 == 0)
					{
						//zera o primeiro ponteiro do pai
						No temp4 = objArqB.carregaNo(no.get_pai());
						temp4.set_filho((long int) NULL, 0);
						objArqB.escreveNo(&temp4);
						objArqB.setListaDisp(no.get_pos());

					}
					else
					{ //mais de um elemento
						//mais de um elemento retira o ch e move os da direita um para esquerda
						j = 0;
						while (no.getRA(j) < ch)
							j++;

						for (; j <= no.getNChaves(); j++)
						{
							no.setRA(no.getRA(j + 1), j);
							no.setRegistro(no.getRegistro(j + 1), j);
						}
						no.setNChaves(no.getNChaves() - 1);
						objArqB.escreveNo(&no);
					}
				}
			}
			else
			{
				if (no.getNChaves() - 1 == 0)
				{
					//se nao existem filhos e o no so tem um elemento
					No temp4 = objArqB.carregaNo(no.get_pai());
					int p = 0;
					if (ch > temp4.getRA(p))
					{
						while (temp4.getRA(p) < ch && p < temp4.getNChaves())
							p++;
					}
					temp4.set_filho((long int) NULL, p);
					objArqB.escreveNo(&temp4);
					objArqB.setListaDisp(no.get_pos());
				}
				else
				{
					//se nao existem filhos e o no tem mais de um elemento
					//mais de um elemento retira o ch e move os da direita um para esquerda
					j = 0;
					while (no.getRA(j) < ch)
						j++;

					for (; j <= no.getNChaves(); j++)
					{
						no.setRA(no.getRA(j + 1), j);
						no.setRegistro(no.getRegistro(j + 1), j);
					}
					no.setNChaves(no.getNChaves() - 1);
					objArqB.escreveNo(&no);
				}
			}
		}
	}

};

#endif /*ARVOREB_H_*/
