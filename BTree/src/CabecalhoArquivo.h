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
		
		int getEnderecoDisp()
		{
			return enderecoDisp;
		}
		
		void setEnderecoDisp(int endereco)
		{
			enderecoDisp = endereco;
		}
		
		void setEnderecoArquivo(int endereco)
		{
			enderecoArquivo = endereco;
		}
		
		
		int getEnderecoArquivo()
		{
			return enderecoArquivo;
		}
		
		char getIdentificacao()
		{
			return identificacao;
		}
		
		
		
	
};



