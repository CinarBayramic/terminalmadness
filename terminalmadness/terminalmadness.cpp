// terminalmadness.cpp : main class

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>

int main(int argc, char* argv[])
{
    int camX;
    int camY;
    char symbols[3] = {'#','*','P'};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    std::vector<std::vector<int>> grid(columns, std::vector<int>(rows, 0));
    camX = columns / 2;
    camY = rows / 2;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("*");
            grid[j][i] = 1;
        }
        printf("\n");
    }
    printf("continue? (enter anything except empty)\n");
    bool contprog = false;
    scanf_s("\n");
    printf("\n");
    while (true) {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int new_columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int new_rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        // Check if console window size has changed
        if (new_columns >= columns && new_rows >= rows) {
            columns = new_columns;
            rows = new_rows;
        } else if (new_columns >= columns && new_rows <= rows) {
            columns = new_columns;
        } else if (new_columns <= columns && new_rows >= rows) {
            rows = new_rows;
        }
        grid.resize(columns + 2, std::vector<int>(rows + 2, 0));
        //printf("columns: %d, rows: %d\n", columns,rows);
        for (int i = 0; i < new_rows; i++) {
            for (int j = 0; j < new_columns; j++) {
                printf("%c",symbols[grid[j][i]]);
            }
            printf("\n");
        }
        Sleep(50);
        system("cls");
    }
    return 0;
}