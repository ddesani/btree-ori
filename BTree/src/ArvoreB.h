#ifndef ARVOREB_H_
#define ARVOREB_H_

using namespace std;

typedef No *pontno;

class Btree
{
public:
	fstream fB;
	Chave *lista;
	pontno *listaPtr;
	pontno raiz;
	int nChaves, nosMinimos;

	long	_raiz;
	long	_endListaDispo;
	
	Btree(int n)
	{
		fB.open("btree.txt");
		fB.seekg(0);
		//fB << 'I' << '.' << n +1 << '.' << 0 << '.' << 0 << '\xa';

		nChaves = n;
		lista = new Chave[n+1]; //lista para a ordenacao das chaves do No
		listaPtr = new pontno[n+2]; //lista de ponteiros para os No`s filhos
		nosMinimos = n / 2; //quantidade minima de No`s
		raiz = NULL;

		_raiz = 0;
		
		//cout << getRaN(8,0);
		
		carregaNo(8);
		
	}
	Btree()
	{
		
		
		fB.open("btree.txt");
		if (fB.is_open())
		{
			int ordem = getOrdemC();
			
			_raiz = getEndRaizC(); //obtem o endereco da raiz no cabecalho
			_endListaDispo = getEndListaC();
			
			lista = new Chave[ordem]; //lista para a ordenacao das chaves do No
			listaPtr = new pontno[ordem +1]; //lista de ponteiros para os No`s filhos
			
			nChaves =  ordem -1;
			nosMinimos = (ordem -1) / 2; //quantidade minima de No`s
			raiz = NULL;
			_raiz = 0;
		}

		/*//metodo para fazer a leitura do cabecalho
		nosMinimos = n / 2; //quantidade minima de No`s
		raiz = NULL;
		_raiz = 0;
		//objCabecalhoB.setOrdemB(n+1); //n+1 eh a ordem da arvore
			nChaves = objCabecalhoB.getOrdemB()-1;
		 lista = new Chave[objCabecalhoB.getOrdemB()];
		 listaPtr = new pontno[objCabecalhoB.getOrdemB() + 1];
		 nosMinimos = (objCabecalhoB.getOrdemB() -1) / 2;
		raiz = NULL;*/
	}

	/*
	 * Funcoes para obter o Nodo
	 */
	
	long getFilhoN(long posicao, int indice)
	{
		int ordem = getOrdemC();
		if (indice < ordem)
		{
			int i=0;
			char a[1];
			long end;
			fB.seekg(posicao, ios::beg);
			do
			{
				fB >> a[0];

				if (a[0] == '.')
					i++;
			} while (i != indice + 2*(ordem-1) + 2); //posicao inicial dos filhos no No

			fB >> end;

			return end;

		}
		else
			return -1; //mudar para 0 quando testar com registro.txt
	}
	
	
	long getPaiN(long posicao)
	{
		int ordem = getOrdemC();
		if (posicao != 0) //ver o limite para a posicao de acordo com o cabecalho
		{
			int i=0;
			char a[1];
			long end;
			fB.seekg(posicao, ios::beg);
			do
			{
				fB >> a[0];

				if (a[0] == '.')
					i++;
			} while (i != 2*(ordem -1) +1);

			fB >> end;

			return end;

		}
		else
			return -1; //mudar para 0 quando testar com registro.txt
	}

	long getEndN(long posicao, int indice)
	{
		int ordem = getOrdemC();
		if (indice < ordem -1)
		{
			int i=0;
			char a[1];
			long end;
			fB.seekg(posicao, ios::beg);
			do
			{
				fB >> a[0];

				if (a[0] == '.')
					i++;
			} while (i != indice + ordem);

			fB >> end;

			return end;

		}
		else
			return -1; //mudar para 0 quando testar com registro.txt
	}

	int getRaN(long posicao, int indice)
	{
		if (indice < getOrdemC() -1)
		{
			int i=0;
			char a[1];
			int ra;
			fB.seekg(posicao, ios::beg);
			do
			{
				fB >> a[0];

				if (a[0] == '.')
					i++;
			} while (i != indice+1);

			fB >> ra;

			return ra;

		}
		else
			return -1; //mudar para 0 quando testar com registro.txt
	}

	int getNumeroChavesN(long posicao)
	{
		int nChavesN =0;

		fB.seekg(posicao, ios::beg);
		fB >> nChavesN;

		return nChavesN;

	}

	void	setNumeroChavesN(long posicao)
	{
		int nChavesN =0;

		fB.seekp(posicao, ios::beg);
		fB << nChavesN;

	}
	
	
	/*
	 * Funcoes para obter o cabecalho
	 */

	char getIdC()
	{
		char id[1];

		fB.seekg(0, ios::beg);
		fB >> id[0];

		return id[0];
	}

	int getOrdemC()
	{
		int ordem;

		fB.seekg(2, ios::beg);
		fB >> ordem;

		return ordem;
	}

	int getEndRaizC()
	{
		int endRaiz;

		fB.seekg(4, ios::beg);
		fB >> endRaiz;

		return endRaiz;
	}

	int getEndListaC()
	{
		int endListaDispo;
		char a[1];
		fB.seekg(4, ios::beg);

		do
		{
			fB >> a[0];
		} while (a[0] != '.');

		fB >> endListaDispo;
		return endListaDispo;
	}

	
	
	~Btree()
	{
		fB.close();
		delete[] lista;
		delete[] listaPtr;

	}

	void leNo(int posicao)
	{

	}

	void escreveNo(pontno no)
	{
		int ordem;
		int endRaiz;
		int endLista;
		int pos;

		fB.seekp(0, ios::end);

		pos = fB.tellp();

		fB << no->getNChaves() << '.';
		for (int i=0; i<nChaves; ++i)
			fB << no->chave[0].valor << '.';

		for (int i=0; i<nChaves; ++i)
			fB << no->chave[0].registro << '.';

		fB << no->pai << '.';
		for (int i = 0; i<= nChaves; ++i) //escreve n+1 (ordem) ponteiros
			fB << no->filho[i] << '.';

		fB << '\xa'; // termina o nodo com \xa

		endRaiz = getEndRaizC();

		if (endRaiz == 0)
		{
			fB.seekp(4);
			fB << pos;
		}

	}

	void insere(Chave ch, pontno no, pontno filho1, pontno filho2)
	{
		pontno pai, novo;
		int i, j;
		bool sair = false;

		// inserir nova chave no no
		do
		{
			if (!no)
			{
				no = new No(nChaves); //** cria a raiz
				no->setNChaves(0);
				no->pai = NULL;
				raiz = no;
			}
			pai = no->pai;
			if (no->getNChaves() == nChaves)
			{ // overflow
				// no direito
				novo = new No(nChaves);
				// Constroi lista ordenada
				i = 0;
				while (no->chave[i].valor < ch.valor && i < nChaves)
				{
					lista[i] = no->chave[i];
					listaPtr[i] = no->filho[i];
					i++;
				}
				lista[i] = ch;
				listaPtr[i] = filho1;
				listaPtr[i+1] = filho2;
				while (i < nChaves)
				{
					lista[i+1] = no->chave[i];
					listaPtr[i+2] = no->filho[i+1];
					i++;
				}
				// Dividir nos
				// No esquerdo
				no->setNChaves(nChaves/2);
				for (j = 0; j < no->getNChaves(); j++)
				{
					no->chave[j] = lista[j];
					no->filho[j] = listaPtr[j];
				}
				no->filho[no->getNChaves()] = listaPtr[no->getNChaves()];

				// No direito
				novo->setNChaves(nChaves - no->getNChaves());
				for (j = 0; j < novo->getNChaves(); j++)
				{
					novo->chave[j] = lista[j+(nChaves/2)+1];
					novo->filho[j] = listaPtr[j+(nChaves/2)+1];
				}
				novo->filho[novo->getNChaves()] = listaPtr[nChaves+1];

				for (j = 0; j <= no->getNChaves(); j++)
					if (no->filho[j])
						(no->filho[j])->pai = no;

				for (j = 0; j <= novo->getNChaves(); j++)
					if (novo->filho[j])
						(novo->filho[j])->pai = novo;

				ch = lista[nChaves/2];
				filho1 = no;
				filho2 = novo;
				no = pai;
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
						no->filho[j] = no->filho[j-1];
				}
				no->setNChaves(no->getNChaves()+1);
				no->chave[i] = ch;
				no->filho[i] = filho1;
				no->filho[i+1] = filho2;
				if (filho1)
					filho1->pai = no;
				if (filho2)
					filho2->pai = no;
				escreveNo(no);
				sair = true;
			}
		} while (!sair);
	}
	void imprimir(pontno no)
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

public:

	No	carregaNo(long posicao)
	{
		No	aux(nChaves);
		if(posicao != 0)
		{
			
			
			aux.nChaves = getNumeroChavesN(posicao);
			for(int i=0; i<nChaves; ++i)
				aux.chave[i].valor = getRaN(posicao,i);
			
			for(int j=0; j<nChaves; ++j)
				aux.chave[j].registro = getEndN(posicao,j);
			
			aux.set_pai(getPaiN(posicao)); 
			
			for(int k=0; k<nChaves+1; ++k)
				aux.set_filho(getFilhoN(posicao,k),k);
		}
		
		
		return	aux;
	}
	
	
	
	long buscar(char ch)
	{
		pontno no = raiz;
		
		
		//no->
		int i;

		while (no)
		{
			i = 0;
			while (i < no->getNChaves() && (no->chave[i].valor < ch))
				i++;
			if (no->chave[i].valor == ch)
				return no->chave[i].registro;
			else
				no = no->filho[i];
		}
		return -1L;
	}
	bool inserir(Chave ch)
	{
		pontno no, pai;
		int i;

		// verificar se a chave nao esta na arvore
		pai = no = raiz;
		while (no)
		{
			pai = no;
			i = 0;
			while (i < no->getNChaves() && (no->chave[i].valor < ch.valor))
				i++;
			/* 
			 * Caso a chave seja igual ao elemento do vetor e
			 * o contador i ainda pertence ao intervalo de elementos
			 * eh retornado false
			 */
			if (no->chave[i].valor == ch.valor && i < no->getNChaves())
				return false; //chave existente
			else
				no = no->filho[i];
		}
		no = pai;
		insere(ch, no, NULL, NULL); // parametros filho1 e filho2 sao null
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
