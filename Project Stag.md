Project Stag
---------------
Basically this is meant to be a shmup(maybe bullet hell) game where the player relies on melee for the main form of attacking.

---12/3/23---
Just want to jot down a few things im considering for the game atm. Ultimately there will have to be testing for these ideas to see which ones I actually like.
Gameplay
**Hitboxes**: I heard about shmups using circle colliders. I did a little looking around, but I don't see any examples of that. It could be interesting tho. However, I think I'm going to go with boxes
Player: The player will have two things. A sword and a sheild. Now one thing I'm trying to decide between having a charge attack when the button is held or rapid attacks. Maybe both? Just have an autofire button. It could
be pretty neat to have bullets and stuff that can be only effected by charged attacks. For the shielf: naturally it will block bullets, but perhaps there could be a way to shoot the bullets back? Either by directly reflecting the trajectory, absorbing the bullets and release homing things, or something completely different. Also, how will blocking be activated? Holding back like a fighting game, or a separate button?

Visuals: Basically I just want excuses to draw what i like seeing. In this game, at the moment, I am thinking medival with a touch of futuristic aesthetic.

Today's Goal:
-Box colliders independent from sprite size
-checkerboard background with shadow cuz funny?

---12/6/23---
Goal: today. collision?
the answer is mostly no. I now have a separate stuct that holds the collider data and seemingly works fine w/ the player, but when i tried to make a gizmo for the enemy its way off. i set the x = 1200 for the enemy but its suddenly 1263 when i run the game

---12/8/23---
Now have a collider struct, game objects have a list of them, colliders have 2 modes: 1 is hurtbox and 2 is hitbox. They also contain a bool that is meant to tell whether they are active or not. Right now the player has a hurtbox and a hitbox set up. the hitbox is only visible when an attack is initiated. I feel like this is a decent basis to build the collision system on (at least relatively speaking). However, there seems to be a couples issues. Most notably is the fact that the collider boxes' position don't update when the window is scaled. The other concern I have is the potential need for nested for loops. 

Visual: Root raised a pretty interesting idea. Having a sort of story book theme. Its certainly intriguing. I could work well w/ the medival fantasy aesthetic that I mentioned before