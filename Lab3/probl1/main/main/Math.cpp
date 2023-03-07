#include "Math.h"
#include <cstdarg>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

int Math::Add(int x, int y) {
	return x + y;
}
int Math::Add(int x, int y, int z) {
	return x + y + z;
}
int Math::Add(double x, double y) {
	return x + y;
}
int Math::Add(double x, double y, double z) {
	return x + y + z;
}

int Math::Mul(int x, int y) {
	return x * y;
}
int Math::Mul(int x, int y, int z) {
	return x * y * z;
}
int Math::Mul(double x, double y) {
	return x * y;
}
int Math::Mul(double x, double y, double z) {
	return x * y * z;
}

int Math::Add(int count, ...) {
	int result = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		result += va_arg(args, int);
	}
	va_end(args);
	return result;
}

char* Math::Add(const char* string1, const char* string2) {
	if (!string1 || !string2) {
		return nullptr;
	}
	else {
		char result[256];
		strcpy(result, string1);
		strcat(result, string2);
		return result;
	}
}