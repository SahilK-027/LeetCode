# 📚 CONTRIBUTION GUIDELINES 📚

## Before contributing
Welcome to [SahilK-027/Leetcode](https://github.com/SahilK-027/LeetCode)

```diff
@@ Before submitting pull requests, please make sure that you have read the whole guidelines @@

```

## Contributor

Being a contributor at The Algorithms, we request you to follow the points mentioned below:

- You did your own work.
- No plagiarism is allowed. Any plagiarized work will not be merged.
- Please follow the repository guidelines and standards mentioned below.

**New implementations** are welcome!

We're glad you're interested in adding LeetCode solutions to the repository.
Here we'll be explaining how to contribute to LeetCode solutions properly.

## 📝 Solution for Non-existing Problem in REPOSITORY 📝
If you have a solution for the problem which is not yet solved then for addig it follow following steps

1. Create a directory `Leetcode/no.PROBLEM_NAME`
    - For example: if the problem's number is 100, then create a repository 100. Same Tree.

2. Add two files README.md and solution.cpp `(or in that case any language)` inside the directory you have just created

3. Inside the readme follow the following code to write problem description
```
# Probelm Name
## Description


Example 1:

if there is image for explaination

![alt](imgsrc)


Input:
Output: 
Explaination:


(If there exists) Follow-up: 

```
4. Adding code in solution.cpp
Provide Runtime, memory, time and space complexity , author name a brief description of the solution at the top of the file. A function should go below that. 

You can follow this method: 
For example:
```cpp
/*
243 ms
75.3 MB

TC : O(n^2)
SC : O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Simple directed graph
*/

/*
NOTE: YOU CAN EXPALIN YOUR APPROACH HERE
*/
```
### 📜 Adding your new solution to the list 📜

Great! You've added your solution. Now, you'll have to add it to `leetcode/README.md`.\
Please use numerical order. For example: if the solution's number is `100`, add your solution after `99`, if available.

This is the required format for new solutinos:

```markdown
| <Problem number>   | [<Problem name>]|  | <difficulty> 🟢 or 🟡 or 🔴 |[solution](LEAVE THIS SPACE EMPTY)|  
```

<br/>
<br/>
<br/>


## 📝 Adding a alternative solution for Problem in REPOSITORY 📝

All solved LeetCode problems can be found [**here**](https://github.com/SahilK-027/LeetCode).
If you have a solution to any of these problems (which are not being [**repeated**]), that's great! Here are the steps:

1. Add a new file in `the directory for particular problem` with file file name as new_Problem_no.cpp.
    - For example: if the problem's number is 100, then the filename should be `new_100.cpp`.
2. Provide Runtime, memory, time and space complexity , author name a brief description of the solution at the top of the file. A function should go below that. 

You can follow this method: 
For example:
```cpp
/*
243 ms
75.3 MB

TC : O(n^2)
SC : O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Simple directed graph
*/

/*
NOTE: YOU CAN EXPALIN YOUR APPROACH HERE
*/
```

3. Do not provide a `main` function. Use the required standalone functions instead.
4. Simple/small documentation or comments should be fine.



### Making Changes

#### Code

- Please use the directory structure of the repository.
- Make sure the file extensions should be `*.cpp` `*.py` etc.
- You can suggest reasonable changes to existing solutions.
- Strictly use snake_case (underscore_separated) in filenames.
- If you have added or modified code, please make sure the code compiles and gets accept on leetcode before submitting.
- **Be consistent in the use of these guidelines.**

#### Documentation

- Make sure you put useful comments in your code. Do not comment on obvious things.
- Please avoid creating new directories if at all possible. Try to fit your work into the existing directory structure. If you want to create a new directory, then please check if a similar category has been recently suggested or created by other pull requests.
- If you have modified/added documentation, please ensure that your language is concise and must not contain grammatical errors.
- Do not update [`README.md`](https://github.com/SahilK-027/LeetCode/blob/main/README.md) if you are only adding alternative solution for preexisting problem in list.  First, create an issue and then link to that issue in your pull request to suggest specific changes.

## Pull Requests

- Checkout our [pull request template](https://github.com/SahilK-027/LeetCode/blob/main/.github/workflows/pull_request_template.md)
By now you are ready to make a **PULL REQUEST**

<br/>

[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=IBM+Plex+Sans&color=ff1493&size=36&lines=‎‎‎‎‎‎‎‎‎‎‎‎‎‎‎‎‎‎‎‎‎+Happy+LeetCoding!;)](https://git.io/typing-svg)
