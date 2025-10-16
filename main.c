#include <windows.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
short b[44100*8];void gm(){for(int t=0;t<44100*8;t++){float tt=t/44100.f,o1=sinf(2*3.1415f*220*tt),o2=sinf(2*3.1415f*330*tt)*.5,o3=sinf(2*3.1415f*440*tt)*.25;b[t]=(short)((o1+o2+o3)*.15*32767);}}void pm(){WAVEFORMATEX w={1,1,44100,88200,2,16,0};HWAVEOUT h;waveOutOpen(&h,WAVE_MAPPER,&w,0,0,0);WAVEHDR wh={(LPSTR)b,44100*8*2,0,0,0,0,0,0};waveOutPrepareHeader(h,&wh,sizeof(wh));waveOutWrite(h,&wh,sizeof(wh));}
const char*vs="#version 330 core\nlayout(location=0)in vec2 p;layout(location=1)in vec2 t;out vec2 uv;void main(){uv=t;gl_Position=vec4(p,0,1);}";
const char*fs="#version 330 core\nprecision mediump float;out vec4 f;in vec2 uv;uniform float t;"
"float h(vec2 p){return fract(sin(dot(p,vec2(127.1,311.7)))*43758.5453);}"
"float n(vec2 p){vec2 i=floor(p),f=fract(p);float a=h(i),b=h(i+vec2(1,0)),c=h(i+vec2(0,1)),d=h(i+vec2(1,1));vec2 u=f*f*(3.-2.*f);return mix(a,b,u.x)+(c-a)*u.y*(1.-u.x)+(d-b)*u.x*u.y;}"
"void main(){vec2 p=uv*10.;p.y+=sin(p.x*3.+t*2.)*0.08+cos(p.x*7.+t*1.5)*0.04;float sx=abs(fract(p.x)-.5),sy=abs(fract(p.y)-.5);"
"float tx=smoothstep(.42,.46,sx),ty=smoothstep(.42,.46,sy);vec3 cols[3];cols[0]=vec3(.9,.8,.2);cols[1]=vec3(.9,.1,.1);cols[2]=vec3(.1,.6,.1);"
"int idx=int(mod(floor(t*2.),3.));vec3 c=mix(cols[idx],cols[(idx+1)%3],tx);c=mix(c,cols[(idx+2)%3],ty);"
"float wv=sin(p.x*100.+cos(p.y*50.+t*3.))*sin(p.y*80.+sin(p.x*60.+t*2.)),wvB=.5+.5*wv,txn=n(p*12.);c*=.3+.6*wvB+txn;"
"vec2 pp=uv-vec2(.5);float w=.08;vec2 n1=normalize(vec2(1.,1.)),n2=normalize(vec2(1.,-1.));"
"float pulse=0.02*sin(t*10.);float sM=clamp(1.-smoothstep(w-pulse,w+pulse,abs(dot(pp,n1)))+1.-smoothstep(w-pulse,w+pulse,abs(dot(pp,n2))),0.,1.);"
"c=mix(c,vec3(.95),sM);c+=0.1*sin(t*5.+pp.x*10.)*wvB;f=vec4(c,1.);}";
GLuint cs(const char*s,GLenum t){GLuint x=glCreateShader(t);glShaderSource(x,1,&s,0);glCompileShader(x);return x;}
int main(){gm();pm();glfwInit();GLFWwindow*w=glfwCreateWindow(800,600,"4K",0,0);glfwMakeContextCurrent(w);glewExperimental=1;glewInit();GLuint pr=glCreateProgram();glAttachShader(pr,cs(vs,GL_VERTEX_SHADER));glAttachShader(pr,cs(fs,GL_FRAGMENT_SHADER));glLinkProgram(pr);glUseProgram(pr);GLint tLoc=glGetUniformLocation(pr,"t");float q[]={-1,-1,0,0,1,-1,1,0,-1,1,0,1,-1,1,0,1,1,-1,1,0,1,1,1,1};GLuint vao,vbo;glGenVertexArrays(1,&vao);glBindVertexArray(vao);glGenBuffers(1,&vbo);glBindBuffer(GL_ARRAY_BUFFER,vbo);glBufferData(GL_ARRAY_BUFFER,sizeof(q),q,GL_STATIC_DRAW);glEnableVertexAttribArray(0);glVertexAttribPointer(0,2,GL_FLOAT,0,4*sizeof(float),0);glEnableVertexAttribArray(1);glVertexAttribPointer(1,2,GL_FLOAT,0,4*sizeof(float),(void*)(2*sizeof(float)));while(!glfwWindowShouldClose(w)){glUniform1f(tLoc,(float)glfwGetTime());glClear(GL_COLOR_BUFFER_BIT);glBindVertexArray(vao);glDrawArrays(GL_TRIANGLES,0,6);glfwSwapBuffers(w);glfwPollEvents();}glfwTerminate();return 0;}
