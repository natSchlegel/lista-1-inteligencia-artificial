#include <iostream>
#include <cstdlib>
#include <string>
#include <locale.h>
#include <stack>
#include <queue>

using namespace std;

class Tarefas
{
public:
    string descricao;
    int prioridade;
};

struct CompararPrioridade
{
    bool operator()(Tarefas const& aux, Tarefas const& auxi)
    {
        return aux.prioridade < auxi.prioridade;
    }
};

void OlaMundo();
void Vetor();
void Matriz();
void Pilha();
void Fila();
void Tarefa();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    cout << "Voc� deseja chamar qual exerc�cio?" << endl;
    cout << "" << endl;
    cout << "1. Fa�a um programa que escreva �Ol� mundo�." << endl;
    cout << "2. Fa�a um programa que leia 10 n�meros e os armazene em um vetor. Imprima o vetor." << endl;
    cout << "3. Fa�a um programa que leia e preencha uma matriz de 10x10. No final, imprima a matriz." << endl;
    cout << "4. Fa�a um programa que leia 10 n�meros, insira em uma pilha. O programa deve remover os dados da pilha e imprimi-los na tela." << endl;
    cout << "5. Fa�a um programa que leia 10 n�meros, insira em uma fila. O programa deve remover os dados da fila e imprimi-los na tela." << endl;
    cout << "6. Fa�a um programa que leia 10 tarefas. Cada tarefa cont�m uma descri��o (string) e uma prioridade (inteiro de 0 a 5. Utilizar classe ou estrutura para representar a tarefa). As tarefas devem ser inseridas em uma fila de prioridade. O programa deve imprimir as tarefas na tela de acordo com a sua prioridade." << endl;

    cout << "Digite o n�mero: ";
    int aux;
    cin >> aux;
    switch (aux)
    {
    case 1:
        cout << "" << endl;
        OlaMundo();
        break;
    case 2:
        cout << "" << endl;
        Vetor();
        break;
    case 3:
        cout << "" << endl;
        Matriz();
        break;
    case 4:
        cout << "" << endl;
        Pilha();
        break;
    case 5:
        cout << "" << endl;
        Fila();
        break;
    case 6:
        cout << "" << endl;
        Tarefa();
        break;
    }
    return 0;
}
void OlaMundo()
{
    cout << "Ol� mundo" << endl;
}
void Vetor()
{

    int aux[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Digite o " << i + 1 << "� n�mero:" << endl;
        cin >> aux[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << aux[i] << " | ";
    }
}
void Matriz()
{
    int matriz[10][10];
    int c, l;
    for (l = 0; l < 10; l++)
    {
        for (c = 0; c < 10; c++)
        {
            int aux;
            // cout << "Digite o n�mero da " << l + 1 << "� linha e " << c + 1 << "� coluna: ";
            // cin >> aux;
            aux = rand() % 90 + 10;
            matriz[l][c] = aux;
        }
    }
    for (l = 0; l < 10; l++)
    {
        for (c = 0; c < 10; c++)
        {

            cout << matriz[l][c] << " | ";
        }
        cout << "" << endl;

    }
}
void Pilha()
{
    stack < int > pilha;
    int aux;
    for (int i = 0; i < 10; i++)
    {
        cout << "Digite o " << i + 1 << "� n�mero: ";
        cin >> aux;
        pilha.push(aux);
    }
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {

        cout << pilha.top() << " | ";
        pilha.pop();
    }
}
void Fila()
{

    queue < int > fila;
    int aux;
    for (int i = 0; i < 10; i++)
    {
        cout << "Digite o " << i + 1 << "� n�mero: ";
        cin >> aux;
        fila.push(aux);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << fila.front() << " | ";
        fila.pop();
    }
}
void Tarefa()
{
    string aux;
    int auxi;


    Tarefas tarefa[5];
    priority_queue <Tarefas, vector<Tarefas>, CompararPrioridade> fila;
    for (int i=0; i<5; i++)
    {
        cout<< "Digite a descri��o da tarefa:";
        cin.ignore();
        getline(cin, aux);
        tarefa[i].descricao = aux;
        cout<< "Digite o grau de prioridade da tarefa (0 a 5):";
        cin>>auxi;
        cout<<" " <<endl;
        tarefa[i].prioridade = auxi;
        fila.push(tarefa[i]);
    }

    while (!fila.empty())
    {
        Tarefas t = fila.top();
        fila.pop();
        cout << t.prioridade << " " << t.descricao << "\n";
    }

}

