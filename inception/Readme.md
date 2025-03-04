# Using Docker Compose used to harmonise NGINX, MariaDB and Wordpress docker files and set up their interdependant containers to run a Wordpress website.
![one-does-not-simply-say-well-it-worked-on-my-machine1](https://github.com/user-attachments/assets/351dc6fd-e8c7-4405-81ea-3411e9861f2b)

Survived my first dev-ops project! This project could've actually been fun if 42 hadn't added the extra level of virtualisation by requiring us to run the project within a virtual machine. That makes a machine running a virtual machine running 3 containers with their own virualised operating systems...

Otherwise, Docker is an absolute gamechanger! The possibilites feel endless...

Not an easy project to debug- one missed '/' can leave you in an endless loop within your MariaDB container wondering why your SQL commands don't execute. I had to add 'health checks' and other measures to make sure my containers waited for their dependancy containers before running. And, of course, 42 made us go the extra mile by not just learning docker-compose but creating our own individual Docker images from scratch first. Still, I enjoyed learning about docker and felt some serious satisfaction when my docker-compose commands set up, shut down and clean all the containers/ images/ volumes correctly.

**Resources:**
- [Docker video tutorial](https://www.youtube.com/watch?v=pg19Z8LL06w)
- [Docker Compose video tutorial](https://www.youtube.com/watch?v=SXwC9fSwct8)
- [Docker Compose in 16 minutes](https://www.youtube.com/watch?v=DM65_JyGxCo)
- [Inception tutorial](https://yahuitang227.notion.site/Inception-Tutorial-4bb342b48c5f45eb87ade95ee6361eb0#0ae33b792a8d4cb09a1f1742686f31cf)- skipped step 1 and used a recent Ubuntu .iso pour my VM. Don't get mixed up- the subjct states your containers must be built from the penultimate stable version of Alpine or Debian, not your VM. Steps 2-6 very useful for installing everything you need within your VM. Would recommend setting up VS code and connecting it with your GitHub to be able to work and push from within your VM during the project. Otherwise, this tutorial has great explanations in it, but I kept the structure of my project more concise and limited myself to only one script or config filer per container as it felt simpler.

**Reading:**
- _The Fraud_ by Zadie Smith.
