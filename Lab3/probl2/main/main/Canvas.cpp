#include "Canvas.h"
#include <iostream>
#include <math.h>

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    canvas = new char* [height];

    for (int i = 0; i < height; ++i) {
        canvas[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            canvas[i][j] = ' ';
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (pow(i - y, 2) + pow(j - x, 2) == pow(ray, 2))
                canvas[i][j] = ch;
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    if (y + ray <= height && x + ray <= width) {
        for (int i = y - ray; i <= y + ray; i++) {
            for (int j = x - ray; j <= x + ray; j++) {
                if (pow(i - y, 2) + pow(j - x, 2) <= pow(ray, 2) && canvas[i][j] == ' ')
                    canvas[i][j] = ch;
            }
        }
    }

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(right, top, right, bottom, ch);
    DrawLine(right, bottom, left, bottom, ch);
    DrawLine(left, bottom, left, top, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            if (canvas[i][j] == ' ')
                SetPoint(j, i, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        canvas[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << canvas[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
        }
    }
}