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
pr�sente dans l'onglet "Additionnal Options" permet de l'activer. Dans cet onglet, il
est aussi possible de tracer les segments permettant de visualiser la cible de chaque 
agent, lorsqu'il en a une.

--> Question 3
Lorsque les agents-poursuiveurs suivent simplement l'agent avant eux dans le tableau 
d'agents, l'ajout d'un deuxi�me leader implique que le premier ne sera plus jamais suivi.
Cependant, lorsque les agents-poursuiveurs sont en recherche automatique, le comportement 
lors de l'ajout d'un deuxi�me leader est plus al�atoire : en fonction de la position des 
v�hicules, on aura soit une seule file suivant un des deux leaders, soit deux files suivant
chacune un leader. Dans l'onglet "Additionnal Options", il est possible d'activer l'option
"2 leaders", qui relance alors le jeu avec deux agents-leaders.

--> Question 4
Nous avons d�cid� que l'agent-leader contr�l� au clavier pouvait choisir de s'arr�ter. Dans 
ce cas, on constate que les poursuiveurs ne s'arr�tent pas totalement derri�re leur cible, 
il existe toujours un faible mouvement, bien que l'algorithme Arrive soit en place avec une 
poursuite en offset. Il est possible d'activer le contr�le d'un leader avec l'option "KeyBoard
Control" disponible encore une fois dans l'onglet "Additional Options". Le contr�le peut se 
faire avec les touches Z, Q et D ou bien avec les fl�ches directionnelles.

--> Question 5
Nous avons ajout� les diff�rents choix de param�tres de contr�le de jeu dans l'onglet
"Additionnal Options", d�j� mentionn� dans les questions pr�c�dentes. Les v�hicules sont 
dessin�s en gras pour une meilleure visibilit� ici. Un agent-poursuiveur est en bleu, un 
leader en Wander est en rouge, mais en vert s'il est contr�l� au clavier.