# Coding a solution to the Dining Philosophers problem

If you're unfamiliar with the Dining Philosophers problem have a look [here.](https://www.geeksforgeeks.org/dining-philosophers-problem/)

This [project](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2) is a nice follow-on from pipex. Now instead of creating multiple simultaneous processes using forks, we have to run multiple threads within one single process. I like to think about forked processes as lots of identical rooms with one person doing an activity in each room, whereas threads are like lots of people all doing the same activity in the same room. If you move the furniture around in a forked room, your neighbour's furniture won't move. But as a thread, if you change the furniture in the room, everyone's furniture changes.

Anyway, learning about threads and mutexes was pretty cool. CodeVault saved me again with his [videos.](https://www.youtube.com/watch?v=IKG1P4rgm54)

Creating a basic project which works was relatively quick but it's easy to get stuck once you start checking if your philosophers should have died or not... suddenly you end up with 14234385 mutexes all over the place.

**Tips:**
- Don't group variables together to minimise mutexes- give every incrementable variable its own mutex.
- Mutexes should be locked and unlocked **every time** its associated variable is read, incremented or even simply used in a condition.
- Cases with very little time to eat and sleep are important but don't overlook cases where there is plenty of time. In cases where time_to_die > time_to_eat + time_to_eat, try to use you usleeps effectively to reduce any time that your philo threads spend waiting at a mutex as they might accidentally get access to a fork too early and mess up the flow of it all.
- Here's a [visualiser](https://nafuka11.github.io/philosophers-visualizer/) and [tester](https://github.com/Rz-Rz/thales_tester) to help finish the project.
- I didn't have time for the bonuses, but this [repo's](https://github.com/lavrenovamaria/42-philosophers) cat memes seem to be an unrivaled way to get to grips with the differences between mutexes and semaphors.

![137924710-f11fbc8f-c92a-410e-bc53-db926ddeec7a](https://github.com/lbarry9/42/assets/127246677/589bcc1b-c0c6-42a6-9baa-eec1a62a99a5)

Feels good to FINALLY be over exam_02 and in a new circle! Time for mini_hell...

(still) Reading:
_The Goldfinch_ by Donna Tartt
