#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <math.h>
 
//ID´s
enum {ID_LABEL, ID_EDIT, ID_BOTONIGUAL, ID_BOTONRESET, ID_BOTONRESET2, ID_BOTONSUMAR, ID_BOTONRESTAR, ID_BOTONMULTIPLICAR, ID_BOTONDIVIDIR, ID_BOTONPORCENTAJE, ID_BOTONPOTENCIA, ID_BOTONRAIZ, ID_BOTONPI, ID_BOTONCOMA, ID_BOTONSIGNO, ID_BOTONCERO, ID_BOTON1, ID_BOTON2, ID_BOTON3, ID_BOTON4, ID_BOTON5, ID_BOTON6, ID_BOTON7, ID_BOTON8, ID_BOTON9};
 
 
//Prototipos
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
 
void imprimirEdit (int i);                                                  //Funcion que concatena los numeros al hacer clic en los botones
double calcular (double primer_num, double segundo_num, int operacion);     //Funcion que realiza las operaciones
 
HINSTANCE estancia;
HWND label;
HWND edit;
//Iconos
HICON iconoPotencia;
HICON iconoRaiz;
HICON iconoPi;
//Botones
HWND boton1;
HWND boton2;
HWND boton3;
HWND boton4;
HWND boton5;
HWND boton6;
HWND boton7;
HWND boton8;
HWND boton9;
HWND boton0;
HWND botonComa;
HWND botonSigno;
HWND botonIgual;
HWND botonReset;
HWND botonReset2;
HWND botonSumar;
HWND botonRestar;
HWND botonMultiplicar;
HWND botonDividir;
HWND botonPorcentaje;
HWND botonPotencia;
HWND botonRaiz;
HWND botonPi;
 
 
char szClassName[ ] = "CodeBlocksWindowsApp";
 
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
 
    estancia = hThisInstance;
 
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);
 
    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (estancia, "ICONO");
    wincl.hIconSm = LoadIcon (estancia, "ICONO");
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
 
    //Cargamos los iconos de los botones
    iconoPotencia = LoadIcon (estancia, "POTENCIA");
    iconoRaiz = LoadIcon (estancia, "RAIZ");
    iconoPi = LoadIcon (estancia, "PI");
 
    //Color de fondo de la aplicacion
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush (RGB(88, 145, 192));
 
    if (!RegisterClassEx (&wincl))
        return 0;
 
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Calculadora by Alien-Z",
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           300,                 /* The programs width */
           300,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
 
    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);
 
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }
 
    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}
 
 
/*  This function is called by the Windows function DispatchMessage()  */
 
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Alien-Z");
    COLORREF color1 = RGB (192, 192, 192);
 
    //Variables
    char cadenaEditMain [31];
    static int operacion;
    static double primer_num, segundo_num, resultado, signo;
 
 
    switch (message)
    {
        case WM_CREATE:
        {
            //Elementos de la calculadora
            label = CreateWindow ("Static", NULL, BS_CENTER | WS_CHILD | WS_VISIBLE, 20, 20, 250, 25, hwnd, 0, estancia, 0);
            edit = CreateWindowEx (WS_EX_CLIENTEDGE, "edit", 0, ES_RIGHT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 50, 250, 25, hwnd, (HMENU)ID_EDIT, estancia, 0);
 
            boton1 = CreateWindow ("Button", "1", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 20, 90, 40, 25, hwnd, (HMENU) ID_BOTON1, estancia, 0);
            boton2 = CreateWindow ("Button", "2", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 65, 90, 40, 25, hwnd, (HMENU) ID_BOTON2, estancia, 0);
            boton3 = CreateWindow ("Button", "3", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 110, 90, 40, 25, hwnd, (HMENU) ID_BOTON3, estancia, 0);
            boton4 = CreateWindow ("Button", "4", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 20, 120, 40, 25, hwnd, (HMENU) ID_BOTON4, estancia, 0);
            boton5 = CreateWindow ("Button", "5", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 65, 120, 40, 25, hwnd, (HMENU) ID_BOTON5, estancia, 0);
            boton6 = CreateWindow ("Button", "6", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 110, 120, 40, 25, hwnd, (HMENU) ID_BOTON6, estancia, 0);
            boton7 = CreateWindow ("Button", "7", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 20, 150, 40, 25, hwnd, (HMENU) ID_BOTON7, estancia, 0);
            boton8 = CreateWindow ("Button", "8", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 65, 150, 40, 25, hwnd, (HMENU) ID_BOTON8, estancia, 0);
            boton9 = CreateWindow ("Button", "9", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 110, 150, 40, 25, hwnd, (HMENU) ID_BOTON9, estancia, 0);
            boton0 = CreateWindow ("Button", "0", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 20, 180, 40, 25, hwnd, (HMENU) ID_BOTONCERO, estancia, 0);
            botonComa = CreateWindow ("Button", ",", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 65, 180, 40, 25, hwnd, (HMENU) ID_BOTONCOMA, estancia, 0);
            botonSigno = CreateWindow ("Button", "+/-", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 110, 180, 40, 25, hwnd, (HMENU) ID_BOTONSIGNO, estancia, 0);
            botonSumar = CreateWindow ("Button", "+", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 165, 90, 40, 25, hwnd, (HMENU) ID_BOTONSUMAR, estancia, 0);
            botonRestar = CreateWindow ("Button", "-", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 165, 120, 40, 25, hwnd, (HMENU) ID_BOTONRESTAR, estancia, 0);
            botonMultiplicar = CreateWindow ("Button", "*", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 165, 150, 40, 25, hwnd, (HMENU) ID_BOTONMULTIPLICAR, estancia, 0);
            botonDividir = CreateWindow ("Button", "/", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 165, 180, 40, 25, hwnd, (HMENU) ID_BOTONDIVIDIR, estancia, 0);
            botonPorcentaje = CreateWindow ("Button", "%", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 210, 90, 40, 25, hwnd, (HMENU) ID_BOTONPORCENTAJE, estancia, 0);
            botonPotencia = CreateWindow ("Button", "x ²", BS_ICON | BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 210, 120, 40, 25, hwnd, (HMENU) ID_BOTONPOTENCIA, estancia, 0);
            botonRaiz = CreateWindow ("Button", "Raiz", BS_ICON | BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 210, 150, 40, 25, hwnd, (HMENU) ID_BOTONRAIZ, estancia, 0);
            botonPi = CreateWindow ("Button", "Pi", BS_ICON | BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 210, 180, 40, 25, hwnd, (HMENU) ID_BOTONPI, estancia, 0);
            botonIgual = CreateWindow ("Button", "=", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 20, 220, 40, 25, hwnd, (HMENU) ID_BOTONIGUAL, estancia, 0);
            botonReset = CreateWindow ("Button", "C", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 65, 220, 40, 25, hwnd, (HMENU) ID_BOTONRESET, estancia, 0);
            botonReset2 = CreateWindow ("Button", "CE", BS_DEFPUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 110, 220, 40, 25, hwnd, (HMENU) ID_BOTONRESET2, estancia, 0);
 
            //Cambiar fuente de letra del lablel
            static HFONT hFont = CreateFont (16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, VARIABLE_PITCH | FF_SWISS, "Comic Sans MS");
            SendMessage(label, WM_SETFONT, (WPARAM) hFont, true);
 
            //Enviar iconos a los botones
            SendMessage(botonPotencia, BM_SETIMAGE, (WPARAM) IMAGE_ICON, (LPARAM) iconoPotencia);
            SendMessage(botonRaiz, BM_SETIMAGE, (WPARAM) IMAGE_ICON, (LPARAM) iconoRaiz);
            SendMessage(botonPi, BM_SETIMAGE, (WPARAM) IMAGE_ICON, (LPARAM) iconoPi);
 
            //Bloquear el boton "maximizar"
            DWORD dwStyle = (DWORD)GetWindowLong(hwnd, GWL_STYLE);
            dwStyle &= ~WS_MAXIMIZEBOX;
            SetWindowLong(hwnd, GWL_STYLE, (DWORD)dwStyle);
            RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_FRAME | RDW_ERASENOW);
 
            //Bloquear la opcion de cambiarle el tamaño a la ventana
            dwStyle &= ~WS_SIZEBOX;
            SetWindowLong(hwnd, GWL_STYLE, (DWORD)dwStyle);
            RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_FRAME | RDW_ERASENOW);
        }
 
        case WM_COMMAND:
        {
            switch (wParam)
            {
                case ID_BOTON1:                  //Al presionar el boton 1 se llama a la funcion "imprimirEdit" y se le envia el valor "1" que es lo que queremos que se concatene a lo que ya haya en el edit
                {
                    imprimirEdit (1);
                    break;
                }
                case ID_BOTON2:
                {
                    imprimirEdit (2);
                    break;
                }
                case ID_BOTON3:
                {
                    imprimirEdit (3);
                    break;
                }
                case ID_BOTON4:
                {
                    imprimirEdit(4);
                    break;
                }
                case ID_BOTON5:
                {
                    imprimirEdit(5);
                    break;
                }
                case ID_BOTON6:
                {
                    imprimirEdit(6);
                    break;
                }
                case ID_BOTON7:
                {
                    imprimirEdit(7);
                    break;
                }
                case ID_BOTON8:
                {
                    imprimirEdit(8);
                    break;
                }
                case ID_BOTON9:
                {
                    imprimirEdit(9);
                    break;
                }
                case ID_BOTONCERO:
                {
                    imprimirEdit(0);
                    break;
                }
                case ID_BOTONCOMA:
                {
                    GetWindowText (edit, cadenaEditMain, 30);        //Se obtiene lo que hay en el edit y se guarda en "CadenaEditMain"
                    if (strstr (cadenaEditMain, ".") == NULL)        //Analizamos "cadenaEditMain" y si no posee una coma se ejecuta lo que hay dentro del if (en caso de que ya tenga una coma no hace nada)
                    {
                        strcat (cadenaEditMain, ".");                //Se le añade una coma a lo que hay en "CadenaEditMain"
                        SetWindowText (edit, cadenaEditMain);        //Se imprime el nuevo numero en el edit
                    }
                    break;
                }
                case ID_BOTONSIGNO:                                  //Boton que cambia el signo del numero
                {
                    GetWindowText (edit, cadenaEditMain, 30);        //Se obtiene lo que hay en el edit y se guarda en "CadenaEditMain"
                    signo = atof (cadenaEditMain);                   //Transforma la cadena obtenida en un double y lo guarda en "signo"
                    signo *= -1;                                     //Se multiplica el numero por -1 (si es positivo se quedara negativo, y viceversa)
                    sprintf (cadenaEditMain, "%f", signo);           //Se transforma el double obtenido en una cadena y se guarda en "cadenaEditMain"
                    SetWindowText (edit, cadenaEditMain);            //Se imprime el nuevo numero en el edit
                    break;
                }
                case ID_BOTONSUMAR:
                {
                    operacion = 1;                                    //Cambia el valor de "operacion" para indicar que se va a sumar
                    GetWindowText (edit, cadenaEditMain, 30);         //Obtiene el numero ingresado en el edit
                    primer_num = atof (cadenaEditMain);               //Transforma la cadena obtenida en un double y lo guarda en "primer_num"
                    SetWindowText (edit, "");                         //Limpia el edit
                    break;
                }
                case ID_BOTONRESTAR:
                {
                    operacion = 2;                                    //Cambia el valor de "operacion" para indicar que se va a restar
                    GetWindowText (edit, cadenaEditMain, 30);
                    primer_num = atof (cadenaEditMain);
                    SetWindowText (edit, "");
                    break;
                }
                case ID_BOTONMULTIPLICAR:
                {
                    operacion = 3;                                    //Cambia el valor de "operacion" para indicar que se va a multiplicar
                    GetWindowText (edit, cadenaEditMain, 30);
                    primer_num = atof (cadenaEditMain);
                    SetWindowText (edit, "");
                    break;
                }
                case ID_BOTONDIVIDIR:
                {
                    operacion = 4;                                    //Cambia el valor de "operacion" para indicar que se va a dividir
                    GetWindowText (edit, cadenaEditMain, 30);
                    primer_num = atof (cadenaEditMain);
                    SetWindowText (edit, "");
                    break;
                }
                case ID_BOTONPORCENTAJE:
                {
                    operacion = 5;                                    //Cambia el valor de "operacion" para indicar que vamos a hallar el porcentaje
                    GetWindowText (edit, cadenaEditMain, 30);
                    primer_num = atof (cadenaEditMain);
                    SetWindowText (edit, "");
                    break;
                }
                case ID_BOTONPOTENCIA:
                {
                    operacion = 6;                                    //Cambia el valor de "operacion" para indicar que vamos a hallar una potencia
                    GetWindowText (edit, cadenaEditMain, 30);
                    primer_num = atof (cadenaEditMain);
                    SetWindowText (edit, "");
                    SetWindowText (label, "¿A cuánto está elevado el número?");
                    break;
                }
                case ID_BOTONRAIZ:
                {
                    operacion = 7;                                    //Cambia el valor de "operacion" para indicar que vamos a hallar la raiz
                    GetWindowText (edit, cadenaEditMain, 30);
                    primer_num = atof (cadenaEditMain);
                    SetWindowText (edit, "");
                    SetWindowText (label, "¿A cuánto está elevada la raiz?");
                    break;
                }
                case ID_BOTONPI:
                {
                    SetWindowText (edit, "3.141592653589793");        //Imprime en el edit el valor de PI
                    break;
                }
                case ID_BOTONIGUAL:
                {
                    GetWindowText (edit, cadenaEditMain, 30);         //Obtiene el numero ingresado en el edit
                    segundo_num = atof (cadenaEditMain);              //Transforma la cadena obtenida en un double y lo guarda en "segundo_num"
                    resultado = calcular (primer_num, segundo_num, operacion); //El resultado se obtiene apartir de la funcion "calcular", a esta funcion se le envian las variables "primer_num", "segundo_num" y "operacion"
                    sprintf (cadenaEditMain, "%f", resultado);        //Se transforma el double obtenido en una cadena y se guarda en "cadenaEditMain"
                    SetWindowText (edit, cadenaEditMain);             //Se imprime en el edit la cadena donde se encuentra el resultado
                    //Reseteamos las variables
                    primer_num = 0;
                    segundo_num = 0;
                    operacion = 0;
                    break;
                }
                case ID_BOTONRESET:                                  //Boton que limpia las variables y datos para calcular de nuevo
                {
                    primer_num = 0;
                    segundo_num = 0;
                    operacion = 0;
                    SetWindowText (edit, "");
                    SetWindowText (label, "");
                    break;
                }
                case ID_BOTONRESET2:                                 //Boton que borra solo el ultimo numero introducido
                {
                    segundo_num = 0;
                    SetWindowText (edit, "");
                    break;
                }
 
                break;
            }
            break;
        }
 
        case WM_PAINT:
        {
            hdc = BeginPaint(hwnd, &ps);
            SetBkColor (hdc, RGB(88, 145, 192));
            SetTextColor (hdc, color1);
            TextOut(hdc, 230, 240, greeting, _tcslen(greeting));
            EndPaint (hwnd, &ps);
            break;
        }
 
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
 
    return 0;
}
 
void imprimirEdit (int i)                        //Funcion que concatena los numeros al hacer clic en los botones
{
    char cadenaEdit [31];                        //Variable donde se guardara lo que hay en el edit (no es la misma variable que cadenaEditMain)
    char numero [3];                             //Variable donde se guardara el numero de la tecla presionada
    sprintf (numero, "%i", i);                   //Se transforma el numero (i) del tipo entero a una cadena
 
    GetWindowText (edit, cadenaEdit, 30);        //Se obtiene lo que hay en el edit y se guarda en "CadenaEdit"
    strcat (cadenaEdit, numero);                 //Se une lo que hay en "CadenaEdit" y lo que hay en "numero" (es decir, se une lo que habia en el edit y el numero de la tecla presionada) y se queda guardada la nueva cifra en "cadenaEdit"
    SetWindowText (edit, cadenaEdit);            //Se imprime el nuevo numero en el edit
}
 
double calcular (double primer_num, double segundo_num, int operacion)   //Funcion que realiza las operaciones
{
    double resultado;                                                    //Variable donde se guardara el resultado (sera lo que se retorne)
 
    switch (operacion)                                                   //Ver lo que hay en la variable "operacion"
    {
        case 1:                                                          //En caso de que sea "1" se suma el primer numero al segundo
        {
            resultado = primer_num + segundo_num;
            break;
        }
        case 2:                                                          //En caso de que sea "2" se le resta el segundo numero al primero
        {
            resultado = primer_num - segundo_num;
            break;
        }
        case 3:                                                          //En caso de que sea "3" se multiplica el primer numero por el segundo
        {
            resultado = primer_num * segundo_num;
            break;
        }
        case 4:                                                          //En caso de que sea "4" se divide el primer numero entre el segundo
        {
            resultado = primer_num / segundo_num;
            break;
        }
        case 5:                                                          //En caso de que sea "5" se haya el tanto por cierto (primer numero) del segundo numero
        {
            resultado = (primer_num * segundo_num) / 100;
            break;
        }
        case 6:                                                          //En caso de que sea "6" se obtiene la potencia del primer numero elevado al segundo
        {
            resultado = pow (primer_num, segundo_num);
            break;
        }
        case 7:                                                          //En caso de que sea "7" se obtiene la raiz del primer numero (el segundo define si dicha raiz es cubica, cuadrada...)
        {
            resultado = pow (primer_num, 1/segundo_num);
            break;
        }
        default:                                                         //Si no se realiza ninguna operacion se imprime en el label un mensaje, con esto sabriamos si ha habido algun error
        {
            SetWindowText (label, "No se ha realizado ninguna operacion.");
            break;
        }
    }
 
    SetWindowText (label, "");                                           //Limpiamos el label
    return resultado;                                                    //Devuelve el resultado
}
