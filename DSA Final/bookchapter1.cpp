#include <iostream>
using namespace std;

class node
{
public:
    int count;
    string name;
    node *children[10];
};

class Book
{
    node *root;

    public:

    Book()
    {
        root = NULL;
    }

    void create()
    {
        root = new node();
        cout << "\nEnter the name of the book you want to create : ";
        cin >> root->name;
        cout << "\nBook created succesfully !!";

        cout << "\n\nEnter the number of chapters in the book : ";
        cin >> root->count;

        for (int i = 0; i < root->count; i++)
        {
            root->children[i] = new node();
            cout << "\nEnter the name of chapter " << i + 1 << " : ";
            cin >> root->children[i]->name;

            cout << "\nEnter the number of sections in chapter " << root->children[i]->name << " : ";
            cin >> root->children[i]->count;

            for (int j = 0; j < root->children[i]->count; j++)
            {
                root->children[i]->children[j] = new node();
                cout << "\nEnter the name of section " << j + 1 << " : ";
                cin >> root->children[i]->children[j]->name;

                cout << "\nEnter the nunber of subsections in the section " << root->children[i]->children[j]->name << " : ";
                cin >> root->children[i]->children[j]->count;

                for (int k = 0; k < root->children[i]->children[j]->count; k++)
                {
                    root->children[i]->children[j]->children[k] = new node();
                    cout << "\nEnter the name of sub-section " << k + 1 << " : ";
                    cin >> root->children[i]->children[j]->children[k]->name;
                }
            }
        }
    }

    void display()
    {
        cout << "\n\n-----------Displaying information of the book-------------";
        cout << "\n\nNAME OF THE BOOK : " << root->name;

        for (int i = 0; i < root->count; i++)
        {

            cout << "\n\nCHAPTER" << i + 1 << " : " << root->children[i]->name;

            for (int j = 0; j < root->children[i]->count; j++)
            {
                cout << "\n\t" << j + 1 << ". " << root->children[i]->children[j]->name;

                for (int k = 0; k < root->children[i]->children[j]->count; k++)
                {
                    cout << "\n\t\t" << char(k + 49) << ". " << root->children[i]->children[j]->children[k]->name;
                }
            }
        }
    }
};

int main()
{
    Book b;
    b.create();
    b.display();
    return 0;
}