#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // Para gerenciar o tamanho da janela no Windows

using namespace std;

// Função para mover o cursor para uma posição específica (X, Y)
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// Função para desenhar um "Tile" (Bloco)
void drawTile(int x, int y, int w, int h, string label, string colorCode) {
    // Define a cor de fundo e desenha o bloco
    for (int i = 0; i < h; i++) {
        gotoxy(x, y + i);
        cout << colorCode;
        for (int j = 0; j < w; j++) cout << " ";
    }
    // Escreve o nome do App no centro do bloco
    gotoxy(x + 1, y + h / 2);
    cout << label << "\033[0m"; // Reseta a cor
}

void drawStartScreen() {
    system("cls");
    // Cores ANSI: 44=Azul, 42=Verde, 41=Vermelho, 45=Roxo, 46=Ciano
    cout << "\033[1m  AetherOS - Start\033[0m\n\n";

    // Grade de Tiles (Simulando Windows 8)
    drawTile(5, 5, 18, 8, "Mensagens", "\033[44m");
    drawTile(25, 5, 18, 8, "Calendario", "\033[42m");
    drawTile(45, 5, 10, 8, "Fotos", "\033[41m");
    drawTile(57, 5, 10, 8, "Loja", "\033[45m");

    drawTile(5, 14, 10, 8, "Musica", "\033[46m");
    drawTile(17, 14, 10, 8, "Config", "\033[100m");
    drawTile(29, 14, 26, 8, "Aether Shell", "\033[43m");

    gotoxy(1, 25);
    cout << "Use os comandos: notas, cal, shell ou exit." << endl;
}

int main() {
    // Configura o terminal para aceitar cores ANSI no Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    string cmd;
    while (true) {
        drawStartScreen();
        gotoxy(1, 27);
        cout << "AetherOS > ";
        cin >> cmd;

        if (cmd == "exit") break;
        if (cmd == "shell") {
            system("cls");
            cout << "--- AETHER SHELL ---\nDigite 'back' para voltar.\n";
            string sCmd;
            while(cin >> sCmd && sCmd != "back") system(sCmd.c_str());
        }
        if (cmd == "cal") {
            system("cls");
            system("date /t");
            system("pause");
        }
    }

    return 0;
}