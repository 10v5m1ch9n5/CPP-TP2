# TP C++ n°2 : Héritage - Polymorphisme
## A faire :

- Trouver une solution sans `dynamic_cast` pour l'ajout d'un trajet dans un `TrajetCompose`
- Ajouter mots clés `const`, `explicit`, `noexept`, etc.
- Créer les contructeurs de copie
- Fusionner les classes `ListeChainee` et `ListeChaineeGenerique`

## Description des classes

### Noeud

La classe `Noeud` permet de constituer les résultats de la recherche avancée sous forme d'arborescence.
Chaque Ainsi, chaque`Noeud` possède une liste chainée de `Noeud` enfants.

### ListeChaineeGenerique

Cette classe comme son nom l'indique est une liste chainée générique. En pratique elle ne sert qu'à collecter des objets `Noeud`.

### ChainonGenerique

Cette classe est utilisée par `ListeChaineeGenerique`. Elle représente un élément de la liste chainée, un "chainon" qui contient un élément de type générique (objet `Noeud` par exemple) et un pointeur vers le `ChainonGenerique` suivant dans la liste.

### ListeChainee

La classe `ListeChainee` possède un pointeur sur son premier et son dernier objet `Chainon`.
Elle est utilisée pour mettre en place des collections de `Trajet` dans des objets `TrajetCompose` ou `Catalogue`.
Elle possède des méthodes permettant de supprimer et d'ajouter des `Trajet` à la liste en surveillant l'évolution de sa taille.

## Difficultés rencontrées

### Gestion de la mémoire

Dans un premier temps, nous avions des fuites de mémoire car les destructeurs des différentes classes (surtout `ListeChainee`) ne libéraient pas tous leurs pointeurs.
Une fois les destructeurs corrigés, nous avons rencontré un second problème, il arrivait que des mêmes trajets soient détruits plusieurs fois.
Notamment lorsqu'un `TrajetSimple` appartenait à un `TrajetCompose`: son destructeur était appelé à la destruction du catalogue, mais aussi à celle du `TrajetCompose` le contenant.

Pour pallier ce nouveau problème, nous avons décidé de créer un copie d'un `TrajetSimple` lorsqu'il se trouvait ajouté à un `TrajetCompose`.
Ainsi, chaque `TrajetCompose` détruisait sa propre copie du `TrajetSimple` et le catalogue détruisait l'original.\
Cependant, le fait de créer une copie de `TrajetSimple` pour chaque référence qui lui est faite nous est vite paru comme un gâchis de mémoire.
D'autant plus qu'en ajoutant, des `TrajetCompose` au sein d'autres `TrajetCompose`, les copies se multiplieraient encore plus vite.

Nous avons donc choisi comme solution finale de compter dynamiquement le nombre de références faites à chaque `Trajet`et de n'appeler son destructeur par l'objet dont il dépend que lorsque celui-ci n'a plus qu'une référence (l'objet en question), le cas échéant on décrémente juste le nombre de références au `Trajet`.

### Boucles infinies avec `cin`

Lorsque l'utilisateur entre un caractère quelconque différent du caractère attendu (souvent un chiffre compris entre 1 et 4), les lectures clavier se désactivent et la boucle du main ne s'arrêtait plus, nous forçant à quitter le programme avec un signal externe.
Ce comportement très déroutant nous a longtemps mis en défaut, jusqu'à notre découverte de ce qu'est le *failbit* de cin :

https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected 