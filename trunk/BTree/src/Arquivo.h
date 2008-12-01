using namespace std;

class Arquivo
{
private:
	string nome;
	fstream f;
	Registro r;
public:
	Arquivo(string filename)
	{

		nome = filename;
		f.open(nome.c_str());
		
		f.seekg(0*242,ios::beg);
		f.getline(reinterpret_cast<char *>(&r), 242);
		f.seekg(100*242,ios::beg);
		f.write(reinterpret_cast<char *>(&r), 242);
		f << '\xA';
				
	}
	
	void setEnd(int endereco)
	{
		
	}
	
	
	int getRA(int posicao)
	{
		f.seekg(posicao,ios::beg);
		f.getline(reinterpret_cast<char *>(&r), 242);
		return r.getRA();
	}
	
	void imprime(int posicao)
	{
		f.seekg(posicao,ios::beg);
		f.getline(reinterpret_cast<char *>(&r), 242);
		r.imprime();
	}
	
	int getPosicao()
	{
		return f.tellg();
	}
	
};
