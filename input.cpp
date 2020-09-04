
#include "headers.h"

using namespace std;

vector<string> input(boost::filesystem::path &acao)
{
    cout << "Onde Estamos: " << acao.string() << endl;

    cout << "MPD -> Mostrar Pastas e Arquivos    AA -> Abrir Arquivos" << endl;
    cout << "ENP -> Entrar nas Pastas            CA -> Criar Arquivos" << endl;
    cout << "CP -> Criar Pasta                   S -> Sair" << endl;

    string texto;
    getline(cin, texto);

    istringstream iterate_string(texto);
    vector<string> palavras;
    string i;
    // problema no loop:

    do
    {
        i = " ";
        iterate_string >> i;
        palavras.push_back(i);

    } while(iterate_string);

    if(palavras[0] != "mpd" && palavras[0] != "aa" && palavras[0] != "enp" && palavras[0] != "ca" && palavras[0] != "cp" && palavras[0] != "s")
    {
        system("cls");
        cout << "Comando Incorreto" << endl;
        palavras.clear();
        palavras = input(acao);
        return palavras;
    }

    system("cls");
    return palavras;
}
