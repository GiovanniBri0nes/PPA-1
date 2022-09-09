#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>
using namespace std;

fstream Archivo;

struct nodo_dA {
	char NombrAd[50], ContrAd[15];
	nodo_dA* siguienteAd;
	nodo_dA* anteriorAd;
}adm;
nodo_dA* raiz_dA = nullptr;
nodo_dA* aux_dA = nullptr;
struct nodo_dC {
	char NombrCA[50], ContrCA[15];
	nodo_dC* siguienteCA;
	nodo_dC* anteriorCA;
}caj;
nodo_dC* raiz_dC = nullptr;
nodo_dC* aux_dC = nullptr;
struct nodo_dCL {
	char NombrCL[30], AL[15],  EM[25];
	long long TEL;
	nodo_dCL* siguienteCL;
	nodo_dCL* anteriorCL;
}cli;
nodo_dCL* raiz_dCL = nullptr;
nodo_dCL* aux_dCL = nullptr;

void menuAd();
void agregar_ADM(char[], char[]);
void agregar_CAJ(char[], char[]);
void borrar_CAJ(char[], char[]);
void alta_Cliente(char[], char[],long long, char[]);
void baja_Cliente(char[], char[], long long , char[]);
void impr_clien();
void leer_archv_adm();
void abrir_archivoAd();

int main()
{
	setlocale(LC_CTYPE, "Spanish");
	char com[15], usu[15], contr[15], com2[15], usuA[15], contrA[15], com3[15], usu3[15], contr3[15];
	int resp = 0;
	cout << "***INICIAR SESION***" << endl;
	cout << "Comercio" << endl;
	cin.getline(com, 15, '\n');
	cout << "Nombre de usuario" << endl;
	cin.getline(usu, 15, '\n');
	cout << "Contraseña" << endl;
	cin.getline(contr, 15, '\n');
	cout << "***REGISTRO DE USUARIO ADMINISTRADOR***" << endl;
	cout << "Comercio" << endl;
	cin.getline(com2, 15, '\n');
	cout << "Usuario" << endl;
	cin.getline(usuA, 15, '\n');
	cout << "Contraseña" << endl;
	cin.getline(contrA, 15, '\n');
	cout << "***ADMINISTRADOR REGISTRADO CON ÉXTIO***" << endl;
	cout << "¿Es usted un administrador?" << endl;
	cout << "1-Si     2-No" << endl;
	cin >> resp;

	if (resp == 1)
	{
		while (getchar() != '\n');
		cout << "Comercio" << endl;
		cin.getline(com3, 15, '\n');
		cout << "Usuario" << endl;
		cin.getline(usu3, 15, '\n');
		cout << "Contraseña" << endl;
		cin.getline(contr3, 15, '\n');

		if (strcmp(com3, com2) == 0 && strcmp(usu3, usuA) == 0 && strcmp(contr3, contrA) == 0)
		{
			menuAd();
		}
		else
		{
			return main();
		}

	}

}

void menuAd()
{
	int decision = 0, op;
	do
	{
		cout << "***BIENVENIDO***" << endl;
		cout << "Ingrese 1 para Alta De Nuevo Administrador" << endl;
		cout << "Ingrese 2 para Alta De NUevo Cajero" << endl;
		cout << "Ingrese 3 para Baja De Usuario Tipo Cajero" << endl;
		cout << "Ingrese 4 para Actualizar Usuario" << endl;
		cout << "Ingrese 5 para Restablecer Contraseña" << endl;
		cout << "Ingrese 6 para ver el Listado de Usuarios" << endl;
		cout << "Ingrese 7 para Alta De Cliente " << endl;
		cout << "Ingrese 8 para Baja De Cliente " << endl;
		cout << "Ingrese 9 para Actualizar Clientes " << endl;
		cout << "Ingrese 10 para ver el Listado de Clientes " << endl;
		cout << "Ingrese 11 para Alta De Promoción " << endl;
		cout << "Ingrese 12 para Baja De Promoción " << endl;
		cout << "Ingrese 13 para ver el Listado de Promociones " << endl;
		cout << "Ingrese 14 para Alta De Consumo " << endl;
		cout << "Ingrese 15 para ver el Listado De Consumos " << endl;
		cout << "Ingrese 16 para limnpiar pantalla " << endl;
		cout << "Ingrese 17 para abrir binario de admin" << endl;
		cout << "Ingrese 18 para salir" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			do
			{
			while (getchar() != '\n');
			cout << "Ingrese usuario" << endl;
			cin.getline(adm.NombrAd, 50, '\n');
			cout << "Ingrese contraseña" << endl;
			cin.getline(adm.ContrAd, 15, '\n');
			cout << "¿Dese aregar otro administrador?" << endl;
			cout << "1-Si     2-No" << endl;
			cin >> decision;
			}while (decision == 1);
			agregar_ADM(adm.NombrAd, adm.ContrAd);
			return menuAd();
			break;
		case 2:
			do
			{
				while (getchar() != '\n');
				cout << "Ingrese cajero" << endl;
				cin.getline(caj.NombrCA, 50, '\n');
				cout << "Ingrese contraseña" << endl;
				cin.getline(caj.ContrCA, 15, '\n');
				cout << "¿Dese aregar otro cajero?" << endl;
				cout << "1-Si     2-No" << endl;
				cin >> decision;
			} while (decision == 1);
			agregar_CAJ(caj.NombrCA, caj.ContrCA);
			return menuAd();
			break;

		case 3:
			do {
				while (getchar() != '\n');
				cout << "Ingrese cajero a eliminar" << endl;
				cin.getline(caj.NombrCA, 50, '\n');
				cout << "Ingrese contraseña a eliminar" << endl;
				cin.getline(caj.ContrCA, 15, '\n');
				cout << "¿Dese eleminar otro cajero?" << endl;
				cout << "1-Si     2-No" << endl;
			} while (decision == 1);
			borrar_CAJ(caj.NombrCA, caj.ContrCA);
			return menuAd();
			break;

		case 4:
			return menuAd();
			break;

		case 5:
			return menuAd();
			break;

		case 6:
			return menuAd();

			break;
		case 7:
			do
			{
				while (getchar() != '\n');
			    cout << "Ingrese cliente" << endl;
				cin.getline(cli.NombrCL, 50, '\n');
				cout << "Ingrese alias" << endl;
				cin.getline(cli.AL, 15, '\n');
				cout << "Ingrese teléfono" << endl;
				cin >> cli.TEL;
				while (getchar() != '\n');
				cout << "Ingrese email" << endl;
				cin.getline(cli.EM, 25, '\n');
				cout << "¿Dese aregar otro cliente?" << endl;
				cout << "1-Si     2-No" << endl;
				cin >> decision;
			} while (decision == 1);
			alta_Cliente(cli.NombrCL, cli.AL, cli.TEL, cli.EM);
				return menuAd();
			break;

		case 8:
			do {
				while (getchar() != '\n');
				cout << "Ingrese cliente a eliminar" << endl;
				cin.getline(cli .NombrCL, 50, '\n');
				cout << "Ingrese alias a eliminar" << endl;
				cin.getline(cli.AL, 15, '\n');
				cout << "Ingrese teléfono a eliminar" << endl;
				cin >> cli.TEL;
				while (getchar() != '\n');
				cout << "Ingrese correo a eliminar" << endl;
				cin.getline(cli.EM, 25, '\n');
				cout << "¿Dese eleminar otro cajero?" << endl;
				cout << "1-Si     2-No" << endl;
			} while (decision == 1);
			return menuAd();
			break;

		case 9:
			return menuAd();
			break;

		case 10:
			impr_clien();
			return menuAd();
			break;

		case 11:
			return menuAd();
			break;

		case 12:
			return menuAd();
			break;
		case 13:
			return menuAd();
			break;

		case 14:
			return menuAd();
			break;

		case 15:
			return menuAd();
			break;

		case 16:
			system("cls");
			return menuAd();
			break;
		case 17:
			leer_archv_adm();
			abrir_archivoAd();
			break;
		case 18:
			
			break;
		default:
			cout << "Opcion incorrecta" << endl;

		}
	} while (decision == 1);

}
void agregar_ADM(char NA[50], char CA[15])
{

	if (raiz_dA == nullptr)
	{
		raiz_dA = new nodo_dA;
		raiz_dA->NombrAd[50] = NA[50];
		raiz_dA->ContrAd[15] = CA[15];
		raiz_dA->siguienteAd = nullptr;
		raiz_dA->anteriorAd = nullptr;
		aux_dA = raiz_dA;
	}
	else
	{
		aux_dA = raiz_dA;
		while (aux_dA->siguienteAd != nullptr)
		{
			aux_dA = aux_dA->siguienteAd;
		}
		aux_dA->siguienteAd = new nodo_dA;
		aux_dA->siguienteAd->siguienteAd = nullptr;
		aux_dA->siguienteAd->anteriorAd = aux_dA;
		aux_dA = aux_dA->siguienteAd;
		aux_dA->NombrAd[50] = NA[50];
		aux_dA->ContrAd[15] = CA[15];
	}
}
void agregar_CAJ(char NCA[50], char CCA[15])
{
	if (raiz_dC == nullptr)
	{
		raiz_dC = new nodo_dC;
		raiz_dC->NombrCA[50] = NCA[50];
		raiz_dC->ContrCA[15] = CCA[15];
		raiz_dC->siguienteCA = nullptr;
		raiz_dC->anteriorCA = nullptr;
		aux_dC = raiz_dC;
	}
	else
	{
		aux_dC = raiz_dC;
		while (aux_dC->siguienteCA != nullptr)
		{
			aux_dC = aux_dC->siguienteCA;
		}
		aux_dC->siguienteCA = new nodo_dC;
		aux_dC->siguienteCA->siguienteCA = nullptr;
		aux_dC = aux_dC->siguienteCA;
		aux_dC->NombrCA[45] = NCA[45];
		aux_dC->ContrCA[14] = CCA[14];
	}
	
}
void borrar_CAJ(char NCA[50], char CCA[15])
{
	//en caso de que la lista este vacia
	if (raiz_dC == nullptr)
	{
		return;
	}

	//Si el elemento a borrar es el primer nodo
	aux_dC = raiz_dC;
	if (aux_dC->NombrCA[45] == NCA[45] && aux_dC->ContrCA[15] == CCA[15])
	{
		raiz_dC = raiz_dC->siguienteCA;
		raiz_dC->anteriorCA = nullptr;
		delete aux_dC;
	}
	else
	{
		//Si el elemento a borrar es algun nodo de en medio
		while ((aux_dC != nullptr && aux_dC->NombrCA[45] != NCA[45]) && (aux_dC != nullptr && aux_dC->ContrCA[14] != CCA[14]))
		{
			aux_dC = aux_dC->siguienteCA;
		}

		if (aux_dC != nullptr)
		{
			if ((aux_dC->NombrCA[45] == NCA[45]) && (aux_dC->ContrCA[15] == CCA[15]))
			{

				nodo_dC* temporal = aux_dC;
				temporal->anteriorCA->siguienteCA = temporal->siguienteCA;
				if (temporal->siguienteCA != nullptr) //por si es el ultimo de la lista
				{
					temporal->siguienteCA->anteriorCA = temporal->anteriorCA;
				}
				delete temporal;
			}
		}

	}

}
void alta_Cliente(char NCL[30], char ALC[15], long long TLC, char EMC[25])
{
	if (raiz_dCL == nullptr)
	{
		raiz_dCL = new nodo_dCL;
		raiz_dCL->NombrCL[30] = NCL[30];
		raiz_dCL->AL[15] = ALC[15];
		raiz_dCL->TEL = TLC;
		raiz_dCL->EM[15] = EMC[15];
		raiz_dCL->siguienteCL = nullptr;
		raiz_dCL->anteriorCL = nullptr;
		aux_dCL = raiz_dCL;
	}
	else
	{
		aux_dCL = raiz_dCL;
		while (aux_dCL->siguienteCL != nullptr)
		{
			aux_dCL = aux_dCL->siguienteCL;
		}
		aux_dCL->siguienteCL = new nodo_dCL;
		aux_dCL->siguienteCL->siguienteCL = nullptr;
		aux_dCL = aux_dCL->siguienteCL;
		raiz_dCL->NombrCL[30] = NCL[30];
		aux_dCL->AL[15] = ALC[15];
		aux_dCL->TEL = TLC;
		raiz_dCL->EM[25] = EMC[25];
	}

}
void baja_Cliente(char NCL[30], char ALC[15], long long TLC, char EMC[25])
{
	//en caso de que la lista este vacia
	if (raiz_dCL == nullptr)
	{
		return;
	}

	//Si el elemento a borrar es el primer nodo
	aux_dCL = raiz_dCL;
	if (aux_dCL->NombrCL[30] == NCL[30] && aux_dCL->AL[15] == ALC[15] && aux_dCL->TEL == TLC && aux_dCL->EM[25] == EMC[25])
	{
		raiz_dCL = raiz_dCL->siguienteCL;
		raiz_dCL->anteriorCL = nullptr;
		delete aux_dCL;
	}
	else
	{
		//Si el elemento a borrar es algun nodo de en medio
		while ((aux_dCL != nullptr && aux_dCL->NombrCL[30] != NCL[30]) && (aux_dCL != nullptr && aux_dCL->AL[15] != ALC[15]) && (aux_dCL != nullptr && aux_dCL->TEL  != TLC) && (aux_dCL != nullptr && aux_dCL->EM[25] != EMC[25]))
		{
			aux_dCL = aux_dCL->siguienteCL;
		}

		if (aux_dCL != nullptr)
		{
			if ((aux_dCL->NombrCL[30] == NCL[30]) && (aux_dCL->AL[15] == ALC[15]) && (aux_dCL->TEL == TLC) && (aux_dCL->EM[25] == EMC[25]))
			{

				nodo_dCL* temporal = aux_dCL;
				temporal->anteriorCL->siguienteCL = temporal->siguienteCL;
				if (temporal->siguienteCL != nullptr) //por si es el ultimo de la lista
				{
					temporal->siguienteCL->anteriorCL = temporal->anteriorCL;
				}
				delete temporal;
			}
		}

	}
}
void impr_clien()
{
	aux_dCL = new nodo_dCL;
	aux_dCL= raiz_dCL;

	while (aux_dCL!= nullptr)
	{
		cout << aux_dCL->NombrCL <<endl;
		aux_dCL = aux_dCL->siguienteCL;
	
	}
}
void leer_archv_adm()
{
	nodo_dA* actual = new nodo_dA;
	actual->NombrAd[50];

	Archivo.open("Archivo.bin", ios::out | ios::binary);
	if (Archivo.is_open())
	{
		Archivo.write(reinterpret_cast<char*>(actual), sizeof(nodo_dA));
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Archivo.close();
}
void abrir_archivoAd()
{
	Archivo.open("Archivo.bin", ios::in | ios::binary);
	if (Archivo.is_open())
	{
		int size = Archivo.tellg();

		int i = 0;
		nodo_dA* Temp = new nodo_dA;
		Archivo.seekg(i * sizeof(nodo_dA));
		Archivo.read(reinterpret_cast<char*>(Temp), sizeof(nodo_dA));

		nodo_dA lista;
		lista.NombrAd[50] = Temp->NombrAd[50];
		delete Temp;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Archivo.close();
}