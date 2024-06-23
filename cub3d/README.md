# Creating a 3D game using Wolfenstein-esque raycasting with my mate [KhaSmiley](https://github.com/KhaSmiley).

We made a thing which you can play!!

[cub3d_video.webm](https://github.com/lbarry9/42/assets/127246677/f6491efa-9dad-41ff-8c2e-de6b39e8b856)

![cub3d](https://github.com/lbarry9/42/assets/127246677/f1bb63fe-e391-4c96-89cf-1187c7d78d45)

Cub3d wasn't the easiest project to get my head around- even as someone who doesn't mind maths. I can't code if I don't fully understand what I'm doing and I split every project into babysteps- this was almost impossible on this project where everyone seems to code using one old lodev tutorial and you have to code a bunch of maths functions in one go to see any result on screen. I couldn't find resources which didn't skip over important steps in my understanding and, once I did, transforming the mathematical concepts into code (still in C) was really difficult. Big thanks to [Sefir](https://github.com/SefirOutin) for helping me flip my textures around and fix some extremely hard to pinpoint bugs.

**We ended up splitting the project into:**
- parsing
- understanding the maths behing raycasting (trigonometry++)
- 2D movements and wall collisions
- 2D 'raycasting' where lines of pixels are projected from the player position and stop at walls in the map (this code isn't used in the end but it's an interesting step to go through anyway)
- 3D raycasting with block coloured walls- calculating wall height and using mlx_pixel_put to display a ceiling, floor and walls in different colours
- checking player FOV rotations work and that wall colours match up with the direction in which the player spawns (N, E, S or W)
- 3D raycasting with wall textures (images in xpm format)- replacing put pixel with a screen buffer (essentially a pointer to the memory address for every pixel of your computer screen, using which you can directly update each pixel's colour using all your previous calculations and texture info)
- we added a function which allows you to rotate the player's FOV using the mouse cursor instead of the keyboard arrows

***In the end I dipped in and out of lots of different resources and restarted my raycasting three times...***
- I used [this site](https://demoman.net/?a=trig-for-games) to help understand the maths behing raycasting.
- [This video](https://www.youtube.com/watch?v=U0_ONQQ5ZNM) helped me visualise how the maths transforms into 3D images.
- [This video](https://www.youtube.com/watch?v=NbSee-XM7WA) is a nice intro into the DDA algorithm (not as complicated as its name makes it seem- it's basically just a way of saving computer resources by not checking for wall collisions at every pixel or every square of your map, but only at relevant square intersections).
- Here are some tutorials I used, though I found none of them sufficienly clear on its own once in the middle of the 3D raycasting part: [1](https://lodev.org/cgtutor/raycasting.html), [2](https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/), [3](https://medium.com/@rtailidounia/raycasting-in-cub3d-42-network-project-a-practical-tutorial-using-vectors-68eeb16b3de2), [4](https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf). Would recommend renaming your variables and crossreferencing multiple raycasting codes if they're not that clear for you either.
- [Here's one very concise raycasting code](https://github.com/l-yohai/cub3d/blob/master/mlx_example/01_untextured_raycast.c) split into textured and untextured- interesting to play about with (though be careful not to mix up x and y as they have at certain points).

Excited to finally move on from C and to stop dreaming about x and y coordinates :upside_down_face:

**Reading:** _Grand Union_ Short stories by Zadie Smith.
