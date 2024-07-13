from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        robots = sorted(zip(positions, healths, directions, range(len(positions))))
        
        stack = [] 
        results = [None] * len(positions)  
        
        for pos, health, direction, index in robots:
            if direction == 'R':
                stack.append((pos, health, direction, index))
            else:  # direction == 'L'
                while stack and health > 0:
                    r_pos, r_health, r_direction, r_index = stack[-1]
                    if r_health < health:
                        health -= 1
                        stack.pop()
                    elif r_health > health:
                        stack[-1] = (r_pos, r_health - 1, r_direction, r_index)
                        health = 0
                    else:  
                        stack.pop()
                        health = 0
                
                if health > 0:
                    results[index] = health
        
        while stack:
            pos, health, direction, index = stack.pop()
            results[index] = health
        
        return [health for health in results if health is not None]