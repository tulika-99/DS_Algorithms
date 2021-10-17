# DS Algorithms

A collection of different types of algorithms used for various different Data Structures, in different languages.
This repository is open to all. 
To help you out with your Hacktoberfest goals!!  
All you need to do is just add any sorting algorithm of your choice in any language you like with only the condition that it hasn't already been added.


## Structure of the Repository

- The Repository contains folders with names of Data Structures the Algorithms are based on, or the Name of the Algorithms if its valid for multiple data Structures.
- Inside each folder there maybe subfolders for the specific Algorithms.
- Each Algorithm folder contains        

 1.  A Text file or an MD file which contains the Theory/ Explanation of the Algorithm
 2. and Several other files containing the code for the same, for different languages.   
These files MUST BE NAMED in the format **Algorithm Name - language**. ( Eg: Binary Search - C++ )  

Example:   
Trees -> Inorder Traversal -> InorderTraversal- C++, Inorder Traversal-Python   
Graphs -> Bellman Ford -> Bellman Ford-C++, BellmanFord-Java,....


## What can you contribute ?

You can either add
- The theory/explainations of the Algorithms   
 ( Discuss the approach, Time and Space Complexities, Examples, etc. )   
 (Please add references as well, if used)  

- Code for the Algorithm in a language of your choice.


## Guidelines

- Go Inside the Data Structure or Algorithm folder (if already created, else create one).
- Go inside the  folder with the specific Algorithm Name. If not present then create a new folder with the name of the algorithm and add your files in it.
- Create a .txt file with the Algorithm Theory/Explanation or a solution file which contains the code for the Algorithm, named acc to the language used to implement it. ( Eg: Inorder Traversal-C++ )
- Add this file inside the folder with the name of the algorithm you have implemented.
- If you have some specific details u need to add according to the implementation in a specific language, add it as comments in the code, or create a sub-folder (Algo Name - language) and add the text file and the code files.  
(Can also be done in case the implementation in a language requires more than one file.)
- It is a good practice to always add comments in your code explaining the steps. (I would still prefer if you add a file explianing the algorithm)
- A more organized and structured pull request has greater chances to be approved. (Cuz maintainers are Lazy AF)


## Steps

- Fork this repo (button on top)
- Star this repo (button on top)
- Clone the repo on your local machine

```terminal
git clone https://github.com/your-username/DS_Algorithms.git
```

- Create a new folder with the algorithm name.
- Add your Theory/ Explanation or Code file in that folder. ( Please keep in mind the naming of the files) (Algorithm Name - language) 
- Commit and push

```terminal
git add .
git commit -m "Added <algorithm-name> in <language>"
git push origin master
```

- Create a new pull request from your forked repository
- And you are one step closer!   
**Check out your progress at https://hacktoberfest.digitalocean.com/profile**

## Links to help you out

In case you find the steps given above as vague and unclear, feel free to look up these amazing articles  
https://help.github.com/en/articles/adding-a-file-to-a-repository-using-the-command-line
https://www.digitalocean.com/community/tutorials/how-to-create-a-pull-request-on-github  
https://medium.com/@saumya.ranjan/how-to-write-a-readme-md-file-markdown-file-20cb7cbcd6f  


## Note

- Avoid overwriting other people's contributions, adding spaces and tabs or making any other type of invalid pull requests.   
 (They will be marked invalid and won't be counted in your HacktoberFest goals.) ( PS- If you find any such requests, please report to me.)
- **No Array or Linked List Sorting Algorithms please** 
We already have a repo for that from last year : https://github.com/tulika-99/sorting-algorithms
- If you have any other doubts, feel free to discuss in the issue.

Idea for some algorithms  :

- Searching Algorithms ( Interpolation Search)
- Graph Algos ( Bellman Ford ,Topological sort, BFS,DFS,Dijkstra, Min spanning tree algos) 
- Tree Algos 
- Stacks ( inorder and post order expressions)
