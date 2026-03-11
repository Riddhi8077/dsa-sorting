class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        if not digits:
            return []
        
        mapping = {
            "2": "abc", "3": "def", "4": "ghi",
            "5": "jkl", "6": "mno", "7": "pqrs",
            "8": "tuv", "9": "wxyz"
        }
        
        result = []
        
        def backtrack(index, path):
            if index == len(digits):
                result.append(path)
                return
            
            letters = mapping[digits[index]]
            
            for letter in letters:
                backtrack(index + 1, path + letter)
        
        backtrack(0, "")
        return result
