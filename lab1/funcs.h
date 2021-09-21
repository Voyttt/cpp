#ifndef funcs_h
#define funcs_h

namespace Data {
    typedef struct Val {
        unsigned int y;
        int value;

        struct Val* next;
    }Val;

    typedef struct Matrix {
        Val** data;
        Val** cur;

        unsigned int size;
    }Matrix;
}

using namespace Data;

const int read_matrix(Matrix* M, int m);

const int read_real_matrix(Matrix* M, bool f);

Matrix* init_matrix(int n, int m, bool f);

const int get_value(const char* k);

void clear_matrix(Matrix* M);

Matrix* mod_matrix(Matrix* M);
#endif //funcs_hpp