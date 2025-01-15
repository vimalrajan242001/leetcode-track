public class Solution {
    public bool IsRobotBounded(string instructions) {
        int x = 0, y = 0;  // Start at the origin (0, 0)
        int direction = 0;  // 0 = North, 1 = East, 2 = South, 3 = West

        // Directions corresponding to (dx, dy)
        int[][] directions = new int[][] {
            new int[] {0, 1},  // North
            new int[] {1, 0},  // East
            new int[] {0, -1}, // South
            new int[] {-1, 0}  // West
        };

        foreach (var instruction in instructions) {
            if (instruction == 'G') {
                x += directions[direction][0];
                y += directions[direction][1];
            } else if (instruction == 'L') {
                direction = (direction + 3) % 4;  // Turn left (counterclockwise)
            } else if (instruction == 'R') {
                direction = (direction + 1) % 4;  // Turn right (clockwise)
            }
        }

        // Robot is bounded if it's back at the origin or facing a different direction
        return (x == 0 && y == 0) || direction != 0;
    }
}
/*
Let’s go through the iteration for the input `"GGLLGG"` with detailed calculations for how the `direction` variable changes and how the position `(x, y)` updates. We'll also track the changes to the `direction` variable explicitly.

### Initial Setup:
- Position: `(x, y) = (0, 0)`
- Direction: `direction = 0` (North)
- Directions:
  - North (`direction = 0`): `(0, 1)`
  - East (`direction = 1`): `(1, 0)`
  - South (`direction = 2`): `(0, -1)`
  - West (`direction = 3`): `(-1, 0)`

### Instructions: `"GGLLGG"`

#### **First Instruction: 'G'**

- Current position: `(x, y) = (0, 0)`
- Direction: `direction = 0` (North)
- Direction vector for North: `(0, 1)`
  
  Calculation:
  - Move: `(x, y) = (0 + 0, 0 + 1) = (0, 1)`
  - New position: `(0, 1)`
  - Direction remains unchanged at `0` (North).

#### **Second Instruction: 'G'**

- Current position: `(x, y) = (0, 1)`
- Direction: `direction = 0` (North)
- Direction vector for North: `(0, 1)`
  
  Calculation:
  - Move: `(x, y) = (0 + 0, 1 + 1) = (0, 2)`
  - New position: `(0, 2)`
  - Direction remains unchanged at `0` (North).

#### **Third Instruction: 'L'**

- Current position: `(x, y) = (0, 2)`
- Direction: `direction = 0` (North)
  
  Calculation:
  - Turn left. When turning left, the direction changes counterclockwise (decrease direction by 1).
  - New direction: `(direction + 3) % 4 = (0 + 3) % 4 = 3` (West)
  - Position remains unchanged: `(x, y) = (0, 2)`
  - New direction: `direction = 3` (West)

#### **Fourth Instruction: 'L'**

- Current position: `(x, y) = (0, 2)`
- Direction: `direction = 3` (West)
  
  Calculation:
  - Turn left. When turning left, the direction changes counterclockwise (decrease direction by 1).
  - New direction: `(direction + 3) % 4 = (3 + 3) % 4 = 2` (South)
  - Position remains unchanged: `(x, y) = (0, 2)`
  - New direction: `direction = 2` (South)

#### **Fifth Instruction: 'G'**

- Current position: `(x, y) = (0, 2)`
- Direction: `direction = 2` (South)
- Direction vector for South: `(0, -1)`
  
  Calculation:
  - Move: `(x, y) = (0 + 0, 2 - 1) = (0, 1)`
  - New position: `(0, 1)`
  - Direction remains unchanged at `2` (South).

#### **Sixth Instruction: 'G'**

- Current position: `(x, y) = (0, 1)`
- Direction: `direction = 2` (South)
- Direction vector for South: `(0, -1)`
  
  Calculation:
  - Move: `(x, y) = (0 + 0, 1 - 1) = (0, 0)`
  - New position: `(0, 0)`
  - Direction remains unchanged at `2` (South).

### Final State:
- Position: `(x, y) = (0, 0)`
- Direction: `direction = 2` (South)

### Conclusion:
- The robot is back at the origin `(0, 0)`. Since it has returned to the origin, the robot is **bounded** in a circle.
- The result of the function would be `True`.

The formula `(direction + 3) % 4` for turning left and `(direction + 1) % 4` for turning right is based on modular arithmetic, and it comes from the way we represent directions in a circular fashion. Let me explain this step-by-step.

### Directions as Indices:

We represent the four possible directions (North, East, South, West) using indices:
- North = `0`
- East = `1`
- South = `2`
- West = `3`

### Turning Right (`R`):
When the robot turns right, we want to move one position forward in this circle of directions. For example:
- If the robot is facing North (`direction = 0`), after turning right, it should face East (`direction = 1`).
- If the robot is facing East (`direction = 1`), after turning right, it should face South (`direction = 2`).
- If the robot is facing South (`direction = 2`), after turning right, it should face West (`direction = 3`).
- If the robot is facing West (`direction = 3`), after turning right, it should face North (`direction = 0`).

To achieve this in modular arithmetic, we add 1 to the current direction index and then use `% 4` to ensure the result wraps around when it exceeds 3 (i.e., goes back to 0). The formula is:
```csharp
direction = (direction + 1) % 4;
```

This ensures that:
- If `direction = 3` (West), `(3 + 1) % 4 = 4 % 4 = 0` (North).
- If `direction = 2` (South), `(2 + 1) % 4 = 3` (West), and so on.

### Turning Left (`L`):
When the robot turns left, we want to move one position backward in this circle of directions. For example:
- If the robot is facing North (`direction = 0`), after turning left, it should face West (`direction = 3`).
- If the robot is facing East (`direction = 1`), after turning left, it should face North (`direction = 0`).
- If the robot is facing South (`direction = 2`), after turning left, it should face East (`direction = 1`).
- If the robot is facing West (`direction = 3`), after turning left, it should face South (`direction = 2`).

To achieve this, we subtract 1 from the current direction index. However, since we're working with modular arithmetic, we have to ensure that when we subtract 1 from `0` (North), we get `3` (West), which is equivalent to going backward in a circular manner. This is where the formula `(direction + 3) % 4` comes in.

We add `3` to the direction before applying the modulo operation, which guarantees that the result wraps around correctly:
```csharp
direction = (direction + 3) % 4;
```

This ensures that:
- If `direction = 0` (North), `(0 + 3) % 4 = 3` (West).
- If `direction = 1` (East), `(1 + 3) % 4 = 4 % 4 = 0` (North), and so on.

### Why Use Modulo 4?
We use modulo 4 because there are 4 directions (North, East, South, West), and applying modulo 4 ensures that the direction index stays within the valid range of `0` to `3`. When the direction index exceeds `3`, it wraps around back to `0` (for example, moving right from West should take us to North).

### Summary:
- **Right Turn (`R`)**: Add `1` to the current direction and wrap around using `% 4`.
- **Left Turn (`L`)**: Add `3` to the current direction (equivalent to subtracting 1) and wrap around using `% 4`.

This approach avoids any explicit conditional checks for each direction, making the code more concise and efficient while using modular arithmetic to handle the circular behavior of directions.

*/
