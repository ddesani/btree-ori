#ifndef ARVOREB_H_
#define ARVOREB_H_

using namespace std;

// definicao da struct key
struct Chave
{
	long registro; // posicao da chave no vetor de registros
	char valor; // valor da chave
};

// declaração da classe No
class No
{
public:
	int nChaves; // numero de chaves armazenadas na pagina
	Chave *chave; // vetor de chaves do no
	No **filho; // vetor de ponteiros para os nos filhos    
	No *pai; // ponteiro para o no pai

public:
	No(int); // construtor
	~No(); // destrutor

	friend class BTree;
};

typedef No *pontno;

No::No(int n)
{
	nChaves = 0;
	chave = new Chave[n];
	filho = new pontno[n+1];
	pai = NULL;
}

No::~No()
{
	delete[] chave;
	delete[] filho;
}

class Btree
{
public:
	Chave *lista;
	pontno *listaPtr;
	pontno raiz;
	int nChaves, nosMinimos;
	void insere(Chave ch, pontno no, pontno filho1, pontno filho2);
	void passarChDir(pontno dir, pontno pai, pontno no, int posChPai);
	void passarChEsq(pontno esq, pontno pai, pontno no, int posChPai);
	void imprimir(pontno no);
public:
	Btree(int); // construtor
	~Btree(); // destrutor
	long buscar(char); // busca
	bool inserir(Chave); // insercao
	void mostrar();
};

Btree::Btree(int n)
{
	nChaves = n;
	lista = new Chave[n+1];
	listaPtr = new pontno[n+2];
	nosMinimos = n / 2;
	raiz = NULL;
}

Btree::~Btree()
{
	delete[] lista;
	delete[] listaPtr;
}

void Btree::mostrar()
{
	cout << "Arvore B" << endl;
	imprimir(raiz);
	cout << "##################" << endl;
}

void Btree::imprimir(pontno no)
{
	int i;

	if (!no)
		return;
	for (i = 0; i < no->nChaves-1; i++)
		cout << no->chave[i].valor << "-";
	if (no->nChaves)
		cout << no->chave[i].valor << " [";
	if (no->pai)
		cout << (no->pai)->chave[0].valor;
	else
		cout << "*";
	cout << "]" << endl;
	for (i = 0; i <= no->nChaves; i++)
		imprimir(no->filho[i]);
}

long Btree::buscar(char ch)
{
	pontno no = raiz;
	int i;

	while (no)
	{
		i = 0;
		while (i < no->nChaves && (no->chave[i].valor < ch))
			i++;
		if (no->chave[i].valor == ch)
			return no->chave[i].registro;
		else
			no = no->filho[i];
	}
	return -1L;
}

bool Btree::inserir(Chave ch)
{
	pontno no, pai;
	int i;

	// verificar se a chave nao esta na arvore
	pai = no = raiz;
	while (no)
	{
		pai = no;
		i = 0;
		while (i < no->nChaves && (no->chave[i].valor < ch.valor))
			i++;
		/* 
		 * Caso a chave seja igual ao elemento do vetor e
		 * o contador i ainda pertence ao intervalo de elementos
		 * eh retornado false
		 */
		if (no->chave[i].valor == ch.valor && i < no->nChaves)
			return false; //chave existente
		else
			no = no->filho[i];
	}
	no = pai;
	insere(ch, no, NULL, NULL); // parametros filho1 e filho2 sao null
								// para inicializar o novo no
	return true;
}

void Btree::insere(Chave ch, pontno no, pontno filho1, pontno filho2)
{
	pontno pai, novo;
	int i, j;
	bool sair = false;

	// inserir nova chave no no
	do
	{
		if (!no)
		{
			no = new No(nChaves);
			no->nChaves = 0;
			no->pai = NULL;
			raiz = no;
		}
		pai = no->pai;
		if (no->nChaves == nChaves)
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
			no->nChaves = nChaves/2;
			for (j = 0; j < no->nChaves; j++)
			{
				no->chave[j] = lista[j];
				no->filho[j] = listaPtr[j];
			}
			no->filho[no->nChaves] = listaPtr[no->nChaves];

			// No direito
			novo->nChaves = nChaves - no->nChaves;
			for (j = 0; j < novo->nChaves; j++)
			{
				novo->chave[j] = lista[j+(nChaves/2)+1];
				novo->filho[j] = listaPtr[j+(nChaves/2)+1];
			}
			novo->filho[novo->nChaves] = listaPtr[nChaves+1];

			for (j = 0; j <= no->nChaves; j++)
				if (no->filho[j])
					(no->filho[j])->pai = no;

			for (j = 0; j <= novo->nChaves; j++)
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
			if (no->nChaves > 0)
			{
				while (no->chave[i].valor < ch.valor && i < no->nChaves)
					i++;

				for (j = no->nChaves; j > i; j--)
					no->chave[j] = no->chave[j-1];

				for (j = no->nChaves+1; j > i; j--)
					no->filho[j] = no->filho[j-1];
			}
			no->nChaves++;
			no->chave[i] = ch;
			no->filho[i] = filho1;
			no->filho[i+1] = filho2;
			if (filho1)
				filho1->pai = no;
			if (filho2)
				filho2->pai = no;
			sair = true;
		}
	} while (!sair);
}

void Btree::passarChDir(pontno dir, pontno pai, pontno no, int posChPai)
{
	int i;

	no->chave[no->nChaves] = pai->chave[posChPai];
	no->nChaves++;
	pai->chave[posChPai] = dir->chave[0];
	no->filho[no->nChaves] = dir->filho[0];
	if (dir->filho[0])
		dir->filho[0]->pai = no;
	for (i = 0; i < dir->nChaves; i++)
		dir->chave[i] = dir->chave[i+1];

	for (i = 0; i <= dir->nChaves; i++)
		dir->filho[i] = dir->filho[i+1];

	dir->nChaves--;
}

void Btree::passarChEsq(pontno esq, pontno pai, pontno no, int posChPai)
{
	int i;

	for (i = no->nChaves; i > 0; i--)
		no->chave[i] = no->chave[i-1];

	for (i = no->nChaves+1; i > 0; i--)
		no->filho[i] = no->filho[i-1];

	no->nChaves++;
	no->chave[0] = pai->chave[posChPai];
	pai->chave[posChPai] = esq->chave[esq->nChaves-1];
	no->filho[0] = esq->filho[esq->nChaves];
	if (no->filho[0])
		no->filho[0]->pai = no;
	esq->nChaves--;
}

#endif /*ARVOREB_H_*/
