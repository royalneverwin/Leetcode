class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        min_energy = sum(energy)+1
        res = max(0, min_energy - initialEnergy)

        for exp in experience:
            min_exp = exp+1
            res += max(0, min_exp-initialExperience)
            initialExperience += max(0, min_exp-initialExperience)
            initialExperience += exp

        return res