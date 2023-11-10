#include <fstream>
#include <cstring>
#define NR_MAX_CIFRE 100001
#define LGINT 11
using namespace std;
ifstream fin("cifrab.in");
ofstream fout("cifrab.out");
int ceaMaiMicaBaza(char*);
char cifraControl(char*, int);
int main()
{
    char nr[NR_MAX_CIFRE];
    int baza;
    fin.getline(nr, NR_MAX_CIFRE);
    fin.close();
    baza = ceaMaiMicaBaza(nr);
    fout << baza << '\n' << cifraControl(nr, baza);
    fout.close();
    return 0;
}
bool cifra(char c)
{
    return c >= '0' && c <= '9';
}
char codLitera(int x)
{
    return x < 10 ? '0'+x : 'A'+(x-10);
}
int codCifra(char c)
{
    return cifra(c) ? c-'0' : c-'A'+10;
}
void convertesteNumarDinBazaZeceInBaza(int baza, int nr, char* rez)
{
    int r[LGINT], n, i;
    for (n = 0; nr; nr /= baza) r[n++] = nr % baza;
    for (i = n-1; i >= 0; i--) rez[n-i-1] = codLitera(r[i]);
    rez[n] = 0;
}
int sumaCifre(char* nr)
{
    int s = 0;
    for (char *c = nr; *c; c++)
            s += codCifra(*c);
    return s;
}
char cifraControl(char* nr, int baza)
{
    char sc[LGINT];
    convertesteNumarDinBazaZeceInBaza(baza, sumaCifre(nr), sc);
    while (strlen(sc) > 1)
        convertesteNumarDinBazaZeceInBaza(baza, sumaCifre(sc), sc);
    return sc[0];
}
int ceaMaiMicaBaza(char* nr)
{
    int c, b=1;
    for (int i = 0; nr[i]; i++)
    {
        c = codCifra(nr[i]);
        if (c > b) b = c;
    }
    return b+1;
}
// scor 100 - pbinfo
