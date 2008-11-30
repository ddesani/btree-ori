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


	int getRA()
	{
		return atoi(RA);
	}

	void ajustaI()
	{
		ajustaI(nome, 40);
		ajustaI(RG, 10);
		ajustaI(CPF, 12);
		ajustaI(RA, 7);
		ajustaI(cidade, 20);
		ajustaI(rua, 25);
		ajustaI(numero, 5);
		ajustaI(CEP, 9);
		ajustaI(UF, 3);
		ajustaI(telefone, 11);
		ajustaI(rua2, 35);
		ajustaI(numero2, 5);
		ajustaI(CEP2, 9);
		ajustaI(telefone2, 11);
		ajustaI(curso, 25);
		ajustaI(anoIngresso, 5);
		str[0]=nome[0];

	}
	void init()
	{
		strncat(str,nome,40);
		strncat(str,RG,10);
		strncat(str,CPF,12);
		strncat(str,RA,7);
		strncat(str,cidade,20);
		strncat(str,rua,35);
		strncat(str,numero,5);
		strncat(str,CEP,9);
		strncat(str,UF,3);
		strncat(str,telefone,11);
		strncat(str,rua2,35);
		strncat(str,numero2,5);
		strncat(str,CEP2,9);
		strncat(str,telefone2,11);
		strncat(str,curso,25);
		strncat(str,anoIngresso,4);
		str[241]='\n';
		
	}
	
	char*	getStr()
	{
		return str;
	}

	/*void imprime()
	{
		cout << endl;
		cout << "Registro de Alunos" << endl;
		cout << "Nome: " << ajustaI(nome, 40) << endl;
		cout << "RG: " << ajustaI(RG, 10) << endl;
		cout << "CPF: " << ajustaI(CPF, 12) << endl;
		cout << "RA: " << ajustaI(RA, 7) << endl;
		cout << "Cidade: " << ajustaI(cidade, 20) << endl;
		cout << "Rua: " << ajustaI(rua, 25) << endl;
		cout << "Numero: " << ajustaI(numero, 5) << endl;
		cout << "CEP: " << ajustaI(CEP, 9) << endl;
		cout << "UF: " << ajustaI(UF, 3) << endl;
		cout << "Telefone: " << ajustaI(telefone, 11) << endl;
		cout << "Rua S: " << ajustaI(rua2, 35) << endl;
		cout << "Numero S: " << ajustaI(numero2, 5) << endl;
		cout << "CEP S: " << ajustaI(CEP2, 9) << endl;
		cout << "Telefone S: " << ajustaI(telefone2, 11) << endl;
		cout << "Curso: " << ajustaI(curso, 25) << endl;
		cout << "Ano Ingresso: " << ajustaI(anoIngresso, 5) << endl;
		cout << endl;
	}*/
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

	char	str[242];
	
	char* ajustaI(char* var, int n)
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
