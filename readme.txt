----------------------------------------
-          MEMBRES DE L'EQUIPE         -
----------------------------------------

BAUDY Paul  - BAUP17019504
COCQ Elodie - COCE16529404


-----------------------------------------
-	FONCTIONNALITES AJOUTEES	-
-----------------------------------------

--> Question 1
Il existe deux types de recherche pour un agent poursuiveur:
- Il peut poursuivre l'agent avant lui dans le tableau d'agents
- Il peut chercher automatiquement le premier agent qu'il trouve dans son voisinage, 
tant qu'il n'en trouve pas, il est en wander. L'option "Automatic Follower Research",
présente dans l'onglet "Additionnal Options" permet de l'activer. Dans cet onglet, il
est aussi possible de tracer les segments permettant de visualiser la cible de chaque 
agent, lorsqu'il en a une.

--> Question 3
Lorsque les agents-poursuiveurs suivent simplement l'agent avant eux dans le tableau 
d'agents, l'ajout d'un deuxième leader implique que le premier ne sera plus jamais suivi.
Cependant, lorsque les agents-poursuiveurs sont en recherche automatique, le comportement 
lors de l'ajout d'un deuxième leader est plus aléatoire : en fonction de la position des 
véhicules, on aura soit une seule file suivant un des deux leaders, soit deux files suivant
chacune un leader. Dans l'onglet "Additionnal Options", il est possible d'activer l'option
"2 leaders", qui relance alors le jeu avec deux agents-leaders.

--> Question 4
Nous avons décidé que l'agent-leader contrôlé au clavier pouvait choisir de s'arrêter. Dans 
ce cas, on constate que les poursuiveurs ne s'arrêtent pas totalement derrière leur cible, 
il existe toujours un faible mouvement, bien que l'algorithme Arrive soit en place avec une 
poursuite en offset. Il est possible d'activer le contrôle d'un leader avec l'option "KeyBoard
Control" disponible encore une fois dans l'onglet "Additional Options". Le contrôle peut se 
faire avec les touches Z, Q et D ou bien avec les flèches directionnelles.

--> Question 5
Nous avons ajouté les différents choix de paramètres de contrôle de jeu dans l'onglet
"Additionnal Options", déjà mentionné dans les questions précédentes. Les véhicules sont 
dessinés en gras pour une meilleure visibilité ici. Un agent-poursuiveur est en bleu, un 
leader en Wander est en rouge, mais en vert s'il est contrôlé au clavier.