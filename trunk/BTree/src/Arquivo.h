using namespace std;

class Arquivo
{
private:
	string nome;
	fstream f;
	Registro r;
	char a[2];
public:
	Arquivo(string filename)
	{

		nome = filename;
		f.open(nome.c_str(), ios::in | ios::out | ios::binary);
		for (int i = 0; i < 100; ++i)
		{
			f.getline(reinterpret_cast<char *>(&r), 242);
			cout << r.getRA();
			r.imprime();
			cout << endl;
		}


	}

};
