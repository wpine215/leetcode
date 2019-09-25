class MinStack:

    def __init__(self):
        self.mstack = []

    def push(self, x: int) -> None:
        # Add item at top of stack, keep track of current minimum value
        if len(self.mstack) == 0:
            cmin = x
        else:
            cmin = min([x, self.getMin()])
            
        self.mstack.append((x, cmin))

    def pop(self) -> None:
        # Remove item at top of stack
        self.mstack.pop()

    def top(self) -> int:
        # Return item at top of stack
        return self.mstack[-1][0]

    def getMin(self) -> int:
        # Get current minimum value from top of stack
        return self.mstack[-1][1]