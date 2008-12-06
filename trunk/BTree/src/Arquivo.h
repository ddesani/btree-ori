using namespace std;
/*
 * No cabecalho contem os seguintes campos, respectivamente:
 * Identificacao do cabecalho, seu endereco e a posicao do ultimo registro excluido
 */

class Arquivo
{
	private:
		string nome;
		fstream f;
		Registro r;
		
		/**
		 * Metodo que insere espacos vazios no fim de cada variavel char,
		 * a partir do tamanho da variavel, ele conta quantos caracteres tem o char, ate o '\0',
		 * a partir disso, ele inclui espacos em cada posicao do char, ate completar o seu tamanho
		 * @param *a ponteiro para o que sera escrito no arquivo
		 * @param tamanho tamanho do campo que sera escrito no arquivo
		 * @return retorna um ponteiro pra char com os espacoes ja incluidos
		 */
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
		
	public:
		
		/**
		 * Construtor, abre o arquivo de dados
		 * @param filename string que contem o nome do arquivo
		 */
		Arquivo(string filename)
		{
			nome = filename;
			f.open(nome.c_str());
		}
		
		/**
		 * Destrutor, fecha o arquivo de dados
		 */
		~Arquivo()
		{
			f.close();
		}
		
		/**
		 * Metodo que insere novos dados no arquivo, caso a lista de disponivel esteja vazia,
		 * o novo registro sera incluido no final, caso nao esteja, o registro sera inserido
		 * na ultima posicao deletada, e assim por diante, como uma pilha
		 * @return se a lista de disponivel estiver vazia, retorna o endereco do ultimo registro, caso contraio,
		 * retorna o que esta no cabecalho
		 */
		int inserirArq()
		{
			//Tipo registro que auxilia com as variaveis para formar o vetor de char do registro
			Registro reg;
			
			
			//Registro final com todos os campos
			char registro[242];
			
			
			//nome
			cout << "Nome: ";
			cin.getline(reg.nome, sizeof(reg.nome));
			char *aux = insereEspaco(reg.nome, reg.tamanhoNome);
			strcpy(registro, aux);
			strcat(registro, " ");
			//RG
			cout << "RG: ";
			cin.getline(reg.RG, sizeof(reg.RG));
			aux = insereEspaco(reg.RG, reg.tamanhoRG);
			strcat(registro, aux);
			strcat(registro, " ");
			//CPF
			cout << "CPF: ";
			cin.getline(reg.CPF, sizeof(reg.CPF));
			aux = insereEspaco(reg.CPF, reg.tamanhoCPF);
			strcat(registro, aux);
			strcat(registro, " ");
			//RA
			cout << "RA: ";
			cin.getline(reg.RA, sizeof(reg.RA));
			aux = insereEspaco(reg.RA, reg.tamanhoRA);
			strcat(registro, aux);
			strcat(registro, " ");
			//Cidade
			cout << "Cidade: ";
			cin.getline(reg.cidade, sizeof(reg.cidade));
			aux = insereEspaco(reg.cidade, reg.tamanhoCidade);
			strcat(registro, aux);
			strcat(registro, " ");
			//Rua
			cout << "Rua: ";
			cin.getline(reg.rua, sizeof(reg.rua));
			aux = insereEspaco(reg.rua, reg.tamanhoRua);
			strcat(registro, aux);
			strcat(registro, " ");
			//Numero
			cout << "Numero: ";
			cin.getline(reg.numero, sizeof(reg.numero));
			aux = insereEspaco(reg.numero, reg.tamanhoNumero);
			strcat(registro, aux);
			strcat(registro, " ");
			//CEP
			cout << "CEP: ";
			cin.getline(reg.CEP, sizeof(reg.CEP));
			aux = insereEspaco(reg.CEP, reg.tamanhoCEP);
			strcat(registro, aux);
			strcat(registro, " ");
			//UF
			cout << "UF: ";
			cin.getline(reg.UF, sizeof(reg.UF));;
			aux = insereEspaco(reg.UF, reg.tamanhoUF);
			strcat(registro, aux);
			strcat(registro, " ");
			//Telefone
			cout << "Telefone: ";
			cin.getline(reg.telefone, sizeof(reg.telefone));
			aux = insereEspaco(reg.telefone, reg.tamanhoTelefone);
			strcat(registro, aux);
			strcat(registro, " ");
			//Rua 2
			cout << "Rua 2: ";
			cin.getline(reg.rua2, sizeof(reg.rua2));
			aux = insereEspaco(reg.rua2, reg.tamanhoRua2);
			strcat(registro, aux);
			strcat(registro, " ");
			//Numero 2
			cout << "Numero 2: ";
			cin.getline(reg.numero2, sizeof(reg.numero2));
			aux = insereEspaco(reg.numero2, reg.tamanhoNumero2);
			strcat(registro, aux);
			strcat(registro, " ");
			//CEP 2
			cout << "CEP 2: ";
			cin.getline(reg.CEP2, sizeof(reg.CEP2));
			aux = insereEspaco(reg.CEP2, reg.tamanhoCEP2);
			strcat(registro, aux);
			strcat(registro, " ");
			//Telefone 2
			cout << "Telefone 2: ";
			cin.getline(reg.telefone2, sizeof(reg.telefone2));
			aux = insereEspaco(reg.telefone2, reg.tamanhoTelefone2);
			strcat(registro, aux);
			strcat(registro, " ");
			//Curso
			cout << "Curso: ";
			cin.getline(reg.curso, sizeof(reg.curso));
			aux = insereEspaco(reg.curso, reg.tamanhoCurso);
			strcat(registro, aux);
			strcat(registro, " ");
			//Ano Ingresso 
			cout << "Ano Ingresso: ";
			cin.getline(reg.anoIngresso, sizeof(reg.anoIngresso)+1);
			aux = insereEspaco(reg.anoIngresso, reg.tamanhoAnoIngresso+1);
			strcat(registro, aux);
			
			
			//coloca o xA no fim registro ao inves do \0
			registro[241] = '\xA';
			
			char *auxiliar = lerCabecalhoDisp();
			if (auxiliar[0] == '0')
			{
				f.seekp(0, ios::end);
				int i = f.tellp();
				f.write(registro, 242);
				return i;
			}
			else
			{
				char endCampo[100];
				int b = atoi(lerCabecalhoDisp());
				f.seekp(b, ios::beg);
				strcpy(endCampo, lerCampo(lerCabecalhoDisp()));
				f.seekp(b, ios::beg);
				f.write(registro, 242);
				int aa = atoi(endCampo);
				escreverCabecalhoDisp(aa);
				return b;
				
			}
			
		}
		
		
		/**
		 * Metodo que retorna o RA de um registro, dada a sua posicao no arquivo de dados
		 * @param posicao posicao passada para recuperar o RA
		 * @return retorna o RA de um registro
		 */
		int getRA(int posicao)
		{
			f.seekg(posicao, ios::beg);
			f.getline(reinterpret_cast<char *>(&r), 242);
			return r.getRA();
		}
		
		
		/**
		 * Metodo que imprime um registro, dada a sua posicao
		 * @param posicao posicao passada para impressao do registro
		 */
		void imprime(int posicao)
		{
			f.seekg(posicao, ios::beg);
			f.getline(reinterpret_cast<char *>(&r), 242);
			
			if (r.testaRegistro() == true)
			{
				r.ajusta();
				r.imprime();
			}
			else
				cout << "Nao ha registro nesta posicao." << endl;
			
		}
		
		
		/**
		 * Metodo que retorna a posicao do arquivo
		 * @return retorna a posicao do arquivo
		 */
		long getPosicao()
		{
			return f.tellg();
		}
		
		
		/**
		 * Metodo que converte inteiro para char
		 * @param endereco endereco que esta em char que sera convertido para int
		 * @return retorna um ponteiro para char com o valor ja convertido
		 */
		char* intToChar(int endereco)
		{
			char *caracter = new char[100];
			sprintf(caracter, "%d", endereco);
			
			return caracter;
		}
		
		
		/**
		 * Metodo que le o endereco disponivel no cabecalho para insercao de registro
		 * @return retorna o char que contem o endereco do registro que esta na lista de disponiveis no cabecalho
		 */
		char* lerCabecalhoDisp()
		{
			char *buf = new char[100];
			char temp;
			int i = 0;
			
			f.seekg(40, ios::beg);
			f.read(&temp, 1);
			do
			{
				buf[i++] = temp;
				f.read(&temp, 1);
			} while (temp != ' ');
			buf[i] = '\0';
			
			return buf;
		}
		
		
		/**
		 * Metodo que escreve no cabecalho a posicao do ultimo registro excluido
		 * @param endereco endereco endereco de um registro que ficou livre que sera escrito no cabecalho
		 */
		void escreverCabecalhoDisp(unsigned int endereco)
		{
			char end[200];
			int count = 0;
			
			strcpy(end, intToChar(endereco));
			
			f.seekg(40, ios::beg);
			while (end[count] != '\0')
				count++;
			
			int i = count;
			while (i < 200)
				end[i++] = ' ';
			
			f.seekp(40, ios::beg);
			f.write(end, sizeof(end));
		}
		
		
		/**
		 * Metodo que remove um registro do arquivo de dados,
		 * e verificado no metodo lerCabecalhoDisp() o ultimo registro excluido,
		 * ele le no cabecalho a ultima posicao removida e vai ate ela marcar a posicao atual a ser removida.
		 * e assim sucessivamente.
		 * @param endereco endereco do registro que sera removido
		 * @return retorna verdadeiro se o registro foi removido (quando um endereco de um removido
		 * e escrito no lugar de um registro, antes dele e colocado um espaco, por isso a condicao
		 * de b(variavel auxiliar) ser diferente de espaco) ou false caso o registro ja tenha sido removido anteriormente,
		 * ou seja, nao removeu nada na chamada do metodo atual
		 */
		bool removerRegistro(unsigned int endereco)
		{
			char b[1];
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
			
			f.clear();
			f.seekg(endereco, ios::beg);
			//f >> b[0];
			f.read(b, 1);
			
			if (b[0] != ' ')
			{
				f.seekp(endereco, ios::beg);
				f.write(limpo, 242);
				escreverCabecalhoDisp(endereco);
				f.flush();
				
				return true;
			}
			else
				return false;
			
		}
		
		
		/**
		 * Metodo para leitura do campo que indica que um registro foi removido
		 * @param *endereco endereco do campo que sera lido
		 * @return retorna o endereco do proximo registro disponivel
		 */
		char* lerCampo(char *endereco)
		{
			char *campo = new char[100];
			int end;
			end = atoi(endereco);
			
			f.seekg(end+1, ios::beg);
			
			f.read(campo, 241);
			
			int i = 0;
			
			while (campo[i] != ' ')
				++i;
			
			strncpy(campo, campo, i);
			campo[i] = '\0';
			
			return campo;
		}
		
		
		/**
		 * Metodo que le todos os registros e coloca na chave o RA e seu endereco
		 * @param *ch chave que guardara o RA e seu endereco, sera retornado por referencia
		 */
		void lerRegistro(Chave* ch)
		{
			
			f.clear();
			f.seekg(242, ios::beg);
			
			while (f.getline(reinterpret_cast<char *>(&r), 242))
				if (r.testaRegistro() == true)
				{
					ch->setRA(r.getRA());
					ch->setRegistro(getPosicao());
				}
		}
		
};
