Write-Host "Tentative de compilation..." -ForegroundColor Blue
g++ -o CGE.exe main.cpp -I./include/glfw -L./lib -lglfw3 -lgdi32 -lopenGL32 -mconsole
.\CGE.exe