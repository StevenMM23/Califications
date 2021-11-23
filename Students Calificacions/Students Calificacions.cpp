// Hecho por:  
//		Steven Martínez - 1101817
//		Sebastián Henriquez - 1101507


#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
//Prototipos {Modelos limitados de una entidad mas completa que vendra posteriormente....}
float standard_desv(float cal[]);
float HigherCal(float cal[]);
vector<float> lowerCal(float cal[], float min);

int main()
{
	// Declara un arreglo tipo Float que trandra las calificaciones
	float cal[10];
	// Para i = 0 Hasta 10...
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter the " << i + 1 << " number: ";
		// El dato ingresado lo posicionara en posicion i del arreglo
		cin >> cal[i];
		// Limpia la consola
		system("cls");
	}
	// flotante que guardará lo retornado de la Funcion HigherCal
	float higherCal = HigherCal(cal);

	// flotante que guardará lo retornado de la Funcion standard_dev
	float standardDev = standard_desv(cal);

	// flotante que guardará el valor de 2 desviaciones estándar respecto a la calificación más alta
	float twoDeviation = higherCal - (standardDev * 2);

	//Arreglo que tendra las calificaciones finales
	float finalCal[10];

	// Vector que tendra las calificaciones menores a 2 desviaciones estandar
	vector<float> Lower = lowerCal(cal, twoDeviation);

	// Muestras las calificaciones ingresadas anteriormente
	cout << "Califications: [ "; for (float cal1 : cal) cout << cal1 << " "; cout << " ]\n";

	// Muestra la calificación mas alta
	cout << "Higher Calification = " << higherCal << endl;

	// Muestra la Deviacion Estandar 
	cout << "Standard Deviation = " << standardDev << endl;

	// Muestra cual es el valor de 2 Desviaciones estandar respecto a la calificacion mas alta
	cout << "Two Standard Deviation = " << twoDeviation << "\n\n";

	cout << "Those numbers that have Two standard Deviation are: ";

	// Muestra cuales son los numeros que estan 2 desviaciones estandar agregados en el vector Lower
	for (float lower : Lower)
		cout << lower << " ";

	// Agrega las calificaciones y aquellas menores a 2 desviaciones estandar se le suma 25
	for (int i = 0; i < 10; i++)
		if (cal[i] < twoDeviation)
			finalCal[i] = cal[i] + 25;
		else
			finalCal[i] = cal[i];



	cout << "\n\nPRESS ENTER TO SHOW THE NEW CURVE....\n";

	//Pausa la consola hasta presionar una tecla 
	system("Pause");

	// Muestra como queda la nueva curva con todas las calificaciones y la suma de los menores a 2 desviaciones
	for (auto final_cal : finalCal)
		cout << final_cal << " ";
}
// Funcion que me calcula la Desviacion Estandar...
float standard_desv(float cal[])
{
	//Declarando e Inicializando variables
	float sum = 0.0, standardDesv = 0.0;

	// Para i = 0 hasta que llegue a 10...
	for (int i = 0; i < 10; i++)
		sum += cal[i];

	// Calcula el promedio siendo la suma entre la cantidad de calificaciones
	float average = sum / 10;

	// Para i = 0 hasta que llegue a 10
	for (int i = 0; i < 10; i++)

		// Formula de la varianza (Sigma(calificacion - promedio)^2)
		standardDesv += pow(cal[i] - average, 2);

	//Formula de la desviacion estandar Poblacion (La raiz de la varianza entre la cantidad de elementos)
	return sqrt(standardDesv / 10);
}


// Funcion que determina la mayor de las calificaciones
float HigherCal(float cal[])
{
	// Se inicializa suponiendo que cal[0] es la mas alta
	float maxCal = cal[0];

	for (int i = 0; i < 10; i++)

		// Si maxCal es menor a Una de las calificaciones, si es verdad maxCal sera esa calificación, sino maxCal se quedara igual
		maxCal < cal[i] ? maxCal = cal[i] : maxCal;

	// Me retorna la calificacion mas alta
	return maxCal;
}

//Funcion que me retorna un Vector con las calificaciones menores a 2 desviaciones
vector<float> lowerCal(float cal[], float min)
{
	//Inicializo un vector numbers
	vector<float> numbers;

	//Bucle que recorrera todas las calificaciones...
	for (int i = 0; i < 10; i++)
	{
		// Si una calificacion es menor a 2 desviaciones estándar...
		if (cal[i] < min)

			// El vector numbers agrega esa calificacion
			numbers.push_back(cal[i]);
	}

	// Retorna el vector numbers (Calificaciones menores a 2 desviaciones)
	return numbers;
}
