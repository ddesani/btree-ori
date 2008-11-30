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
	int getRA(char* ra, int n)
	{
		return atoi(ajusta(ra,7));
	}
	
	char* ajusta(char* var, int n)
	{
		char* aux = new char [n-1];
		
		for(int i=0; i<n; ++i)
			aux[i] = '\0';
		
		for(int i=0; i<n-1; ++i)
			aux[i] = var[i];
		
		strcpy(var,aux);
		
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
		cout << "Ano Ingresso: " << anoIngresso << endl;
	}
};
