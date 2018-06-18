Your terraforming crew is busy at work on a mountaintop, but it's time to break for lunch. In order to allow everyone to have lunch together, we'd like to find a plateau on the mountain where everyone can sit.

Given a topographic map in the form of a matrix of integers map, find the area of the largest plateau.

## Example

- For
     ```
     map = [[1,0,0,2,2,0],
            [0,0,2,1,0,2],
            [0,1,1,2,2,2],
            [1,2,1,0,2,1]]
     ```

     the output should be `largestPlateau(map) = 5`. The crew could either choose the plateau with elevation `0` or the one with elevation `2`; both of      which have an area of `5`:

## Input / Output

- `[execution time limit]` 4 seconds (py)

- `[input]` array.array.integer map

     A matrix of integers representing the height at each point of the topographic map of the mountain.

     *Guaranteed constraints*:
     0 ≤ map.length ≤ 1000
     0 ≤ map[i].length ≤ 1000
     0 ≤ map[i][j] ≤ 106

- `[output]` integer

     The area of the largest plateau on the map (largest number of adjacent elements sharing the same value).