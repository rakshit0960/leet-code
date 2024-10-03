class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        def func(k):
            if k == 1: return 'a'
            
            i = floor(log(k - 1, 2))
            l = 1 << i

            ch = func(k - l)
            if operations[i] == 0:
                return ch
            else:
                if ch == 'z':
                    return 'a'
                else:
                    return chr(ord(ch) + 1)
        
        return func(k)