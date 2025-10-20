#include "Ej1.cpp"
#include <iostream>

void simuldados(double n){
    double uno = 0, dos = 0, tres = 0, cuatro = 0, cinco = 0, seis = 0;
    for (int i = 0; i <= n; ++i){
        int aux = num_aleat_a_b(1, 6);
        switch(aux)
        {
            case 1:
                uno++;
                break;
            case 2:
                dos++;
                break;
            case 3:
                tres++;
                break;
            case 4:
                cuatro++;
                break;
            case 5:
                cinco++;
                break;
            case 6:
                seis++;
                break;
        }
    }

    cout << "1 -> " << uno/n*100 << endl;
    cout << "2 -> " << dos/n*100 << endl;
    cout << "3 -> " << tres/n*100 << endl;
    cout << "4 -> " << cuatro/n*100 << endl;
    cout << "5 -> " << cinco/n*100 << endl;
    cout << "6 -> " << seis/n*100 << endl;
}

int main(){
    simuldados(10000000);
    return 0;
}