// Hecho por:  
//		Steven Martínez - 1101817
//		Sebastián Henriquez - 1101507

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//Prototipos {Modelos limitados de una entidad mas completa que vendra posteriormente....}
float standard_desv(vector<float> cal);
float HigherCal(vector<float> cal);
vector<vector<float>> lowerCal(vector<float> cal, float min);


int main()
{
	// Declara un vector tipo Float que trandra las calificaciones
	vector<float> cal;

	// x es donde se alojara las calificaciones
	float x = 0;
	//Para i = 0 hasta que i sea menor que 10.... 
	for (int i = 0; i < 10; i++)
	{
			//	Output que le dice al usuario que debe introducir
			cout << "Enter the " << i + 1 << " Calificacion: ";
			// x es donde va a alojar el dato
			cin >> x;

			//Valida el valor introducido en x por si es negativo
			if (x < 0) { cout << "\nNo se permiten valores menores a 0"; return 0; }

			// cal agrega el valor de x al index cal[i] que le corresponde 
			cal.push_back(x);
			// El sistema procede a limpiar la consola
			system("cls");
		
	}

	// Constante flotante que guardará lo retornado de la Funcion HigherCal
	const float higher_cal = HigherCal(cal);

	// Constante flotante que guardará lo retornado de la Funcion standard_dev
	const float standard_dev = standard_desv(cal);

	// Constante flotante que guardará el valor de 2 desviaciones estándar respecto a la calificación más alta
	const float two_deviation = standard_dev * 2;

	/* Vector 2D de tipo float que guarda las calificaciones que se le debe aplicar la desviación
	Y tambien, guarda las calificaciones con la suma de 25 si esta a 2 desviaciones estándar */
	const vector<vector<float>> Lower = lowerCal(cal, two_deviation); 


	// Muestra las calificaciones que insertamos anteriormente
	cout << "Califications: [ "; for (float cal1 : cal) cout << cal1 << " "; cout << " ]\n";

	// Muestra la calificación mas alta
	cout << "Higher Calification = " << higher_cal << endl;

	// Muestra la Deviacion Estandar 
	cout << "Standard Deviation = " << standard_dev << endl;

	// Muestra cual es el valor de 2 Desviaciones estandar respecto a la calificacion mas alta
	cout << "Two Standard Deviation = " << two_deviation << "\n\n";

	// Muestra cuales son los numeros que estan 2 desviaciones estandar
	cout << "Those numbers that have Two standard Deviations are: ";

	// Para los valores lower del Vector Lower[0]....
	for (auto lower : Lower[0])

		//Muestra los valores del primer vector (Vector low)
		cout << lower << " ";

	cout << "\n\nPRESS ENTER TO SHOW THE NEW CURVE....\n";

	// Pausar la consola hasta que se presione una tecla
	system("Pause");

	// Para los "final" del Vector Lower[1]....
	for (auto final : Lower[1])
		//Muestra los valores que estan en el segundo vector (Final_cal)
		cout << final << " ";
}

// Funcion que me calcula la Desviacion Estandar...
float standard_desv(vector<float> cal)
{
	//Declarando e Inicializando variables
	float sum = 0.0, standard_desv = 0.0;

	// Para i = 0 hasta que llegue a 10...
	for (int i = 0; i < 10; i++)

		// Suma todas las calificaciones y lo guarda en la variable sum
		sum += cal[i];

	// Calcula el promedio siendo la suma entre la cantidad de calificaciones
	const float average = sum / 10;

	// Para i = 0 hasta que llegue a 10
	for (int i = 0; i < 10; i++)

		// Formula de la varianza (Sigma(calificacion - promedio)^2)
		standard_desv += pow(cal[i] - average, 2);

	//Formula de la desviacion estandar Poblacion (La raiz de la varianza entre la cantidad de elementos)
	return sqrt(standard_desv / 10);
}

// Funcion que determina la mayor de las calificaciones
float HigherCal(vector<float> cal)
{
	// Se inicializa suponiendo que cal[0] es la mas alta
	float maxCal = cal[0];

	// Recorre todas las calificaciones
	for (int i = 1; i < 10; i++)

		// Si maxCal es menor a Una de las calificaciones, si es verdad maxCal sera esa calificación, sino maxCal se quedara igual
		maxCal < cal[i] ? maxCal = cal[i] : maxCal;

	return maxCal; // Me retorna la calificacion mas alta
}

//Funcion que me retorna un Vector 2D
vector<vector<float>> lowerCal(vector<float> cal, float min)
{
	//Declaro un vector de vectores de tipo float llamado number
	vector<vector<float>> numbers;

	// El vector low guardara aquellos que estan por debajo del 2 desviaciones estandar
	vector<float> low;

	// El vectir final_cal guardara todos los numeros y aquellos que estan por debajo se le sumara 25
	vector<float> final_cal;

	// Para i = 0 hasta 10 (Longitud del vector)
	for (int i = 0; i < 10; i++)
	{
		// Si una calificacion es menor a 2 desviaciones estándar...
		if (cal[i] < min)
		{
			// El vector low agrega esa calificación
			low.push_back(cal[i]);

			// El vector final_cal lo agrega sumandole 25 al valor
			final_cal.push_back(cal[i] + 25);
		}
		// Sino...
		else
			// final_cal agrega el valor al vector final 
			final_cal.push_back(cal[i]);

	}
	// El vector de vectores (Vector 2D) agregar ambos vectores
	numbers.push_back(low);
	numbers.push_back(final_cal);

	return numbers; // Retorna el vector 2D
}
