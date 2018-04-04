#include "grman/grman.h"
#include <iostream>
#include "menu.h"
#include "graph.h"


int main()
{


    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    ///Declaration du menu
    Menu menu;

    /// Un graphe à charger depuis un fichier choisi
    Graph g;
    g.make_example();


    ///Gestion des menus
    menu.affiche_principal();
    menu.gestion_menu2(g);



    if(menu.getChoix()==2)
    {
        /// Vous gardez la main sur la "boucle de jeu"
        /// ( contrairement à des frameworks plus avancés )
        while ( !key[KEY_ESC] )
        {

            /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
            g.update();

            /// Mise à jour générale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();
        }
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


