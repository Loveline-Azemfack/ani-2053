# DEMO1:

Ici nous allons travailler dans le dépôt **Exercice1-print2-clone2**.

Pour faire cet exercice; nous allons observer le graphe

## 1. Observer le graphe des commits

Pour commencer, je vérifie l'historique de mon dépôt avec :

```
git log --oneline --graph --all
```

Cette commande permet d'afficher les commits sous forme de graphe et de voir les différentes branches ainsi que les fusions.

Dans mon historique, je peux observer une partie qui contient une divergence entre deux branches puis une fusion. comme dans l'exercice 10. 

## 2. Graphe des commits

Je peux représenter cette partie de mon historique sous forme d'arborescence :

```
                    3a55bbb
                   /       \
                  /         \
be7af1a ─────────            bfcfe5b
                  \         /
                   \       /
                    42a5715
```

Ici :

* `be7af1a` est le **point de  divergence.**
* `3a55bbb` est l'une des  **branches**.
* `42a5715` représente une autre **branche**.
* `bfcfe5b` est le **point de fusion des deux branches.**


## même graphe avec git log -{}-graph

Après avoir dessiné le graphe, je vérifie avec la commande :

```
git log --oneline --graph --all
```

Resultat:
```
* 3590358 (HEAD -> integration-rebase) suppression du fichier de 10Mo dans le cadre de l'exercice 11
* 440c410 ajout d'un fichier de 10Mo dans le cadre de l'exercice 11
* c56dfde modification dans le cas de rebase
* 31611ed (integration-merge-et-rebase) modification dans le cas de merge
* 89dc22f (print2) ajout du commentaire pour le travail en cours
* c10bdfc (origin/print2, origin/HEAD) Revert "anonce de la somme de 2 +6"
| * 4b1fa6d (refs/stash) WIP on print2: c204f9a anonce de la somme de 2 +6
|/| 
| * c8ffaf0 index on print2: c204f9a anonce de la somme de 2 +6
|/  
* c204f9a anonce de la somme de 2 +6
*   964a08f anonce de la somme de 2 +6
|\  
| *   5d0b8b0 anonce de la somme de 2 +6
| |\  
| * | 40bfbae anonce de la somme de 2 +6
* | | 8735c18 anonce de la somme 2 + 4
| |/  
|/|   
* | bfcfe5b conflit de la ligne 5 resolu
|\| 
| * 42a5715 affichons bonjour a tous
* | 3a55bbb affichons bonjour
|/  
* be7af1a premier main vide
* 79b5cd1 ajout de iostream
* 4eb1ced premiere modification
* 71ef3d6 modif
* 98767fd modification du fichier1
* a7fd8e0 creation de mon troisieme fichier
* 467d24f creation de mon deuxieme fichier
* e8ea254 creation de mon premier fichier
```
On remarque bien la premiere partie representee plus haut.

## CORRESPONDANCE

On remarque ici que la premiere partie du graph obtenu avec la commande et celle faite manuellement ont d'abord quelqueselements en commun comme les differentes branches, l'identifiant du commit qui sert de fusion, la divergenc remaquee, la seule chose qui les differents est que celui fait manuellement est plus facile a comprendre que celui fait a travers la commande. Mais il y a une chose a ajouter, je ne sais pas si la commande **git log -{}-graph** tel qu'ecrit est une erreur mais lorsque je l'ai tape elle n'a pas prise j'ai donc taper a ma propre maniere la commande que j'ai toujours utilise pour voir les graph.  
