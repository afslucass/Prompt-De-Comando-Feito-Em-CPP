#include <iostream>
#include "boost/filesystem.hpp"
#include "headers.h"

using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[])
{

    // c++ program crash on delete pointer, estudar mais sobre gerenciamento e desalocamento de memoria.

    path p = path(path(argv[0]).parent_path().string());

    loop(p);

    return 0;
}
