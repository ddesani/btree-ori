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
	
		
public:
	int getRA()
	{
		return atoi(RA);
	}
	
	
	void imprime()
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
		cout << "Rua S: " << rua2 << endl;
		cout << "Numero S: " << numero2 << endl;
		cout << "CEP S: " << CEP2 << endl;
		cout << "Telefone S: " << telefone2 << endl;
		cout << "Curso: " << curso << endl;
		cout << "Ano Ingresso: " << anoIngresso << endl;
	}
};

