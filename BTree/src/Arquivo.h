
using namespace std;

class Arquivo
{
private:
	string nome;
	fstream f;
	Registro r;
	CabecalhoArquivo a;
	
	void insereArq(int n, char *registro){
			//insere na ultima linha do arquivo
			f.seekg(n*sizeof(registro), ios::beg);
			f.clear();
			f.write(registro, 242);
	}
	
			
public:
	Arquivo(string filename)
	{
		nome = filename;
		f.open(nome.c_str());
	}
	
	~Arquivo()
	{
		f.close();
	}

	//insere espacos vazios no fim de cada variavel char
	char* insereEspaco(char *a, int tamanho)
	{
		char *aux = new char[tamanho];
		int i = 0;
		while (a[i] != '\0' && i != tamanho - 1)
		{
			aux[i] = a[i];
			++i;
		}
		while (i < tamanho - 1)
			aux[i++] = ' ';

		aux[i] = '\0';
		return aux;
	}

	void inserirArq(int n)
	{
		//Tipo registro que auxilia com as variaveis para formar o vetor de char do registro
		Registro reg;

		//Registro final com todos os campos
		char registro[242];

		//nome
		cout << "Nome: ";
		cin >> reg.nome;
		char *aux = insereEspaco(reg.nome, reg.tamanhoNome);
		strcpy(registro, aux);
		strcat(registro, " ");
		//RG
		cout << "RG: ";
		cin >> reg.RG;
		aux = insereEspaco(reg.RG, reg.tamanhoRG);
		strcat(registro, aux);
		strcat(registro, " ");
		//CPF
		cout << "CPF: ";
		cin >> reg.CPF;
		aux = insereEspaco(reg.CPF, reg.tamanhoCPF);
		strcat(registro, aux);
		strcat(registro, " ");
		//RA
		cout << "RA: ";
		cin >> reg.RA;
		aux = insereEspaco(reg.RA, reg.tamanhoRA);
		strcat(registro, aux);
		strcat(registro, " ");
		//Cidade
		cout << "Cidade: ";
		cin >> reg.cidade;
		aux = insereEspaco(reg.cidade, reg.tamanhoCidade);
		strcat(registro, aux);
		strcat(registro, " ");
		//Rua
		cout << "Rua: ";
		cin >> reg.rua;
		aux = insereEspaco(reg.rua, reg.tamanhoRua);
		strcat(registro, aux);
		strcat(registro, " ");
		//Numero
		cout << "Numero: ";
		cin >> reg.numero;
		aux = insereEspaco(reg.numero, reg.tamanhoNumero);
		strcat(registro, aux);
		strcat(registro, " ");
		//CEP
		cout << "CEP: ";
		cin >> reg.CEP;
		aux = insereEspaco(reg.CEP, reg.tamanhoCEP);
		strcat(registro, aux);
		strcat(registro, " ");
		//UF
		cout << "UF: ";
		cin >> reg.UF;
		aux = insereEspaco(reg.UF, reg.tamanhoUF);
		strcat(registro, aux);
		strcat(registro, " ");
		//Telefone
		cout << "Telefone: ";
		cin >> reg.telefone;
		aux = insereEspaco(reg.telefone, reg.tamanhoTelefone);
		strcat(registro, aux);
		strcat(registro, " ");
		//Rua 2
		cout << "Rua 2: ";
		cin >> reg.rua2;
		aux = insereEspaco(reg.rua2, reg.tamanhoRua2);
		strcat(registro, aux);
		strcat(registro, " ");
		//Numero 2
		cout << "Numero 2: ";
		cin >> reg.numero2;
		aux = insereEspaco(reg.numero2, reg.tamanhoNumero2);
		strcat(registro, aux);
		strcat(registro, " ");
		//CEP 2
		cout << "CEP 2: ";
		cin >> reg.CEP2;
		aux = insereEspaco(reg.CEP2, reg.tamanhoCEP2);
		strcat(registro, aux);
		strcat(registro, " ");
		//Telefone 2
		cout << "Telefone 2: ";
		cin >> reg.telefone2;
		aux = insereEspaco(reg.telefone2, reg.tamanhoTelefone2);
		strcat(registro, aux);
		strcat(registro, " ");
		//Curso
		cout << "Curso: ";
		cin >> reg.curso;
		aux = insereEspaco(reg.curso, reg.tamanhoCurso);
		strcat(registro, aux);
		strcat(registro, " ");
		//Ano Ingresso 
		cout << "Ano Ingresso: ";
		cin >> reg.anoIngresso;
		aux = insereEspaco(reg.anoIngresso, reg.tamanhoAnoIngresso);
		strcat(registro, aux);

		//coloca o xA no fim registro ao inves do \0
		registro[241] = '\xA';

		//insere na ultima linha do arquivo
		f.seekg(n*sizeof(registro), ios::beg);
		f.clear();
		f.write(registro, 242);

	}
	
	

	/*void escreve()
	 {
	 busca na fila posicao livre
	 f.clear();
	 f.seekg(posicao,ios::beg);
	 f.write(nome, sizeof(Registro));
	 
	 }
	 */
	
	//metodo que retorna o ra de um registro, dada a sua posicao no arquivo de dados
	int getRA(int posicao)
	{
		f.seekg(posicao, ios::beg);
		f.getline(reinterpret_cast<char *>(&r), 242);
		return r.getRA();
	}
	
	//imprime um registro dada a sua posicao
	void imprime(int posicao)
	{
		f.seekg(posicao, ios::beg);
		f.getline(reinterpret_cast<char *>(&r), 242);
		r.imprime();
	}

	//retorna posicao do arquivo
	int getPosicao()
	{
		return f.tellg();
	}
	
	//metodo que converte inteiro para char
	char* intToChar(int endereco)
	{
		stringstream out;
		string s;//string que recebera o int convertido
		 char *caracter; //char que recebera a string convertida
		
		
		//converte inteiro para string
		out << endereco;
		s = out.str();
		
		//converte string para char
		caracter = const_cast<char*>(s.c_str());
		
		return caracter;
		
	}
	
	
	//metodo que le o endereco disponivel no cabecalho
	char* lerCabecalhoDisp()
	{
		char *buf = new char[100];
		f.seekg(40, ios::beg);
		f.read(buf,3);
		
		return buf;
	}
	
	//metodo que escreve no cabecalho a posicao do ultimo registro excluido
	void escreverCabecalhoDisp(unsigned int endereco)
	{
		char *end = new char[100];
		end = intToChar(endereco);
		
		f.seekg(40, ios::beg);
		f.write(end, sizeof(end));
	}
	
	/* metodo que remove um registro do arquivo de dados
	 * é verificado no metodo lerCabecalhoDisp() o ultimo registro excluido,
	 * ele le no cabecalho a ultima posicao removida e vai ate ela marcar a posicao atual a ser removida.
	 * e assim sucessivamente. 
	 */
	int removerRegistro(unsigned int endereco)
	{
		char* aux = lerCabecalhoDisp();
	
			char limpo[242];
			strcpy(limpo, " ");
			strcat(limpo, aux);
			int i = 0;
			while (limpo[i] != '\0')
				++i;
			while (i < 241)
			{
				strcat(limpo, " ");
				++i;
			}
			limpo[241] = '\xA';
			f.seekg(endereco, ios::beg);
			f.clear();
			f.write(limpo, 242);
			escreverCabecalhoDisp(endereco);
			return 1;
	}
	
	//metodo para leitura do campo que indica que um registro foi removido.
	char* lerCampo(char *endereco)
	{
		char *campo = new char[100];
		int end;
		end = atoi(endereco);
		
		f.seekg(end+1,ios::beg);
		
		f.read(campo,241);
		
		int i = 0;
		//char *valor = new char[100];
		
		while(campo[i] != ' ')
			++i;
		
		strncpy(campo,campo,i);
		campo[i] = '\0'; 
		
		cout << campo << endl;
		
		return campo;
	}
	
	

};
