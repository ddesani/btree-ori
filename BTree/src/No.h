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
	
	int _pai;
	int* _filho;
	
public:
	No(int n)
	{
		nChaves = 0;
		chave = new Chave[n];
		filho = new No*[n+1];
		pai = NULL;
		
		_pai = 0;
		_filho = new int[n+1];
		
	}
	
	void set_pai(int end)
	{
		_pai = end;
	}

	int	get_pai()
	{
		return _pai;
	}
	
	void set_filho(int valor, int pos)
	{
		_filho[pos] = valor;
	}
	
	int get_filho(int posicao)
	{
		return _filho[posicao];
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
