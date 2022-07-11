//
// Created by hefan on 2022/5/30.
//
#include "../SequentialStack.h"

/**
 * 栈的应用一——括号匹配
 * 判断表达式括号是否匹配
 * @param c char 类型数组 c,括号数组‘{}’，‘[]’，‘()’，‘#’为结束符
 * @return 返回 1 为匹配，返回 0 为不匹配
 */
int matchBrackets(char c[]) {
    int i = 0;
    SequentialStack st;
    init(&st);
    while (c[i] != '#') {
        switch (c[i]) {
            case '{':
            case '[':
            case '(':
                push(&st, c[i]);
                break;
            case '}':
                if (!empty(st) && read(st) == '{') {
                    pop(&st);
                    break;
                } else {
                    return 0;
                }
            case ']':
                if (!empty(st) && read(st) == '[') {
                    pop(&st);
                    break;
                } else {
                    return 0;
                }
            case ')':
                if (!empty(st) && read(st) == '(') {
                    pop(&st);
                    break;
                } else {
                    return 0;
                }
        }
        i++;
    }
    return empty(st);//栈为空则匹配，否则不匹配
}

/**
 * 将数字字符转变成相应的数
 * @param f char 类型数组 f,数字字符数组
 * @param i 指向 int 类型变量的指针 i
 * @return 返回数字字符串对应的数
 */
double readNumber(char f[], int *i) {
    double x = 0.0;
    int k = 0;
    //处理整数部分
    while (f[*i] >= '0' && f[*i] <= '9') {
        x = x * 10 + (f[*i] - '0');
        (*i)++;
    }

    //处理小数部分
    if (f[*i] == '.') {
        (*i)++;
        while (f[*i] >= '0' && f[*i] <= '9') {
            x = x * 10 + (f[*i] - '0');
            (*i)++;
            k++;
        }
    }

    while (k != 0) {
        x /= 10.0;
        k--;
    }
    return (x);
}

/**
 * 求一个后缀表达式的值
 * @param f char 类型数组 f,后缀表达式数组,'#'结尾
 * @return 返回后缀表达式的值
 */
double suffixCalculate(char f[]) {
    /**
     * 操作数栈
     */
    double operandStack[100];
    int top = 0;
    int i = 0;
    /**
     * 左右两个操作数
     */
    double x1, x2;
    while (f[i] != '#') {
        if (f[i] >= '0' && f[i] <= '9') {
            operandStack[top] = readNumber(f, &i);
            top++;
        } else if (f[i] == ' ') {
            i++;
        } else if (f[i] == '+') {
            x2 = operandStack[--top];
            x1 = operandStack[--top];
            operandStack[top] = x1 + x2;
            top++;
            i++;
        } else if (f[i] == '-') {
            x2 = operandStack[--top];
            x1 = operandStack[--top];
            operandStack[top] = x1 - x2;
            top++;
            i++;
        } else if (f[i] == '*') {
            x2 = operandStack[--top];
            x1 = operandStack[--top];
            operandStack[top] = x1 * x2;
            top++;
            i++;
        } else if (f[i] == '/') {
            x2 = operandStack[--top];
            x1 = operandStack[--top];
            operandStack[top] = x1 / x2;
            top++;
            i++;
        }
    }
    return operandStack[0];
}

/**
 * 判断一个字符是否为运算符
 * @param operator char 类型变量
 * @return 返回 1 表示是运算符，否则不是
 */
int isOperator(char operator) {
    switch (operator) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

/**
 * 求运算符的优先级
 * @param operator 运算符
 * @return 返回各运算符的优先级
 */
int operatorPriority(char operator) {
    switch (operator) {
        case '#':
            return -1;
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

/**
 * 将一个中缀表达式 infix 转换为与它相等的后缀表达式 suffix
 * @param infix 中缀表达式,'#'结尾
 * @param suffix 后缀表达式，'#'结尾
 */
void infixToSuffix(char infix[], char suffix[]) {
    int i = 0, j = 0;
    /**
     * 操作符栈
     */
    char operatorStack[100];
    int top, t;
    top = 0;
    operatorStack[top] = '#';
    top++;

    while (infix[i] != '#') {
        if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
            //遇到数字或小数点直接写入后缀表达式
            suffix[j++] = infix[i];
        } else if (infix[i] == '(') {
            //遇到左括号将其进栈
            operatorStack[top++] = infix[i];
        } else if (infix[i] == ')') {
            //遇到右括号将其对应的左括号后的操作符全部写入后缀表达式
            t = top - 1;
            while (operatorStack[t] != '(') {
                suffix[j++] = operatorStack[--top];
                t = top - 1;
            }
            //'('出栈
            top--;
        } else if (isOperator(infix[i])) {
            //用空格分开连个操作数，一个操作数由多个数组元素存储，故要分开
            suffix[j++] = ' ';
            //当所遇到的是操作符，且优先级小于等于栈顶元素的优先级时，弹出所有小于当前操作符的优先级的栈顶元素加入到后缀表达式
            while (operatorPriority(infix[i]) <= operatorPriority(operatorStack[top - 1])) {
                suffix[j++] = operatorStack[--top];
            }
            //当所遇到的是操作符，且优先级大于栈顶元素的优先级时,进栈
            operatorStack[top++] = infix[i];
        }
        //处理下一个中缀表达元素
        i++;
    }
    while (top) {
        suffix[j++] = operatorStack[--top];
    }
}

int main() {
    /*
     * 栈测试
     */
    SequentialStack st;
    init(&st);
    push(&st, 5);
    push(&st, 8);
    push(&st, 9);
    datatype t = read(st);
    printf("栈测试:\n读栈顶:t = %d\n", t);//9
    pop(&st);
    printf("出栈后读栈顶t = %d\n", read(st));//8

    /*
     * 栈的应用一——括号匹配
     */
    char c[] = {
            '{', '{', '[', '(', ')', ']', '}', '}', '#'
    };
    printf("栈的应用一——括号匹配: %d", matchBrackets(c));


    /*
     * 栈顶的应用二——算术表达式求值
     */
    /**
     * 中缀表达式
     */
    char infix[] = {
            '3', '/', '(', '5', '*', '2', '+', '1', ')', '#'
    };
    char suffix[100];
    printf("\n栈顶的应用二——算术表达式求值:\ninfix：%s", infix);
    infixToSuffix(infix, suffix);
    printf("\nsuffix：%s", suffix);

    printf("\n3/(5*2+1) = %lf", suffixCalculate(suffix));
    return 0;
}