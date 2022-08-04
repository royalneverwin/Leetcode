class Solution:
    def Cmp(a, b):
        return a[1] < b[1] if a[0]==b[0] else a[0] < b[0]
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        p = [p1, p2, p3, p4]
        p.sort()
        p1 = p[0]
        p2 = p[1]
        p3 = p[3]
        p4 = p[2]

        vec12 = [p2[0] - p1[0], p2[1] - p1[1]]
        vec23 = [p3[0] - p2[0], p3[1] - p2[1]]
        vec34 = [p4[0] - p3[0], p4[1] - p3[1]]
        vec41 = [p1[0] - p4[0], p1[1] - p4[1]]
        if vec12[0]*vec23[0] + vec12[1]*vec23[1] == 0 and \
                vec23[0]*vec34[0] + vec23[1]*vec34[1] == 0 and \
                vec34[0]*vec41[0] + vec34[1]*vec41[1] == 0 and \
                vec41[0]*vec12[0] + vec41[1]*vec12[1] == 0 and \
                (vec12[0]**2 + vec12[1]**2) == (vec23[0]**2 + vec23[1]**2) and \
                (vec23[0]**2 + vec23[1]**2) == (vec34[0]**2 + vec34[1]**2) and \
                (vec34[0]**2 + vec34[1]**2) == (vec41[0]**2 + vec41[1]**2) and \
                (vec12[0]**2 + vec12[1]**2):
            return True
        else:
            return False
