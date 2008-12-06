#ifndef CHAVE_H_
#define CHAVE_H_

using namespace std;

// definicao da struct key
class Chave
{
private:
	long registro; // posicao da chave no vetor de registros
	int valor; // valor da chave
public:
	
	long getRegistro()
	{
		return registro;
	}
	
	void setRegistro(long reg)
	{    
		registro = reg;
	}
	
	int getValor()
	{
		return valor;
	}
	
	void setValor(int val)
	{
		valor = val;
	}
	
};

#endif /*CHAVE_H_*/
