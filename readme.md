# TP C++ n°2 : Héritage - Polymorphisme
## A faire :

- Trouver une solution sans `dynamic_cast` pour l'ajout d'un trajet dans un `TrajetCompose`
- Ajouter mots clés `const`, etc.
- Perfectionner l'affichage (couleurs, moyens de transports des trajets simples composant les trajets composés)

## Description des classes

### Noeud

La classe `Noeud` permet de constituer les résultats de la recherche avancée sous forme d'arborescence.
Chaque Ainsi, chaque`Noeud` possède une liste chainée de `Noeud` enfants.

### ListeChaineeGenerique

Cette classe comme son nom l'indique est une liste chainée générique. En pratique elle ne sert qu'à collecter des objets `Noeud`.

### ChainonGenerique

Cette classe est utilisée par `ListeChaineeGenerique`. Elle représente un élément de la liste chainée, un "chainon" qui contient un élément de type générique (objet `Noeud` par exemple) et un pointeur vers le `ChainonGenerique` suivant dans la liste.

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