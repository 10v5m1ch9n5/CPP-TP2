#include <iostream>
#include <cstring>
using namespace std;

enum IndexCouleur { NOIR, ROUGE, VERT, JAUNE, BLEU, MAGENTA, CYAN, BLANC, RESET };
static const char* const COULEUR [] = {"\033[30m", "\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m", "\033[m\017"};

class CouleurTTY
{
public:
    explicit CouleurTTY(IndexCouleur i) : index(i) {};
    inline friend ostream & operator << (ostream & os, const CouleurTTY & manip)
    {
        os.write(COULEUR[manip.index], strlen(COULEUR[manip.index]));
        return os.flush();
    }
private:
    IndexCouleur index;
};

