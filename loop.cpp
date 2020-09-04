
#include "headers.h"

using namespace boost::filesystem;
using namespace std;

void loop(path &pt)
{
    int on = 1;
    action acoes;
    acoes.set_pt(pt);
    while(on == 1)
    {
        vector<string> comando = input(acoes.get_path());

        if(comando[0] == "mpd")
        {
            acoes.mpd();
        } else if(comando[0] == "aa")
        {
            acoes.aa(comando);
        } else if(comando[0] == "enp")
        {
            acoes.enp(comando);
        } else if(comando[0] == "ca")
        {
            acoes.ca(comando);
        } else if(comando[0] == "cp")
        {
            acoes.cp(comando);
        } else if(comando[0] == "s")
        {
            on = acoes.s();
        }

    }

    return;
}
