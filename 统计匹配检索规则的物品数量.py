class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        return sum([1 for t, c, n in items if {"type": t, "color": c, "name": n}[ruleKey] == ruleValue])