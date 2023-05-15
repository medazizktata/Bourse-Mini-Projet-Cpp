# Bourse-Mini-Projet-Cpp
Projet de classe Cpp
Projet de Simulation de Bourse
Ce projet de simulation de bourse est conçu pour permettre aux utilisateurs de simuler des transactions sur le marché boursier. Il offre la possibilité de créer une bourse virtuelle, d'effectuer des transactions d'achat et de vente d'actions, et de suivre l'évolution du portefeuille d'actions et du solde.

Fonctionnalités principales
Classe Date : Cette classe représente une date avec des fonctionnalités telles que la validation de la date, l'incrémentation et la décrémentation de la date, ainsi que des opérations de comparaison.

Classe PrixJournalier : Cette classe représente les informations d'un prix journalier d'une action, y compris la date, le nom de l'action et le prix. Elle offre des fonctionnalités pour obtenir et définir les valeurs de ces attributs.

Classe PersistancePrixJournaliers : Cette classe fournit des méthodes statiques pour lire les données des prix journaliers à partir d'un fichier dans trois structures de données différentes : vecteur, multimap et multiset.

Classe Bourse : Cette classe abstraite représente une bourse virtuelle et définit les méthodes principales pour obtenir le prix d'une action à une certaine date, récupérer la liste des actions disponibles à une date donnée, et effectuer des opérations sur le portefeuille.

Classe BourseVector : Cette classe dérive de la classe Bourse et implémente les méthodes spécifiques à la structure de données vecteur pour stocker les prix journaliers des actions.

Classe BourseSet : Cette classe dérive de la classe Bourse et implémente les méthodes spécifiques à la structure de données multiset pour stocker les prix journaliers des actions.

Classe BourseMultimap : Cette classe dérive de la classe Bourse et implémente les méthodes spécifiques à la structure de données multimap pour stocker les prix journaliers des actions.

Classe Titre : Cette classe représente une action avec un nom et une quantité. Elle offre des fonctionnalités pour obtenir et définir ces valeurs, ainsi que des opérations d'ajout et de retrait de quantité.

Classe Transaction : Cette classe représente une transaction effectuée sur une action, comprenant le type de transaction (achat, vente ou rien) et l'action associée. Elle fournit des méthodes pour obtenir et définir ces valeurs, ainsi qu'une conversion du type de transaction en chaîne de caractères.

Classe Portefeuille : Cette classe représente un portefeuille d'actions avec un solde et une liste d'actions possédées. Elle offre des fonctionnalités pour obtenir ces valeurs, alimenter le portefeuille avec un montant donné, effectuer des achats et des ventes d'actions, ainsi que l'exécution d'une transaction spécifique sur le portefeuille.

Classe Trader : Cette classe abstraite représente un trader qui prend des décisions sur les transactions à effectuer. Elle définit une méthode abstraite pour choisir une transaction à effectuer.

Classe Trader_aleatoire : Cette classe dérive de la classe Trader et implémente la méthode de choix de transaction de manière aléatoire

Classe Simulation : Cette classe permet de simuler le fonctionnement d'une bourse en utilisant des traders et un portefeuille. Elle initialise les différentes instances nécessaires, exécute les transactions en fonction des décisions des traders, et affiche les résultats de la simulation.
Comment utiliser le projet
Assurez-vous d'avoir installé un compilateur C++ compatible sur votre système.
Clonez ce dépôt GitHub sur votre machine locale.
Compilez le code source à l'aide de votre compilateur C++ en exécutant la commande g++ main.cpp -o simulation.
Exécutez le programme en utilisant la commande ./simulation.
Suivez les instructions affichées pour effectuer des transactions et observer les résultats de la simulation.
Contributions
Les contributions à ce projet sont les bienvenues. Si vous souhaitez ajouter de nouvelles fonctionnalités, corriger des bogues ou améliorer la documentation, n'hésitez pas à ouvrir une demande de pull. Veuillez vous assurer de suivre les meilleures pratiques de développement et d'ajouter des tests appropriés lorsque cela est nécessaire.

Licence
Ce projet est sous licence MIT. Vous êtes libre de l'utiliser, le modifier et le distribuer selon les termes de la licence. Référez-vous au fichier LICENSE pour plus d'informations.

Avertissement
Ce projet est une simulation de bourse et ne traite pas de transactions réelles sur le marché boursier. Les résultats obtenus dans cette simulation ne doivent pas être considérés comme des conseils financiers ou des indications de performances futures. Utilisez-le à des fins éducatives et expérimentales uniquement.
