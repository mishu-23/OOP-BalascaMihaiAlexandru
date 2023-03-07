#include <iostream>
#include "Canvas.h"

using namespace std;

//   ------------------------>  x
//  |
//  |
//  |
//  |
//  |
//  |
//  |
//  |
//  |
//  V  y

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    canvas = new char* [height];
    for (int i = 0; i < height; i++) {
        canvas[i] = new char[width];
        //i rows and j columns
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
            //row i, column j
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int cx = 0;
    int cy = ray;
    int d = 3 - 2 * ray;
    while (cx <= cy) {
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x + cx, y - cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x - cy, y - cx, ch);
        if (d < 0) {
            d = d + 4 * cx + 6;
        }
        else {
            d = d + 4 * (cx - cy) + 10;
            cy--;
        }
        cx++;
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    int x1 = x - ray;
    int x2 = x + ray;
    int y1 = y - ray;
    int y2 = y + ray;
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            int dx = j - x;
            int dy = i - y;
            if (dx * dx + dy * dy < ray * ray && canvas[i][j] == ' ') {
                SetPoint(j, i, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++)
    {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }

    for (int i = top + 1; i < bottom; i++)
    {
        SetPoint(left, i, ch);
        SetPoint(right, i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left + 1; i < right; i++)
        for (int j = top + 1; j < bottom; j++)
            SetPoint(i, j, ch);
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x <= width || y >= 0 && y <= height)
        canvas[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) {
            break;
        }
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
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            cout << canvas[i][j] << ' ';
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            SetPoint(i, j, ' ');
}