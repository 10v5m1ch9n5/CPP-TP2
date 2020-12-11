# TP C++ n°2 : Héritage - Polymorphisme
## A faire :

- Trouver une solution sans `dynamic_cast` pour l'ajout d'un trajet dans un `TrajetCompose`
- Ajouter mots clés `const`, etc.
- Perfectionner l'affichage (couleurs, moyens de transports des trajets simples composant les trajets composés)
- Implémenter la recherche récursive

## Choix actuel de gestion de la mémoire :

- Compter le nombre de références à un trajet pour savoir quand appeler son destructeur (quand il n'a plus qu'une référence)
