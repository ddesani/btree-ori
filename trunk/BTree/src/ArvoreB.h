#ifndef ARVOREB_H_
#define ARVOREB_H_

using namespace std;

//typedef No *pontno;

class Btree
{
public:
	//fstream fB;
	ArquivoB objArqB;
	
	
	Chave* lista;
	No** listaPtr;
	No* raiz;
	int nChaves, nosMinimos;

	long _raiz;
	long* _listaPtr;
	long _endListaDispo;

	Btree(int n)
	{
		
		objArqB.setFileName("btree.txt");
		objArqB.open();
		
		nChaves = n;
		objArqB.setCabecalho(nChaves + 1); // recebe o numero de elementos +1 == ordem
		
		lista = new Chave[n+1]; //lista para a ordenacao das chaves do No
		listaPtr = new No*[n+2]; //lista de ponteiros para os No`s filhos
		_listaPtr = new long[n+2];
		nosMinimos = n / 2; //quantidade minima de No`s
		raiz = NULL;

		_raiz = 0;

	}
	Btree()
	{

		//fB.open("btree.txt");
		if (!objArqB.open())
		{
			int ordem = objArqB.getOrdemC();

			_raiz = objArqB.getEndRaizC(); //obtem o endereco da raiz no cabecalho
			_endListaDispo = objArqB.getEndListaC();

			lista = new Chave[ordem]; //lista para a ordenacao das chaves do No
			listaPtr = new No*[ordem +1]; //lista de ponteiros para os No`s filhos

			nChaves = ordem -1;
			nosMinimos = (ordem -1) / 2; //quantidade minima de No`s
			raiz = NULL;
			_raiz = 0;
		}

	}

	

	~Btree()
	{
		//fB.close();
		delete[] lista;
		delete[] listaPtr;
		delete[] _listaPtr;

	}

	void insere(Chave ch, No* no, No* _filho1, No* _filho2)
	{
		No _pai(nChaves);
		No* novo;
		int i, j;
		bool sair = false;

		// inserir nova chave no no
		do
		{
			if (no->getNChaves() != 0)
			{
				no = new No(nChaves); //** cria a raiz
				no->setNChaves(0);
				no->_pai = 0;
				_raiz = no->get_pos();
				//setEndRaizC(_raiz);
				objArqB.setRaiz(_raiz);
				
			}
			if (no->get_pai() != 0)
				_pai = objArqB.carregaNo(no->get_pai(), nChaves);

			if (no->getNChaves() == nChaves)
			{ // overflow
				// no direito
				novo = new No(nChaves);
				// Constroi lista ordenada
				i = 0;
				while (no->chave[i].valor < ch.valor && i < nChaves)
				{
					lista[i] = no->chave[i];
					_listaPtr[i] = no->get_filho(i);
					++i;
				}
				lista[i] = ch;
				_listaPtr[i] = _filho1->get_pos();
				_listaPtr[i+1] = _filho2->get_pos();
				while (i < nChaves)
				{
					lista[i+1] = no->chave[i];
					_listaPtr[i+2] = no->get_filho(i+1);
					i++;
				}
				// Dividir nos
				// No esquerdo
				no->setNChaves(nChaves/2);
				for (j = 0; j < no->getNChaves(); j++)
				{
					no->chave[j] = lista[j];
					no->set_filho(_listaPtr[j], j);
				}
				no->set_filho(_listaPtr[no->getNChaves()], no->getNChaves());

				// No direito
				novo->setNChaves(nChaves - no->getNChaves());
				for (j = 0; j < novo->getNChaves(); j++)
				{
					novo->chave[j] = lista[j+(nChaves/2)+1];
					novo->set_filho(_listaPtr[j+(nChaves/2)+1], j);
				}
				novo->set_filho(_listaPtr[nChaves+1], novo->getNChaves());

				for (j = 0; j <= no->getNChaves(); j++)
					if (no->get_filho(j))
						(no->filho[j])->set_pai(no->get_pos());

				for (j = 0; j <= novo->getNChaves(); j++)
					if (novo->get_filho(j))
						(novo->filho[j])->set_pai(novo->get_pos());

				ch = lista[nChaves/2];
				*_filho1 = objArqB.carregaNo(no->get_pos(), nChaves);
				*_filho2 = objArqB.carregaNo(novo->get_pos(), nChaves);
				*no = objArqB.carregaNo(_pai.get_pos(), nChaves);
			}
			else //numero de Chaves != no->chaves
			{
				// Insere nova chave em seu lugar
				i = 0;
				if (no->getNChaves() > 0)
				{
					while (no->chave[i].valor < ch.valor && i
							< no->getNChaves())
						i++;

					for (j = no->getNChaves(); j > i; j--)
						no->chave[j] = no->chave[j-1];

					for (j = no->getNChaves()+1; j > i; j--)
						no->_filho[j] = no->_filho[j-1];
				}
				no->setNChaves(no->getNChaves()+1);
				no->chave[i] = ch;
				no->set_filho(_filho1->get_pos(), i);
				no->set_filho(_filho2->get_pos(), i+1);

				if (_filho1->nChaves != 0)
					_filho1->set_pai(no->get_pos());
				if (_filho2->nChaves !=0)
					_filho2->set_pai(no->get_pos());
				objArqB.escreveNo2(no);
				sair = true;
			}
		} while (!sair);
	}

	void imprimir(No* no)
	{
		int i;

		if (!no)
			return;
		for (i = 0; i < no->getNChaves()-1; i++)
			cout << no->chave[i].valor << "-";
		if (no->getNChaves())
			cout << no->chave[i].valor << " [";
		if (no->pai)
			cout << (no->pai)->chave[0].valor;
		else
			cout << "*";
		cout << "]" << endl;
		for (i = 0; i <= no->getNChaves(); i++)
			imprimir(no->filho[i]);
	}


	

	long buscar(int ch)
	{
		No no = objArqB.carregaNo(objArqB.getEndRaizC(), nChaves);

		int i;

		while (no.getNChaves() !=0)
		{
			i =0;
			while (i< no.getNChaves() && (no.chave[i].valor < ch))
				++i;
			if (no.chave[i].valor == ch)
				return no.chave[i].registro;
			else
				no = objArqB.carregaNo(no._filho[i], nChaves);
		}
		return 0; //tratar o retorno 0 caso nao ache o valor
	}


	bool inserir(Chave ch)
	{
		No no(nChaves);
		No pai(nChaves);

		int i;

		// verificar se existe uma raiz para a arvore
		if (objArqB.getEndRaizC() != 0)
			pai = no = objArqB.carregaNo(objArqB.getEndRaizC(), nChaves);
		while (no.getNChaves() !=0)
		{
			pai = no;
			i = 0;
			while (i < no.getNChaves() && (no.chave[i].valor < ch.valor))
				i++;
			/* 
			 * Caso a chave seja igual ao elemento do vetor e
			 * o contador i ainda pertence ao intervalo de elementos
			 * eh retornado false
			 */
			if (no.chave[i].valor == ch.valor && i < no.getNChaves())
				return false; //chave existente
			else
					no = objArqB.carregaNo(no.get_filho(i), nChaves);
		}
		no = pai;
		insere(ch, &no, NULL, NULL); // parametros filho1 e filho2 sao null
		// para inicializar o novo no
		return true;
	}

	void mostrar()
	{
		cout << "Arvore B" << endl;
		imprimir(raiz);
		cout << "##################" << endl;
	}
};

#endif /*ARVOREB_H_*/
