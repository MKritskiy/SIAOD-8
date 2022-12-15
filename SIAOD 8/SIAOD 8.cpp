#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Одна вершина графа
struct Vertex {
    //Ребра с другими вершинами
    vector <Vertex*> cnctns;
    //цвет вершины
    int clr = 0;
    //текст врешины
    string text;
};


//Все вершины графа
vector<Vertex*> vrtxs;


//Создание вершины
void createVrtx() {
    string text;
    cout << "text: ";
    cin >> text;
    Vertex* newVrtx = new Vertex();
    newVrtx->text = text;
    int cnctCount;
    cout << "vrtx count: ";
    cin >> cnctCount;
    string cnctVrtxText;
    for (int i = 0; i < cnctCount; i++)
    {
        cout << "vrtx " << i << " connection text : ";
        cin >> cnctVrtxText;
        for (int j = 0; j < vrtxs.size(); j++)
        {
            if (vrtxs[j]->text == cnctVrtxText) {
                newVrtx->cnctns.push_back(vrtxs[j]);
                vrtxs[j]->cnctns.push_back(newVrtx);
                break;
            }
        }
    }
    vrtxs.push_back(newVrtx);
}



//Раскраска вершин жадным алгоритмом
void pntVrtxs() {
    int counter = 0;
    for (int color = 1; counter<vrtxs.size(); color++)
    {
        for (auto vrtx : vrtxs)
        {
            bool hasColor = false;
            if (vrtx->clr == 0) {
                for (auto cnction : vrtx->cnctns)
                {
                    if (cnction->clr == color) {
                        hasColor = true;
                        break;
                    }
                }
                if (!hasColor) {
                    vrtx->clr = color;
                    counter++;
                }
            }
        }
    }
}


//Вывод всех раскрасок
void printPntgs() {
    int counter = 0;
    for (int color = 1; counter<vrtxs.size(); color++)
    {
        cout << color << "\t";
        for (auto vrtx : vrtxs)
        {
            if (vrtx->clr == color) {
                cout << vrtx->text<<", ";
                counter++;
            }
        }
        cout << "\n";
    }
}



int main()
{
    cout << "Count of vrtxs: ";
    int cntOfVrtxs;
    cin >> cntOfVrtxs;
    for (int i = 0; i < cntOfVrtxs; i++)
    {
        createVrtx();
    }
    pntVrtxs();
    printPntgs();
}
//13
//AB
//0
//AC
//0
//AD
//0
//BA
//0
//BC
//1
//AB
//BD
//2
//AB
//AC
//DA
//3
//AB
//AC
//BD
//DB
//2
//AC
//BC
//DC
//0
//EA
//3
//AB
//AC
//AD
//EB
//5
//AC
//AD
//BC
//BD
//DA
//EC
//4
//AD
//BD
//DA
//DB
//ED
//0
