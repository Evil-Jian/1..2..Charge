# 1..2..Charge!

* [Introduction](#introduction)
* [For Users](#for-users)

## Introduction

1..2..Charge! is based on a childhood game played during my elementary years in the Philippines. It was made up by someone and it spread to different schools in the city. It is played with at least 2 players and doesn't have a max limit. It would play similar to a glorified version of rock paper scissors with each action having its own hand gesture. Each turn would start with players clapping eachothers hands with their right hand facing downwards and their left hand facing upwards. After a single clap, they clap eachothers hands going away from their chest. After such clap, they would proceed with the hand gesture that signifies their action. Each turn begins with the two clap gestures until someone wins.

***[This piece of software is my Networking subject. -Jian]***

## Game Rules

The rules for this game depended on the ruleset of the players of each school. Players win when the action they pick beats the opponent's action as based from the action chart. The game runs on an resource system called charges. Players' actions are dependent on the amount of charges they spend for each action. For this game, the server acts first, then the client. The actions are only revealed once both players have made their action.

| In-game code |          Move          |                                          Beats                                         |                          Loses to                         |                                 Draw                                 |
|:------------:|:----------------------:|:--------------------------------------------------------------------------------------:|:---------------------------------------------------------:|:--------------------------------------------------------------------:|
|       9      |   Black Hole, Cost: 5  | Plasma, Electric, Double Wave, Telewave, Wave, Double Shield, Teleport, Shield, Charge |                             -                             |                              Black Hole                              |
|       8      |     Plasma, Cost: 4    |               Electric, Double Wave, Wave, Double Shield, Shield, Charge               |                    Black Hole, Telewave                   |                           Plasma, Teleport                           |
|       7      |    Electric, Cost: 3   |                    Double Wave, Wave, Double Shield, Shield, Charge                    |                Black Hole, Plasma, Telewave               |                          Electric, Teleport                          |
|       6      |  Double Wave, Cost: 2  |                             Wave, Teleport, Shield, Charge                             |                Black Hole, Plasma, Electric               |                 Double Wave, Telewave, Double Shield                 |
|       5      |    Telewave, Cost: 2   |                        Plasma, Electric, Wave, Teleport, Charge                        |                         Black Hole                        |             Double Wave, Telewave, Double Shield, Shield             |
|       4      |      Wave, Cost: 1     |                                         Charge                                         |    Black Hole, Plasma, Electric, Double Wave, Telewave    |                 Wave, Double Shield, Teleport, Shield                |
|       3      | Double Shield, Cost: 1 |                                            -                                           |                Black Hole, Plasma, Electric               | Double Wave, Telewave, Wave, Double Shield, Teleport, Shield, Charge |
|       2      |    Teleport, Cost: 1   |                                            -                                           |             Black Hole, Telewave, Double Wave             |    Plasma, Electric, Wave, Double Shield, Teleport, Shield, Charge   |
|       1      |     Shield, Cost: 0    |                                            -                                           |         Black Hole, Plasma, Electric, Double Wave         |        Telewave, Wave, Double Shield, Teleport, Shield, Charge       |
|       0      |     Charge, Cost: 0    |                                            -                                           | Black Hole, Plasma, Electric, Double Wave, Telewave, Wave |                Double Shield, Teleport, Shield, Charge               |

## For users

**Quickstart**

1. `git clone <repository link>`
2. `cd <cloned repository directory>`
3. `make`
4. run server `./dist/server <port number>` e.g. `./dist/server 9999`
5. run client `./dist/client <server address> <port number>` e.g. `./dist/client 192.168.1.1 9999`

