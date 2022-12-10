class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        if coordinates[0] == 'a' or coordinates[0] == 'c' or coordinates[0] == 'e' or coordinates[0] == 'g':
            if coordinates[1] == '1' or coordinates[1] == '3' or coordinates[1] == '5' or coordinates[1] == '7':
                return False
            else:
                return True
        else:
            if coordinates[1] == '1' or coordinates[1] == '3' or coordinates[1] == '5' or coordinates[1] == '7':
                return True
            else:
                return False