Write-Host "Tentative de compilation..." -ForegroundColor Blue
g++ -o CGE.exe src/main.cpp src/constant.cpp src/glad.c src/graphism/graphism_functions.cpp src/graphism/shaders/shaders.cpp src/graphism/shaders/shaderCompilation.cpp -I./include/glfw -L./lib -lglfw3 -lgdi32 -lopengl32 -mconsole

.\CGE.exe