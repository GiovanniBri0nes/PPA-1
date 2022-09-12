#include <iostream>
#include <string>
#include <string.h>
#include <locale.h>
#include <fstream>
using namespace std;

fstream Archivo;


struct nodo_dA {
	string NombrAd, ContrAd;
	nodo_dA* sigAd;
};
nodo_dA* raiz = nullptr;
nodo_dA* aux = nullptr;

struct nodo_dC {
	string NombrCA, ContrCA;
	nodo_dC* sigCA;
};
nodo_dC* raiz_CA = nullptr;
nodo_dC* aux_CA = nullptr;

struct nodo_dCL {
	string NombrCL, EM, Al;
	long long Tel;
	nodo_dCL* sigCL;
};
nodo_dCL* raiz_CL = nullptr;
nodo_dCL* aux_CL = nullptr;

struct nodo_PR {
	string NombrPR;
	float prc;
	int MPR;
	nodo_PR* sigPR;
};
nodo_PR* raiz_PR = nullptr;
nodo_PR* aux_PR = nullptr;

void agregar_adm(string, string);
void agregar_caj(string);
void baja_caj(string);
void agregar_cl(string,string, string, long long, string);
void baja_cl(string);
void agregar_prom(string, float, int);
void menu_Ad();
void list_cl();
void list_usu();
void leer_archv_adm();
void abrir_archivoAd();
void leer_archv_caj();
void abrir_archivoCaj();

int main()
{
	setlocale(LC_CTYPE, "Spanish");
	int resp = 0;

	char usu[50], contr[15], com[15], usu2[50], contr2[15], com2[15], usu3[50], contr3[15], com3[15];

	cout << "***INICIAR SESION***" << endl;
	cout << "Comercio" << endl;
	cin.getline(com, 15, '\n');
	cout << "Nombre de usuario" << endl;
	cin.getline(usu, 50, '\n');
	cout << "Contraseña" << endl;
	cin.getline(contr, 15, '\n');
	cout << "***REGISTRO DE USUARIO ADMINISTRADOR***" << endl;
	cout << "Comercio" << endl;
	cin.getline(com2, 15, '\n');
	cout << "Usuario" << endl;
	cin.getline(usu2, 50, '\n');
	cout << "Contraseña" << endl;
	cin.getline(contr2, 15, '\n');
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
		cin.getline(usu3, 50, '\n');
		cout << "Contraseña" << endl;
		cin.getline(contr3, 15, '\n');

		if (strcmp(com3, com2) == 0 && strcmp(usu3, usu2) == 0 && strcmp(contr3, contr2) == 0)
		{
			menu_Ad();
		}

	}
}
void agregar_adm(string NA, string CA)
{
	if (raiz == nullptr)
	{
		raiz = new nodo_dA;
		raiz->NombrAd = NA;
		raiz->ContrAd = CA;
		raiz->sigAd = nullptr;
		aux = raiz;
	}
	else
	{
		aux= raiz;
		while (aux->sigAd != nullptr)
		{
			aux = aux->sigAd;
		}
		aux->sigAd = new nodo_dA;
		aux->sigAd->sigAd = nullptr;
		aux = aux->sigAd;
		aux->NombrAd = NA;
		aux->ContrAd = CA;
	}
}
void agregar_caj(string NC, string CCJ)
{
	if (raiz_CA == nullptr)
	{
		raiz_CA = new nodo_dC;
		raiz_CA->NombrCA = NC;
		raiz_CA->ContrCA = CCJ;
		raiz_CA->sigCA = nullptr;
		aux_CA = raiz_CA;
	}
	else
	{
		aux_CA = raiz_CA;
		while (aux_CA->sigCA != nullptr)
		{
			aux_CA = aux_CA->sigCA;
		}
		aux_CA->sigCA = new nodo_dC;
		aux_CA->sigCA->sigCA = nullptr;
		aux_CA = aux_CA->sigCA;
		aux_CA->NombrCA = NC;
		aux_CA->ContrCA= CCJ;
	}
}
void agregar_cl(string NCL, string EMCL, long long TLC, string ALI)
{
	if (raiz_CL == nullptr)
	{
		raiz_CL = new nodo_dCL;
		raiz_CL ->NombrCL = NCL;
		raiz_CL->Tel = TLC;
		raiz_CL->EM = EMCL;
		raiz_CL->Al = ALI;
		raiz_CL->sigCL= nullptr;
		aux_CL = raiz_CL;
	}
	else
	{
		aux_CL = raiz_CL;
		while (aux_CL->sigCL != nullptr)
		{
			aux_CL = aux_CL->sigCL;
		}
		aux_CL->sigCL= new nodo_dCL;
		aux_CL->sigCL->sigCL = nullptr;
		aux_CL = aux_CL->sigCL;
		aux_CL->NombrCL = NCL;
		aux_CL->Tel = TLC;
		aux_CL->EM = EMCL;
		aux_CL->Al = ALI;
	}
}
void agregar_prom(string NPR, float PR, int MTPR)
{
	if (raiz_PR == nullptr)
	{
		raiz_PR = new nodo_PR;
		raiz_PR->NombrPR = NPR;
		raiz_PR->prc = PR;
		raiz_PR->MPR = MTPR;
		raiz_PR->sigPR = nullptr;
		aux_PR = raiz_PR;
	}
	else
	{
		aux_PR = raiz_PR;
		while (aux_PR->sigPR != nullptr)
		{
			aux_PR = aux_PR->sigPR;
		}
		aux_PR->sigPR = new nodo_PR;
		aux_PR->sigPR->sigPR = nullptr;
		aux_PR = aux_PR->sigPR;
		aux_PR->NombrPR = NPR;
		aux_PR->prc = PR;
		aux_PR->MPR = MTPR;

	}
}
void baja_caj(string NC)
{
	if (raiz_CA == nullptr)
	{
		return;
	}
	
	aux_CA = raiz_CA;
	if (aux_CA->NombrCA == NC)
	{
		raiz_CA = raiz_CA->sigCA;
		delete aux_CA;
	}
	else
	{
		while (aux_CA->sigCA != nullptr && aux_CA->sigCA->NombrCA != NC)
		{
			aux_CA = aux_CA->sigCA;
		}

		if (aux_CA->sigCA != nullptr && aux_CA->sigCA->NombrCA == NC)
		{
			nodo_dC* temporal = aux_CA->sigCA;
			aux_CA->sigCA = aux_CA->sigCA->sigCA;
			delete temporal;
		}
	}


}
void baja_cl(string NCL)
{
	if (raiz_CL == nullptr)
	{
		return;
	}

	aux_CL = raiz_CL;
	if (aux_CL->NombrCL == NCL)
	{
		raiz_CL = raiz_CL->sigCL;
		delete aux_CL;
	}
	else
	{
		while (aux_CL->sigCL != nullptr && aux_CL->sigCL->NombrCL != NCL)
		{
			aux_CL = aux_CL->sigCL;
		}

		if (aux_CL->sigCL != nullptr && aux_CL->sigCL->NombrCL == NCL)
		{
			nodo_dCL* temporal = aux_CL->sigCL;
			aux_CL->sigCL = aux_CL->sigCL->sigCL;
			delete temporal;
		}
	}
}
void menu_Ad()
{
	string NombrAd, ContrAd, NombrCA, ContrCA, NombrCL, EM, Al, NombrPR;
	int decision = 0, op, MPR;
	float prc;
	long long Tel;
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
		cout << "Ingrese 17 para archivo binario" << endl;
		cout << "Ingrese 18 para salir" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			do
			{
				while (getchar() != '\n');
				cout << "Ingrese nombre de usuario" << endl;
				getline(cin, NombrAd);
				cout << "Ingrese contraseña" << endl;
				getline(cin, ContrAd);
				agregar_adm(NombrAd, ContrAd);
				cout << "¿Desea agregar otro administrador?" << endl;
				cout << "1-Si     2-No" << endl;
				cin >> decision;
				while (getchar() != '\n');
			} while (decision == 1);
			return menu_Ad();
			break;
		case 2:
			do
			{
				while (getchar() != '\n');
				cout << "Ingrese nombre de cajero" << endl;
				getline(cin, NombrCA);
				cout << "Ingrese contraseña" << endl;
				getline(cin, ContrCA);
				agregar_caj(NombrCA, ContrCA);
				cout << "¿Desea agregar otro cajero?" << endl;
				cout << "1-Si     2-No" << endl;
				cin >> decision;
				
			
			} while (decision == 1);
		
			return menu_Ad();
			break;

		case 3:

			do 
			{
		    	while (getchar() != '\n');
				cout << "Ingrese cajero a eliminar" << endl;
				getline(cin, NombrCA);
				baja_caj(NombrCA);
				cout << "¿Dese eliminar otro cajero?" << endl;
				cout << "1-Si     2-No" << endl;
				cin >> decision;
		
			} while (decision == 1);
			
			return menu_Ad();
			break;

		case 4:
			return menu_Ad();
			break;

		case 5:
			return menu_Ad();
			break;

		case 6:
			list_usu();
			return menu_Ad();

			break;
		case 7:
			do
			{
				while (getchar() != '\n');
				cout << "Ingrese nombre de cliente" << endl;
				getline(cin, NombrCL);
				cout << "Ingrese alias" << endl;
				getline(cin, Al);
				cout << "Ingrese numero de telefono" << endl;
				cin >> Tel;
				while (getchar() != '\n');
				cout << "Ingrese email" << endl;
				getline(cin, EM);
				agregar_cl(NombrCL, EM, Tel, Al);
				cout << "¿Desea agregar otro cliente?" << endl;
				cout << "1-Si     2-No" << endl;
				cin >> decision;
	
			} while (decision == 1);
			
			return menu_Ad();
			break;

		case 8:
			do {
				while (getchar() != '\n');
				cout << "Ingrese nombre de cliente a eliminar" << endl;
				getline(cin, NombrCL);
				baja_cl(NombrCL);
				cout << "¿Desea eliminar otro cliente?" << endl;
				cout << "1-Si     2-No" << endl;
				cin >> decision;
			} while (decision == 1);
			return menu_Ad();
			break;

		case 9:
			return menu_Ad();
			break;

		case 10:
			list_cl();
			return menu_Ad();
			break;

		case 11:
		   do{
			   while (getchar() != '\n');
			   cout << "Ingrese nombre de la promocion" << endl;
			   getline(cin, NombrPR);
			   do {
				   cout << "Ingrese el monto de las promociones" << endl;
				   cin >> MPR;
			   } while (MPR < 100);
			   cout << "Ingrese el porcentaje del descuento" << endl;
			   cin >> prc;
			   agregar_prom(NombrPR,prc,MPR);
			   cout << "¿Desea agregar otra promocion?" << endl;
			   cout << "1-Si     2-No" << endl;
			   cin >> decision;
		   } while (decision == 1);
			return menu_Ad();
			break;

		case 12:
			return menu_Ad();
			break;
		case 13:
			return menu_Ad();
			break;

		case 14:
			return menu_Ad();
			break;

		case 15:
			return menu_Ad();
			break;

		case 16:
			system("cls");
			return menu_Ad();
			break;
		case 17:
			 leer_archv_adm();
			 abrir_archivoAd();
			 leer_archv_caj();
			 abrir_archivoCaj();
			return menu_Ad();
			break;
		case 18:

			break;
		default:
			cout << "Opcion incorrecta" << endl;

		}
	} while (decision == 1);

}
void list_cl()
{
	aux_CL = raiz_CL;
	if (aux_CL != nullptr)
	{ 
		cout << "********CLIENTES*******" << endl;
		while (aux_CL != nullptr)
		{
			cout << aux_CL->NombrCL << endl;
			aux_CL = aux_CL->sigCL;
		}
	}
}
void list_usu()
{
	aux = raiz;
	if (aux != nullptr)
	{
		cout << "**********ADMINS****************" << endl;
		while (aux != nullptr)
		{

			cout << aux->NombrAd << endl;
			aux = aux->sigAd;
		}
	}
	aux_CA = raiz_CA;
	if (aux_CA != nullptr)
	{
		cout << "**********CAJEROS****************" << endl;
		while (aux_CA != nullptr)
		{

			cout << aux_CA->NombrCA << endl;
			aux_CA = aux_CA->sigCA;
		}
	}

}
void leer_archv_adm()
{
	nodo_dA* actual = new nodo_dA;
	actual->NombrAd;

	Archivo.open("Admin.bin", ios::out | ios::binary);
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
	Archivo.open("Admin.bin", ios::in | ios::binary);
	if (Archivo.is_open())
	{
		int size = Archivo.tellg();

		int i = 0;
		nodo_dA* Temp = new nodo_dA;
		Archivo.seekg(i * sizeof(nodo_dA));
		Archivo.read(reinterpret_cast<char*>(Temp), sizeof(nodo_dA));

		nodo_dA lista;
		lista.NombrAd = Temp->NombrAd;
		delete Temp;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Archivo.close();
}
void leer_archv_caj()
{
	nodo_dC* actual = new nodo_dC;
	actual->NombrCA;

	Archivo.open("Cajeros.bin", ios::out | ios::binary);
	if (Archivo.is_open())
	{
		Archivo.write(reinterpret_cast<char*>(actual), sizeof(nodo_dC));
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Archivo.close();

}
void abrir_archivoCaj()
{
	Archivo.open("Cajeros.bin", ios::in | ios::binary);
	if (Archivo.is_open())
	{
		int size = Archivo.tellg();

		int i = 0;
		nodo_dC* Temp = new nodo_dC;
		Archivo.seekg(i * sizeof(nodo_dC));
		Archivo.read(reinterpret_cast<char*>(Temp), sizeof(nodo_dC));

		nodo_dA lista;
		lista.NombrAd = Temp->NombrCA;
		delete Temp;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Archivo.close();


}
