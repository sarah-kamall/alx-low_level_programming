#!/bin/python3
"""Defines an island perimeter measuring function."""
def island_perimeter(grid):
    """
    Return the perimiter of an island.

    The grid represents water by 0 and land by 1.

    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in grid.
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
