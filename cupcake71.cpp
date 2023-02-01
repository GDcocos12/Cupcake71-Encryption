#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string encode(string stri) {
    vector<int> nop;
    for (int i = 0; i < stri.length(); i++) {
        nop.push_back(int(stri[i]));
    }
    int num = 0;
    string code = "";
    for (int i = 0; i < nop.size(); i++) {
        while (true) {
            if (num + 30 < nop[i]) {
                num += 30;
                code += "7";
            }
            else if (num + 25 < nop[i]) {
                num += 25;
                code += "e";
            }
            else if (num + 20 < nop[i]) {
                num += 20;
                code += "k";
            }
            else if (num + 15 < nop[i]) {
                num += 15;
                code += "a";
            }
            else if (num + 10 < nop[i])
            {
                num += 10;
                code += "c";
            }
            else if (num + 5 < nop[i]) {
                num += 5;
                code += "p";
            }
            else if (num + 2 < nop[i]) {
                num += 2;
                code += "u";
            }
            else if (num + 1 < nop[i]) {
                num += 1;
                code += "C";
            }
            else {
                code += "1";
                num = 0;
                break;
            }
        }
    }
    return code;
}

string decode(string code) {
    string fin = "";
    int num = 0;
    string stri = "";
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == 'C') {
            num += 1;
        }
        else if (code[i] == 'u') {
            num += 2;
        }
        else if (code[i] == 'p') {
            num += 5;
        }
        else if (code[i] == 'c') {
            num += 10;
        }
        else if (code[i] == 'a') {
            num += 15;
        }
        else if (code[i] == 'k') {
            num += 20;
        }
        else if (code[i] == 'e') {
            num += 25;
        }
        else if (code[i] == '7') {
            num += 30;
        }
        else if (code[i] == '1') {
            num += 1;
            fin += char(num);
            num = 0;
        }
    }
    return fin;
}

int main()
{
    cout << "Welcome to Cupcake71 encoder/decoder!" << endl;
    int mode;
    cout << "Mode(1 - encode, 2 - decode): ";
    cin >> mode;
    if (mode == 1)
    {
        string stri;
        cout << "String to encode: ";
        cin >> stri;
        string fin = encode(stri);
        cout << fin << endl;
        system("pause");
    }
    else if (mode == 2)
    {
        string code;
        cout << "Code to decode: ";
        cin >> code;
        string stri = decode(code);
        cout << stri << endl;
        system("pause");
    }
    else
    {
        cout << "Error! Invalid mode." << endl;
        system("pause");
    }

    return 0;
}