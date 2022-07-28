# push_swap
Visualisation of my sorting stack algorithm

![push_swap_50](https://user-images.githubusercontent.com/77667022/181585303-184953fa-c302-4ed0-9715-2eb3631b5b4e.gif)

Take a look at this -> https://phemsi-a.itch.io/push-swap
<img width="1191" alt="Capture d’écran 2022-07-28 à 17 18 36" src="https://user-images.githubusercontent.com/77667022/181585257-1e9f80cf-5523-4a67-8abe-4ed0c0c17c8c.png">
  A game to understand push_swap game -> https://phemsi-a.itch.io/push-swap
  
  The goal is to sort all the disk into the first stack.
  
  First:
    make && make bonus
  
  Then:
    ./push_swap 50 20 1 -2 30 40
These value represent the stack that you want to create, you can put all number that you want, but dont put 2 time one number
  
  
  
    ./push_swap 50 20 1 -2 30 40 | ./checker 50 20 1 -2 30 40
Display 'OK' if instruction sort the stack



    ./push_swap 50 20 1 -2 30 40 | ./checker 2
This display 'KO'
