#include "Number.h"
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

using namespace std;

Number::Number(const char* value, int base) {
	if (base < 2 || base > 16) {
		this->value = new char[strlen(value) + 1];
		strcpy(this->value, value);
		this->base = base;
	}
	else {
		cerr << "Base is not between 2 and 16";
	}
}

Number::~Number() {
	if (value != nullptr) {
		delete[] value;
		value = nullptr;
		base = NULL;
	}
}

Number::Number(const Number& copyNumber) {
	this->value = new char[strlen(copyNumber.value) + 1];
	strcpy(this->value, copyNumber.value);
	this->base = copyNumber.base;
}

Number::Number(Number&& moveNumber) {
	this->value = moveNumber.value;
	this->base = moveNumber.base;
	moveNumber.value = nullptr;
	moveNumber.base = NULL;
}

int Number::GetBase() {
	return base;
}

int Number::GetDigitsCount() {
	return strlen(value);
}

void Number::Print() {
	cout << value;
}

void Number::SwitchBase(int newBase) {
	int multiply = 1;
	int newIntValue = 0;
	for (int i = strlen(value) - 1; i >= 0; i--) {
		if (isalpha(value[i])) {
			newIntValue += (value[i] - 'A' + 10) * multiply;
		}
		else {
			newIntValue += (value[i] - '0') * multiply;
		}
		multiply *= base;
	}
	char newValue[256];
	newValue[0] = NULL;
	while (newIntValue) {
		int rest = newIntValue % newBase;
		newIntValue /= newBase;
		for (int i = 1; i <= strlen(newValue); i++) {
			newValue[i] = newValue[i - 1];
		}
		if (rest <= 9) {
			newValue[0] = rest + '0';
		}
		else {
			newValue[0] = rest + 'A' - 10;
		}
	}
	delete[] value;
	value = (char*)realloc(value, strlen(newValue + 1));
	strcpy(value, newValue);
	base = newBase;
}

Number operator+ (const Number& n1, const Number& n2) {
	Number firstNumber = n1;
	Number secondNumber = n2;
	int newBase, size = 0, res = 0, aux = 0, power = 1, index = 1;
    if (n1.base > n2.base) {
		newBase = n1.base;
    }
    else {
		newBase = n2.base;
    }
	firstNumber.SwitchBase(10);
	secondNumber.SwitchBase(10);
    for (int i = firstNumber.GetDigitsCount() - 1; i >= 0; i--) {
		aux = ((int)firstNumber.value[i] - '0') * power + aux, power *= 10;
    }
	res += aux;
	power = 1, aux = 0;
    for (int i = secondNumber.GetDigitsCount() - 1; i >= 0; i--) {
		aux = ((int)secondNumber.value[i] - '0') * power + aux, power *= 10;
    }
	res += aux;
	aux = res;
    while (aux) {
		aux /= 10, size++;
    }
	char* auxValue = new char[size];
	auxValue[size] = 0;
    while (res) {
		auxValue[size - index] = (char)(res % 10 + '0'), res /= 10, index++;
    }
	Number result(auxValue, 10);
	result.SwitchBase(newBase);
	return result;
}
Number operator+ (const Number& n1, int n2) {
    Number firstNumber = n1;
    int size = 0, res = n2, aux = 0, power = 1, index = 1;
    firstNumber.SwitchBase(10);
    for (int i = firstNumber.GetDigitsCount() - 1; i >= 0; i--) {
        aux = ((int)firstNumber.value[i] - '0') * power + aux, power *= 10;
    }
    res += aux;
    aux = res;
    while (aux) {
        aux /= 10, size++;
    }
    char* auxValue = new char[size];
    auxValue[size] = 0;
    while (res) {
        auxValue[size - index] = (char)(res % 10 + '0'), res /= 10, index++;
    }
    Number result(auxValue, 10);
    result.SwitchBase(n1.base > 10 ? n1.base : 10);
    return result;
}

Number operator+ (int n1, const Number& n2) {
    Number firstNumber = n2;
    int size = 0, res = n1, aux = 0, power = 1, index = 1;
    firstNumber.SwitchBase(10);
    for (int i = firstNumber.GetDigitsCount() - 1; i >= 0; i--) {
        aux = ((int)firstNumber.value[i] - '0') * power + aux, power *= 10;
    }
    res += aux;
    aux = res;
    while (aux) {
        aux /= 10, size++;
    }
    char* auxValue = new char[size];
    auxValue[size] = 0;
    while (res) {
        auxValue[size - index] = (char)(res % 10 + '0'), res /= 10, index++;
    }
    Number result(auxValue, 10);
    result.SwitchBase(n2.base > 10 ? n2.base : 10);
    return result;
}

Number operator- (const Number& n1, const Number& n2) {
    Number firstNumber = n1;
    Number secondNumber = n2;
    int newBase, size = 0, res = 0, aux = 0, power = 1, index = 1;
    if (n1.base > n2.base) {
        newBase = n1.base;
    }
    else {
        newBase = n2.base;
    }
    firstNumber.SwitchBase(10);
    secondNumber.SwitchBase(10);
    for (int i = firstNumber.GetDigitsCount() - 1; i >= 0; i--) {
        aux = ((int)firstNumber.value[i] - '0') * power + aux, power *= 10;
    }
    res += aux;
    power = 1, aux = 0;
    for (int i = secondNumber.GetDigitsCount() - 1; i >= 0; i--) {
        aux = ((int)secondNumber.value[i] - '0') * power + aux, power *= 10;
    }
    res -= aux;
    aux = res;
    while (aux) {
        aux /= 10, size++;
    }
    char* auxValue = new char[size];
    auxValue[size] = 0;
    while (res) {
        auxValue[size - index] = (char)(res % 10 + '0'), res /= 10, index++;
    }
    Number result(auxValue, 10);
    result.SwitchBase(newBase);
    return result;
}

Number operator- (const Number& n1, int n2) {
    Number firstNumber = n1;
    int size = 0, res = 0 - n2, aux = 0, power = 1, index = 1;
    firstNumber.SwitchBase(10);
    for (int i = firstNumber.GetDigitsCount() - 1; i >= 0; i--) {
        aux = ((int)firstNumber.value[i] - '0') * power + aux, power *= 10;
    }
    res += aux;
    aux = res;
    while (aux) {
        aux /= 10, size++;
    }
    char* auxValue = new char[size];
    auxValue[size] = 0;
    while (res) {
        auxValue[size - index] = (char)(res % 10 + '0'), res /= 10, index++;
    }
    Number result(auxValue, 10);
    result.SwitchBase(n1.base > 10 ? n1.base : 10);
    return result;
}

Number operator- (int n1, const Number& n2) {
    Number firstNumber = n2;
    int size = 0, res = n1, aux = 0, power = 1, index = 1;
    firstNumber.SwitchBase(10);
    for (int i = firstNumber.GetDigitsCount() - 1; i >= 0; i--) {
        aux = ((int)firstNumber.value[i] - '0') * power + aux, power *= 10;
    }
    res -= aux;
    aux = res;
    while (aux) {
        aux /= 10, size++;
    }
    char* auxValue = new char[size];
    auxValue[size] = 0;
    while (res) {
        auxValue[size - index] = (char)(res % 10 + '0'), res /= 10, index++;
    }
    Number result(auxValue, 10);
    result.SwitchBase(n2.base > 10 ? n2.base : 10);
    return result;
}

void Number::operator= (const Number& copy) {
    if (this->value != nullptr)
    {
        delete[] this->value;
        this->value = nullptr;
    }
    this->value = new char[strlen(copy.value) + 1];
    strcpy(this->value, copy.value);
    this->base = copy.base;
}

void Number::operator= (int num) {
    int newBase = 10, digit, size = 1, x = num;
    if (base < 10) {
        newBase = 10;
    }
    else {
        newBase = base;
    }

    while (x > 0) {

        digit = x % newBase;

        if (digit >= 0 && digit <= 9) {
            value[size - 1] = (char)(digit + '0');
        }
        else {
            value[size - 1] = (char)(digit - 10 + 'A');
        }
        size++;
        value = (char*)realloc(value, size);
        x /= newBase;
    }
    value[size - 1] = 0;
    std::reverse(value, value + strlen(value));
    base = newBase;
}

void Number::operator+= (const Number& n) {
    Number aux = (*this) + n;
    *this = aux;
}

void Number::operator-= (const Number& n) {
    Number aux = (*this) - n;
    *this = aux;
}

void Number::operator+= (int n) {
    *this = (*this) + n;
}

void Number::operator-= (int n) {
    *this = (*this) - n;
}

void Number::operator-- () {
    memmove(value, value + 1, strlen(value));
}

void Number::operator-- (int p) {
    if (strlen(value))
        value[strlen(value) - 1] = NULL;
}

bool Number::operator== (Number& n) {
    Number aux = *this;
    aux.SwitchBase(n.base);

    if (aux.GetDigitsCount() != n.GetDigitsCount())
        return false;
    for (int i = aux.GetDigitsCount(); i > 0; i--)
        if (int(aux.value[i]) != int(aux.value[i]))
        {
            return false;
        }
    return true;
}

bool Number::operator!= (Number& n) {
    unsigned int eq = 0;
    Number aux = *this;
    aux.SwitchBase(n.base);

    if (aux.GetDigitsCount() != n.GetDigitsCount())
        return true;
    for (int i = aux.GetDigitsCount(); i > 0; i--)
        if (int(aux.value[i]) == int(aux.value[i]))
        {
            eq++;
        }
    return (eq == aux.GetDigitsCount() ? true : false);
}

bool Number::operator< (Number& n) {
    Number aux = *this;
    aux.SwitchBase(n.base);

    if (aux.GetDigitsCount() < n.GetDigitsCount())
        return true;
    if (aux.GetDigitsCount() > n.GetDigitsCount())
        return false;
    if (aux == n)
        return false;
    for (int i = Number::GetDigitsCount(); i > 0; i--)
        if (int(aux.value[i]) < int(n.value[i]))
        {
            return true;
        }
    return false;
}

bool Number::operator<= (Number& n) {
    Number aux = *this;
    aux.SwitchBase(n.base);

    if (aux.GetDigitsCount() < n.GetDigitsCount())
        return true;
    if (aux.GetDigitsCount() > n.GetDigitsCount())
        return false;
    if (aux == n)
        return true;
    for (int i = Number::GetDigitsCount(); i > 0; i--)
        if (int(aux.value[i]) < int(n.value[i]))
        {
            return true;
        }
    return false;
}

bool Number::operator> (Number& n) {
    Number aux = *this;
    aux.SwitchBase(n.base);

    if (aux.GetDigitsCount() > n.GetDigitsCount())
        return true;
    if (aux.GetDigitsCount() < n.GetDigitsCount())
        return false;
    if (aux == n)
        return false;
    for (int i = Number::GetDigitsCount(); i > 0; i--)
        if (int(aux.value[i]) > int(n.value[i]))
        {
            return true;
        }
    return false;
}

bool Number::operator>= (Number& n) {
    Number aux = *this;
    aux.SwitchBase(n.base);

    if (aux.GetDigitsCount() > n.GetDigitsCount())
        return true;
    if (aux.GetDigitsCount() < n.GetDigitsCount())
        return false;
    if (aux == n)
        return true;
    for (int i = Number::GetDigitsCount(); i > 0; i--)
        if (int(aux.value[i]) > int(n.value[i]))
        {
            return true;
        }
    return false;
}