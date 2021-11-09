#include <iostream>
#include <ctime>
#include <string>

using namespace std;

unsigned long units(unsigned long& x, unsigned long& y){ //еденицы

    string a = to_string(x);
    string b = to_string(y);
    int c = 0;
    int c1 = 0;
    for (int i = 0; i < 10; i++){
        if (a[i] == '1') {
            c += 1;
        }
        if (b[i] == '1') {
            c1 += 1;
        }
    }
    if (c > c1){
        return x;
    }
    else if (c < c1) {
        return y;
    }
    else return 5;
}

unsigned long sum(unsigned long& x, unsigned long& y){

    string a = to_string(x);
    string b = to_string(y);
    string c;
    for (int i = 0; i < 10; i++){
        if ((a[i] == '1') || (b[i] == '1')){
            c += '1';
        }
        else c += '0';
    }
    return stol(c); // перевод строки в число
}

int main()
{
    srand(time(NULL));
    unsigned long a = 1, b = 1, c = 1;
    int number = 0;
    int epochs;
    cout << "Write number of epochs: " << endl;
    cin >> epochs;
    for (int i = 0; i < 9; i++){
        a *= 10;
        a += rand() % 2;
        b *= 10;
        b += rand() % 2;
        c *= 10;
        c += rand() % 2;
    }
    cout << "    initial epoch   "<<endl;
    cout << "a --- " << a << endl << "b --- " << b << endl << "c --- " << c << endl;
    for (int i = 1; i <= epochs; i++){
        cout << "________________" << endl;
        number = rand()%3;
        if (number == 0){
            unsigned long z = units(a, b);
            if (z == a && b < sum(a, b)){
                b = sum(a, b);
            }
            else if (z == b && a < sum(a, b)){
                a = sum(a, b);
            }
            else {
                unsigned long tmp = sum(a, b);
                a = tmp;
                b = tmp;
            }
            cout<<" a + b,  "<<i<<"  epoch"<<endl;
        }
        if (number == 1){
            unsigned long z = units(b, c);
            if (z == b && c < sum(b, c)){
                c = sum(b, c);
            }
            else if (z == c && b < sum(b, c)){
                b = sum(b, c);
            }
            else {
                unsigned long tmp = sum(b, c);
                b = tmp;
                c = tmp;
            }
            cout<<" b + c,  "<<i<<"  epoch"<<endl;
        }
        if (number == 2){
            unsigned long z = units(a, c);
            if (z == a && c < sum(a, c)){
                c = sum(a, c);
            }
            else if (z == c && a < sum(a, c)){
                a = sum(a, c);
            }
            else {
                unsigned long tmp = sum(a, c);
                a = tmp;
                c = tmp;
            }
            cout<<" a + c,  "<<i<<"  epoch"<<endl;
        }
        cout << "a --- " << a << endl << "b --- " << b << endl << "c --- " << c << endl;
    }
    return 0;
}
