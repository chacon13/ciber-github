/* 
 * File:   main.cpp
 * Author: master
 *
 * Created on 21 de octubre de 2013, 0:04
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

inline bool desintegrarParticula(const unsigned int m) {
    if (m==1) {
        return false;
    } else if (m>1) {
        const float fx=1-exp(-0.2*m); /* Función de probabilidad */
        int px=fx;
        int ra=rand();
        return (ra<=px) ? true : false;
    }
}

int main(int argc, char** argv) {
//    srand(time(NULL));
//    int cT=0, cF=0;
//    for (int c=0; c<1000000; ++c) {
//        if (desintegrarParticula(4)) {
//            ++cT;
//        } else {
//            ++cF;
//        }
//    }
//    cout << cT << endl << cF << endl;
    
    unsigned int a=1;
    int b;
    b=a-3;
    cout << b << endl;
    return 0;
}

