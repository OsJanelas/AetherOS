@echo off
:MENU
cls
color 1F
echo ==========================================
echo   AETHER OS - START SCREEN
echo ==========================================
echo [1] Bloco de Notas    [4] Calculadora
echo [2] Calendario        [5] Prompt
echo [3] Explorador        [6] Temas
echo [7] Atari (Ping)      [8] Sair
echo ==========================================
set /p opt="Escolha: "
if %opt%==1 start notepad
if %opt%==2 (date /t & pause)
if %opt%==3 start explorer .
if %opt%==4 start calc
if %opt%==5 cmd
if %opt%==7 ping 127.0.0.1 -n 10
if %opt%==8 exit
goto MENU