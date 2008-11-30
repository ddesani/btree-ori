using namespace std;

class Registro
{
public:
	char nome[40];
	char RG[10];
	char CPF[12];
	char RA[7];
	char cidade[20];
	char rua[35];
	char numero[5];
	char CEP[9];
	char UF[3];
	char telefone[11];
	char rua2[35];
	char numero2[5];
	char CEP2[9];
	char telefone2[11];
	char curso[25];
	char anoIngresso[4];
	//char	reg[232];
		
public:
	
	
	int getRA()
	{
		return atoi(ajusta(RA,7));
	}
	
	char* ajusta(char* var, int n)
	{
		char* aux = new char [n-1];
		
		
		for(int i=0; i<(n-1); ++i)
			aux[i] = var[i];
		//strncpy(aux,var,n-1);
		
		strcpy(var,aux);
		
		for(int i=0; i<(n-1); ++i)
			aux[i] = '\0';
		
		delete[] aux;

		return var;
	}
	
	void imprime()
	{
		cout << endl;
		cout << "Registro de Alunos" << endl;
		cout << "Nome: " << ajusta(nome,40) << endl;
		cout << "RG: " << ajusta(RG,10) << endl;
		cout << "CPF: " << ajusta(CPF,12) << endl;
		cout << "RA: " << ajusta(RA,7) << endl;
		cout << "Cidade: " << ajusta(cidade,20) << endl;
		cout << "Rua: " << ajusta(rua,25) << endl;
		cout << "Numero: " << ajusta(numero,5) << endl;
		cout << "CEP: " << ajusta(CEP,9) << endl;
		cout << "UF: " << ajusta(UF,3) << endl;
		cout << "Telefone: " << ajusta(telefone,11) << endl;
		cout << "Rua S: " << ajusta(rua2,35) << endl;
		cout << "Numero S: " << ajusta(numero2,5) << endl;
		cout << "CEP S: " << ajusta(CEP2,9) << endl;
		cout << "Telefone S: " << ajusta(telefone2,11) << endl;
		cout << "Curso: " << ajusta(curso,25) << endl;
		cout << "Ano Ingresso: " << ajusta(anoIngresso,5) << endl;
		cout << endl;
	}
	void imprime2()
	{
		cout << endl;
		cout << "Registro de Alunos" << endl;
		cout << "Nome: " << nome << endl;
		cout << "RG: " << RG << endl;
		cout << "CPF: " << CPF << endl;
		cout << "RA: " << RA << endl;
		cout << "Cidade: " << cidade << endl;
		cout << "Rua: " << rua << endl;
		cout << "Numero: " << numero << endl;
		cout << "CEP: " << CEP << endl;
		cout << "UF: " << UF << endl;
		cout << "Telefone: " << telefone << endl;
		cout << "Rua S: " << rua2<< endl;
		cout << "Numero S: " << numero2 << endl;
		cout << "CEP S: " << CEP2 << endl;
		cout << "Telefone S: " << telefone2 << endl;
		cout << "Curso: " << curso << endl;
		cout << "Ano Ingresso: " << anoIngresso << endl;
		cout << endl;
	}

	
};
