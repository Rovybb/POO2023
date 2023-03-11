#include "Canvas.h"
#include <iostream>

using namespace std;

int main()
{
    int width, height;
    cout << "Enter canvas width: ";
    cin >> width;
    cout << "Enter canvas height: ";
    cin >> height;
    Canvas canvas = Canvas(width, height);

    bool running = true;
    while (running)
    {
        cout << "0 - Exit" << endl;
        cout << "1 - Draw a circle" << endl;
        cout << "2 - Draw a rectangle" << endl;
        cout << "3 - Draw a line" << endl;
        cout << "4 - Draw a point" << endl;
        cout << "5 - Print canvas" << endl;
        cout << "6 - Clear canvas" << endl;
        cout << endl << "Enter instruction: ";
        int instr;
        cin >> instr;
        while (instr < 0 || instr > 6) {
            cout << endl << "Error: invalid instruction. Try again: ";
            cin >> instr;
        }
        switch (instr)
        {
        case 0: {
            running = false;
            break;
        }

        case 1: {
            cout << "Enter the values for circle's center coordinates, ray length and the character to draw: " << endl;
            int x, y, ray;
            char ch;
            cin >> x >> y >> ray >> ch;
            cout << "Do you want to fill the circle? Y/N ";
            char response;
            cin >> response;
            while (response != 'y' && response != 'n' && response != 'Y' && response != 'N') {
                cout << "Error: invalid instruction. Do you want to fill the circle? Y/N ";
                cin >> response;
            }
            if (response == 'y' || response == 'Y') {
                canvas.FillCircle(x, y, ray, ch);
            }
            else {
                canvas.DrawCircle(x, y, ray, ch);
            }
            break;
        }
        case 2: {
            cout << "Enter the values for rectangle's boundaries(left, top, rigth, bottom) and the character to draw: " << endl;
            int left, top, rigth, bottom;
            char ch;
            cin >> left >> top >> rigth >> bottom >> ch;
            cout << "Do you want to fill the rectangle? Y/N ";
            char response;
            cin >> response;
            while (response != 'y' && response != 'n' && response != 'Y' && response != 'N') {
                cout << "Error: invalid instruction. Do you want to fill the rectangle? Y/N ";
                cin >> response;
            }
            if (response == 'y' || response == 'Y') {
                canvas.FillRect(left, top, rigth, bottom, ch);
            }
            else {
                canvas.DrawRect(left, top, rigth, bottom, ch);
            }
            break;
        }
        case 3: {
            cout << "Enter the coordinates for both ends of the line and the character to draw: " << endl;
            int x1, y1, x2, y2;
            char ch;
            cin >> x1 >> y1 >> x2 >> y2 >> ch;
            canvas.DrawLine(x1, y1, x2, y2, ch);
            break;
        }
        case 4: {
            cout << "Enter point coordinates and the character to draw: " << endl;
            int x, y;
            char ch;
            cin >> x >> y >> ch;
            canvas.SetPoint(x, y, ch);
            break;
        }
        case 5: {
            canvas.Print();
            break;
        }
        case 6: {
            canvas.Clear();
            cout << "Canvas cleared" << endl;
            break;
        }
        default:
            break;
        }
    }

    return 0;
}