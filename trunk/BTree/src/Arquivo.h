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
		for (int i = 0; i < 100; ++i)
		{
			f.getline(reinterpret_cast<char *>(&r), 242);
			cout << r.getRA();
			r.imprime();
			cout << endl;
		}
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
