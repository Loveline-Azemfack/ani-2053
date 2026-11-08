#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Pourquoi créons-nous une structure Texture ?
// Parce que chaque texture possède un numéro unique et un état
// qui indique si elle a déjà été libérée.
struct Texture {
    int numero;
    bool liberee;
};

int main() {
    int S, V, F;

    // Pourquoi lisons-nous S, V et F ?
    // Parce que l'énoncé définit trois endroits où les textures peuvent être libérées :
    // S correspond à SUPPRIME, V correspond à VIDE et F correspond à la FIN du programme.
    // Chaque valeur indique combien de fois une texture est libérée à cet endroit.
    cin >> S >> V >> F;

    int N;

    // Pourquoi lisons-nous N ?
    // Parce que nous devons connaître le nombre d'opérations à exécuter.
    cin >> N;

    // Pourquoi créons-nous ce vector ?
    // Parce qu'il représente le tableau de textures du programme.
    // Il contient uniquement les textures qui sont encore présentes dans le tableau.
    vector<Texture> tableau;

    // Pourquoi créons-nous ce deuxième vector ?
    // Parce que nous devons conserver l'état de toutes les textures créées,
    // même celles qui ont déjà été retirées du tableau.
    // Ainsi, nous pouvons savoir si une texture a déjà été libérée.
    vector<bool> etatTextures;

    int creees = 0;

    // Pourquoi créons-nous cette fonction lambda ?
    // Parce que la même opération de libération intervient à trois endroits :
    // SUPPRIME, VIDE et FIN.
    // Nous évitons ainsi de répéter le même traitement.
    //
    // Pourquoi recevons-nous numero et nombreLiberations ?
    // Parce que nous devons connaître la texture concernée
    // et le nombre de fois qu'elle doit être libérée.
    auto liberer = [&](int numero, int nombreLiberations) -> bool {

        // Pourquoi répétons-nous la libération ?
        // Parce que S, V ou F peut valoir 0, 1 ou 2.
        for (int i = 0; i < nombreLiberations; i++) {

            // Pourquoi vérifions-nous si la texture est déjà libérée ?
            // Parce que libérer une deuxième fois une texture déjà libérée
            // provoque un plantage du programme.
            if (etatTextures[numero - 1]) {
                return false;
            }

            // Pourquoi passons-nous son état à true ?
            // Parce que nous venons de libérer cette texture.
            // Cette information permettra de détecter une éventuelle
            // deuxième libération.
            etatTextures[numero - 1] = true;
        }

        // Pourquoi retournons-nous true ?
        // Parce que toutes les libérations demandées ont été effectuées
        // sans provoquer de plantage.
        return true;
    };

    // Pourquoi parcourons-nous les N opérations ?
    // Parce que nous devons rejouer le déroulement du programme
    // dans l'ordre exact où les opérations sont données.
    for (int i = 0; i < N; i++) {
        string operation;

        cin >> operation;

        // Pourquoi traitons-nous AJOUTE séparément ?
        // Parce que cette opération crée une nouvelle texture
        // et l'ajoute à la fin du tableau.
        if (operation == "AJOUTE") {

            // Pourquoi augmentons-nous creees ?
            // Parce que chaque AJOUTE crée une nouvelle texture.
            // Ce compteur sert également à lui attribuer un numéro unique.
            creees++;

            // Pourquoi ajoutons-nous une nouvelle texture au tableau ?
            // Parce que la texture vient d'être créée et doit être présente
            // dans le tableau des textures actives.
            tableau.push_back({creees, false});

            // Pourquoi ajoutons-nous également false dans etatTextures ?
            // Parce qu'une nouvelle texture n'a pas encore été libérée.
            // Son indice dans ce vector correspond à son numéro moins un.
            etatTextures.push_back(false);
        }

        // Pourquoi traitons-nous SUPPRIME ?
        // Parce que cette opération retire une texture située à un index précis.
        else if (operation == "SUPPRIME") {
            int index;

            // Pourquoi lisons-nous index ?
            // Parce que l'énoncé indique la position de la texture
            // à supprimer dans le tableau actuel.
            cin >> index;

            // Pourquoi récupérons-nous son numéro avant de la supprimer ?
            // Parce que son index indique sa position actuelle,
            // tandis que son numéro permet de l'identifier définitivement.
            int numero = tableau[index].numero;

            // Pourquoi appelons-nous liberer avec S ?
            // Parce que SUPPRIME libère la texture S fois avant de la retirer du tableau.
            if (!liberer(numero, S)) {

                // Pourquoi affichons-nous PLANTAGE ?
                // Parce que la texture vient d'être libérée une deuxième fois.
                // Nous devons afficher le numéro de l'opération et celui de la texture.
                cout << "PLANTAGE " << i + 1 << " TEXTURE " << numero << '\n';

                // Pourquoi arrêtons-nous immédiatement le programme ?
                // Parce que l'énoncé exige de nous arrêter au premier plantage,
                // sans effectuer les opérations suivantes.
                return 0;
            }

            // Pourquoi supprimons-nous cette texture du tableau ?
            // Parce que SUPPRIME retire la texture, même si S vaut zéro.
            // Elle ne sera donc plus présente parmi les textures actives.
            tableau.erase(tableau.begin() + index);
        }

        // Pourquoi traitons-nous VIDE ?
        // Parce que cette opération libère toutes les textures présentes
        // dans le tableau, puis vide complètement celui-ci.
        else if (operation == "VIDE") {

            // Pourquoi parcourons-nous tout le tableau ?
            // Parce que chaque texture présente doit être libérée V fois.
            for (int j = 0; j < tableau.size(); j++) {
                int numero = tableau[j].numero;

                // Pourquoi appelons-nous liberer avec V ?
                // Parce que V représente le nombre de libérations
                // effectuées par l'opération VIDE.
                if (!liberer(numero, V)) {

                    // Pourquoi affichons-nous i + 1 ?
                    // Parce que i représente l'indice de l'opération dans notre boucle,
                    // alors que l'énoncé numérote les opérations à partir de 1.
                    cout << "PLANTAGE " << i + 1 << " TEXTURE " << numero << '\n';

                    // Pourquoi arrêtons-nous immédiatement ?
                    // Parce qu'une deuxième libération a été détectée.
                    return 0;
                }
            }

            // Pourquoi vidons-nous le tableau après le parcours ?
            // Parce que l'opération VIDE retire toutes les textures du tableau.
            tableau.clear();
        }
    }

    // Pourquoi effectuons-nous un dernier parcours ?
    // Parce que l'énoncé précise qu'à la fin du programme,
    // toutes les textures encore présentes dans le tableau
    // sont libérées F fois.
    for (int i = 0; i < tableau.size(); i++) {
        int numero = tableau[i].numero;

        // Pourquoi appelons-nous liberer avec F ?
        // Parce que F représente le nombre de libérations effectuées
        // automatiquement à la fin du programme.
        if (!liberer(numero, F)) {

            // Pourquoi écrivons-nous FIN au lieu d'un numéro ?
            // Parce que ce plantage ne provient pas d'une opération de l'entrée,
            // mais de la libération effectuée à la fin du programme.
            cout << "PLANTAGE FIN TEXTURE " << numero << '\n';

            return 0;
        }
    }

    // Pourquoi affichons-nous CREEES ?
    // Parce que l'énoncé demande le nombre total de textures créées,
    // y compris celles qui ont déjà été retirées du tableau.
    cout << "CREEES " << creees << '\n';

    int fuites = 0;

    // Pourquoi parcourons-nous etatTextures ?
    // Parce que certaines textures ont pu être retirées du tableau
    // sans être libérées.
    // Nous devons donc examiner toutes les textures créées,
    // et pas seulement celles qui sont encore présentes.
    for (int i = 0; i < creees; i++) {

        // Pourquoi comptons-nous les textures dont l'état est false ?
        // Parce qu'une texture dont l'état est false n'a jamais été libérée.
        if (!etatTextures[i]) {
            fuites++;
        }
    }

    // Pourquoi affichons-nous FUITES ?
    // Parce que l'énoncé demande le nombre de textures
    // qui n'ont jamais été libérées.
    cout << "FUITES " << fuites << '\n';

    // Pourquoi affichons-nous PERDUES ?
    // Parce que l'énoncé demande également les numéros des textures
    // qui n'ont jamais été libérées, dans l'ordre croissant.
    cout << "PERDUES";

    bool aucune = true;

    // Pourquoi parcourons-nous les textures dans leur ordre de création ?
    // Parce que leurs numéros augmentent dans cet ordre.
    // Nous obtenons donc directement la liste dans l'ordre croissant.
    for (int i = 0; i < creees; i++) {

        // Pourquoi vérifions-nous encore etatTextures ?
        // Parce que nous devons identifier précisément
        // les textures qui n'ont jamais été libérées.
        if (!etatTextures[i]) {
            cout << " " << i + 1;
            aucune = false;
        }
    }

    // Pourquoi affichons-nous AUCUN ?
    // Parce que le format de sortie impose ce mot
    // lorsqu'aucune texture n'a été perdue.
    if (aucune) {
        cout << " AUCUN";
    }

    cout << '\n';

    return 0;
}