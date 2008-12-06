using namespace std;

class Registro {
public:
	//variaveis char do registro
	char nome[40];
	char RG[10];
	char CPF[12];
	char RA[7];
	char cidade[20];
	char rua[35];
	char numero[5];
	char CEP[9];
	char UF[3];
	char telefone[11];
	char rua2[35];
	char numero2[5];
	char CEP2[9];
	char telefone2[11];
	char curso[25];
	char anoIngresso[4];

	//variaveis que gardam o tamanho dos char do registro
	int tamanhoNome;
	int tamanhoRG;
	int tamanhoCPF;
	int tamanhoRA;
	int tamanhoCidade;
	int tamanhoRua;
	int tamanhoNumero;
	int tamanhoCEP;
	int tamanhoUF;
	int tamanhoTelefone;
	int tamanhoRua2;
	int tamanhoNumero2;
	int tamanhoCEP2;
	int tamanhoTelefone2;
	int tamanhoCurso;
	int tamanhoAnoIngresso;
	char getNome() const {
		return nome;
	}

	void setNome(char nome[40]) {
		this->nome = nome;
	}

	char getRG() const {
		return RG;
	}

	void setRG(char RG[10]) {
		this->RG = RG;
	}

	char getCPF() const {
		return CPF;
	}

	void setCPF(char CPF[12]) {
		this->CPF = CPF;
	}

	void setRA(char RA[7]) {
		this->RA = RA;
	}

	char getCidade() const {
		return cidade;
	}

	void setCidade(char cidade[20]) {
		this->cidade = cidade;
	}

	char getRua() const {
		return rua;
	}

	void setRua(char rua[35]) {
		this->rua = rua;
	}

	char getNumero() const {
		return numero;
	}

	void setNumero(char numero[5]) {
		this->numero = numero;
	}

	char getCEP() const {
		return CEP;
	}

	void setCEP(char CEP[9]) {
		this->CEP = CEP;
	}

	char getUF() const {
		return UF;
	}

	void setUF(char UF[3]) {
		this->UF = UF;
	}

	char getTelefone() const {
		return telefone;
	}

	void setTelefone(char telefone[11]) {
		this->telefone = telefone;
	}

	char getRua2() const {
		return rua2;
	}

	void setRua2(char rua2[35]) {
		this->rua2 = rua2;
	}

	char getNumero2() const {
		return numero2;
	}

	void setNumero2(char numero2[5]) {
		this->numero2 = numero2;
	}

	char getCEP2() const {
		return CEP2;
	}

	void setCEP2(char CEP2[9]) {
		this->CEP2 = CEP2;
	}

	char getTelefone2() const {
		return telefone2;
	}

	void setTelefone2(char telefone2[11]) {
		this->telefone2 = telefone2;
	}

	char getCurso() const {
		return curso;
	}

	void setCurso(char curso[25]) {
		this->curso = curso;
	}

	char getAnoIngresso() const {
		return anoIngresso;
	}

	void setAnoIngresso(char anoIngresso[4]) {
		this->anoIngresso = anoIngresso;
	}

	int getTamanhoNome() const {
		return tamanhoNome;
	}

	void setTamanhoNome(int tamanhoNome) {
		this->tamanhoNome = tamanhoNome;
	}

	int getTamanhoRG() const {
		return tamanhoRG;
	}

	void setTamanhoRG(int tamanhoRG) {
		this->tamanhoRG = tamanhoRG;
	}

	int getTamanhoCPF() const {
		return tamanhoCPF;
	}

	void setTamanhoCPF(int tamanhoCPF) {
		this->tamanhoCPF = tamanhoCPF;
	}

	int getTamanhoRA() const {
		return tamanhoRA;
	}

	void setTamanhoRA(int tamanhoRA) {
		this->tamanhoRA = tamanhoRA;
	}

	int getTamanhoCidade() const {
		return tamanhoCidade;
	}

	void setTamanhoCidade(int tamanhoCidade) {
		this->tamanhoCidade = tamanhoCidade;
	}

	int getTamanhoRua() const {
		return tamanhoRua;
	}

	void setTamanhoRua(int tamanhoRua) {
		this->tamanhoRua = tamanhoRua;
	}

	int getTamanhoNumero() const {
		return tamanhoNumero;
	}

	void setTamanhoNumero(int tamanhoNumero) {
		this->tamanhoNumero = tamanhoNumero;
	}

	int getTamanhoCEP() const {
		return tamanhoCEP;
	}

	void setTamanhoCEP(int tamanhoCEP) {
		this->tamanhoCEP = tamanhoCEP;
	}

	int getTamanhoUF() const {
		return tamanhoUF;
	}

	void setTamanhoUF(int tamanhoUF) {
		this->tamanhoUF = tamanhoUF;
	}

	int getTamanhoTelefone() const {
		return tamanhoTelefone;
	}

	void setTamanhoTelefone(int tamanhoTelefone) {
		this->tamanhoTelefone = tamanhoTelefone;
	}

	int getTamanhoRua2() const {
		return tamanhoRua2;
	}

	void setTamanhoRua2(int tamanhoRua2) {
		this->tamanhoRua2 = tamanhoRua2;
	}

	int getTamanhoNumero2() const {
		return tamanhoNumero2;
	}

	void setTamanhoNumero2(int tamanhoNumero2) {
		this->tamanhoNumero2 = tamanhoNumero2;
	}

	int getTamanhoCEP2() const {
		return tamanhoCEP2;
	}

	void setTamanhoCEP2(int tamanhoCEP2) {
		this->tamanhoCEP2 = tamanhoCEP2;
	}

	int getTamanhoTelefone2() const {
		return tamanhoTelefone2;
	}

	void setTamanhoTelefone2(int tamanhoTelefone2) {
		this->tamanhoTelefone2 = tamanhoTelefone2;
	}

	int getTamanhoCurso() const {
		return tamanhoCurso;
	}

	void setTamanhoCurso(int tamanhoCurso) {
		this->tamanhoCurso = tamanhoCurso;
	}

	int getTamanhoAnoIngresso() const {
		return tamanhoAnoIngresso;
	}

	void setTamanhoAnoIngresso(int tamanhoAnoIngresso) {
		this->tamanhoAnoIngresso = tamanhoAnoIngresso;
	}

	Registro() {
		//inicializa as variaveis tamanho
		tamanhoNome = 40;
		tamanhoRG = 10;
		tamanhoCPF = 12;
		tamanhoRA = 7;
		tamanhoCidade = 20;
		tamanhoRua = 35;
		tamanhoNumero = 5;
		tamanhoCEP = 9;
		tamanhoUF = 3;
		tamanhoTelefone = 11;
		tamanhoRua2 = 35;
		tamanhoNumero2 = 5;
		tamanhoCEP2 = 9;
		tamanhoTelefone2 = 11;
		tamanhoCurso = 25;
		tamanhoAnoIngresso = 4;
	}

	//retorna o RA (cast para inteiro)
	int getRA() {
		return atoi(RA);
	}

	//metodo para ajuste dos campos do registro
	void ajusta() {
		ajusta(nome, 40);
		ajusta(RG, 10);
		ajusta(CPF, 12);
		ajusta(RA, 7);
		ajusta(cidade, 20);
		ajusta(rua, 25);
		ajusta(numero, 5);
		ajusta(CEP, 9);
		ajusta(UF, 3);
		ajusta(telefone, 11);
		ajusta(rua2, 35);
		ajusta(numero2, 5);
		ajusta(CEP2, 9);
		ajusta(telefone2, 11);
		ajusta(curso, 25);
		ajusta(anoIngresso, 5);

	}

	//metodo para impressao dos dados de um registro
	void imprime() {
		cout << endl;
		cout << "Registro de Alunos" << endl;
		cout << "Nome: " << nome << endl;
		cout << "RG: " << RG << endl;
		cout << "CPF: " << CPF << endl;
		cout << "RA: " << RA << endl;
		cout << "Cidade: " << cidade << endl;
		cout << "Rua: " << rua << endl;
		cout << "Numero: " << numero << endl;
		cout << "CEP: " << CEP << endl;
		cout << "UF: " << UF << endl;
		cout << "Telefone: " << telefone << endl;
		cout << "Rua S: " << rua2 << endl;
		cout << "Numero S: " << numero2 << endl;
		cout << "CEP S: " << CEP2 << endl;
		cout << "Telefone S: " << telefone2 << endl;
		cout << "Curso: " << curso << endl;
		cout << "Ano Ingresso: " << anoIngresso << endl;
		cout << endl;
	}

	//verifica se ha registro em uma determinada posicao de endereco
	bool testaRegistro() {
		if (nome[0] == ' ')
			return false;
		else
			return true;
	}

private:

	/* metodo para ajustar os dados do arquivo de dados
	 * ele separa por variaveis cada um dos campos
	 */
	char* ajusta(char* var, int n) {
		char* aux = new char[n - 1];

		for (int i = 0; i < (n - 1); ++i)
			aux[i] = var[i];
		//strncpy(aux,var,n-1);

		strcpy(var, aux);

		for (int i = 0; i < (n - 1); ++i)
			aux[i] = '\0';

		delete[] aux;

		return var;
	}

};
