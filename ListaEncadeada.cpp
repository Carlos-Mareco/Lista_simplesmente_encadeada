#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>

using std::cout;
using std::cin;
using std::endl;

typedef struct no
{
	int valor;
	struct no* proximo;
}no;

int menu(int itens);
int inserirInicio(no** lista, int itens);
int inserirPos(no** lista, int itens);
void listar(no* lista);
void alterar(no** lista, int itens);
int excluir(no** lista, int itens);

int main()
{
	setlocale(LC_ALL, "UTF-8");

	no* lista = NULL;
	int itens = 0;
	bool sair = false;
	
	while (sair != true)
	{
		switch (menu(itens))
		{
		case 1:
			//inserir
			itens = inserirInicio(&lista, itens);
			system("cls");
			break;
		case 2:
			//inserir por posição
			itens = inserirPos(&lista, itens);
			system("cls");
			break;
		case 3:
			//listar itens
			listar(lista);
			system("pause");
			system("cls");
			break;
		case 4:
			//alterar valor
			alterar(&lista, itens);
			system("cls");
			break;
		case 5:
			//excluir
			if (lista != NULL)
				listar(lista);
			itens = excluir(&lista, itens);
			system("cls");
			break;
		case 6:
			//limpar lista
			lista = NULL;
			itens = 0;
			system("pause");
			system("cls");
			break;
		case 7:
			//sair
			sair = true;
			break;
		default:
			break;
		}
	}
	return 0;
}

int menu(int itens)
{
	int opcao;
	cout << "****LISTA SIMPLESMENTE ENCADEADA****" << endl;
	cout << "1 - Inserir" << endl;
	cout << "2 - Inserir por posição" << endl;
	cout << "3 - Listar itens ("<< itens << ")" << endl;
	cout << "4 - Alterar valor" << endl;
	cout << "5 - Excluir" << endl;
	cout << "6 - Limpar lista" << endl;
	cout << "7 - Sair" << endl;
	cout << "Escolher: ";
	cin >> opcao;
	return opcao;
}

int inserirInicio(no** lista, int itens)
{
	int num;
	no* novo;

	cout << "Entre com um número inteiro: ";
	cin >> num;

	novo = (no*) new no;
	novo->valor = num;
	novo->proximo = *lista;
	*lista = novo;
	itens++;
	return itens;
}

int inserirPos(no** lista, int itens)
{
	int num, pos;
	no* aux = *lista;
	no* novo;

	cout << "Entre com um número inteiro: ";
	cin >> num;
	cout << "Entre com uma posição: ";
	cin >> pos;

	if (pos == 1)
	{
		itens = inserirInicio(&aux, itens);
		return itens;
	}
	else
	{
		if (pos > 1 && pos <= itens+1)
		{
			for (int i = 2; i < pos; i++)
			{
				aux = aux->proximo;
			}
			novo = (no*) new no;
			novo->valor = num;
			novo->proximo = aux->proximo;
			aux->proximo = novo;
			itens++;
			return itens;
		}
		else
		{
			cout << "Posição inválida!" << endl;
			system("pause");
			itens;
			return itens;
		}
	}
}
void listar(no* lista)
{
	no* aux = lista;
	int contador = 0;

	if (lista == NULL)
	{
		cout << "Lista vazia!" << endl;
	}
	else
	{
		while (aux != NULL)
		{
			cout << contador+1 << "ª :" <<aux->valor << endl;
			aux = aux->proximo;
			contador++;
		}
	}
}

void alterar(no** lista, int itens)
{
	int num, pos;
	no* aux = *lista;

	cout << "Entre com um número inteiro: ";
	cin >> num;
	cout << "Entre com uma posição: ";
	cin >> pos;

	if (pos >= 1 && pos <= itens)
	{
		for (int i = 1; i < pos; i++)
		{
			aux = aux->proximo;
		}
		aux->valor = num;
	}
	else
	{
		cout << "Posição inválida!" << endl;
	}
}

int excluir(no** lista, int itens)
{
	int pos;
	no* aux = *lista;
	no* delNo;

	cout << "Entre com uma posição: ";
	cin >> pos;

	if (pos > 1 && pos != 0 && pos <= itens)
	{
		for (int i = 2; i < pos; i++)
		{
			aux = aux->proximo;
		}
		delNo = aux->proximo;
		aux->proximo = delNo->proximo;
		itens--;
		return itens;
	}
	else
	{
		if (pos == 1 && pos != 0 && pos <= itens)
		{
			*lista = aux->proximo;
			itens--;
			return itens;
		}
		else
		{
			cout << "Posição inválida!" << endl;
			return itens;
		}
	}
}