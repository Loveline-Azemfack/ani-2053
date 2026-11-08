#include <iostream>
#include <string>

// Pourquoi avons-nous créé un enum Etat ?
// Parce que nous avons quatre états possibles pour chaque déclaration :
// elle peut être absente, écrite normalement, définie par défaut ou supprimée.
enum Etat {
    ABSENT,
    ECRIT,
    DEFAUT,
    SUPPRIME
};


// Pourquoi avons-nous créé cette fonction ?
// Parce que nous voulons transformer les différentes valeurs de Etat
// en chaînes de caractères afin de pouvoir les afficher.
std::string nomEtat(Etat etat) {

    // Pourquoi utilisons-nous switch ? 
    // Parce que nous voulons vérifier chaque valeur possible de etat.
    switch (etat) {

        // Pourquoi retournons-nous ABSENT ?
        // Parce que la déclaration correspondante n'a pas été trouvée.
        case ABSENT:
            return "ABSENT";

        // Pourquoi retournons-nous ECRIT ?
        // Parce que la déclaration a été écrite normalement.
        case ECRIT:
            return "ECRIT";

        // Pourquoi retournons-nous DEFAUT ?
        // Parce que la déclaration utilise le mot-clé default.
        case DEFAUT:
            return "DEFAUT";

        // Pourquoi retournons-nous SUPPRIME ?
        // Parce que la déclaration utilise le mot-clé delete.
        case SUPPRIME:
            return "SUPPRIME";
    }

    // Pourquoi retournons-nous une chaîne vide ici ?
    // Parce que nous devons prévoir une valeur de retour si aucun cas ne correspond.
    return "";
}


// Pourquoi avons-nous créé cette fonction ?
// Parce que les espaces peuvent empêcher notre programme de reconnaître
// correctement les différentes déclarations.
std::string supprimerEspaces(std::string ligne) {

    // Pourquoi créons-nous une nouvelle chaîne vide ?
    // Parce que nous allons y reconstruire la ligne sans ses espaces.
    std::string resultat = "";

    // Pourquoi utilisons-nous cette boucle for ?
    // Parce que nous voulons parcourir chaque caractère de la ligne.
    for (char caractere : ligne) {

        // Pourquoi vérifions-nous si le caractère est différent d'un espace ?
        // Parce que nous voulons conserver uniquement les caractères utiles.
        if (caractere != ' ') {

            // Pourquoi ajoutons-nous le caractère à resultat ?
            // Parce que nous construisons progressivement notre nouvelle chaîne.
            resultat += caractere;
        }
    }

    // Pourquoi retournons-nous resultat ?
    // Parce que nous voulons récupérer la ligne après avoir supprimé ses espaces.
    return resultat;
}


// Pourquoi avons-nous créé cette fonction ?
// Parce que nous voulons savoir si une déclaration est écrite normalement,
// définie par défaut ou supprimée.
Etat determinerEtat(std::string ligne) {

    // Pourquoi vérifions-nous la fin de la ligne avec size() et substr() ?
    // Parce que nous voulons savoir si la déclaration se termine par =delete;.
    if (ligne.size() >= 8 &&
        ligne.substr(ligne.size() - 8) == "=delete;") {

        // Pourquoi retournons-nous SUPPRIME ?
        // Parce que la déclaration a été explicitement supprimée.
        return SUPPRIME;
    }

    // Pourquoi effectuons-nous une deuxième vérification ?
    // Parce que nous voulons savoir si la déclaration se termine par =default;.
    if (ligne.size() >= 9 &&
        ligne.substr(ligne.size() - 9) == "=default;") {

        // Pourquoi retournons-nous DEFAUT ?
        // Parce que la déclaration demande au compilateur d'utiliser
        // l'implémentation générée par défaut.
        return DEFAUT;
    }

    // Pourquoi retournons-nous ECRIT si aucune condition n'est vérifiée ?
    // Parce que nous considérons que la déclaration est écrite normalement.
    return ECRIT;
}


int main() {

    // Pourquoi initialisons-nous toutes les variables à ABSENT ?
    // Parce qu'au début du programme, nous n'avons encore analysé aucune déclaration.

    Etat destructeur = ABSENT;
    Etat copie = ABSENT;
    Etat AffectationCopie = ABSENT;
    Etat Deplacement = ABSENT;
    Etat AffectationDeplacement = ABSENT;

    // Pourquoi créons-nous une variable nomClasse ?
    // Parce que nous devons récupérer le nom de la classe que nous voulons analyser.
    std::string nomClasse;

    // Pourquoi utilisons-nous getline() ?
    // Parce que cette fonction permet de récupérer toute la première ligne saisie.
    std::getline(std::cin, nomClasse);


    // Pourquoi créons-nous une variable ligne ?
    // Parce que nous allons y récupérer successivement les différentes déclarations.
    std::string ligne;

    // Pourquoi utilisons-nous while avec getline() ?
    // Parce que nous voulons continuer à lire les lignes tant que la lecture réussit.
    while (std::getline(std::cin, ligne)) {

        // Pourquoi utilisons-nous find("//") ?
        // Parce que nous voulons rechercher le début d'un commentaire dans la ligne.
        size_t position = ligne.find("//");

        // Pourquoi vérifions-nous si position est différent de npos ?
        // Parce que npos signifie que le texte recherché n'a pas été trouvé.
        if (position != std::string::npos) {

            // Pourquoi utilisons-nous substr(0, position) ?
            // Parce que nous voulons conserver uniquement la partie située
            // avant le commentaire et supprimer tout ce qui vient après.
            ligne = ligne.substr(0, position);
        }


        // Pourquoi supprimons-nous les espaces ?
        // Parce que nous voulons faciliter la comparaison des déclarations.
        ligne = supprimerEspaces(ligne);


        // Pourquoi vérifions-nous si la ligne est vide ?
        // Parce qu'une ligne vide ne contient aucune déclaration à analyser.
        if (ligne.empty()) {

            // Pourquoi utilisons-nous continue ?
            // Parce que nous voulons passer directement à la ligne suivante.
            continue;
        }


        // Pourquoi recherchons-nous "~" suivi du nom de la classe ?
        // Parce que c'est la forme qui permet de reconnaître son destructeur.
        if (ligne.find("~" + nomClasse + "(") != std::string::npos) {

            // Pourquoi appelons-nous determinerEtat() ?
            // Parce que nous voulons connaître l'état de ce destructeur.
            destructeur = determinerEtat(ligne);
        }


        // Pourquoi vérifions-nous le constructeur de copie ?
        // Parce que nous voulons savoir si la classe possède un constructeur
        // qui reçoit une référence constante vers un autre objet de même classe.
        else if (ligne.find(nomClasse + "(const" + nomClasse + "&") == 0) {

            // Pourquoi créons-nous cette chaîne debut ?
            // Parce que nous voulons conserver le début exact du constructeur de copie
            // afin de vérifier le caractère qui vient juste après.
            std::string debut = nomClasse + "(const" + nomClasse + "&";

            // Pourquoi vérifions-nous le caractère suivant ?
            // Parce que deux esperluettes (&&) correspondent à une référence
            // de déplacement et non à une référence de copie.
            if (ligne.size() == debut.size() ||
                ligne[debut.size()] != '&') {

                // Pourquoi enregistrons-nous l'état dans copie ?
                // Parce que nous venons de reconnaître un constructeur de copie.
                copie = determinerEtat(ligne);
            }
        }


        // Pourquoi recherchons-nous operator= avec const et le nom de la classe ?
        // Parce que nous voulons reconnaître l'opérateur d'affectation par copie.
        else if (ligne.find(nomClasse + "&operator=(const" + nomClasse + "&") == 0) {

            // Pourquoi créons-nous cette chaîne debut ?
            // Parce que nous voulons vérifier que la déclaration correspond
            // bien à une affectation par copie et non à une affectation par déplacement.
            std::string debut = nomClasse + "&operator=(const" + nomClasse + "&";

            // Pourquoi vérifions-nous que le caractère suivant n'est pas '&' ?
            // Parce que && représente une référence de déplacement.
            if (ligne.size() == debut.size() ||
                ligne[debut.size()] != '&') {

                // Pourquoi enregistrons-nous le résultat dans AffectationCopie ?
                // Parce que nous avons reconnu l'opérateur d'affectation par copie.
                AffectationCopie = determinerEtat(ligne);
            }
        }


        // Pourquoi recherchons-nous le nom de la classe suivi de && ?
        // Parce que cette forme permet de reconnaître le constructeur de déplacement.
        else if (ligne.find(nomClasse + "(" + nomClasse + "&&") == 0) {

            // Pourquoi enregistrons-nous son état ?
            // Parce que nous devons savoir si ce constructeur est écrit,
            // défini par défaut ou supprimé.
            Deplacement = determinerEtat(ligne);
        }


        // Pourquoi recherchons-nous operator= avec && ?
        // Parce que nous voulons reconnaître l'opérateur d'affectation par déplacement.
        else if (ligne.find(nomClasse + "&operator=(" + nomClasse + "&&") == 0) {

            // Pourquoi enregistrons-nous son état ?
            // Parce que nous avons reconnu une affectation par déplacement.
            AffectationDeplacement = determinerEtat(ligne);
        }
    }


    // Pourquoi créons-nous cinq variables booléennes ?
    // Parce que nous voulons savoir simplement si chacun des cinq éléments
    // a été déclaré ou non, sans avoir à vérifier chaque état plusieurs fois.

    bool d = destructeur != ABSENT;
    bool c = copie != ABSENT;
    bool ac = AffectationCopie != ABSENT;
    bool m = Deplacement != ABSENT;
    bool am = AffectationDeplacement != ABSENT;


    // Pourquoi créons-nous une variable regle ?
    // Parce que nous devons enregistrer la règle qui correspond
    // aux déclarations trouvées dans la classe.
    std::string regle;


    // Pourquoi vérifions-nous si les cinq variables sont fausses ?
    // Parce que cela signifie qu'aucun des cinq éléments n'a été déclaré.
    if (!d && !c && !ac && !m && !am) {

        // Pourquoi attribuons-nous ZERO ?
        // Parce qu'aucun des cinq éléments n'est présent.
        regle = "ZERO";
    }


    // Pourquoi vérifions-nous si les cinq variables sont vraies ?
    // Parce que cela signifie que les cinq éléments ont tous été déclarés.
    else if (d && c && ac && m && am) {

        // Pourquoi attribuons-nous CINQ ?
        // Parce que les cinq éléments sont présents.
        regle = "CINQ";
    }


    // Pourquoi vérifions-nous si les trois premiers sont vrais
    // et les deux derniers sont faux ?
    // Parce que cela correspond au cas où le destructeur,
    // la copie et l'affectation par copie sont déclarés,
    // mais où les deux opérations de déplacement sont absentes.
    else if (d && c && ac && !m && !am) {

        // Pourquoi attribuons-nous TROIS ?
        // Parce que seuls les trois premiers éléments sont présents.
        regle = "TROIS";
    }


    // Pourquoi utilisons-nous else ?
    // Parce que tous les autres cas ne correspondent à aucune des règles précédentes.
    else {

        // Pourquoi attribuons-nous INCOMPLETE ?
        // Parce que les déclarations trouvées ne constituent pas
        // une des trois configurations précédentes.
        regle = "INCOMPLETE";
    }


    // Pourquoi affichons-nous les cinq états ?
    // Parce que nous devons présenter le résultat de l'analyse de chaque élément.

    std::cout << "DESTRUCTEUR " << nomEtat(destructeur) << std::endl;
    std::cout << "COPIE " << nomEtat(copie) << std::endl;
    std::cout << "AFFECTATION_COPIE " << nomEtat(AffectationCopie) << std::endl;
    std::cout << "DEPLACEMENT " << nomEtat(Deplacement) << std::endl;
    std::cout << "AFFECTATION_DEPLACEMENT " << nomEtat(AffectationDeplacement) << std::endl;


    // Pourquoi affichons-nous regle ?
    // Parce que nous voulons présenter la règle déterminée par notre programme.
    std::cout << "REGLE " << regle << std::endl;


    // Pourquoi vérifions-nous si regle est égale à INCOMPLETE ?
    // Parce que dans ce cas, nous devons également afficher les éléments manquants.
    if (regle == "INCOMPLETE") {

        // Pourquoi vérifions-nous si m ou am est vrai ?
        // Parce que si au moins une des deux opérations de déplacement est déclarée,
        // nous devons vérifier la présence des cinq éléments.
        if (m || am) {

            // Pourquoi vérifions-nous chaque variable avec ! ?
            // Parce que ! signifie NON et nous permet donc de détecter
            // les éléments qui n'ont pas été déclarés.

            if (!d) std::cout << "MANQUE DESTRUCTEUR" << std::endl;
            if (!c) std::cout << "MANQUE COPIE" << std::endl;
            if (!ac) std::cout << "MANQUE AFFECTATION_COPIE" << std::endl;
            if (!m) std::cout << "MANQUE DEPLACEMENT" << std::endl;
            if (!am) std::cout << "MANQUE AFFECTATION_DEPLACEMENT" << std::endl;
        }


        // Pourquoi utilisons-nous else ici ?
        // Parce que si aucune opération de déplacement n'est déclarée,
        // nous devons uniquement vérifier les trois premiers éléments.
        else {

            if (!d) std::cout << "MANQUE DESTRUCTEUR" << std::endl;
            if (!c) std::cout << "MANQUE COPIE" << std::endl;
            if (!ac) std::cout << "MANQUE AFFECTATION_COPIE" << std::endl;
        }
    }


    // Pourquoi vérifions-nous si destructeur est égal à ECRIT ?
    // Parce que dans les conditions de cet exercice, une classe possède une ressource
    // lorsque son destructeur est écrit normalement.
    // L'opérateur ternaire permet d'afficher OUI si la condition est vraie,
    // et NON dans le cas contraire.
    std::cout << "POSSEDE "<< (destructeur == ECRIT ? "OUI" : "NON")<< std::endl;


    // Pourquoi créons-nous la variable unique ?
    // Parce que nous voulons vérifier si le constructeur de copie est supprimé
    // et si le constructeur de déplacement est écrit ou défini par défaut.
    bool unique = (copie == SUPPRIME) && (Deplacement == ECRIT || Deplacement == DEFAUT);


    // Pourquoi affichons-nous unique avec un opérateur ternaire ?
    // Parce que nous voulons afficher OUI si la classe respecte ces conditions,
    // et NON si au moins une des conditions n'est pas respectée.
    std::cout << "UNIQUE " << (unique ? "OUI" : "NON") << std::endl;


    return 0;
}