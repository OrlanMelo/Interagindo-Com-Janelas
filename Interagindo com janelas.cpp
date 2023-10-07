#include <Windows.h>
#include <ShlObj_core.h>
#include <string>
#include <iostream>
#include <fstream>
#pragma comment(lib,"ole32.lib")

using namespace std;

class cFuncoes
{
private:

	IShellDispatch* Janelas = 0;

public:

	void InicializarInstancia()
	{
		CoInitializeEx(0, COINIT_MULTITHREADED);
		CoCreateInstance(CLSID_Shell, 0, CLSCTX_ALL, IID_IShellDispatch, (void**)&Janelas);
	}

	void MinimizarJanelas()
	{
		HRESULT Res;
		Res = Janelas->MinimizeAll();
	}

	void RestaurarJanelasMinimizadas()
	{
		Janelas->UndoMinimizeALL();
	}

	void JanelasEmCascata()
	{
		Janelas->CascadeWindows();
	}

	void AbrirJanelaExecutar()
	{
		Janelas->FileRun();
	}

}Funcoes;

int main()
{
	cout << "O assistente está se interagindo com janelas...";

	Funcoes.InicializarInstancia();
	Funcoes.MinimizarJanelas();
	Funcoes.RestaurarJanelasMinimizadas();
	Funcoes.JanelasEmCascata();
	Funcoes.AbrirJanelaExecutar();

	CoUninitialize();

	system("pause");
}