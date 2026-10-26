Examen de programmation C++ : 
  Exercice 1 /
    1. Résultat affiché
      15 20
    a est une référence sur x, donc x passe de 10 à 15. b est une copie de y, donc y reste à 20.
    2. Passage par valeur vs par référence
    Par valeur : la fonction reçoit une copie de la variable.
    Les modifications faites dans la fonction n’affectent pas la variable d’origine.
    Par référence : la fonction reçoit un alias de la variable d’origine.
    Les modifications faites dans la fonction affectent directement la variable d’origine, et il n’y a pas de copie.
    3. Fonction modifiée
    cpp
    void modifier(int &a, int &b) {
    a += 5;
    b += 10;
    }
    Le programme affiche alors 15 30.
    4. Rôle de &
    Dans la déclaration d’un paramètre, & indique que le paramètre est une référence, 
    c’est-à-dire un autre nom pour la variable passée en argument.
    La fonction travaille donc sur l’original et non sur une copie.
    Cela évite aussi une copie coûteuse pour les gros objets.

  Exercice 2 / 
    <img width="960" height="540" alt="Ex2" src="https://github.com/user-attachments/assets/b604e927-6afc-4915-95bd-4899c12e3152" />

  Exercic 3 /
    6. Pourquoi le destructeur de Vehicule doit être virtual
Quand on fait delete sur un pointeur Vehicule* qui pointe vers un objet dérivé (Voiture ou Camion) 
et que le destructeur n’est pas virtuel,
seul le destructeur de Vehicule est appelé. 
Le destructeur de la classe dérivée est ignoré.
C’est un comportement indéfini, qui provoque des fuites mémoire et des ressources non libérées.
Avec un destructeur virtual,
la liaison dynamique appelle d’abord le destructeur de la classe dérivée,
puis celui de la classe mère, et l’objet est détruit correctement.
  
    <img width="960" height="540" alt="Ex3" src="https://github.com/user-attachments/assets/07dea3f7-c4f0-4c97-9bb6-c47ac7a590b8" />
