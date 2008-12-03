#ifndef NO_H_
#define NO_H_
using namespace std;
// declaração da classe No
class No
{
public:
	int nChaves; // numero de chaves armazenadas na pagina
	Chave *chave; // vetor de chaves do no 
	No **filho; // vetor de ponteiros para os nos filhos    
	No *pai; // ponteiro para o no pai
	long	_pos;
	
	long _pai;
	long* _filho;
	
public:
	No(int n)
	{
		nChaves = 0;
		chave = new Chave[n];
		filho = new No*[n+1];
		pai = NULL;
		
		_pai = 0;
		_filho = new long[n+1];
		
	}
	
	void set_pai(long end)
	{
		_pai = end;
	}

	long	get_pai()
	{
		return _pai;
	}
	
	void set_filho(long valor, int indice)
	{
		_filho[indice] = valor;
	}
	
	void set_pos(long posicao)
	{
		_pos = posicao;
	}
	
	long get_pos()
	{
		return _pos;
	}
	
	long get_filho(int indice)
	{
		return _filho[indice];
	}
	
	~No()
	{
		delete[] chave;
		delete[] filho;
	}
	
	int		getNChaves()
	{
		return nChaves;
	}
	void	setNChaves(int valor)
	{
		nChaves = valor;
	}
	
	
	friend class BTree;
};


#endif /*NO_H_*/
