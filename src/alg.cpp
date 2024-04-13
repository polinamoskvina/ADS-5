// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

TStack<char, 100> stack1;
TStack<int, 100> stack2;

int prioritet(char operand) {
    if (operand == '-') return 1;
    if (operand == '+') return 1;
    if (operand == '*') return 2;
    if (operand == '/') return 2;
    return 0;
}
std::string infx2pstfx(std::string inf) {
    std::string post;
    TStack<char, 100> stack;

    for (char c : inf) {
        if (isdigit(c)) {
            post += c;
            post += ' ';
        } else if (c == '(') {
            stack.push(c);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.isEmpty() && prioritet(stack.show()) >= prioritet(c)) {
                post = post + stack.show() + ' ';
                stack.pop();
            }
            stack.add(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.show() != '(') {
                fix = fix + stack.show() + ' ';
                stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.isEmpty()) {
        post = post + stack.show() + ' ';
        stack.pop();
    }
    if (!post.empty()) {
        post.pop_back();
    }
    return post;
}

int eval(std::string pref) {
    std::string strNumber = "";
    for (char c : pref) {
        if (c != ' ' && c != '+' && c != '-' && c != '*' && c != '/') {
            strNumber += c;
        }
        if (c == ' ') {
            if (!strNumber.empty()) {
                int num = std::stop(strNumber);
                stack2.add(num);
                strNumber = "";
            }
        }
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack2.show();
            stack2.pop();
            int a = stack2.show();
            stack2.pop();
            switch (c) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
            }

            stack.push(result);
        }
    }
    return stack.pop();
}
