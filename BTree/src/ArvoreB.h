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
		objArqB.setCabecalho(n+1);
		//objArqB.open();
		nChaves = n;
		//objArqB.setCabecalho(nChaves + 1); // recebe o numero de elementos +1 == ordem
		lista = new Chave[n+1]; //lista para a ordenacao das chaves do No
		_listaPtr = new long[n+2];
		nosMinimos = n / 2; //quantidade minima de No`s
		_raiz = 0;

	}
	Btree()
	{

		//fB.open("btree.txt");
		if (!objArqB.open())
		{
			int ordem = objArqB.getOrdem();

			_raiz = objArqB.getRaiz(); //obtem o endereco da raiz no cabecalho
			_endListaDispo = objArqB.getListaDisp();

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
			if (no->getNChaves() == 0)
			{
				no = new No;
				no->iniciaNo(nChaves);
				no->setNChaves(0);
			}
			if (no->get_pai() != 0)
				*_pai = objArqB.carregaNo(no->get_pai());

			if (no->getNChaves() == nChaves)
			{ // overflow
				// no direito
				novo = new No;
				novo->iniciaNo(nChaves);
				// Constroi lista ordenada
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
				no->setNChaves(nChaves/2);
				objArqB.escreveNo(no);
				for (j = 0; j < no->getNChaves(); j++)
				{
					no->setChave(lista[j], j);
					no->set_filho(_listaPtr[j], j);
				}
				no->set_filho(_listaPtr[no->getNChaves()], no->getNChaves());

				// No direito
				novo->setNChaves(nChaves - no->getNChaves());
				for (j = 0; j < novo->getNChaves(); j++)
				{
					novo->setChave(lista[j+(nChaves/2)+1], j);
					novo->set_filho(_listaPtr[j+(nChaves/2)+1], j);
				}
				novo->set_filho(_listaPtr[nChaves+1], novo->getNChaves());

				for (j = 0; j <= no->getNChaves(); j++)
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

				ch = lista[nChaves/2];
				*_filho1 = objArqB.carregaNo(no->get_pos());
				_filho2 = novo;
				objArqB.escreveNo(_filho2);
				//*_filho2 = objArqB.carregaNo(novo->get_pos());
				no = _pai;
				//*no = objArqB.carregaNo(_pai->get_pos());
			}
			else //numero de Chaves != no->chaves
			{
				// Insere nova chave em seu lugar
				i = 0;
				if (no->getNChaves() > 0)
				{
					while (no->getRA(i) < ch.getRA() && i < no->getNChaves())
						i++;

					for (j = no->getNChaves(); j > i; j--)
						no->setChave(no->getChave(j-1), j);

					for (j = no->getNChaves()+1; j > i; j--)
						no->set_filho(no->get_filho(j-1), j);
				}
				no->setNChaves(no->getNChaves()+1);
				no->setChave(ch, i);
				no->set_filho(_filho1->get_pos(), i);
				no->set_filho(_filho2->get_pos(), i+1);

				objArqB.escreveNo(no);
				if (objArqB.getRaiz() != no->get_pai())
				{
					_raiz = no->get_pos();
					objArqB.setRaiz(_raiz);
				}
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

	void imprimir(No no)
	{
		int i;

		if (no.getNChaves() == 0)
			return;
		for (i = 0; i < no.getNChaves()-1; i++)
			cout << no.getRA(i) << "-";
		if (no.getNChaves())
			cout << no.getRA(i) << " [";
		if (no.get_pai())
		{
			No auxPai = objArqB.carregaNo(no.get_pai());
			cout << auxPai.getRA(0);
		}
		else
			cout << "*";
		cout << "]" << endl;
		for (i = 0; i <= no.getNChaves(); i++)
			imprimir(objArqB.carregaNo(no.get_filho(i)));
	}

	long buscar(int ch)
	{
		No no = objArqB.carregaNo(objArqB.getRaiz());

		int i;

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
		return 0; //tratar o retorno 0 caso nao ache o valor
	}

	bool inserir(Chave ch)
	{
		No* no2;
		no2 = new No;
		no2->iniciaNo(nChaves);
		No* pai;
		pai = new No;
		pai->iniciaNo(nChaves);

		int i;

		// verificar se existe uma raiz para a arvore
		if (objArqB.getRaiz() != 0)
		{
			*pai = *no2 = objArqB.carregaNo(objArqB.getRaiz());
			pai = no2;
		}
		while (no2->getNChaves() !=0)
		{
			pai = no2;
			i = 0;
			while (i < no2->getNChaves() && (no2->getRA(i) < ch.getRA()))
				i++;
			/* 
			 * Caso a chave seja igual ao elemento do vetor e
			 * o contador i ainda pertence ao intervalo de elementos
			 * eh retornado false
			 */
			if (no2->getRA(i) == ch.getRA() && i < no2->getNChaves())
				return false; //chave existente
			else
			{
				No* auxFilho;
				auxFilho = new No;
				*auxFilho = objArqB.carregaNo(no2->get_filho(i));
				no2 = auxFilho;
			}
		}
		no2 = pai;
		insere(ch, no2, NULL, NULL); // parametros filho1 e filho2 sao null
		// para inicializar o novo no
		return true;
	}

	void mostrar()
	{
		cout << "Arvore B" << endl;
		imprimir(*raiz);
		cout << "##################" << endl;
	}
};

#endif /*ARVOREB_H_*/
