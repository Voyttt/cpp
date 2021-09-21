#include "funcs.h"

#include <iostream>

using namespace Data;
using namespace std;

const int get_value(const char* k) {
    while(true) {
        cout << k;
        int n;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(5534, '\n');
            cout << "Try again: ";
        }
        else return n;
    }
}

unsigned int sum_count(int n) {
    unsigned int d = 0;
    while (n > 0) {
        d += n % 10;
        n /= 10;
    }
    return d;
}

const int read_matrix(Matrix* M, int m){
    for (int i = 0; i < M->size; i++) {
        cout << "String " << i + 1 << ": ";
        if (!M->data[i]) {cout << "\n"; continue;}
        Val* v = M->data[i];
        for (int j = 0; j < m; j ++){
            if (v && v->y != j) cout << "0 ";
            else{
                cout << v->value << " ";
                v = v->next;
            }
        }
        cout << endl;
    }
    return 0;
}

const int read_real_matrix(Matrix* M, bool f){
    for (int i = 0; i < M->size; i++) {
        cout << "String " << i + 1 << ": ";
        if (!M->data[i]) {cout << "\n"; continue;}
        Val* v = M->data[i];

        while (v){
            //for (int i = 0; i < 2; i ++){
            if (f) cout << "(" << v->value << ", " << v->y << ") ";
            else cout << v->value << " ";
            v = v->next;
        }
        cout << endl;
    }
    return 0;
}

void add_values(Matrix* M, int m){
    int k;
    Val* v;
    for (int i = 0; i < M->size; i++) {
        cout << "Enter " << i + 1 << " string: ";
        for (int j = 0; j < m; j++) {
            if ((k = get_value("")) != 0) {
                v = new Val;
                v->value = k;
                v->y = j;
                v->next = NULL;
                if (!(M->data[i])) {
                    M->data[i] = v;
                    M->data[i]->next = v->next;
                    M->cur[i] = v;}
                else {
                    M->cur[i]->next = v;
                    M->cur[i] = M->cur[i]->next;}
            }
        }
    }
}

Matrix* mod_matrix(Matrix* M){
    Matrix* NM = init_matrix(M->size, 0, 0);
    for (int i = 0; i < M->size; i++){
        if (!M->data[i]) continue;
        Val* v = M->data[i];
        int n = sum_count(M->cur[i]->value);
        while (v->next){
            //cout << v->value << "\n";
            if ((sum_count(v->value) == n)){
                Val* qv = new Val;
                qv->value = v->value;
                qv->next = NULL;
                //cout << "DD\n";
                //cout << "----" << qv->value << "\n";
                if (!(NM->data[i])) {
                    NM->data[i] = qv;
                    NM->data[i]->next = qv->next;
                    NM->cur[i] = qv;
                }
                else {
                    NM->cur[i]->next = qv;
                    NM->cur[i] = NM->cur[i]->next;

                }
            }
            v = v->next;
        }
        Val* qv = new Val;
        qv->value = M->cur[i]->value;
        qv->next = NULL;
        if (!(NM->data[i])) {
            NM->data[i] = qv;
            NM->data[i]->next = NULL;
        }
        else{
            NM->cur[i]->next = qv;
            NM->cur[i] = NM->cur[i]->next;
            NM->cur[i]->next = NULL;
        }
    }
    return NM;
}

Matrix* init_matrix(int n, int m, bool f) {
    Matrix* M = new Matrix;
    M->data = new Val*[n];
    M->cur = new Val*[n];
    M->size = n;
    if (f) add_values(M, m);
    return M;
}

void clear_matrix(Matrix* M){
    //cout << "----" << M->size << "\n";
    for (int i = 0; i < M->size; i ++){
        if (!M->data[i]) continue;
        Val* v = M->data[i];
        //cout << M->data[1]->value << "\n";
        //cout << v->value << "\n";
        Val* qv;
        while(v){
            //cout << v->value;
            qv = v->next;
            delete v;
            v = qv;
        }
        //cout << endl;

    }
    delete[] M->data;
    delete[] M->cur;
    delete M;
}//
// Created by anton on 21.09.2021.
//

