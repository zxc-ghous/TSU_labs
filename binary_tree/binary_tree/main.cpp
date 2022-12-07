#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "search_treeh.h"
using namespace std;

void testTree(BinaryTree& tree, const int treeSize)
{
    BinaryTree& tree1 = tree;
    BinaryTree& tree2 = tree;
    BinaryTree& tree3 = tree;
    //заполняем дерево tree1 0,1,2,3.... и удаляем элементы в прямом порядке
    for (int i = 0; i < treeSize; i++)
    {
        tree1.addNode(i, tree1.GetRoot());
    }

    cout<<"tree1 find key 10: "<<tree1.FindKey(10,tree1.GetRoot())->GetKey()<<endl;
    vector<int> tree1_nodes = tree1.getTreeKeysVector(tree1.GetRoot());
    for (int i = 0; i < tree1_nodes.size(); i++)
    {
        tree1.deleteNode(tree1_nodes[i]);
    }
    cout << "tree1 is empty: " << tree1.isEmpty() << endl;
    //заполняем дерево tree2 0,1,2,3.... и удаляем элементы в обратном порядке
    for (int i = 0; i < treeSize; i++)
    {
        tree2.addNode(i, tree2.GetRoot());
    }
    cout<<"tree2 find key 10: "<<tree2.FindKey(10,tree1.GetRoot())->GetKey()<<endl;
    vector<int> tree2_nodes = tree2.getTreeKeysVector(tree2.GetRoot());
    for (int i = tree2_nodes.size()-1; i >= 0; i--)
    {
        tree2.deleteNode(tree2_nodes[i]);
    }
    cout << "tree2 is empty: " << tree2.isEmpty() << endl;
    //заполняем дерево tree3 случайными числами и удаляем элементы в прямом порядке
    for (int i = 0; i < treeSize; i++)
    {
        tree3.addNode(rand()%50, tree3.GetRoot());
    }
    cout<<"tree3 find key -100: "<<tree3.FindKey(-100,tree3.GetRoot())->GetKey()<<endl;
    vector<int> tree3_nodes = tree3.getTreeKeysVector(tree3.GetRoot());
    for (int i = 0; i < tree3_nodes.size(); i++)
        {
            tree3.deleteNode(tree3_nodes[i]);
        }
    cout << "tree3 is empty: " << tree3.isEmpty() << endl;
}

void testSTTree(SearchTree& tree, const int treesize, bool printTree=false)
{
    SearchTree tree1;
    for (int i = 0; i < treesize; i++)
    {
        tree1.addNode(i, tree1.GetRoot());
    }
    for (int i = 0; i < treesize; i++)
    {
        tree.addNode(rand()%50, tree.GetRoot());
    }
    cout<<"0 to treesize "<<"min element: "<<tree1.getMin(tree1.GetRoot())->GetKey()<<" max element: "<<tree1.getMax(tree1.GetRoot())->GetKey()<<endl;
    cout<<"rand()%50 "<<"min element: "<<tree.getMin(tree.GetRoot())->GetKey()<<" max element: "<<tree.getMax(tree.GetRoot())->GetKey()<<endl;
    cout<<"delete tree1 only min element"<<endl;
    for (int i = 0; i < treesize; i++)
    {
            if (printTree) tree1.PrintTree(tree1.GetRoot(),5);
            cout<<"------min element "<<tree1.getMin(tree1.GetRoot())->GetKey()<<"--------"<<endl;
            tree1.deleteNode(tree1.getMin(tree1.GetRoot())->GetKey());
    }
    cout << "tree1 is empty: " << tree1.isEmpty() << endl;
    cout<<"delete tree only min element"<<endl;
    for (int i = 0; i < treesize; i++)
    {
            if (printTree) tree.PrintTree(tree.GetRoot(),5);
            cout<<"------min element "<<tree.getMin(tree.GetRoot())->GetKey()<<"--------"<<endl;
            tree.deleteNode(tree.getMin(tree.GetRoot())->GetKey());
    }
    cout << "tree is empty: " << tree.isEmpty() << endl;
    SearchTree treemax1;
    SearchTree treemax2;
    for (int i = 0; i < treesize; i++)
    {
        int rand_val=rand()%50;
        treemax1.addNode(rand_val, treemax1.GetRoot());
        treemax2.addNode(rand_val, treemax2.GetRoot());
    }
    cout<<"delete treemax1 only max element"<<endl;
    for (int i = 0; i < treesize; i++)
    {
            if (printTree) treemax1.PrintTree(treemax1.GetRoot(),5);
            cout<<"------max element "<<treemax1.getMax(treemax1.GetRoot())->GetKey()<<"--------"<<endl;
            treemax1.deleteNode(treemax1.getMax(treemax1.GetRoot())->GetKey());
    }
    cout << "treemax1 is empty: " << treemax1.isEmpty() << endl;
    cout<<"delete treemax2 only root element"<<endl;
    for (int i = 0; i < treesize; i++)
    {
            if (printTree) treemax2.PrintTree(treemax2.GetRoot(),5);
            cout<<"------root element "<<treemax2.GetRoot()->GetKey()<<"--------"<<endl;
            treemax2.deleteNode(treemax2.GetRoot()->GetKey());
    }
    cout << "treemax2 is empty: " << treemax2.isEmpty() << endl;

}

void testTree(const int treesize, bool printTree=false)
{
    BinaryTree bt;
    SearchTree st;
    cout << "binary tree test: " << endl;
    //testTree(bt, treesize);
    cout << "--------------------------------" << endl;
    cout << "--------------------------------" << endl;
    cout << "search tree test: " << endl;
    //testTree(st, treesize);
    testSTTree(st, treesize,printTree);
}

int main()
{
    SearchTree tree;
    int size = 1;

    std::vector<int> keys;
    for (int i = 0; i < size; i++) {
        keys.push_back(i + 1);
    }

    for (int i = 0; i < size; i++) {
        int index = rand() % keys.size();
        tree.addNode(keys[index], tree.GetRoot());
        keys.erase(keys.begin() + index);
    }
    tree.PrintTree(tree.GetRoot(), 5);

    while (!tree.isEmpty()) {
        int key;
        cin >> key;
        cout << (tree.deleteNode(key) ? "true" : "false") << endl;
        tree.PrintTree(tree.GetRoot(), 5);
    }
    return 0;
    Node *node = tree.FindKey(17, tree.GetRoot());
    std::cout << tree.FindKey(17, tree.GetRoot())->GetKey() << std::endl;
    //testTree(15,true);
//    SearchTree tree3;
//    tree3.addNode(8,tree3.GetRoot());
//    tree3.addNode(3,tree3.GetRoot());
//    tree3.addNode(10,tree3.GetRoot());
//    tree3.addNode(1,tree3.GetRoot());
//    tree3.addNode(6,tree3.GetRoot());
//    tree3.addNode(14,tree3.GetRoot());
//    tree3.addNode(4,tree3.GetRoot());
//    tree3.addNode(7,tree3.GetRoot());
//    tree3.addNode(3,tree3.GetRoot());
//    tree3.addNode(13,tree3.GetRoot());
//    cout<<"delete tree3 only root element"<<endl;
//    for (int i = 0; i < 10; i++)
//    {
//            tree3.PrintTree(tree3.GetRoot(),5);
//            cout<<"------root element "<<tree3.GetRoot()->GetKey()<<"--------"<<endl;
//            tree3.deleteNode(tree3.GetRoot()->GetKey());
//    }
//    cout << "tree3 is empty: " << tree3.isEmpty() << endl;
//    int treeSize=8;
//    SearchTree tree3;
//    for (int i = 0; i < treeSize; i++)
//    {
//        tree3.addNode(rand()%10, tree3.GetRoot());
//    }
//    tree3.PrintTree(tree3.GetRoot(),5);
//    //cout<<tree3.GetRoot()->right->GetKey();
//    vector<int> tree3_nodes = tree3.getTreeKeysVector(tree3.GetRoot());
//    for (int i = 0; i < tree3_nodes.size(); i++)
//        {
//            tree3.PrintTree(tree3.GetRoot(),5);
//            int temp=rand()%50;
//            cout<<"---------------"<<temp<<"----------"<<endl;
//            tree3.deleteNode(temp);
//        }
//    cout << "tree3 is empty: " << tree3.isEmpty() << endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
