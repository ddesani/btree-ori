#include <iostream>
#include <fstream>
#include <sstream>
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
	
	//a.escreverCabecalhoDisp(11111);
	
	a.removerRegistro(242*4);
	/*unsigned long x;
	char y[11] = {'1','1','1','1','1','1','1','1','1','1','1'};
	
	x = atol(y);
	cout << x;*/

	cout << endl << "Fim " << endl;
	return 0;
}
