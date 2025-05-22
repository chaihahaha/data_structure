class SuffixAutomaton:
    def __init__(self, s):
        self.states = [{}]  # List of dictionaries to store transitions for each state
        self.link = [-1]    # Suffix link array
        self.length = [0]   # Length of longest string in each state
        self.last = 0       # Last state added

        for char in s:
            self.add_char(char)

    def add_char(self, char):
        current = len(self.states)
        self.states.append({})
        self.length.append(self.length[self.last] + 1)
        self.link.append(0)
        p = self.last

        while p != -1 and char not in self.states[p]:
            self.states[p][char] = current
            p = self.link[p]

        if p == -1:
            self.link[current] = 0
        else:
            q = self.states[p][char]
            if self.length[p] + 1 == self.length[q]:
                self.link[current] = q
            else:
                clone = len(self.states)
                self.states.append(self.states[q].copy())
                self.length.append(self.length[p] + 1)
                self.link.append(self.link[q])
                self.link[q] = self.link[current] = clone

                while p != -1 and self.states[p].get(char) == q:
                    self.states[p][char] = clone
                    p = self.link[p]

        self.last = current

    def decode_string(self):
        # Start from state 0 and reconstruct the string by following the transitions
        current = 0
        result = []

        while True:
            if not self.states[current]:
                break  # Stop if there are no more transitions
            # Follow the smallest lexicographical transition
            next_char = min(self.states[current])
            result.append(next_char)
            current = self.states[current][next_char]

        return ''.join(result)

# Example usage
s = "abacabadabacaba"
sa = SuffixAutomaton(s)
decoded_string = sa.decode_string()
print(f"Decoded string: {decoded_string}")

