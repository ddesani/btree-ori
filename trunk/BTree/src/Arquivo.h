using namespace std;

class Arquivo
{
	private:
		string		nome;
		fstream		f;
		Registro	r;
	public:
		Arquivo(string filename)
		{
			nome = filename;
			f.open(nome.c_str());
			f.getline(reinterpret_cast<char *>(&r),242,'\n');
			//r.setNome();
			r.imprime();
		}
		
		/*string getRA()
		{
			char ra[7];
			
			//f.seekg(0,ios::beg);
			
			for(int i=0; i<7; ++i)
				ra[i] = r.RA[i];
			
			string teste(ra); //converte char para string
			
			
			return teste.substr(0,7);
		}*/
		
		/*char getEndereco()
		{
			return;
		}
		*/
		
		
		
};
