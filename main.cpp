#include <iostream>
#include<string>
#include<vector>
#include<math.h>
#include<array>
#include<algorithm>
using namespace std;
//exercice 1
int main()
{
    //entier
    int* pe=new int;
    *pe=42;
    cout<<"Valeur de l'entier: "<<*pe<<endl;
    cout<<"Adresse de l'entier: "<<pe<<endl;
    return 0;
    //reel
    float* pr=new float;
    *pr=42.2;
    cout<<"Valeur de l'entier: "<<*pr<<endl;
    cout << "Adresse de l'entier: "<<pr<<endl;
    return 0;

}
//exercice 2

void tValeur(int a, int b){
    cout<<"Par valeur: "<<(a==b) <<endl;
}

void tAdresse(int* a,int* b){
    cout<<"Par adresse: "<<(*a==*b)<<endl;
}

void tReference(int& a,int& b){
    cout<<"Par référence: "<<(a==b)<<endl;
}

int main() {
    int x=5,y=5;
    tValeur(x,y);
    tAdresse(&x,&y);
    tReference(x,y);
    return 0;
}
//exercice 3
void incrementer(int* a){
    (*a)++;
}

void permuter(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void permuterReference(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}

int main(){
    int a=5, b=10;
    incrementer(&a);
    cout<<"Après incrémentation: "<<a<<endl;

    permuter(&a,&b);
    cout<<"Après permutation (pointeurs): a = "<<a<<", b = "<<b<<endl;

    permuterReference(a, b);
    cout<<"Après permutation (références): a = "<<a<<", b = "<<b<< endl;

    return 0;
}
//exercice 4
void afficherMenu() {
    cout << "Choisissez une opération:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Soustraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Quitter" << endl;
}

int main() {
    int choix;
    do {
        afficherMenu();
        cin>>choix;

        if (choix>=1&&choix<=4){
            double a,b;
            cout<<"Entrez deux nombres: ";
            cin>>a>>b;

            switch (choix){
                case 1:cout<<"Résultat: "<<a+b<<endl; break;
                case 2:cout<<"Résultat: "<< a-b<<endl; break;
                case 3:cout<<"Résultat: "<< a*b<<endl; break;
                case 4: 
                    if(b!=0)
                        cout<<"Résultat:"<<a/b<<endl;
                    else
                        cout<<"Erreur: Division par zéro!"<<endl;
                    break;
            }
        }
        system("cls");
    } while (choix != 5);

    return 0;
}
//exercice 5
#include <cstdlib>
#include <ctime>

void NbrAlea(int min,int max){
    for (int i=0;i<5;i++){
        int randomNum=min+rand()%(max-min+1);
        cout<<"Nombre aléatoire "<<(i + 1)<<": "<< randomNum<<endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initialiser le générateur de nombres aléatoires
    NbrAlea(1, 100); // Générer des nombres aléatoires entre 1 et 100
    return 0;
}

//exercice 6

using namespace std;

void Cone(int hauteurCone,int& boulesRestantes){
    int largeur=2*hauteurCone-1;

    for (int i=0;i<hauteurCone;i++){
        int nbEtoiles=2*i+1;
        int nbEspaces=(largeur-nbEtoiles)/2;
        for (int j=0;j<nbEspaces;j++){
            cout<<' ';
        }
        for (int j=0;j<nbEtoiles;j++){
            if (boulesRestantes >0 && ((rand()%100)/100.0)<0.5){
                cout << 'O';
                boulesRestantes--;
            } else {
                cout<<'*';
            }
        }

        cout<<endl;
    }
}
void Tronc(int hauteurTronc, int largeurTronc, int largeurCone) {
    int nbEspaces=(largeurCone-largeurTronc)/2;

    for (int i=0;i<hauteurTronc;i++) {
        // Espaces avant le tronc
        for (int j=0;j<nbEspaces;j++) {
            cout<<' ';
        }

        // Tronc
        for (int j=0;j<largeurTronc;j++){
            cout<<'|';
        }

        cout<<endl;
    }
}

int main(){
    srand(time(0));
    int hauteurCone, hauteurTronc, largeurTronc, nbBoules;

    cout<<"Entrez la hauteur du cône : ";
    cin>>hauteurCone;

    cout<<"Entrez la hauteur du tronc : ";
    cin>>hauteurTronc;

    cout<<"Entrez la largeur du tronc : ";
    cin>>largeurTronc;

    cout<<"Entrez le nombre de boules : ";
    cin>>nbBoules;
    int boulesRestantes=nbBoules;
    Cone(hauteurCone,boulesRestantes);
    Tronc(hauteurTronc,largeurTronc,2*hauteurCone-1);
    return 0;
}
//exercice 7
int u(int n) {
    if (n == 0) return 3;
    return 3 * u(n - 1) + 4;
}

int main() {
    int N;
    cout<<"Entrez un entier N: ";
    cin>>N;
    cout<<"u(" << N << ") = "<<u(N)<<endl;
    return 0;
}