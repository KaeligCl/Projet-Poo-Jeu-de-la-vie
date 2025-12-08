# Projet Jeu de la Vie 🎮

Le Jeu de la Vie est un automate cellulaire inventé par le mathématicien John Conway. Ce projet propose une implémentation en C++ du Jeu de la Vie en utilisant les concepts de la programmation orientée objet (POO). Dans ce jeu, une population de cellules, vivantes ou mortes, évolue sur une grille bidimensionnelle selon des règles simples :

- Une cellule morte possédant exactement trois voisines vivantes devient vivante.
- Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.

## Fonctionnalités

### Mode Console

- **Affichage des États des Cellules** : Affiche les états des cellules pour un nombre d'itérations donné.
- **Sortie Fichier** : Les résultats sont écrits dans des fichiers dans un dossier nommé `Fichier_test.txt`.

### Mode Graphique

- **Interface Graphique** : Affiche la grille de cellules dans une interface graphique basée sur la bibliothèque SFML.
- **Contrôle de la Simulation** : La simulation démarre automatiquement avec un contrôle sur la durée entre deux itérations.

## Extensions

- **Grille Torique** : Les cellules des bords opposés de la grille sont considérées comme adjacentes.
- **Cellules Obstacle** : Les cellules obstacles conservent leur état initial (vivant ou mort) tout au long de l'exécution.

## Exemple d'Utilisation

Pour compiler le programme :

```bash
g++ -o jeu_de_la_vie v02121342.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

Pour lancer le programme :

```bash
./jeu_de_la_vie
```

## Diagrammes :
Diagramme de Classe
<img width="1461" height="795" alt="image" src="https://github.com/user-attachments/assets/bd15fd5d-5d01-4466-bf6f-353d0bc878b4" />

Diagramme d'activité
<img width="788" height="1025" alt="image" src="https://github.com/user-attachments/assets/79200f11-dd09-4804-a68a-7bd35b41bae5" />

Diagramme de Séquence
<img width="697" height="1125" alt="image" src="https://github.com/user-attachments/assets/d26a8c40-8a19-4d6a-8579-d388159724c2" />

---

1. [Fonctionnalités](#fonctionnalités)
2. [Extensions](#extensions)
3. [Exemple d'Utilisation](#exemple-dutilisation)
4. [Diagrammes](#captures-décran)
   
