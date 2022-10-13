
#include <iostream>
using namespace std;
#include <string>
bool uyeEPostaCheck(string ePosta) {
    for (size_t i = 0; i < sizeof(ePosta); i++)
    {
        if (ePosta[i] == '@') {
            int atInYeri = i;
            break;
        }
    }
    string atDenSonra = ePosta.substr(i);
}