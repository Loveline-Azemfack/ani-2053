# EXERCICE 12: REGLES GIT D'UN PROJET

## nommage des branches
Avant tout il faut d'abord que le nom d'une brance doit rfleter son role, cela veut dire que lorsqu;une personnne veux travailler dans une branche que le nom lui permette de savoir ce qu'elle doit ou ne pa sfaire dans le branche.  Ainsi notons ceci:  
Branches principales : 
main      → Production 

La branche de production c'est d'abord la branche principale donc le **main** et ils ne devront pas travailler directement dessus, donc on peut utiliser cette convention ci pour nommer les branches:
```
feat/user-authentication
fix/login-error-message
docs/update-installation
```
Ici, 
- feat(feature) renvoie aux nouvelles fonctionnalites
- fix ici sera utiliser pour les corrections, c'est donc la qu'on arrete de nommer les branches un peu comme **modification1** 
- docs ici c'est pour la documentation

Donc ici, l'objectif de nommer les branches c'est pour eviter de travailler directement dans la branche principale et ne pas ecraser le travail des autres, donc mieux chacun fait ce qu'il a a faire dans sa branche et lorsqu'il va pousser sur github, si le chef de projet voit que sa modification est necessaire, on integrera cette derniere dans la branche principale

## contenu d'un commit
En ce qui concerne le contenu de commit, ils devront utiliser une version commune pour que chaque modification puisse etre explicite lors du **push** donc ils peuvent ecrire leur contenu de cette convention:
```
type (scope): description
```
* leurs commits ne doivent pas ausssi etre trop longs ca doit etre court, clair et explicite

Par exemple si j'ai modifier qulque chose dans la branche docs je mets
```
docs (readme): fix typo introduction"
```
la le type est docs et c'est dans le readme qu'il y a eu une modification et il decrit qu'il a modifier une faute de frappe dans l'intoduction. La on voit bien ce que peut contenir le changement du fichier a ce moment la.
* Avant de commit il faut toujours faire un **git status** pour voir l'etat de son travail  
* Chaque ajout de nouvelles fonctionnalites doit avoir son propre commit, ne pas melanger plusieurs idees afin de ne pas embrouiller son relecteur

## qui relit quoi

Pour la relecture, puisqu'il s'agit d'un projet collectif, un seul etudiant ne peut pas approuver son propre travail lui meme seul, il doit aussi avoir l'avis des autres avant de l'integrer dans le main, c'est donc pour ca que chaque fois qu'un etudiant fera une modification, l'etudiant pouvant relire et comprendre ses modifiations devra  le faire afin de voir si il y a des incoherences ou pas.
Le travail peut être proposé sous forme de **Pull Request** afin que l'autre étudiant puisse effectuer la relecture avant le merge. **Donc avant tout il faudra definir quii devra relire une modification de type (feat, docs ou encore fix) ou du moins etablir un autre critere de choix  fonction de son travail et de ses performance car on ne peut pas dire a une personne qui est centree sur la partie documentation de relire le travail d'une personne qui a fait une modification de tupe 'feat'** , donc on devra faire de telle sorte que si c'est l'etudiant **bob** par exemple qui doit relire le travail de l'etudiant **john** qu'on attende d'aord son approbation avant d'integrer le travail de john dans le main.

##  ce qui est interdit
Pour la part des interdits dans un travail collectif :
* La premiere des chose est travailler sur la branche principale;
* integrer dans le main un travail qui n'a pas ete relus
* Faire des commits ambigue, ceux qui melangent plusieurs idees dans ue seule description
* Fusionner sa propre banche avec main
* ecraser le travail qui a deja ete integrer dans la branche principae avec **git push --force** 
* effacer le commit d'une autre personnes ou pour l'historique du travail 
* pousser un travail qui ne compile pas consciement a vouloir qu'on l'integre dans la branche principale
* faire un **git reset --hard** sur le main, car le **--hard** detruit et c'est l'une des commandes les plus dangereuse dans un travail collectif;

* Ne pas mettre ses donnees securiser dans un depot un peu comme **les mots de passe, les cles d'acces** 
## ce qu'on fait quand quelqu'un casse la branche principale
Pour cette partie il y a pas deux chose que deux faire recours directement au **git revert** avec l'accord des autres membres, car il faut d'abord identifier le commit qui a provoque cela et  si on trouve que ca a plus fait du mal que de bien, utiliser un **git revert** et puis on doit verifier que le projet fonctionne toujours normalement 
