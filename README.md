# push_swap
Visualisation of my sorting stack algorithm

![push_swap_50](https://user-images.githubusercontent.com/77667022/181585303-184953fa-c302-4ed0-9715-2eb3631b5b4e.gif)

Take a look at this -> https://phemsi-a.itch.io/push-swap
<img width="1191" alt="Capture d’écran 2022-07-28 à 17 18 36" src="https://user-images.githubusercontent.com/77667022/181585257-1e9f80cf-5523-4a67-8abe-4ed0c0c17c8c.png">
  A game to understand push_swap game -> https://phemsi-a.itch.io/push-swap
  
  The goal is to sort all the disk into the first stack.
  
  1: Compil project :arrow_down: :arrow_down: :arrow_down:
  
    make && make bonus
  
  2: These value represent the stack that you want to create, you can put all number that you want, but dont put 2 time one number: :arrow_down: :arrow_down: :arrow_down:
  
    ./push_swap 50 20 35 21 1
    ./push_swap 999 22 99 33 88 4 0 -2 8876 5678909876543 -4

An image explain better : 

<img width="248" alt="stack" src="https://user-images.githubusercontent.com/77667022/181591697-e9077271-3497-4231-90c0-4fa54a08ff95.png">

the output is the instruction to sort the stack: 50 20 35 21 1 (equivalent to 5 2 4 3 1)

    rra
    pb
    ra
    pb
    sa
    pa
    pa

  3: Display 'OK' if instruction sort the stack :arrow_down: :arrow_down: :arrow_down:
    
    ./push_swap 50 20 1 -2 30 40 | ./checker 50 20 1 -2 30 40

  4: This display 'KO' :arrow_down: :arrow_down: :arrow_down: 
    
    ./push_swap 50 20 1 -2 30 40 | ./checker 2

