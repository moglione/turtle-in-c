//////////////////////////////////////////////////////////////////////////
// tortuga.h (ver 1.08 - 13/7/2024) (MM)     moglione@gmail.com         //
// ---------------------------------------------------------------------//
// This is a source code library (not compiled) to add turtle graphics  //
// to DEV C++ (MinGW-32) and use it as a pedagogical tool               //
// to teach C language through a LOGO approach                          //
// -------------------------------------------------------------------- //
// Developed by moglione@gmail.com at Easter 2024                       //
// between March 21 and 31, 2024                                        //
// ---------------------------------------------------------------------//
// For it to work, the GDI32 library must be included                   //
//                                                                      //
//     menu TOOLS->COMPILER OPTIONS->                                   //
//          ADD THESE COMMANDS TO LINKER COMMAND LINE                   //
//          -lgdi32 <-- that switch must be added                       //
//                                                                      //
// -------------------------------------------------------------------- //
// Instituto Tecnico Salesiano San Jose ITSSJ - 8013 -                  //
// Rosario - Santa Fe - Republica Argentina                             //
//////////////////////////////////////////////////////////////////////////

#include <windows.h>    // Win32API Header File
#include <wingdi.h>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <time.h>

/////////////////////////////////////////////////////////////////////////////
// a macro to create the "repeat" of the logo with the "for" of C
#define repeat(x) for(int iii=1; iii<=x; iii++)
#define repetir(x) for(int iii=1; iii<=x; iii++)

// 1- different ways to write the forward primitive
#define avanza(x) 	forward(x)
#define av(x) 		forward(x)
#define fw(x) 		forward(x)

// 2- backward
#define retrocede(x) 	backward(x)
#define re(x) 			backward(x)
#define bw(x) 			backward(x)

// 3- rightTurn
#define righturn(x) 	rightTurn(x)
#define girarDerecha(x) rightTurn(x)
#define girarderecha(x) rightTurn(x)
#define gd(x) 			rightTurn(x)
#define rt(x) 			rightTurn(x)

// 4- leftTurn
#define leftturn(x) 		leftTurn(x)
#define girarIzquierda(x) 	leftTurn(x)
#define girarizquierda(x) 	leftTurn(x)
#define gi(x) 				leftTurn(x)
#define lt(x) 				leftTurn(x)

// 5- penUp
#define penup(x) 		penUp(x)
#define pu(x) 			penUp(x)
#define subeLapiz(x) 	penUp(x)
#define subelapiz(x) 	penUp(x)
#define sl(x) 			penUp(x)

// 6- penDown
#define pendown(x) 		penDown(x)
#define pd(x) 			penDown(x)
#define bajaLapiz(x) 	penDown(x)
#define bajalapiz(x) 	penDown(x)
#define bl(x) 			penDown(x)

// 7- penSize
#define pensize(x) 		penSize(x)
#define ps(x) 			penSize(x)
#define grosorLapiz(x) 	penSize(x)
#define grosorlapiz(x) 	penSize(x)
#define gl(x) 			penSize(x)

// 8- penColour
#define pencolour(r, g, b) 		penColour(r, g, b)
#define pc(r, g, b) 			penColour(r, g, b)
#define colorLapiz(r, g, b) 	penColour(r, g, b)
#define colorlapiz(r, g, b) 	penColour(r, g, b)
#define cl(r, g, b) 			penColour(r, g, b)

// 9- hideTurtle
#define hideturtle()		hideTurtle()
#define ht() 				hideTurtle()
#define ocultaTortuga() 	hideTurtle()
#define ocultatortuga() 	hideTurtle()
#define ot() 				hideTurtle()

// 10- showTurtle
#define showturtle()		showTurtle()
#define st()				showTurtle()
#define muestraTortuga()	showTurtle()
#define muestratortuga()	showTurtle()
#define mt()				showTurtle()


// 11- draw text in te screen
#define drawtext(text, x, y, color) drawText(text, x, y, color)
#define dibujarTexto(text, x, y, color) drawText(text, x, y, color)
#define dt(text, x, y, color) drawText(text, x, y, color)


// 12- randomColor
#define randomcolor(r, g, b) 	randomColor(r, g, b)
#define colorazar(r, g, b) 		randomColor(r, g, b)
#define colorAzar(r, g, b) 		randomColor(r, g, b)

// 13- rgb color from gdi
#define rgb(r, g, b) 	RGB(r, g, b)
#define rva(r, g, b) 	RGB(r, g, b)
#define RVA(r, g, b) 	RGB(r, g, b)

// 14- random numbers
#define azar(x) 	random(x)

// 15- window size
#define ventana(x, y, width, height) 	size(x, y, width, height)

// 16- set viewport coordinates
#define setviewportsize(left, right, top, bottom) setViewportSize(left, right, top, bottom)
#define coordenadas(left, right, top, bottom) setViewportSize(left, right, top, bottom)

// 17- clearScreen
#define clearscreen(x) 		clearScreen(x)
#define borrarPantalla(x) 	clearScreen(x)
#define borrarpantalla(x) 	clearScreen(x)

// 18- wait for a key press
#define esperar() wait()

// 19- bring console to front
#define consoletofront 	consoleToFront()
#define consolaAlFrente consoleToFront()
#define consolaalfrente consoleToFront()

//////////////////////////////////////////////////////////////////////////////////
// Colores
#define ROJO RGB(255,0,0)
#define RED RGB(255,0,0)

#define VERDE RGB(0,255,0)
#define GREEN RGB(0,255,0)

#define AZUL RGB(0,0,255)
#define BLUE RGB(0,0,255)

#define NEGRO RGB(0,0,0)
#define BLACK RGB(0,0,0)

#define BLANCO RGB(255,255,255)
#define WHITE RGB(255,255,255)





static void crearVentanaGrafica(void);
void initCanvas();
void executeCommand();
void ventanaGrafica();	



// get the console handler
HWND GetConsoleWndHandle(void);
HWND consolaHandle = GetConsoleWndHandle();	
HWND ventanaHandle;
HDC canvas;


//width and height of the viewport on the screen (in pixels)
float anchoViewPort=0;
float altoViewPort=0;

//viewport coordinates in the world
float wTop;
float wLeft;
float wBottom;
float wRight;
float escala;

// size and position of the graphic screen (window)
int canvasX=0;
int canvasY=0;
int canvasAncho=0;
int canvasAlto=0;
int canvasChangeSize=0;


// default viewport scale
float viewportLeft=-2500;
float viewportRight=2500;
float viewportTop=2500;
float viewportBottom=-2500;


float velocidadTortuga=500;
int debugMode=0;
int hideMode=0;  // hide the turtle
int winVersion=8;
int firstTime=0;
int isCanvasEnable=0; // Is the canvas initialized? 0=no 1=yes;



// structure where the primitive commands of 
// the logo and its parameters are stored
struct Myprimitiva{   
  char* orden;  
  double valor;
  double valor2;
}; 

struct Myprimitiva primitiva;

// the stack where the program 
// is saved in logo (64k) for any restart
struct Myprimitiva stackPrimitivas[65536];
int stackPointer=0;

// the structure where all the data 
// and states of the turtle are stored
struct MyTortuga {   
  int x;  
  int y;
  int xOld;
  int yOld;
  float angulo;
  float anguloAnt;
  int colorLapiz;
  int grosorLapiz; 
  int lapiz;   // 0 up 1 down 
  char visible;  
  char visibleAnt;
       
         
}; 

struct MyTortuga tortuga;

/////////////////////////////////////////////////////////
// Initial values to the turtle
/////////////////////////////////////////////////////////
void inicializarTortuga(){
	tortuga.angulo=-90;
	tortuga.anguloAnt=-90;
	tortuga.x=0;
	tortuga.y=0;
	tortuga.xOld=0;
	tortuga.yOld=0;
	tortuga.lapiz=1;
	tortuga.colorLapiz=RGB(255,0,0);
	tortuga.grosorLapiz=10;
	tortuga.visible=1;
	tortuga.visibleAnt=1;
	
	
}


/////////////////////////////////////////////////////////
// set the size and position of the graphics 
// window in the screen 
/////////////////////////////////////////////////////////
void size(int x, int y, int ancho, int alto){
 canvasX=x;
 canvasY=y;
 canvasAncho=ancho;
 canvasAlto=alto;
 canvasChangeSize=1;
}


/////////////////////////////////////////////////////////
// set viewport coordinates
/////////////////////////////////////////////////////////
void setViewportSize(float left, float right, float top, float bottom){
 viewportLeft=left;
 viewportRight=right;
 viewportTop=top;
 viewportBottom=bottom;
}


/////////////////////////////////////////////////////////
// determine if the program is running on win7 
// to set certain screen properties later
/////////////////////////////////////////////////////////
void osVersion(){
    DWORD dwVersion = 0; 
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0; 
    DWORD dwBuild = 0;

    dwVersion = GetVersion();
 
    // Get the Windows version.

    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

    // Get the build number.

    if (dwVersion < 0x80000000) dwBuild = (DWORD)(HIWORD(dwVersion));
   
    if(dwMajorVersion==6 && dwMinorVersion==1) winVersion=7;
    if(dwMajorVersion==6 && dwMinorVersion==2) winVersion=8;
  
}



/////////////////////////////////////////////////////////
// draws an empty or filled rectangle in 
// pixels and with screen coordinates
/////////////////////////////////////////////////////////
void rectangleInPixels(int x1, int y1, int x2, int y2,int color, int Fill=0, int width=2){
	
	// If the canvas is not initialized, is initialized
    if(isCanvasEnable==0) ventanaGrafica();	
	
	POINT p1,p2;
  	
  	p1.x=x1;
  	p1.y=y1;
  	
  	p2.x=x2;
  	p2.y=y2;
	
    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,width,color); 
    SelectObject(canvas,pen);

	HBRUSH brush;
    // filled
  	if (Fill)brush = CreateSolidBrush(color);
  	// hollow
  	if (!Fill)brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	
	SelectObject(canvas,brush);
	Rectangle(canvas,p1.x,p1.y,p2.x,p2.y);
	
	DeleteObject(pen);
	DeleteObject(brush);
	
	
}

/////////////////////////////////////////////////////////
// draw text at position x,y of the window
/////////////////////////////////////////////////////////
void drawText(char* texto, int x, int y, int color){
	
	// If the canvas is not initialized, is initialized
    if(isCanvasEnable==0) ventanaGrafica();	
    
	SetTextColor(canvas, color);
	SetBkColor(canvas, RGB(0,0,0));
    SetBkMode(canvas, TRANSPARENT);
	RECT  rect;
    rect.left = x;
    rect.top = y;
    DrawText(canvas, texto, -1, &rect, DT_NOCLIP);
}


/////////////////////////////////////////////////////////
// Graphic message on the screen
/////////////////////////////////////////////////////////
void mensaje(char* mensaje ){
	
	// If the canvas is not initialized, is initialized
    if(isCanvasEnable==0) ventanaGrafica();	
	
	// clear the message area
	rectangleInPixels(8,0,(int) anchoViewPort,30,RGB(0,0,0),1);
	drawText(mensaje, 20 , 8, RGB(255,255,255));
    
    
	
}

/////////////////////////////////////////////////////////
// transform a point (x,y) to the world coordinates
// to screen coordinates
/////////////////////////////////////////////////////////
POINT worldToScreen(POINT p){
	
	// apply origin offset (p.x - left);
	// and then multiply by the scale (widthViewPort / (right - left))
	p.x=(anchoViewPort / (wRight - wLeft)) * (p.x - wLeft);
	p.y=(altoViewPort /(wBottom - wTop) )* (p.y - wTop);

	return p;
}


////////////////////////////////////////////////////////
// stores a command (LOGO program line)
// on the stack and increment the stackPointer
/////////////////////////////////////////////////////////
void storeInStack(char* orden, double valor=0, double valor2=0){

	primitiva.orden=orden;
	primitiva.valor=valor;
	primitiva.valor2=valor2;
	
	// here the LOGO command is executed
	executeCommand();
	
	
    // the primitives are saved 
	// on a stack for when it is done
	// a reset and must be repeated
	stackPrimitivas[stackPointer]=primitiva;
	stackPointer++;
	

}

///////////////////////////////////////////////////
// Just to feed the ego
///////////////////////////////////////////////////
void about(){
	mensaje("Libreria GDTPC\nGraficos de Tortuga para C\nDesarrollada por: moglione@gmail.com\nmarzo 2024");
}


/////////////////////////////////////////////////////////
// set the coordinate of the viewport
/////////////////////////////////////////////////////////
void setViewPortCoords(float left, float right, float top, float bottom){
	
	
	wLeft=left;
	wRight=right;
	wTop=top;
   	wBottom=bottom;
   	
   	escala=anchoViewPort / abs(wRight - wLeft);
    
}



///////////////////////////////////////////////////////////////////////
// Functions to turn on or off a pixel 
// of a given color in world coordinates
///////////////////////////////////////////////////////////////////////
void setPixel(int x, int y, int color=0 ){
	
 
    // If the canvas is not initialized, is initialized
    if(isCanvasEnable==0) ventanaGrafica();	
    
    POINT p;
    p.x=x;
    p.y=y;
    
    // transforms the x, y values of the point in 
	// the world to screen values (pixels)
    p=worldToScreen(p);
    
	SetPixel(canvas,p.x,p.y,color);
    
}

void pixel(int x, int y, int color=0 ){
	setPixel(x, y, color);
}


/////////////////////////////////////////////////////////
// draw a line from the real world to the screen
/////////////////////////////////////////////////////////
void line (float x1,float y1,float x2,float y2, int color=0, int width=1, int style=PS_SOLID){
	
  
  
  // if the canvas is not initialized, is initialized
  if(isCanvasEnable==0) ventanaGrafica();	
  
  POINT p1, p2;
  
  p1.x=x1;
  p1.y=y1;
    
  p2.x=x2;
  p2.y=y2;
  
  p1=worldToScreen(p1);
  p2=worldToScreen(p2);
    
  HPEN hOPen;
  // penstyle, width, color
  HPEN hNPen = CreatePen(style, width, color);
  
  hOPen = (HPEN)SelectObject(canvas, hNPen);
  // starting point of line
  MoveToEx(canvas, p1.x, p1.y, NULL);
  // ending point of line
  LineTo(canvas, p2.x, p2.y);
  DeleteObject(hOPen);
  DeleteObject(hNPen);
  
}

void linea (float x1,float y1,float x2,float y2, int color=0, int width=1, int style=PS_SOLID){
  line (x1, y1,x2, y2, color, width);
}



/////////////////////////////////////////////////////////
// draw a hollow or filled circle
/////////////////////////////////////////////////////////
void circle(int X,int Y,int R,int color=0,int Fill=0){
	
  // if the canvas is not initialized, is initialized
  if(isCanvasEnable==0) ventanaGrafica();
	
 
  
  POINT p;
  p.x=X;
  p.y=Y;
  
  R=R*escala;
  
  p=worldToScreen(p);	
  
 
  // penstyle, width, color
  HPEN   hNPen = CreatePen(PS_SOLID, 2, color);
  HPEN   hOPen = (HPEN)SelectObject(canvas, hNPen);
  HBRUSH brush;
    
  // Filled
  if (Fill)brush = CreateSolidBrush(Fill);
  
  // Hollow
  if (!Fill)brush = (HBRUSH)GetStockObject(NULL_BRUSH);
  
  brush = (HBRUSH)SelectObject(canvas, brush);
  
  Ellipse(canvas, p.x-R, p.y+R, p.x+R, p.y-R);
  DeleteObject(hOPen);
  DeleteObject(hNPen);
  DeleteObject(brush);
  
  
}

void circulo(int X,int Y,int R,int color=0,int Fill=0){
	circle(X, Y, R, color, Fill);	

}

/////////////////////////////////////////////////////////
// draw a hollow or filled rectangle
/////////////////////////////////////////////////////////
void rectangle(int x1, int y1, int x2, int y2,int color, int Fill=0){
	

  	
  	// if the canvas is not initialized, is initialized
    if(isCanvasEnable==0) ventanaGrafica();
  	
  	POINT p1,p2;
  	
  	p1.x=x1;
  	p1.y=y1;
  	
  	p2.x=x2;
  	p2.y=y2;
  	
	p1=worldToScreen(p1);
	p2=worldToScreen(p2);
	
	
	
    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,color); 
    SelectObject(canvas,pen);

	HBRUSH brush;
    // filled
  	if (Fill)brush = CreateSolidBrush(Fill);
  	// hollow
  	if (!Fill)brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	
	SelectObject(canvas,brush);
	
	Rectangle(canvas,p1.x,p1.y,p2.x,p2.y);
	
	DeleteObject(pen);
    DeleteObject(brush);
	
}

void rectangulo(int x1, int y1, int x2, int y2,int color, int Fill=0){
	rectangle(x1, y1, x2, y2,color, Fill);
}


//////////////////////////////////////////////////////
// rotate one point around another 
// a certain number of degrees
//////////////////////////////////////////////////////
POINT rotate_point(POINT centro, POINT punto, float angle){


	
  float s = sin(angle*0.01745329251);
  float c = cos(angle*0.01745329251);

  // translate point back to origin:
  punto.x -= centro.x;
  punto.y -= centro.y;

  // rotate point
  float xnew = punto.x * c - punto.y * s;
  float ynew = punto.x * s + punto.y * c;

  // translate point back:
  POINT p; 
  p.x = xnew + centro.x;
  p.y = ynew + centro.y;
  return p;
}

/////////////////////////////////////////////////////////
// draw the turtle that is actually a hollow triangle
/////////////////////////////////////////////////////////
void drawTurtle(int borrar=0){


	POINT punto1;
	POINT punto2;
	POINT punto3;
	POINT centro;
	int x,y;
	float angulo;
	
	if(borrar==0){
		x=tortuga.x;
		y=tortuga.y;
		angulo=tortuga.angulo;
	}
		
	
	if(borrar==1){
		x=tortuga.xOld;
		y=tortuga.yOld;
		angulo=tortuga.anguloAnt;
	}
	
	centro.x=x;
	centro.y=y;
	
	
	centro=worldToScreen(centro);

	
	// width and height of the turtle (magic numbers!!!!)
	int ancho=25; 
	int alto=15; 



	// The points of the triangle are calculated from the center
	punto1.x=centro.x+ancho/2;
	punto1.y=centro.y ;

	punto2.x= centro.x - ancho/2;
	punto2.y= centro.y + alto/2;
	
	punto3.x= centro.x - ancho/2;
	punto3.y= centro.y - alto/2;
	
	
	// the turtle is rotated according to its angle
	punto1=rotate_point(centro, punto1, angulo);
	punto2=rotate_point(centro, punto2, angulo);
	punto3=rotate_point(centro, punto3, angulo);
	
		
	// is drawn in XOR mode
	LOGBRUSH lb;
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(255, 0, 0);  

    HPEN hpenNew = ExtCreatePen(PS_COSMETIC , 1, &lb, 0, NULL);
    HPEN hpenOld = (HPEN)SelectObject(canvas, hpenNew);

    int ropOld  = SetROP2(canvas, R2_NOT);
    int modeOld = SetBkMode(canvas, TRANSPARENT); 

    HBRUSH hbrOriginal = (HBRUSH)SelectObject(canvas, GetStockObject(NULL_BRUSH));
       
    MoveToEx(canvas, punto1.x, punto1.y, NULL);
    LineTo(canvas, punto2.x, punto2.y);
    LineTo(canvas, punto3.x, punto3.y);
    LineTo(canvas, punto1.x, punto1.y);

    SelectObject(canvas, hbrOriginal);
    SetBkMode(canvas, modeOld);
    SetROP2(canvas, ropOld);
    SelectObject(canvas, hpenOld);
    
	DeleteObject(hpenNew);
    DeleteObject(hpenOld);
    DeleteObject(hbrOriginal);
    
	
	
}


//////////////////////////////////////////////////////
// update the position of the turtle
//////////////////////////////////////////////////////
void updateTortuga(){

	// the turtle goes from visible to invisible
    if(tortuga.visible==0 && tortuga.visibleAnt==1){
     	drawTurtle(1);
     	tortuga.visibleAnt=0;
     	return;	
	}

	// the turtle goes from invisible to visible
    if(tortuga.visible==1 && tortuga.visibleAnt==0){
     	drawTurtle(1);
     	tortuga.visibleAnt=1;
     	return;	
	}


	// the turtle drawing is updated only if it is visible
	if(tortuga.visible==1){
		drawTurtle(1); // the previous turtle is deleted
		drawTurtle();  // the current turtle is draw

	}

	// the position of the turtle is saved to delete it later
	tortuga.xOld=tortuga.x;
	tortuga.yOld=tortuga.y;
	tortuga.anguloAnt=tortuga.angulo;
   
	
	
}


/////////////////////////////////////////////////////////
// waiting loop at the end that scans the keyboard
// and intercepts the keys
////////////////////////////////////////////////////////
void wait(){
	
   //if(tortuga.visible==0) drawTurtle(1); 		
   updateTortuga();
   mensaje("FIN DE LA EJECUCION\nPRESIONE Q PARA SALIR"); 	
   
   MSG msg;
   while (GetMessage(&msg, ventanaHandle, 0, 0) > 0){
		DispatchMessage(&msg);
   }
   
}







/////////////////////////////////////////////////////////
// draw a line with Bresenham's algorithm 
// point to point to simulate the movement of the turtle
/////////////////////////////////////////////////////////
void plotLineWidth(int x0, int y0, int x1, int y1, float wd){ 
	
		
     
        wd=tortuga.grosorLapiz; 
   		
	  
		if(velocidadTortuga <= 10){
			if (tortuga.lapiz==1) line(x0,y0,x1,y1, tortuga.colorLapiz ,tortuga.grosorLapiz);	
			tortuga.x=x1;
        	tortuga.y=y1;
			updateTortuga();
			return;
		}
	
	
        int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
        int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
        int err = dx - dy, e2, x2, y2; /* error value e_xy */
        float ed = dx + dy == 0 ? 1 : sqrt((float)dx * dx + (float)dy * dy);

        for (wd = (wd + 1) / 2;;) { /* pixel loop */
        	
            if (tortuga.lapiz==1)setPixel(x0,y0,tortuga.colorLapiz);
            tortuga.x=x0;
            tortuga.y=y0;
			updateTortuga();
		
			
            e2 = err;
            x2 = x0;
            
			if (2 * e2 >= -dx) { /* x step */
                for (e2 += dy, y2 = y0; e2 < ed * wd && (y1 != y2 || dx > dy); e2 += dx)
                    if (tortuga.lapiz==1)setPixel(x0,y2 += sy,tortuga.colorLapiz);
                if (x0 == x1)break;
                e2 = err;
                err -= dy;
                x0 += sx;
            }
            
			if (2 * e2 <= dy) { /* y step */
                for (e2 = dx - e2; e2 < ed * wd && (x1 != x2 || dx < dy); e2 += dy)
                    if (tortuga.lapiz==1)setPixel(x2 += sx,y0,tortuga.colorLapiz);
                if (y0 == y1) break;
                err += dx;
                y0 += sy;
            }
        }
    }


/////////////////////////////////////////////////////////
// A more complete function to obtain the handle
// off the console window
/////////////////////////////////////////////////////////
HWND GetConsoleWndHandle(void){
  HWND hConWnd;
  OSVERSIONINFO os;
  char szTempTitle[64], szClassName[128], szOriginalTitle[1024];

  os.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );
  GetVersionEx( &os );
  // may not work on WIN9x
  if ( os.dwPlatformId == VER_PLATFORM_WIN32s ) return 0;

  GetConsoleTitle( szOriginalTitle, sizeof( szOriginalTitle ) );
  sprintf( szTempTitle,"%u - %u", GetTickCount(), GetCurrentProcessId() );
  SetConsoleTitle( szTempTitle );
  Sleep( 40 );
  // handle for NT
  hConWnd = FindWindow( NULL, szTempTitle );
  SetConsoleTitle( szOriginalTitle );

  // may not work on WIN9x
  if ( os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )
  {
    hConWnd = GetWindow( hConWnd, GW_CHILD );
    if ( hConWnd == NULL )  return 0;
    GetClassName( hConWnd, szClassName, sizeof ( szClassName ) );
    while ( strcmp( szClassName, "ttyGrab" ) != 0 )
    {
      hConWnd = GetNextWindow( hConWnd, GW_HWNDNEXT );
      if ( hConWnd == NULL )  return 0;
      GetClassName( hConWnd, szClassName, sizeof( szClassName ) );
    }
  }
  return hConWnd;
}




/////////////////////////////////////////////////////////
// show the debug on the screen
/////////////////////////////////////////////////////////
void debug(){
	
	  	
	// clear the debug area
	rectangleInPixels(8,altoViewPort-30,anchoViewPort,altoViewPort-8,RGB(0,0,00),1);
	drawText("DEBUG", 15 , altoViewPort-30, RGB(255,255,255));
    
    
	// produces a message when a key is pressed
    // (Wait for a key to trigger a message)
	MSG msg;
    GetMessage(&msg, ventanaHandle, WM_KEYFIRST, WM_KEYLAST); 
	DispatchMessage(&msg);

}


/////////////////////////////////////////////////////////
// delete the client area with a certain color
/////////////////////////////////////////////////////////
void clearScreen(int color=0){
	if(color==0)color=RGB(1,1,1);
	rectangle(wLeft,wTop,wRight,wBottom,color,color);

}







/////////////////////////////////////////////////////////
// draw the abscissa and ordinate lines
/////////////////////////////////////////////////////////
void drawScale(){
	
	borrarPantalla();
	
	int mitadAncho=abs(wLeft-wRight) /2;
    int mitadAlto= abs(wTop-wBottom) / 2;
	
	line( wLeft, 0, wRight, 0, RGB(70,70,70), 1);
    line(0, -mitadAlto, 0, mitadAlto, RGB(70,70,70), 1);
    
    for(int i=wLeft; i<wRight; i+=100){
    	line( i, 20, i, -20, RGB(70,70,70), 1);
	}
	
	for(int i=wBottom; i<wTop; i+=100){
    	line( 20, i, -20, i, RGB(70,70,70), 1);
	}
	
	
	
	

}



////////////////////////////////////////////////////////
// basic primitive of LOGO
////////////////////////////////////////////////////////
void turtleWalk(double largo){
	
	
	double x=tortuga.x;
	double y=tortuga.y;
	double angulo=tortuga.angulo;

	angulo=angulo*0.01745329251;
		
	double x2=round(x + cos(angulo) * largo);
	double y2=round(y - sin(angulo) * largo);
 		
	plotLineWidth (x,y,x2,y2,tortuga.grosorLapiz);
		
	tortuga.x=x2;
	tortuga.y=y2;


}

////////////////////////////////////////////////////////////////////////////////
// HERE THE PRIMITIVES OF THE TURTLE BEGIN  (LOGO)
////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// turtle forward speed
/////////////////////////////////////////////////////////
void velocidad(int v){
	storeInStack("velocidad", v);
	
}

/////////////////////////////////////////////////////////
// go to an xy position
/////////////////////////////////////////////////////////
void ir(double x , double y){
  storeInStack("ir", x , y);	
  
}

void gotoxy(double x , double y){
  storeInStack("ir", x , y);	
  
}


/////////////////////////////////////////////////////////
// forward
/////////////////////////////////////////////////////////
void forward(double largo){
  storeInStack("av", largo);	
}

/////////////////////////////////////////////////////////
// backward
/////////////////////////////////////////////////////////
void backward(double largo){
  storeInStack("av", -largo);
}




/////////////////////////////////////////////////////////
//turn to the right
/////////////////////////////////////////////////////////
void rightTurn(float angulo){
	storeInStack("gd", angulo);
}


/////////////////////////////////////////////////////////
// turn to the left
/////////////////////////////////////////////////////////
void leftTurn(float angulo){
	storeInStack("gi", angulo);
	
}


/////////////////////////////////////////////////////////
// pen up
/////////////////////////////////////////////////////////
void penUp(){
	storeInStack("sl", 0);
	
}

/////////////////////////////////////////////////////////
// pen down
/////////////////////////////////////////////////////////
void penDown(){
	storeInStack("bl", 1);
	
}


/////////////////////////////////////////////////////////
// pen colour
/////////////////////////////////////////////////////////
void penColour(int r, int g, int b){
	storeInStack("colorlapiz", RGB(r, g, b));
}


/////////////////////////////////////////////////////////
// pens size (thickness)
/////////////////////////////////////////////////////////
void penSize(int g){
	storeInStack("grosorlapiz", g);
}



/////////////////////////////////////////////////////////
// Random numbers
/////////////////////////////////////////////////////////
int random(int g){
	int r= rand() % g;
	return r;
}



/////////////////////////////////////////////////////////
// Hide turtle
/////////////////////////////////////////////////////////
void hideTurtle(){
   storeInStack("ocultatortuga", 0);
}

/////////////////////////////////////////////////////////
// show turtle
/////////////////////////////////////////////////////////
void showTurtle(){
   storeInStack("muestratortuga", 0);
}

/////////////////////////////////////////////////////////
//create a random color
////////////////////////////////////////////////////////
int randomColor(){
	return RGB(azar(255), azar(255), azar(255));
}


////////////////////////////////////////////
//brings the console window to the front
///////////////////////////////////////////
void consoleToFront(){
	BringWindowToTop(consolaHandle);
}


/////////////////////////////////////////////////////
// an emulation of Visual Basic's doEvents
// so that the other messages are attended to
// window while in a loop
////////////////////////////////////////////////////
void doEvents(){
	MSG msg;
   	if (PeekMessageA(&msg, ventanaHandle, 0, 0,PM_REMOVE) > 0) DispatchMessage(&msg);
  
}

/////////////////////////////////////////////////////////
// Main loop where the stack commands are 
// executed to perform the drawing
////////////////////////////////////////////////////////
void executeCommand(){
        
	// if the canvas is not initialized, it is initialized
    if(isCanvasEnable==0) initCanvas();
	
	
	if(debugMode==1) debug();
	

	// to avoid blocking while the instructions are executed
	doEvents();
  
		
	//esperar(velocidadTortuga);
	

	
 	//Forward 
 	if(primitiva.orden=="av"){
		turtleWalk(primitiva.valor);
		
	}

	//goto xy 
 	if(primitiva.orden=="ir"){
 		
 		float opuesto=primitiva.valor2-tortuga.y;
 		float adyacente=primitiva.valor-tortuga.x;
 		float angulo= atan (opuesto/adyacente) * 180 / 3.14159265;
 		 		
		tortuga.angulo=-angulo;
		updateTortuga();
		
		plotLineWidth(tortuga.x,tortuga.y,primitiva.valor,primitiva.valor2,tortuga.grosorLapiz);
		
	}
		
		

	//backward
	if(primitiva.orden=="rt"){
		turtleWalk(primitiva.valor);
		
	}	
	
	
	//turn left
	if(primitiva.orden=="gi"){
		tortuga.angulo=tortuga.angulo-primitiva.valor;
		updateTortuga();
	}	
		
		
	//turn right
	if(primitiva.orden=="gd"){
		tortuga.angulo=tortuga.angulo+primitiva.valor;
		updateTortuga();
	}	
	
	//vspeed
	if(primitiva.orden=="velocidad"){
		velocidadTortuga=1000-primitiva.valor;
	}

	//pen colour
	if(primitiva.orden=="colorlapiz"){
		tortuga.colorLapiz=primitiva.valor;
	}	
	
	//pen size
	if(primitiva.orden=="grosorlapiz"){
		tortuga.grosorLapiz=5*primitiva.valor;
	}		
		
	//pen up
	if(primitiva.orden=="sl"){
		tortuga.lapiz=primitiva.valor;
	}	
	
	//pen down
	if(primitiva.orden=="bl"){
		tortuga.lapiz=primitiva.valor;
	}	
	
	
	//hide turtle
	if(primitiva.orden=="ocultatortuga"){
		tortuga.visible=0;
		updateTortuga();
	}		
		
		
	
	//show turtle
	if(primitiva.orden=="muestratortuga"){
		tortuga.visible=1;
		updateTortuga();
	}		
			


}


/////////////////////////////////////////////////////////
// Start again
/////////////////////////////////////////////////////////
void resetear(){
	
	// extracts the width and height values ??from the client area (the drawing area)
	RECT Rect;
  	GetClientRect(ventanaHandle, &Rect);
  	anchoViewPort=Rect.right-Rect.left;
  	altoViewPort=Rect.bottom-Rect.top;
  	
  		
	// set the coordinates again
	setViewPortCoords(viewportLeft, viewportRight,viewportTop, viewportBottom);
	borrarPantalla();
	
	
	inicializarTortuga();
	drawTurtle(1); // delete turtle drawing
	
	// the turtle's orders are executed again
	for(int i=0; i<stackPointer; i++){
		primitiva=stackPrimitivas[i];
		executeCommand();
	}
	

	
	
}


/////////////////////////////////////////////////////////
// initialize the canvas for the turtle
/////////////////////////////////////////////////////////
void ventanaGrafica(){
    srand(time(NULL));
	inicializarTortuga();
	crearVentanaGrafica();
	isCanvasEnable=1;
	tortuga.visible=0;
	updateTortuga();
	
}


/////////////////////////////////////////////////////////
// canvas initialization function without the turtle
/////////////////////////////////////////////////////////
void initCanvas(){
	srand(time(NULL));
	inicializarTortuga();
	crearVentanaGrafica();
	isCanvasEnable=1;
	
}

////////////////////////////////////////////////////////////
// function that processes the keys
////////////////////////////////////////////////////////////
void atenderTeclas(int tecla){
	static int sobre=0;
	
	printf("%d \n",tecla);	
  	
	// If the "D" key is pressed it activates the Debug
	if( tecla==68 && debugMode== 0 ){
			debugMode=1;
			return;
	}
	
	// If press the "D" key again, Debug is disabled
	if( tecla==68 && debugMode== 1 ){
		debugMode=0;
		// borra el area de debug
		rectangleInPixels(8,altoViewPort-30,anchoViewPort,altoViewPort-8,RGB(0,0,00),1);
	}
	
	// If it was the "R" key, a Reset is performed
	if(tecla==82){
		resetear();
	}
	
	// if it was the "Q" key quit makes it terminate
	if( tecla==81 || tecla==27 ){
		PostQuitMessage(0);
    	PostMessage(GetConsoleWndHandle(),WM_CLOSE,0,0);
		return;
	}
	
	
	// show about
	if( tecla==65 && sobre==0 ){
		sobre=1;
		rectangleInPixels(3,3,anchoViewPort/2,altoViewPort/4,RGB(0,0,0),1);
		return;
	}	
	
	// delete about
	if( tecla==65 && sobre==1 ){
		sobre=0;
		about();
		return;
	}	
	


    // If it was the "T" again, quit hideMode
	if( tecla==84 && hideMode==1 ){
		hideMode=0;
	}
		

	// If it was the "T" key you enter hideMode (the turtle is hidden)
	if( tecla==84 ){
		hideMode=1;
		
	}

		
	
}



////////////////////////////////////////////////////////////
// All incoming messages to the graphic window 
// are attended here
////////////////////////////////////////////////////////////
static LRESULT CALLBACK bucleVentana(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    static int xClient, yClient;
    
    PAINTSTRUCT ps;
	
	HDC device_context;
	HPEN pen;
	HBRUSH brush;

    switch(message){
    	
    	case WM_KEYDOWN:
    	
			atenderTeclas(wParam);
		  	
    		break;
    	
		case WM_CREATE:
    		
   			
			break; 
        
		case WM_SIZE:
		
            xClient = LOWORD(lParam);
            yClient = HIWORD(lParam);  
            
            break ;
            
        case WM_EXITSIZEMOVE:  
            // redraws everything when window is resized
			resetear();
			break ;  

        case WM_PAINT:
        	
   		 
			if(firstTime==0){
				firstTime=1;	    
				// The width and height values ??are extracted from the client area (the drawing area)
				RECT Rect;
    			GetClientRect(ventanaHandle, &Rect);
    			anchoViewPort=Rect.right-Rect.left;
    			altoViewPort=Rect.bottom-Rect.top;
				canvas= GetDC(ventanaHandle);
				setViewPortCoords(viewportLeft, viewportRight,viewportTop, viewportBottom);
						
			
		    	SetViewportExtEx(canvas, 1, -1, NULL); // '-' to have the y-axis increase upward
		    	drawTurtle();
		    	
		    }
		    
		    break;

        case WM_DESTROY:
            PostQuitMessage(0);
            PostMessage(GetConsoleWndHandle(),WM_CLOSE,0,0);
            break;
    }
    
	return DefWindowProc(hwnd, message, wParam, lParam);
}

///////////////////////////////////////////////////////////////////
// The graphics window is created
//////////////////////////////////////////////////////////////////
static void crearVentanaGrafica(void){
    const char *className = "MainWindow";
    HINSTANCE hInstance = GetModuleHandle(NULL);

    WNDCLASS wc = {0};
    // to re-paint the client area when the window's size changes
    wc.style = CS_VREDRAW | CS_HREDRAW;
    wc.lpfnWndProc = bucleVentana;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = className;

	
    if (!RegisterClass(&wc))MessageBox(NULL, "no se pudo registrar la clase ventana", "Error", MB_OK);
    
    int xScreen = GetSystemMetrics(SM_CXSCREEN);
    int yScreen = GetSystemMetrics(SM_CYSCREEN);

    RECT window;
    window.left = xScreen / 4;
    window.right =xScreen / 2;
    window.top = yScreen / 8;
    window.bottom = 6 * yScreen / 8;
    
    
    if(canvasChangeSize==1) {
		window.left=canvasX;
    	window.top=canvasY;
    	window.right=canvasAncho;
    	window.bottom=canvasAlto;
  	}
	

    ventanaHandle = CreateWindow(
							className, 
							"Graficos de tortuga (8013)", 
							WS_OVERLAPPEDWINDOW, 
							window.left, 
							window.top, 
							window.right, 
							window.bottom, 
							NULL, 
							NULL, 
							hInstance, 
							NULL
							);

    ShowWindow(ventanaHandle, SW_SHOWDEFAULT);
    UpdateWindow(ventanaHandle);
    canvas = GetDC(ventanaHandle);

  
}


/////////////////////////////////////////////////////////////////////
// EOHF (End OF Header File)
// for now...
/////////////////////////////////////////////////////////////////////

