# EXERCICE 12 : RÈGLES GIT D'UN PROJET

## nommage des branches

Avant tout il faut d'abord que le nom d'une branche doit refléter son rôle, cela veut dire que lorsqu'une personne veut travailler dans une branche, le nom lui permet de savoir ce qu'elle doit faire dans la branche et ce qu'elle ne doit pas faire.

Ainsi notons ceci :

**Branche principale :**

`main` → Production

La branche de production c'est d'abord la branche principale donc le **main** et les étudiants ne devront pas travailler directement dessus. Donc on peut utiliser cette convention pour nommer les branches :

```
feat/user-authentication

fix/login-error-message

docs/update-installation
```

Ici :

* **feat** renvoie aux nouvelles fonctionnalités ;
* **fix** sera utilisé pour les corrections, c'est donc là qu'on arrête de nommer les branches un peu comme **modification1** ;
* **docs** est utilisé pour la documentation.

Donc ici, l'objectif de nommer les branches est d'éviter de travailler directement dans la branche principale et de ne pas écraser le travail des autres. Chacun fait donc ce qu'il a à faire dans sa branche et lorsqu'il va pousser sur GitHub, son travail sera relu avant d'être intégré dans le **main**.

## contenu d'un commit

En ce qui concerne le contenu des commits, ils devront utiliser une version commune pour que chaque modification soit explicite lors du **push**. Ils peuvent donc écrire leur contenu avec cette convention :

```
type(scope): description
```

Par exemple, si j'ai modifié quelque chose dans la branche `docs`, je peux mettre :

```
docs(readme): fix typo introduction
```

Là, le type est **docs**, le scope est **readme** et la description indique qu'une faute de frappe a été corrigée dans l'introduction.

Pour que la règle soit vérifiable, un commit doit respecter les conditions suivantes :

* un commit doit contenir **une seule idée ou une seule modification liée** ;
* le message doit respecter la forme `type(scope): description` ;
* le message doit permettre au relecteur de comprendre le changement en **moins d'une minute** ;
* une nouvelle fonctionnalité importante ne doit pas être mélangée avec une correction sans rapport ;
* avant de faire le commit, il faut toujours faire un **git status** pour voir l'état du travail.

Si le changement contient plusieurs idées différentes, il faut les séparer en plusieurs commits afin de faciliter la relecture.

## qui relit quoi

Pour la relecture, puisqu'il s'agit d'un projet collectif, un étudiant ne peut pas approuver son propre travail lui-même avant de l'intégrer dans le **main**.

Comme nous sommes quatre étudiants, nous définissons dès le début qui relit le travail de chacun en fonction de son rôle dans le projet.

* **Alice** → développement des nouvelles fonctionnalités (`feat/*`) → relue par **Bob**, qui travaille aussi sur la partie développement ;
* **Bob** → corrections et modifications techniques (`fix/*`) → relu par **Alice** ;
* **John** → documentation (`docs/*`) → relu par **Marie** ;
* **Marie** → tests et vérification de l'intégration → relue par **Bob**.

Ainsi, on ne demande pas à une personne qui travaille uniquement sur la documentation de relire une fonctionnalité technique qu'elle ne connaît pas. Le choix du relecteur dépend donc de la partie du projet sur laquelle il travaille et de sa capacité à comprendre la modification.

Le travail est proposé sous forme de **Pull Request**. Le relecteur doit vérifier le contenu du changement avant le merge. Tant que le relecteur désigné n'a pas approuvé la Pull Request, elle ne doit pas être fusionnée dans le **main**.

## ce qui est interdit

Pour la part des interdits dans un travail collectif :

* travailler directement sur la branche principale ;
* intégrer dans le **main** un travail qui n'a pas été relu ;
* fusionner sa propre branche avec le **main** ;
* faire des commits ambigus qui mélangent plusieurs idées dans une seule modification ;
* écraser le travail qui a déjà été intégré dans la branche principale avec **git push --force** ;
* effacer le commit d'une autre personne ou modifier volontairement l'historique partagé ;
* pousser volontairement un travail qui ne compile pas dans le but de le faire intégrer dans la branche principale ;
* faire un **git reset --hard** sur le **main**, car cette commande peut supprimer les modifications présentes dans le répertoire de travail ;
* mettre dans le dépôt des données secrètes comme les **mots de passe** ou les **clés d'accès**.

## ce qu'on fait quand quelqu'un casse la branche principale

Si quelqu'un casse la branche principale, on ne continue pas les intégrations comme si de rien n'était.

D'abord, la personne qui constate le problème doit **prévenir immédiatement les autres membres du groupe** afin que tout le monde sache que le **main** est temporairement bloqué.

Ensuite, le **responsable de l'intégration, Marie**, identifie le commit qui a provoqué le problème. Si ce commit doit être annulé, elle utilise :

```
git revert <commit>
```

Le `git revert` crée un nouveau commit qui annule les changements du commit responsable sans supprimer l'historique.

Après le revert, Marie vérifie que le projet fonctionne de nouveau normalement et que le code compile. Un autre membre du groupe doit également vérifier le résultat.

Tant que cette vérification n'est pas terminée, **aucune nouvelle intégration dans le main ne doit être faite**.

Une fois que le **main** est de nouveau fonctionnel et que la résolution a été vérifiée, les intégrations peuvent reprendre normalement avec les Pull Requests et les relectures prévues.
