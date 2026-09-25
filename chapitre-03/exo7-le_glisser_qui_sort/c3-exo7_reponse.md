# EXERCICE 7:
Pour cet exercice nous allons commencer avec l'experience sans capture et pour verifier le deplacement de la souris dans la fenetre nous allons utiiser cette portion de code:
```cpp
events.AddEventCallback<NkMouseMoveEvent>(
        [&](NkMouseMoveEvent *e) {
            std::cout << "Souris : "
                << e->GetX()
                << " ; "
                << e->GetY()
                << std::endl;
        }
    );
```

qui affichera les positions de la souris a chaque deplacement:
## SANS CAPTURE

Lorsqu'on lane le rendu, on obtient ceci:
```
Souris : 934 ; 744
Souris : 915 ; 719
Souris : 899 ; 691
Souris : 893 ; 682
Souris : 879 ; 651
Souris : 861 ; 592
Souris : 854 ; 553
Souris : 848 ; 504
Souris : 842 ; 461
Souris : 842 ; 417
Souris : 851 ; 341
Souris : 857 ; 298
Souris : 869 ; 247
Souris : 883 ; 201
Souris : 914 ; 124
Souris : 935 ; 83
Souris : 962 ; 35
Souris : 986 ; 3
Souris : 1290 ; 4
Souris : 1296 ; 11
Souris : 1301 ; 15
Souris : 1310 ; 24
Souris : 1315 ; 31
Souris : 1322 ; 40
Souris : 1326 ; 45
Souris : 1328 ; 46
Souris : 1332 ; 50
Souris : 1335 ; 52
Souris : 1339 ; 54
Souris : 1342 ; 57
Souris : 1347 ; 60
Souris : 1350 ; 62
Souris : 1351 ; 63
Souris : 1353 ; 64
Souris : 1356 ; 65
Souris : 1358 ; 66
Souris : 1359 ; 66
Souris : 1359 ; 65
Souris : 1360 ; 65
Souris : 1362 ; 64
Souris : 1366 ; 63
Souris : 1369 ; 62
Souris : 1372 ; 62
Souris : 1376 ; 61
Souris : 1379 ; 60
Souris : 1381 ; 59
Souris : 1385 ; 56
Souris : 1386 ; 56
Souris : 1387 ; 55
Souris : 1399 ; 54
Souris : 1411 ; 51
Souris : 1436 ; 48
Souris : 1462 ; 42
Souris : 1477 ; 39
Souris : 1492 ; 34
Souris : 1502 ; 30
Souris : 1506 ; 27
Souris : 1508 ; 26
Souris : 1508 ; 25
Souris : 1508 ; 24
Souris : 1506 ; 23
Souris : 1498 ; 19
Souris : 1485 ; 15
Souris : 1456 ; 6
Souris : 1436 ; 4
Souris : 1414 ; 3
Souris : 1408 ; 3
Souris : 1386 ; 3
Souris : 1367 ; 5
Souris : 1344 ; 14
Souris : 1338 ; 16
Souris : 1335 ; 19
Souris : 1334 ; 21
Souris : 1334 ; 23
Souris : 1336 ; 26
Souris : 1338 ; 29
Souris : 1339 ; 30
Souris : 1344 ; 33
Souris : 1352 ; 37
Souris : 1360 ; 38
Souris : 1372 ; 38
Souris : 1388 ; 38
Souris : 1391 ; 38
Souris : 1407 ; 37
Souris : 1419 ; 36
Souris : 1431 ; 34
Souris : 1432 ; 31
Souris : 1433 ; 30
Souris : 1433 ; 29
Souris : 1432 ; 24
Souris : 1426 ; 17
Souris : 1411 ; 4
Souris : 1271 ; 4
Souris : 1271 ; 8
Souris : 1272 ; 12
Souris : 1274 ; 16
Souris : 1275 ; 17
Souris : 1283 ; 22
Souris : 1289 ; 24
Souris : 1302 ; 27
Souris : 1313 ; 27
Souris : 1326 ; 27
Souris : 1335 ; 26
Souris : 1349 ; 24
Souris : 1361 ; 21
Souris : 1369 ; 17
Souris : 1374 ; 14
Souris : 1376 ; 12
Souris : 1379 ; 8
Souris : 1380 ; 6
Souris : 1381 ; 1
Souris : 1244 ; 13
Souris : 1228 ; 29
Souris : 1219 ; 39
Souris : 1207 ; 57
Souris : 1202 ; 69
Souris : 1199 ; 81
Souris : 1201 ; 85
Souris : 1201 ; 86
Souris : 1203 ; 90
Souris : 1209 ; 92
Souris : 1214 ; 93
Souris : 1221 ; 93
Souris : 1227 ; 90
Souris : 1233 ; 88
Souris : 1234 ; 87
Souris : 1234 ; 85
Souris : 1228 ; 82
Souris : 1221 ; 78
Souris : 1206 ; 73
Souris : 1163 ; 61
Souris : 1133 ; 54
Souris : 1122 ; 52
Souris : 1084 ; 45
Souris : 1047 ; 39
Souris : 982 ; 32
Souris : 953 ; 32
Souris : 917 ; 35
Souris : 896 ; 41
Souris : 879 ; 46
Souris : 860 ; 55
Souris : 852 ; 59
Souris : 847 ; 62
Souris : 844 ; 63
Souris : 843 ; 63
Souris : 844 ; 63
Souris : 835 ; 63
Souris : 823 ; 63
Souris : 813 ; 63
Souris : 787 ; 63
Souris : 766 ; 63
Souris : 729 ; 63
Souris : 704 ; 63
Souris : 666 ; 61
Souris : 636 ; 59
Souris : 577 ; 56
Souris : 548 ; 54
Souris : 516 ; 51
Souris : 496 ; 50
Souris : 475 ; 48
Souris : 3 ; 663
Souris : 2 ; 683
Souris : 2 ; 698
Souris : 2 ; 715
Souris : 2 ; 727
Souris : 2 ; 744
Souris : 2 ; 763
Souris : 2 ; 778
Souris : 2 ; 805
Souris : 235 ; 958
Souris : 271 ; 938
Souris : 329 ; 909
Souris : 407 ; 880
Souris : 564 ; 834
Souris : 665 ; 815
Souris : 694 ; 810
Souris : 802 ; 796
Souris : 909 ; 789
Souris : 980 ; 786
Souris : 1073 ; 781
Souris : 1174 ; 781
Souris : 1240 ; 782
Souris : 1280 ; 788
Souris : 1299 ; 790
Souris : 1320 ; 797
Souris : 1329 ; 802
Souris : 1331 ; 806
Souris : 1367 ; 756
Souris : 1461 ; 635
Souris : 1517 ; 571
Souris : 1579 ; 504
Souris : 1619 ; 460
Souris : 1671 ; 415
Souris : 1705 ; 393
Souris : 1727 ; 381
Souris : 1750 ; 376
Souris : 1759 ; 377
Souris : 1761 ; 377
Souris : 1785 ; 347
Souris : 1793 ; 337
Souris : 1813 ; 306
Souris : 1852 ; 246
Souris : 1873 ; 209
Souris : 1891 ; 175
Souris : 1903 ; 151
Souris : 1917 ; 120
Souris : 1919 ; 112
Souris : 1919 ; 87
Souris : 1919 ; 67
Souris : 1919 ; 57
Souris : 1919 ; 45
Souris : 1919 ; 43
Souris : 1919 ; 30
Souris : 1919 ; 18
Souris : 1918 ; 1
```
Il faut noter ici que quand vous voyez une position de x ou y se rapprochant de 1 alors c'est juste la souris qui sort de la fenetre.

### REMARQUE
Lorsqu'on nous sommes dans la fentre, on remarque que le systeme releve bin les differentes positions de la souris et quand on sort il ne recoit lses positions donc hors de la fenetre, on dirait que pour lui la souris a disparu.  
Du point de vue de l'utilisateur, le glisser commencé dans la fenêtre ne se poursuit donc pas correctement une fois la souris sortie.

## AVEC CAPTURE
Pour cette partie, il a fallu que je me serve des fichiers tels que: NKEvent/NkMouseEvent.h, NKEvent/NkEventState.h et de NkWin32Window.cpp. Donc j'ai rmaarque ube fonction  qui parlait deja des mousecapture et puis dans mon code j;ai une fois integrer ceci:
```cpp
 events.AddEventCallback<NkMouseMoveEvent>(
        [&](NkMouseMoveEvent *e) {
            events.AddEventCallback<NkMouseButtonPressEvent>(
                [&](NkMouseButtonPressEvent *e) {
                    if (e->IsLeft()) {
                        std::cout << "Clic gauche : capture active" << std::endl;
                        window.CaptureMouse(true);
                    }
                }
            );
            std::cout << "Souris : "
                << e->GetX()
                << " ; "
                << e->GetY()
                << std::endl;
            events.AddEventCallback<NkMouseButtonReleaseEvent>(
                [&](NkMouseButtonReleaseEvent *e) {
                    if (e->IsLeft()) {
                        std::cout << "Clic gauche : capture liberee" << std::endl;
                        window.CaptureMouse(false);
                    }
                }
            );
        }
    );

```
Et lorsque je construit puis j'execute, mon executable donne ceci:
```
Souris : 318 ; 317
Souris : 316 ; 316
Souris : 313 ; 313
Souris : 311 ; 310
Souris : 309 ; 308
Souris : 306 ; 304
Souris : 306 ; 303
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Clic gauche : capture active
Souris : 454 ; 316
Souris : 468 ; 313
Souris : 498 ; 306
Souris : 518 ; 302
Souris : 541 ; 295
Souris : 1238 ; 189
Souris : 1242 ; 192
Souris : 1244 ; 193uris : 95 ; 340
Souris : 85 ; 339
Souris : 73 ; 335
Souris : 67 ; 334
Souris : 61 ; 333
Souris : 56 ; 332
Souris : 50 ; 332
Souris : 45 ; 332
Souris : 40 ; 332
Souris : 34 ; 332
Souris : 25 ; 332
Souris : 3 ; 335
Souris : -17 ; 342
Souris : -38 ; 347
Souris : -57 ; 355
Souris : -83 ; 365
Souris : -94 ; 370
Souris : -102 ; 373
Souris : -106 ; 375
Souris : -110 ; 378
Souris : -113 ; 379
Souris : -114 ; 380
Souris : -118 ; 380
Souris : -120 ; 380
Souris : -124 ; 381
Souris : -127 ; 381
Souris : -130 ; 382
Souris : -134 ; 384
Souris : -136 ; 384
Souris : -139 ; 384
Souris : -141 ; 384
Souris : -143 ; 384
Souris : -144 ; 384
Souris : -147 ; 384
Souris : -155 ; 384
Souris : -156 ; 384
Souris : -159 ; 384
Souris : -160 ; 384
Souris : -161 ; 384
Souris : -162 ; 384
Souris : -165 ; 384
Souris : -168 ; 384
Souris : -172 ; 384
Souris : -174 ; 384
Souris : -176 ; 384
Souris : -179 ; 385
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Clic gauche : capture liberee
Souris : 1211 ; 126
Souris : 1230 ; 123
Souris : 1250 ; 118
Souris : 1264 ; 114
Souris : 1278 ; 109
Souris : 1278 ; 7
Souris : 1275 ; 6
Souris : 1271 ; 4
Souris : 1269 ; 4
Souris : 1265 ; 3
Souris : 1261 ; 2
Souris : 1258 ; 1
Souris : 1256 ; 0
```

### REMARQUE
Et on remarque dons que meme hors de la fenetre, on coninue toujours a repere les poisition de la souris.
Selon le point de viue de l'observateur, le glisser qui commence et continue a l'exterieur poursuit correctemnt la souris.

## NB
_je n'ai pas tout mis les executables car ils etaient tellement long_

## CONCLUSION (DIFFERENCE)
| Sans capture                            | Avec capture                          |
| --------------------------------------- | ------------------------------------- |
| Souris suivie dans la fenêtre           | Souris suivie même hors de la fenêtre |
| Sortie de la fenêtre → suivi interrompu | Sortie de la fenêtre → suivi continue |
| Pas de capture                          | Capture active pendant le clic        |
| Adapté aux mouvements simples           | Utile pour le glisser-déposer         |
