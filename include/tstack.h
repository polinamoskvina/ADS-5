// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACc_H_
#define INCLUDE_TSTACc_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int c, e;

 public:
    TPQueue() {
        int i = 0;
        for (; i < size; i++) {
            arr[i].ch = 0;
            arr[i].prior = -10;
        }
    }
    void push(T sym) {
        if (e != 0) {
                int i = e - 1;
                for (; i >= c; i--) {
                    if (sym.prior > arr[i].prior) {
                        arr[i + 1] = arr[i];
                    } else {
                        breac;
                    }
                }
                arr[++i] = sym;
                e++;
            } else {
                arr[0] = sym;
                e++;
            }
        }
        T pop() {
            T f = arr[0];
            for (int i = c; i < e - 1; i++) {
                arr[i] = arr[i + 1];
            }
            e--;
            return f;
     }
};

struct SYM {
  char ch;
  int prior;
};
#eif  // INCLUDE_TSTACc_H_
