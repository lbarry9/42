# Understanding IP Adresses and Subnetting

![image (2)](https://github.com/lbarry9/42/assets/127246677/1fb3c669-7b09-4621-bcc6-a9a90d9f93f8)

It was about time I dipped my toe into the magical, mysterious and frankly uninviting side of IT that turned me off it for years and years... And to be honest I found it a lot of fun! Netpractce was a nice quick project, perfect for people with busy brains who enjoy trying to do quick sums in their heads. What a nice respite after minishell- instant gratification and not a single line of code!

This [guy's videos](https://www.youtube.com/watch?v=5WfiTHiU4x8&list=PLIhvC56v63IKrRHh3gvZZBAGvsvOhwrRF&index=1) made my intro into this world much much less painful than it could've been with some of the very dry material out there. Would recommend watching this playlist and practicing converting between [IPv4 addresses](https://medium.com/coding-in-simple-english/a-beginners-guide-to-ipv4-and-ipv6-anatomy-fcc9444b0d4d) and binary. Thank you to mr [AmyYre](https://github.com/AmYre) for another excellent YouTube recommendation and for passing on your brilliantly simple logic for this project.

At the beginning it seems to all be about IP addresses but REALLY its all about the masks...

Take the IP address 166.43.223.12 for example. Using a mask of 255.255.255.0 means we have access to ALL the network addresses between 166.43.223.1 and 166.43.223.254 (.0 being the reserved for the network address and .255 for the broadcast address for this network). But the same network address with a mask of 255.255.255.128 only gives us access to the first half of the network. In this second case, giving the internet access (as is demanded in later levels) to the network 166.43.223.0/25 would mean the IP address 166.43.223.12 has internet access, but any IP address above 166.43.223.128 wouldn't. To give the _second half_ of the network access to internet we would have to give the internet _their_ network address: 166.43.223.128/25. Or give access to the whole network with 166.43.223.0/24. Dividing networks up in this way is called subnetting.

Amir's method which I stole for this project:
- First use the mask to calculate the chunks that you are splitting the network into: the chunk size is the difference bewteen 256 (max no of networks possible) and the first number in the mask which is different from 255. e.g. 255.255.255.252 --> 256-252 = 4 --> the network is split into chunks of 4 with 2 IP addresses available once you take away the network address (first in each chunk) and broadcast address (last in each chunk).
- When IP addresses are provided, figure out which chunk they are in. E.g. IP address 1.1.1.17 with a mask of 255.255.255.240 (chunks of 16) is in the 16-31 chunk. A mask of 255.255.192.0 tells us that since 192 is different from 255, the third _byte_ (see next point) of the network's IP addresses are split into chunks of 64 (256 - 192). The IP address 13.55.144.17, with a third byte of 144, falls into the 128-191 chunk. Since the fourth byte in the mask is .0, there are an extra 255 IP addreses to play with every time we change number in the third byte.
- Converting your masks between IPv4 addresses and binary will help you understand the /24 /30 /18 business. Imagine each number between the '.' is one byte. One byte can be written as 8 bits of either 1's or 0's. 1 means on and 0 means off. Once you've marked a bit as off the following bits are also off. Taking a set of numbers (powers of 2 which add up to a total of 255, in descending order left to right), imagine the first collumn as 128, the next as 64, 32, 16 etc etc. If you can take 128 away from your number without going into negatives, you mark it is on (1). You do this with the other numbers until you reach 0. (as seen below).

![Screenshot from 2024-05-02 22-46-20](https://github.com/lbarry9/42/assets/127246677/e59898c1-be85-4ba6-a581-3e4103870e11)
- These calculations ARE RELEVANT because it helps you calculate the /n numbers that you see when giving access to networks in the later levels. Writing a mask with the above logic in binary and counting the number of 1's you have is what GIVES you this number. E.g. 255.255.225.252 --> 11111111.11111111.11111111.11111100 --> (count the 1's) = /30. 255.255.225.252 --> 11111111.11111111.11000000.00000000. --> /18.

Eventually you get used to seeing the numbers 128, 64, 32, 16, 8 etc all the time and these calculations take a lot less time. Hope this helps anyone lost in the world of netpractice! Now go getpractice and try to solve them quicker than your pals! Have fun xo

Other useful repos/ tutorials
- [here](https://github.com/tblaase/Net_Practice?tab=readme-ov-file)
- [and here](https://github.com/lpaube/NetPractice)

**Reading:** _Grand Union_ collection of short stories by Zadie Smith
