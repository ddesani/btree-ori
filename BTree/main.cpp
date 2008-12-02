#include <iostream>
#include <fstream>
using namespace std;

#include "src/Registro.h"
#include "src/CabecalhoArquivo.h"
#include "src/Arquivo.h"
#include "src/ArvoreB.h"

int main()
{
/*	Btree arvore(3);
	Chave chave;
	
	for (int i = 0; i < 4; i++)
	{		
		cin >> chave.registro;
		cin >> chave.valor;
		arvore.inserir(chave);
	}

	arvore.mostrar();
*/
	
	Arquivo a("registro.txt");
	
	a.manipCabecalho();

	cout << endl << "Fim " << endl;
	return 0;
}
