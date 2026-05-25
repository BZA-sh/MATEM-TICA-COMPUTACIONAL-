En Python
def detectar_taquicardia(fc):

    contador = 0
    inicio = -1

    for i in range(len(fc)):

        if fc[i] > 100:

            if contador == 0:
                inicio = i

            contador += 1

            if contador > 5:
                return True, inicio, i

        else:
            contador = 0

    return False, -1, -1


def detectar_fatiga(fc):

    primeros_10 = fc[:10]
    ultimos_10 = fc[-10:]

    promedio_inicio = sum(primeros_10) / 10
    promedio_final = sum(ultimos_10) / 10

    if promedio_final > promedio_inicio * 1.20:
        return True, promedio_inicio, promedio_final

    return False, promedio_inicio, promedio_final


def evaluar_paciente(nombre, fc):

    print("\n================================")
    print("Paciente:", nombre)
    print("================================")

    taq, inicio, fin = detectar_taquicardia(fc)

    if taq:
        print("\nTaquicardia Sostenida")
        print(f"Desde minuto {inicio + 1} hasta minuto {fin + 1}")
    else:
        print("\nSin Taquicardia")

    fatiga, prom_inicio, prom_final = detectar_fatiga(fc)

    print("\nPromedio primeros 10 min:",
          round(prom_inicio, 2))

    print("Promedio últimos 10 min:",
          round(prom_final, 2))

    if fatiga:
        print("\nFatiga por Esfuerzo")
    else:
        print("\nSin Fatiga")


pacientes = {

    "Hulk Banner": [
        100,82,85,80,85,88,84,83,81,83,
        95,108,110,95,112,111,105,90,108,117,
        85,84,83,82,81,80,79,78,77,76,
        75,76,108,110,112,105,108,110,101,102,
        93,94,95,96,97,98,99,100,101,102,
        105,99,100,105,90,91,105,109,99,110
    ],

    "Tony Iron": [
        80,82,85,80,85,88,84,83,81,80,
        105,88,110,95,92,111,95,110,98,117,
        84,85,93,92,91,80,78,79,87,86,
        86,85,88,90,88,86,85,92,91,90,
        93,94,95,96,97,88,89,90,91,101,
        105,108,90,95,102,111,95,90,88,110
    ],

    "Steve América": [
        85,98,90,95,102,101,105,90,88,110,
        95,88,90,95,92,101,102,110,103,101,
        104,105,93,92,91,80,78,79,87,86,
        86,85,88,90,88,86,85,92,91,90,
        93,94,95,96,97,88,89,90,91,101,
        81,82,83,80,85,90,84,80,81,80
    ],

    "Bruce Batman": [
        105,108,90,105,112,111,105,90,108,117,
        95,98,90,95,92,111,95,90,88,110,
        85,84,83,82,81,80,79,78,77,76,
        75,76,78,80,82,85,88,90,91,92,
        93,94,95,96,97,98,99,100,101,102,
        75,76,78,80,82,85,88,90,91,92
    ]
}


while True:

    print("\n==============================")
    print("DETECTOR CARDIACO")
    print("==============================")

    print("\nPacientes disponibles:")

    for nombre in pacientes:
        print("-", nombre)

    opcion = input("\nIngrese paciente o salir: ")

    if opcion.lower() == "salir":
        print("\nPrograma finalizado")
        break

    if opcion in pacientes:
        evaluar_paciente(opcion, pacientes[opcion])
    else:
        print("\nPaciente no encontrado")

En C++

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool detectarTaquicardia(vector<int> fc,
                         int &inicio,
                         int &fin)
{
    int contador = 0;

    for (int i = 0; i < fc.size(); i++)
    {
        if (fc[i] > 100)
        {
            if (contador == 0)
            {
                inicio = i;
            }

            contador++;

            if (contador > 5)
            {
                fin = i;
                return true;
            }
        }
        else
        {
            contador = 0;
        }
    }

    return false;
}

bool detectarFatiga(vector<int> fc,
                    double &promedioInicio,
                    double &promedioFinal)
{
    promedioInicio = 0;
    promedioFinal = 0;

    for (int i = 0; i < 10; i++)
    {
        promedioInicio += fc[i];
    }

    for (int i = 50; i < 60; i++)
    {
        promedioFinal += fc[i];
    }

    promedioInicio /= 10;
    promedioFinal /= 10;

    if (promedioFinal > promedioInicio * 1.20)
    {
        return true;
    }

    return false;
}

void evaluarPaciente(string nombre,
                     vector<int> fc)
{
    cout << "\n==============================";
    cout << "\nPaciente: " << nombre;
    cout << "\n==============================\n";

    int inicio = -1;
    int fin = -1;

    bool taquicardia =
        detectarTaquicardia(fc, inicio, fin);

    if (taquicardia)
    {
        cout << "\nTaquicardia Sostenida\n";

        cout << "Desde minuto "
             << inicio + 1
             << " hasta minuto "
             << fin + 1 << endl;
    }
    else
    {
        cout << "\nSin Taquicardia\n";
    }

    double promInicio;
    double promFinal;

    bool fatiga =
        detectarFatiga(fc, promInicio, promFinal);

    cout << "\nPromedio primeros 10 min: "
         << promInicio << endl;

    cout << "Promedio ultimos 10 min: "
         << promFinal << endl;

    if (fatiga)
    {
        cout << "\nFatiga por Esfuerzo\n";
    }
    else
    {
        cout << "\nSin Fatiga\n";
    }
}

int main()
{
    map<string, vector<int>> pacientes;

    pacientes["Hulk Banner"] = {
        100,82,85,80,85,88,84,83,81,83,
        95,108,110,95,112,111,105,90,108,117,
        85,84,83,82,81,80,79,78,77,76,
        75,76,108,110,112,105,108,110,101,102,
        93,94,95,96,97,98,99,100,101,102,
        105,99,100,105,90,91,105,109,99,110
    };

    pacientes["Tony Iron"] = {
        80,82,85,80,85,88,84,83,81,80,
        105,88,110,95,92,111,95,110,98,117,
        84,85,93,92,91,80,78,79,87,86,
        86,85,88,90,88,86,85,92,91,90,
        93,94,95,96,97,88,89,90,91,101,
        105,108,90,95,102,111,95,90,88,110
    };

    pacientes["Steve América"] = {
        85,98,90,95,102,101,105,90,88,110,
        95,88,90,95,92,101,102,110,103,101,
        104,105,93,92,91,80,78,79,87,86,
        86,85,88,90,88,86,85,92,91,90,
        93,94,95,96,97,88,89,90,91,101,
        81,82,83,80,85,90,84,80,81,80
    };

    pacientes["Bruce Batman"] = {
        105,108,90,105,112,111,105,90,108,117,
        95,98,90,95,92,111,95,90,88,110,
        85,84,83,82,81,80,79,78,77,76,
        75,76,78,80,82,85,88,90,91,92,
        93,94,95,96,97,98,99,100,101,102,
        75,76,78,80,82,85,88,90,91,92
    };

    string opcion;

    while (true)
    {
        cout << "\n==============================";
        cout << "\nDETECTOR CARDIACO";
        cout << "\n==============================\n";

        cout << "\nPacientes disponibles:\n";

        for (auto paciente : pacientes)
        {
            cout << "- " << paciente.first << endl;
        }

        cout << "\nIngrese paciente o salir: ";

        getline(cin, opcion);

        if (opcion == "salir")
        {
            cout << "\nPrograma finalizado\n";
            break;
        }

        if (pacientes.find(opcion) != pacientes.end())
        {
            evaluarPaciente(opcion,
                             pacientes[opcion]);
        }
        else
        {
            cout << "\nPaciente no encontrado\n";
        }
    }

    return 0;
}