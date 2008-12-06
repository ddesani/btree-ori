using namespace std;

/**
 * @brief Classe Registro
 * Classe para manipular os registro no arquivo de registros
 *
 * @author Juliana Scaquetti, 298921
 * @author Victor Hugo B. R. Santos, 298557
 * @author Diego D. da Silva, 298700
 * @author Thiago A. C. Chagas, 280615
 * @version 6 de Dezembro de 2008
 */
class Registro
{
	friend class Arquivo;
	
	private:
		/**
		 * variavel que contem o nome do registro
		 */
		char nome[40];

		/**
		 * variavel que contem o RG do registro
		 */
		char RG[10];

		/**
		 * variavel que contem o CPF do registro
		 */
		char CPF[12];

		/**
		 * variavel que contem o RA do registro
		 */
		char RA[7];

		/**
		 * variavel que contem a cidade do registro
		 */
		char cidade[20];

		/**
		 * variavel que contem a rua do registro
		 */
		char rua[35];

		/**
		 * variavel que contem o numero do registro
		 */
		char numero[5];

		/**
		 * variavel que contem o CEP do registro
		 */
		char CEP[9];

		/**
		 * variavel que contem o estado do registro
		 */
		char UF[3];

		/**
		 * variavel que contem o telefone do registro
		 */
		char telefone[11];

		/**
		 * variavel que contem a segunda rua do registro
		 */
		char rua2[35];

		/**
		 * variavel que contem o segundo numero do registro
		 */
		char numero2[5];

		/**
		 * variavel que contem o segundo CEP do registro
		 */
		char CEP2[9];

		/**
		 * variavel que contem o segundo telefone do registro
		 */
		char telefone2[11];

		/**
		 * variavel que contem o curso do registro
		 */
		char curso[25];

		/**
		 * variavel que contem o ano de ingresso do registro
		 */
		char anoIngresso[4];

		/**
		 * variavel que contem o tamanho do nome
		 */
		int tamanhoNome;

		/**
		 * variavel que contem o tamanho do RG
		 */
		int tamanhoRG;

		/**
		 * variavel que contem o tamanho do CPF
		 */
		int tamanhoCPF;

		/**
		 * variavel que contem o tamanho do RA
		 */
		int tamanhoRA;

		/**
		 * variavel que contem o tamanho da cidade
		 */
		int tamanhoCidade;

		/**
		 * variavel que contem o tamanho da rua
		 */
		int tamanhoRua;

		/**
		 * variavel que contem o tamanho do numero
		 */
		int tamanhoNumero;

		/**
		 * variavel que contem o tamanho do CEP
		 */
		int tamanhoCEP;

		/**
		 * variavel que contem o tamanho do estado
		 */
		int tamanhoUF;

		/**
		 * variavel que contem o tamanho do telefone
		 */
		int tamanhoTelefone;

		/**
		 * variavel que contem o tamanho da segunda rua
		 */
		int tamanhoRua2;

		/**
		 * variavel que contem o tamanho do segundo numero
		 */
		int tamanhoNumero2;

		/**
		 * variavel que contem o tamanho do segundo CEP
		 */
		int tamanhoCEP2;

		/**
		 * variavel que contem o tamanho do segundo telefone
		 */
		int tamanhoTelefone2;

		/**
		 * variavel que contem o tamanho do curso
		 */
		int tamanhoCurso;

		/**
		 * variavel que contem o tamanho do ano de ingresso
		 */
		int tamanhoAnoIngresso;

		/**
		 * Metodo para ajustar os dados do arquivo de dados,
		 * ele separa por variaveis cada um dos campos
		 * @param *var variavel que sera ajustada
		 * @param n tamanho da variavel que sera ajustada
		 * @return retorna a variavel ajustada
		 */
		char* ajusta(char* var, int n)
		{
			char* aux = new char[n - 1];
			
			for (int i = 0; i < (n - 1); ++i)
				aux[i] = var[i];
			//strncpy(aux,var,n-1);

			strcpy(var, aux);
			
			for (int i = 0; i < (n - 1); ++i)
				aux[i] = '\0';
			
			delete[] aux;
			
			return var;
		}
		
	public:
		/**
		 * Construtor, inicializa as variaveis tamanho
		 */
		Registro()
		{
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
		
		
		/**
		 * Metodo que retorna o nome associado ao registro
		 * @return retorna nome associado ao registro
		 */
		char* getNome()
		{
			return nome;
		}
		
		
		/**
		 * Metodo que seta o nome
		 * @param nome parametro que contem o nome que sera setado
		 */
		void setNome(char nome[40])
		{
			strcpy(this->nome, nome);
		}
		
		
		/**
		 * Metodo que retorna o RG associado ao registro
		 * @return retorna RG associado ao registro
		 */
		char* getRG()
		{
			return RG;
		}
		
		
		/**
		 * Metodo que seta o RG
		 * @param RG parametro que contem o RG que sera setado
		 */
		void setRG(char RG[10])
		{
			strcpy(this->RG, RG);
		}
		
		
		/**
		 * Metodo que retorna o CPF associado ao registro
		 * @return retorna CPF associado ao registro
		 */
		char* getCPF()
		{
			return CPF;
		}
		/**
		 * Metodo que seta o CPF
		 * @param CPF parametro que contem o CPF que sera setado
		 */
		void setCPF(char CPF[12])
		{
			strcpy(this->CPF, CPF);
		}
		
		/*
		 * Metodo que retorna o RA inteiro
		 * @return valor do RA inteiro
		 */
		int getRA()
		{
			return atoi(RA);
		}
		
		
		/**
		 * Metodo que seta o RA
		 * @param RA parametro que contem o RA que sera setado
		 */
		void setRA(char RA[7])
		{
			strcpy(this->RA, RA);
		}
		
		
		/**
		 * Metodo que retorna a cidade associada ao registro
		 * @return retorna cidade associada ao registro
		 */
		char* getCidade()
		{
			return cidade;
		}
		
		
		/**
		 * Metodo que seta a cidade
		 * @param cidade parametro que contem a cidade que sera setado
		 */
		void setCidade(char cidade[20])
		{
			strcpy(this->cidade, cidade);
		}
		
		
		/**
		 * Metodo que retorna a rua associada ao registro
		 * @return retorna rua associada ao registro
		 */
		char* getRua()
		{
			return rua;
		}
		
		
		/**
		 * Metodo que seta a rua
		 * @param rua parametro que contem a rua que sera setado
		 */
		void setRua(char rua[35])
		{
			strcpy(this->rua, rua);
		}
		
		
		/**
		 * Metodo que retorna o numero associado ao registro
		 * @return retorna numero associado ao registro
		 */
		char* getNumero()
		{
			return numero;
		}
		
		
		/**
		 * Metodo que seta o numero
		 * @param numero parametro que contem o numero que sera setado
		 */
		void setNumero(char numero[5])
		{
			strcpy(this->numero, numero);
		}
		
		
		/**
		 * Metodo que retorna o CEP associado ao registro
		 * @return retorna CEP associado ao registro
		 */
		char* getCEP()
		{
			return CEP;
		}
		/**
		 * Metodo que seta o CEP
		 * @param CEP parametro que contem o CEP que sera setado
		 */
		void setCEP(char CEP[9])
		{
			strcpy(this->CEP, CEP);
		}
		
		
		/**
		 * Metodo que retorna o estado associado ao registro
		 * @return retorna estado associado ao registro
		 */
		char* getUF()
		{
			return UF;
		}
		
		
		/**
		 * Metodo que seta o estado
		 * @param estado parametro que contem o estado que sera setado
		 */
		void setUF(char UF[3])
		{
			strcpy(this->UF, UF);
		}
		
		
		/**
		 * Metodo que retorna o telefone associado ao registro
		 * @return retorna telefone associado ao registro
		 */
		char* getTelefone()
		{
			return telefone;
		}
		
		
		/**
		 * Metodo que seta o telefone
		 * @param telefone parametro que contem o telefone que sera setado
		 */
		void setTelefone(char telefone[11])
		{
			strcpy(this->telefone, telefone);
		}
		
		
		/**
		 * Metodo que retorna a segunda rua associada ao registro
		 * @return retorna segunda rua associada ao registro
		 */
		char* getRua2()
		{
			return rua2;
		}
		
		
		/**
		 * Metodo que seta a segunda rua
		 * @param rua2 parametro que contem a segunda rua que sera setado
		 */
		void setRua2(char rua2[35])
		{
			strcpy(this->rua2, rua2);
		}
		
		
		/**
		 * Metodo que retorna o segundo numero associado ao registro
		 * @return retorna segundo numero associado ao registro
		 */
		char* getNumero2()
		{
			return numero2;
		}
		
		
		/**
		 * Metodo que seta o segundo numero
		 * @param numero2 parametro que contem o numero2 que sera setado
		 */
		void setNumero2(char numero2[5])
		{
			strcpy(this->numero2, numero2);
		}
		
		
		/**
		 * Metodo que retorna o segundo CEP associado ao registro
		 * @return retorna segundo CEP associado ao registro
		 */
		char* getCEP2()
		{
			return CEP2;
		}
		
		
		/**
		 * Metodo que seta o segundo CEP
		 * @param CEP2 parametro que contem o segundo CEP que sera setado
		 */
		void setCEP2(char CEP2[9])
		{
			strcpy(this->CEP2, CEP2);
		}
		
		
		/**
		 * Metodo que retorna o segundo telefone associado ao registro
		 * @return retorna segundo telefone associado ao registro
		 */
		char* getTelefone2()
		{
			return telefone2;
		}
		
		
		/**
		 * Metodo que seta o segundo telefone
		 * @param telefone2 parametro que contem o segundo telefone que sera setado
		 */
		void setTelefone2(char telefone2[11])
		{
			strcpy(this->telefone2, telefone2);
		}
		
		
		/**
		 * Metodo que retorna o curso associado ao registro
		 * @return retorna curso associado ao registro
		 */
		char* getCurso()
		{
			return curso;
		}
		
		
		/**
		 * Metodo que seta o curso
		 * @param curso parametro que contem o curso que sera setado
		 */
		void setCurso(char curso[25])
		{
			strcpy(this->curso, curso);
		}
		
		
		/**
		 * Metodo que retorna o ano de ingresso associado ao registro
		 * @return retorna o ano de ingresso associado ao registro
		 */
		char* getAnoIngresso()
		{
			return anoIngresso;
		}
		
		
		/**
		 * Metodo que seta o ano de ingresso
		 * @param anoIngresso parametro que contem o ano de ingresso que sera setado
		 */
		void setAnoIngresso(char anoIngresso[4])
		{
			strcpy(this->anoIngresso, anoIngresso);
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o nome associado ao registro
		 * @return retorna o tamanho que ocupa o nome associado ao registro
		 */
		int getTamanhoNome()
		{
			return tamanhoNome;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o RG associado ao registro
		 * @return retorna o tamanho que ocupa o RG associado ao registro
		 */
		int getTamanhoRG()
		{
			return tamanhoRG;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o CPF associado ao registro
		 * @return retorna o tamanho que ocupa o CPF associado ao registro
		 */
		int getTamanhoCPF()
		{
			return tamanhoCPF;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o RA associado ao registro
		 * @return retorna o tamanho que ocupa o RA associado ao registro
		 */
		int getTamanhoRA()
		{
			return tamanhoRA;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa a cidade associada ao registro
		 * @return retorna o tamanho que ocupa a cidade associada ao registro
		 */
		int getTamanhoCidade()
		{
			return tamanhoCidade;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa a rua associada ao registro
		 * @return retorna o tamanho que ocupa a rua associada ao registro
		 */
		int getTamanhoRua()
		{
			return tamanhoRua;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o numero associado ao registro
		 * @return retorna o tamanho que ocupa o numero associado ao registro
		 */
		int getTamanhoNumero()
		{
			return tamanhoNumero;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o CEP associado ao registro
		 * @return retorna o tamanho que ocupa o CEP associado ao registro
		 */
		int getTamanhoCEP()
		{
			return tamanhoCEP;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o estado associado ao registro
		 * @return retorna o tamanho que ocupa o estado associado ao registro
		 */
		int getTamanhoUF()
		{
			return tamanhoUF;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o telefone associado ao registro
		 * @return retorna o tamanho que ocupa o telefone associado ao registro
		 */
		int getTamanhoTelefone()
		{
			return tamanhoTelefone;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa a segunda rua associada ao registro
		 * @return retorna o tamanho que ocupa a segunda rua associada ao registro
		 */
		int getTamanhoRua2()
		{
			return tamanhoRua2;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o segundo numero associado ao registro
		 * @return retorna o tamanho que ocupa o segundo numero associado ao registro
		 */
		int getTamanhoNumero2()
		{
			return tamanhoNumero2;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o segundo CEP associado ao registro
		 * @return retorna o tamanho que ocupa o segundo CEP associado ao registro
		 */
		int getTamanhoCEP2()
		{
			return tamanhoCEP2;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o segundo telefone associado ao registro
		 * @return retorna o tamanho que ocupa o segundo telefone associado ao registro
		 */
		int getTamanhoTelefone2()
		{
			return tamanhoTelefone2;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o curso associado ao registro
		 * @return retorna o tamanho que ocupa o curso associado ao registro
		 */
		int getTamanhoCurso()
		{
			return tamanhoCurso;
		}
		
		
		/**
		 * Metodo que retorna o tamanho que ocupa o ano de ingresso associado ao registro
		 * @return retorna o tamanho que ocupa o ano de ingresso associado ao registro
		 */
		int getTamanhoAnoIngresso()
		{
			return tamanhoAnoIngresso;
		}
		
		
		
		
		/*
		 * Metodo que ajusta os campos do registro
		 */
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
		
		
		/**
		 * Metodo que imprime um registro completo
		 */
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
			cout << endl;
		}
		
		
		/**
		 * Metodo que testa se ha um registro em um determinado endereco, caso o primeiro
		 * caracter do registro seja espaco, ele estara vazio.
		 * @return verdadeiro se nao estiver vazio, falso se estiver vazio
		 */
		bool testaRegistro()
		{
			if (nome[0] == ' ')
				return false;
			else
				return true;
		}
		
};
