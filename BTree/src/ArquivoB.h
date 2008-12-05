#ifndef ARQUIVOB_H_
#define ARQUIVOB_H_
using namespace std;

class ArquivoB
{
private:
	string filename;
	fstream fB;

public:

	/*
	 * Ctor para ArquivoB
	 * 	inicializa filename
	 */
	ArquivoB()
	{
		filename = "";

	}

	/*
	 * Dtor para ArquivoB
	 * 	fecha o arquivo caso este esteja aberto
	 */
	~ArquivoB()
	{
		if (fB.is_open())
			fB.close();
	}

	/*
	 * Metodo para abertura do arquivo
	 * 	retorna 
	 */

	void setCabecalho(int n)
	{
		if (fB.is_open())
		{
			fB.seekg(0);
			fB << 'I' << '.' << n << '.' << 0 << '.' << 0 << '\xa';
		}
	}

	bool open()
	{
		if (filename.size() > 0 && !fB.is_open())
			fB.open(filename.c_str());

		return fB.is_open();
	}

	/*
	 * Metodo para inicializar filename
	 */
	void setFileName(string nome)
	{
		filename = nome;
	}

	/*
	 * Metodo para obter filename
	 */
	string getFileName()
	{
		return filename;
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
		if (posicao != 0) //ver o limite para a posicao de acordo com o cabecalho
		{
			int i=0;
			char a[1];
			long end;
			int nChavesNo;
			fB.clear();
			fB.seekg(posicao, ios::beg);
			fB >> nChavesNo;
			fB.clear();
			fB.seekg(posicao, ios::beg);

			do
			{
				fB >> a[0];

				if (a[0] == '.')
					i++;
			} while (i != 3*nChavesNo);

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

	void setNumeroChavesN(long posicao)
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

		fB.flush();
		fB.seekg(2, ios::beg);
		fB >> ordem;
		cout << fB.tellg();

		return ordem;
	}

	int getEndRaizC()
	{
		int endRaiz;

		fB.seekg(4, ios::beg);
		fB >> endRaiz;

		return endRaiz;
	}
	
	void setRaiz(int endRaiz)
	{
		if (fB.is_open())
		{
			fB.seekp(4, ios::beg);
			fB << endRaiz;
		}
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
	void escreveNo(No* no, int nChaves)
	{
		int endRaiz;
		int pos;

		fB.seekp(0, ios::end);

		pos = fB.tellp();

		fB << no->getNChaves() << '.';
		for (int i=0; i<nChaves; ++i)
			fB << no->chave[0].valor << '.';

		for (int i=0; i<nChaves; ++i)
			fB << no->chave[0].registro << '.';

		fB << no->pai << '.';
		for (int i = 0; i<= nChaves; ++i)
			//escreve n+1 (ordem) ponteiros
			fB << no->filho[i] << '.';

		fB << '\xa'; // termina o nodo com \xa

		endRaiz = getEndRaizC();

		if (endRaiz == 0)
		{
			fB.seekp(4);
			fB << pos;
		}

	}

	No carregaNo(long posicao, int nChaves)
	{
		No aux(nChaves);
		if (posicao != 0)
		{

			aux.nChaves = getNumeroChavesN(posicao);
			for (int i=0; i<nChaves; ++i)
				aux.chave[i].valor = getRaN(posicao, i);

			for (int j=0; j<nChaves; ++j)
				aux.chave[j].registro = getEndN(posicao, j);

			aux.set_pai(getPaiN(posicao));

			for (int k=0; k<nChaves+1; ++k)
				aux.set_filho(getFilhoN(posicao, k), k);
			aux.set_pos(posicao);
		}

		return aux;
	}

	void escreveNo2(No* no)
	{
		int endRaiz;
		int pos;

		if (no->get_pos() == 0)
		{
			fB.clear();
			fB.seekp(no->get_pos(), ios::end);

			pos = fB.tellp();
			endRaiz = getEndRaizC();

			if (endRaiz == 0) //atualizando o end da raiz
			{

				fB.seekp(4);
				fB << pos;
				fB.seekp(0, ios::end);
			}

			fB << no->getNChaves() << '.';
			for (int i=0; i<no->getNChaves(); ++i)
				fB << no->chave[i].valor << '.';

			for (int i=0; i<no->getNChaves(); ++i)
				fB << no->chave[i].registro << '.';

			fB << no->_pai << '.';
			for (int i = 0; i<= no->getNChaves(); ++i)
				fB << no->_filho[i] << '.'; //escreve n+1 (ordem) ponteiros


			fB << '\xa'; // termina o nodo com \xa

			/*endRaiz = getEndRaizC();

			 if (endRaiz == 0)
			 {
			 fB.seekp(4);
			 fB << pos;
			 }*/

		}

	}

};

#endif /*ARQUIVOB_H_*/
