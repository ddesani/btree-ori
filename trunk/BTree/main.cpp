#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "src/Chave.h"
#include "src/No.h"
#include "src/Registro.h"
#include "src/CabecalhoArquivo.h"
#include "src/Arquivo.h"
#include "src/ArvoreB.h"

int main()
{
	Btree arvore(3);
	Arquivo arq("registro.txt");
	int opcao=-1;
	int RA;
	
	while(opcao != 0)
	{
		cout << "Digite 1 para inserir" << endl;
		cout << "Digite 2 para buscar" << endl;
		cout << "Digite 3 para deletar" << endl;
		cout << "Digite 0 para sair;
		cin >> opcao;
		
		switch(opcao)
		{
			case 1:
				arq.inserirArq();
				break;
			case 2:
				cin >> RA;
				arq.buscar(RA);
				break;
			case 3:
				arq.removerRegistro();
			case 0:
				opcao = 0;
				break;
			default:
				cin << opcao;
				break;
				
		}
	}

	cout << endl << "Fim " << endl;
	return 0;
}
