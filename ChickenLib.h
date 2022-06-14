#pragma once
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <mmsystem.h>
#include <algorithm>
#pragma comment (lib, "winmm.lib")

// Library with helpful functions and stuff.
using namespace std;
class EasyConsoleColorHandle {
public:
void BLUE() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 01);
}
void GREEN() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
}
void LBLUE() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03);
}
void RED() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 04);
}
void PURPLE() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 05);
}
void YELLOW() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 06);
}
void WHITE() {
    SetConsoleTextAttribute(GetStdHandle((STD_OUTPUT_HANDLE)), 07);
}
};
void EasySoundPlay(string wavpath) {
    PlaySound((LPCWSTR)wavpath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}
void TTS(string speak) {
    int temprand = rand() % 1000 + 1;
    string path = to_string(temprand).append(".vbs");
    char const* systempath = path.c_str();
    ofstream FILE(path);
    FILE << "'" << endl << "set speech = Wscript.CreateObject(\"SAPI.spVoice\")" << endl << "speech.speak \"" << speak << "\"";
    FILE.close();
    system(systempath);
    remove(systempath);
}
int GetLineAmmountInFile(string fileToCheck) {
    int LineAmmount = 0;
    string TempLine = "";
    ifstream FTC(fileToCheck);
    while (FTC.peek() != EOF)
    {
        getline(FTC, TempLine);
        LineAmmount++;
    }
    FTC.close();
    return LineAmmount;
}
void remFile(string FileName) {
    remove(FileName.c_str());
}
bool CFSIS(string CheckIn, string CheckForIn) {
    if (strstr(CheckIn.c_str(), CheckForIn.c_str())) {
        return true;
    }
    else {
        return false;
    }
}
void ConsoleTitle(string TitleA) {
    SetConsoleTitleA((LPCSTR)reinterpret_cast<LPARAM>(TitleA.c_str()));
}
void ConsoleTextSize(int size) {
    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 0;
    fontex.dwFontSize.X = size;
    fontex.dwFontSize.Y = size;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}
void cpause() {
    system("pause");
}
void coutwithcolor(string out, string color) {
    transform(color.begin(), color.end(), color.begin(), ::tolower);
    EasyConsoleColorHandle cl;
    if (color == "blue") 
    {
        cl.BLUE();
        cout << out;

    }
    else if (color == "green")
    {
        cl.GREEN();
        cout << out;
    }
    else if (color == "lblue")
    {
        cl.LBLUE();
        cout << out;
    }
    else if (color == "red")
    {
        cl.RED();
        cout << out;
    }
    else if (color == "purple")
    {
        cl.PURPLE();
        cout << out;
    }
    else if (color == "yellow")
    {
        cl.YELLOW();
        cout << out;
    }
    else if (color == "white")
    {
        cl.WHITE();
        cout << out;
    }
    cl.WHITE();
}