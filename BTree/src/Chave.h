#ifndef CHAVE_H_
#define CHAVE_H_

using namespace std;

// definicao da struct key
class Chave
{
private:
	/**
	 * variavel que guarda a posicao do registro no arquivo de dados
	 */
	long registro;

	/*
	 * variavel que guarda o RA da chave
	 */
	int RA;
public:

	/**
	 * Metodo que retorna a posicao do registro no arquivo de dados
	 * @return posicao do registro
	 */
	long getRegistro()
	{
		return registro;
	}

	/**
	 * Metodo que seta a posicao do registro no arquivo de dados
	 * @param reg valor que sera setado para registro
	 */
	void setRegistro(long reg)
	{
		registro = reg;
	}

	/**
	 * Metodo que retorna o RA
	 * @return retorna o RA
	 */
	int getRA()
	{
		return RA;
	}

	/**
	 * Metodo que seta o RA
	 * @param valor valor que sera setado em RA
	 */
	void setRA(int val)
	{
		RA = val;
	}

};

#endif /*CHAVE_H_*/
