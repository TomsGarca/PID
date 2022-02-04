#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

////////////////DEFINICIONES////////////////
#define MONO 1
#define MULTI 2
#define NONE 3
////////////////DEFINICIONES////////////////

using namespace std;

////////////////FUNCIONES GLOBALES////////////////
int _contador = 100;
int incrmt () { return _contador = _contador + 1; }
////////////////FUNCIONES GLOBALES////////////////

//////////////////////////////////////////////////ASPECTO//////////////////////////////////////////////////
void fila( int with, char caracter )
{
    cout << " " << setw ( with ) << setfill ( caracter ) << " "<< setfill ( ' ' ) << endl;
}

void fila( int with, char caracter, int o )
{
    cout << setw ( with ) << setfill ( caracter ) << " " << setfill ( ' ' ) << endl;
}

void titulo( int with, int l, int c, string n, int r )
{
    fila ( with, '-' );
    cout << "|" << left << setw ( l ) << " " << left << setw ( c ) << n << right << setw ( r ) << " " << "|" << endl;
    fila ( with, '-' );
}

void renglon( int l, string posicion, int intr,string txt, int r )
{
    cout << "|" << right << setw ( l ) << posicion << right << setw ( intr ) << txt << right << setw ( r ) << " " << "|" << endl;
}

void renglon( int l, string posicion, int l2, string text1, int c, string textc, int r2, string text2, int r1, string text3 )
{
    cout << "|" << left << setw ( l ) << posicion << "|" << left << setw ( l2 ) << text1 << "|" << left << setw ( c ) << textc << "|" << left << setw ( r2 ) << text2 << "|" << left << setw ( r1 ) << text3 << "|" << endl;
}

void renglon( int l, string posicion, int intr,string txt, int r, char n )  //// laterales con caracter personalido
{
    cout << n << right << setw ( l ) << posicion << left << setw ( intr ) << txt << right << setw ( r ) << n << endl;
}

void renglond(int l, string posicion, int l2, string text1, int c, string textc, int r2, string text2, int r1, string text3)
{
    cout << "|" << left << setw ( l ) << posicion << "|" << right << setw ( l2 ) << text1 << "|" << right << setw ( c ) << textc << "|" << right << setw ( r2 ) << text2 << "|" << right << setw ( r1 ) << text3 << "|" << endl;
}
//////////////////////////////////////////////////ASPECTO//////////////////////////////////////////////////

struct Nodo
{
    string name;
    short prio;
    short t_exe;
    short t_ll;
    short fin;
    int PID;
    Nodo *next;
};

struct Cola
{
    Nodo *sgte = NULL;
    Nodo *atras = NULL;
};

//////ESTILO DE IMPRESION
void printCola( Cola q )
{
    //titulo(80, 28, 25, "LISTA DE PROCESOS", 25);
    fila ( 80, '-' );
    renglon ( 15, "NOMBRE", 10, "PID", 20, "T. LLEGADA", 20, "T. EXE", 10, "PRIORIDAD" );
    fila ( 80, '-', 0 );

    Nodo *primero;
    primero = q.sgte;

    while( primero != NULL )
    {
        renglond ( 15, primero->name, 10, to_string ( primero->PID ), 20, to_string ( primero->t_ll ), 20, to_string ( primero->t_exe ), 10, to_string ( primero->prio ) );
            primero = primero->next;
    }

    fila ( 80 , '-');
    cout << endl;
}

/////AGREGA DATOS A LA COLA
void encolarT( Cola &q, string n, short p, short texe, short tll )
{
    Nodo *primero = new ( Nodo );

    primero->name = n;
    primero->prio = p;
    primero->t_exe = texe;
    primero->t_ll = tll;
    primero->PID = incrmt ();
    primero->next = NULL;
    
    if( q.sgte == NULL )
    {
        q.sgte = primero;
    }
    else
    {
        ( q.atras )->next = primero;
    }
    q.atras = primero;
}

/////AGREGA DATOS A LA COLA CON PID
void encolarT( Cola &q, string n, short p, short texe, short tll, int ID )
{
    Nodo *primero = new ( Nodo );
    
    primero->name = n;
    primero->prio = p;
    primero->t_exe = texe;
    primero->t_ll = tll;
    primero->PID = ID;
    primero->next = NULL;
    
    if( q.sgte == NULL)
    {
        q.sgte = primero;
    }
    else
    {
        (q.atras)->next = primero;
    }
    q.atras = primero;
}

/////AGREGA UN NODO A LA COLA CON PID
void encolarT( Cola &q, Nodo n )
{
    Nodo *primero = new ( Nodo );
    primero->name = n.name;
    primero->prio = n.prio;
    primero->t_exe = n.t_exe;
    primero->t_ll = n.t_ll;
    primero->PID = n.PID;
    primero->next = NULL;
    
    if( q.sgte == NULL)
    {
        q.sgte = primero;
    }
    else
    {
        (q.atras)->next = primero;
    }
    q.atras = primero;
}

/////AGREGA DATOS A LA COLA POR MEDIO DE ARCHIVO .TXT
void encolarT( Cola &q, string archivo )
{
    short prio, texe, tll;
    string name, archv = "../resource/" + archivo;

    if ( ifstream datos { archv } )
    {
        datos.is_open ();
        string linea;

        while ( getline ( datos, linea ) )
        {
            stringstream procesar { linea };

            procesar >> name;
            procesar >> tll;
            procesar >> texe;
            procesar >> prio;

            encolarT ( q, name, prio, texe, tll );
        }
    }
    else if ( datos.fail () )
    {
        cout << "ERROR! El archivo '" << archivo << "' no fue encontrado o no existe." << endl;
    }
    
}

//// QUITA PRIMER DATO
Nodo desencolarNodo ( Cola &q ) //DESENCOLA EL PRIMER NODO
{
    int _pid, _prio, _texe, _tll;
    string _name;
    Nodo *primero, segundo;

    primero = q.sgte;
    _pid = primero->PID;
    _name = primero->name;
    _prio = primero->prio;
    _texe = primero->t_exe;
    _tll = primero->t_ll;

    q.sgte = (q.sgte)->next;

    delete ( primero );

    segundo.name = _name;
    segundo.PID = _pid;
    segundo.prio = _prio;
    segundo.t_exe = _texe;
    segundo.t_ll = _tll;

    return segundo;
}

void cambio ( Nodo *primero, Nodo *segundo )
{
    short prio_aux, texe_aux, tll_aux;
    string name_aux; int pid_aux;

    prio_aux = primero->prio;
    texe_aux = primero->t_exe;
    tll_aux = primero->t_ll;
    name_aux = primero->name;
    pid_aux = primero->PID;

    primero->prio = segundo->prio;
    primero->t_exe = segundo->t_exe;
    primero->t_ll = segundo->t_ll;
    primero->name = segundo->name;
    primero->PID = segundo->PID;

    segundo->prio = prio_aux;
    segundo->t_exe = texe_aux;
    segundo->t_ll = tll_aux;
    segundo->name = name_aux;
    segundo->PID = pid_aux;
}

void orderTll ( Cola &q )
{
    Nodo *primero, *segundo;

    primero = q.sgte;

    while ( primero->next != NULL )
    {
        segundo = primero->next;
        while ( segundo != NULL )
        {
            if ( primero->t_ll > segundo->t_ll )
            {
               cambio( primero, segundo );
            }
            segundo = segundo->next;
        }
        primero = primero->next;
    }
}

void eliminarTarea ( Cola &q, int ID )
{
    Nodo *Siguiente = new ( Nodo );
    Nodo *Atras = new ( Nodo );
    bool ent = false;
    Siguiente = q.sgte;
    Atras = NULL;

    while ( Siguiente != NULL && ent != true )
    {
        if ( Siguiente->PID == ID )
        {
            cout << "\tELIMINANDO PROCESO " << Siguiente->PID <<  "\n" << endl;
            fila ( 80, '-' );
            renglon ( 15, "NOMBRE", 10, "PID", 20, "T. EXE", 20, "T. LLEGADA", 10, "PRIORIDAD" );
            fila ( 80, '-', 0 );
            renglond ( 15, Siguiente->name, 10, to_string ( Siguiente->PID ), 20, to_string ( Siguiente->t_exe ), 20, to_string ( Siguiente->t_ll ), 10, to_string ( Siguiente->prio ) );
            fila (80 , '-', 0);
            
            if ( Siguiente == q.sgte )
            {
                q.sgte = (q.sgte)->next;
            }
            else if ( Siguiente == q.atras )
            {
                Atras->next = NULL;
                q.atras = Atras;
            }
            else
            {
                Atras->next = Siguiente->next;
            }
            ent = true;
            cout << "\tPROCESO ELIMINADO" << "\n" << endl;
        }
        Atras = Siguiente;
        Siguiente = Siguiente->next;
    }
    if ( !ent )
    {
        cout << "\tEL PID: " << ID << " NO EXISTE EN LA LISTA DE PROCESOS" << endl;
    }
}

struct Procesador //// STRUCT O CLASE?
{
    int tipo; //MONOPROCRESO, MULTIPROCESO
    int gestion; //MONOTAREA, MULTITAREA
    Nodo *sgte = NULL;
    Nodo *atras = NULL;
    Cola canal; ////Canales?
};

void encolarT( Procesador &p, Nodo n )
{
    Nodo *primero = new ( Nodo );
    primero->name = n.name;
    primero->prio = n.prio;
    primero->t_exe = n.t_exe;
    primero->t_ll = n.t_ll;
    primero->PID = n.PID;
    primero->next = NULL;
    
    if( p.sgte == NULL)
    {
        p.sgte = primero;
    }
    else
    {
        (p.atras)->next = primero;
    }
    p.atras = primero;
}

void encolarT( Cola &p, Nodo n, short pass )
{
    Nodo *primero = new ( Nodo );
    primero->name = n.name;
    primero->prio = n.prio;
    primero->t_exe = n.t_exe;
    primero->t_ll = n.t_ll;
    primero->PID = n.PID;
    primero->fin = pass;
    primero->next = NULL;
    
    if( p.sgte == NULL)
    {
        p.sgte = primero;
    }
    else
    {
        (p.atras)->next = primero;
    }
    p.atras = primero;
}

Nodo desencolarNodo( Procesador &q ) //DESENCOLA EL PRIMER NODO
{
    int _pid, _prio, _texe, _tll;
    string _name;
    Nodo *primero, segundo;

    primero = q.sgte;
    _pid = primero->PID;
    _name = primero->name;
    _prio = primero->prio;
    _texe = primero->t_exe;
    _tll = primero->t_ll;

    q.sgte = (q.sgte)->next;

    delete ( primero );

    segundo.name = _name;
    segundo.PID = _pid;
    segundo.prio = _prio;
    segundo.t_exe = _texe;
    segundo.t_ll = _tll;

    return segundo;
}

void orderPID( Procesador &q , short prio[] )
{
    Nodo *primero, *segundo;

    primero = q.sgte;

    switch ( prio [ 0 ] )
    {
        case 1:
            while ( primero->next != NULL )
            {
                segundo = primero->next;
                while ( segundo != NULL )
                {
                    if ( primero->PID > segundo->PID )  //orden ASC
                    {
                        cambio ( primero, segundo );
                    }
                    segundo = segundo->next;
                }
                primero = primero->next;
            }
            break;
        case 2:
            while ( primero->next != NULL )
            {
                segundo = primero->next;
                while ( segundo != NULL )
                {
                    if ( primero->PID < segundo->PID)   // Orden DSC
                    {
                        cambio ( segundo, primero );
                    }
                    segundo = segundo->next;
                }
                primero = primero->next;
            }
        default:
            break;
    }
}

void orderTexe( Procesador &q, short opc, short prio [] )
{
    Nodo *primero, *segundo;
    primero = q.sgte;

    switch ( prio [ 0 ] )
    {
        case 1:
            while ( primero->next != NULL )
            {
                segundo = primero->next;
                while ( segundo != NULL )
                {
                    if ( primero->t_exe == segundo->t_exe )
                    {
                        switch ( opc )
                        {
                            case 1: /// SI ELIGE PRIORIDAD
                                switch ( prio [ 1 ] )
                                {
                                    case 1:
                                        if ( primero->prio == segundo->prio )
                                        {
                                            switch ( prio [ 2 ] )
                                            {
                                                case 1:
                                                    if ( primero->PID > segundo->PID )
                                                    {
                                                    cambio ( primero, segundo );
                                                    }
                                                    break;
                                                case 2:
                                                    if ( primero->PID < segundo->PID )
                                                    {
                                                    cambio ( segundo, primero );
                                                    }
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        if ( primero->prio > segundo->prio )
                                        {
                                        cambio ( primero, segundo );
                                        }
                                        break;
                                    case 2:
                                        if ( primero->prio == segundo->prio )
                                        {
                                            switch ( prio [ 2 ] )
                                            {
                                                case 1:
                                                    if ( primero->PID > segundo->PID )
                                                    {
                                                    cambio ( primero, segundo );
                                                    }
                                                    break;
                                                case 2:
                                                    if ( primero->PID < segundo->PID )
                                                    {
                                                    cambio ( segundo, primero );
                                                    }
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        if ( primero->prio < segundo->prio )
                                        {
                                        cambio ( segundo, primero );
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            case 2: /// SI ELIGE PID
                                switch (prio[1])
                                {
                                    case 1:
                                        if ( primero->PID > segundo->PID )
                                        {
                                        cambio ( primero, segundo );
                                        }
                                        break;
                                    case 2:
                                        if ( primero->PID < segundo->PID )
                                        {
                                        cambio ( segundo, primero );
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                break;
                        default:
                            break;
                        }
                    }
                    if ( primero->t_exe > segundo->t_exe )
                    {
                        cambio ( primero, segundo );
                    }
                    segundo = segundo->next;
                }
                primero = primero->next;
            }
            break;
        case 2:
            while ( primero->next != NULL )
            {
                segundo = primero->next;
                while ( segundo != NULL )
                {
                    if ( primero->t_exe == segundo->t_exe )
                    {
                        switch ( opc )
                        {
                            case 1: /// SI ELIGE PRIORIDAD
                                switch ( prio[ 1 ] )
                                {
                                    case 1:
                                        if ( primero->prio == segundo->prio )
                                        {
                                            switch ( prio [ 2 ] )
                                            {
                                                case 1:
                                                    if (primero->PID > segundo->PID)
                                                    {
                                                    cambio ( primero, segundo );
                                                    }
                                                    break;
                                                case 2:
                                                    if ( primero->PID < segundo->PID )
                                                    {
                                                    cambio ( segundo, primero );
                                                    }
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        if ( primero->prio > segundo->prio )
                                        {
                                        cambio ( primero, segundo );
                                        }
                                        break;
                                    case 2:
                                        if ( primero->prio == segundo->prio )
                                        {
                                            switch ( prio[ 2 ] )
                                            {
                                                case 1:
                                                    if ( primero->PID > segundo->PID )
                                                    {
                                                    cambio ( primero, segundo );
                                                    }
                                                    break;
                                                case 2:
                                                    if ( primero->PID < segundo->PID )
                                                    {
                                                    cambio ( segundo, primero );
                                                    }
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        if ( primero->prio < segundo->prio )
                                        {
                                        cambio ( segundo, primero );
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            case 2: /// SI ELIGE PUD
                                switch ( prio [ 1 ] )
                                {
                                    case 1:
                                        if ( primero->PID > segundo->PID )
                                        {
                                        cambio ( primero, segundo );
                                        }
                                        break;
                                    case 2:
                                        if ( primero->PID < segundo->PID )
                                        {
                                        cambio ( segundo, primero );
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                break;
                        default:
                            break;
                        }
                    }
                    if ( primero->t_exe < segundo->t_exe )
                    {
                        cambio ( segundo, primero );
                    }
                    segundo = segundo->next;
                }
                primero = primero->next;
            }
        default:
            break;
    }
}

void orderPrio( Procesador &q, short opc, short prio [] )
{
    Nodo *primero, *segundo;

    primero = q.sgte;

    switch ( prio [ 0 ] )
    {
        case 1:
            while ( primero->next != NULL )
            {
                segundo = primero->next;
                while ( segundo != NULL )
                {
                    if ( primero->prio == segundo->prio )
                    {
                        switch ( opc )
                        {
                            case 1: /// SI ELIGE TEXE
                                switch ( prio[ 1 ] )
                                {
                                    case 1:
                                        if ( primero->t_exe == segundo->t_exe )
                                        {
                                            switch ( prio [ 2 ] )
                                            {
                                                case 1:
                                                    if ( primero->PID > segundo->PID )
                                                    {
                                                    cambio ( primero, segundo );
                                                    }
                                                    break;
                                                case 2:
                                                    if ( primero->PID < segundo->PID )
                                                    {
                                                    cambio ( segundo, primero );
                                                    }
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        if ( primero->t_exe > segundo->t_exe )
                                        {
                                        cambio ( primero, segundo );
                                        }
                                        break;
                                    case 2:
                                        if ( primero->t_exe == segundo->t_exe )
                                        {
                                            switch ( prio [ 2 ] )
                                            {
                                                case 1:
                                                    if ( primero->PID > segundo->PID )
                                                    {
                                                    cambio ( primero, segundo );
                                                    }
                                                    break;
                                                case 2:
                                                    if ( primero->PID < segundo->PID )
                                                    {
                                                    cambio ( segundo, primero );
                                                    }
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        if ( primero->t_exe < segundo->t_exe )
                                        {
                                        cambio ( segundo, primero );
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            case 2: /// SI ELIGE PID
                                switch ( prio [ 1 ] )
                                {
                                    case 1:
                                        if ( primero->PID > segundo->PID )
                                        {
                                        cambio ( primero, segundo );
                                        }
                                        break;
                                    case 2:
                                        if ( primero->PID < segundo->PID )
                                        {
                                        cambio ( segundo, primero );
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                break;
                        default:
                            break;
                        }
                    }
                    if ( primero->prio > segundo->prio )
                    {
                        cambio ( primero, segundo );
                    }
                    segundo = segundo->next;
                }
                primero = primero->next;
            }
            break;
        case 2:
            while ( primero->next != NULL )
            {
                segundo = primero->next;
                while ( segundo != NULL )
                {
                    if ( primero->prio == segundo->prio )
                    {
                        switch ( opc )
                        {
                            case 1: /// SI ELIGE texe
                                switch ( prio [ 1 ] )
                                {
                                    case 1:
                                        if ( primero->t_exe == segundo->t_exe )
                                        {
                                            switch ( prio [ 2 ] )
                                            {
                                                case 1:
                                                    if ( primero->PID > segundo->PID )
                                                    {
                                                    cambio ( primero, segundo );
                                                    }
                                                    break;
                                                case 2:
                                                    if ( primero->PID < segundo->PID )
                                                    {
                                                    cambio ( segundo, primero );
                                                    }
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        if ( primero->t_exe > segundo->t_exe )
                                        {
                                        cambio ( primero, segundo );
                                        }
                                        break;
                                    case 2:
                                        if ( primero->t_exe == segundo->t_exe )
                                        {
                                            switch ( prio [ 2 ] )
                                            {
                                                case 1:
                                                    if ( primero->PID > segundo->PID )
                                                    {
                                                    cambio ( primero, segundo );
                                                    }
                                                    break;
                                                case 2:
                                                    if ( primero->PID < segundo->PID )
                                                    {
                                                    cambio ( segundo, primero );
                                                    }
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        if ( primero->t_exe < segundo->t_exe )
                                        {
                                        cambio ( segundo, primero );
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            case 2: /// SI ELIGE PID
                                switch ( prio [ 1 ] )
                                {
                                    case 1:
                                        if ( primero->PID > segundo->PID )
                                        {
                                        cambio ( primero, segundo );
                                        }
                                        break;
                                    case 2:
                                        if ( primero->PID < segundo->PID )
                                        {
                                        cambio ( segundo, primero );
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                break;
                        default:
                            break;
                        }
                    }
                    if ( primero->prio < segundo->prio )
                    {
                        cambio ( segundo, primero );
                    }
                    segundo = segundo->next;
                }
                primero = primero->next;
            }
        default:
            break;
    }
}

void order( Procesador &q, short opc[], short prio[] )
{
    switch ( opc [ 0 ] )
    {
        case 1:
            orderTexe ( q, opc [ 1 ], prio );
            break;
        case 2:
            orderPrio ( q, opc [ 1 ], prio );
            break;
        case 3:
            orderPID ( q, prio );
            break;
        default: 
            break;
    }
}

void copiarNodo( Cola q, Cola &f ) //DESENCOLA EL PRIMER NODO
{
    int _pid, _prio, _texe, _tll, _fin;
    string _name;
    Nodo *primero, segundo;

    primero = q.sgte;
    _pid = primero->PID;
    _name = primero->name;
    _prio = primero->prio;
    _texe = primero->t_exe;
    _tll = primero->t_ll;
    _fin = primero->fin;

    //q.sgte = (q.sgte)->next;

    segundo.name = _name;
    segundo.PID = _pid;
    segundo.prio = _prio;
    segundo.t_exe = _texe;
    segundo.t_ll = _tll;
    segundo.fin = _fin;

    encolarT( f, segundo );
}

void eliminar0 ( Cola &q, Cola &f, int ID )
{
    Nodo *Siguiente = new ( Nodo );
    Nodo *Atras = new ( Nodo );
    bool ent = false;
    Siguiente = q.sgte;
    Atras = NULL;

    while ( Siguiente != NULL && ent != true )
    {
        if ( Siguiente->t_exe == ID )
        {
            copiarNodo ( q, f );
            if ( Siguiente == q.sgte )
            {
                q.sgte = (q.sgte)->next;
            }
            else if ( Siguiente == q.atras )
            {
                Atras->next = NULL;
                q.atras = Atras;
            }
            else
            {
                Atras->next = Siguiente->next;
            }
            ent = true;
        }
        else if ( Siguiente->t_exe != ID )
        {
            Atras = Siguiente;
            Siguiente = Siguiente->next;
        }
    }
}

void orderTexe( Cola &q)
{
    Nodo *primero, *segundo;
    primero = q.sgte;

    while ( primero->next != NULL )
    {
        segundo = primero->next;
        while ( segundo != NULL )
        {
            if ( primero->t_exe > segundo->t_exe )
            {
                cambio ( primero, segundo );
            }
            segundo = segundo->next;
        }
        primero = primero->next;
    }
}

void printCola( Procesador p )
{
    titulo ( 80, 28, 25, "PROCESADOR", 25 );
    fila ( 80, '-' );
    renglon ( 15, "NOMBRE", 10, "PID", 20, "T. LLEGADA", 20, "T. EXE", 10, "PRIORIDAD" );
    fila ( 80, '-', 0 );

    Nodo *primero;
    primero = p.sgte;

    while( primero != NULL )
    {
        renglond ( 15, primero->name, 10, to_string ( primero->PID ), 20, to_string ( primero->t_ll ), 20, to_string ( primero->t_exe ), 10, to_string ( primero->prio ) );
        primero = primero->next;
    }

    fila ( 80 , '-', 0 );
    cout << endl;
}

void printCola( Cola q, char c )
{
    switch (c)
    {
        Nodo *primero;
        case '*':
            titulo ( 80, 28, 25, "CANALES DE EJECUCION", 25 );
            fila ( 80, '-' );
            renglon ( 15, "NOMBRE", 10, "PID", 20, "T. LLEGADA", 20, "T. EXE", 10, "PRIORIDAD" );
            fila ( 80, '-', 0 );

            primero = q.sgte;
            
            while( primero != NULL )
            {
                renglond ( 15, primero->name, 10, to_string ( primero->PID ), 20, to_string ( primero->t_ll ), 20, to_string ( primero->t_exe ), 10, to_string ( primero->prio ) );
                primero = primero->next;
            }

            fila ( 80 , '-', 0 );
            cout << endl;
            break;
        case '-':
            titulo ( 80, 28, 25, "PROCESOS FINALIZADOS", 25 );
            fila ( 80, '-' );
            renglon ( 15, "NOMBRE", 10, "PID", 20, "T. EXE", 20, "ESTADO", 10, "T.FINAL" );
            fila ( 80, '-', 0 );

            primero = q.sgte;
            
            while( primero != NULL )
            {
                renglond ( 15, primero->name, 10, to_string ( primero->PID ), 20, to_string ( primero->t_exe ), 20, "FINALIZA", 10, to_string ( primero->fin ) );
                primero = primero->next;
            }

            fila ( 80 , '-', 0 );
            cout << endl;
            break;
        case '/':
            titulo ( 80, 28, 25, "COLA DE ESPERA", 25 );
            fila ( 80, '-' );
            renglon ( 15, "NOMBRE", 10, "PID", 20, "T. EXE", 20, "T. LLEGADA", 10, "PRIORIDAD" );
            fila ( 80, '-', 0 );

            
            primero = q.sgte;
            
            while( primero != NULL )
            {
                renglond ( 15, primero->name, 10, to_string ( primero->PID ), 20, to_string ( primero->t_exe ), 20, to_string ( primero->t_ll ), 10, to_string ( primero->prio ) );
                primero = primero->next;
            }

            fila ( 80 , '-', 0 );
            cout << endl;
            break;
        default:
            break;
    }
}

float sumaf( Cola q )
{
    float suma = 0.0;
    Nodo *primero;
    primero = q.sgte;

    while ( primero != NULL )
    {
        suma = suma + ( - primero->t_ll - primero->t_exe );
        primero = primero->next;
    }
    return suma;
}

float sumaf( Cola q, float sumado )
{
    float suma = 0.0;
    Nodo *primero;
    primero = q.sgte;

    while ( primero != NULL )
    {
        suma = suma + ( primero->fin );
        primero = primero->next;
    }
    return ( suma + sumado );
}

int cont( Cola q )
{
    int i = 0;
    Nodo *primero;
    primero = q.sgte;

    while ( primero != NULL )
    {
        i++;
        primero = primero->next;
    }
    return i;
}

void reducir( Cola &q )
{
    Nodo *primero;
    primero = q.sgte;

    while ( primero != NULL )
    {
        primero->t_exe--;
        primero = primero->next;
    }
}

int check( Cola q )
{
    int i = 0;
    Nodo *primero;
    primero = q.sgte;

    while ( primero != NULL )
    {
        if ( primero->t_exe == 0 )
        {
            i++;
        }
        primero = primero->next;
    }
    return i;
}

void procesarMM( Procesador &p, Cola &q, short opc [], short prio [] ) //MONOPROCESO MONOTAREA  DATOS.TXT XXXXX 
{
    short pass = 0; float temp = 0; 
    Cola f;
    orderTll ( q );    temp = sumaf( q );

    do
    {
        if ( q.sgte->t_ll == pass )
        {
            encolarT ( p, desencolarNodo ( q ) );
            order( p, opc, prio );
            
            if ( (p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0 )
            {
                encolarT ( f, desencolarNodo ( p.canal ), pass );
                //encolarT( p.canal, desencolarNodo ( p ) );
            }

        }
        else if ( q.sgte->t_ll != pass && p.sgte != NULL )
        {
            if ( (p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0 )
            {
                encolarT ( f, desencolarNodo ( p.canal ), pass );
                encolarT( p.canal, desencolarNodo ( p ) );
            }
            if ( (p.canal).sgte == NULL )
            {
                encolarT( p.canal, desencolarNodo ( p ) );
            }
            if ( (p.canal).sgte !=  NULL && (p.canal).sgte->t_exe != 0 )
            {
                (p.canal).sgte->t_exe--;
            }
            
            printCola ( q );
            printCola ( p );
            printCola ( p.canal, '*' );
            printCola ( f, '-' );
            cout << "\t PASO " << pass << "\n" << endl;
            pass++;
            system( "pause" );
            system( "cls" );
        }
        else if ( q.sgte->t_ll != pass && p.sgte == NULL )
        {
            if ( (p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0 )
            {
                encolarT ( f, desencolarNodo ( p.canal ), pass );
            }
            if ( (p.canal).sgte != NULL )
            {
                (p.canal).sgte->t_exe--;
            }
            
            printCola ( q );
            printCola ( p );
            printCola ( p.canal, '*' );
            printCola ( f, '-' );
            cout << "\t PASO " << pass << "\n" << endl;
            pass++;
            system( "pause" );
            system( "cls" );
        }
    } while ( q.sgte != NULL );

    do
    {
        if ( (p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0 )
        {
            encolarT ( f, desencolarNodo ( p.canal ), pass );
            encolarT( p.canal, desencolarNodo ( p ) );
        }
        if ( (p.canal).sgte == NULL )
        {
            encolarT( p.canal, desencolarNodo ( p ) );
        }
        if ( (p.canal).sgte != NULL && (p.canal).sgte->t_exe != 0 )
        {
            (p.canal).sgte->t_exe--;
        }
        
        printCola ( p );
        printCola ( p.canal, '*' );
        printCola ( f, '-' );
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system( "pause" );
        system( "cls" );
    } while ( p.sgte != NULL && q.sgte == NULL );

    do
    {
        if ( (p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0 )
        {
            encolarT ( f, desencolarNodo ( p.canal ), pass );
        }
        if ( (p.canal).sgte != NULL )
        {
            (p.canal).sgte->t_exe--;
        }
        
        printCola ( p.canal, '*' );
        printCola ( f, '-' );
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system( "pause" );
        system( "cls" );
        
    }while ( (p.canal).sgte != NULL && p.sgte == NULL && q.sgte == NULL );

    printCola ( f, '-' );
    cout << "\t PASO " << pass-1 << right << setw ( 53 ) << "SUMA: " << right << setw ( 6 ) << sumaf ( f, temp ) << endl;
    cout << right << setw ( 73 ) << "PROMEDIO: " << ( sumaf ( f, temp ) / cont ( f ) ) << endl;
    pass = 0;
    temp = 0;
    system("pause");
    system("cls");
}

void procesarMMt( Procesador &p, Cola &q, short opc [], short prio [] ) //MONOPROCESO MULTITAREA  DATOS2.TXT  
{
    short pass = 0; float temp = 0;
    Cola f; Cola espera;
    orderTll ( q );    temp = sumaf ( q );

    do
    {
        if (q.sgte->t_ll == pass)
        {
            if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0)
            {
                encolarT (f, desencolarNodo(p.canal), pass);
                //encolarT(p.canal, desencolarNodo(p));
            }

            if ((p.canal).sgte == NULL && p.sgte == NULL && espera.sgte != NULL)
            {
                //cout << "CANAL VACIO" << endl;
                while (espera.sgte != NULL)
                {
                    encolarT (p, desencolarNodo(espera));
                }
            }

            encolarT(p, desencolarNodo(q));
            order(p, opc, prio);
            
        }
        else if (q.sgte->t_ll != pass && p.sgte != NULL)
        {
            if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0)
            {
                encolarT (f, desencolarNodo(p.canal), pass);
                encolarT(p.canal, desencolarNodo(p));
            }
            if ((p.canal).sgte == NULL)
            {
                encolarT(p.canal, desencolarNodo(p));
            }
            if ((p.canal).sgte !=  NULL && (p.canal).sgte->t_exe != 0)
            {
                (p.canal).sgte->t_exe--;
                if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe != 0)
                {
                    encolarT (espera, desencolarNodo(p.canal));
                }
            }
            printCola (q);
            printCola (p);
            printCola (p.canal, '*'); printCola (espera, '/');
            printCola (f, '-');
            cout << "\t PASO " << pass << "\n" << endl;
            pass++;
            system("pause");
            system("cls");
            
        }
        else if (q.sgte->t_ll != pass && p.sgte == NULL)
        {
            if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0)
            {
                encolarT (f, desencolarNodo(p.canal), pass);
                encolarT(p.canal, desencolarNodo(p));
            }
            if ((p.canal).sgte == NULL && p.sgte == NULL)
            {
                while (espera.sgte != NULL)
                {
                    encolarT (p, desencolarNodo(espera));
                }
                if ((p.canal).sgte == NULL)
                {
                    encolarT(p.canal, desencolarNodo(p));
                }
                if ((p.canal).sgte !=  NULL && (p.canal).sgte->t_exe != 0)
                {
                    (p.canal).sgte->t_exe--;
                    if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe != 0)
                    {
                        encolarT (espera, desencolarNodo(p.canal));
                    }
                    
                }
                printCola (q);
                printCola (p);
                printCola (p.canal, '*'); printCola (espera, '/');
                printCola (f, '-');
                cout << "\t PASO " << pass << "\n" << endl;
                pass++;
                system("pause");
                system("cls");
            }
            else if ((p.canal).sgte != NULL)
            {
                if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0)
                {
                    encolarT (f, desencolarNodo(p.canal), pass);
                }
                if ((p.canal).sgte !=  NULL && (p.canal).sgte->t_exe != 0)
                {
                    (p.canal).sgte->t_exe--;
                    if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe != 0)
                    {
                        encolarT (espera, desencolarNodo(p.canal));
                    }
                }
                printCola (q);
                printCola (p);
                printCola (p.canal, '*'); printCola (espera, '/');
                printCola (f, '-');
                cout << "\t PASO " << pass << "\n" << endl;
                pass++;
                system("pause");
                system("cls");
                
            }
        }
    } while ( q.sgte != NULL );

    do
    {
        if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0)
        {
            encolarT (f, desencolarNodo(p.canal), pass);
            encolarT(p.canal, desencolarNodo(p));
        }
        if ((p.canal).sgte == NULL)
        {
            encolarT(p.canal, desencolarNodo(p));
        }
        if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe != 0)
        {
            (p.canal).sgte->t_exe--;
            if ((p.canal).sgte->t_exe != 0)
            {
                encolarT (espera, desencolarNodo(p.canal));
            }
        }
        printCola (p);
        printCola (p.canal, '*'); printCola (espera, '/');
        printCola (f, '-');
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system("pause");
        system("cls");
    } while ( p.sgte != NULL && q.sgte == NULL );

    do
    {
        if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0)
        {
            encolarT (f, desencolarNodo(p.canal), pass);
        }
        if ((p.canal).sgte == NULL)
        {
            encolarT(p.canal, desencolarNodo(espera));
        }
        if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe != 0)
        {
            (p.canal).sgte->t_exe--;
            if ((p.canal).sgte->t_exe != 0)
            {
                encolarT (espera, desencolarNodo(p.canal));
            }
        }
        printCola (p.canal, '*'); printCola (espera, '/');
        printCola (f, '-');
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system("pause");
        system("cls");
    } while ( espera.sgte != NULL && p.sgte == NULL && q.sgte == NULL );

    do
    {
        if ((p.canal).sgte != NULL && (p.canal).sgte->t_exe == 0)
        {
            encolarT (f, desencolarNodo(p.canal), pass);
        }
        if ((p.canal).sgte !=  NULL)
        {
            (p.canal).sgte->t_exe--;
            if ((p.canal).sgte->t_exe != 0)
            {
                encolarT (espera, desencolarNodo(p.canal));
            }
        }
        printCola (p.canal, '*'); printCola (espera, '/');
        printCola (f, '-');
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system("pause");
        system("cls");
    } while ( (p.canal).sgte != NULL && p.sgte == NULL && q.sgte == NULL );
    
    printCola ( f, '-' );
    cout << "\t PASO " << pass-1 << right << setw(53) << "SUMA: " << right << setw(6) << sumaf(f, temp) << endl;
    cout << right << setw ( 73 ) << "PROMEDIO: "  << ( sumaf ( f, temp ) / cont ( f ) ) << endl;
    pass = 0;
    temp = 0;
    system("pause");
    system("cls");
}

void procesarMtM( Procesador &p, Cola &q, short opc [], short prio[], int canal ) // MULTIPROCESO MONOTAREA  DATOS3.TXT   
{
    short pass = 0; float temp = 0;
    Cola f; temp = sumaf ( q );
    orderTll ( q );

    do
    {
        if (q.sgte->t_ll == pass)
        {
            encolarT(p, desencolarNodo(q));
            order(p, opc, prio);
            
            if ((p.canal).sgte != NULL && check(p.canal) != 0 )
            {
                orderTexe(p.canal);
                while (check(p.canal) != 0)
                {
                    encolarT(f, desencolarNodo(p.canal), pass);
                    check(p.canal);
                }
            }
        }
        else if ( q.sgte->t_ll != pass && p.sgte != NULL)
        {
            if ((p.canal).sgte != NULL && check(p.canal) != 0 )
            {
                orderTexe(p.canal);
                while (check(p.canal) != 0)
                {
                    encolarT(f, desencolarNodo(p.canal), pass);
                    check(p.canal);
                }
            }
            if (cont(p.canal) < (canal))
            {
                int i = cont(p.canal);
                while ( i < canal && p.sgte != NULL)
                {
                    encolarT(p.canal, desencolarNodo(p));
                    i++;
                }
            }
            if ((p.canal).sgte != NULL && check(p.canal) == 0 )
            {
                reducir(p.canal);
            }

            printCola (q);
            printCola (p);
            printCola (p.canal, '*');
            printCola (f, '-');
            cout << "\t PASO " << pass << "\n" << endl;
            pass++;
            system("pause");
            system("cls");
        }
        else if ( q.sgte->t_ll != pass && p.sgte == NULL)
        {
            if ((p.canal).sgte != NULL && check(p.canal) != 0 )
            {
                orderTexe(p.canal);
                while (check(p.canal) != 0)
                {
                    encolarT(f, desencolarNodo(p.canal), pass);
                    check(p.canal);
                }
            }
            if ((p.canal).sgte != NULL && check(p.canal) == 0 )
            {
                reducir(p.canal);
            }
            printCola (q);
            printCola (p);
            printCola (p.canal, '*');
            printCola (f, '-');
            cout << "\t PASO " << pass << "\n" << endl;
            pass++;
            system("pause");
            system("cls");
        }
    } while ( q.sgte != NULL );

    do
    {
        if ((p.canal).sgte != NULL && check(p.canal) != 0 )
        {
            orderTexe(p.canal);
            while (check(p.canal) != 0)
            {
                encolarT(f, desencolarNodo(p.canal), pass);
                check(p.canal);
            }
        }
        if (cont(p.canal) < (canal))
        {
            int i = cont(p.canal);
            while ( i < canal && p.sgte != NULL)
            {
                encolarT(p.canal, desencolarNodo(p));
                i++;
            }
        }
        if ((p.canal).sgte != NULL && check(p.canal) == 0 )
        {
            reducir(p.canal);
        }
        printCola (p);
        printCola (p.canal, '*');
        printCola (f, '-');
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system("pause");
        system("cls");
        
    } while ( p.sgte != NULL && q.sgte == NULL );

    do
    {
        if ((p.canal).sgte != NULL && check(p.canal) != 0 )
        {
            orderTexe(p.canal);
            while (check(p.canal) != 0)
            {
                encolarT(f, desencolarNodo(p.canal), pass);
                check(p.canal);
            }
        }
        if ((p.canal).sgte != NULL && check(p.canal) == 0 )
        {
            reducir(p.canal);
        }

        printCola (p.canal, '*');
        printCola (f, '-');
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system("pause");
        system("cls");
    }while ( (p.canal).sgte != NULL && p.sgte == NULL && q.sgte == NULL );

    printCola ( f, '-' );
    cout << "\t PASO " << pass-1 << right << setw ( 53 ) << "SUMA: " << right << setw ( 6 ) << sumaf ( f, temp ) << endl;
    cout << right << setw ( 73 ) << "PROMEDIO: " << ( sumaf ( f, temp ) / cont ( f ) ) << endl;
    pass = 0;
    temp = 0;
    system( "pause" );
    system( "cls" );
}

void procesarMtMt( Procesador &p, Cola &q, short opc [], short prio[], int canal ) //MULTIPROCESO MULTITAREA  DATOS4.TXT  
{
    short pass = 0; float temp = 0;
    Cola f; Cola espera; temp = sumaf ( q );
    orderTll ( q );

    do
    {
        if (q.sgte->t_ll == pass)
        {
            if ((p.canal).sgte != NULL && check(p.canal) != 0 )
            {
                while (check(p.canal) != 0)
                {
                    encolarT(f, desencolarNodo(p.canal), pass);
                    check(p.canal);
                }
                
                // printCola (q);
                // printCola (p);
                // printCola (p.canal, '*'); printCola (espera, '/');
                // printCola (f, '-');
                // cout << "\t PASO " << pass << "\n" << endl;
                ////system("pause");
                //system("cls");
            }
            if ((p.canal).sgte == NULL && p.sgte == NULL && espera.sgte != NULL)
            {
                while (espera.sgte != NULL)
                {
                    encolarT (p, desencolarNodo(espera));
                }
            }
            encolarT(p, desencolarNodo(q));
            order(p, opc, prio);
        }
        else if ( q.sgte->t_ll != pass && p.sgte != NULL)
        {
            if ((p.canal).sgte != NULL && check(p.canal) != 0 )
            {
                while (check(p.canal) != 0)
                {
                    encolarT(f, desencolarNodo(p.canal), pass);
                    check(p.canal);
                }
            }
            if (cont(p.canal) < (canal))
            {
                int i = cont(p.canal);
                while ( i < canal && p.sgte != NULL)
                {
                    encolarT(p.canal, desencolarNodo(p));
                    i++;
                }
            }
            if ((p.canal).sgte != NULL && check(p.canal) == 0 )
            {
                reducir(p.canal);
                while ((p.canal).sgte != NULL && check(p.canal) == 0 )
                {
                    encolarT(espera, desencolarNodo(p.canal));
                }
            }

            printCola (q);
            printCola (p);
            printCola (p.canal, '*'); printCola (espera, '/');
            printCola (f, '-');
            cout << "\t PASO " << pass << "\n" << endl;
            pass++;
            system("pause");
            system("cls");
        }
        else if ( q.sgte->t_ll != pass && p.sgte == NULL)
        {
            if ((p.canal).sgte != NULL && check(p.canal) != 0 )
            {
                while (check(p.canal) != 0)
                {
                    encolarT(f, desencolarNodo(p.canal), pass);
                    check(p.canal);
                }
            }
            if ((p.canal).sgte == NULL && p.sgte == NULL)
            {
                while (espera.sgte != NULL)
                {
                    encolarT (p, desencolarNodo(espera));
                }
                if ((p.canal).sgte == NULL && p.sgte != NULL)
                {
                    if (cont(p.canal) < (canal))
                    {
                        int i = cont(p.canal);
                        while ( i < canal && p.sgte != NULL)
                        {
                            encolarT(p.canal, desencolarNodo(p));
                            i++;
                        }
                    }
                }
                if ((p.canal).sgte != NULL && check(p.canal) == 0)
                {
                    reducir(p.canal);
                    while ((p.canal).sgte != NULL && check(p.canal) == 0)
                    {
                        encolarT (espera, desencolarNodo(p.canal));
                    }
                }

                printCola (q);
                printCola (p);
                printCola (p.canal, '*'); printCola (espera, '/');
                printCola (f, '-');
                cout << "\t PASO " << pass << "\n" << endl;
                pass++;
                system("pause");
                system("cls");
            }
            else if ((p.canal).sgte != NULL)
            {
                if ((p.canal).sgte != NULL && check(p.canal) != 0)
                {
                    while (check(p.canal) != 0)
                    {
                        encolarT(f, desencolarNodo(p.canal), pass);
                        check(p.canal);
                    }
                }
                if ((p.canal).sgte != NULL && check(p.canal) == 0 )
                {
                    reducir(p.canal);
                    while ((p.canal).sgte != NULL && check(p.canal) == 0 )
                    {
                        encolarT(espera, desencolarNodo(p.canal));
                    }
                }

                printCola (q);
                printCola (p);
                printCola (p.canal, '*'); printCola (espera, '/');
                printCola (f, '-');
                cout << "\t PASO " << pass << "\n" << endl;
                pass++;
                system("pause");
                system("cls");
            }
        }
    } while ( q.sgte != NULL );

    do
    {
        if ((p.canal).sgte != NULL && check(p.canal) != 0 )
        {
            while (check(p.canal) != 0)
            {
                encolarT(f, desencolarNodo(p.canal), pass);
                check(p.canal);
            }
        }
        if (cont(p.canal) < (canal))
        {
            int i = cont(p.canal);
            while ( i < canal && p.sgte != NULL)
            {
                encolarT(p.canal, desencolarNodo(p));
                i++;
            }
        }
        if ((p.canal).sgte != NULL && check(p.canal) == 0 )
        {
            reducir(p.canal);
            while ((p.canal).sgte != NULL && check(p.canal) == 0 )
            {
                encolarT(espera, desencolarNodo(p.canal));
            }
        }
        
        printCola (p);
        printCola (p.canal, '*'); printCola (espera, '/');
        printCola (f, '-');
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system("pause");
        system("cls");
    } while ( p.sgte != NULL && q.sgte == NULL );

    do
    {
        if ((p.canal).sgte != NULL && check(p.canal) != 0)
        {
            while (check(p.canal) != 0)
            {
                encolarT(f, desencolarNodo(p.canal), pass);
                check(p.canal);
            }
        }
        if (cont(p.canal) < (canal))
        {
            int i = cont(p.canal);
            while ( i < canal && espera.sgte != NULL)
            {
                encolarT(p.canal, desencolarNodo(espera));
                i++;
            }
        }
        if ((p.canal).sgte != NULL && check(p.canal) == 0)
        {
            reducir(p.canal);
            while ((p.canal).sgte != NULL && check(p.canal) == 0)
            {
                encolarT (espera, desencolarNodo(p.canal));
            }
        }

        printCola (p.canal, '*'); printCola (espera, '/');
        printCola (f, '-');
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system("pause");
        system("cls");
    } while ( espera.sgte != NULL && p.sgte == NULL && q.sgte == NULL );
    
    do
    {
        if ((p.canal).sgte != NULL && check(p.canal) != 0 )
        {
            while (check(p.canal) != 0)
            {
                encolarT(f, desencolarNodo(p.canal), pass);
                check(p.canal);
            }
        }
        if (cont(p.canal) < (canal))
        {
            int i = cont(p.canal);
            while ( i < canal && espera.sgte != NULL)
            {
                encolarT(p.canal, desencolarNodo(espera));
                i++;
            }
        }
        if ((p.canal).sgte != NULL && check(p.canal) == 0 )
        {
            reducir(p.canal);
        }

        printCola (p.canal, '*'); printCola (espera, '/');
        printCola (f, '-');
        cout << "\t PASO " << pass << "\n" << endl;
        pass++;
        system("pause");
        system("cls");
    }while ( (p.canal).sgte != NULL && p.sgte == NULL && q.sgte == NULL );

    printCola ( f, '-' );
    cout << "\t PASO " << pass << right << setw ( 53 ) << "SUMA: " << right << setw ( 6 ) << sumaf ( f, temp ) << endl;
    cout << right << setw ( 73 ) << "PROMEDIO: " << ( sumaf ( f, temp ) / cont ( f ) ) << endl;
    pass = 0;
    temp = 0;
    system( "pause" );
    system( "cls" );
}

void menu( Cola, Procesador );

int main ()
{
    Cola C1; Procesador P1;
    menu(C1, P1);
    return 0;
}

void menu(Cola C1, Procesador P1)
{
    P1.tipo = NONE; P1.gestion = NONE; 
    short prioridad, texe, tllegada; // valores para tarea
    short key[4]; int pid; /// llaves para menu y pid para borrar
    int n; n = 0;
    string cadena; // valores para tarea
    short opc[2] = {1,1}; short prio[3] = {1,1,1}; /// ORDENAMIENTO DEFAULT
    do
    {
        titulo( 80, 28, 25, "SIMULADOR--PROCESADOR", 26 );
        renglon( 46,  "ELIGE UNA OPCION", 32, "", 0);
        fila( 80 , '-');
        renglon( 10, "1) ", 28, "INGRESAR NUEVA TAREA", 41 );
        renglon( 10, "2) ", 36, "INGRESAR TAREA DESDE ARCHIVO", 33 );
        renglon( 10, "3) ", 31, "MOSTRAR LISTA DE TAREAS", 38 );
        renglon( 10, "4) ", 28, "MODIFICAR PROCESADOR", 41 );
        renglon( 10, "5) ", 36, "MODIFICAR ORDEN DE EJECUCION", 33 );
        renglon( 10, "6) ", 29, "INICIAR PROCESAMIENTO", 40 );
        renglon( 10, "7) ", 24, "ELIMINAR PROCESO", 45 );
        renglon( 10, "0) ", 13, "SALIR", 56 );
        fila( 80 , '-');
        cout << "\tOPCION: "; cin >> key [ 0 ];
        switch ( key [ 0 ] )
        {
            case 1:
                system("cls");
                titulo( 80, 28, 20, "INGRESAR NUEVA TAREA", 31);
                cout << "\tNOMBRE: "; cin >> cadena;
                cout << "\tPRIORIDAD: "; cin >> prioridad;
                cout << "\tTIEMPO DE EJECUCION: "; cin >> texe;
                cout << "\tTIEMPO DE LLEGADA: "; cin >> tllegada;
                encolarT( C1, cadena, prioridad, texe, tllegada);
                cout << "\n\tTAREA CREADA CON EXITOSAMENTE " << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                titulo( 80, 25, 30, "INGRESAR TAREA DESDE ARCHIVO", 24 );
                cout << "\tNOMBRE DE ARCHIVO: "; cin >> cadena;
                encolarT( C1, cadena );
                cout << "\n\tTAREA CREADA CON EXITOSAMENTE " << endl;
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                titulo( 80, 27, 25, "MOSTRAR LISTA DE TAREAS", 27 );
                printCola( C1 );
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                titulo( 80, 28, 25, "MODIFICAR PROCESADOR", 26 );
                renglon( 46,  "ELIGE UNA OPCION", 32, "", 0);
                renglon(10, "1) ", 26, "TIPO DE PROCESADOR", 43);
                renglon(10, "2) ", 29, "TIPO DE PROCESAMIENTO", 40);
                fila( 80, '-');
                cout << "\tOPCION: "; cin >> key[1];
                switch (key[1])
                {
                    case 1:
                        titulo( 80, 28, 25, "TIPO DE PROCESADOR", 26 );
                        renglon(10, "1) ", 19, "MONOPROCESO", 50);
                        renglon(10, "2) ", 20, "MULTIPROCESO", 49);
                        fila( 80, '-');
                        cout << "\tOPCION: "; cin >> key[2];
                        switch (key[2])
                        {
                            case 1:
                                P1.tipo = MONO;
                                break;
                            case 2:
                                P1.tipo = MULTI;
                                cout << "\tNUMERO DE CANALES: "; cin >> n;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        titulo( 80, 28, 25, "TIPO DE PROCESAMIENTO", 26 );
                        renglon(10, "1) ", 17, "MONOTAREA", 52);
                        renglon(10, "2) ", 18, "MULTITAREA", 51);
                        fila( 80, '-');
                        cout << "\tOPCION: "; cin >> key[2];
                        switch (key[2])
                        {
                            case 1:
                                P1.gestion = MONO;
                                break;
                            case 2:
                                P1.gestion = MULTI;
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                titulo( 80, 25, 30, "MODIFICAR ORDEN DE EJECUCION", 24 );
                titulo( 80, 28, 25, "PRIMER CRITERIO", 26 );
                renglon(10, "1) ", 26, "TIEMPO DE EJECUCION", 43);
                renglon(10, "2) ", 16, "PRIORIDAD", 53);
                renglon(10, "3) ", 10, "PID", 59);
                fila( 80, '-');
                cout << "\tOPCION: "; cin >> key[1];
                switch (key[1])
                {
                    case 1: ////EXE
                        opc[0] = 1;
                        titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                        renglon(10, "1) ", 18, "\tASC\t(LIGERO)", 40);
                        renglon(10, "2) ", 18, "\tDSC\t(PESADO)", 40);
                        fila( 80, '-');
                        cout << "\tOPCION: "; cin >> prio[0];
                        system("pause");

                        titulo( 80, 28, 25, "SEGUNDO CRITERIO", 26 );
                        renglon(10, "1) ", 16, "PRIORIDAD", 53);
                        renglon(10, "2) ", 10, "PID", 59);
                        fila( 80, '-');
                        cout << "\tOPCION: "; cin >> key[2];
                        switch (key[2])
                        {
                            case 1: ///prioridad
                                opc[1] = 1;
                                titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                                renglon(10, "1) ", 18, "\tASC\t(BAJA)", 42);
                                renglon(10, "2) ", 18, "\tDSC\t(ALTA)", 42);
                                fila( 80, '-');
                                cout << "\tOPCION: "; cin >> prio[1];
                                system("pause");

                                titulo( 80, 28, 25, "TERCER CRITERIO", 26 );
                                renglon(10, "1) ", 10, "PID", 59);
                                fila( 80, '-');
                                titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                                renglon(10, "1) ", 18, "\tASC\t(0...N)", 41);
                                renglon(10, "2) ", 18, "\tDSC\t(N...0)", 41);
                                fila( 80, '-');
                                cout << "\tOPCION: "; cin >> prio[2];
                                system("pause");
                                system("cls");
                                break;
                            case 2: ////pid 
                                opc[1] = 2;
                                titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                                renglon(10, "1) ", 18, "\tASC\t(0...N)", 41);
                                renglon(10, "2) ", 18, "\tDSC\t(N...0)", 41);
                                fila( 80, '-');
                                cout << "\tOPCION: "; cin >> prio[2];
                                system("pause");
                                system("cls");
                                break;
                            default:
                                system("cls");
                                break;
                        }
                        break;
                    case 2: //PRIORIDAD
                        opc[0] = 2;
                        titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                        renglon(10, "1) ", 18, "\tASC\t(BAJA)", 42);
                        renglon(10, "2) ", 18, "\tDSC\t(ALTA)", 42);
                        fila( 80, '-');
                        cout << "\tOPCION: "; cin >> prio[0];
                        system("pause");

                        titulo( 80, 28, 25, "SEGUNDO CRITERIO", 26 );
                        renglon(10, "1) ", 26, "TIEMPO DE EJECUCION", 43);
                        renglon(10, "2) ", 10, "PID", 59);
                        fila( 80, '-');
                        cout << "\tOPCION: "; cin >> key[2];
                        switch (key[2])
                        {
                            case 1: //EXE
                                opc[1] = 1;
                                titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                                renglon(10, "1) ", 18, "\tASC\t(LIGERO)", 40);
                                renglon(10, "2) ", 18, "\tDSC\t(PESADO)", 40);
                                fila( 80, '-');
                                cout << "\tOPCION: "; cin >> prio[1];
                                system("pause");

                                titulo( 80, 28, 25, "TERCER CRITERIO", 26 );
                                renglon(10, "1) ", 10, "PID", 59);
                                fila( 80, '-');
                                titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                                renglon(10, "1) ", 18, "\tASC\t(0...N)", 41);
                                renglon(10, "2) ", 18, "\tDSC\t(N...0)", 41);
                                fila( 80, '-');
                                cout << "\tOPCION: "; cin >> prio[2];
                                system("pause");
                                system("cls");
                                break;
                            case 2:  //PID
                                opc[1] = 2;
                                titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                                renglon(10, "1) ", 18, "\tASC\t(0...N)", 41);
                                renglon(10, "2) ", 18, "\tDSC\t(N...0)", 41);
                                fila( 80, '-');
                                cout << "\tOPCION: "; cin >> prio[1];
                                system("pause");
                                system("cls");
                                break;
                            default:
                                system("cls");
                                break;
                        }
                        break;
                    case 3: //PID
                        opc[0] = 3;
                        titulo( 80, 24, 25, "TIEMPO DE EJECUCION ASC O DSC", 26 );
                        renglon(10, "1) ", 18, "\tASC\t(0...N)", 41);
                        renglon(10, "2) ", 18, "\tDSC\t(N...0)", 41);
                        fila( 80, '-');
                        cout << "\tOPCION: "; cin >> prio[0];
                        system("pause");
                        system("cls");
                        break;
                    default:
                        system("cls");
                        break;
                }
                break;
            case 6:
                system("cls");
                titulo( 80, 25, 25, "INICIAR PROCESAMIENTO", 26 );
                system("pause");
                system("cls");
                switch (P1.tipo)
                {
                    case MONO:
                        cout << "\tPROCESADOR MONOPROCESO" << endl;
                        switch (P1.gestion)
                        {
                            case MONO:
                                cout << "\tGESTION MONOTAREA" << endl;
                                system("pause");
                                procesarMM (P1, C1, opc, prio);
                                system("cls");
                                titulo( 80, 29, 20, "NOS VEMOS LUEGO  <3", 30 );
                                system("pause");
                                system("cls");
                                key[0] = 0;
                                break;
                            case MULTI:
                                cout << "\tGESTION MULTITAREA" << endl;
                                system("pause");
                                procesarMMt(P1, C1, opc, prio);
                                system("cls");
                                titulo( 80, 29, 20, "NOS VEMOS LUEGO  <3", 30 );
                                system("pause");
                                system("cls");
                                key[0] = 0;
                                break;
                            case NONE:
                                cout << "\tNO AH SELECCIONADO UN TIPO DE GESTION" << endl;
                                break;
                            default:
                                break;
                        }
                        break;
                    case MULTI:
                        cout << "\tPROCESADOR MULTIPROCESO" << endl;
                        switch (P1.gestion)
                        {
                            case MONO:
                                cout << "\tGESTION MONOTAREA" << endl;
                                system("pause");
                                procesarMtM (P1, C1, opc, prio, n);
                                system("cls");
                                titulo( 80, 29, 20, "NOS VEMOS LUEGO  <3", 30 );
                                system("pause");
                                system("cls");
                                key[0] = 0;
                                break;
                            case MULTI:
                                cout << "\tGESTION MULTITAREA" << endl;
                                system("pause");
                                procesarMtMt(P1, C1, opc, prio, n);
                                system("cls");
                                titulo( 80, 29, 20, "NOS VEMOS LUEGO  <3", 30 );
                                system("pause");
                                system("cls");
                                key[0] = 0;
                                break;
                            case NONE:
                                cout << "\tNO AH SELECCIONADO UN TIPO DE GESTION" << endl;
                                break;
                            default:
                                break;
                        }
                        break;
                    case NONE:
                        cout << "\tNO AH SELECCIONADO UN TIPO DE PROCESADOR" << endl;
                        break;
                    default:
                        break;
                }
                break;
            case 7:
                system("cls");
                titulo(80, 25, 25, "ELIMINAR PROCESO", 29);
                cout << "\tINGRESE PID A ELIMINAR: "; cin >> pid;
                eliminarTarea(C1, pid);
                printCola (C1);
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                titulo( 80, 29, 20, "NOS VEMOS LUEGO  <3", 30 );
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                break;
        }
    } while ( key[0] != 0);
}