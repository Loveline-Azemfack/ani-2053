# DEMO4:

Pour cet exercice nous avons choisi de prendre pour projet le gestionnaire d'etudiants.

Pour cela, nous avons élaboré un travail de quatre étudiants dont les matricules sont :

25p896, 25p916, 25p917 et 25p928.

Nous avons d'abord commencé à définir les critères de nomination de nos branches et pour ce fait, nous avons créé 4 branches de travail : `feat/students-management`, `feat/students-management-durel`, `feat/students-search`, `feat/students-search-Gabriel`.

Chacun a travaillé sur sa branche. Dès lors, nous avons fait un `git push` sur les branches et ensuite nous avons utilisé :

```powershell
git switch main
```

Nous avons ensuite fusionné les branches et chacun a fait un `git pull` en étant sur son espace de travail.

Moi personnellement, j'ai obtenu ceci :

```text
25ed5d9 (HEAD -> main) Merge branch 'main' of https://github.com/Loveline-Azemfack/GestionnaireEtudiants

1584597 (origin/main, origin/feat/student-search-gabriel, origin/HEAD) Code qui fait la recherche

c9f1c3a (origin/feat/student-search, feat/student-search) feat(Recherche-etudiant): Etablissons le plan de recherche des etudiants a travers recherche.cpp

d2ac43e (feat/student-management) creation du projet
```

## COMMIT A ANALYSER

```text
1584597 (origin/main, origin/feat/student-search-gabriel, origin/HEAD) Code qui fait la recherche
```

### CE QU'IL FAIT

D'après la description, ce commit porte sur le code permettant d'effectuer la recherche des étudiants. Le message indique donc que le commit concerne la fonctionnalité de recherche, mais il reste assez général et ne précise pas exactement ce qui a été ajouté ou modifié.

### SI LES COMMITS SONT LISIBLES

Chez moi, je peux voir les commits suivants :

```text
25ed5d9 Merge branch 'main' of https://github.com/Loveline-Azemfack/GestionnaireEtudiants

1584597 Code qui fait la recherche

c9f1c3a feat(Recherche-etudiant): Etablissons le plan de recherche des etudiants a travers recherche.cpp

d2ac43e creation du projet
```

Le commit que j'analyse est identifié par l'empreinte `1584597`. Son message **« Code qui fait la recherche »** permet de comprendre qu'il concerne la recherche des étudiants, mais il reste assez général. Le commit `c9f1c3a` est également lié à la recherche et son message permet de comprendre davantage l'objectif de la modification.

### CE QUI MANQUE

En ce qui concerne le commit analysé, il faudrait que le message soit plus précis afin de permettre de comprendre rapidement ce qui a été ajouté dans le code de recherche.

Il faut également vérifier que la fonctionnalité de recherche correspond bien au travail prévu dans le projet.

### CE QUI NE DEVRAIT PAS Y ÊTRE

Dans le commit que j'analyse, je n'ai pas constaté de modification qui ne devrait pas y être. Le commit concerne la recherche des étudiants et reste donc lié au travail demandé.

Cependant, le fait d'avoir un commit de fusion de `main` dans l'historique mérite d'être distingué du travail de recherche lui-même, car il ne correspond pas directement à la fonctionnalité de recherche.

### CE QUE LA DISCUSSION À QUATRE A CHANGÉ

Après la discussion à quatre, nous avons pu comparer nos différentes observations sur les branches. Cette discussion nous a permis de mieux comprendre l'importance d'avoir des commits lisibles et de vérifier le contenu d'une branche avant son intégration.
