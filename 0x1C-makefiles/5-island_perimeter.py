#!/bin/python3
def island_perimeter(grid):
    """
        function finding primeter of grid 
    """
    height = len(grid)
    width = len(grid[0])
    priemeter = 0
    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                if i-1 >=0 and grid[i-1][j] == 0:
                    priemeter+=1
                    
                if j-1 >=0 and grid[i][j-1] == 0:
                    priemeter+=1
                 
                if i+1 < height and grid[i+1][j] == 0:
                    priemeter+=1
                    
                if j+1 >=0 and grid[i][j+1] == 0:
                    priemeter+=1
                    
    return priemeter
