Write-Host "Tentative de compilation..." -ForegroundColor Blue
g++ -o CGE.exe Code/main.cpp Code/constant.cpp Code/graphism/graphism_functions.cpp -I./include/glfw -L./lib -lglfw3 -lgdi32 -lopenGL32 -mconsole
.\CGE.exe