# Creating a 3D game using Wolfenstein-esque raycasting with my mate [KhaSmiley](https://github.com/KhaSmiley).

We made a thing which you can play!!

[cub3d_video.webm](https://github.com/lbarry9/42/assets/127246677/f6491efa-9dad-41ff-8c2e-de6b39e8b856)

![cub3d](https://github.com/lbarry9/42/assets/127246677/f1bb63fe-e391-4c96-89cf-1187c7d78d45)

Cub3d wasn't the easiest project to get my head around- even as someone who doesn't mind maths. I can't code if I don't fully understand what I'm doing and I split every project into babysteps- this was almost impossible on this project where everyone seems to code using one old tutorial and you have to code a bunch of functions in one go for the maths to work. I couldn't find resources which didn't skip over important steps in my understanding and, once I did, transforming the mathematical concepts into code (still in C) which was comprehensible AND debuggable was really difficult.

We ended up splitting the project into:
- parsing
- understanding the maths behing raycasting (trigonometry++)
- 2D movements and wall collisions
- 2D 'raycasting' where lines of pixels are projected from the player position and stop at walls in the map (this code isn't used in the end but it's an interesting step to go through anyway)
- 3D raycasting calculating wall height and using mlx_put_pixel to display a ceiling, floor and walls (big step)
- 3D raycasting with textures (images in xpm format) on the walls- replacing put_pixel with a screen buffer, using which you can directly update the colour each pixel of the screen

In the end I dipped in and out of lots of different resources and restarted my raycasting three times...
- I used [this site](https://demoman.net/?a=trig-for-games) to help understand the maths behing raycasting.
- [This video](https://www.youtube.com/watch?v=U0_ONQQ5ZNM) helped me visualise how the maths transforms into 3D images.
- [This video](https://www.youtube.com/watch?v=NbSee-XM7WA) is a nice intro into the DDA algorithm (not as complicated as its name makes it seem- it's basically just a way of saving computer resources by not checking for wall collisions at every pixel or every square of your map, but only at relevant square intersections).
- Here are some tutorials I used, though I found none of them sufficienly clear on its own once in the middle of the 3D raycasting part: [1](https://lodev.org/cgtutor/raycasting.html), [2](https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/), [3](https://medium.com/@rtailidounia/raycasting-in-cub3d-42-network-project-a-practical-tutorial-using-vectors-68eeb16b3de2). Would recommend renaming your variables and crossreferencing multiple raycasting codes if they're not that clear for you either.
- [Here's one very concise raycasting code](https://github.com/l-yohai/cub3d/blob/master/mlx_example/01_untextured_raycast.c) split into textured and untextured- interesting to play about with (though be careful not to mix up x and y as they have at certain points).

Excited to finally move on from C and to stop dreaming about x and y coordinates :upside_down_face:

**Reading:** _Grand Union_ Short stories by Zadie Smith.
