#include <iostream>
#include <time.h>
#include <tuple>
#include <bitset>


int log2(int n) {
    int x = 0;
    while (n > 0) {
        n = n & (n-1);
        ++x;
    }
    return x;
}
int get_rand() {
    return rand() % 1024;
}

void print_swap(int from, int tob) {

}
void print(int num, std::string label) {
    std::bitset<10> b_num(num);
    std::cout << label << ": " << b_num << " : " << log2(num) <<"\t|" << std::endl;
}

std::tuple<int, int> process(int a, int b) {
    int d = a | b;
    int d_units = log2(d);

    print(d, "d");
    if (d_units > log2(a)) {
        print_swap(b, d);
        a = d;
    }
    else if (d_units > log2(b)) {
        print_swap(b, d);
        b = d;
    }

    return std::make_tuple(a, b);
}
int main() {
    using namespace std;
    srand((unsigned)time(NULL) );

    cout << "number of epochs: " << endl;
    int epochs = 0;
    cin >> epochs;

    int num = 0;
    int a, b, c = 0;
    a = get_rand();
    b = get_rand();
    c = get_rand();

    string operation [3] = {"a + b", "a + c", "b + c"};

    for (int i = 0; i < epochs; ++i) {
        num = rand() % 3;
        cout << i << ": " << num << " -> " << operation[num] <<"           |" << endl;
        print(a, "a");
        print(b, "b");
        print(c, "c");
        cout  << "\t\t\t|"<< endl;
        switch(num) {
            case 0: {
                tie(a, b) = process(a, b);
                break;
            }
            case 1: {
                tie(a, c) = process(a, c);
                break;
            }
            case 2: {
                tie(b, c) = process(b, c);
                break;
            }
        }
        cout << "-------------------------" << endl;
    }
    cout << "=========================" << endl;
    print(a, "a");
    print(b, "b");
    print(c, "c");
    cout << "=========================" << endl;

    return 0;
}