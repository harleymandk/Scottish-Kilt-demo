# Scottish-Kilt-demo
Scottish Kilt demo done for TrSac 2025
* Musik
* Dynamiske klanfarver
* Saltire
* Pulserende knuder
* Bølgende kilt
* Subtile farveblendinger og ekstra glans for mere visuel “wow”

### 🔹 Højdepunkter

1. **Farveblending**: Små subtile farveskift over tid → mere levende tartan-effekt.
2. **Knuder & Saltire pulserer med musik** → `pulse=0.02*sin(t*10.)`
3. **Bølge-animation og keltiske knuder** som før
4. **Extra glans/shine** → `c+=0.1*sin(t*5.+pp.x*10.)*wvB` giver liv til overfladen
5. **Alt self-contained under 4 KB** → klar til IQ 4k framework

erstatte `main.c` i IQ 4k framework med denne fil, og demoen kører med alle features.
ScottishKiltDemo/
│
├─ main.cpp          <-- Din C++ demo (self-contained shader)
├─ glew32.dll        <-- GLEW runtime DLL
├─ glfw3.dll         <-- GLFW runtime DLL
├─ Libraries/        <-- Biblioteker
│   ├─ GLEW/
│   │   ├─ include/GL/glew.h
│   │   └─ lib/Release/Win32/glew32.lib
│   └─ GLFW/
│       ├─ include/GLFW/glfw3.h
│       └─ lib-vc2019/glfw3.lib
└─ ScottishKilt.sln  <-- Visual Studio solution


