# EscapeMaze

The problem we will solve is the problem of finding a path to the end of a maze. The maze can take various forms, such as a two-dimensional grid, continuous terrain, or even a space with more than three dimensions. In our case, the maze will be like a two-dimensional chessboard. We will use the Depth First Search (DFS) algorithm to find the maze's exit. DFS is an algorithm that, among the possible paths, chooses one and continues along it until it reaches the end or exhausts all possible paths. When it reaches a "dead end," the algorithm backtracks to the last decision point and chooses the next path. It continues this process until it finds the maze's end or no more paths are available. The DFS algorithm is named after its depth-first traversal through the maze, momentarily ignoring other paths, similar to a person navigating the maze.
## Getting Started

To use EscapeMaze, follow the instructions below:

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Installation

1. Clone the repository

  ```bash
  git clone https://github.com/lfelipediniz/EscapeMaze.git
  ```

2. Navigate to the project directory

  ```bash
  cd EscapeMaze
  ```

### Usage

1. Compile and run the program using the provided Makefile

  ```bash
  make
  ```

2. Execute the program (with either of the two commands)

  ```bash
  make run
  ```

3. To delete the generated files run

  ```bash
  make clean
  ```

### Explaining the use in more detail

The program's input consists of specifying the number of rows and columns in the matrix. Subsequently, you input all the matrix data, where 0 denotes maze walls, 1 signifies a pathway, and 2 represents the exit point of the maze.

## Test case

### Case 1

<table align="center">
<thead>
<tr>
<th>Input</th>
<th>Output</th>
</tr>
</thead>
<tbody>
<tr>
<td>3 3 <br>
1 1 1 <br>
1 0 1 <br>
1 1 2 <br>
</td>
<td> 
(0, 0) <br>
(0, 1)<br>
(0, 2) <br>
(1, 2) <br>
(2, 2)<br>
</td>
</table>

### Case 2
<table align="center">
<thead>
<tr>
<th>Input</th>
<th>Output</th>
</tr>
</thead>
<tbody>
<tr>
<td>3 3 <br>
1 1 1 <br>
1 0 0 <br>
1 1 2 <br>
</td>
<td> 
(0, 0) <br>
(0, 1) <br>
(0, 2) <br>
(1, 0) <br>
(2, 0) <br>
(2, 1) <br>
(2, 2) <br>
</td>
</table>

### Case 3

<table align="center">
<thead>
<tr>
<th>Input</th>
<th>Output</th>
</tr>
</thead>
<tbody>
<tr>
<td>5 6 <br>
1 1 1 1 0 1 <br>
1 0 1 0 0 1<br>
1 1 1 1 1 1<br>
1 0 1 0 0 1<br>
2 1 0 0 1 1<br>
</td>
<td> 
(0, 0) <br>
(0, 1)<br>
(0, 2)<br>
(0, 3)<br>
(1, 2)<br>
(2, 2) <br>
(2, 3)<br>
(2, 4)<br>
(2, 5)<br>
(1, 5)<br>
(0, 5)<br>
(3, 5)<br>
(4, 5)<br>
(4, 4)<br>
(2, 1)<br>
(2, 0)<br>
(1, 0)<br>
(3, 0)<br>
(4, 0)<br>
</td>
</table>

Project for the course ["Algorithm and Data Structure"](https://uspdigital.usp.br/jupiterweb/obterDisciplina?sgldis=SSC0902) at the Institute of Mathematics and Computer Science, University of Sao Paulo
