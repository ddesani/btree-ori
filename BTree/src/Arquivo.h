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
		
		f.seekg(99*242,ios::beg);
		f.getline(reinterpret_cast<char *>(&r), 242);
		r.init(); //str = nome
		r.ajustaI();
		r.imprime();
		f.clear();
		f << '\n';
		f.write(r.getStr(),241);
		//f << '\n';
		
		
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
