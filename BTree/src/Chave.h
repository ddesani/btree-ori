#ifndef CHAVE_H_
#define CHAVE_H_

using namespace std;

// definicao da struct key
class Chave
{
private:
	long registro; // posicao da chave no vetor de registros
	int RA; // RA da chave
public:
	
	long getRegistro()
	{
		return registro;
	}
	
	void setRegistro(long reg)
	{    
		registro = reg;
	}
	
	int getRA()
	{
		return RA;
	}
	
	void setRA(int val)
	{
		RA = val;
	}
	
};

#endif /*CHAVE_H_*/
