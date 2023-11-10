#include <fstream>
#include <cstring>
#define NR_MAX_CIFRE 100001
#define LGINT 11
using namespace std;
ifstream fin("cifrab.in");
ofstream fout("cifrab.out");
int codCifra(char);
char codLitera(int);
bool cifra(char);
int ceaMaiMicaBaza(char [NR_MAX_CIFRE]);
char cifraControl(char [NR_MAX_CIFRE], int);
int main()
{
    char nr[NR_MAX_CIFRE];
    int baza;
    fin.getline(nr, NR_MAX_CIFRE);
    fin.close();
    baza = ceaMaiMicaBaza(nr);
    fout << baza << endl << cifraControl(nr, baza);
    fout.close();
    return 0;
}
void convertesteNumarDinBazaZeceInBaza(int baza, int nr, char rez[])
{
    int r[LGINT], n, i;
    char s[LGINT];
    for (n = 0; nr; nr /= baza) r[n++] = nr % baza;
    strcpy(rez, "");
    for (i = n-1; i >= 0; i--) rez[n-i-1] = codLitera(r[i]);
    rez[n] = 0;
}
int sumaCifre(char nr[NR_MAX_CIFRE])
{
    int s = 0;
    for (char *c = nr; *c; c++)
            s += codCifra(*c);
    return s;
}
char cifraControl(char nr[NR_MAX_CIFRE], int baza)
{
    char sc[LGINT];
    convertesteNumarDinBazaZeceInBaza(baza, sumaCifre(nr), sc);
    while (strlen(sc) > 1)
        convertesteNumarDinBazaZeceInBaza(baza, sumaCifre(sc), sc);
    return sc[0];
}
int ceaMaiMicaBaza(char nr[NR_MAX_CIFRE])
{
    int c, b=1;
    for (int i = 0; nr[i]; i++)
    {
        c = codCifra(nr[i]);
        if (c > b) b = c;
    }
    return b+1;
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
// scor 0 - "could not evaluate output"
