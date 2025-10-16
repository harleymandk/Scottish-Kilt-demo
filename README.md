Perfekt! 😎 Her er en **færdig README.md**, klar til GitHub. Den inkluderer:

* Projektbeskrivelse
* Setup/instruktioner
* Fuld mappe-diagram med ikoner
* Licens
* Kort kode snippet for main.c

Du kan kopiere filen direkte ind i dit repo og pushe.

---

```markdown
# Scottish Kilt 4K Demo

En lille 4KB demo skrevet i C/GLSL, der viser en procedural Scottish Kilt med:

- Musik
- Dynamiske klanfarver (MacLeod, MacDonald, Campbell)
- Saltire (det skotske flag)
- Pulserende keltiske knuder
- Bølgete animation og subtle glans

---

## Setup

1. Download afhængigheder:

   - GLFW: [https://www.glfw.org/download.html](https://www.glfw.org/download.html)  
   - GLEW: [http://glew.sourceforge.net/](http://glew.sourceforge.net/)

2. Placer headers i:

```

include/GLFW/
include/GLEW/

```

3. Placer lib-filer i:

```

lib/
├─ glfw3.lib
└─ glew32s.lib

```

4. Åbn Visual Studio og opret et nyt projekt, eller åbn `main.c` som et projekt.

5. Projektindstillinger:

- Additional Include Directories: `$(ProjectDir)include`  
- Additional Library Directories: `$(ProjectDir)lib`  
- Linker → Input → Additional Dependencies: `glfw3.lib; glew32s.lib; opengl32.lib; winmm.lib`  
- Runtime Library: Multithreaded (/MT)

6. Build & Run.

---

## Folder-struktur

```

ScottishKiltDemo/
├─ README.md       📄 Instruktioner & setup
├─ main.c          💻 Demo kode (musik + shader + kilt)
├─ .gitignore      ❌ Ignorerer build-filer og VS midlertidige filer
├─ include/        📂 Headers
│   ├─ GLFW/       📄 GLFW headers
│   └─ GLEW/       📄 GLEW headers
└─ lib/            📂 Biblioteker
├─ glfw3.lib   📦 GLFW lib
└─ glew32s.lib 📦 GLEW statisk lib

````

📄 = tekst- eller kodefil  
💻 = vigtig kodefil (main.c)  
❌ = ignorerede filer  
📂 = folder  
📦 = bibliotek  

---

## Kort kode snippet

```c
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <math.h>

int main() {
    glfwInit();
    GLFWwindow* w = glfwCreateWindow(800, 600, "4K", 0, 0);
    glfwMakeContextCurrent(w);
    glewInit();
    // Shader, musik og animation her
    while (!glfwWindowShouldClose(w)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(w);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
````

> Fuld demo-kode med musik og shaders findes i `main.c`.

---

## Licens

MIT License – fri at bruge, remix og dele.

```

---

Denne README.md er **færdig til GitHub**. Når du kopierer den ind i repoet og pusher, vil brugere straks kunne se:  

- Hvordan projektet er organiseret  
- Hvordan man bygger og kører demoen  
- Mappe-struktur med grafisk overblik  

---

Hvis du vil, kan jeg næste lave **en GitHub-kompatibel ZIP med alle placeholders**, inkl. README, klar til push, så du bare skal tilføje GLFW/GLEW og køre.  

Vil du have, jeg laver den?
```


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

├─ **README.md**       📄 Instruktioner & setup

├─ **main.c**          💻 Demo kode (musik + shader + kilt)

├─ **.gitignore**      ❌ Ignorerer build-filer og VS midlertidige filer

├─ **include/**        📂 Headers

│   ├─ **GLFW/**       📄 GLFW headers

│   └─ **GLEW/**       📄 GLEW headers

└─ **lib/**            📂 Biblioteker

    ├─ **glfw3.lib**   📦 GLFW lib
    
    └─ **glew32s.lib** 📦 GLEW statisk lib

Opsætning : https://www.youtube.com/watch?v=HzFatL3WT6g

GLEW: http://glew.sourceforge.net/
 → Windows binary

GLFW: https://www.glfw.org/download.html
 → Windows precompiled

