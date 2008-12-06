#ifndef NO_H_
#define NO_H_
using namespace std;
// declaração da classe No
class No
{
private:
	int nChaves; // numero de chaves armazenadas na pagina
	Chave *chave; // vetor de chaves do no 
	No **filho; // vetor de ponteiros para os nos filhos    
	No *pai; // ponteiro para o no pai

	/**
	 * Endereco do Nodo
	 */
	long endereco;

	long _pos;
	long _pai;
	long* _filho;

public:
	No()
	{
		nChaves = 0;
		_pos = 0;
		_pai = 0;

	}

	void iniciaNo(int n)
	{
		chave = new Chave[n];
		_filho = new long[n+1];
	}

	void set_pai(long end)
	{
		_pai = end;
	}

	long get_pai()
	{
		return _pai;
	}

	void setRA(int ra, int indice)
	{
		chave[indice].setRA(ra);
	}

	int getRA(int indice)
	{
		return chave[indice].getRA();
	}

	void setRegistro(long endereco, int indice)
	{
		chave[indice].setRegistro(endereco);
	}

	long getRegistro(int indice)
	{
		return chave[indice].getRegistro();
	}

	void set_filho(long valor, int indice)
	{
		_filho[indice] = valor;
	}

	long get_filho(int indice)
	{
		return _filho[indice];
	}

	void set_pos(long posicao)
	{
		_pos = posicao;
	}

	long get_pos()
	{
		return _pos;
	}

	Chave getChave(int indice)
	{
		Chave aux;

		aux.setRA(getRA(indice));
		aux.setRegistro(getRegistro(indice));

		return aux;
	}

	void	setChave(Chave ch, int indice)
	{
		setRA(ch.getRA(),indice);
		setRegistro(ch.getRegistro(),indice);
	}
	
	int getNChaves()
	{
		return nChaves;
	}
	void setNChaves(int valor)
	{
		nChaves = valor;
	}

	~No()
	{
		/*delete[] chave;
		 delete[] filho;*/
	}

	friend class BTree;
};

#endif /*NO_H_*/
