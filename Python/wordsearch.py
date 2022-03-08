"""
1. search main_grid for first letter of first word to be searched
2. if match, check surrounding letters if second letter matches
3. if match again, continue checking if all letters in that direction match
4. if yes, output index of first letter. if no, search for next occurrence of letter and repeat from step 2
5. repeat for other words in words
"""
"""
For each word to search, output the row and column (two integers separated by a space) on one line,
corresponding to the row and column where the first letter of the word is found in the grid.
If the word appears multiple times in the grid, output the coordinates of the uppermost occurrence of the word in the grid.
If two or more occurrences are uppermost, output the coordinates for the leftmost occurrence in the grid.
All words are guaranteed to be found at least once in the grid.
"""

R, C = map(int, input().split())
main_grid = []
results_a = []
results_b = []
for i in range(R):
    main_grid.append(input()) # grid to be searched
N = int(input())
words = []
for i in range(N):
    words.append(input())
dirs = [[-1,0],[1,0],[0,-1],[0,1],[-1,-1],[-1,1],[1,-1],[1,1]] # W, E, S, N, SW, NW, SE, NE

i = 0   
while i < N:
    coordinates = False
    for x in range(R): # row = x
        for y in range(C): # col = y
            if coordinates == False:
                tempx = x
                tempy = y
                z = 0
                coords = 0
                count = 0
                while z < len(words[i]):
                    if coords > 7:
                        break
                    a,b = dirs[coords]
                    if tempx + a >= 0 and tempx + a < R and tempy + b >= 0 and tempy + b < C and main_grid[tempx][tempy] == words[i][z] and z < len(words[i])-1: # searches all coords matching first letter of words[i]
                        tempx += a
                        tempy += b
                        count += 1
                        z += 1
                    elif main_grid[tempx][tempy] == words[i][z] and z == len(words[i])-1:
                        tempx = tempx + count*a
                        tempy = tempy + count*b
                        results_a.append(x+1)
                        results_b.append(y+1)
                        coordinates = True
                        break
                    else:
                        tempx = x
                        tempy = y
                        z = 0
                        count = 0
                        coords += 1
                        continue
    i += 1         

print(results_a)
print(results_b)
for x in range(len(words)):
    print("{} {}".format(results_a[x],results_b[x]))
