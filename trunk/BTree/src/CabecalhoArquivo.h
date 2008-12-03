using namespace std;

class CabecalhoArquivo
{
	private:
		int enderecoDisp; //guarda no cabecalho o end do primeiro na lista de disp
		int enderecoArquivo; //guarda o end do comeco do arquivo de dados.
		char identificacao; //identifica o cabecalho
		
	public:
		CabecalhoArquivo()
		{
			identificacao = 'A';
			enderecoArquivo = 5;
		}
		
		~CabecalhoArquivo()
		{
			
		}
		
		//retorna o endereco do ultimo excluido lista de disponiveis
		int getEnderecoDisp()
		{
			return enderecoDisp;
		}
		//seta enderecoDisponiveis
		void setEnderecoDisp(int endereco)
		{
			enderecoDisp = endereco;
		}
		
		//seta enderecoArquivo
		void setEnderecoArquivo(int endereco)
		{
			enderecoArquivo = endereco;
		}
		
		//retorna o endereco do comeco do arquivo de dados
		int getEnderecoArquivo()
		{
			return enderecoArquivo;
		}
		
		//retorna a identificacao do cabecalho
		char getIdentificacao()
		{
			return identificacao;
		}
		
		
		
	
		
		
	
};



