
#ifndef HEADERS
#define HEADERS

#include "boost/filesystem.hpp"
#include "string"
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

void loop(boost::filesystem::path &pt);

class action
{
private:
    boost::filesystem::path* pt = NULL;
public:
    // IMPORTANTE: Antes de dar delete, tem-se que atribuir nullptr, senao ele crashara o programa:
    ~action() { pt = nullptr; delete pt; }

    void mpd(); // mostra a po toda
    void aa(std::vector<std::string> &comando); // abre car
    void enp(std::vector<std::string> &comando); // entra na pasta
    void ca(std::vector<std::string> &comando); // cria car
    void cp(std::vector<std::string> &comando); // cria pasta

    void set_pt(boost::filesystem::path &pt) {this->pt = &pt;}
    boost::filesystem::path& get_path();
    int s(); // sair
};

std::vector<std::string> input(boost::filesystem::path &acao);

#endif // HEADERS
