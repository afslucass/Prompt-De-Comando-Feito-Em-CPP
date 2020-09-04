
#include "headers.h"

using namespace boost::filesystem;
using namespace std;

void action::mpd()
{
    cout << "Diretorio: " << *pt << endl << endl;
    try {
        for(directory_entry &i : directory_iterator(*pt))
        {
            if(is_directory(i))
            {
                cout << "Diretorio: " << i.path().filename() << endl;
            } else
            {
                cout << "Arquivo: " << i.path().filename() << endl;
            }
        }
    } catch (const filesystem_error &err) {
        cout << "Ocorreu Algum Problema" << endl;
    }

    cout << endl;

    return;
}
void action::aa(vector<string> &comando)
{
    string file;
    for(string i : comando)
    {
        if(i != "aa"){
            file = file + i + " ";
        }
    }

    file = file.substr(0, file.length() - 3);

    path p(this->pt->string() + "\\" + file);

    if(exists(p) && is_regular_file(p)){
        // string texto;
        // std::ifstream in(p.string(), std::fstream::binary);

        // getline(in, texto);
        // cout << texto << endl << endl;
        // char p_char[p.string().length() + 1];
        // system(strcpy(p_char, p.string().c_str()));

        // Declara o stream:
        std::ifstream bin(p.string());
        // Declara os objetos que indicam as posicoes no stream, para fazer o calculo do tamanho do arquivo:
        std::streampos begin, end;

        // Captura a posicao atual:
        begin = bin.tellg();
        // Pula para o final:
        bin.seekg(0, ios::end);
        // Pega a posicao atual;
        end = bin.tellg();

        // Cria um array com o exato tamanho do arquivo:
        char caracteres[(end-begin)];

        // Volta para o inicio do arquivo, para fazer a leitura abaixo:
        bin.seekg(0, ios::beg);

        while(!bin.eof()){
            bin.read(reinterpret_cast<char *> (caracteres), (end-begin));
        }

        bin.close();

        for(int i = 0; i < 1024; i++){
            cout << caracteres[i];
        }
        cout << endl;

    } else {
        cout << "Não Foi Possivel Abrir o Arquivo" << endl << endl;
    }

    return;
}
void action::enp(vector<string> &comando)
{
    string file;
    for(string i : comando)
    {
        if(i != "enp"){
            file = file + i + " ";
        }
    }

    file = file.substr(0, file.length() - 3);

    path p;

    if(this->pt->string().substr(this->pt->string().length() - 1, this->pt->string().length()) == "/" ||
    this->pt->string().substr(this->pt->string().length() - 1, this->pt->string().length()) == "\\"){
        p = path(this->pt->string() + file);
    } else {
        p = path(this->pt->string() + "\\" + file);
    }

    if(is_directory(p) && exists(p) && file[0] != ' '){

        int tem_pontos;

        for(auto &i : file){
            if(i != '.'){
                tem_pontos = 0;
                break;
            } else {
                tem_pontos = 1;
            }
        }

        if(tem_pontos == 0){
            *(this->pt) = path(p.string() + "\\");

        } else {
            for(auto &i : file){
                *(this->pt) = path(path(this->pt->string().substr(0, this->pt->string().length() - 1)).parent_path());
            }
        }

    } else {
        cout << "O Diretorio: " << p.string() << " Nao Existe ou Nao É um Diretorio" << endl;
    }

    return;
}
void action::ca(vector<string> &comando)
{
    string nome_arquivo;
    string conteudo_arquivo;

    for(auto& nome : comando){
        if(nome != "ca"){
            nome_arquivo += nome + " ";
        }
    }
    nome_arquivo = nome_arquivo.substr(0, nome_arquivo.length()-3);
    cout << this->pt->string() << "\\" << nome_arquivo << endl;

    cout << "Digite o Conteudo: " << endl;
    getline(cin, conteudo_arquivo);

    std::ofstream out(this->pt->string() + "/" + nome_arquivo , ios::app);
    out << conteudo_arquivo;

    out.close();
    system("cls");

    return;
}
void action::cp(vector<string> &comando)
{
    string nome_dir;

    for(auto &coman : comando){
        if(coman != "cp"){
            nome_dir += coman + " ";
        }
    }

    nome_dir = nome_dir.substr(0, nome_dir.length() -3);

    create_directory(path(this->pt->string() + "\\" + nome_dir));

    return;
}
path& action::get_path(){
    return *(this->pt);
}
int action::s()
{
    return 0;
}
