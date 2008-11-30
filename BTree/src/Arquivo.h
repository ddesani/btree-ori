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
			r.imprime();
		}
		
		
		
		
};
