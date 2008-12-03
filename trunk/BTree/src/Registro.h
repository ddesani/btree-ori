using namespace std;

class Registro
{
public:
	//variaveis char do registro
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
	
	//variaveis que gardam o tamanho dos char do registro
	int tamanhoNome;
	int tamanhoRG;
	int tamanhoCPF;
	int tamanhoRA;
	int tamanhoCidade;
	int tamanhoRua;
	int tamanhoNumero;
	int tamanhoCEP;
	int tamanhoUF;
	int tamanhoTelefone;
	int tamanhoRua2;
	int tamanhoNumero2;
	int tamanhoCEP2;
	int tamanhoTelefone2;
	int tamanhoCurso;
	int tamanhoAnoIngresso;

	Registro() {
		//inicializa as variaveis tamanho
		tamanhoNome = 40;
		tamanhoRG = 10;
		tamanhoCPF = 12;
		tamanhoRA = 7;
		tamanhoCidade = 20;
		tamanhoRua = 35;
		tamanhoNumero = 5;
		tamanhoCEP = 9;
		tamanhoUF = 3;
		tamanhoTelefone = 11;
		tamanhoRua2 = 35;
		tamanhoNumero2 = 5;
		tamanhoCEP2 = 9;
		tamanhoTelefone2 = 11;
		tamanhoCurso = 25;
		tamanhoAnoIngresso = 4;
	}
	
	//retorna o RA (cast para inteiro)
	int getRA()
	{
		return atoi(RA);
	}

	//metodo para ajuste dos campos do registro
	void ajusta()
	{
		ajusta(nome, 40);
		ajusta(RG, 10);
		ajusta(CPF, 12);
		ajusta(RA, 7);
		ajusta(cidade, 20);
		ajusta(rua, 25);
		ajusta(numero, 5);
		ajusta(CEP, 9);
		ajusta(UF, 3);
		ajusta(telefone, 11);
		ajusta(rua2, 35);
		ajusta(numero2, 5);
		ajusta(CEP2, 9);
		ajusta(telefone2, 11);
		ajusta(curso, 25);
		ajusta(anoIngresso, 5);

	}

	//metodo para impressao dos dados de um registro
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
		cout << "Rua S: " << rua2<< endl;
		cout << "Numero S: " << numero2 << endl;
		cout << "CEP S: " << CEP2 << endl;
		cout << "Telefone S: " << telefone2 << endl;
		cout << "Curso: " << curso << endl;
		cout << "Ano Ingresso: " << anoIngresso << endl;
		cout << endl;
	}

private:

	/* metodo para ajustar os dados do arquivo de dados
	 * ele separa por variaveis cada um dos campos
	 */
	char* ajusta(char* var, int n)
	{
		char* aux = new char [n-1];

		for (int i=0; i<(n-1); ++i)
			aux[i] = var[i];
		//strncpy(aux,var,n-1);

		strcpy(var, aux);

		for (int i=0; i<(n-1); ++i)
			aux[i] = '\0';

		delete[] aux;

		return var;
	}

};
