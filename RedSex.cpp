// RedSex.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "string"
#include "../Biblioteca/DiskIO.h"
#include "Problema.h"
#include "Persona.h"
#include "../Biblioteca/grafo.h"
using namespace std;

int pruebas()
{
    if (((float)0 / 12) > 1.2)
        cout << (float)0 / 12;
    if (((float)2 / 12) > 1.2)
        cout << (float)2 / 12;
    if (((float)12 / 12) > 1.2)
        cout << (float)12 / 12;
    if (((float)15 / 12) > 1.2)
        cout << (float)15 / 12;
}
int main(int argc, char* argv[])
{
	string problema_de_entrada = "problema.pro";
    string solucion_de_salida = "";

    cout << "***************************************************************************" << endl;
	cout << "Simulador de redes de contactos sexuales " << SW_VERSION << endl;
    cout << "Autores: J. Villanueva-Oller, R. J. Villanueva y V. Sanchez" << endl;
    cout << "Departamento de Matematica Aplicada, Universidad Politecnica de Valencia" << endl;
    cout << "CES Felipe II, Universidad Complutense de Madrid" << endl;
    cout << "Direccion de contacto: jvillanueva@pdi.ucm.es, vicsana3@doctor.upv.es" << endl;
    cout << "***************************************************************************" << endl;

    if (argc == 2)
        problema_de_entrada = argv[1];

    if (argc == 3)

    {
        problema_de_entrada = argv[1];
        solucion_de_salida = argv[2];
    }

    if (argc == 2 &&
        (problema_de_entrada == "-boinc" || problema_de_entrada == "-BOINC"))
        {
            problema_de_entrada = "problema.pro";
            solucion_de_salida = "problema.sol";;
        }

    if (argc==1)
    {
       CArchivoTexto archivo;
       string buffer;
       string omision = "problema.pro";
       //Prueba repositorio
       if (archivo.AbreArchivoLectura(omision) == false)
         return -1; // archivo no encontrado

       archivo.LeeLinea(buffer);
       archivo.LeeLinea(buffer); // Leemos nombre del problema
       buffer+=".sol";
       solucion_de_salida = buffer;
       problema_de_entrada = omision;
    }

    CProblema problema;
    problema.Soluciona(problema_de_entrada, solucion_de_salida);


	return 0;
}

